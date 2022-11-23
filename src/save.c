#include <stdlib.h>
#include "./ADT/array/array.h"
#include "./ADT/mapscoreboard/map.h"

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
    fprintf(txt,"%s\n",intToString(sb.Count));
    MapSB temp = sb;
    int i=0;
    for(i;i<sb.Count;i++){
        fprintf(txt,"%s %s\n",temp.Elements[iMax(temp)].Key,intToString(Val(temp,temp.Elements[iMax(temp)].Key)));
        DeleteMap(&temp,temp.Elements[iMax(temp)].Key);
    }
}

void save(char *namafile, TabStr games, MapSB sbTOH,MapSB sbDiner,MapSB sbSOM,MapSB sbRNG,MapSB sbHangman, MapSB sbGameTambahan)
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
  for (i = 0; i < LengthArray(games) - 1; i++)
  {
    fprintf(txt, "%s\n", games.TI[i]);
  }
  fprintf(txt, "%s\n", games.TI[LengthArray(games) - 1]);
  saveSB(sbRNG,txt);
  saveSB(sbDiner,txt);
  saveSB(sbHangman,txt);
  saveSB(sbTOH,txt);
  saveSB(sbSOM,txt);
  saveSB(sbGameTambahan,txt);

  fclose(txt);
  printf("Save file berhasil disimpan.\n");
}
