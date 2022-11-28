#include "../header/hangman.h"

// Fungsi untuk membuat char menjadi huruf kecil
char toLower(char huruf)
{
    if ((int)huruf >= 65 && (int)huruf <= 90)
    {
        huruf = huruf + 32;
    }
    return huruf;
}

// Fungsi untuk membuat char menjadi huruf kapital
char toUpper(char huruf)
{
    if ((int)huruf >= 97 && (int)huruf <= 122)
    {
        huruf = huruf - 32;
    }
    return huruf;
}

// Fungsi untuk menghasilkan panjang string
int lengthStr(char str[])
{
    int count;
    for (count = 0; str[count] != '\0'; ++count)
        ;
    return count;
}

// Prosedur untuk display main menu
void mainmenu()
{
    printf("\t __________\n"
           "\t|          |\n"
           "\t|       WELCOME\n"
           "\t|         TO\n"
           "\t|       HANGMAN\n"
           "\t|              \n"
           "\t|              \n"
           "========================");
}

// Prosedur untuk display hangman
void displayHangman(int mistakes, char *body)
{
    switch (mistakes)
    {
    case 9:
        body[9] = '\\';
        break;
    case 8:
        body[8] = '/';
        break;
    case 7:
        body[7] = '\\';
        break;
    case 6:
        body[6] = '|';
        break;
    case 5:
        body[5] = '/';
        break;
    case 4:
        body[4] = ')';
        break;
    case 3:
        body[3] = 'v';
        break;
    case 2:
        body[2] = ':';
        break;
    case 1:
        body[1] = '(';
        break;
    default:
        break;
    }

    printf("\t __________\n"
           "\t|          |\n"
           "\t|        %c%c%c%c\n"
           "\t|         %c%c%c\n"
           "\t|         %c %c\n"
           "\t|             \n"
           "\t|             \n"
           "========================",
           body[1], body[2], body[3],
           body[4], body[5], body[6], body[7], body[8], body[9]);
}

// Fungsi untuk mereturn kata tebakan
ArrayChar createBlankKata(ArrayChar kamus)
{
    ArrayChar blank;
    CreateAC(&blank);
    int i = 0;
    for (i; i < kamus.Neff; i++)
    {
        SetAC(&blank, i, '_');
    }
    return blank;
}

// Fungsi untuk mereturn huruf yang telah ditebak
ArrayChar createHistory()
{
    ArrayChar history;
    CreateAC(&history);
    return history;
}

// Prosedur untuk menampilkan huruf yang telah ditebak
void displayHistory(ArrayChar history)
{
    printf("Tebakan sebelumnya: ");
    if (IsEmptyAC(history))
    {
        printf("-");
    }
    else
    {
        int i = 0;
        for (i; i < history.Neff; i++)
        {
            printf("%c", history.TI[i]);
        }
    }
    printf("\n");
}

// Prosedur untuk menampilkan kata tebakan
void displayTebak(ArrayChar kata)
{
    printf("Kata: ");
    int i = 0;
    for (i; i < kata.Neff; i++)
    {
        printf("%c ", kata.TI[i]);
    }
    printf("\n");
}

// Prosedur untuk memproses tebakan yang diinput oleh user
void prosesKata(ArrayChar *kata, ArrayChar kamus, char huruf, int *chance)
{
    boolean flag = false;
    int i = 0;
    for (i; i < kamus.Neff; i++)
    {
        if (kamus.TI[i] == toUpper(huruf))
        {
            kata->TI[i] = toUpper(huruf);
            flag = true;
        }
    }
    if (flag == false)
    {
        (*chance)--;
    }
}

// Prosedur untuk menambahkan kata yang telah ditebak
void setHistory(ArrayChar *history, char huruf)
{
    int i = 0;
    boolean found = false;
    while (!found && i < history->Neff)
    {
        if (history->TI[i] == huruf)
        {
            found = true;
        }
        i++;
    }
    if (!found)
    {
        SetAC(history, history->Neff, huruf);
    }
}

// Fungsi untuk check apakah array sama
boolean isSameArr(ArrayChar kata1, ArrayChar kata2)
{
    if (kata1.Neff != kata2.Neff)
    {
        return false;
    }
    else
    {
        boolean same = false;
        int i = 0;
        while (!same && i < kata1.Neff)
        {
            if (toLower(kata1.TI[i]) != toLower(kata2.TI[i]))
            {
                return false;
            }
            i++;
        }
        return true;
    }
}

// Fungsi untuk check apakah char di dalam suatu array
boolean isCharInArr(ArrayChar kata, char huruf)
{
    int i = 0;
    while (i < kata.Neff)
    {
        if (kata.TI[i] == huruf)
        {
            return true;
        }
        i++;
    }
    return false;
}

