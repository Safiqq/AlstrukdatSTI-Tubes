#include <stdio.h>
#include "./ADT/queue/queue.h"
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"

int WordToInt(Word CWord)
{
    int result = 0;
    for(int i = 0; i < CWord.Length;i++)
    {
        result = result*10 + (CWord.TabWord[i] - '0');
    }  
    return result;
}
void skipgame(Word skip, TabStr *listgame, Queue *antriangameidx){
    ADVWORD();
    int num = WordToInt(currentWord);        //cara ngubah word ke int belum fix
    printf("Berikut adalah daftar game milikmu: \n");
    for(int i=1;i<=length(*antriangameidx);i++){
        printf("%d. %s\n",i,listgame->TI[antriangameidx->buffer[i-1]]);
    }
    if (num>length(*antriangameidx)-1){
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
    else{
        while (num!=0){
            QueElType val;
            dequeue(antriangameidx, &val);
            num--;
        }
        playgame(listgame,antriangameidx);
    }
}