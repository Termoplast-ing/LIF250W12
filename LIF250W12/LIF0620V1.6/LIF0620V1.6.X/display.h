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

void display(void);

char dig0;
char dig1;
char digito;
char bcd;

extern  int unsigned salPotencia;
extern char selMenu;
extern char setPoint;                                
extern char SPFxBaj;
extern char SPFxAlt;
extern char SPFxSen;
extern char CTRauto;
extern char setPotMan;
extern char offSet;
extern char setDefault;
extern char pass0;
extern char pass1;
extern char pass2;
extern char potSal;
char deciSP;
char enteSP;
extern char dig[10];
extern char auxoffSet;
extern char deciTemp1;
extern char convTemp1;
extern char deciTemp2;
extern char convTemp2;
extern  char tempDisplay;
extern  char tempDecimal;
 char tempDisplay1;
 extern char tempNeg;
 extern char alarmaLectura;
 extern char alarmaFxBaj;
extern char alarmaFxSen;
extern char alarmaFxAlt;
extern char tecla;
char OFFSet;
char decimalOffSet;
extern int resetWatch;
char auxSetenFalla;