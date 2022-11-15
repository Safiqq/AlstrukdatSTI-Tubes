#include "matriks.h"

int main()
{
    Matrix2D M;
    CreateMtx(&M);
    PrintMtx(M);
    printf("%d\n", IsFullMtx(M));
    return 0;
}