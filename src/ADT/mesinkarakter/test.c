#include "mesinkarakter.h"

int main()
{
    START("", "");
    printf("%c %d\n", GetCC(), IsEOP());
    ADV();
    printf("%c %d\n", GetCC(), IsEOP());
    return 0;
}