#include "listdp.h"

boolean LengthLDP(ListDP L)
{
    addressLDP P = First(L);
    int count = 0;
    while (P != NilLDP)
    {
        count++;
        P = Next(P);
    }
    return count;
}

boolean IsEmptyLDP(ListDP L)
{
    return First(L) == NilLDP && Last(L) == NilLDP;
}

void CreateLDP(ListDP *L)
{
    First(*L) = NilLDP;
    Last(*L) = NilLDP;
}

addressLDP AlokasiLDP(int info, int x, int y)
{
    ElmtLDP *P = (ElmtLDP *)malloc(sizeof(ElmtLDP));
    if (P != NilLDP)
    {
        Info(P) = info;
        X(P) = x;
        Y(P) = y;
        Prev(P) = NilLDP;
        Next(P) = NilLDP;
    }
    return P;
}

void DealokasiLDP(addressLDP P)
{
    free(P);
}

addressLDP SearchLDP(ListDP L, int x, int y)
{
    boolean isFound = false;
    if (!IsEmptyLDP(L))
    {
        addressLDP P = First(L);
        if (x < 0)
            x = 4;
        else if (y < 0)
            y = 4;
        else if (x > 4)
            x = 0;
        else if (y > 4)
            y = 0;
        while (!isFound && Next(P) != NilLDP)
        {
            if (X(P) == x && Y(P) == y)
                isFound = true;
            else
                P = Next(P);
        }
        return ((X(P) == x && Y(P) == y) || isFound) ? P : NilLDP;
    }
    return NilLDP;
}

void InsVFirstLDP(ListDP *L, int info, int x, int y)
{
    addressLDP P = AlokasiLDP(info, x, y);
    if (P != NilLDP)
        InsertFirstLDP(L, P);
}

void InsVLastLDP(ListDP *L, int info, int x, int y)
{
    addressLDP P = AlokasiLDP(info, x, y);
    if (P != NilLDP)
        InsertLastLDP(L, P);
}

void DelVFirstLDP(ListDP *L, ElTypeLDP *X)
{
    addressLDP P;
    DelFirstLDP(L, &P);
    *X = El(P);
    DealokasiLDP(P);
}

void DelVLastLDP(ListDP *L, ElTypeLDP *X)
{
    addressLDP P;
    DelLastLDP(L, &P);
    *X = El(P);
    DealokasiLDP(P);
}

void InsertFirstLDP(ListDP *L, addressLDP P)
{
    if (IsEmptyLDP(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
        InsertBeforeLDP(L, P, First(*L));
}

void InsertLastLDP(ListDP *L, addressLDP P)
{
    if (IsEmptyLDP(*L))
        InsertFirstLDP(L, P);
    else
        InsertAfterLDP(L, P, Last(*L));
}

void InsertAfterLDP(ListDP *L, addressLDP P, addressLDP Prec)
{
    Prev(P) = Prec;
    Next(P) = Next(Prec);
    Next(Prec) = P;
    if (Next(P) == NilLDP)
        Last(*L) = P;
    else
        Prev(Next(P)) = P;
}

void InsertBeforeLDP(ListDP *L, addressLDP P, addressLDP Succ)
{
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if (Prev(P) == NilLDP)
        First(*L) = P;
    else
        Next(Prev(P)) = P;
}

void DelFirstLDP(ListDP *L, addressLDP *P)
{
    *P = First(*L);
    if (First(*L) == Last(*L))
    {
        First(*L) = NilLDP;
        Last(*L) = NilLDP;
    }
    else
    {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = NilLDP;
    }
}

void DelLastLDP(ListDP *L, addressLDP *P)
{
    *P = Last(*L);
    if (First(*L) == Last(*L))
    {
        First(*L) = NilLDP;
        Last(*L) = NilLDP;
    }
    else
    {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = NilLDP;
    }
}

void DelPLDP(ListDP *L, int info, int x, int y)
{
    addressLDP P = SearchLDP(*L, x, y);
    if (P != NilLDP)
    {
        if (P == First(*L))
            DelFirstLDP(L, &P);
        else
            DelAfterLDP(L, &P, Prev(P));
    }
}

void DelAfterLDP(ListDP *L, addressLDP *Pdel, addressLDP Prec)
{
    *Pdel = Next(Prec);
    if (Next(*Pdel) == NilLDP)
    {
        Next(Prec) = NilLDP;
        Last(*L) = Prec;
    }
    else
    {
        Next(Prec) = Next(*Pdel);
        Prev(Next(*Pdel)) = Prec;
    }
}

void DelBeforeLDP(ListDP *L, addressLDP *Pdel, addressLDP Succ)
{
    *Pdel = Prev(Succ);
    if (Prev(*Pdel) == NilLDP)
    {
        Prev(Succ) = NilLDP;
        First(*L) = Succ;
    }
    else
    {
        Prev(Succ) = Prev(*Pdel);
        Next(Prev(*Pdel)) = Succ;
    }
}
