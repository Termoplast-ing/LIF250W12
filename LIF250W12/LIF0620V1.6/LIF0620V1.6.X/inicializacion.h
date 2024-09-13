/*
 * File:   inicializacion.h
 * Author: Brian Avila
 * Empresa: Termoplast
 * Created on 3 de abril de 2020, 17:26
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
void inicializacion (void);

extern char parametros[8];
char q = 0;
char r = 0;
char l = 0;
extern char setPoint;                                
extern char SPFxBaj;
extern char SPFxAlt;
extern char SPFxSen;
extern char CTRauto;
extern char setPotMan;
extern char setDefault;
extern char offSet;
extern int resetWatch;


