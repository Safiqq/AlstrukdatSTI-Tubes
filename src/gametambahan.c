#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gametambahan()
{
	int n;
	char pilih, bot;
	srand(time(NULL));
	n = rand() % 3;
	if (n == 0)
		bot = 'k';
	else if (n ==1)
		bot = 'b';
	else
		bot = 'g';
	printf("Pilih b(batu), k(kertas), atau g(gunting)\n");
	scanf("%c", &pilih);

    int condition;
    if (pilih == bot){
        condition= 1;
    }

    if (pilih == 'b' && bot == 'g'){
		condition= 2;
    }
	else if (pilih == 'g' && bot == 'b'){
		condition= 3;
    }

	if (pilih == 'b' && bot =='k'){
		condition= 3;
    }
	else if (pilih =='k' && bot == 'b'){
         condition= 2;
    }

	if (pilih =='k' && bot == 'g'){
		condition= 3;
    }
	else if (pilih == 'g' && bot =='k'){
		condition= 2;
    }

    printf("Kamu pilih : %c\n",pilih);
    printf("Komputer pilih : %c\n",bot);

	if (condition == 1) {
		printf("Imbang!\n");
	}
	else if (condition == 2) {
		printf("Yay, kamu menang!\n");
	}
	else {
		printf("Hiks, kamu kalah!\n");
	}
}
