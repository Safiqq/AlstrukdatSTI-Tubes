#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Sementara aman, tar cek lg
int RNG()
{
    srand(time(NULL));
    int i = rand();
    srand(i);
    int j = rand();
    srand(j);
    int k = rand();
    srand(k);
    return ((i + j - rand() * k) % 100 + 111) % 100;
}