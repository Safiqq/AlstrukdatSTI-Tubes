#include "../header/resetscoreboard.h"

void resetScoreboard(ArrayMap *arrSB, ArrayStr games)
{
  printf("DAFTAR SCOREBOARD:\n");
  printf("0. ALL\n");

  int i;
  for (i = 0; i < NbElmtAM(*arrSB); i++)
  {
    printf("%d. %s\n", i + 1, games.TI[i]);
  }
  printf("SCOREBOARD YANG INGIN DIHAPUS: ");
  STARTWORD("", "");
  int n = atoi(currentWord.TabWord);
  if (n == 0)
  {
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SEMUA (YA/TIDAK)? ");
  }
  else
  {
    printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", games.TI[n - 1]);
  }
  STARTWORD("", "");
  while (!(isEqual(currentWord, "YA") || isEqual(currentWord, "TIDAK")))
  {
    printf("INPUT TIDAK VALID, APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)? ", games.TI[n - 1]);
    STARTWORD("", "");
  }

  if (isEqual(currentWord, "YA"))
  {
    if (n == 0)
    {
      for (i = 0; i < NbElmtAM(*arrSB); i++)
      {
        arrSB->TIMap[i].Count = 0;
      }
    }
    else
    {
      arrSB->TIMap[n - 1].Count = 0;
    }
    printf("Scoreboard berhasil di-reset. \n");
  }
  else
  {
    printf("Scoreboard tidak di-reset. \n");
  }
}