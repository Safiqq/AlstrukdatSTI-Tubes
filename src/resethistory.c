#include "./ADT/stackH/stack.h"
#include "ADT/mesinkata/mesinkata.h"
#include "./ADT/array/array.h"

void resethistory(Stack *history, TabStr games){
    if (!IsEmptyStack(*history)){
        printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK) ");
        STARTWORD("", "");
        while (!isEqual(currentWord, "YA") && !isEqual(currentWord, "TIDAK")){
            printf("MASUKAN SALAH! SILAKAN ULANGI. (YA/TIDAK) ");
            STARTWORD("", "");
        }
        if (isEqual(currentWord, "YA")){
            while (!IsEmptyStack(*history)){
                infotype x;
                pop(history,&x);
            }
            printf("History berhasil di-reset.\n");
        }
        else{
            printf("History tidak jadi di-reset. ");
            int i;
            printf("Berikut adalah daftar game yang telah dimainkan: \n");
            for (i = nbelmtStack(*history); i > 0; i--)
            {
                printf("%d. %s\n", nbelmtStack(*history)-i+1, history->Tab[i - 1]);
            }
        }
    }
    else{
        printf("History-mu kosong, kamu belum memainkan game apapun, gaada yang bisa dihapus nih.\n");
    }
}