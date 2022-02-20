#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FromCsvToRecord.h"


int main(int argc, char**argv){
    if(argc!=3){
        printf("USAGE: #FILE_BASE #FILE_MOD");
        return -1;
    }
    FILE* fpb = fopen(argv[1],"r");
    FILE* fpm = fopen(argv[2],"r");
    if(fpb == NULL || fpm == NULL){
        printf("Errore apertura di File_Base o File_Modificatore\n\ncontrollare se i file sono esitenti");
        return -2;
    }
    Account* persona = crea("ID",100);
    showAccount(*persona);
    distruggi(persona);
    return 0;
}

/*
--> ricevere id e conto corrente da CSV
*/
