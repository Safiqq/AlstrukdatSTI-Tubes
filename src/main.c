#include "main.h"

#define MAX_LENGTH 100

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
        }
        else if (isEqual(currentWord, "LOAD"))
        {
            ADVWORD();
            load(currentWord.TabWord, &games);
        }
        else if (isEqual(currentWord, "SAVE"))
        {
            ADVWORD();
            save(currentWord.TabWord, games);
        }
        else if (isEqual(currentWord, "CREATEGAME"))
        {
            createGame(currentWord.TabWord, &games);
        }
        else if (isEqual(currentWord, "LISTGAME"))
        {
            listGame(games);
        }
        else if (isEqual(currentWord, "DELETEGAME"))
        {
            deleteGame(&games, antriangames);
        }
        else if (isEqual(currentWord, "QUEUEGAME"))
        {
            queueGame(&games, &antriangames);
        }
        else if (isEqual(currentWord, "PLAYGAME"))
        {
            playGame(&games, &antriangames);
        }
        else if (isEqual(currentWord, "SKIPGAME"))
        {
            skipGame(currentWord, &games, &antriangames);
        }
        else if (isEqual(currentWord, "QUIT"))
            quit();
        else if (isEqual(currentWord, "HELP"))
            help();
        else
            commandLain();

        // Reset currentWord
        currentWord.TabWord[0] = '\0';
        currentWord.Length = 0;
    }
    return 0;
}