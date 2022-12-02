#include "arrayMap.h"

void InsertLastAM(ArrayMap *T)
{
    MapStr M;
    CreateMS(&M);
    (*T).TIMap[NbElmtAM(*T)] = M;
    (*T).NeffArrMap++;
}

void CreateAM(ArrayMap *T)
{
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    InsertLastAM(T);
    (*T).NeffArrMap = 8;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMaxAM-IdxMinAM+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtAM(ArrayMap T)
{
    return (T.NeffArrMap);
}

void DeleteAtAM(ArrayMap *T, IdxTypeAM i)
{
    int j;
    for (j = i; j < NbElmtAM(*T); j++)
    {
        (*T).TIMap[j] = (*T).TIMap[j + 1];
    }
    (*T).NeffArrMap--;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */
