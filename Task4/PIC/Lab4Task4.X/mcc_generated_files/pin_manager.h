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
        Device            :  PIC16F1709
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

// get/set A0 aliases
#define A0_TRIS                 TRISAbits.TRISA4
#define A0_LAT                  LATAbits.LATA4
#define A0_PORT                 PORTAbits.RA4
#define A0_WPU                  WPUAbits.WPUA4
#define A0_OD                   ODCONAbits.ODA4
#define A0_ANS                  ANSELAbits.ANSA4
#define A0_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define A0_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define A0_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define A0_GetValue()           PORTAbits.RA4
#define A0_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define A0_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define A0_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define A0_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define A0_SetPushPull()        do { ODCONAbits.ODA4 = 0; } while(0)
#define A0_SetOpenDrain()       do { ODCONAbits.ODA4 = 1; } while(0)
#define A0_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define A0_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RST aliases
#define RST_TRIS                 TRISAbits.TRISA5
#define RST_LAT                  LATAbits.LATA5
#define RST_PORT                 PORTAbits.RA5
#define RST_WPU                  WPUAbits.WPUA5
#define RST_OD                   ODCONAbits.ODA5
#define RST_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define RST_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define RST_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RST_GetValue()           PORTAbits.RA5
#define RST_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define RST_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define RST_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define RST_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define RST_SetPushPull()        do { ODCONAbits.ODA5 = 0; } while(0)
#define RST_SetOpenDrain()       do { ODCONAbits.ODA5 = 1; } while(0)

// get/set SDI aliases
#define SDI_TRIS                 TRISBbits.TRISB4
#define SDI_LAT                  LATBbits.LATB4
#define SDI_PORT                 PORTBbits.RB4
#define SDI_WPU                  WPUBbits.WPUB4
#define SDI_OD                   ODCONBbits.ODB4
#define SDI_ANS                  ANSELBbits.ANSB4
#define SDI_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define SDI_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define SDI_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define SDI_GetValue()           PORTBbits.RB4
#define SDI_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define SDI_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define SDI_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define SDI_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define SDI_SetPushPull()        do { ODCONBbits.ODB4 = 0; } while(0)
#define SDI_SetOpenDrain()       do { ODCONBbits.ODB4 = 1; } while(0)
#define SDI_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define SDI_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set SDO aliases
#define SDO_TRIS                 TRISBbits.TRISB5
#define SDO_LAT                  LATBbits.LATB5
#define SDO_PORT                 PORTBbits.RB5
#define SDO_WPU                  WPUBbits.WPUB5
#define SDO_OD                   ODCONBbits.ODB5
#define SDO_ANS                  ANSELBbits.ANSB5
#define SDO_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define SDO_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define SDO_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define SDO_GetValue()           PORTBbits.RB5
#define SDO_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define SDO_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define SDO_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define SDO_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define SDO_SetPushPull()        do { ODCONBbits.ODB5 = 0; } while(0)
#define SDO_SetOpenDrain()       do { ODCONBbits.ODB5 = 1; } while(0)
#define SDO_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define SDO_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set SCK aliases
#define SCK_TRIS                 TRISBbits.TRISB6
#define SCK_LAT                  LATBbits.LATB6
#define SCK_PORT                 PORTBbits.RB6
#define SCK_WPU                  WPUBbits.WPUB6
#define SCK_OD                   ODCONBbits.ODB6
#define SCK_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define SCK_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define SCK_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define SCK_GetValue()           PORTBbits.RB6
#define SCK_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define SCK_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONBbits.ODB6 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONBbits.ODB6 = 1; } while(0)

// get/set RC0 aliases
#define RC0_TRIS                 TRISCbits.TRISC0
#define RC0_LAT                  LATCbits.LATC0
#define RC0_PORT                 PORTCbits.RC0
#define RC0_WPU                  WPUCbits.WPUC0
#define RC0_OD                   ODCONCbits.ODC0
#define RC0_ANS                  ANSELCbits.ANSC0
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()           PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetPushPull()        do { ODCONCbits.ODC0 = 0; } while(0)
#define RC0_SetOpenDrain()       do { ODCONCbits.ODC0 = 1; } while(0)
#define RC0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define RC0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set RC1 aliases
#define RC1_TRIS                 TRISCbits.TRISC1
#define RC1_LAT                  LATCbits.LATC1
#define RC1_PORT                 PORTCbits.RC1
#define RC1_WPU                  WPUCbits.WPUC1
#define RC1_OD                   ODCONCbits.ODC1
#define RC1_ANS                  ANSELCbits.ANSC1
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()           PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetPushPull()        do { ODCONCbits.ODC1 = 0; } while(0)
#define RC1_SetOpenDrain()       do { ODCONCbits.ODC1 = 1; } while(0)
#define RC1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define RC1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

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