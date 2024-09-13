/*
 * File:   main.c
 * Author: Brian Avila
 *
 * Created on 3 de abril de 2020, 17:25
 */

// PIC18F25K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 250       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = SWON       // Watchdog Timer Enable bits (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<5:0> pins are configured as digital I/O on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTB5   // ECCP2 B output mux bit (P2B is on RB5)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = ON        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = ON      // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = ON       // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = ON      // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = ON       // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <pic18f25k22.h>


/*// PIC18F25K22 Configuration Bit Settings

// 'C' source line config statements

//CONFIG1H


#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 190       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = OFF      // Watchdog Timer Enable bits (Watch dog timer is always disabled. SWDTEN has no effect.)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTB5   // ECCP2 B output mux bit (P2B is on RB5)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.*/

#include <xc.h>
#include "ds1820.h"
#include "display.h"
#include "teclado.h"
#include "inicializacion.h"
#include "menu.h"
#include "conversionTemp.h"
#include "alarma.h"
#include "salidaPotencia.h"
#define _XTAL_FREQ 4000000

char selMenu = 0;
char setPoint = 0;                                
char SPFxBaj = 0;
char SPFxAlt = 0;
char SPFxSen = 0;
char CTRauto = 0;
char setPotMan = 0;
char setDefault = 0;
char pass =0;
char pass0 = 0;
char pass1 = 0;
char pass2 = 0;
char potSal = 0;
char dig[10] = {0,0,0,0,0,0,0,0,0,0};
char i = 0;
char auxPass = 0;
char offSet = 0;
char auxoffSet = 0;
char nsen = 0;
char alarma2 = 0; 
char alarma1 = 0;
char lectScrat1[9] = {0,0,0,0,0,0,0,0,0};
char lectRom1[8] = {0,0,0,0,0,0,0,0};
char lectScrat2[9] = {0,0,0,0,0,0,0,0,0};
char lectRom2[8] = {0,0,0,0,0,0,0,0};
char operacion = 0;
char deciTemp1 = 0;
char convTemp1 = 0;
char deciTemp2 = 0;
char convTemp2 = 0;
unsigned int conversion1  = 0;
unsigned int conversion2  = 0;
char lectura1  = 0;
char lectura2  = 0;
 char aux1 = 0;
 char aux2 = 0;
 char tempDisplay = 0;
 char tempDecimal = 0;
char tempNeg = 0;
 char tempDisplay1 = 0;
 char tempNeg1 = 0;
char tempNeg2 = 0;
char tempDeci1 = 0;
char tempDeci2 = 0;
char alarmaLectura = 0;
int unsigned salPotencia = 0;
int z = 150;
char salPotenciaAux0 = 0;
char salPotenciaAux1 = 0;
char auxDisp = 0;
char ii = 0;
int unsigned salPotenciaAux = 0;
unsigned long tiempoAlarma = 0;
char alarmaFxBaj = 0;
char estable = 0;
char alarmaSensor1 = 0;
char alarmaSensor2 = 0;
char alarmaFxSen = 0;
char alarmaFxAlt = 0;
char alarmLect1 = 0;
char alarmLect2 = 0;
char pilotoAlarma = 0;
char pilotoAlarmaAUX = 0;
char flagLED = 0;
char ManAuto = 0;
char pilotoSensor = 0;
char pilotoSensorAUX = 0;
char setPointAUX = 0;
char teclaAUX = 0;
char alarmaLamp1 = 0;
char alarmaLamp2 = 0;
char alarmaLampAux = 0;
int resetWatch = 0;
char aux10;
char aux11;
char aux20;
char aux21;
char auxRSTsensor;
char auxfallatemp1;
char auxfallatemp2;
char parametros[8] = {0,0,0,0,0,0,0,0};


char tecla = 0;

