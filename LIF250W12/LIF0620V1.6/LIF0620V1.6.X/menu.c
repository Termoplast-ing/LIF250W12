/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 10 de abril de 2020, 8:06
 * Version: 1.2
 * version main: 1.2

 */

#include <xc.h>
#include "menu.h"
#define _XTAL_FREQ 4000000

void wrEprom(char dir , char dato){                                             //rutina para escribir eemprom
    
    EEADR = dir;                                                                //seteo la direccion que se va grabar de memoria
    EEDATA = dato;                                                              //cargo el dato que se va a grabar
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


void menu(void) {
    INTCONbits.INT0E = 1;
    resetWatch = 0;
    if(selMenu > 8){
        selMenu = 0;        
    }
//////////////////////////PANTALLA PRINCIPAL////////////////////////////////////
     
    if(selMenu == 0){     
        resetWatch = 0;  
                                                          //si selMenu es 0 (pantalla principal)
        /////////////////////PANTALLA PRINCIPAL EN AUTOMATICO///////////////////
        if(CTRauto == 0){                                                       //decision para setear el set point o la potencia segun este en manual o automatico
            if((alarmaFxBaj == 1)||(alarmaFxAlt == 1)||(alarmaFxSen == 1)){
              //  if(tecla == 0x04){                                                  //si presiono menu corto en pantalla principal
               //     pilotoAlarma = 0;                                    //guarda el valor de setpoint em memoria
                //    tecla = 0x00;
                }
            
            else{
                if(tecla == 0x01){                                                  //y presiono subir incremento '.5' 
                    setPoint++;                                                     //el setpoint
                    if(setPoint > 199){                                             //ssi llega a 99.5 
                        setPoint = 0;                                               // pasa 0   
                    }
                    wrEprom( 0x00 ,  setPoint);
                tecla = 0x00;                                                       //resetea variable tecla
                }
                if(tecla == 0x02){                                                  //si presiono bajar decremento '.5'
                    setPoint--;                                                     // el setpoint
                    if((setPoint == 0)||(setPoint > 199)){                                              //si llega a 0
                        setPoint = 199;                                         //vuelve a 99.5   
                    }
                    wrEprom( 0x00 ,  setPoint);
                tecla = 0x00;                                                       //resetea variable tecla
                }
                if(tecla == 0x04){                                                  //si presiono menu corto en pantalla principal
                        pilotoSensor = 0;
                        pilotoAlarma = 0;
                    wrEprom( 0x00 ,  setPoint);                                 //guarda el valor de setpoint em memoria
                    tecla = 0x00; 
                }
            
            }
        }
        
        /////////////////PANTALLA PRINCIPAL EN MANUAL///////////////////////////
        if(CTRauto == 1){
            
            if(tecla == 0x01){                                                  //y presiono subir incremento '1' 
                setPotMan++;                                                    //el valor de potencia
                if(setPotMan > 99){                                             //ssi llega a 99 
                    setPotMan = 99;                                              // pasa 0
                }
            tecla = 0x00;                                                       //resetea variable tecla
            }
            if(tecla == 0x02){                                                  //si presiono bajar decremento '1'
                setPotMan--;                                                    // el el valor de potencia
                if(setPotMan < 15){                                             //si llega a 0
                    setPotMan = 15;                                             //vuelve a 99
                }
                tecla = 0x00;                                                   //resetea variable tecla
            }
            if(tecla == 0x04){                                                  //si presiono menu corto en pantalla principal
                wrEprom( 0x05 , setPotMan);                                     //guarda el valor de potencia em memoria
                tecla = 0x00;                                                   //resetea variable tecla
            }
        }
        if(tecla == 0x08){
            tecla = 0x00;
        }
            if(tecla == 0x10){ 
                selMenu = 8;                                                    //para ingresar la contraseña
                tecla = 0x00;                                                   //reseteo variable tecla
            }
        }
    
    //////////MENU 1: SETEO POTENCIA DE SALIDA EN FALLA POR BAJA////////////////
    
    if(selMenu == 1){ 
        resetWatch = 0;                                                         //si selmenu es 1 entra al seteo de potencia en falla por baja
        if(tecla == 0x01){                                                      //si presiono subir
            SPFxBaj++;                                                          //incrementa en '1'
            if(SPFxBaj > 99){                                                   //el valor seteado si llega a 99 pasa a cero
               SPFxBaj = 15;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x02){                                                      //si presiono bajar
            SPFxBaj--;                                                          //decrementa en '1'
            if(SPFxBaj < 15){                                                   //el valor seteado si llega a cero pasa a 99
                SPFxBaj = 99;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x01 ,SPFxBaj);                                             //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            selMenu = 1;
            tecla = 0x00;                                                      //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    //////////MENU 2: SETEO POTENCIA DE SALIDA EN FALLA POR ALTA////////////////
    
    if(selMenu == 2){                                                           //si selmenu es 2 entra al seteo de potencia en falla por alta
        resetWatch = 0;
        if(tecla == 0x01){                                                      //si presiono subir
            SPFxAlt++;                                                          //incrementa en '1'
            if(SPFxAlt > 99){                                                   //el valor seteado si llega a 99 pasa a cero
               SPFxAlt = 0;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x02){                                                      //si presiono bajar
            SPFxAlt--;                                                          //decrementa en '1'
            if(SPFxAlt < 15){                                                   //el valor seteado si llega a cero pasa a 99
                SPFxAlt = 99;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x02 ,SPFxAlt);                                             //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            selMenu=1;
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    //////////MENU 3: SETEO POTENCIA DE SALIDA EN FALLA POR SENSOR//////////////
    
    if(selMenu == 3){                                                           //si selmenu es 3 entra al seteo de potencia en falla por falta sensor
        resetWatch = 0;
        if(tecla == 0x01){                                                      //si presiono subir
            SPFxSen++;                                                          //incrementa en '1'
            if(SPFxSen > 99){                                                   //el valor seteado si llega a 99 pasa a cero
               SPFxSen = 0;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x02){                                                      //si presiono bajar
            SPFxSen--;                                                          //decrementa en '1'
            if(SPFxSen < 15){                                                   //el valor seteado si llega a cero pasa a 99
                SPFxSen = 99;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x03 ,SPFxSen);                                             //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            selMenu = 1;
            tecla = 0x00;                                                      //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    ////////////MENU 4: SETEO AUT / MAN EL CONTROL DE TEMPERATURA///////////////
    
    if(selMenu == 4){                                                           //si selmenu es 4 entra al seteo de man/auto del controlador de temperatura
        resetWatch = 0;
        if((tecla == 0x01) || (tecla == 0x02)){                                 //si presiono subir o  bajar
            if(CTRauto == 0){                                                   //cambio el estado de auto a man y devuelta a auto
                CTRauto = 1;    
                EEADR = 0x05 ;
            EECON1bits.EEPGD = 0;                                                       //se designa que se va a acceder a la memoria eeprom
        EECON1bits.CFGS = 0;                                                        //se designa que se va a acceder a la memoria eeprom
        EECON1bits.RD = 1;                                                          //se inicia el ciclo de leectura
        while(EECON1bits.RD == 1){                                                  //bucle vacio del cual va a salir cuando se haya terminado la lectura
        }
        setPotMan = EEDATA;                                                     //si es cero esta en auto
            }else{                                                              //si es uno esta en man
                CTRauto = 0;
                
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x04,CTRauto);                                                   //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            
            selMenu = 1;
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        
    }
    
    /////////////MENU 5: SETEO POTENCIA DE SALIDA EN MODO MANUAL////////////////
    
    if(selMenu == 5){                                                           //si selmenu es 5 entra al seteo de potencia en modo manual cuando inicia o si se hace un default
        resetWatch = 0;
        if(tecla == 0x01){                                                      //si presiono subir
            setPotMan++;                                                           //incrementa en '1'
            if(setPotMan > 99){                                                    //el valor seteado si llega a 99 pasa a cero
               setPotMan = 0;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x02){                                                      //si presiono bajar
            setPotMan--;                                                           //decrementa en '1'
            if(setPotMan < 15){                                                    //el valor seteado si llega a cero pasa a 99
                setPotMan = 99;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x05 , setPotMan);                                          //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            selMenu = 1;
            tecla = 0x00;                                                      //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    //////////////////////////MENU 6: SETEO OFFSET//////////////////////////////
    
   if(selMenu == 6){                                                            //si selmenu es 6 entra al seteo de offset
       resetWatch = 0; 
       if(tecla == 0x01){                                                      //si presiono subir
            offSet++; 
             if(offSet < 20){
                 offSet++; 
             }                                                                   //incrementa en '1'
            if(offSet > 40){                                                    //el valor seteado si llega a 15 pasa a 0
               offSet = 20;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x02){                                                      //si presiono bajar
            offSet--;  
                 if(offSet < 21){
                 offSet--; 
             }                                                                 //decrementa en '1'
            if((offSet == 0)||(offSet > 40)){                                                 //el valor seteado si llega a -15 pasa a 0
                offSet = 20;
            }
            
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu++;                                                          //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if(tecla == 0x08){                                                      //si presiono menu medio
            wrEprom(0x03 ,offSet);                                             //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
            selMenu = 1;
            tecla = 0x00;                                                      //reseta variable tecla
        }
        if(tecla == 0x10){                                                      //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    //////////MENU 7: RESETEO DE LOS PARAMETROS A VALOR POR DEFAULT/////////////
    
    if(selMenu == 7){                                                           //si selmenu es 7 entra al menu para reestablecer valores default
        resetWatch = 0; 
        if((tecla == 0x01) || (tecla == 0x02)){                                //si presiono subir o  bajar
            if(setDefault == 0){                                                //cambio el estado de si a no y a si devuelta
                setDefault = 1;                                                 //si es cero esta en 'no' reestablecer
            }else{                                                              //si es uno esta en si reestablecer
                setDefault = 0;
            }
        tecla = 0x00;                                                           //reseta variable tecla
        }
        if(tecla == 0x04){                                                      //si presiono menu corto
            selMenu = 1;                                                        //paso a la siguiente pagina del menu sin grabar
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if((tecla == 0x08) && (setDefault == 1)){                                 //si presiono menu medio y esta seteado para reestablecer
            
            setPoint = 50;
            SPFxBaj = 99;
            SPFxAlt = 15; 
            SPFxSen = 50;
            CTRauto = 0;
            setPotMan = 50;
            offSet = 16;
            setDefault = 0;
            
            for(y = 0 ; y < 7 ; y++ ) {                                         //grabo en memoria el valor seteado y vuelvo a la pag 1 del menu
                if(y == 0){
                    valMem = setPoint;
                }if(y == 1){
                    valMem = SPFxBaj;
                }if(y == 2){
                    valMem = SPFxAlt;
                }if(y == 3){
                    valMem = SPFxSen;
                }if(y == 4){
                    valMem = CTRauto;
                }if(y == 5){
                    valMem = setPotMan;
                }if(y == 6){
                    valMem = offSet;
                }
                wrEprom(y ,valMem);
            }
            selMenu = 1;
            tecla = 0x00;                                                       //reseta variable tecla
        }
        if (tecla == 0x10){                                                     //si presiono menu largo 
            selMenu = 0x00;                                                     //vuelvo a la pantalla principal sin guardar
            tecla = 0x00;                                                       //reseta variable tecla
        }
    }
    
    /////////////INGRESO PASS: CONTRASEÑA PARA INGRESAR AL MENU/////////////////
    
    if(selMenu == 8){                                                           //si selmenu es 7 si muestra la pantalla para poner el pass y entrar al menu
        resetWatch = 0;
        if(tecla==0x04){                                                        //si se presiona menu corto cambia de digito a modificar
            pass ++;
            if(pass > 2){
                pass = 0;
            }
            tecla = 0x00;                                                       //resetea variable tecla
        }
        if(tecla == 0x01){                                                      // si se presiona subir incrementa en 1 el digito elegido 
            switch(pass){                                                       //si llega a nueve vuelve a cero
                case 0 :{
                    pass0 ++;
                    if(pass0 > 9){
                        pass0 = 0;
                    }
                    break;
                }
                case 1 :{
                    pass1 ++;
                    if(pass1 > 9){
                        pass1 = 0;
                    }
                    break;
                }
                case 2 :{
                    pass2 ++;
                    if(pass2 > 9){
                        pass2 = 0;
                    }
                    break;
                }
            }
            tecla = 0x00;                                                       //resetea variable tecla
        }
        if(tecla == 0x02){                                                      //sise presiona baja decrementa en 1 el digito elegido
            switch(pass){                                                       //si llega a 0 vuelve a 9
                case 0 :{
                    pass0 --;
                    if(pass0 > 9){
                        pass0 = 9;
                    }
                    break;
                }
                case 1 :{
                    pass1 --;
                    if(pass1 > 9){
                        pass1 = 9;
                    }
                    break;
                }
                case 2 :{
                    pass2 --;
                    if(pass2 > 9){
                        pass2 = 9;
                    }
                    break;
                }
            }
            tecla = 0x00;                                                         //resetea variable tecla
        }
        if(tecla == 0x08){                                                      //si se presiona menu mediose compara los valores 
            if((pass0 == 1)&&(pass1 == 5)&&(pass2 == 2)){                       //puestos en la variables pass y si corresponde cada 
                selMenu = 1;                                                    //digito a '1''5''2'(cumpleaños de adrian monti) se ingresa al menu
                pass = 0;                                                       //se reinicia todas las variables
                pass0 = 0;                                                      //que verifican el pass
                pass1 = 0;                                                      // para que  quede listo 
                pass2 = 0;                                                      //por si se quiere volver a entrar al menu
            }
        tecla = 0x00;                                                           //resetea variable tecla
        }
        if(tecla == 0x10){                                                      //si se presiona menu larga vulve
            selMenu=0x00;                                                       //a la pantalla principal
            tecla = 0x00;                                                       //resetea variable tecla
        }
    }
    return;
}

