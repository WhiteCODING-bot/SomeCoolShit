#ifndef __FILE_H__
#define __FILE_H__

#include "FunzioniBanca.h"
#include "Movimenti.h"

#define MAX 2048
#define SEPARATORE ';'

char* readline(FILE*);
char** split(char*);
char** duplicatore(char**);
Account* loadAcc(FILE* fp);
void distruggiVettStringhe(char**);
Movimento* loadMov(FILE* fp);

char* readline(FILE* fp){

    char buffer[MAX];
    int i = 0;
    for(;(buffer[i] = fgetc(fp)) != '\n' && buffer[i] != EOF; i++);
    buffer[i] = '\0';
    if(i == 0) return NULL;
    return strdup(buffer); 
}

char** split(char* s){

    char sep[] = {SEPARATORE, '\0'};
    char* vettstr[MAX];
    vettstr[0] = strtok(s, sep);
    int i = 1;
    for(; (vettstr[i] = strtok(NULL, sep)) != NULL; i++){}
      return duplicatore(vettstr);  

    
}

char** duplicatore(char** vettstr){
    int lunghezza;
    for(lunghezza=0;*(lunghezza+vettstr);lunghezza++){}
    char** ret = (char**)malloc(sizeof(char*)*lunghezza+1);
    char** tmp = ret;
    for(tmp;*tmp=*vettstr;tmp++,vettstr++){}
    return ret;
}

Account* loadAcc(FILE* fp){
    //LEGGERE CSV
    char* stringa = readline(fp);
    char** vett_stringhe = split(stringa);
    int id = atoi(vett_stringhe[0]);
    int soldi = atoi(vett_stringhe[1]);
    Account* acc = creaAccount(id, soldi, vett_stringhe[2]);
    distruggiVettStringhe(vett_stringhe);
    return acc;
}

Movimento* loadMov(FILE* fp){
    //LEGGERE CSV
    char* stringa = readline(fp);
    char** vett_stringhe = split(stringa);
    int id = atoi(vett_stringhe[0]);
    int soldi = atoi(vett_stringhe[1]);
    char* data = vett_stringhe[2];
    Movimento* mov = creaMovimento(id, soldi, data);
    distruggiVettStringhe(vett_stringhe);
    return mov;

}

void distruggiVettStringhe(char** vett_stringhe)
{
    char** tmp = vett_stringhe;
    //for(;*vett_stringhe;vett_stringhe++)
    //{
    //    free(*vett_stringhe);
    //}
    free(tmp);
}

#endif // __FILE_H__