void __interrupt(high_priority) myIsr(void){
    
    if(PIR1bits.TMR1IF == 1){
        
        PIE1bits.TMR1IE = 0;
        INTCONbits.INT0E = 1;
        PIR1bits.TMR1IF = 0;
        if(salPotencia>=15){
            PORTBbits.RB5 = 1; 
            __delay_us(20);
            if(salPotencia<95){
                PORTBbits.RB5 = 0;
            }
        }
        resetWatch++;
        INTCONbits.INT0E = 1;
}

    if(INTCONbits.INT0IF==1){
        if(resetWatch > 10000){
            WDTCONbits.SWDTEN=1;
        }else{
               WDTCONbits.SWDTEN=0;
        }
        PIE1bits.TMR1IE = 0;
        INTCONbits.INT0E = 1;
        INTCONbits.INT0IF=0;
        PIR1bits.TMR1IF = 0;
        TMR1L = salPotenciaAux0;
        TMR1H = salPotenciaAux1; 
        T1CONbits.TMR1ON = 1;
        PIE1bits.TMR1IE = 1;
  
 
    
    /*
        PIR1bits.TMR1IF = 0;
        TMR1L = salPotenciaAux0;
        TMR1H = salPotenciaAux1;        
        PIE1bits.TMR1IE = 1;
        T1CONbits.TMR1ON = 1;
        INTCONbits.INT0E = 1;
        INTCONbits.INT0IF = 0;
    }else{
    
    //if(PIR1bits.TMR1IF == 1){
        PORTBbits.RB5 = 1; 
        __delay_us(10);
        PORTBbits.RB5 = 0; 
        resetWatch++;
        INTCONbits.INT0F = 0;
        INTCONbits.INT0E = 1;
        PIE1bits.TMR1IE = 0;
        T1CONbits.TMR1ON = 0;
        
    }
    INTCONbits.GIE = 1;
    INTCONbits.PEIE =1;*/

}  
    /*if(INTCONbits.INT0IF == 1){
        
        INTCONbits.INT0E = 0;
        PIE1bits.TMR1IE = 0;
        INTCONbits.INT0IF = 0;
        TMR1L = salPotenciaAux0;
        TMR1H = salPotenciaAux1;
        PIR1bits.TMR1IF = 0;
        PIE1bits.TMR1IE = 0b1;
        INTCONbits.INT0E = 1;
        T1CONbits.TMR1ON = 1;
        
    }
    
    if(PIR1bits.TMR1IF == 1){
        
        INTCONbits.INT0E = 0;
        
        PIE1bits.TMR1IE = 0;
        PIR1bits.TMR1IF = 0;
        T1CONbits.TMR1ON = 0;
        PORTBbits.RB5 = 1;
 //       for(ii = 0; i < 50 ; ii++){
   //         PORTBbits.RB5 = 1;
   //     }
        __delay_us(5);
        PORTBbits.RB5 = 0;
        INTCONbits.INT0E = 1;*/
        
}

