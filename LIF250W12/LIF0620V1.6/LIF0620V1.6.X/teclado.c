/*
 * File:   teclado.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 8 de abril de 2020, 7:53
 * Version: 1.2
 * version main: 1.2
 */

#include "teclado.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

void teclado(void){
    INTCONbits.INT0E = 1;
    resetWatch = 0;
    
    if((PORTAbits.RA3 == 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA5 == 1)){
        __delay_ms(1);
        if(PORTAbits.RA3==0){
            up++;
        }
    }
    
    if((PORTAbits.RA4 == 0) && (PORTAbits.RA3 == 1) && (PORTAbits.RA5 == 1)){
        __delay_ms(1);
        if(PORTAbits.RA4==0){
            down++;
        }
    }
    
    if((PORTAbits.RA5== 0) && (PORTAbits.RA4 == 1) && (PORTAbits.RA3 == 1)){
        __delay_ms(1);
        if(PORTAbits.RA5==0){
            enter++;
        }
    }
    
    if((up > 5) && (PORTAbits.RA3 == 1)){
        tecla=0b00000001;
        up=0x00;
    }
    if((down > 5) && (PORTAbits.RA4 == 1)){
        tecla=0b00000010;
        down=0x00;
    }
 //   if(enter > 120){
 //       enter =  0;
  //  }
    if((enter > 3) && (PORTAbits.RA5 == 1)){
        if(enter < 150){
                tecla = 0b00000100;
        }if((enter <= 350)&&(enter >= 150)){
                tecla = 0b00001000;
        }if(enter > 350){
                tecla = 0b00010000;
        }
        enter = 0x00;
    }
    resetWatch = 0;
    return;
}

