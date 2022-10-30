#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100

FILE *file;

void START()
{
    file = fopen("../data/config.txt", "r");
    if (file == NULL)
        printf("File config.txt tidak bisa dibuka.\n");
    else
    {
        int gameCount, historyCount;
        char buf[MAX_LENGTH];
        fgets(buf, MAX_LENGTH, file);
        gameCount = atoi(buf);
        // looping sebanyak gameCount, pake queue
        fgets(buf, MAX_LENGTH, file);
        historyCount = atoi(buf);
        // looping sebanyak historyCount, pake queue
        printf("%d", gameCount);
    }
}