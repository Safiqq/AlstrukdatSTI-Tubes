#include <stdio.h>
#include "arraymap.h"
#include <stdlib.h>

void InsertLast(TabMap *T)
{
    MapSB M;
    CreateMapSB(&M);
    (*T).TIMap[NbElmtArrMap(*T)] = M;
    (*T).NeffArrMap++;
}

void CreateEmptyArrMap(TabMap *T)
{
    InsertLast(T);
    InsertLast(T);
    InsertLast(T);
    InsertLast(T);
    InsertLast(T);
    InsertLast(T);
    InsertLast(T);
    (*T).NeffArrMap = 7;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxArrayMap-IdxMinArrayMap+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrMap(TabMap T)
{
    return (T.NeffArrMap);
}

void DeleteAt(TabMap *T, IdxTypeArrayMap i)
{
    int j;
    for (j = i; j < NbElmtArrMap(*T); j++)
    {
        (*T).TIMap[j] = (*T).TIMap[j + 1];
    }
    (*T).NeffArrMap--;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

