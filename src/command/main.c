#include "../header/main.h"

int isLogged = false;

int main()
{
    ArrayStr games;
    Queue antriangames;
    StackStr riwayat;
    ArrayMap arraySB;

    CreateAS(&games);
    CreateQI(&antriangames);
    CreateSS(&riwayat);
    CreateAM(&arraySB);
    mainMenu();
    while (true)
    {
        printf("ENTER COMMAND: ");
        STARTWORD("", "");

        if (IsEqual(currentWord, "START"))
        {
            start(&games);
            isLogged = true;
        }
        else if (IsEqual(currentWord, "LOAD"))
        {
            ADVWORD();
            load(currentWord.TabWord, &games, &riwayat, &arraySB);
            isLogged = true;
        }
        else if (IsEqual(currentWord, "SAVE"))
        {
            ADVWORD();
            if (isLogged)
                save(currentWord.TabWord, games, riwayat, arraySB);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (IsEqual(currentWord, "CREATE"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    createGame(currentWord.TabWord, &games, &arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "LIST"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    listGame(games);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "DELETE"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    deleteGame(&games, &antriangames, &riwayat, &arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "QUEUE"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    queueGame(&games, &antriangames);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "PLAY"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    playGame(&games, &antriangames, &riwayat, &arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "SKIP"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "GAME"))
            {
                if (isLogged)
                    skipGame(currentWord, &games, &antriangames, &riwayat, &arraySB);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "HISTORY"))
        {
            if (isLogged)
                history(&riwayat);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (IsEqual(currentWord, "RESET"))
        {
            ADVWORD();
            if (IsEqual(currentWord, "HISTORY"))
            {
                if (isLogged)
                    resetHistory(&riwayat);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else if (IsEqual(currentWord, "SCOREBOARD"))
            {
                if (isLogged)
                    resetScoreboard(&arraySB, games);
                else
                    printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
            }
            else
                commandLain();
        }
        else if (IsEqual(currentWord, "SCOREBOARD"))
        {
            if (isLogged)
                scoreboard(arraySB, games);
            else
                printf("Kamu perlu menjalankan START/LOAD terlebih dahulu.\n");
        }
        else if (IsEqual(currentWord, "QUIT"))
            quit();
        else if (IsEqual(currentWord, "HELP"))
            help(isLogged);
        else
            commandLain();
        ClearCurrentWord();
    }
    return 0;
}