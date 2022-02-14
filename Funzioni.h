#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char* nome;
char* cognome;
char* pass;
char* id; //(once random generator)
int soldi;
}Account;

char* getNome(Account);
char* getCognome(Account);
char* getPass(Account);
char* getID(Account);
int getSoldi(Account);

void setNome(Account*, char*);
void setCognome(Account*, char*);
void setPass(Account*, char*);
void setID(Account*, char*);
void setSoldi(Account*, int);

Account* creaDefault();
Account* crea(char*, char*, char*, char*, int);
void distruggi(Account*);
Account* creaCopia(Account e);

void showAccount(Account e);



char* getNome(Account e)
{
    return e.nome;
}
char* getCognome(Account e)
{
    return e.cognome;
}
char* getPass(Account e)
{
    return e.pass;
}
char* getID(Account e)
{
    return e.id;
}
int getSoldi(Account e)
{
    return e.soldi;
}

void setNome(Account* e, char* nome)
{
    e->nome=nome;
}
void setCognome(Account* e, char* cognome)
{
    e->cognome=cognome;
}
void setPass(Account* e, char* pass)
{
    e->pass=pass;
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
    return crea(NULL,NULL,NULL,NULL,0);
}
Account* crea(char* nome, char* cognome, char* pass, char* id, int soldi)
{  
    Account* e = (Account*)malloc(sizeof(Account));
    e->nome=nome;
    e->cognome=cognome;
    e->pass=pass;
    e->id=id;
    e->soldi=soldi;
    return e;
}


void showAccount(Account e)
{
    printf("---Account---\n");
    printf("nome: %c\n", getNome(e));
    printf("cognome: %c\n", getCognome(e));
    printf("pass: %c\n", getPass(e));
    printf("id: %c\n", getID(e));
    printf("soldi: %d\n", getSoldi(e));
}
void distruggi(Account* e)
{
    free(e);
}
Account* creacopia(Account e){
    return crea(getNome(e),getCognome(e),getPass(e),getID(e),getSoldi(e));
}
#endif

