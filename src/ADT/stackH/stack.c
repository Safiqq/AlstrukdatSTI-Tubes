#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
    Top(*S) = Nil;
};
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : Top bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
    return (Top(S) == Nil);
};

/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S){
    return (Top(S) == MaxEl-1);
};
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack * S, infotype X){
    Top(*S)++;
    InfoTop(*S) = X;
};
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi Top yang baru,Top bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S)--;
};
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen Top yang lama, Top berkurang 1 */

int nbelmtStack(Stack S)
/* Mengembalikan jumlah elemen dari stack*/
{
    return Top(S) + 1;
}

void reversestack(Stack *S)
/* I.S Stack tidak kosong, stack terdefinisi*/
/* F.S Stack berisi elemen yang urutannya terbalik dari yang awal*/
{
    Stack S2;
    CreateEmptyStack(&S2);
    while (!IsEmptyStack(*S))
    {
        infotype X;
        pop(S,&X);
        push(&S2,X);
    }
    int i;
    for (i=0;i<nbelmtStack(S2);i++){
        S->Tab[i]=S2.Tab[i];
    }
    S->TOP=S2.TOP;
}