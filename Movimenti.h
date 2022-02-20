#ifndef __MOVIMENTI_BANCARI_H__
#define __MOVIMENTI_BANCARI_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 1024

typedef struct{
    int id;
    int soldi;
}Movimento;


int getId (Movimento);
int getSaldo (Movimento);
void setId (Movimento*, int);
void setSaldo (Movimento*, int);
Movimento* creaMovimento(int, int);
Movimento* creaMovimentoDefault ();
Movimento* creaPCcopia(Movimento);
void showMovimento(Movimento);
void disposerMovimento(Movimento*);
//int RandomN();
//int RandomId();

int getId (Movimento e){
    return e.id;
}
int getSaldo (Movimento e){
    return e.soldi;
}
    //Fatto da Fabio Luca Stanciu

void setId (Movimento* e, int id){
    e->id = id;
}
void setSaldo (Movimento* e, int soldi){
    e->soldi = soldi;
}


Movimento* creaMovimento(int Id, int Saldo){
    Movimento* e = (Movimento*)malloc(sizeof(Movimento));
    e -> id = Id;
    e -> soldi = Saldo;
    return e;
}

Movimento* creaMovimentoDefault(){
    return creaMovimento(0, 0);
}

Movimento* creaMovimentocopia(Movimento e){
    int Id_tmp = e.id;
    int Saldo_tmp = e.soldi;

    Movimento* e2 = creaMovimento(Id_tmp, Saldo_tmp);
    return e2;
}

void disposerMovimento(Movimento* e){
    free(e);
}

void showMovimento(Movimento e){
    printf ("\nId: %d\n", getId(e));
    printf ("\nSaldo: %d\n", getSaldo(e));
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
