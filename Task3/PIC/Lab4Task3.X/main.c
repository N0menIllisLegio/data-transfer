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
        Device            :  PIC16F1947
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
#include "string.h"
/*
                         Main application
 */

void PrintOK()
{
    EUSART2_Write(0b01001111);
    EUSART2_Write(0b01101011);
    
    EUSART2_Write(0b00001101);
}

void PrintERROR()
{
    EUSART2_Write(0b01000101);
    EUSART2_Write(0b01110010);
    EUSART2_Write(0b01110010);
    EUSART2_Write(0b01101111);
    EUSART2_Write(0b01110010);
    
    EUSART2_Write(0b00001101);
}

void LightRED()
{
    LED_GREEN_SetLow();
    LED_YELLOW_SetLow();
    LED_RED_SetHigh();
}

void LightGREEN()
{
    LED_GREEN_SetHigh();
    LED_YELLOW_SetLow();
    LED_RED_SetLow();
}

void LightYELLOW()
{
    LED_GREEN_SetLow();
    LED_YELLOW_SetHigh();
    LED_RED_SetLow();
}

void TurnOFFLeds()
{
    LED_GREEN_SetLow();
    LED_YELLOW_SetLow();
    LED_RED_SetLow();
}

void ClearLCD()
{
    putch(254);
    putch(1);
}

void PrintLCD(char command[], char result[])
{
    ClearLCD();
    putch(63);
    printf(command);
    
    putch(254);
    putch(192);
    printf(result);
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
    
    
    
    while (1)
    {
        char buffer[20] = "";
        bool stop = false;
        int pointer = -1;
        
        while (!stop)
        {
        if (eusart2RxCount != 0)
        {
            if (pointer == -1)
            {
               pointer = 0; 
            }
            
            uint8_t temp = EUSART2_Read();

            buffer[pointer] = (char) temp;
            pointer++;
            
        }
        else
        {
            if (strstr(buffer, ";") != NULL || pointer >= 20)
            {
                
                if (pointer >= 20)
                {
                    TurnOFFLeds();
                    ClearLCD();
                    PrintERROR();
                }
                else if (strstr(buffer, "light") != NULL)
                {
                    if (strstr(buffer, "green") != NULL)
                    {
                        PrintOK();
                        PrintLCD("Light green", "Lighted!");
                        LightGREEN();
                    } 
                    else if (strstr(buffer, "red") != NULL)
                    {
                        PrintOK();
                        PrintLCD("Light red", "Lighted!");
                        LightRED();
                    }
                    else if (strstr(buffer, "yellow") != NULL)
                    {
                        PrintOK();
                        PrintLCD("Light yellow", "Lighted!");
                        LightYELLOW();
                    }
                    else
                    {
                        TurnOFFLeds();
                        ClearLCD();
                        PrintERROR();
                    }
                }
                else if (strcmp(buffer, "Turn off;") == 0)
                {
                    PrintOK();
                    PrintLCD("Turn off", "LEDs turned off.");
                    TurnOFFLeds();
                }
                else
                {
                    TurnOFFLeds();
                    ClearLCD();
                    PrintERROR();
                }
                
                //printf(eusart2RxBuffer);
                //buffer[0] = '\0';
                pointer = -1;
                stop = true;
            }
        }
    }
    }
}

  
/**
 End of File
*/