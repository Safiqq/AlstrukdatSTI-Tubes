#include "../header/tictactoe.h"

// FUNGSI / PROSEDUR PRIMITIF

// Untuk menghitung panjang string
int len(char *str)
{
    int len;
    for (len = 0;; ++len)
        if (str[len] == 0)
            return len;
}

// Untuk convert string to integer
int stringToInteger(char *str)
{
    int i, sum = 0;
    for (i = 0; i < len(str); i++)
    {
        sum = sum * 10 + (str[i] - '0');
    }
    return sum;
}

// Untuk validasi apakah sudah memenuhi kondisi win atau belum
boolean winCondition(ArrayChar T, char p)
{
    int i, j;
    boolean flag = false;
    for (i = 0; i <= 6; i = i + 3)
    {
        if (T.TI[i] == p && T.TI[i + 1] == p && T.TI[i + 2] == p)
        {
            flag = true;
        }
    }
    for (j = 0; j <= 2; j++)
    {
        if (T.TI[j] == p && T.TI[j + 3] == p && T.TI[j + 6] == p)
        {
            flag = true;
        }
    }
    if ((T.TI[0] == p && T.TI[4] == p && T.TI[8] == p) || T.TI[2] == p && T.TI[4] == p && T.TI[6] == p)
    {
        flag = true;
    }
    return flag;
}

// Untuk menampilkan table saat ini
void displayTable(ArrayChar T)
{
    int i;
    printf("Table saat ini: \n\n");
    for (i = 0; i <= 6; i = i + 3)
    {
        printf(" %c | %c | %c\n", T.TI[i], T.TI[i + 1], T.TI[i + 2]);
        printf("------------\n");
    }
}

void infoTable()
{
    int i;
    printf("Penjelasan Index Table: \n\n");
    for (i = 0; i <= 6; i = i + 3)
    {
        printf(" %d | %d | %d\n", i, i + 1, i + 2);
        printf("------------\n");
    }
}

// Untuk menghasilkan random number
int randomNumber(int min, int max)
{
    return ((rand() % max) + min);
}

// prosedur giliran Bot
void botTurn(ArrayChar *T, char bot, char player)
{
    int i = randomNumber(0, 8);
    boolean flag = false;
    while (!flag)
    {
        if ((*T).TI[i] != player && (*T).TI[i] != bot)
        {
            SetAC(T, i, bot);
            flag = true;
        }
        else
        {
            i = (i + 1) % 9;
        }
    }
    printf("Bot sudah mengisi kotak\n");
}

// Validasi apakah string itu isinya digit semua atau bukan
boolean isDigit(char *string)
{
    boolean flag = false;
    int i = 0;
    while (!flag && i < len(string))
    {
        if (string[i] - '0' < 0 || string[i] - '0' > 9)
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
void playerTurn(ArrayChar *T, char player, char bot)
{
    boolean flag = false;
    int index;
    while (!flag)
    {
        boolean flagcmd = false;
        while (!flagcmd)
        {
            printf("Silahkan masukkan index kotak (0-8) yang akan diisi : ");
            STARTWORD("", "");
            if (isDigit(currentWord.TabWord))
            {
                flagcmd = true;
                index = stringToInteger(currentWord.TabWord);
            }
            else
            {
                printf("Kamu nanyeeaa kenapa gabisa? Biar aku kasih tau ya kamu inputnya string atau angka minus ya, bukan integer positif! RAAAWWRRR\n");
            }
        }
        if (index > 8 || index < 0)
        {
            printf("Index di luar jangkauan, Silahkan masukkan index yang benar!\n");
        }
        else
        {
            if ((*T).TI[index] != bot && (*T).TI[index] != player)
            {
                SetAC(T, index, player);
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
    while (!flag)
    {
        int ibot = randomNumber(0, 2); // 0 = Gunting, 1 = Batu, 2 = Kertas
        if (ibot == 0)
        {
            bot = 'G';
        }
        else if (bot == 1)
        {
            bot = 'B';
        }
        else
        {
            bot = 'K';
        }

        if (bot != player)
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
    if ((bot == 'G' && player == 'B') || (bot == 'K' && player == 'G') || (bot == 'B' && player == 'K'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Program Utama
void tictactoe(ArrayMap *arrSB)
{
    int i;
    // Membuat table kosong
    ArrayChar Table;
    CreateAC(&Table);
    for (i = 0; i < 9; i++)
    {
        SetAC(&Table, i, ' ');
    }

    // Deklarasi variabel
    char p;
    char playerType, botType;

    printf("---Selamat datang di TicTacToe---\n\n");

    // Input Pengguna dan check apakah player menang atau kalah suit dengan bot
    boolean flagp = false;
    while (!flagp)
    {
        printf("Silahkan input (Batu/Gunting/Kertas) untuk menentukan giliran pertama : ");
        STARTWORD("", "");
        if (IsEqual(currentWord, "BATU") || IsEqual(currentWord, "Batu") || IsEqual(currentWord, "batu"))
        {
            p = 'B';
            flagp = true;
        }
        else if (IsEqual(currentWord, "GUNTING") || IsEqual(currentWord, "Gunting") || IsEqual(currentWord, "gunting"))
        {
            p = 'G';
            flagp = true;
        }
        else if (IsEqual(currentWord, "KERTAS") || IsEqual(currentWord, "Kertas") || IsEqual(currentWord, "kertas"))
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
    if (suit(p, bot))
    {
        if (bot == 'G')
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
        if (bot == 'G')
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

    infoTable();
    displayTable(Table);
    int count = 0;
    boolean seri = false;
    // Jika player menang suwit sama bot maka player mendapatkan giliran pertama
    if (suit(p, bot))
    {
        // Selama belum menang atau kalah atau seri maka permainan akan terus dijalankan
        while (!winCondition(Table, botType) && !winCondition(Table, playerType) && count <= 8 && !seri)
        {
            playerTurn(&Table, playerType, botType);
            count++;
            displayTable(Table);
            if (count == 9)
            {
                seri = true;
            }
            if (!winCondition(Table, playerType) && !seri)
            {
                botTurn(&Table, botType, playerType);
                count++;
                displayTable(Table);
            }
        }
    }
    else // Jika player kalah suwit sama bot
    {
        while (!winCondition(Table, botType) && !winCondition(Table, playerType) && count <= 8 && !seri)
        {
            botTurn(&Table, botType, playerType);
            count++;
            displayTable(Table);
            if (count == 9)
            {
                seri = true;
            }
            if (!winCondition(Table, botType) && !seri)
            {
                playerTurn(&Table, playerType, botType);
                count++;
                displayTable(Table);
            }
        }
    }

    printf("\n");
    printf("=========================================\n");
    // Check siapakah pemenangnya atau bisa seri
    int skor;
    if (winCondition(Table, playerType))
    {
        printf("Selamat Anda menang!\n");
        skor = 100;
    }
    else if (winCondition(Table, botType))
    {
        printf("Selamat Anda kalah :V\n");
        skor = 0;
    }
    else
    {
        printf("Masa Seri sama bot :V\n");
        skor = 50;
    }
    InsertSB(&arrSB->TIMap[5], skor);
    printf("=========================================\n\n");
}