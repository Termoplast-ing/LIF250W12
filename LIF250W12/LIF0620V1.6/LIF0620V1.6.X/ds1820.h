/*
 * File:   display.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 13 de abril de 2020, 12:12
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

void ds1820(char operacion,char nsen);
extern char alarma1;
extern char alarma2;
extern char lectScrat1[9];
extern char lectRom1[8];
extern char lectScrat2[9];
extern char lectRom2[8];
extern unsigned int conversion1;
extern unsigned int conversion2;
extern char lectura1;
extern char lectura2;
extern char alarmLect1;
extern char alarmLect2;
extern int resetWatch;
extern char aux10;
extern char aux11;
extern char aux20;
extern char aux21;


