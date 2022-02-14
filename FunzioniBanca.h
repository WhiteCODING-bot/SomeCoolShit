#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#define DIM 1024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char* id;
    int soldi;
}Account;

char* getID(Account);
int getSoldi(Account);

void setID(Account*, char*);
void setSoldi(Account*, int);

Account* creaDefault();
Account* crea(char*, int);
void distruggi(Account*);
Account* creaCopia(Account e);

void showAccount(Account e);
char* recordToString(Account);
void stringToFile(Account, FILE*);




char* getID(Account e)
{
    return e.id;
}
int getSoldi(Account e)
{
    return e.soldi;
}


void setID(Account* e, char* id)
{
    e->id=id;
}
void setSoldi(Account* e, int soldi)
{
    e->soldi=soldi;
}

Account* creaDefault()
{
    return crea(NULL,0);
}
Account* crea(char* id, int soldi)
{  
    Account* e = (Account*)malloc(sizeof(Account));
    e->id=id;
    e->soldi=soldi;
    return e;
}


void showAccount(Account e)
{
    printf("---Account---\n");
    printf("id: %c\n", getID(e));
    printf("soldi: %d\n", getSoldi(e));
}
void distruggi(Account* e)
{
    free(e);
}
Account* creacopia(Account e){
    return crea(getID(e),getSoldi(e));
}
char* recordToString(Account e){

    char buffer[DIM];

    char* id_tmp = getID(e);
    int soldi_tmp = getSoldi(e);
   

    sprintf(buffer, "%c;%c;%c,%c,%d", id_tmp,soldi_tmp);


    free(id_tmp);
    free(soldi_tmp);

    return strdup(buffer);    
}

void stringToFile(Account e, FILE* fp){

    char* tmp = recordToString(e);

    fprintf(fp, "%s\n", tmp);

    free(tmp);
}
#endif
