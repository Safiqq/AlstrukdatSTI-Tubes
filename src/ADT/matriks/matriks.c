#include "matriks.h"

void CreateMtx(Matrix2D *M, int cap)
{
    int i, j;
    M->MI = (int **)malloc(sizeof(int) * cap);
    for (i = 0; i < cap; i++)
    {
        M->MI[i] = (int *)malloc(sizeof(int) * cap);
        for (j = 0; j < cap; j++)
        {
            M->MI[i][j] = 0;
        }
    }
    M->capacity = cap;
}

boolean IsFullMtx(Matrix2D M)
{
    int i = 0, j;
    boolean isFull = true;
    while (i < M.capacity && isFull)
    {
        j = 0;
        while (j <  M.capacity && isFull)
        {
            if (M.MI[i][j] == 0)
                isFull = false;
            j++;
        }
        i++;
    }
    return isFull;
}

void PrintMtx(Matrix2D M, int sub, char zero)
{
    int i, j, k;
    printf(" ");
    for (k = 0; k < M.capacity * 2 + sub + 2; k++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < M.capacity; i++)
    {
        for (j = 0; j < M.capacity; j++)
        {
            if (j % sub == 0)
                printf("| ");
            if (M.MI[i][j] == 0)
                printf("%c", zero);
            else
                printf("%d", M.MI[i][j]);
            if (j != M.capacity - 1)
                printf(" ");
            else
                printf(" |");
        }
        if (i % sub == sub - 1 && i != M.capacity - 1)
        {
            printf("\n");
            for (k = 0; k < M.capacity * 2 + sub * 2 + 1; k++)
            {
                printf("-");
            }
            printf("\n");
        } else
            printf("\n");
    }
    printf(" ");
    for (k = 0; k < M.capacity * 2 + sub + 2; k++)
    {
        printf("-");
    }
    printf("\n");
}