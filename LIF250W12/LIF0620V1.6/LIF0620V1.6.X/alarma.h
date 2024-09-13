/*
 * File:   display.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 20 de abril de 2020, 9:18
 * Version: 1.2
 * version main: 1.2

 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

#include <xc.h>

void alarma(void);
extern char alarmLect1;
extern char alarmLect2;
extern char lectScrat1[9];
extern char lectRom1[8];
extern char lectScrat2[9];
extern char lectRom2[8];
extern char setPoint;
extern char tempMuestra;
extern unsigned long tiempoAlarma;
extern char alarmaFxBaj;
extern char estable;
extern char alarmaSensor1;
extern char alarmaSensor2;
extern char alarmaFxSen;
extern char alarmaFxAlt;
extern char alarma1;
extern char alarma2;
extern char pilotoAlarma;
extern char tempDisplay;
extern char CTRauto;
extern char flagLED;
extern char setPointAUX;
char extern ManAuto;
char extern pilotoSensor;
unsigned int alarmaSenAUX;
extern char alarmaLamp1;
extern char alarmaLamp2;
extern char aux1;
extern char aux2;
extern int resetWatch;
