#include <stdio.h>
#include "./ADT/arrayTTT/array.h"
#include <stdlib.h>

// FUNGSI / PROSEDUR PRIMITIF

// Untuk menghitung panjang string
int len(char *str)
{
    for (int len = 0;;++len) if (str[len]==0) return len;
}

// Untuk convert string to integer
int stringToInteger(char*str)
{
    int sum = 0;
    for(int i = 0; i < len(str); i++)
    {
        sum += str[i] - '0';
    }
    return sum;
}

// Untuk validasi apakah sudah memenuhi kondisi win atau belum
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

// Untuk menampilkan table saat ini
void displayTable(Tab T)
{
    printf("Table saat ini: \n\n");
    for(int i = 0; i <=6; i = i+3)
    {
        printf(" %c | %c | %c\n", T.TI[i], T.TI[i+1], T.TI[i+2]);
        printf("------------\n");
    }
}

// Untuk menghasilkan random number
int randomNumber(int min, int max)
{
    return ((rand()%max) + min);
}

// prosedur giliran Bot
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

// Validasi apakah string itu isinya digit semua atau bukan
boolean isDigit(char * string)
{
    boolean flag = false;
    int i = 0;
    while(!flag && i < len(string))
    {
        if(string[i] - '0' < 0 || string[i] - '0' > 9)
        {
            flag = true;
        }
        else
        {
            i++;
        }
    }
    return !flag;
}

// Prosedur giliran player
void playerTurn(Tab *T, char player)
{
    boolean flag = false;
    char idx[21];
    int index;
    while(!flag)
    {
        boolean flagcmd = false;
        while(!flagcmd)
        {
            printf("Silahkan masukkan index kotak (0-8) yang akan diisi : ");
            scanf("%s", &idx);
            if(isDigit(idx))
            {
                flagcmd = true;
                index = stringToInteger(idx);
            }
            else
            {
                printf("Kamu nanyeeaa kenapa gabisa? Biar aku kasih tau ya kamu inputnya string ya bukan integer! RAAAWWRRR\n");
            }
            printf("\n");

        }
        if(index > 8 || index <0)
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

// Menghasilkan tipe suit bot (batu/gunting/kertas)
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

// Check siapakah yang menang suit
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

// Check string 1 string 2 sama atau beda
boolean isSame(char *str1, char *str2, int len){
    int i = 0;
    while (i < len){
        if(str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return true;
}


// Program Utama
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

    // Input Pengguna dan check apakah player menang atau kalah suit dengan bot
    boolean flagp = false;
    while(!flagp)
    {
        printf("Silahkan input (Batu/Gunting/Kertas) untuk menentukan giliran pertama : ");
        char cmd[10];
        scanf("%s", &cmd);
        if(isSame(cmd, "BATU", 4) || isSame(cmd, "Batu", 4) || isSame(cmd, "batu", 4))
        {
            p = 'B';
            flagp = true;
        }
        else if (isSame(cmd, "Gunting", 4) || isSame(cmd, "GUNTING", 4) || isSame(cmd, "gunting", 4))
        {
            p = 'G';
            flagp = true;
        }
        else if (isSame(cmd, "KERTAS", 4) || isSame(cmd, "Kertas", 4) || isSame(cmd, "kertas", 4))
        {
            p = 'K';
            flagp = true;
        }
        else
        {
            printf("Input salah! Mohon ulangi dengan benar\n");
        }
        printf("\n");
    }

    // Deklarasi bot itu tipe suitnya apa
    char bot = botChar(p);
    
    // Check siapa yang menang suit dan menentukan giliran pertama
    if(suit(p, bot))
    {
        if(bot == 'G')
        {
            printf("Bot memilih Gunting sehingga Anda menang dan mendapatkan giliran pertama\n\n");
        }
        else if (bot == 'K')
        {
            printf("Bot memilih Kertas sehingga Anda menang dan mendapatkan giliran pertama\n\n");
        }
        else if (bot == 'B')
        {
            printf("Bot memilih Batu sehingga Anda menang dan mendapatkan giliran pertama\n\n");
        }
        botType = 'O';
        playerType = 'X';
    }
    else
    {
        if(bot == 'G')
        {
            printf("Bot memilih Gunting sehingga Anda kalah dan mendapatkan giliran kedua\n\n");
        }
        else if (bot == 'K')
        {
            printf("Bot memilih Kertas sehingga Anda kalah dan mendapatkan giliran kedua\n\n");
        }
        else if (bot == 'B')
        {
            printf("Bot memilih Batu sehingga Anda kalah dan mendapatkan giliran kedua\n\n");
        }
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