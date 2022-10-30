#include <stdio.h>
#include "boolean.h"

#define MAX_LENGTH 100

boolean isEqual(char *str1, char *str2)
{
    int i = 0;
    boolean isDiffer = false;
    while (str1[i] != '\0' && str2[i] != '\0' && !isDiffer)
    {
        printf("%c %c\n", str1[i], str2[i]);
        if (str1[i] != str2[i])
            isDiffer = true;
        i++;
    }
    return !isDiffer;
}

int main()
{
    char inp[MAX_LENGTH];
    printf("ENTER COMMAND: ");
    scanf("%s", inp);
    if (isEqual(inp, "START"))
    {
        // START()
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    }
    else if (isEqual(inp, "LOAD"))
    {
    }
    else if (isEqual(inp, "SAVE"))
    {
    }
    else if (isEqual(inp, "CREATEGAME"))
    {
        char gameName[MAX_LENGTH];
        printf("Masukkan nama game yang akan ditambahkan: ");
        scanf("%s\n", gameName);
        // Perlu checker??
        if (isEqual(gameName, "RNG") || isEqual(gameName, "Diner Dash"))
            printf("Game sudah ada");
        else
            printf("Game berhasil ditambahkan");
    }
    else if (isEqual(inp, "LISTGAME"))
    {
    }
    else if (isEqual(inp, "DELETEGAME"))
    {
    }
    else if (isEqual(inp, "QUEUEGAME"))
    {
    }
    else if (isEqual(inp, "PLAYGAME"))
    {
    }
    else if (isEqual(inp, "QUIT"))
    {
    }
    else if (isEqual(inp, "HELP"))
    {
    }
    // Command lain
    else
    {
    }
    return 0;
}