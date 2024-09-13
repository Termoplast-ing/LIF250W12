/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 16 de abril de 2020, 8:27
 * Version: 1.2
 * version main: 1.2

 */

#include "conversionTemp.h"
#include <xc.h>

char tempAux;

void conversionTemp(void) {
    resetWatch = 0;
    INTCONbits.INT0E = 1;
    if(offSet > 19){
        offSet1 = offSet - 20;
        offSet2 = offSet - 20;
    }if(offSet < 20){
        offSet1 = 20 - offSet;
        offSet2 =  20 - offSet;
    }
        switch(lectRom1[0]){
            case 0x10:{
                aux1=aux10;
                    /*if(lectScrat1[1] == 0){
                        aux1=lectScrat1[0];
                    }if(lectScrat1[1] > 0){
                        aux1=lectScrat1[0]>>1;
                    }*/
                tempNeg1=0;
                if(offSet > 20){
                    aux1 = aux1 + offSet1;
                }if((offSet < 20)&&(offSet1<aux1)){
                    aux1 = aux1 - offSet1; 
                }
                if(aux11 > 0){
                    aux1=~aux10;
                    aux1=aux1+1;
                    tempNeg1=1;
                    if(offSet > 20){
                    aux1 = aux1 - offSet1;
                }if(offSet < 20){
                    aux1 = aux1 + offSet1; 
                }
                }
       //         
                break;
            }
            case 0x28:{
                /*decimal2=lectScrat2[0]&0x08;
                aux2=lectScrat2[0]>>4;
                aux2=aux2&0b00001111;
                if((lectScrat2[1] & 0x01) == 0x01 ){
                    aux2 = aux2 + 0x10;
                }if((lectScrat2[1] & 0x02) == 0x02 ){
                    aux2 = aux2 + 0x20;
                }if((lectScrat2[1] & 0x04) == 0x04 ){
                    aux2 = aux2 + 0x40;
                }if((lectScrat2[1] & 0b11111000) >= 0x08){
                    aux2 = aux2 + 0x08;*/
                    
                        aux1=aux10>>3;
                       // aux2 = aux2 & 0b00011111;
                        aux1=aux1&0b00011111;
                        if((aux11 & 0x01) == 0x01 ){
                            aux1 = aux1 + 0x20;
                        }if((aux11 & 0x02) == 0x02 ){
                            aux1 = aux1 + 0x40;
                        }if((aux11 & 0x04) == 0x04 ){
                            aux1 = aux1 + 0x80;
                        }
                        if(offSet > 20){
                    aux1 = aux1 + offSet1;
                }if((offSet < 20)&&(offSet1<aux1)){
                    aux1 = aux1 - offSet1; 
                }
                        tempNeg1=0;
                        if(aux11 >=0x08){
                            aux1=~aux1;
                            aux1=aux1+1;                                   
                            tempNeg1=1;
                            if(offSet > 20){
                    aux1 = aux1 - offSet1;
                }if(offSet < 20){
                    aux1 = aux1 + offSet1; 
                }
                        }
                        break;
                    }
        }
            /*case 0x28:{
                
                    if((lectScrat1[1] & 0b11111000) == 0 ){
                        aux1=lectScrat1[0]>>3;
                        if((lectScrat1[1] & 0x01) == 0x01 ){
                            aux1 = aux1 + 0x20;
                        }if((lectScrat1[1] & 0x02) == 0x02 ){
                            aux1 = aux1 + 0x40;
                        }if((lectScrat1[1] & 0x04) == 0x04 ){
                            aux1 = aux1 + 0x80;
                        }
                       
                    }
                    if((lectScrat1[1] & 0b11111000) > 0){
                        aux1=lectScrat1[0]>>4;
                        if((lectScrat1[1] & 0x01) == 0x01 ){
                            aux1 = aux1 + 0x10;
                        }if((lectScrat1[1] & 0x02) == 0x02 ){
                            aux1 = aux1 + 0x20;
                        }if((lectScrat1[1] & 0x04) == 0x04 ){
                            aux1 = aux1 + 0x40;
                        }
                        aux1 = aux1 + 0x80;
                    }
                }
                break;
            }
*/resetWatch = 0;
        switch(lectRom2[0]){
           /* case 0x10:{
                    if(lectScrat2[1] == 0){
                    aux2=lectScrat2[0];
                    }if(lectScrat2[1] > 0){
                        aux2=lectScrat2[0]>>1;
                    }
            break;
            }*/
            case 0x10:{
                aux2=aux20;
                    /*if(lectScrat1[1] == 0){
                        aux1=lectScrat1[0];
                    }if(lectScrat1[1] > 0){
                        aux1=lectScrat1[0]>>1;
                    }*/
                tempNeg2=0;
                if(offSet > 20){
                    aux2 = aux2 + offSet2;
                }if((offSet < 20)&&(offSet2<aux2)){
                    aux2 = aux2 - offSet2; 
                }
                if(aux21 > 0){
                    aux2=~aux20;
                    aux2=aux2+1;
                    tempNeg2=1;
                    if(offSet > 20){
                    aux2 = aux2 - offSet2;
                }if(offSet < 20){
                    aux2 = aux2 + offSet2; 
                }
                }
                break;
            }
            case 0x28:{
                /*decimal2=lectScrat2[0]&0x08;
                aux2=lectScrat2[0]>>4;
                aux2=aux2&0b00001111;
                if((lectScrat2[1] & 0x01) == 0x01 ){
                    aux2 = aux2 + 0x10;
                }if((lectScrat2[1] & 0x02) == 0x02 ){
                    aux2 = aux2 + 0x20;
                }if((lectScrat2[1] & 0x04) == 0x04 ){
                    aux2 = aux2 + 0x40;
                }if((lectScrat2[1] & 0b11111000) >= 0x08){
                    aux2 = aux2 + 0x08;*/
                    
                        aux2=aux20>>3;
                       // aux2 = aux2 & 0b00011111;
                        aux2=aux2&0b00011111;
                        if((aux21 & 0x01) == 0x01 ){
                            aux2 = aux2 + 0x20;
                        }if((aux21 & 0x02) == 0x02 ){
                            aux2 = aux2 + 0x40;
                        }if((aux21 & 0x04) == 0x04 ){
                            aux2 = aux2 + 0x80;
                        }
                        if(offSet > 20){
                    aux2 = aux2 + offSet2;
                }if((offSet < 20)&&(offSet2<aux2)){
                    aux2 = aux2 - offSet2; 
                }
                        tempNeg2=0;
                        if(aux21>=0x08){
                            aux2=~aux2;
                            aux2=aux2+1;                                   
                            tempNeg2=1;
                            if(offSet > 20){
                    aux2 = aux2 - offSet2;
                }if(offSet < 20){
                    aux2 = aux2 + offSet2; 
                }
                        }
                        break;
                    }
                   /* if((lectScrat2[1] & 0b11111000) > 0){
                        aux2=lectScrat2[0]>>4;
                     //   aux2=aux2 & 0b00001111;
                        if((lectScrat2[1] & 0x01) == 0x01 ){
                            aux2 = aux2 + 0x10;
                        }if((lectScrat2[1] & 0x02) == 0x02 ){
                            aux2 = aux2 + 0x20;
                        }if((lectScrat2[1] & 0x04) == 0x04 ){
                            aux2 = aux2 + 0x40;
                        }
                        aux2 = aux2 + 0x80;*/
            }


        
     
        resetWatch = 0;
        
        if((alarmLect1==0)&&(alarmLect2==0)&&(alarma1==0)&&(alarma2==0)&&(alarmaLamp1==0)&&(alarmaLamp2==0)){
            tempDisplay = (aux1 + aux2)>>2;
            tempDisplay = tempAnterior + tempDisplay;
            tempDecimal = tempDisplay & 0x01;
            tempDisplay = tempDisplay >> 1;
            tempAnterior = tempDisplay;
            
            
        
        
/*if((alarmLect1==0)&&(alarmLect2==0)&&(alarma1==0)&&(alarma2==0)&&(alarmaLamp1==0)&&(alarmaLamp2==0)) { 
    
        if((tempNeg1==0) && (tempNeg2==0)){
            tempDeci1=aux1&0x01;
            tempDeci2 = aux2 & 0x01;
            aux1=aux1>>1;
            aux2=aux2>>1;
            
            if((tempDeci1==0)&&(tempDeci2==0)){
                tempDecimal=0;
                tempProm = (aux1 + aux2)>>1;
            }
            
            if(((tempDeci1==0)&&(tempDeci2==1))||((tempDeci1==1)&&(tempDeci2==0))){
                tempDecimal=0;
                tempProm = (aux1 + aux2)>>1;
            }
            
            if((tempDeci1==1)&&(tempDeci2==1)){
                tempDecimal = 1;
                tempProm = ((aux1 + aux2 +1)>>1);
            }
            
            tempNeg=0;
            tempDisplay = (tempProm + tempAnterior)>>1;
            tempAnterior = tempProm;
            
        }
        if((tempNeg1==1)&&(tempNeg2==1)){
            tempDisplay = 200;
            tempNeg = 1;
        }else{
            if(tempNeg1==1){
                tempDeci2 = aux2 & 0x01;
                tempNeg=tempNeg2;
                tempDisplay=((aux2>>1) + tempAnterior)>>1;
                tempAnterior=aux2>>1;
            }
            if(tempNeg2==1){
                tempDeci1 = aux1 & 0x01;
                tempNeg=tempNeg1;
                tempDisplay=((aux1>>1) + tempAnterior)>>1;
                tempAnterior=aux1>>1;
            }
        }
   /* if((tempNeg1==1)&&(tempNeg2==1)){
            tempDeci1=aux1&0x01;
            tempDeci2 = aux2 & 0x01;
            aux1=aux1>>1;
            aux2=aux2>>1;
            
            if((tempDeci1==0)&&(tempDeci2==0)){
                tempDecimal=1;
                tempProm = (aux1 + aux2)>>1;
            }
            
            if(((tempDeci1==0)&&(tempDeci2==1))||((tempDeci1==1)&&(tempDeci2==0))){
                tempDecimal=0;
                tempProm = (aux1 + aux2)>>1;
            }
            if((tempDeci1==1)&&(tempDeci2==1)){
                tempDecimal = 1;
                tempProm = ((aux1 + aux2 +1)>>1);
            }
            tempNeg=1;
            tempDisplay = (tempProm + tempAnterior)>>1;
            tempAnterior = tempProm;
        }
    
        if(((tempNeg1==1)&&(tempNeg2==0))||((tempNeg1==0)&&(tempNeg2==1))){
            tempDeci1 = aux1 & 0x01;
            tempDeci2 = aux2 & 0x01;
            aux1=aux1>>1;
            aux2=aux2>>1;
        
            if((tempDeci1==0)&&(tempDeci2==0)){
                tempDecimal=1;
                if (aux1 > aux2){
                    tempProm=(aux1-aux2)>>1;
                    tempNeg=tempNeg1;
                }if (aux2 > aux1){
                    tempProm=(aux2-aux1)>>1;
                    tempNeg=tempNeg2;
                }
            }
            if(((tempDeci1==0)&&(tempDeci2==1))||((tempDeci1==1)&&(tempDeci2==0))){
                tempDecimal=1;
                if (aux1 > aux2){
                    tempProm=(aux1-aux2-1)>>1;
                    tempNeg=tempNeg1;
                }if (aux2 > aux1){
                    tempProm=(aux2-aux1-1)>>1;
                    tempNeg=tempNeg2;
                }
            }
            if((tempDeci1==1)&&(tempDeci2==1)){
                tempDecimal = 0;
                if (aux1 > aux2){
                    tempProm = ((aux1 - aux2)>>1);
                    tempNeg=tempNeg1;
                }if (aux2 > aux1){
                    tempProm = ((aux2 - aux1)>>1);
                    tempNeg=tempNeg2;
                }
            }
            tempDisplay = (tempProm + tempAnterior)>>1;
            tempAnterior = tempProm;
        }*/
}
        if((((alarmLect1==1)||(alarma1>0))&&((alarma2==0)&&(alarmLect2==0)))||(alarmaLamp1 > 0)){
            tempDeci2 = aux2 & 0x01;
            tempNeg=tempNeg2;
            tempDisplay=((aux2>>1) + tempAnterior)>>1;
            tempAnterior=aux2>>1;
        }
        if((((alarmLect2==1)||(alarma2>0))&&((alarma1==0)&&(alarmLect1==0)))||(alarmaLamp2 > 0)){
            tempDeci1 = aux1 & 0x01;
            tempNeg=tempNeg1;
            tempDisplay=((aux1>>1) + tempAnterior)>>1;
            tempAnterior=aux1>>1;
        }
        if(((alarma1>0)||(alarmLect1==1))&&((alarma2>0)||(alarmLect2==1))){
            alarmaLectura=1;
        }else{
           alarmaLectura=0;
        }
    resetWatch = 0;
        
        /*/////////
        
       /* if((alarmaSensor2==0)&&(alarmaSensor1==0)){
            if((tempNeg1==0)&&(tempNeg2==0)){
            tempAnterior = tempAux;
            tempAux = aux1 + aux2;
            tempDisplay = (tempAux + tempAnterior)>>2;
        }
        }
        if((alarmaSensor2==1)&&(alarmaSensor1==0)){
            tempAnterior = tempAux;
            tempAux = aux1 + tempAnterior;
            tempDisplay = tempAux >>1;
        }  
        if((alarmaSensor2==0)&&(alarmaSensor1==1)){
            tempAnterior = tempDisplay;
            tempAux = aux2 + tempAnterior;
            tempDisplay = tempAux >>2;
        } 
            
         */   
            
        
                    
        
        
        
   return;    
}

