#include "../header/save.h"

char *intToString(int val)
{
  if (val == 0)
  {
    return "0";
  }
  else
  {
    static char buf[32] = {0};
    int i = 30;
    for (; val && i; --i, val /= 10)
      buf[i] = "0123456789abcdef"[val % 10];
    return &buf[i + 1];
  }
}

void saveSB(MapStr sb, FILE *txt)
{
  fprintf(txt, "%s", intToString(sb.Count));
  MapStr temp = sb;
  int i = 0;
  for (i; i < sb.Count; i++)
  {
    fprintf(txt, "\n%s %s", temp.Elements[iMax(temp)].Key, intToString(ValueMS(temp, temp.Elements[iMax(temp)].Key)));
    DeleteMS(&temp, temp.Elements[iMax(temp)].Key);
  }
}

void save(char *namafile, ArrayStr games, StackStr riwayat, ArrayMap arrSB)
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

  fprintf(txt, "%s\n", intToString(games.Neff));
  for (i = 0; i < LengthAS(games); i++)
  {
    fprintf(txt, "%s\n", games.TI[i]);
  }

  fprintf(txt, "%s\n", intToString(NbElmtSS(riwayat)));
  for (i = NbElmtSS(riwayat); i > 0; i--)
  {
    fprintf(txt, "%s\n", riwayat.Tab[i - 1]);
  }

  for (i = 0; i < NbElmtAM(arrSB) - 1; i++)
  {
    saveSB(arrSB.TIMap[i], txt);
    fprintf(txt, "\n");
  }
  saveSB(arrSB.TIMap[i], txt);

  fclose(txt);
  printf("Save file berhasil disimpan.\n");
}
