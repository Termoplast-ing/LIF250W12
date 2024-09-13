/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 11 de abril de 2020, 11:00
 * Version: 1.2
 * version main: 1.2

 */

#include "calibracion.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

char conv(char dig){
    
    switch (dig) {
        case 0:{//0
            digito = 0xc0;
            break;
        }case 1:{//1
            digito = 0xf9;
            break;
        }
        case 2:{//2
            digito = 0xa4;
            break;
        }
        case 3:{//3
            digito = 0xb0;
            break;
        }
        case 4:{//4
            digito = 0x99;
            break;
        }
        case 5:{//5
            digito = 0x92;
            break;
        }
        case 6:{//6
            digito = 0x82;
            break;
        }
        case 7:{//6
            digito = 0xf8;
            break;
        }
        case 8:{//6
            digito = 0x80;
            break;
        }
        case 9:{//9
            digito = 0x90;
            break;
        }
        case 10:{//a
            digito = 0xA0;
            break;
        }
        case 11:{//b
            digito = 0x83;
            break;
        }
        case 12:{//c
            digito = 0x86;
            break;
        }
        case 13:{//d
            digito = 0xA1;
            break;
        }
        case 14:{//e
            digito = 0x84;
            break;
        }
        case 15:{//f
            digito = 0x8E;
            break;
        }
    }
    return(digito);
}

