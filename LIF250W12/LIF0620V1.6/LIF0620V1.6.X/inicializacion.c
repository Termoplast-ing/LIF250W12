/*
 * File:   inicializacion.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 3 de abril de 2020, 17:26
 * Version: 1.2
 * version main: 1.2

 */

#include "ds1820.h"
#include "inicializacion.h"
#include "calibracion.h"
#include <xc.h>
#include <pic18f25k22.h>

#define _XTAL_FREQ  4000000

void inicializacion(void) {
    
  
    //lee la posicion 00h de la mem eeprom que contiene el valor de set point//
    resetWatch = 0;
    for(q = 0; q < 8 ; q++){                                                    //bucle para llamar todos los parametros en memoria eeprom
        EEADR = q ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        switch(q){                                                                  //se le asigna a la variable el valor leido en la posicion 00h de la mem eeprom
            case 0:{
               setPoint = EEDATA;
               break;
            }
            case 1:{
                SPFxBaj = EEDATA;
                break;
            }
            case 2:{
                SPFxAlt = EEDATA; 
            break;
            }
            case 3:{
                SPFxSen = EEDATA;
            break;
            }
            case 4:{
                CTRauto = EEDATA;
            break;
            }
            case 5:{
                setPotMan = EEDATA;
            break;
            }
            case 6:{
                offSet = EEDATA;
            break;
            }
            
        }                                                  
    }
    q = 0;
    
    ///////iniciliza y configura los puertos y hace la prueba de lampara////////
    resetWatch = 0;
    TRISA = 0x3f;                                                               //define las entradas y salidas del puerto A
    TRISB = 0b000001;                                                           //define las entradas y salidas del puerto B    
    TRISC = 0x00;                                                               //define las entradas y salidas del puerto C    
    ANSELA= 0x00;                                                               //define que las entradas del puerto A sean digitales 
    ANSELB = 0x00;
    ANSELC = 0x00;
    PORTA = 0;                                                                  //inicializa en 0 el puerto A
    PORTB = 0b000000;                                                           //inicializa en 0 el puerto B
    PORTC =0xff;                                                                //inicializa en 0 el puerto C

    ////////////inicializacion y configuracion interrupcion timer 0/////////////
    resetWatch = 0;
    T0CONbits.TMR0ON = 0;                                                       //temporizador apagado
    T0CONbits.T08BIT = 1;                                                       //temporizador de 8 bit
    T0CONbits.T0CS = 0;                                                         //ciclo de reloj interno (CLKOUT)
    T0CONbits.T0SE = 0;                                                         //incrementa en el flanco ascendente T0CKI pin
    T0CONbits.PSA = 0;                                                          //se le asigna un preescaler
    T0CONbits.T0PS = 0b010;                                                     //se configura un preescaler de 8
    TMR0H = 0x00;                                                               //se le asigna 0 al byte mas significativo del carga del timer 0 xq trabaja en 8 bit este
    TMR0L = 0x06;                                                               //se le asigana 6 al byte de carga del timer para un timer de 1ms TMR0 = 256 - ( 2ms / ( 1us x 8))
    INTCONbits.TMR0IF = 0;                                                      //pone a 0 el flag de desbordamiento del timer, cuando se desborda se pone a 1 
    INTCONbits.TMR0IE = 1;                                                      //en 1 habilita la interrupcion por desbordamiento
    INTCON2bits.TMR0IP = 0;                                                     //en 1 lo asigna como alta prioridad al timer
    RCONbits.IPEN = 1;                                                          //habilita la prioridad de niveles de interrupcion
    INTCONbits.GIEH = 1;                                                        //habilita todas las interruciones de alta prioridad  
    INTCONbits.GIEL = 1;
    
    /////////////////////////////////calibracion////////////////////////////////
    if((PORTAbits.RA3==0)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==0)){
        for(l=0 ; l < 10 ; l++){
            __delay_ms(1);
        }
        if((PORTAbits.RA3==0)&&(PORTAbits.RA4==0)&&(PORTAbits.RA5==0)){
            calibracion();
        }
    }
   
    resetWatch = 0;
    INTCONbits.PEIE = 1;
    INTCONbits.INT0IE = 0;
    INTCONbits.INT0IF = 0;     
    INTCON2bits.INTEDG0 = 1;
    T1CONbits.TMR1CS = 0b00;
    T1CONbits.T1CKPS= 0b00;
    T1CONbits.T1SOSCEN = 0;
    T1CONbits.T1RD16 = 0;
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 0;
    IPR1bits.TMR1IP = 1;
    TMR1L = 0x78;
    TMR1H = 0xec;
            
    /////////////////////////////prueba de lamparas/////////////////////////////
    
    
    
    /*for(q = 0 ; q < 7 ; q++ ){                                                  //bucle para altenear
                                                                                //el segmento que enciende
        for(r = 0 ; r < 100 ; r++){                                             //bucle que va
            __delay_ms(1);                                                      //prendiendo los distintos 
            PORTB = PORTB + 0b1;                                               //display por aprox
            if(PORTB > 0b1010){                                                   //durante 200 ms
                PORTB = 0b0000;                                                   // cada segmento
              
            }
        }
        PORTC = PORTC << 1  ;
    }*/
    PORTC = 0xff;                                                               //apaga todos los segmentos
    PORTB= 0b11110;
    /*
    while(PORTAbits.RA3 == 1){
        PORTB= 0b1101;
        __delay_ms(5);
        PORTB= 0b1100;
        __delay_ms(5);
    }
    while(PORTAbits.RA4==1){
        PORTB= 0b1010;
        __delay_ms(5);
        PORTB= 0b1011;
        __delay_ms(5);
    }
    while(PORTAbits.RA5 ==1){
        
        PORTB = 0b1010;
        __delay_ms(5);
        PORTB = 0b1011;
        __delay_ms(5);
        PORTB = 0b1101;
        __delay_ms(5);
        PORTB = 0b1100;
        __delay_ms(5);
    }*/

    ////////////////////////enciende el timer0 y el PWM////////////////////////
   // setPoint = 50;
   // SPFxBaj = 15;
   // SPFxAlt = 15; 
   /// SPFxSen = 50;
   // CTRauto = 0;
   // setPotMan = 50;
   // offSet = 16;
  //  setDefault = 0;
    resetWatch = 0;
    ds1820(1,1);
    ds1820(1,2);
                                                       //enciende el PWM
    T0CONbits.TMR0ON = 1;                                                       //temporizador encendido
    INTCONbits.INT0IE = 1;
}