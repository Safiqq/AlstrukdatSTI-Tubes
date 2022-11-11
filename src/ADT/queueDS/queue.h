/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef __QUEUEDS_H__
#define __QUEUEDS_H__

#include <stdio.h>
#include "../../boolean.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct
{
    int timeC;
    int timeK;
    int price;
} ElTypeDS;

typedef struct
{
    ElTypeDS buffer[CAPACITY];
    int idxHead;
    int idxTail;
} QueueDS;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQueueDS(QueueDS *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean IsEmptyQueueDS(QueueDS q);
/* Mengirim true jika q kosong: lihat definisi di atas */

int LengthQueueDS(QueueDS q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void EnqueueDS(QueueDS *q, ElTypeDS val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void DequeueDS(QueueDS *q, ElTypeDS *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

#endif