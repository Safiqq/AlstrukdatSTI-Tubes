#include <stdio.h>
#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
#include "boolean.h"

#define MAX_LENGTH 100

int main()
{
    TabStr T;
    Queue Q, Qds;
    MakeEmpty(&T);
    CreateQueue(&Q), CreateQueue(&Qds);

    printf("ENTER COMMAND: ");

    isFile = false;
    STARTWORD("", "");

    if (isEqual(currentWord, "START"))
    {
        BNMO_START(&T);
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.");
    }
    else if (isEqual(currentWord, "LOAD"))
    {
    }
    else if (isEqual(currentWord, "SAVE"))
    {
        ADVWORD();
        save(currentWord.TabWord, T);
    }
    else if (isEqual(currentWord, "CREATEGAME"))
    {
        printf("Masukkan nama game yang akan ditambahkan: ");
        ADVWORD();
        createGame(currentWord.TabWord, &T);
    }
    else if (isEqual(currentWord, "LISTGAME"))
    {
        listgame(Q);
    }
    else if (isEqual(currentWord, "DELETEGAME"))
    {
        deletegame(&T, Q);
    }
    else if (isEqual(currentWord, "QUEUEGAME"))
    {
        QueueGame(&T, &Q);
    }
    else if (isEqual(currentWord, "PLAYGAME"))
    {
        playgame(&T, &Q);
    }
    else if (isEqual(currentWord, "QUIT"))
    {
        quit();
    }
    else if (isEqual(currentWord, "HELP"))
    {
        help();
    }
    // Command lain
    else
        printf("Command tidak dikenali, silakan masukkan command yang valid.");
    return 0;
}