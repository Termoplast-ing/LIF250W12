/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 21 de abril de 2020, 12:24
 * Version: 1.2
 * version main: 1.2

 */

#include "salidaPotencia.h"
#include <xc.h>

void salidaPotencia(void) {
    INTCONbits.INT0E = 1;
    resetWatch = 0;
    if(CTRauto == 0){
        w ++;
        if(alarmaFxSen > 0){
            salPotencia = SPFxSen;
        }
        if((alarmaFxSen == 0) && (alarmaFxBaj > 0)){
            salPotencia = SPFxBaj;
        }
        if((alarmaFxSen == 0) && (alarmaFxAlt > 0)){
            salPotencia = SPFxAlt;
        }
        if((alarmaFxSen == 0) && (alarmaFxAlt == 0) && (alarmaFxBaj == 0)){
    tempMuestra = tempDisplay << 1;
    
    if(tempDecimal == 1){
        tempMuestra = tempMuestra & 0b11111110;
        tempMuestra = tempMuestra + 0x01;
    }else{
        tempMuestra = tempMuestra & 0b11111110;
    }
    
    if(tempNeg == 1){
        tempSpPv = setPoint + tempMuestra;
    }else{
        tempSpPv = setPoint - tempMuestra;
        if(tempMuestra > setPoint){
            tempSpPv = 0x00;
        }
    }
    resetWatch = 0;
    if(((setPointAUX - 5) > tempDisplay) || ((setPointAUX + 5) < tempDisplay)){
    salPotenciaAnterior = salPotencia;
    
    denominador = (20*setPoint)/100;
    
    salPotencia = (tempSpPv * 100 ) / denominador;
    }
    
        }
        if(((setPointAUX - 3) > tempDisplay) || ((setPointAUX + 3) < tempDisplay)){
            if((salPotencia > salPotenciaAnterior) && ((salPotencia - salPotenciaAnterior) > 5)){
                salPotenciaAnterior = salPotenciaAnterior + 5;
                salPotencia = salPotenciaAnterior;
                w = 0;
            }
            if((salPotencia < salPotenciaAnterior) && ((salPotenciaAnterior - salPotencia) > 5)){
                salPotenciaAnterior = salPotenciaAnterior - 5;
                salPotencia = salPotenciaAnterior;
                w = 0;
            }
        }else{
            if((tempDisplay > setPointAUX) && (w >2)){
                salPotencia = salPotencia - 3;
                salPotenciaAnterior = salPotencia;
                w=0;
            }
            if((tempDisplay < setPointAUX) && (w >2)){
                salPotencia = salPotencia + 3;
                salPotenciaAnterior = salPotencia;
                w=0;
            }
        }
        /*if ((salPotencia - salPotenciaAnterior) > 5){
            
            salPotencia = salPotenciaAnterior + 5;
            salPotenciaAnterior = salPotenciaAnterior + 5;
        }
        if ((salPotenciaAnterior - salPotencia) > 5){
            
            salPotencia = salPotenciaAnterior + 5;
            salPotenciaAnterior = salPotenciaAnterior + 5;
        }*/
        
    if(salPotencia > 99){
        salPotencia = 99;
    }
    
    if(salPotencia < 15){
        salPotencia = 15;
    }
    if(salPotencia > 93){
     //   INTCONbits.INT0E = 1;
     //   PIE1bits.TMR1IE = 0;
        salPotenciaAux = 0x0258;
    }else{
            salPotenciaAux = 10000 - (salPotencia * 100) ;
           // INTCONbits.INT0E = 1;
           // PIE1bits.TMR1IE = 1;
    }
    
    salPotenciaAux = (0xffff - salPotenciaAux);
    
    salPotenciaAux0 = salPotenciaAux;
    
    salPotenciaAux1 = salPotenciaAux>>8;
    }
    
    if(CTRauto == 1){
        salPotencia = setPotMan;
        if(salPotencia > 93){
     //   INTCONbits.INT0E = 1;
     //   PIE1bits.TMR1IE = 0;
        salPotenciaAux = 0x0258;
    }else{
            salPotenciaAux = 10000 - (salPotencia * 100) ;
           // INTCONbits.INT0E = 1;
           // PIE1bits.TMR1IE = 1;
    }
        salPotenciaAux = (0xffff - salPotenciaAux);
    
    salPotenciaAux0 = salPotenciaAux;
    
    salPotenciaAux1 = salPotenciaAux>>8;
        
    }
    resetWatch = 0;
    /*
    if(salPotencia < 15){
        salPotencia = 15;
    }
    if(salPotencia > 95){
        INTCONbits.INT0E = 0;
        PIE1bits.TMR1IE = 0;
        PORTBbits.RB5 = 1;
    }else{
            salPotenciaAux = 10000 - (salPotencia * 100) ;
            INTCONbits.INT0E = 1;
            PIE1bits.TMR1IE = 1;
    }
    salPotenciaAux = (0xffff - salPotenciaAux);
    
    salPotenciaAux0 = salPotenciaAux;
    
    salPotenciaAux1 = salPotenciaAux>>8;
    }*/
    
    
    
    
    
    return;
}