#include <stdlib.h>
#include "./ADT/array/array.h"

void save(char *namafile, TabStr games)
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

    fprintf(txt,"%c\n",(char)(games.Neff+48));

  for (i = 0; i < LengthArray(games) - 1; i++)
  {
    fprintf(txt, "%s\n", games.TI[i]);
  }
  fprintf(txt, "%s", games.TI[LengthArray(games) - 1]);

  fclose(txt);
  printf("Save file berhasil disimpan.\n");
}
