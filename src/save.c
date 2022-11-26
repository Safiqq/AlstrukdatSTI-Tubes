#include <stdlib.h>
#include "./ADT/array/array.h"
#include "./ADT/stackH/stack.h"
#include "./ADT/mapscoreboard/mapsb.h"
#include "./ADT/arrayOfMap/arraymap.h"
//r
char* intToString(int val){
    if(val==0){
        return "0";
    }
    else{
         static char buf[32] = {0};
        int i = 30;
        for(; val && i ; --i, val /= 10)
            buf[i] = "0123456789abcdef"[val % 10];
        return &buf[i+1];
    }
}

void saveSB(MapSB sb,FILE * txt){
    fprintf(txt,"%s",intToString(sb.Count));
    MapSB temp = sb;
    int i=0;
    for(i;i<sb.Count;i++){
        fprintf(txt,"\n%s %s",temp.Elements[iMax(temp)].Key,intToString(Value(temp,temp.Elements[iMax(temp)].Key)));
        DeleteMap(&temp,temp.Elements[iMax(temp)].Key);
    }
}

void save(char *namafile, TabStr games, Stack riwayat,TabMap arrSB)
{
  FILE *txt;
  char path[100] = "../data/";
  int i = 8;
  while (*namafile != '\0')
  {
    path[i] = *namafile;
    i++;
    *namafile++;
  }
  txt = fopen(path, "w");

  fprintf(txt,"%s\n",intToString(games.Neff));
  for (i = 0; i < LengthArray(games); i++)
  {
    fprintf(txt, "%s\n", games.TI[i]);
  }

  fprintf(txt,"%s\n",intToString(nbelmtStack(riwayat)));
   for (i = nbelmtStack(riwayat); i>0 ; i--)
  {
    fprintf(txt, "%s\n", riwayat.Tab[i - 1]);
  }

  for(i=0;i<NbElmtArrMap(arrSB);i++){
    saveSB(arrSB.TIMap[i],txt);
    fprintf(txt,"\n");
  }
  saveSB(arrSB.TIMap[i],txt);

  fclose(txt);
  printf("Save file berhasil disimpan.\n");
}
