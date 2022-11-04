#include <stdio.h>
#include <stdlib.h>
#include "./ADT/array/array.h"

void save(char * namafile, TabStr listgame){
    FILE*txt;
    char path[100] = "../data/";
    int i = 8;
    while(*namafile!='\0'){
      path[i] = *namafile;
      i++;
      *namafile++;
    }
    txt=fopen(path,"w");

    fprintf(txt,"%c\n",(char)(listgame.Neff+48));

    for(int i=0;i<NbElmt(listgame)-1;i++){
        fprintf(txt,"%s\n",listgame.TI[i]);
    }
    fprintf(txt,"%s",listgame.TI[NbElmt(listgame)-1]);

    fclose(txt);
    printf("Save file berhasil disimpan.\n");
}
