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
#include "Picture.h"
/*
                         Main application
 */

void InversePicture(uint8_t *current)
{
    uint8_t normal = 0b10100110;
    uint8_t reverse = 0b10100111;
    
    if (*current == normal)
    {
        *current = reverse;
    }
    else
    {
        *current = normal;
    }
        
    A0_SetLow();
    SPI_ExchangeByte(*current); 
    A0_SetHigh();
}

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    SPI_Open(0);    
    A0_SetHigh();
    uint8_t line = 0b10110001;
    int page = 0;
    int column = 0;
    SPI_ExchangeByte(0);
    
    for (int i = 0; i < 1024; i++)
    {
        SPI_ExchangeByte(GetMyByte(column++, page));
        //SPI_ExchangeByte(255);
        __delay_ms(10);
        
        if (i % 128 == 0 && i != 0)
        {
            page++;
            column = 0;
            A0_SetLow();
            __delay_ms(100);
            
            SPI_ExchangeByte(line++);
            SPI_ExchangeByte(0b00010000);
            __delay_ms(100);
            
            A0_SetHigh();
        }
    }
    

    
    uint8_t current = 0b10100110;
    
    while (1)
    {
        if (RC0_GetValue() == HIGH)
        {
            InversePicture(&current);
        }
    }
}

/**
 End of File
*/