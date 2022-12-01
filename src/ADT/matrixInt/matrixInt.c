#include "matrixInt.h"

void CreateMxI(Matrix2D *M, int cap)
{
    int i, j;
    M->MI = (ElTypeMxI **)malloc(sizeof(int) * cap * cap);
    for (i = 0; i < cap; i++)
    {
        M->MI[i] = (ElTypeMxI *)malloc(sizeof(int) * cap);
        for (j = 0; j < cap; j++)
        {
            M->MI[i][j] = 0;
        }
    }
    M->capacity = cap;
}

boolean IsFullMxI(Matrix2D M)
{
    int i = 0, j;
    boolean IsFullSI = true;
    while (i < M.capacity && IsFullSI)
    {
        j = 0;
        while (j < M.capacity && IsFullSI)
        {
            if (M.MI[i][j] == 0)
                IsFullSI = false;
            j++;
        }
        i++;
    }
    return IsFullSI;
}

void PrintMxI(Matrix2D M, int sub, char zero, boolean useTab)
{
    int i, j, k;
    printf("Berikut merupakan peta permainan:\n");
    printf(" ");
    for (k = 0; k < (M.capacity + useTab) * (useTab ? 7 : 2) + (useTab ? M.capacity - 1 : 0) + sub + 1 + (sub > 0); k++)
    {
        printf("-");
    }
    printf("\n");
    for (i = 0; i < M.capacity; i++)
    {
        for (j = 0; j < M.capacity; j++)
        {
            if (sub == 0 && j == 0)
                useTab ? printf("|\t") : printf("| ");
            else if (sub > 0)
                if (j % sub == 0)
                    useTab ? printf("|\t") : printf("| ");
            if (M.MI[i][j] == 0)
                printf("%c", zero);
            else if (M.MI[i][j] == 'H' || M.MI[i][j] == 'M' || M.MI[i][j] == 'o' || M.MI[i][j] == '#' || M.MI[i][j] == 'X' || M.MI[i][j] == 'O')
                printf("%c", M.MI[i][j]);
            else
                printf("%d", M.MI[i][j]);
            if (j != M.capacity - 1)
                useTab ? printf("\t") : printf(" ");
            else
                useTab ? printf("\t|") : printf(" |");
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
    for (k = 0; k < (M.capacity + useTab) * (useTab ? 7 : 2) + (useTab ? M.capacity - 1 : 0) + sub + 1 + (sub > 0); k++)
    {
        printf("-");
    }
    printf("\n");
}