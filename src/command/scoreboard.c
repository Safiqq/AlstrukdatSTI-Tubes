#include "../header/scoreboard.h"

void printScoreboard(MapStr sb, char *nama)
{
    MapStr temp = sb;
    printf("**** SCOREBOARD GAME %s ****\n", nama);
    printf("| NAMA\t\t| SKOR\t\t|\n");
    printf("|-------------------------------|\n");
    int i = 0;
    for (i; i < sb.Count; i++)
    {
        printf("| %s\t", temp.Elements[iMax(temp)].Key);
        if (stringLength(temp.Elements[iMax(temp)].Key) < 6)
        {
            printf("\t");
        }
        printf("| %d\t\t|\n", ValueMS(temp, temp.Elements[iMax(temp)].Key));
        DeleteMS(&temp, temp.Elements[iMax(temp)].Key);
    }
    printf("\n");
}

void scoreboard(ArrayMap arrSB, ArrayStr games)
{
    int i;
    for (i = 0; i < NbElmtAM(arrSB); i++)
    {
        printScoreboard(arrSB.TIMap[i], games.TI[i]);
    }
}
