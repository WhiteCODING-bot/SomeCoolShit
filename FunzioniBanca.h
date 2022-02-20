    //Fatto da Fabio Luca Stanciu
#ifndef __Movimento_H__
#define __Movimento_H__
#define DIM 1024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Movimenti.h"



int getID(Movimento);
int getSoldi(Movimento);

void setID(Movimento*, int);
void setSoldi(Movimento*, int);

Movimento* creaDefault();
Movimento* crea(int, int);
void distruggi(Movimento*);
Movimento* creaCopia(Movimento e);

char* recordToString(Movimento);
void stringToFile(Movimento, FILE*);




int getID(Movimento e)
{
    return e.id;
}

int getSoldi(Movimento e)
{
    return e.soldi;
}

void setID(Movimento* e, int id)
{
    e->id=id;
}

void setSoldi(Movimento* e, int soldi)
{
    e->soldi=soldi;
}

Movimento* creaDefault()
{
    return crea(0,0);
}

Movimento* crea(int id, int soldi)
{  
    Movimento* e = (Movimento*)malloc(sizeof(Movimento));
    e->id=id;
    e->soldi=soldi;
    return e;
}

void distruggi(Movimento* e)
{
    free(e);
}

    //Fatto da Fabio Luca Stanciu
Movimento* creacopia(Movimento e){
    return crea(getID(e),getSoldi(e));
}

char* recordToString(Movimento e){
    char buffer[DIM];
    int id_tmp = getID(e);
    int soldi_tmp = getSoldi(e);
    sprintf(buffer, "%c;%c;%c,%c,%d", id_tmp,soldi_tmp);
    return strdup(buffer);    
}

void stringToFile(Movimento e, FILE* fp){
    char* tmp = recordToString(e);
    fprintf(fp, "%s\n", tmp);
    free(tmp);
}



#endif
