/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 13 de abril de 2020, 12:12
 * Version: 1.2
 * version main: 1.2

 */
char presencia1;
char rdBit1;
char wrByte1;
char rdByte1;
char presencia2;
char rdBit2;
char wrByte2;
char rdByte2;
char j = 0;
char k = 0;
char sens;
char n;
char u;
char t;
char crc1;
char crc2;
char poli;
char byte1;
char byte_carry1;
char crc_carry1;
char byte2;
char byte_carry2;
char crc_carry2;
char operacion;

#include "ds1820.h"
#include <xc.h>
#define _XTAL_FREQ 4000000


void reset1(void){
    TRISAbits.TRISA0 = 0;
    //TRISA = 0x00;
      PORTAbits.RA0 = 0;
    __delay_us(480);
    TRISAbits.TRISA0 = 1;
    //TRISA = 0x01;
    __delay_us(70);
        presencia1 = PORTAbits.RA0;
    __delay_us(410);
    
}
void reset2(void){
     TRISAbits.TRISA1 = 0;
    //TRISA = 0x00;
      PORTAbits.RA1 = 0;
    __delay_us(480);
     TRISAbits.TRISA1 = 1;
    //TRISA = 0x02;
    __delay_us(70);
        presencia2 = PORTAbits.RA1;
    __delay_us(410);
    
}

void wrCero1 (void){
     TRISAbits.TRISA0 = 0;
    //TRISA = 0x00;
        PORTAbits.RA0 = 0;
    __delay_us(60);
     TRISAbits.TRISA0 = 1;
    //TRISA = 0x01;
    __delay_us(10);
    
}
void wrCero2 (void){
    TRISAbits.TRISA1 = 0;
    //TRISA = 0x00;
        PORTAbits.RA1 = 0;
    __delay_us(60);
     TRISAbits.TRISA1 = 1;
    //TRISA = 0x02;
    __delay_us(10);
    
}

void wrUno1 (void){
     TRISAbits.TRISA0 = 0;
    //TRISA = 0x00;
       PORTAbits.RA0 = 0;
    __delay_us(6);
     TRISAbits.TRISA0 = 1;
   // TRISA = 0x01;
    __delay_us(64);
    
}
void wrUno2 (void){
     TRISAbits.TRISA1 = 0;
    //TRISA = 0x00;
       PORTAbits.RA1 = 0;
    __delay_us(6);
     TRISAbits.TRISA1 = 1;
    //TRISA = 0x02;
    __delay_us(64);
    
}

 void readBit1 (void){
     
      TRISAbits.TRISA0 = 0;
     //TRISA = 0x00;
         PORTAbits.RA0 = 0;
     __delay_us(6);
      TRISAbits.TRISA0 = 1;
     //TRISA = 0x01;
     __delay_us(9);
        rdBit1 = PORTAbits.RA0;
     __delay_us(55);
     
 }
 void readBit2 (void){
      TRISAbits.TRISA1 = 0;
     //TRISA = 0x00;
         PORTAbits.RA1 = 0;
     __delay_us(6);
      TRISAbits.TRISA1 = 1;
     //TRISA = 0x02;
     __delay_us(9);
        rdBit2 = PORTAbits.RA1;
     __delay_us(55);
     
 }
 
 void writeByte1(char comando){
    
     for ( n=0 ; n<8 ; n++ ) {
       wrByte1 = comando & 0x01;
       if( wrByte1 == 1){
           wrUno1();
       }else{
           wrCero1();
       }
       comando>>=1;
 }
 }

  void writeByte2(char comando){
    
     for ( n=0 ; n<8 ; n++ ) {
       wrByte2 = comando & 0x01;
       if( wrByte2 == 1){
           wrUno2();
       }else{
           wrCero2();
       }
       comando>>=1;
 }
 }
 
 void readByte1 (char scratRom,char m){
    
    
    for( j=0 ; j<m ; j++ ){
        rdByte1 = 0x00;
        for( k=0 ; k<8 ; k++){
    
            readBit1();
            rdBit1 = rdBit1 << k;
            rdByte1 = rdByte1 + rdBit1;
            
        }
        if(scratRom == 0){
                lectScrat1[j] = rdByte1;
            rdBit1 = 0;
        }
        if(scratRom == 1){
                lectRom1[j] = rdByte1;
            }
            rdBit1 = 0;
        }
    }
 void readByte2 (char scratRom,char m){
    
    
    for( j=0 ; j<m ; j++ ){
        rdByte2 = 0x00;
        for( k=0 ; k<8 ; k++){
    
            readBit2();
            rdBit2 = rdBit2 << k;
            rdByte2 = rdByte2 + rdBit2;
            
        }
        if(scratRom == 0){
                lectScrat2[j] = rdByte2;
            rdBit2 = 0;
        }
        if(scratRom == 1){
                lectRom2[j] = rdByte2;
            }
            rdBit2 = 0;
        }
    }