void __interrupt(low_priority) myLoIsr(void){
    
    
  INTCONbits.INT0E = 1;
    T0CONbits.TMR0ON = 0; 
    INTCONbits.TMR0IF = 0;
    
    resetWatch++;
    if(resetWatch >30000){
        resetWatch = 10001;
    }
    
    tiempoAlarma ++;
    if(tiempoAlarma > 65000){
        tiempoAlarma = 38001;
    }
    INTCONbits.PEIE=1;
    auxfallatemp1 ++;
    auxfallatemp2 ++;
    z++;
    if(z > 20000){
        z = 151;
    }
    
    if(selMenu == 8){
        switch(pass){
            case 0:{
                if(auxPass > 40){
                    dig[3]=0xff;
                }
            break;
            }
            case 1:{
                if(auxPass > 40){
                    dig[4]=0xff;
                }
            break;
            }
            case 2:{
                if(auxPass > 40){
                    dig[5]=0xff;
                }
            break;
            }
        }
        auxPass++;
        if(auxPass > 80){
            auxPass = 0x00;
        }
    }
            for(i = 0 ; i < 10 ; i++){

                PORTC = 0xff;
                auxDisp= i;
                auxDisp = auxDisp << 1;
                PORTB = PORTB & 0b11100001;
                PORTB = PORTB + auxDisp;
                __delay_us(80);
                PORTC = dig[i];
                __delay_ms(1);
                PORTC = 0xff;
            }
    if((pilotoAlarma == 0) && (pilotoSensor == 1)){
        PORTB = PORTB & 0b11100001;
        if(pilotoSensorAUX < 50){
            PORTB = PORTB & 0b11100001;
            PORTB = PORTB + 0x18;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            PORTB = PORTB + 0x1a;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            pilotoSensorAUX ++;
        }
        if(pilotoSensorAUX >= 50){
            PORTB = PORTB & 0b11100001;
            __delay_ms(1);
            pilotoSensorAUX ++;
            if(pilotoSensorAUX >100){
                pilotoSensorAUX = 0;
            }
        }
    }
    resetWatch++;
    if(resetWatch >30000){
        resetWatch = 10001;
    }
    if((pilotoAlarma == 0) && (pilotoSensor == 0)){
    for(char a = 13; a > 9 ; a--){
        PORTB = PORTB & 0b11100001; 
        switch(a){
            case 10:{
                if(estable > 0){
                    PORTB = PORTB | 0x14;
                    __delay_ms(1);
                }
                break;
            }
            case 11:{
                if(ManAuto > 0){
                        PORTB = PORTB | 0x16;
                        __delay_ms(1);
                    }
                    break;
            }
            case 12:{
                if((alarmaSensor2 > 0) || (alarmaLamp2 > 0)){
                    
                    if(alarmaSensor2 > 0){
                    PORTB = PORTB | 0x18;
                    __delay_ms(1);
                }
                    if(alarmaLamp2 > 0){
                        if(alarmaLampAux < 50){
                            alarmaLampAux++;
                            PORTB = PORTB | 0x18;
                            __delay_ms(1);
                        }else{
                            alarmaLampAux++;
                            if(alarmaLampAux > 100){
                                alarmaLampAux = 0;
                            }
                        }
                    }
                }
                break;
            }
            case 13:{
                if((alarmaSensor1 > 0)|| (alarmaLamp1 > 0)){
                    if(alarmaLamp1 > 0){
                        if(alarmaLampAux < 50){
                            alarmaLampAux++;
                            PORTB = PORTB | 0x1a;
                            __delay_ms(1);
                        }else{
                            alarmaLampAux++;
                            if(alarmaLampAux > 100){
                                alarmaLampAux = 0;
                            }
                        }
                    }
                    if(alarmaSensor1 > 0){
                        PORTB = PORTB | 0x1a;
                        __delay_ms(1);
                    }
                }
                break;
            }
        }
    }
    }
    if(pilotoAlarma == 1){
        PORTB = PORTB & 0b11100001;
        if(pilotoAlarmaAUX < 50){
            PORTB = PORTB + 0x14;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            PORTB = PORTB + 0x16;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            PORTB = PORTB + 0x18;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            PORTB = PORTB + 0x1a;
            __delay_ms(1);
            PORTB = PORTB & 0b11100001;
            pilotoAlarmaAUX ++;
        }
        if(pilotoAlarmaAUX >= 50){
            PORTB = PORTB & 0b11100001;
            __delay_ms(1);
            pilotoAlarmaAUX ++;
            if(pilotoAlarmaAUX >100){
                pilotoAlarmaAUX = 0;
            }
        }
    }
    resetWatch++;
    if(resetWatch >30000){
        resetWatch = 10001;
    }     
    
    if(resetWatch > 10000){////////
            WDTCONbits.SWDTEN=1;/////////prueba
        }else{////////////////////////
               WDTCONbits.SWDTEN=0;///////////////////
        }///
    
    T0CONbits.TMR0ON = 1; 
    TMR0H = 0x00;                                                               //se le asigna 0 al byte mas significativo del carga del timer 0 xq trabaja en 8 bit este
    TMR0L = 0x06; 
    INTCONbits.PEIE =1;
    
}

    void main(void) {
        
        inicializacion ();
             
        while(1){
            resetWatch = 0;
            INTCONbits.INT0E = 1;
            T0CONbits.TMR0ON = 0; 
            menu();
            T0CONbits.TMR0ON = 1; 
            
            if((lectura1 >2)&&(lectura2>2)){
                lectura1 = 0;
                lectura2 = 0;
                conversion1 = 0;
                conversion2 = 0 ;
            }
            
            if ((conversion1 == 0) /*&& ((alarma1 & 0x0f) < 0x0a)*/ && (conversion2 == 0)){
                conversion1 = 1;
            }if ((lectura1 == 0) && (conversion1 > 1)){
                conversion1 ++;
                    if(conversion1 >200){
                        lectura1 = 1;
                    }
            }if((lectura1 == 2) && !(conversion1 == 0) && (conversion2 == 0)){ /*&& ((alarma2 & 0x0f) < 0x0a)*/
                conversion2 = 1;
            }if((lectura2 == 0) && (conversion2 > 1)&&(lectura1 == 2)){
                conversion2 ++;
                if(conversion2 >200){
                    lectura2 = 1;
                }
            }if(lectura2 == 2){
                lectura1 = 0;
                lectura2 = 0;
                conversion1 = 0;
                conversion2 = 0;
            }
            resetWatch = 0;
            if(tecla == 0){
                TRISAbits.TRISA3=1;
                TRISAbits.TRISA4=1;
                TRISAbits.TRISA5=1;
                teclado();
    }else{
        teclaAUX ++;
       up=0;
        down=0;
      enter=0;
      if((!(tecla==0))&&(!(tecla==0x01))&&(!(tecla==0x02))&&(!(tecla==0x04))&&(!(tecla==0x08))&&(!(tecla==0x10))){
          tecla=0;
      }
    }
    if(teclaAUX > 250){
        teclaAUX = 0;
        tecla = 0;
    }
            TRISAbits.TRISA3=0;
            TRISAbits.TRISA4=0;
            TRISAbits.TRISA5=0;
            display();
            
            if(((aux1>>1)>60 )&&(z>100)){
                
                auxfallatemp1= 0;
                T0CONbits.TMR0ON = 0;
      INTCONbits.TMR0IE = 0;
      TRISAbits.TRISA0 = 0;
      PORTAbits.RA0 = 0;
      TRISAbits.TRISA0 = 1;
                ds1820(1,1);
            ds1820(2,1);
            T0CONbits.TMR0ON = 1;
              INTCONbits.INT0E = 1;
             INTCONbits.TMR0IE = 1;
            while(auxfallatemp1<200){
                }
            INTCONbits.TMR0IE = 0;
      TRISAbits.TRISA0 = 0;
      PORTAbits.RA0 = 0;
      TRISAbits.TRISA0 = 1;
            ds1820(3,1);
            conversionTemp();
                T0CONbits.TMR0ON = 1;
              INTCONbits.INT0E = 1;
             INTCONbits.TMR0IE = 1;
                lectura1 = 0;
                lectura2 = 0;
               conversion1 = 0;
                conversion2 = 0 ;
                }
               if(((((aux2>>1)>60 )&&(z>100)))&&(auxfallatemp2==0)){
                
                   auxfallatemp2= 0;
                   T0CONbits.TMR0ON = 0;
      INTCONbits.TMR0IE = 0;
      TRISAbits.TRISA1 = 0;
      PORTAbits.RA1 = 0;
      TRISAbits.TRISA1 = 1;
                ds1820(1,2);
                ds1820(2,2);
                T0CONbits.TMR0ON = 1;
              INTCONbits.INT0E = 1;
             INTCONbits.TMR0IE = 1;
                while(auxfallatemp2<200){
                }
             INTCONbits.TMR0IE = 0;
      TRISAbits.TRISA1 = 0;
      PORTAbits.RA1 = 0;
      TRISAbits.TRISA1 = 1;
                ds1820(3,2);
                conversionTemp();
                T0CONbits.TMR0ON = 1;
              INTCONbits.INT0E = 1;
             INTCONbits.TMR0IE = 1;
              lectura1 = 0;
              lectura2 = 0;
               conversion1 = 0;
              conversion2 = 0 ;
                }                           

            if(lectura1 == 1){
     //           PIE1bits.TMR1IE = 0;
      // T1CONbits.TMR1ON = 0;

             INTCONbits.INT0E = 1;
             T0CONbits.TMR0ON = 0;
      INTCONbits.TMR0IE = 0;
                    ds1820(3,1);
               T0CONbits.TMR0ON = 1;
              INTCONbits.INT0E = 1;
             INTCONbits.TMR0IE = 1;
            }if(lectura2 == 1){
        //       PIE1bits.TMR1IE = 0;
   //    T1CONbits.TMR1ON = 0;
               INTCONbits.TMR0IE = 0;
             INTCONbits.INT0E = 1;
              T0CONbits.TMR0ON = 0;
                    ds1820(3,2);
                T0CONbits.TMR0ON = 1;
                INTCONbits.INT0E = 1;
                INTCONbits.TMR0IE = 1;
            }if(conversion1 == 1){
  //              PIE1bits.TMR1IE = 0;
  //      T1CONbits.TMR1ON = 0;
                INTCONbits.TMR0IE = 0;
                INTCONbits.INT0E = 1;
                T0CONbits.TMR0ON = 0;
                    ds1820(2,1);
                T0CONbits.TMR0ON = 1;
                INTCONbits.INT0E = 1;
                INTCONbits.TMR0IE = 1;
            }if(conversion2 == 1){
     //           PIE1bits.TMR1IE = 0;
      //  T1CONbits.TMR1ON = 0;
               INTCONbits.TMR0IE = 0;
               INTCONbits.INT0E = 1;
                T0CONbits.TMR0ON = 0;
                    ds1820(2,2);
                T0CONbits.TMR0ON = 1;
                INTCONbits.INT0E = 1;
                INTCONbits.TMR0IE = 1;
            }
            resetWatch = 0;
        //   alarma();
          conversionTemp();
          
            if(z > 150 ){
               alarma();
   //             conversionTemp();

                salidaPotencia();
                z = 0;
            }
if(setPoint> 199){
        EEADR = 0x00 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        setPoint=EEDATA;
    }
    if((SPFxBaj< 15)||(SPFxBaj> 99)){
        EEADR = 0x01 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        SPFxBaj=EEDATA;
    }
    if((SPFxAlt< 15)||(SPFxAlt> 99)){
        EEADR = 0x02 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        SPFxAlt=EEDATA;
    }
    if((SPFxSen< 15)||(SPFxSen> 99)){
        EEADR = 0x03 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        SPFxSen=EEDATA;
    }
    if(CTRauto > 1){
        EEADR = 0x04 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        CTRauto=EEDATA;
    }
    if((setPotMan< 15)||(setPotMan> 99)){
        EEADR = 0x05 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        setPotMan=EEDATA;
    }
    if((offSet == 0)||(offSet > 40)){
        EEADR = 0x06 ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        offSet=EEDATA;
    }
            
            
            
        }
    return;

    }