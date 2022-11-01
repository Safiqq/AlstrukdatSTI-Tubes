#include <stdio.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "boolean.h"

#define MAX_LENGTH 100

boolean isEqual(Word str1, char *str2)
{
    int i = 0;
    boolean isDiffer = false;
    while (str1.TabWord[i] != '\0' && str2[i] != '\0' && !isDiffer)
    {
        if (str1.TabWord[i] != str2[i])
            isDiffer = true;
        i++;
    }
    return !isDiffer;
}

int main()
{
    printf("ENTER COMMAND: ");
    STARTWORD(false);
    if (isEqual(currentWord, "START"))
    {
        // START()
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    }
    else if (isEqual(currentWord, "LOAD"))
    {
    }
    else if (isEqual(currentWord, "SAVE"))
    {
    }
    else if (isEqual(currentWord, "CREATEGAME"))
    {
        printf("Masukkan nama game yang akan ditambahkan: ");
        ADVWORD();
        // Perlu checker??
        if (isEqual(currentWord, "RNG") || isEqual(currentWord, "Diner Dash"))
            printf("Game sudah ada");
        else
            printf("Game berhasil ditambahkan");
    }
    else if (isEqual(currentWord, "LISTGAME"))
    {
    }
    else if (isEqual(currentWord, "DELETEGAME"))
    {
    }
    else if (isEqual(currentWord, "QUEUEGAME"))
    {
    }
    else if (isEqual(currentWord, "PLAYGAME"))
    {
    }
    else if (isEqual(currentWord, "QUIT"))
    {
    }
    else if (isEqual(currentWord, "HELP"))
    {
    }
    // Command lain
    else
    {
        printf("Command tidak dikenali, silahkan masukkan command yang valid.");
    }
    return 0;
}
