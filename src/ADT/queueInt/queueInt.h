/* File : queueInt.h */
/* Definisi ADT Queue of Int dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __QUEUEINT_H__
#define __QUEUEINT_H__

#include <stdio.h>
#include "../../header/boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef int ElTypeQue;
typedef struct
{
    ElTypeQue buffer[CAPACITY];
    int idxHead;
    int idxTail;
} Queue;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
extern void CreateQI(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
extern boolean IsEmptyQI(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

extern int LengthQI(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
extern void EnqueueI(Queue *q, ElTypeQue val);
// EnqueueI alt-1

extern void DequeueI(Queue *q, ElTypeQue *val);
// DequeueI alt-1

extern void DisplayQI(Queue q);
// menampilkan isi queue
#endif