void calibracion(void) {
    resetWatch = 0;
    for(q = 0 ; q <= 8 ; q++ ){  
        
        
        while(PORTAbits.RA3 == 1){
        resetWatch = 0;
            PORTB=r;
            __delay_ms(1);
            r=r+2;
            if(r == 0x14){
                r=0;
            }
        }
        while(PORTAbits.RA3 == 0){
           resetWatch = 0; 
        }
        PORTC=PORTC<<1;
    }
    PORTC=0xFF;
    while (PORTAbits.RA4 == 1){
        PORTB= 0x01a;
        __delay_ms(1);
        resetWatch = 0;
    }
    while(PORTAbits.RA4 == 0){
        resetWatch = 0;
    }
    while(PORTAbits.RA4==1){
        PORTB= 0x1a;
        __delay_ms(1);
        PORTB= 0x18;
        __delay_ms(1);
        resetWatch = 0;
 
    }
    while(PORTAbits.RA4 == 0){
        resetWatch = 0;
    }
    while(PORTAbits.RA4 ==1){
        
        PORTB= 0x1a;
        __delay_ms(1);
        PORTB= 0x18;
        __delay_ms(1);
        PORTB= 0x16;
        __delay_ms(1);
        resetWatch = 0;
    }
    while(PORTAbits.RA4 == 0){
        resetWatch = 0;
    }
    while(PORTAbits.RA4 ==1){
        
        PORTB= 0x1a;
        __delay_ms(1);
        PORTB= 0x18;
        __delay_ms(1);
        PORTB= 0x16;
        __delay_ms(1);
        PORTB= 0x14;
        __delay_ms(1);
        resetWatch = 0;
    }
    while(PORTAbits.RA4 == 0){
        resetWatch = 0;
    }
    resetWatch = 0;
    ds1820(1,1);
    PORTC=0xFF;
    while(PORTAbits.RA5 ==1){
        dig[0]=0x92;
        PORTC = dig[0];
        PORTB=0x00;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[1]=0x84;
        PORTC = dig[1];
        PORTB=0x02;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[2]=0xF9;
        PORTC = dig[2];
        PORTB=0x04;
        __delay_ms(1);
        PORTB = 0b00011110;
        resetWatch = 0;
    
        if(presencia1 == 1){
            resetWatch = 0;
            dig[4]=0xAB;
            PORTC = dig[4];
            PORTB=0x08;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[5]=0xA3;
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=0x92;
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=0x82;
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
        }else{
            resetWatch = 0;
            if(lectRom1[0]== 0x28){
                dig[3]=0xF9;
                PORTC = dig[3];
                PORTB=0x06;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[4]=0x80;
                PORTC = dig[4];
                PORTB=0x08;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[5]=0x83;
                PORTC = dig[5];
                PORTB=0x0A;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[7]=0xA4;
                PORTC = dig[7];
                PORTB=0x0E;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[8]=0xC0;
                PORTC = dig[8];
                PORTB=0x10;
                __delay_ms(1);
                PORTB = 0b00011110;
            }
            if(lectRom1[0]== 0x10){
                dig[3]=0xF9;
                PORTC = dig[3];
                PORTB=0x06;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[4]=0x80;
                PORTC = dig[4];
                PORTB=0x08;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[5]=0x92;
                PORTC = dig[5];
                PORTB=0x0A;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[7]=0xA4;
                PORTC = dig[7];
                PORTB=0x0E;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[8]=0xC0;
                PORTC = dig[8];
                PORTB=0x10;
                __delay_ms(1);
                PORTB = 0b00011110;
            }
        }
        
    }
    while(PORTAbits.RA5 == 0){
        resetWatch = 0;
    }
 ds1820(2,1);
        __delay_ms(2000);
        ds1820(3,1);
    while(PORTAbits.RA5 == 1){
        resetWatch = 0;
        dig[0]=0x92;
        PORTC = dig[0];
        PORTB=0x00;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[1]=0x84;
        PORTC = dig[1];
        PORTB=0x02;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[2]=0xF9;
        PORTC = dig[2];
        PORTB=0x04;
        __delay_ms(1);
        PORTB = 0b00011110;
        resetWatch = 0;
        if(presencia1 == 1){
            dig[4]=0xAB;
            PORTC = dig[4];
            PORTB=0x08;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[5]=0xA3;
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=0x92;
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=0x82;
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
        }else{
            resetWatch = 0;
            dig[5]=conv((lectScrat1[0]) & 0x0F);
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[4]=conv((lectScrat1[0]>>4)& 0x0f);
            PORTC = dig[4];
            PORTB=0x08;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=conv((lectScrat1[1]>>4)& 0x0f);
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=conv((lectScrat1[1]>>4)& 0x0f);
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
        }  
    }
        while(PORTAbits.RA5 == 0){
            resetWatch = 0;
    }
    ds1820(1,2);
    while(PORTAbits.RA5 ==1){
        resetWatch = 0;
        dig[0]=0x92;
        PORTC = dig[0];
        PORTB=0x00;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[1]=0x84;
        PORTC = dig[1];
        PORTB=0x02;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[2]=0xA4;
        PORTC = dig[2];
        PORTB=0x04;
        __delay_ms(1);
        PORTB = 0b00011110;
    
        if(presencia2 == 1){
            resetWatch = 0;
            dig[4]=0xAB;
            PORTC = dig[4];
            PORTB=0x08;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[5]=0xA3;
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=0x92;
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=0x82;
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
        }else{
            if(lectRom2[0]== 0x28){
                resetWatch = 0;
                dig[3]=0xF9;
                PORTC = dig[3];
                PORTB=0x06;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[4]=0x80;
                PORTC = dig[4];
                PORTB=0x08;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[5]=0x83;
                PORTC = dig[5];
                PORTB=0x0A;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[7]=0xA4;
                PORTC = dig[7];
                PORTB=0x0E;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[8]=0xC0;
                PORTC = dig[8];
                PORTB=0x10;
                __delay_ms(1);
                PORTB = 0b00011110;
            }
            if(lectRom2[0]== 0x10){
                resetWatch = 0;
                dig[3]=0xF9;
                PORTC = dig[3];
                PORTB=0x06;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[4]=0x80;
                PORTC = dig[4];
                PORTB=0x08;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[5]=0x92;
                PORTC = dig[5];
                PORTB=0x0A;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[7]=0xA4;
                PORTC = dig[7];
                PORTB=0x0E;
                __delay_ms(1);
                PORTB = 0b00011110;
                dig[8]=0xC0;
                PORTC = dig[8];
                PORTB=0x10;
                __delay_ms(1);
                PORTB = 0b00011110;
            }
        }
    }
    while(PORTAbits.RA5 == 0){
        resetWatch = 0;
    }
 ds1820(2,2);
        __delay_ms(5000);
        ds1820(3,2);
    while(PORTAbits.RA5 == 1){
        resetWatch = 0;
        dig[0]=0x92;
        PORTC = dig[0];
        PORTB=0x00;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[1]=0x84;
        PORTC = dig[1];
        PORTB=0x02;
        __delay_ms(1);
        PORTB = 0b00011110;
        dig[2]=0xA4;
        PORTC = dig[2];
        PORTB=0x04;
        __delay_ms(1);
        PORTB = 0b00011110;
        if(presencia2 == 1){
            resetWatch = 0;
            dig[4]=0xAB;
            PORTC = dig[4];
            PORTB=0x08;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[5]=0xA3;
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=0x92;
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=0x82;
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
        }else{
            resetWatch = 0;
            dig[5]=conv((lectScrat2[0]) & 0x0F);
            PORTC = dig[5];
            PORTB=0x0A;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[4]=conv((lectScrat2[0]>>4)& 0x0f);
            PORTC = dig[4];
            PORTB=0x08;            
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[8]=conv(lectScrat2[1]& 0x0f);
            PORTC = dig[8];
            PORTB=0x10;
            __delay_ms(1);
            PORTB = 0b00011110;
            dig[7]=conv((lectScrat2[1]>>4)& 0x0f);
            PORTC = dig[7];
            PORTB=0x0E;
            __delay_ms(1);
            PORTB = 0b00011110;
            resetWatch = 0;
        }  
    }
        while(PORTAbits.RA5 == 0){
            resetWatch = 0;
            
        }
        resetWatch = 0;
        while(PORTAbits.RA5 == 1){
            for(l=0;l<7;l++){
            EEADR = l ;                                                           //seteo la direccion que se va grabar de memoria
                    switch(l){                                                                  //se le asigna a la variable el valor leido en la posicion 00h de la mem eeprom
            case 0:{
               EEDATA = 50;
               break;
            }
            case 1:{
                EEDATA = 99;
                break;
            }
            case 2:{
                EEDATA = 15; 
            break;
            }
            case 3:{
                EEDATA = 50;
            break;
            }
            case 4:{
                EEDATA = 0;
            break;
            }
            case 5:{
                EEDATA = 50;
            break;
            }
            case 6:{
                EEDATA = 16;
            break;
            }
                    }                                                               //cargo el dato que se va a grabar
            resetWatch = 0;
            EECON1bits.CFGS = 0;                                                        //se selecta que se va a usar la memoria eeprom
            EECON1bits.EEPGD = 0;                                                       //se selecta que se va a usar la memoria eeprom
            EECON1bits.WRERR = 0;                                                       //pone a cero la bandera de error
            EECON1bits.WREN = 1;                                                        // habilito escritura
            INTCONbits.GIE = 0;                                                         // desabilito las interrupciones
            EECON2 = 0x55;                                                              // destrabo escritura
            EECON2 = 0xAA;                                                              //destrabo escritura
            EECON1bits.WR = 1;                                                          // empiezo escritura
            INTCONbits.GIE = 1;                                                         // habilito la interrupcion
            INTCONbits.PEIE =1;
            EECON1bits.WREN = 0;                                                        // desabilito escritura
            while (EECON1bits.WR){                                                      // espero hasta que WR se haga 0 por hardware(escritura terminada)
            }
        
            }
        }
while(PORTAbits.RA5 == 0){
    resetWatch = 0;
    
}        
    
        for(l = 0; l < 8 ; l++){                                                //bucle para llamar todos los parametros en memoria eeprom
        resetWatch = 0;
        EEADR = l ;                                                                 //setea que se lea la posicion 00h de la mem eeprom
        EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        switch(l){                                                                  //se le asigna a la variable el valor leido en la posicion 00h de la mem eeprom
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
    l = 0;
        resetWatch = 0;
    return;
}
