#include "../header/resethistory.h"

void resetHistory(StackStr *history, ArrayStr games)
{
    if (!IsEmptySS(*history))
    {
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
        STARTWORD("", "");
        while (!isEqual(currentWord, "YA") && !isEqual(currentWord, "TIDAK"))
        {
            printf("MASUKAN SALAH! SILAKAN ULANGI. (YA/TIDAK) ");
            STARTWORD("", "");
        }
        if (isEqual(currentWord, "YA"))
        {
            while (!IsEmptySS(*history))
            {
                infotypeSS x;
                PopSS(history, &x);
            }
            printf("History berhasil di-reset.\n");
        }
        else
        {
            printf("History tidak jadi di-reset. ");
            int i;
            printf("Berikut adalah daftar game yang telah dimainkan: \n");
            for (i = NbElmtSS(*history); i > 0; i--)
            {
                printf("%d. %s\n", NbElmtSS(*history) - i + 1, history->Tab[i - 1]);
            }
        }
    }
    else
    {
        printf("History-mu kosong, kamu belum memainkan game apapun, gaada yang bisa dihapus nih.\n");
    }
}