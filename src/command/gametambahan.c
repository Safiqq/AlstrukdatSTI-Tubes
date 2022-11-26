#include "../header/gametambahan.h"

void gameTambahan(ArrayMap *arrSB, int play)
{
    int skor;
    srand(time(NULL));
    skor = rand() % 100;
    printf("=========================================\n");
    printf("GAME OVER\n");
    InsertSB(&arrSB->TIMap[play], skor);
    printf("=========================================\n\n");
}
