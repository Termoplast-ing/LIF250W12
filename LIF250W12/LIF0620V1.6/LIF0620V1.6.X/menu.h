/*
 * File:   display.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 7 de abril de 2020, 8:38
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

void menu(void);
extern char selMenu;
extern char setPoint;                                
extern char SPFxBaj;
extern char SPFxAlt;
extern char SPFxSen;
extern char CTRauto;
extern char setPotMan;
extern char offSet;
extern char setDefault;
extern char pass;
extern char pass0;
extern char pass1;
extern char pass2;
extern char tecla;
char y=0;
char valMem;
extern char alarmaFxBaj;
extern char alarmaFxSen;
extern char alarmaFxAlt;
extern char pilotoAlarma;
extern char pilotoSensor;
extern char setPointAUX;
extern int resetWatch;


