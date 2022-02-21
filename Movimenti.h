#ifndef __MOVIMENTI_BANCARI_H__
#define __MOVIMENTI_BANCARI_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FunzioniBanca.h"

#define DIM 1024

typedef struct {
    int IdM;
    int Saldo;
    char* Data;
}Movimento;

int getIdM(Movimento);
int getId(Account);
int getSaldo(Movimento);
char* getData(Movimento);
void setIdM(Movimento*, int);
void setSaldo(Movimento*, int);
void setData(Movimento*, char*);
Movimento* creaMovimento(int, int, char*);
Movimento* creaMovimentoDefault();
Movimento* creaMovimentocopia(Movimento);
void disposerMovimento(Movimento*);
void showMovimento(Movimento);
char* MovimentoToString(Movimento);
void stringMToFile(Movimento, FILE*);

int getIdM(Movimento e){
    return e.IdM;
}
int getSaldo(Movimento e){
    return e.Saldo;
}
char* getData(Movimento e){
    return strdup(e.Data);
}

void setIdM(Movimento* e, int IdM){
    e->IdM = IdM;
}
void setSaldo(Movimento* e, int Saldo){
    e->Saldo = Saldo;
}
void setData(Movimento* e, char* Data){
    if(e->Data != NULL) free(e -> Data);
    e -> Data = strdup(Data);
}

Movimento* creaMovimento(int IdM, int Saldo, char* Data){
    Movimento* e = (Movimento*)malloc(sizeof(Movimento));
    e -> IdM = IdM;
    e -> Saldo = Saldo;
    e -> Data = strdup(Data);
    return e;
}

Movimento* creaMovimentoDefault(){
    return creaMovimento(0, 0, NULL);
}

Movimento* creaMovimentocopia(Movimento e){
    int IdM_tmp = e.IdM;
    int Saldo_tmp = e.Saldo;
    char* Data_tmp = strdup(e.Data);

    Movimento* e2 = creaMovimento(IdM_tmp, Saldo_tmp, Data_tmp);
    free(Data_tmp);
    return e2;
}

void disposerMovimento(Movimento* e){
    if(e->Data) free(e->Data);
    free(e);
}

char* MovimentoToString(Movimento e){
    char buffer[DIM];
    char* Data_tmp = getData(e);
    sprintf(buffer, "%d;%d;%s", getIdM(e), getSaldo(e), Data_tmp);
    free(Data_tmp);
    return strdup(buffer);    
}

void stringMToFile(Movimento e, FILE* fp){
    char* tmp = MovimentoToString(e);
    fprintf(fp, "%s\n", tmp);
    free(tmp);
}
void showMovimento(Movimento e){
    printf ("\nId: %d", getIdM(e));
    printf ("\nSaldo: %d\n", getSaldo(e));
    printf("\nData: %s",getData(e));

}

int getId(Account a){
    return a.IdA;
}

void showAccount(Account a){
    printf ("\nId: %d", getId(a));
    printf ("\nSaldo: %d", getSoldi(a));

}



#endif //__MOVIMENTI_BANCARI_H__