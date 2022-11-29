/* File: listdp.h */
/* ADT List dengan Double Pointer */
/* Representasi berkait dengan address adalah pointer */
/* ElTypeLDP adalah ADT yg menyimpan koordinat x dan y, serta info pada koordinat tsb. */

#ifndef __LISTDP_H__
#define __LISTDP_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../header/boolean.h"

#define NilLDP NULL

/* Definisi Type Data */
typedef struct
{
	int x;
	int y;
	char info;
} ElTypeLDP;
typedef struct tElmtLDP *addressLDP;
typedef struct tElmtLDP
{
	ElTypeLDP El;
	addressLDP next;
	addressLDP prev;
} ElmtLDP;
typedef struct
{
	addressLDP First;
	addressLDP Last;
} ListDP;

/* Definisi list : */
/* ListDP kosong : First(L) = NilLDP dan Last(L) = NilLDP */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses */
#define El(P) (P)->El
#define Info(P) (P)->El.info
#define X(P) (P)->El.x
#define Y(P) (P)->El.y
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)

/* PROTOTYPE */
boolean LengthLDP(ListDP L);
/****************** TEST ListDP KOSONG ******************/
boolean IsEmptyLDP(ListDP L);
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN ListDP KOSONG ******************/
void CreateLDP(ListDP *L);
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
addressLDP AlokasiLDP(char info, int x, int y);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=NilLDP, Prev(P)=NilLDP */
/* Jika alokasi gagal, mengirimkan NilLDP. */
void DealokasiLDP(addressLDP P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN ListDP ******************/
addressLDP SearchLDP(ListDP L, int x, int y);
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan NilLDP */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirstLDP(ListDP *L, char info, int x, int y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLastLDP(ListDP *L, char info, int x, int y);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirstLDP(ListDP *L, ElTypeLDP *X);
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLastLDP(ListDP *L, ElTypeLDP *X);
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstLDP(ListDP *L, addressLDP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLastLDP(ListDP *L, addressLDP P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfterLDP(ListDP *L, addressLDP P, addressLDP Prec);
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBeforeLDP(ListDP *L, addressLDP P, addressLDP Succ);
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirstLDP(ListDP *L, addressLDP *P);
/* I.S. ListDP tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLastLDP(ListDP *L, addressLDP *P);
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelPLDP(ListDP *L, char X, int x, int y);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* ListDP mungkin menjadi kosong karena penghapusan */
void DelAfterLDP(ListDP *L, addressLDP *Pdel, addressLDP Prec);
/* I.S. ListDP tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBeforeLDP(ListDP *L, addressLDP *Pdel, addressLDP Succ);
/* I.S. ListDP tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListDP ******************/
void PrintForwardLDP(ListDP L);
/* I.S. ListDP mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
// void PrintBackwardLDP(ListDP L);
/* I.S. ListDP mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

#endif