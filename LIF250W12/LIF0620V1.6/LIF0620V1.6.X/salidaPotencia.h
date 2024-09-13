/*
 * File:   display.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 21 de abril de 2020, 12:24
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

void salidaPotencia(void);

extern int unsigned salPotenciaAux;
extern  int unsigned salPotencia;
int denominador;
char tempSpPv;
extern char setPoint;
extern char tempDisplay;
extern char tempDecimal;
extern char tempNeg;
char tempMuestra;
extern char salPotenciaAux0;
extern char salPotenciaAux1;
extern char CTRauto;
extern char setPotMan;
extern char alarmaFxAlt;
extern char alarmaFxBaj;
extern char alarmaFxSen;
extern char SPFxAlt;
extern char SPFxBaj;
extern char SPFxSen;
char salPotenciaAnterior;
char w;
extern char setPointAUX;
extern int resetWatch;