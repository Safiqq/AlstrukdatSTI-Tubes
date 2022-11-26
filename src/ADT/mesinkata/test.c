#include "mesinkata.h"

int main()
{
    STARTWORD("", "");
    printf("%d\n", stringLength(currentWord.TabWord));
    printf("%d\n", isEqual(currentWord, "TES"));
    printf("%s\n", currentWord.TabWord);
    ConcatWords(&currentWord, ' ', currentWord);
    printf("%s\n", currentWord.TabWord);
    return 0;
}