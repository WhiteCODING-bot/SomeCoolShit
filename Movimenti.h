#ifndef __MOVIMENTI_BANCARI_H__
#define __MOVIMENTI_BANCARI_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 1024

typedef struct {
    int Id;
    int Saldo;
    char* Data;
}Movimento;

int getId (Movimento);
int getSaldo (Movimento);
char* getData (Movimento);
void setId (Movimento*, int);
void setSaldo (Movimento*, int);
void setData (Movimento*, char*);
Movimento* creaMovimento(int, int, char*);
Movimento* creaMovimentoDefault ();
Movimento* creaPCcopia(Movimento);
void showMovimento(Movimento);
void disposerMovimento(Movimento*);
//int RandomN();
//int RandomId();

int getId (Movimento e){
    return e.Id;
}
int getSaldo (Movimento e){
    return e.Saldo;
}
char* getData (Movimento e){
    return strdup(e.Data);
}

void setId (Movimento* e, int Id){
    e->Id = Id;
}
void setSaldo (Movimento* e, int Saldo){
    e->Saldo = Saldo;
}
void setData (Movimento* e, char* Data){
    if(e->Data != NULL) free(e -> Data);
    e -> Data = strdup(Data);
}

Movimento* creaMovimento(int Id, int Saldo, char* Data){
    Movimento* e = (Movimento*)malloc(sizeof(Movimento));
    e -> Id = Id;
    e -> Saldo = Saldo;
    e -> Data = strdup(Data);
    return e;
}

Movimento* creaMovimentoDefault(){
    return creaMovimento(0, 0, NULL);
}

Movimento* creaMovimentocopia(Movimento e){
    int Id_tmp = e.Id;
    int Saldo_tmp = e.Saldo;
    char* Data_tmp = strdup(e.Data);

    Movimento* e2 = creaMovimento(Id_tmp, Saldo_tmp, Data_tmp);
    free(Data_tmp);
    return e2;
}

void disposerMovimento(Movimento* e){
    if(e->Data) free(e->Data);
    free(e);
}

void showMovimento(Movimento e){
    printf ("\nId: %d\n", getId(e));
    printf ("\nSaldo: %d\n", getSaldo(e));
    char* tmp = getData(e);
    printf("Saldo: %s\n", tmp);
    free(tmp);
}

/*
int RandomId(){
    char ar[6];
    int i;
    for(i = 0; i<6;i++){
        ar[i] = RandomN();
    }
    return atoi(ar);
}

int RandomN(){
    srand(time(NULL));
    return (rand()%10);
}
*/
#endif //__MOVIMENTI_BANCARI_H__
