#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FromCsvToRecord.h"



int main(int argc, char**argv,Account a,Movimento m){
    if(argc!=3){
        printf("USAGE: #FILE_BASE #FILE_MOD");
        return -1;
    }
    FILE* fpb = fopen(argv[1],"r+");
    FILE* fpm = fopen(argv[2],"r");
    if(fpb == NULL || fpm == NULL){
        printf("Errore apertura di File_Base o File_Modificatore\n\ncontrollare se i file sono esitenti");
        return -2;
    }

    Movimento* mov = loadMov(fpm);
    Account* acc = loadAcc(fpb);
    int Ida = getIdA(*acc);
    int Idm = getIdM(*mov);
    showAccount(*acc);
    if(Ida==Idm){
        acc->Soldi+=mov->Saldo;
        showAccount(*acc);
        stringAToFile(*acc, fpb);
    }
    fclose(fpb);
    fclose(fpm);
    disposerMovimento(mov);
    DisposerAccount(acc);
    return 0;
}