#include "listlinier.h"

boolean IsEmptyList(List L)
{
    return First(L) == Nil && Last(L) == Nil;
}

void CreateEmptyList(List *L)
{
    First(*L) = Nil;
    Last(*L) = Nil;
}

address AlokasiList(char info, int x, int y)
{
    ElmtList *P = (ElmtList *)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        // printf("1 %d %d %c\n", X(P), Y(P), Info(P));
        Info(P) = info;
        X(P) = x;
        Y(P) = y;
        // printf("2 %d %d %c\n", X(P), Y(P), Info(P));
        Prev(P) = Nil;
        Next(P) = Nil;
    }
    return P;
}

void DealokasiList(address P)
{
    free(P);
}

address SearchList(List L, int x, int y)
{
    boolean isFound = false;
    if (!IsEmptyList(L))
    {
        address P = First(L);
        if (x < 0)
            x = 4;
        else if (y < 0)
            y = 4;
        else if (x > 4)
            x = 0;
        else if (y > 4)
            y = 0;
        while (!isFound && Next(P) != Nil)
        {
            if (X(P) == x && Y(P) == y)
                isFound = true;
            else
                P = Next(P);
        }
        return isFound ? P : Nil;
    }
    return Nil;
}

void InsVFirstList(List *L, char info, int x, int y)
{
    address P = AlokasiList(info, x, y);
    if (P != Nil)
        InsertFirstList(L, P);
}

void InsVLastList(List *L, char info, int x, int y)
{
    address P = AlokasiList(info, x, y);
    if (P != Nil)
        InsertLastList(L, P);
}

void DelVFirstList(List *L, ElTypeList *X)
{
    address P;
    DelFirstList(L, &P);
    *X = El(P);
    DealokasiList(P);
}

void DelVLastList(List *L, ElTypeList *X)
{
    address P;
    DelLastList(L, &P);
    *X = El(P);
    DealokasiList(P);
}

void InsertFirstList(List *L, address P)
{
    if (IsEmptyList(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
        InsertBeforeList(L, P, First(*L));
}

void InsertLastList(List *L, address P)
{
    if (IsEmptyList(*L))
        InsertFirstList(L, P);
    else
        InsertAfterList(L, P, Last(*L));
}

void InsertAfterList(List *L, address P, address Prec)
{
    Prev(P) = Prec;
    Next(P) = Next(Prec);
    Next(Prec) = P;
    if (Next(P) == Nil)
        Last(*L) = P;
    else
        Prev(Next(P)) = P;
}

void InsertBeforeList(List *L, address P, address Succ)
{
    Prev(P) = Prev(Succ);
    Next(P) = Succ;
    Prev(Succ) = P;
    if (Prev(P) == Nil)
        First(*L) = P;
    else
        Next(Prev(P)) = P;
}

void DelFirstList(List *L, address *P)
{
    *P = First(*L);
    if (First(*L) == Last(*L))
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
    }
}

void DelLastList(List *L, address *P)
{
    *P = Last(*L);
    if (First(*L) == Last(*L))
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
    }
}

// void DelPList(List *L, char info, int x, int y)
// {
//     address P = SearchList(*L, info);
//     if (P != Nil)
//     {
//         if (P == First(*L))
//             DelFirstList(L, &P);
//         else
//             DelAfterList(L, &P, Prev(P));
//     }
// }

// void DelAfterList(List *L, address *Pdel, address Prec)
// {
//     *Pdel = Next(Prec);
//     if (Next(*Pdel) == Nil)
//     {
//         Next(Prec) = Nil;
//         Last(*L) = Prec;
//     }
//     else
//     {
//         Next(Prec) = Next(*Pdel);
//         Prev(Next(*Pdel)) = Prec;
//     }
// }

// void DelBeforeList(List *L, address *Pdel, address Succ)
// {
//     *Pdel = Prev(Succ);
//     if (Prev(*Pdel) == Nil)
//     {
//         Prev(Succ) = Nil;
//         First(*L) = Succ;
//     }
//     else
//     {
//         Prev(Succ) = Prev(*Pdel);
//         Next(Prev(*Pdel)) = Succ;
//     }
// }

void PrintForwardList(List L)
{
    address P = First(L);
    if (IsEmptyList(L))
        printf("[]");
    else
    {
        printf("[");
        while (P != Nil)
        {
            printf("%c", Info(P));
            if (P != Last(L))
                printf(",");
            P = Next(P);
        }
        printf("]");
    }
}

// void PrintBackwardList(List L)
// {
//     address P = Last(L);
//     if (IsEmptyList(L))
//         printf("[]");
//     else
//     {
//         printf("[");
//         while (P != Nil)
//         {
//             printf("%d", Info(P));
//             if (P != First(L))
//                 printf(",");
//             P = Prev(P);
//         }
//         printf("]");
//     }
// }