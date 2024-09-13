/*
 * File:   inicializacion.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 16 de abril de 2020, 8:27
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

void conversionTemp(void);

extern char deciTemp1;
extern char convTemp1;
extern char deciTemp2;
extern char convTemp2;
extern char lectScrat1[9];
extern char lectRom1[8];
extern char lectScrat2[9];
extern char lectRom2[8];
extern  char aux1;
extern  char aux2;
char tempAnterior = 0;
extern char tempDisplay;
signed char tempProm = 0;
extern  char tempDecimal;
extern char tempNeg;
 char tempDisplay1;
extern char alarma1;
extern char alarma2;
char alarmLect1;
char alarmLect2;
extern char tempNeg1;
extern char tempNeg2;
extern char tempDeci1;
extern char tempDeci2;
char alarmaLectura;
extern char alarmaSensor1;
extern char alarmaSensor2;
extern char offSet;
extern char tecla;
char offSet2;
char offSet1;
extern char alarmaLamp2;
extern char alarmaLamp1;
extern int resetWatch;
extern char aux10;
extern char aux11;
extern char aux20;
extern char aux21;