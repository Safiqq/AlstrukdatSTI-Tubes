/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdio.h>
#include "../../boolean.h"

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
extern void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
extern boolean IsEmptyQueue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */

extern int LengthQueue(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
extern void Enqueue(Queue *q, ElTypeQue val);
//Enqueue alt-1

extern void Dequeue(Queue *q, ElTypeQue *val);
//dequeue alt-1

extern void DisplayQueue(Queue q);
//menampilkan isi queue
#endif