/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  dsPIC33CK256MP508
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/uart1.h"
#include "SST25xx.h"
#include "SPI_MAX6675.h"
#ifndef FCY
#define FCY (_XTAL_FREQ / 2)
#endif
#include <libpic30.h>
#include <string.h>
/*
                         Main application
 */

int main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    SST_Init();
    while (1)
    {
      /*example code for page data*/
        // Add your application code
//        SST_Sector_Erase(0x100);
//        const char dataWrite1[]= "rpcvn.shop";
//        uint8_t readBufer[10];
//        SST_Sector_Erase(0x100);
//        SST_Write_nByte(0x100,strlen(dataWrite1)+1,dataWrite1);
//        SST_Read_nByte(0x100,strlen(dataWrite1)+1,readBufer);
//        printf("Read Data %s",readBufer);
//        printf("\n");
//        __delay_ms(1000);
       
            uint16_t temperatureC = Max6675_Read_TempC();
            if (temperatureC != 0xFFFF)
            {
                SST_Sector_Erase(0x100);
                SST_Write_Byte(0x100,temperatureC);
                uint16_t tempCValue=SST_Read_Byte(0x100);
//                printf("Temperature: %d C\n", temperatureC);
                printf("TemperatureC: %02d C\n", tempCValue);
               __delay_ms(1000);
            }
            SST_Sector_Erase(0x90);
            uint16_t temperatureF = Max6675_Read_TempF();
            SST_Write_Byte(0x90,temperatureF);
            uint16_t tempFValue=SST_Read_Byte(0x90);
            printf("TemperatureF: %02d F\n", tempFValue);
//             printf("Temperature: %d F\n", temperatureF);
             __delay_ms(1000);
            
            
    }
    return 1; 
}
/**
 End of File
*/

