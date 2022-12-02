#include "listDP.h"

int main()
{
    ListDP L;
    CreateLDP(&L);
    printf("%d %d\n", LengthLDP(L), IsEmptyLDP(L));
    // 0 1, panjang LDP 0 karena LDP kosong
    addressLDP P1 = AlokasiLDP(0, 0, 0);
    InsVFirstLDP(&L, 1, 1, 1);
    InsVLastLDP(&L, 2, 2, 2);
    printf("%d\n", SearchLDP(L, 1, 1));
    // address not NULL, karena ada node dengan x dan y = 1 pada LDP
    ElTypeLDP X;
    DelVFirstLDP(&L, &X);
    DelVLastLDP(&L, &X);
    InsertFirstLDP(&L, P1);
    addressLDP P2 = AlokasiLDP(3, 3, 3);
    InsertLastLDP(&L, P2);
    addressLDP P3 = AlokasiLDP(4, 4, 4);
    InsertAfterLDP(&L, P3, P2);
    addressLDP P4 = AlokasiLDP(5, 5, 5);
    InsertBeforeLDP(&L, P4, P2);
    addressLDP P5;
    DelAfterLDP(&L, &P5, P2);
    DelBeforeLDP(&L, &P5, P2);
    DelFirstLDP(&L, &P5);
    DelLastLDP(&L, &P5);
    InsVFirstLDP(&L, 6, 6, 6);
    DelPLDP(&L, 6, 6, 6);
    DealokasiLDP(P1);
    DealokasiLDP(P2);
    DealokasiLDP(P3);
    DealokasiLDP(P4);
    return 0;
}