#include "./ADT/array/array.h"
#include "./ADT/stackH/stack.h"
#include "ADT/mesinkata/mesinkata.h"

void history(Stack *history, TabStr games){
    ADVWORD();
    int i, num = atoi(currentWord.TabWord);
    if (num>0){
        if (!IsEmptyStack(*history)){
            printf("Berikut adalah daftar game yang telah dimainkan: \n");
            if (num>=nbelmtStack(*history)) {
                for (i = nbelmtStack(*history); i > 0; i--)
                {
                    printf("%d. %s\n", nbelmtStack(*history)-i+1, games.TI[history->Tab[i - 1]]);
                }
            }
            else{
                for (i = nbelmtStack(*history); i > nbelmtStack(*history)-num; i--)
                {
                    printf("%d. %s\n", nbelmtStack(*history)-i+1, games.TI[history->Tab[i - 1]]);
                } 
            }
        }else{
            printf("Kamu belum memainkan game apapun, silakan mainkan game dulu yaa.\n");
        }
    }
    else{
        printf("Masukan <n> tidak valid. Silakan ulangi.\n");
    }
}