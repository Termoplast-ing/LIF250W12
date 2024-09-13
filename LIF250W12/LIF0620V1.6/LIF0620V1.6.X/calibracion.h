/*
 * File:   display.c
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 11 de abril de 2020, 11:00
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
#include "ds1820.h"

void calibracion(void);

char q;
char r;
extern char setPoint;                                
extern char SPFxBaj;
extern char SPFxAlt;
extern char SPFxSen;
extern char CTRauto;
extern char setPotMan;
extern char offSet;
extern char setDefault;
extern char digito;
extern char dig[10];
extern char presencia2;
extern char presencia1;
char l;
extern int resetWatch;