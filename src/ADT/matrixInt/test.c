#include "matrixInt.h"

int main()
{
    Matrix2D M;
    CreateMxI(&M, 3);
    PrintMxI(M, 0, '.', false);
    printf("%d\n", IsFullMxI(M));
    return 0;
}