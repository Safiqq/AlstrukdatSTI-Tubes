#include "matrixInt.h"

int main()
{
    Matrix2D M;
    CreateMC(&M);
    PrintMC(M);
    printf("%d\n", IsFullMC(M));
    return 0;
}