// Prosedur untuk memulai hangman (membaca dari file txt dengan mesin kata)
void startHangman(ArrayChar *tebak, ArrayChar *history, ArrayChar *kamus)
{
    CreateAC(kamus);
    STARTWORD("../data/hangman.txt", "r");
    int i = 0;
    for (i; i < currentWord.Length; i++)
    {
        SetAC(kamus, i, currentWord.TabWord[i]);
    }
    *tebak = createBlankKata(*kamus);
    *history = createHistory();
}

// Program utama
void hangman(ArrayMap *arrSB)
{
    // Menampilkan main menu
    mainmenu();
    printf("\n\n");

    // Deklarasi dan inisialisasi variabel boolean untuk logika looping
    boolean isNewKamus = false;
    boolean bukaKamus = false;
    // Untuk menambahkan jika user ingin membuat kamus baru
    while (!isNewKamus)
    {
        //char cmd[10];
        printf("Apakah kamu mau membuat kamus baru? (Y/N) : ");
        STARTWORD("","");
        if (lengthStr(currentWord.TabWord) > 1)
        {
            printf("Input salah, Silahkan ulangi!\n");
        }
        else
        {
            FILE *txt;
            if (!bukaKamus)
            {
                txt = fopen("../data/hangman.txt", "a");
                bukaKamus = true;
            }

            if (currentWord.TabWord[0] == 'Y')
            {
                char newKamus[21];
                printf("Silahkan masukkan kamus baru : ");
                STARTWORD("","");
                int i = 0;
                while (currentWord.TabWord[i] != '\0')
                {
                    newKamus[i] = currentWord.TabWord[i];
                    i++;
                }
                newKamus[i] = '\0';
                fprintf(txt, "\n%s", newKamus);
            }
            if (currentWord.TabWord[0] == 'N')
            {
                fclose(txt);
                isNewKamus = true;
            }
        }
    }

    // Deklarasi dan inisialisasi variabel
    ArrayChar history, tebak, kamus;
    int poin = 0;
    int chance = 10;
    char body[11] = "          ";

    // Memulai hangman
    startHangman(&tebak, &history, &kamus);
    //Inisialisasi Variabel baris kamus di file txt
    int line=1;
    while (chance != 0)
    {
        // Deklarasi variabel untuk tebakan
        char maxHuruf[10];
        char huruf;

        // Display
        displayHangman(10 - chance, body);
        printf("\n");
        displayHistory(history);
        displayTebak(tebak);
        printf("Kesempatan: %d\n", chance);

        // Proses
        boolean isValid = false;
        while (!isValid)
        {
            printf("Masukkan tebakan: ");
            STARTWORD("","");
            int i = 0;
            while (currentWord.TabWord[i] != '\0')
            {
                maxHuruf[i] = currentWord.TabWord[i];
                i++;
            }
            maxHuruf[i] = '\0';
            if (lengthStr(maxHuruf) > 1)
            {
                printf("Silahkan input huruf bertipe char (1 huruf)!\n");
            }
            else
            {
                huruf = maxHuruf[0];
                if (isCharInArr(history, toLower(huruf)) || isCharInArr(history, toUpper(huruf)))
                {
                    printf("Tidak boleh menebak huruf yang sama!\n");
                }
                else
                {
                    isValid = true;
                }
            }
        }

        // Memproses hangman
        setHistory(&history, huruf);
        prosesKata(&tebak, kamus, huruf, &chance);
        printf("\n");

        // Jika suatu kata berhasil ditebak
        if (isSameArr(tebak, kamus))
        {
            printf("Berhasil menebak kata ");
            int j = 0;
            for (j; j < LengthAC(kamus); j++)
            {
                printf("%c", kamus.TI[j]);
            }
            printf(". Kamu mendapatkan %d poin!\n", kamus.Neff);
            poin = poin + kamus.Neff;
            STARTWORD("../data/hangman.txt", "r");
            int num=1;
            while (num<=line)
            {
                ADVLINE();
                num++;
            }
            CreateAC(&kamus);
            line++;
            int i = 0;
            for (i; i < currentWord.Length; i++)
            {
                SetAC(&kamus, i, currentWord.TabWord[i]);
            }

            printf("\n");
            tebak = createBlankKata(kamus);
            history = createHistory();
        }
        // Jika kamus telah selesai ditebak semua, maka ulangi dari awal
        if (IsEmptyAC(tebak))
        {
            startHangman(&tebak, &history, &kamus);
        }
    }

    // Game berakhir
    printf("=================================\n");
    printf("GAME BERAKHIR.\n");
    InsertSB(&arrSB->TIMap[2], poin);
    printf("=================================\n");
}