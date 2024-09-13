/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 7 de abril de 2020, 8:38
 * Version: 1.2
 * version main: 1.2

 */

#include "display.h"
#include <xc.h>
#define _XTAL_FREQ 4000000

char conv7Seg(char dig){
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
    }
    return(digito);
}

void convBCD(char bcd,char dign,char dignn,char puntoDec){
    dig0 = bcd/10;
    dig1 = bcd%10;
    dig[dign]=conv7Seg(dig0);
    dig[dignn]=conv7Seg(dig1);
    if(puntoDec == 0){
        dig[dignn]=dig[dignn] - 0x80;
    }
}
void display(void){
    INTCONbits.INT0E = 1;
    resetWatch = 0;
    switch(selMenu){
        case 0:{
            
            if(CTRauto == 0){
                if(tempDecimal > 1){
                    tempDecimal = 0;
                }
                    if(tempDecimal == 0){
                        dig[2] = 0xc0;      //dibuja un 0
                    }if(tempDecimal == 1){
                        dig[2] = 0x92;      //dibuja un 5
                    }
                    if(alarmaFxSen == 0){
                        if(tempDisplay > 60){
                            if(tempNeg == 0){
                                dig[0]=0xa3;
                                dig[1]=0xe3;                
                                dig[2]=0xc7;
                            }if(tempNeg == 1){
                                dig[0]=0xa3;
                                dig[1]=0xe3;                
                                dig[2]=0xc7;
                            }
                        }else{
                            convBCD(tempDisplay,0,1,tempNeg);
                        }
                    }else{
                        dig[0]=0x84;
                        dig[1]=0xaf;                
                        dig[2]=0xaf;
                    }

    //dig[0]=0xff;                /////////////////////////////////
    //dig[1]=0xff;                //// temperatura actual falta////
    //dig[2]=0xff;                /////////////////////////////////
                    if((alarmaFxBaj == 0)&&(alarmaFxAlt == 0)&&(alarmaFxSen == 0)){
                    deciSP = setPoint & 0b00000001;
                    if(deciSP == 0){
                        dig[5] = 0xc0;      //dibuja un 0
                    }if(deciSP == 1){
                        dig[5] = 0x92;      //dibuja un 5
                    }
                    enteSP = setPoint>>1;
                    convBCD(enteSP,3,4,0);
                    }else{
                        if((tecla == 0x01)||(tecla == 0x02)){
                            auxSetenFalla = 200;
                        }
                        if(auxSetenFalla > 0){
                            auxSetenFalla --;
                            if(auxSetenFalla >200){
                                auxSetenFalla = 0;
                            }
                            deciSP = setPoint & 0b00000001;
                            tecla = 0x00;
                    if(deciSP == 0){
                        dig[5] = 0xc0;      //dibuja un 0
                    }if(deciSP == 1){
                        dig[5] = 0x92;      //dibuja un 5
                    }
                    enteSP = setPoint>>1;
                    convBCD(enteSP,3,4,0);
                        }else{
                        if(alarmaFxAlt == 1){
                            dig[3]=0x0e;
                            dig[4]=0x88;                
                            dig[5]=0x47;
                        }
                        if(alarmaFxBaj == 1){
                            dig[3]=0x0e;
                            dig[4]=0x83;                
                            dig[5]=0xa0;
                        }
                        if(alarmaFxSen == 1){
                            dig[3]=0x0e;
                            dig[4]=0x92;                
                            dig[5]=0x2b;
                        }
                        }
                        
                            
                        
                    }
                    
                    convBCD(salPotencia,7,8,0);
            
            }
            if(CTRauto == 1){
                    if(tempDecimal == 0){
                        dig[2] = 0xc0;      //dibuja un 0
                    }if(tempDecimal == 1){
                        dig[2] = 0x92;      //dibuja un 5
                    }
                    if(alarmaLectura == 0){
                        if(tempDisplay > 60){
                            if(tempNeg == 0){
                                dig[0]=0xa3;
                                dig[1]=0xe3;                
                                dig[2]=0xc7;
                            }if(tempNeg == 1){
                                dig[0]=0xa3;
                                dig[1]=0xe3;                
                                dig[2]=0x8e;
                            }
                        }else{
                            convBCD(tempDisplay,0,1,tempNeg);
                        }
                    }else{
                        dig[0]=0x84;
                        dig[1]=0xaf;                
                        dig[2]=0xaf;
                    }
                
                dig[3] = 0xc8;
                dig[4] = 0xa0;
                dig[5] = 0x2b;
                convBCD(setPotMan,7,8,0);
            }
        break;
        }
        case 1:{
            resetWatch = 0;
            dig[0]=0x12;        //dibuja una S.
            dig[1]=0x0c;        //dibuja una P.
            dig[2]=0x0e;        //dibuja una F.
            dig[3]=0x83;        //dibuja una b
            dig[4]=0xa0;        //dibuja una a
            dig[5]=0x60;        //dibuja una j.
            
            convBCD(SPFxBaj,7,8,0);   
        
        break;
        } 
        
        case 2:{
            resetWatch = 0;
            dig[0]=0x12;        //dibuja una S.
            dig[1]=0x0c;        //dibuja una P.
            dig[2]=0x0e;        //dibuja una F.
            dig[3]=0x88;        //dibuja una A
            dig[4]=0xc7;        //dibuja una L
            dig[5]=0x07;        //dibuja una t.
            
            convBCD(SPFxAlt,7,8,0);   
        
        break;
        } 

        case 3:{
            resetWatch = 0;
            dig[0]=0x12;        //dibuja una S.
            dig[1]=0x0c;        //dibuja una P.
            dig[2]=0x0e;        //dibuja una F.
            dig[3]=0x92;        //dibuja una S
            dig[4]=0x84;        //dibuja una e
            dig[5]=0x2b;        //dibuja una n.
            
            convBCD(SPFxSen,7,8,0);   
        
        break;
        } 
        
        case 4:{
            resetWatch = 0;
            dig[0]=0xC6;        //dibuja una C
            dig[1]=0x87;        //dibuja una t
            dig[2]=0x2f;        //dibuja una r.
            dig[3]=0x88;        //dibuja una A
            dig[4]=0xe3;        //dibuja una u
            dig[5]=0x07;        //dibuja una t.
            
            if(CTRauto == 0){
                dig[7]=0x92;        //dibuja una S
                dig[8]=0xcf;        //dibuja una I
            }if(CTRauto==1){
                dig[7]=0xab;        //dibuja una n
                dig[8]=0xa3;        //dibuja una o
            }
        
        break;
        }
        case 5:{
            resetWatch = 0;
            dig[0]=0x8c;        //dibuja una P
            dig[1]=0xa3;        //dibuja una o
            dig[2]=0x07;        //dibuja una t.
            dig[3]=0xc8;        //dibuja una M
            dig[4]=0xa0;        //dibuja una a
            dig[5]=0x2b;        //dibuja una n.
            
            convBCD(setPotMan,7,8,0);
        
        break;
        }
        case 6:{
            resetWatch = 0;
            dig[0]=0xa3;        //dibuja una o
            dig[1]=0x8e;        //dibuja una f
            dig[2]=0x8e;        //dibuja una f
            
            if((offSet > 19)&&(offSet < 41)){
                OFFSet = offSet-20;
            decimalOffSet = OFFSet & 0x01;
                if(decimalOffSet == 0){
                    dig[5] = 0xc0;      //dibuja un 0
                    }if(decimalOffSet == 1){
                        dig[5] = 0x92;      //dibuja un 5
                    }
                OFFSet = OFFSet >> 1 ;
                convBCD(OFFSet,3,4,0)  ;
            }
         if((offSet < 20)&&(offSet < 41)){
                  OFFSet = (20 - offSet)>>1 ;
                  convBCD(OFFSet,4,5,0);
                  dig[3] = 0xBF;
         }
            dig[7]=0xff;
            dig[8]=0xff;
            break;
        }
        
        case 7:{
            resetWatch = 0;
            dig[0]=0xa1;        //dibuja una d
            dig[1]=0x84;        //dibuja una e
            dig[2]=0x8e;        //dibuja una f
            dig[3]=0xa0;        //dibuja una A
            dig[4]=0xe3;        //dibuja una u
            dig[5]=0x47;        //dibuja una l.
            
            if(setDefault == 1){
                dig[7]=0x92;        //dibuja una S
                dig[8]=0xcf;        //dibuja una I
            }if(setDefault == 0){
                dig[7]=0xab;        //dibuja una n
                dig[8]=0xa3;        //dibuja una o
            }
        break;
        }
        case 8:{
            resetWatch = 0;
            dig[0]=0x8c;        //dibuja una P
            dig[1]=0xa0;        //dibuja una a
            dig[2]=0x92;        //dibuja una S
            dig[3]= conv7Seg(pass0);
            dig[4]= conv7Seg(pass1);
            dig[5]= conv7Seg(pass2);
            dig[7]= 0xff;
            dig[8]= 0xff;
         break;
        }
    }
    resetWatch = 0;
    return;
}