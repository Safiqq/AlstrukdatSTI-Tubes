#include "matriks.h"

int template1[9][9] = {
    {5, 8, 7, 2, 1, 0, 0, 9, 4},
    {0, 1, 4, 6, 9, 5, 0, 8, 3},
    {0, 0, 0, 0, 0, 7, 0, 5, 2},
    {1, 7, 0, 0, 6, 4, 0, 0, 0},
    {0, 0, 3, 0, 0, 0, 5, 0, 0},
    {0, 0, 0, 1, 3, 0, 0, 4, 0},
    {0, 2, 1, 0, 0, 0, 9, 7, 0},
    {0, 0, 0, 0, 0, 6, 0, 1, 0},
    {3, 5, 0, 9, 0, 0, 4, 0, 0}
};

int template2[9][9] = {
    {0, 3, 0, 7, 0, 4, 8, 0, 5},
    {0, 7, 0, 5, 0, 9, 0, 4, 0},
    {2, 0, 0, 0, 0, 6, 0, 0, 1},
    {8, 1, 0, 6, 5, 0, 0, 7, 4},
    {7, 6, 0, 0, 4, 0, 1, 0, 0},
    {0, 5, 0, 0, 7, 8, 0, 0, 0},
    {4, 0, 0, 2, 0, 1, 5, 8, 0},
    {0, 0, 6, 0, 0, 5, 0, 0, 0},
    {5, 0, 3, 0, 6, 7, 0, 1, 2}
};

int template3[9][9] = {
    {0, 5, 8, 0, 3, 0, 0, 2, 0},
    {4, 0, 2, 0, 0, 0, 9, 0, 5},
    {0, 0, 7, 0, 0, 0, 6, 8, 0},
    {2, 9, 0, 0, 5, 4, 0, 7, 0},
    {5, 0, 0, 0, 6, 2, 0, 0, 0},
    {0, 0, 3, 8, 1, 0, 2, 5, 0},
    {1, 0, 9, 0, 0, 3, 0, 6, 4},
    {8, 6, 5, 4, 9, 0, 1, 3, 0},
    {0, 7, 0, 0, 0, 6, 0, 0, 0}
};

void CreateMtx(Matrix2D *M)
{
    srand(time(NULL));
    int no = rand(), i, j;
    for (i = 0; i < CAPACITY; i++)
    {
        for (j = 0; j < CAPACITY; j++)
        {
            M->TI[i][j] = no % 3 == 0 ? template1[i][j] :
                          no % 3 == 1 ? template2[i][j] : template3[i][j];
        }
    }
}

boolean IsFullMtx(Matrix2D M)
{
    int i = 0, j = 0;
    boolean isFull = true;
    while (i < CAPACITY && isFull)
    {
        while (j < CAPACITY && isFull)
        {
            if (M.TI[i][j] == 0)
                isFull = false;
            j++;
        }
        i++;
    }
    return isFull;
}

void PrintMtx(Matrix2D M)
{
    int i, j;
    printf(" -----------------------\n");
    for (i = 0; i < CAPACITY; i++)
    {
        for (j = 0; j < CAPACITY; j++)
        {
            if (j == 0 || j == 3 || j == 6)
                printf("| ");
            if (M.TI[i][j] == 0)
                printf(".");
            else
                printf("%d", M.TI[i][j]);
            if (j != CAPACITY - 1)
                printf(" ");
            else
                printf(" |");
        }
        if (i == 2 || i == 5)
            printf("\n-------------------------\n");
        else
            printf("\n");
    }
    printf(" -----------------------\n");
}