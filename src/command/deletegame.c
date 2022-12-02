#include "../header/deletegame.h"

void deleteGame(ArrayStr *games, Queue *antriangames, StackStr *history, ArrayMap *arrSB)
{
    int i;
    ElTypeQue hapus;

    printf("Berikut adalah daftar game yang tersedia\n");
    for (i = 1; i <= LengthAS(*games); i++)
        printf("%d. %s\n", i, games->TI[i - 1]);

    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD("", "");
    hapus = atoi(currentWord.TabWord);

    if (hapus <= 8 || hapus > games->Neff)
        printf("Game gagal dihapus.\n");
    else
    {
        boolean isInAntrian = false;
        i = 0;
        while ((i < LengthQI(*antriangames)) && !isInAntrian)
        {
            if (hapus - 1 == (*antriangames).buffer[i])
                isInAntrian = true;
            i++;
        }
        if (isInAntrian)
            printf("Game gagal dihapus.\n");
        else
        {
            // Menghapus game yang ada di history
            StackStr S2;
            CreateSS(&S2);
            while (!IsEmptySS(*history))
            {
                infotypeSS X;
                PopSS(history, &X);
                if (*X != *games->TI[hapus - 1])
                {
                    PushSS(&S2, X);
                }
            }
            ReverseSS(&S2);
            int i;
            for (i = 0; i < NbElmtSS(S2); i++)
            {
                history->Tab[i] = S2.Tab[i];
            }
            history->TOP = S2.TOP;
            // Menghapus game dari list game
            for (i = hapus - 1; i < LengthAS(*games); i++)
            {
                if (i != LengthAS(*games) - 1)
                    (*games).TI[i] = (*games).TI[i + 1];
                else
                    (*games).Neff -= 1; // menghapus elemen terakhir menjadi sampah
            }
            ElTypeQue val;
            for (i = 0; i < LengthQI(*antriangames); i++)
            {
                DequeueI(antriangames, &val);
                if (val >= hapus)
                    val--;
                EnqueueI(antriangames, val);
            }
            DeleteAtAM(arrSB, hapus - 1);
            printf("Game berhasil dihapus.\n");
        }
    }
}