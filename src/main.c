#include "./ADT/array/array.h"
#include "./ADT/mesinkata/mesinkata.h"
#include "./ADT/queue/queue.h"
#include "./ADT/stackH/stack.h"
#include "./ADT/mapscoreboard/mapsb.h"
#include "./ADT/arrayOfMap/arraymap.h"

#define MAX_LENGTH 100

int isLogged = false;

int main()
{
    TabStr games;
    Queue antriangames;
    Stack riwayat;
    TabMap arraySB;

    CreateArray(&games);
    CreateQueue(&antriangames);
    CreateEmptyStack(&riwayat);
    CreateEmptyArrMap(&arraySB);
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
            load(currentWord.TabWord, &games, &riwayat,&arraySB);
            isLogged = true;
        }
        else if (isEqual(currentWord, "SAVE"))
        {
            ADVWORD();
            if (isLogged)
                save(currentWord.TabWord,games,riwayat, arraySB);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "CREATE"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    createGame(currentWord.TabWord, &games,&arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "LIST"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    listGame(games);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "DELETE"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    deleteGame(&games, &antriangames, &riwayat, &arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "QUEUE"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    queueGame(&games, &antriangames);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "PLAY"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    playGame(&games, &antriangames, &riwayat,&arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "SKIP"))
        {
            ADVWORD();
            if (isEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    skipGame(currentWord, &games, &antriangames, &riwayat);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "HISTORY"))
        {
            if (isLogged)
                history(&riwayat, games);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (isEqual(currentWord, "RESET"))
        {
            ADVWORD();
            if (isEqual(currentWord, "HISTORY"))
            {
                if (isLogged)
                    resethistory(&riwayat, games);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else if (isEqual(currentWord, "SCOREBOARD"))
            {
                if (isLogged)
                    resetScoreboard(&arraySB,games);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (isEqual(currentWord, "SCOREBOARD"))
        {
            if (isLogged)
                scoreboard(arraySB,games);
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