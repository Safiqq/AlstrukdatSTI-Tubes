#include <stdio.h>
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
#include "boolean.h"

#define MAX_LENGTH 100

int main()
{
    printf("ENTER COMMAND: ");

    isFile = false;
    STARTWORD();
    if (isEqual(currentWord, "START"))
    {
        Queue Q;
        BNMO_START(&Q);
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
        printf("Command tidak dikenali, silakan masukkan command yang valid.");
    return 0;
}