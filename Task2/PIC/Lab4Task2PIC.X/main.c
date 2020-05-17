/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC16F1709
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

void LCD_Clear()
{
    putch(254);
    putch(1);
    putch(63);
}

void LCD_SecondLine()
{
    putch(254);
    putch(192);
}

void LCD_Display(int frequency, int amplitude)
{
    LCD_Clear();
    printf("Amplitude: %d", amplitude);
    LCD_SecondLine();
    printf("Frequency: %d", frequency);
    // printf("Duty cycle: %%%d", HighImpulsLength / LowImpulsLength)
}

void YellowSignal()
{
    uint8_t signal = 0;
    
    int amp = 0;
    int freq = 0;
    int incrementer = 1;
    
    const double MAX_DAC_OUTPUT = 255.0;    
    const double MAX_ADC_INPUT = 1023.0;
    
    const int MAX_DELAY = 300;
    
    while (1)
    {
        double amplitudePercent = ADC_GetConversion(channel_AN4) / MAX_ADC_INPUT;
        double frequencyPercent = ADC_GetConversion(channel_AN5) / MAX_ADC_INPUT;
        
        int newAmp = amplitudePercent * MAX_DAC_OUTPUT;
        int newFreq = frequencyPercent * MAX_DELAY;
        
        if (newAmp != amp || newFreq != freq)
        {
            amp = newAmp;
            freq = newFreq;
            LCD_Display(freq, amp);
        }
        
        if (signal >= amp)
        {
            incrementer = -1;
        } 
        else if (signal <= 0)
        {
            incrementer = 1;
        }
        
        signal = signal + incrementer;
        DAC_SetOutput(signal);
        for (int i = 0; i < freq; i ++); 
    }
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    uint8_t signal = 0;
    
    int amp = 0;
    int freq = 0;
    
    const double MAX_DAC_OUTPUT = 255.0;    
    const double MAX_ADC_INPUT = 1023.0;
    
    int HighImpulsLength = ADC_GetConversion(channel_AN5) + 1;
    int LowImpulsLength  = HighImpulsLength;
    
    int currentImpulsLength = 0;
    int impulsLength = 0;
    
    __delay_ms(200);
    LCD_Display(ADC_GetConversion(channel_AN5) + 1, ADC_GetConversion(channel_AN4) / MAX_ADC_INPUT);
    
    while (1)
    {
        if (currentImpulsLength >= impulsLength)
        {
            double amplitudePercent = ADC_GetConversion(channel_AN4) / MAX_ADC_INPUT;

            int newAmp = amplitudePercent * MAX_DAC_OUTPUT;
            int newFreq = MAX_ADC_INPUT - ADC_GetConversion(channel_AN5) + 1;

            if (newAmp != amp || newFreq != freq)
            {
                amp = newAmp;
                freq = newFreq;
                
                HighImpulsLength = LowImpulsLength = freq;
                
                LCD_Display(MAX_ADC_INPUT - freq + 2, amp);
            }

            if (signal == 0)
            {
                signal = amp;
                impulsLength = HighImpulsLength;
            }
            else
            {
                signal = 0;
                impulsLength = LowImpulsLength;
            }
            
            currentImpulsLength = 0;
        }
        
        DAC_SetOutput(signal);
        currentImpulsLength++;
    }
}
/**
 End of File
*/