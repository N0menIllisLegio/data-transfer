/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.78
        Device            :  PIC16F1947
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.05 and above
        MPLAB 	          :  MPLAB X 5.20	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LED_RED aliases
#define LED_RED_TRIS                 TRISAbits.TRISA0
#define LED_RED_LAT                  LATAbits.LATA0
#define LED_RED_PORT                 PORTAbits.RA0
#define LED_RED_ANS                  ANSELAbits.ANSA0
#define LED_RED_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define LED_RED_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define LED_RED_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define LED_RED_GetValue()           PORTAbits.RA0
#define LED_RED_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define LED_RED_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define LED_RED_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define LED_RED_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set LED_YELLOW aliases
#define LED_YELLOW_TRIS                 TRISAbits.TRISA1
#define LED_YELLOW_LAT                  LATAbits.LATA1
#define LED_YELLOW_PORT                 PORTAbits.RA1
#define LED_YELLOW_ANS                  ANSELAbits.ANSA1
#define LED_YELLOW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define LED_YELLOW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define LED_YELLOW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define LED_YELLOW_GetValue()           PORTAbits.RA1
#define LED_YELLOW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define LED_YELLOW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define LED_YELLOW_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define LED_YELLOW_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set LED_GREEN aliases
#define LED_GREEN_TRIS                 TRISAbits.TRISA2
#define LED_GREEN_LAT                  LATAbits.LATA2
#define LED_GREEN_PORT                 PORTAbits.RA2
#define LED_GREEN_ANS                  ANSELAbits.ANSA2
#define LED_GREEN_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define LED_GREEN_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define LED_GREEN_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define LED_GREEN_GetValue()           PORTAbits.RA2
#define LED_GREEN_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define LED_GREEN_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define LED_GREEN_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define LED_GREEN_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set RG1 procedures
#define RG1_SetHigh()            do { LATGbits.LATG1 = 1; } while(0)
#define RG1_SetLow()             do { LATGbits.LATG1 = 0; } while(0)
#define RG1_Toggle()             do { LATGbits.LATG1 = ~LATGbits.LATG1; } while(0)
#define RG1_GetValue()              PORTGbits.RG1
#define RG1_SetDigitalInput()    do { TRISGbits.TRISG1 = 1; } while(0)
#define RG1_SetDigitalOutput()   do { TRISGbits.TRISG1 = 0; } while(0)
#define RG1_SetAnalogMode()         do { ANSELGbits.ANSG1 = 1; } while(0)
#define RG1_SetDigitalMode()        do { ANSELGbits.ANSG1 = 0; } while(0)

// get/set RG2 procedures
#define RG2_SetHigh()            do { LATGbits.LATG2 = 1; } while(0)
#define RG2_SetLow()             do { LATGbits.LATG2 = 0; } while(0)
#define RG2_Toggle()             do { LATGbits.LATG2 = ~LATGbits.LATG2; } while(0)
#define RG2_GetValue()              PORTGbits.RG2
#define RG2_SetDigitalInput()    do { TRISGbits.TRISG2 = 1; } while(0)
#define RG2_SetDigitalOutput()   do { TRISGbits.TRISG2 = 0; } while(0)
#define RG2_SetAnalogMode()         do { ANSELGbits.ANSG2 = 1; } while(0)
#define RG2_SetDigitalMode()        do { ANSELGbits.ANSG2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/