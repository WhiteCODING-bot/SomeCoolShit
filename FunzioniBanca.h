#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#define DIM 1024


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    int IdA;
    int Soldi;
    char* Nominativo;
}Account;

int getIdA(Account);
int getSoldi(Account);
char* getNominativo(Account e);
void setID(Account*, int);
void setSoldi(Account*, int);
void setNominativo(Account* e, char* Nominativo);
Account* creaAccountDefault();
Account* creaAccount(int, int, char*);
void DisposerAccount(Account*);
Account* creacopiaAccount(Account e);
char* AccountToString(Account);
void stringAToFile(Account, FILE*);

int getIdA(Account e){
    return e.IdA;
}

int getSoldi(Account e){
    return e.Soldi;
}

char* getNominativo(Account e){
    return strdup(e.Nominativo);
}

void setIdA(Account* e, int id){
    e->IdA=id;
}

void setSoldi(Account* e, int soldi){
    e->Soldi=soldi;
}

void setNominativo(Account* e, char* nominativo){
    if(e->Nominativo != NULL) free(e -> Nominativo);
    e -> Nominativo = strdup(nominativo);
}

Account* creaAccountDefault(){
    return creaAccount(0,0,NULL);
}

Account* creaAccount(int id, int soldi, char*nominativo){  
    Account* e = (Account*)malloc(sizeof(Account));
    e->IdA = id;
    e->Soldi = soldi;
    e->Nominativo = nominativo;
    return e;
}

void DisposerAccount(Account* e){
    free(e);
}

Account* creacopiaAccount(Account e){
    return creaAccount(getIdA(e), getSoldi(e), getNominativo(e));
}

char* AccountToString(Account e){
    char buffer[DIM];
    char* Nominativo_tmp = getNominativo(e);
    sprintf(buffer, "%d;%d;%s", getIdA(e), getSoldi(e), Nominativo_tmp);
    free(Nominativo_tmp);
    return strdup(buffer);    
}

void stringAToFile(Account e, FILE* fp){
    char* tmp = AccountToString(e);
    fprintf(fp, "%s\n", tmp);
    free(tmp);
}

#endif //__ACCOUNT_H__