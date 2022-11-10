#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"

#define MAX_LENGTH 100

int isLogged = false;

int main()
{
    TabStr games;
    Queue antriangames;
    CreateArray(&games);
    CreateQueue(&antriangames);
    mainMenu();

    while (true)
    {
        printf("ENTER COMMAND: ");
        STARTWORD("", "");

        if (isEqual(currentWord, "START"))
        {
            start(&games);
            isLogged = true;
        }
        else if (isEqual(currentWord, "LOAD"))
        {
            ADVWORD();
            load(currentWord.TabWord, &games);
            isLogged = true;
        }
        else if (isEqual(currentWord, "SAVE"))
        {
            ADVWORD();
            if (isLogged)
                save(currentWord.TabWord, games);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "CREATEGAME"))
        {
            if (isLogged)
                createGame(currentWord.TabWord, &games);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "LISTGAME"))
        {
            if (isLogged)
                listGame(games);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "DELETEGAME"))
        {
            if (isLogged)
                deleteGame(&games, &antriangames);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "QUEUEGAME"))
        {
            if (isLogged)
                queueGame(&games, &antriangames);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "PLAYGAME"))
        {
            if (isLogged)
                playGame(&games, &antriangames);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "SKIPGAME"))
        {
            if (isLogged)
                skipGame(currentWord, &games, &antriangames);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "QUIT"))
            quit();
        else if (isEqual(currentWord, "HELP"))
            help(isLogged);
        else
            commandLain();

        // Reset currentWord
        currentWord.TabWord[0] = '\0';
        currentWord.Length = 0;
    }
    return 0;
}