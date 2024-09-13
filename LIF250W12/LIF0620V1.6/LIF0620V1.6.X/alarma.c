/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 20 de abril de 2020, 9:18
 * Version: 1.2
 * version main: 1.2

 */

#include "alarma.h"
#include <xc.h>

# define _XTAL_FREQ 4000000

char lect00scrat;
char lectffscrat;
char i;
int alarmaSen1AUX;
int alarmaSen2AUX;

void alarma (void) {
    INTCONbits.INT0E = 1;
    /*for(i=0;i<9;i++){
        lect00scrat = lect00scrat + lectScrat1[i];
    }
    for(i=0;i<9;i++){
        lectffscrat = lectffscrat & lectScrat1[i];
    }
    if((lect00scrat == 0) || (lectffscrat == 0xff)||((lectScrat1[0] < 0) && (lectScrat1[1] == 0))||(((lectScrat1[0]==0xff))&&(lectScrat1[1]==0x00))){*/
      resetWatch = 0;  
   if(((lectScrat1[0]== 0)&&(lectScrat1[1]==0)&&(lectScrat1[2]==0)&&(lectScrat1[3]==0)
            &&(lectScrat1[4]==0)&&(lectScrat1[5]==0)&&(lectScrat1[6]==0)&&
            (lectScrat1[7]==0)&&(lectScrat1[8]==0))||((lectScrat1[0]==0xff)&&(lectScrat1[1]==0xff)&&(lectScrat1[2]==0xff)&&
            (lectScrat1[3]==0xff)&&(lectScrat1[4]==0xff)&&(lectScrat1[5]==0xff)
            &&(lectScrat1[6]==0xff)&&(lectScrat1[7]==0xff)&&(lectScrat1[8]==0xff))||(((lectScrat1[0]==0xff))&&(lectScrat1[1]==0x00))||((lectScrat1[0] == 0xff) && (lectScrat1[1] == 0))){
        alarmLect1 = 1;
        
    }else{
        alarmLect1 = 0;
    }
    /*for(i=0;i<9;i++){
        lect00scrat = lect00scrat + lectScrat2[i];
    }
    for(i=0;i<9;i++){
        lectffscrat = lectffscrat & lectScrat2[i];
    }
    if((lect00scrat == 0) || (lectffscrat == 0xff)||((lectScrat2[0] < 0) && (lectScrat2[1] == 0))||(((lectScrat2[0]==0xff))&&(lectScrat2[1]==0x00))){*/
   if(((lectScrat2[0]== 0)&&(lectScrat2[1]==0)&&(lectScrat2[2]==0)&&(lectScrat2[3]==0)
     &&(lectScrat2[4]==0)&&(lectScrat2[5]==0)&&(lectScrat2[6]==0)&&
       (lectScrat2[7]==0)&&(lectScrat2[8]==0))||((lectScrat2[0]==0xff)&&(lectScrat2[1]==0xff)&&(lectScrat2[2]==0xff)&&
       (lectScrat2[3]==0xff)&&(lectScrat2[4]==0xff)&&(lectScrat2[5]==0xff)
     &&(lectScrat2[6]==0xff)&&(lectScrat2[7]==0xff)&&(lectScrat2[8]==0xff))||(((lectScrat2[0]==0xff))&&(lectScrat2[1]==0x00))||((lectScrat2[0] == 0xff) && (lectScrat2[1] == 0))){
   /* if(((lectScrat2[0]&lectScrat2[1]&lectScrat2[2]&lectScrat2[3]&lectScrat2[4]&lectScrat2[5]&lectScrat2[6]&lectScrat2[7]&lectScrat2[8])==0)||
       ((lectScrat2[0]&lectScrat2[1]&lectScrat2[2]&lectScrat2[3]&lectScrat2[4]&lectScrat2[5]&lectScrat2[6]&lectScrat2[7]&lectScrat2[8])==0xff)||
       (((lectScrat2[0]==0xff))&&(lectScrat2[1]==0x00))||((lectScrat2[0] == 0xff) && (lectScrat2[1] == 0))){*/
        alarmLect2 = 1;
    }else{
        alarmLect2 = 0;
    }
   setPointAUX= setPoint>>1;
    
    if((tempDisplay < (setPointAUX+5))&&(tempDisplay > (setPointAUX - 5))){
        tiempoAlarma = 0;
        estable = 1;
      //  flagLED = flagLED + 0x08;
        alarmaFxBaj = 0;
        alarmaFxAlt = 0;
    }else{
    //    flagLED = flagLED - 0x08;
        estable = 0;
    }
    
    if((alarmLect1==0)&&(alarmLect2==0)&&(alarma1==0)&&(alarma2==0)){
        if(aux1>aux2){
            alarmaLamp1 = 0;
            if(aux1-aux2 > 14){
                alarmaLamp2 = 1;
            }else{
            alarmaLamp2 = 0;
        }
        }
        if(aux2 > aux1){
            alarmaLamp2 = 0;
            if(aux2-aux1 > 14){
                alarmaLamp1 = 1;
            }else{
            alarmaLamp1 = 0;
        }
        }
    }
   resetWatch = 0;
    if((tempDisplay > (setPointAUX + 5)) && (tiempoAlarma > 38000)){
        alarmaFxAlt = 1;
        pilotoAlarma = 1;
        estable = 0;
        alarmaFxBaj = 0;
        
    }
    if((tempDisplay < (setPointAUX - 5)) && (tiempoAlarma > 38000)){
        alarmaFxBaj = 1;
        pilotoAlarma = 1;
        estable = 0;
        alarmaFxAlt = 0;
    }
    
    
    if(CTRauto == 1){
        alarmaFxBaj = 0;
        pilotoAlarma = 0;
        estable = 0;
        alarmaFxAlt = 0;
        tiempoAlarma = 0;
        ManAuto = 1;
    }else{
        ManAuto = 0 ;
    }
    
    if(((alarmLect2==1)||(alarma2>0))&&((alarma1>0)||(alarmLect1==1))){
        alarmaSenAUX++;
        if(alarmaSenAUX > 20000){
        alarmaSenAUX = 11;
        }
        if(alarmaSenAUX > 10){
        alarmaFxSen = 1;
        pilotoSensor = 1;
        }
    }else{
        alarmaSenAUX = 0;
        alarmaFxSen = 0;
    }
    
    if((alarmLect2==1)||(alarma2>0)){
        alarmaSen2AUX++;
        if(alarmaSen2AUX > 20000){
    //        TRISAbits.TRISA1 =0;
    //        PORTAbits.RA1 = 0;
     //       __delay_ms(1);
            alarmaSen2AUX =16;
        }
        if(alarmaSen2AUX > 15 ){
     //       TRISAbits.TRISA1 =0;
     //     PORTAbits.RA1 = 1;
     //       __delay_ms(1);
        alarmaSensor2 = 1;
        alarmaLamp1 = 0;
        alarmaLamp2 = 0;
        }
       // flagLED = flagLED + 0x02;
    }else{
        alarmaSensor2 = 0;
        alarmaSen2AUX = 0;
      //  flagLED = flagLED - 0x02;
    }
    if((alarmLect1==1)||(alarma1>0)){
       alarmaSen1AUX++;
        if(alarmaSen1AUX > 20000){
         //   TRISAbits.TRISA1 =0;
         //   PORTAbits.RA1 = 0;
         //   __delay_ms(1);
            alarmaSen1AUX =16;
        }
        if(alarmaSen1AUX > 15 ){
        //    TRISAbits.TRISA1 =0;
        //    PORTAbits.RA1 = 1;
          //  __delay_ms(1);
        alarmaSensor1 = 1;
        alarmaLamp1 = 0;
        alarmaLamp2 = 0;
        }
       // flagLED = flagLED + 0x02;
    }else{
        alarmaSensor1 = 0;
        alarmaSen1AUX = 0;
      //  flagLED = flagLED - 0x02;
    }
resetWatch = 0;
            return;
}