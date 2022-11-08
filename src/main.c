#include "main.h"

#define MAX_LENGTH 100

int main()
{
    TabStr T;
    Queue Q, Qds;
    CreateArray(&T);
    CreateQueue(&Q), CreateQueue(&Qds);
    mainmenu();

    while (true)
    {
        printf("ENTER COMMAND: ");

        isFile = false;
        STARTWORD("", "");

        if (isEqual(currentWord, "START"))
        {
            BNMO_START(&T);
        }
        else if (isEqual(currentWord, "LOAD"))
        {
            ADVWORD();
            load(currentWord.TabWord, &T);
        }
        else if (isEqual(currentWord, "SAVE"))
        {
            ADVWORD();
            save(currentWord.TabWord, T);
        }
        else if (isEqual(currentWord, "CREATEGAME"))
        {
            createGame(currentWord.TabWord, &T);
        }
        else if (isEqual(currentWord, "LISTGAME"))
        {
            listgame(T);
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
        else if (isEqual(currentWord, "SKIPGAME"))
        {
            skipgame(currentWord, &T, &Q);
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
            commandlain();

        // Reset currentWord
        currentWord.TabWord[0] = '\0';
        currentWord.Length = 0;
    }
    return 0;
}