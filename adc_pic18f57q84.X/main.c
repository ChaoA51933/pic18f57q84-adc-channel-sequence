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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F57Q84
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

static void ADC_UserContext4Threshold_ISR(void)
{
    //Add your interrupt code here or
    //Use ADC_SetContext4ThresholdInterruptHandler() function to use Custom ISR
   
    static adc_result_t convertedValue1, convertedValue2, convertedValue3, convertedValue4;

    ADC_SelectContext(0);  
    convertedValue1 = ADC_GetConversionResult();
    if (ADPCH == channel_ANA1)
    {
        ADPCH = channel_ANA0;
    }
    else
    {
        ADPCH = channel_ANA1;
    }
        
    ADC_SelectContext(1);  
    convertedValue2 = ADC_GetConversionResult();
    if (ADPCH == channel_ANA1)
    {
        ADPCH = channel_ANA0;
    }
    else
    {
        ADPCH = channel_ANA1;
    }
    
    ADC_SelectContext(2);  
    convertedValue3 = ADC_GetConversionResult();
    if (ADPCH == channel_ANA1)
    {
        ADPCH = channel_ANA0;
    }
    else
    {
        ADPCH = channel_ANA1;
    }
    
    ADC_SelectContext(3); 
    convertedValue4 = ADC_GetConversionResult();
    if (ADPCH == channel_ANA1)
    {
        ADPCH = channel_ANA0;
    }
    else
    {
        ADPCH = channel_ANA1;
    }
    
    // the following 3 line is for next auto context sequence scan.
    // Otherwise start from context 4, not from context 1.
    ADC_DisableChannelSequencer();
    ADC_SelectContext(CONTEXT_1);
    ADC_EnableChannelSequencer();     

 
    IO_RF3_Toggle();
    
    printf("Contex1 AN: %d\r\n", convertedValue1);
    printf("Contex2 AN: %d\r\n", convertedValue2);
    printf("Contex3 AN: %d\r\n", convertedValue3);
    printf("Contex4 AN: %d\r\n", convertedValue4);
    printf("\r\n");
}

/*
                         Main application
 */
void main(void)
{
    static adc_result_t convertedValue1, convertedValue2, convertedValue3, convertedValue4;    
    static adc_result_t convertedValue;
    // Initialize the device
    SYSTEM_Initialize();
    
    // Set Interrupt Handler
    ADC_SetContext4ThresholdInterruptHandler(ADC_UserContext4Threshold_ISR);
    
    ADC_DisableChannelSequencer();
    ADC_SelectContext(CONTEXT_1);
    ADC_EnableChannelSequencer();     
    
    TMR0_StartTimer();    

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    while (1)
    {
        // Add your application code
    }
}
/**
 End of File
*/