#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gametambahan(){
    int poin;
	srand(time(NULL));
	poin = rand() % 100;
    printf("GAME OVER\n");
    printf("Anda mendapatkan %d poin\n",poin);
}
