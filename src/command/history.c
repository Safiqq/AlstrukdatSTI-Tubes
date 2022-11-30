#include "../header/history.h"

void history(StackStr *history)
{
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);
    if (num > 0)
    {
        if (!IsEmptySS(*history))
        {
            printf("Berikut adalah daftar game yang telah dimainkan: \n");
            if (num >= NbElmtSS(*history))
            {
                for (i = NbElmtSS(*history); i > 0; i--)
                {
                    printf("%d. %s\n", NbElmtSS(*history) - i + 1, history->Tab[i - 1]);
                }
            }
            else
            {
                for (i = NbElmtSS(*history); i > NbElmtSS(*history) - num; i--)
                {
                    printf("%d. %s\n", NbElmtSS(*history) - i + 1, history->Tab[i - 1]);
                }
            }
        }
        else
        {
            printf("Kamu belum memainkan game apapun, silakan mainkan game dulu yaa.\n");
        }
    }
    else
    {
        printf("Masukan <n> tidak valid. Silakan ulangi.\n");
    }
}