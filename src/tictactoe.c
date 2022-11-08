#include <stdio.h>
#include "./ADT/arrayTTT/array.h"
#include <stdlib.h>

boolean winCondition(Tab T, char p)
{
    boolean flag = false;
    for(int i = 0; i <=6; i = i+3)
    {
        if(T.TI[i] == p && T.TI[i+1] == p && T.TI[i+2] == p)
        {
            flag = true;
        }
    }
    for(int j = 0; j <=2; j++)
    {
        if(T.TI[j] == p && T.TI[j+3] == p && T.TI[j+6] == p)
        {
            flag = true;
        }
    }
    if((T.TI[0] == p && T.TI[4] == p && T.TI[8] == p) || T.TI[2] == p && T.TI[4] == p && T.TI[6] == p)
    {
        flag = true;
    }
    return flag;
}

void displayTable(Tab T)
{
    printf("Table saat ini: \n\n");
    for(int i = 0; i <=6; i = i+3)
    {
        printf(" %c | %c | %c\n", T.TI[i], T.TI[i+1], T.TI[i+2]);
        printf("------------\n");
    }
}

int randomNumber(int min, int max)
{
    return ((rand()%max) + min);
}

void botTurn(Tab *T, char bot)
{
    boolean flag = false;
    while(!flag)
    {
        int i = randomNumber(0,8);
        if((*T).TI[i] == ' ')
        {
            (*T).TI[i] = bot;
            flag = true;
        }
    }
    printf("Bot sudah mengisi kotak\n");
}

void playerTurn(Tab *T, char player)
{
    boolean flag = false;
    while(!flag)
    {
        int index;
        printf("Silahkan input index kotak (0-8) yang akan diisi : ");
        scanf("%d", &index);
        if(index > 8)
        {
            printf("Index di luar jangkauan, Silahkan masukkan index yang benar!\n");
        }
        else
        {
            if((*T).TI[index] == ' ')
            {
                (*T).TI[index] = player;
                flag = true;
            }
            else
            {
                printf("Kotak sudah terisi, Silahkan mengisi index kotak yang lain!\n");
            }
        }
    }
}

char botChar(char player)
{
    boolean flag = false;
    char bot;
    while(!flag)
    {
        int ibot = randomNumber(0,2);  //0 = Gunting, 1 = Batu, 2 = Kertas
        if(ibot == 0)
        {
            bot = 'G';
        }
        else if(bot == 1)
        {
            bot = 'B';
        }
        else
        {
            bot = 'K';
        }

        if(bot != player)
        {
            flag = true;
        }
    }
    return bot;
}

boolean suit(char player, char bot)
{
    // Condition
    if( (bot == 'G' && player == 'B') || (bot == 'K' && player == 'G') || (bot == 'B' && player == 'K'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void tictactoe()
{
    // Membuat table kosong
    Tab Table;
    CreateArray(&Table);
    for(int i = 0; i <9; i++)
    {
       SetArray(&Table, i, ' ');
    }

    // Deklarasi variabel
    char p;
    char playerType, botType;

    printf("---Selamat datang di TicTacToe---\n\n");
    printf("Silahkan input (B/G/K) untuk menentukan giliran pertama : ");

    // Input Pengguna dan check apakah player menang atau kalah suit dengan bot
    scanf("%c", &p);
    char bot = botChar(p);
    if(suit(p, bot))
    {
        printf("Bot memilih %c sehingga Anda menang dan mendapatkan giliran pertama\n\n", bot);
        botType = 'O';
        playerType = 'X';
    }
    else
    {
        printf("Bot memilih %c sehingga Anda kalah dan mendapatkan giliran kedua\n\n", bot);
        botType = 'X';
        playerType = 'O';
    }

    displayTable(Table);
    int count = 0;

    // Selama belum menang atau kalah atau seri maka permainan akan terus dijalankan
    while(!winCondition(Table, botType) && !winCondition(Table, playerType) && count <8)
    {
        // Kalau player menang suit dengan bot maka player jalan lebih dulu
        if(suit(p, bot))
        {
            playerTurn(&Table, playerType);
            count++;
            displayTable(Table);
            botTurn(&Table,botType);
            count++;
            displayTable(Table);
        }
        // Kalau player kalah suit dengan bot maka bot jalan lebih dulu
        else
        {
            botTurn(&Table, botType);
            count++;
            displayTable(Table);
            playerTurn(&Table, playerType);
            count++;
            displayTable(Table);
        }
    }

    // Check siapakah pemenangnya atau bisa seri
    if(winCondition(Table,playerType))
    {
        printf("Selamat Anda menang!\n");
    }
    else if(winCondition(Table, botType))
    {
        printf("Selamat Anda kalah :V\n");
    }
    else
    {
        printf("Masa Seri sama bot :V");
    }
}