#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__
#define DIM 1024
#define MAX 2048


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

char** split(char* line, char separatore);
char** duplicatore(char** v);



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
    printf("id: %s\n", getID(e));
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
    return strdup(buffer);    
}

void stringToFile(Account e, FILE* fp){
    char* tmp = recordToString(e);
    fprintf(fp, "%s\n", tmp);
    free(tmp);
}

char** split(char* line, char separatore){ //Molto spesso le split alterano la stringa originale
	char* buffer[MAX+1];
	char sep[] = {separatore,'\0'};
	buffer[0] = strtok(line, sep);
	for(int i=1;buffer[i] = strtok(NULL,sep);i++){	}
	return duplicatore(buffer);
	//Funzione strtok ==> modifica la stringa di partenza e ci mette un tappo
	//strtok(line, sep) --> la prima sottostringa
	//strtok(NULL, sep) --> le successive
}

char** duplicatore(char** v){
	int len;
	for(len=0;*(v+len);len++){ } //Prima conta
	char** ret = (char**) malloc(sizeof(char*)*(len+1)); //Poi alloca
	for(char** tmp=ret;*ret=*v;v++,tmp++){ } //Duplica il vettore non il contenuto
	return ret;
}


#endif
