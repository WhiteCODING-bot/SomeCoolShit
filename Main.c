#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FromCsvToRecord.h"

int main(int argc, char**argv,Account a,Movimento m){
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

    Account* acc = loadAcc(fpb);
    Movimento* mov = loadMov(fpm);
    printf("Account");
    showAccount(*acc);
    disposerMovimento(mov);
    DisposerAccount(acc);
    fclose(fpb);
    fclose(fpm);
    return 0;
}
