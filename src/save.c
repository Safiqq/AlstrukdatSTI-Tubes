#include <stdio.h>
#include <stdlib.h>
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"

char *concat(char a[500],char b[500])
{
  int i=0,j=0;
  while(a[i]!='\0')
  i++;
  while(b[j]!='\0')
  {
    a[i]=b[j];
    j++;
    i++;
  }
  a[i]='\0';
  return a;
}

void save(char namafile[100], TabStr arraygame){
    FILE*pita;
    char path[10] = "../data/";
    pita=fopen(concat(path,namafile),"w");

    fprintf(pita,"%c\n",(char)(NbElmt(arraygame)+48));

    for(int i=0;i<NbElmt(arraygame);i++){
        fprintf(pita,"%s\n",arraygame.TI[i]);
    }
    fclose(pita);
    printf("Save file berhasil disimpan.\n");
}

