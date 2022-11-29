#include "matriksChar.h"

void CreateMC(Matrix2D *M, int cap)
{
    int i, j;
    M->MI = (ElTypeMatrix **)malloc(sizeof(int) * cap * cap);
    for (i = 0; i < cap; i++)
    {
        M->MI[i] = (ElTypeMatrix *)malloc(sizeof(int) * cap);
        for (j = 0; j < cap; j++)
        {
            M->MI[i][j] = '0';
        }
    }
    M->capacity = cap;
}

boolean IsFullMC(Matrix2D M)
{
    int i = 0, j;
    boolean IsFullSI = true;
    while (i < M.capacity && IsFullSI)
    {
        j = 0;
        while (j < M.capacity && IsFullSI)
        {
            if (M.MI[i][j] == '0')
                IsFullSI = false;
            j++;
        }
        i++;
    }
    return IsFullSI;
}

void PrintMC(Matrix2D M, int sub, char zero)
{
    int i, j, k;
    printf(" ");
    for (k = 0; k < M.capacity * 2 + sub + 1 + (sub > 0); k++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < M.capacity; i++)
    {
        for (j = 0; j < M.capacity; j++)
        {
            if (sub == 0 && j == 0)
                printf("| ");
            else if (sub > 0)
                if (j % sub == 0)
                    printf("| ");
            printf("%c", M.MI[i][j] == '0' ? zero : M.MI[i][j]);
            if (j != M.capacity - 1)
                printf(" ");
            else
                printf(" |");
        }
        if (sub > 0)
            if (i % sub == sub - 1 && i != M.capacity - 1)
            {
                printf("\n");
                for (k = 0; k < M.capacity * 2 + sub * 2 + 1; k++)
                {
                    printf("-");
                }
            }
        printf("\n");
    }
    printf(" ");
    for (k = 0; k < M.capacity * 2 + sub + 1 + (sub > 0); k++)
    {
        printf("-");
    }
    printf("\n");
}