char crc81(char scratRom,char m){
    poli = 0x8c;
    crc1 = 0x00;
    m = m-1;
    for(t=0; t < m ; t++){
         
        if(scratRom == 0){
                byte1 = lectScrat1[t];
        }
        if(scratRom == 1){
                byte1 = lectRom1[t];
        }
            
        for(u = 0 ; u < 8 ; u++){
            crc_carry1 = crc1 & 0x01;
            crc1 >>= 1 ;
             
            byte_carry1 = byte1 & 0x01;
            byte1 >>= 1 ;
        
            if(byte_carry1 ^ crc_carry1){
                
                crc1 ^= poli;
            }    
             
        }
    }
    
    if(scratRom == 0){
            crc1 = crc1 - lectScrat1[8];
    }if(scratRom == 1){
            crc1 = crc1 - lectRom1[7];
    }
    
    return crc1;
}
char crc82(char scratRom,char m){
    poli = 0x8c;
    crc2 = 0x00;
    m = m-1;
    for(t=0; t < m ; t++){
         
        if(scratRom == 0){
                byte2 = lectScrat2[t];
        }
        if(scratRom == 1){
                byte2 = lectRom2[t];
        }
            
        for(u = 0 ; u < 8 ; u++){
            crc_carry2 = crc2 & 0x01;
            crc2 >>= 1 ;
             
            byte_carry2 = byte2 & 0x01;
            byte2 >>= 1 ;
        
            if(byte_carry2 ^ crc_carry2){
                
                crc2 ^= poli;
            }    
             
        }
    }
    
    if(scratRom == 0){
            crc2 = crc2 - lectScrat2[8];
    }if(scratRom == 1){
            crc2 = crc2 - lectRom2[7];
    }
    
    return crc2;
}
//void scratRom(void){
  //  reset();
    //    if (presencia == 0){
   //         alarma0 = alarma0 & 0b11110111;      
   //         writeByte(0x33);
   //         readByte(1,8);
        //    if (!(crc8(1,8)== 0)){
      //              alarma0 = alarma0 + 0x02;
      //      }else{
      //              alarma0 = alarma0 & 0b11111101;
     //           }
     //   }else{
    //     alarma0 = alarma0 + 0x04;
   //     }
//}

    
void ds1820(char operacion,char nsen){
j = 0;
k = 0;
n = 0;
u = 0;
t = 0;
//T0CONbits.TMR0ON = 1;
 //     INTCONbits.TMR0IE = 1;
        switch(operacion){
            case 1:{
                resetWatch = 0;
                if(nsen == 1){
                    reset1();
                    if (presencia1 == 0){
                        writeByte1(0x33);
                        readByte1(1,8);
                        INTCONbits.INT0E = 1;
                        if((crc81(1,8)== 0)){
                            alarma1 = 0x00;
                            alarmLect2=0;
                        }else{
                            alarma1 = alarma1 + 0x10;
                            alarma1 = alarma1 & 0b11110000;
                        }
                    }if(presencia1 == 1){
                        alarma1 = alarma1 + 0x01;
                        alarma1 = alarma1 &0b00001111;
                    }
                }
                if(nsen == 2){
                    reset2();
                    if (presencia2 == 0){
                        writeByte2(0x33);
                        readByte2(1,8); 
                      INTCONbits.INT0E = 1;
                        if((crc82(1,8)== 0)){
                            alarma2 = 0x00;
                            alarmLect2=0;
                        }else{
                            alarma2 = alarma2 + 0x10;
                            alarma2 = alarma2 & 0b11110000;
                        }
                    }if(presencia2 == 1){
                        alarma2 = alarma2 + 0x01;
                        alarma2 = alarma2 &0b00001111;
                    }
                }
                break;
            }
            case 2:{
                resetWatch = 0;
                if(nsen == 1){
                    reset1();
                    if (presencia1 == 0){
                        writeByte1(0xcc);
                        writeByte1(0x44);    
                       INTCONbits.INT0E = 1;
               //         alarma1 = alarma1 & 0b11110000;
               //         alarmLect2=0;
                        
                    }
                    if(presencia1 == 1){
                        alarma1 = alarma1 + 0x01;
                    }
                    conversion1 = 2;
                }if(nsen == 2){
                    reset2();
                    if (presencia2 == 0){
                        writeByte2(0xcc);
                        writeByte2(0x44);
                        INTCONbits.INT0E = 1;
                //        alarma2 = alarma2 & 0b11110000;
                       // alarmLect2=0;
                                            
                    }if(presencia2 == 1){
                        alarma2 = alarma2 + 0x01;
                    }
                    conversion2 = 2;
                }
                break;
                }
            case 3:{
                resetWatch = 0;
                if(nsen == 1){
                    reset1();
                    if (presencia1 == 0){
                        writeByte1(0xcc);
                        writeByte1(0xbe);
                        readByte1 (0,9); 
                        INTCONbits.INT0E = 1;
                    if((crc81(0,9)== 0)){
                            alarma1 = 0x00;
                            aux10= lectScrat1[0];
                            aux11= lectScrat1[1];
                        //    alarmLect2=0;
                        }else{
                            alarma1 = alarma1 + 0x10;
                            alarma1 = alarma1 & 0b11110000;
                        }
                    
                    }if(presencia1 == 1){
                        alarma1 = alarma1 + 0x01;
                        alarma1 = alarma1 &0b00001111;
                        lectura1 = 2 ;
                    }
                    lectura1 = 2;
                }if(nsen == 2){
                    reset2();
                    if (presencia2 == 0){
                        writeByte2(0xcc);
                        writeByte2(0xbe);
                        readByte2 (0,9); 
                 INTCONbits.INT0E = 1;
                    if((crc82(0,9)== 0)){
                            alarma2 = 0x00;
                            aux20 = lectScrat2[0];
                            aux21 = lectScrat2[1];
                       //     alarmLect2=0;
                        }else{
                            alarma2 = alarma2 + 0x10;
                            alarma2 = alarma2 & 0b11110000;
                        }
                      
                    }
                    resetWatch = 0;
                    if(presencia2 == 1){
                        alarma2 = alarma2 + 0x01;
                        alarma2 = alarma2 &0b00001111;
                        lectura1 = 2 ;
                    }
                    lectura2 = 2;
                }
                
                break;
            }
            
        }
        TRISA=0b111111;
     //   reset();
//reset();
 //   writeByte(0xcc);
  //     writeByte(0x44);
     
  //     __delay_ms(1200);
 //      reset();

 //           writeByte(0xcc);
 //           writeByte(0xbe);
 //           readByte (0,9);

   return;
}
