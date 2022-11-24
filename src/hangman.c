#include <stdio.h>
#include "./ADT/arrayOfChar/array.h"
#include "./ADT/mesinkata/mesinkata.h"
#include <stdlib.h>

char toLower(char huruf)
{
    if((int)huruf >= 65 && (int)huruf <= 90)
    {
        huruf = huruf + 32;
    }
    return huruf;
}

char toUpper(char huruf)
{
    if((int)huruf >= 97 && (int)huruf <= 122)
    {
        huruf = huruf - 32;
    }
    return huruf;
}

int lengthStr(char str[])
{
    int count;     
    for (count = 0; str[count] != '\0'; ++count);
    return count; 
}

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

void displayHangman(int mistakes, char* body) {
	switch(mistakes) 
    {
        case 9: body[9] = '\\'; break;
        case 8: body[8] = '/'; break;
		case 7: body[7] = '\\'; break;
		case 6: body[6] = '|'; break;
		case 5: body[5] = '/'; break;
		case 4: body[4] = ')'; break;
		case 3: body[3] = 'v'; break;
		case 2: body[2] = ':'; break;
        case 1: body[1] = '('; break;
		default: break;
	}

	printf("\t __________\n"
	       "\t|          |\n"
	       "\t|        %c%c%c%c\n"
	       "\t|         %c%c%c\n"
	       "\t|         %c %c\n"
	       "\t|             \n"
	       "\t|             \n"
           "========================", body[1], body[2], body[3],
	       body[4], body[5], body[6], body[7], body[8], body[9]);
}

TabChr createBlankKata(TabChr kamus)
{
    TabChr blank;
    CreateArr(&blank);
    int i = 0;
    for(i; i<kamus.Neff; i++)
    {
        SetArr(&blank, i, '_');
    }
    return blank;
}

TabChr createHistory()
{
    TabChr history;
    CreateArr(&history);
    return history;
}

void displayHistory(TabChr history)
{
    printf("Tebakan sebelumnya: ");
    if(IsEmptyArr(history))
    {
        printf("-");
    }
    else
    {
        int i = 0;
        for(i; i <history.Neff; i++)
        {
            printf("%c", history.TI[i]);
        }
    }
    printf("\n");
}

void displayTebak(TabChr kata)
{
    printf("Kata: ");
    int i = 0;
    for(i; i < kata.Neff; i++)
    {
        printf("%c ", kata.TI[i]);
    }
    printf("\n");
}

void prosesKata(TabChr*kata, TabChr kamus, char huruf, int*chance)
{
    boolean flag = false;
    int i = 0;
    for(i; i< kamus.Neff; i++)
    {
        if(kamus.TI[i] == toUpper(huruf))
        {
            kata->TI[i] = toUpper(huruf);
            flag = true;
        }
    }
    if(flag == false)
    {
        (*chance)--;
    }
}

void setHistory(TabChr*history, char huruf)
{
    int i = 0;
    boolean found = false;
    while(!found && i < history->Neff)
    {
        if(history->TI[i] == huruf)
        {
            found = true;
        }
        i++;
    }
    if(!found)
    {
        SetArr(history, history->Neff, huruf);
    }
}

boolean isSameArr(TabChr kata1, TabChr kata2)
{
    if(kata1.Neff != kata2.Neff)
    {
        return false;
    }
    else
    {
        boolean same = false;
        int i = 0;
        while(!same && i < kata1.Neff)
        {
            if(toLower(kata1.TI[i]) != toLower(kata2.TI[i]))
            {
                return false;
            }
            i++;
        }
        return true;
    }
}

boolean isCharInArr(TabChr kata, char huruf)
{
    int i = 0;
    while(i < kata.Neff)
    {
        if(kata.TI[i] == huruf)
        {
            return true;
        }
        i++;
    }
    return false;
}

void hangman()
{
    mainmenu();
    printf("\n\n");
    boolean isNewKamus = false;
    boolean bukaAwal = false;
    while(!isNewKamus)
    {
        char cmd[10];
        printf("Apakah kamu mau membuat kamus baru? (Y/N) : ");
        scanf(" %s", &cmd);
        if(lengthStr(cmd) > 1)
        {
            printf("Input salah, Silahkan ulangi!\n");
        }
        else
        {
            FILE*txt;
            if(cmd[0] == 'Y')
            {
                if(!bukaAwal)
                {
                    txt = fopen("../data/hangman.txt", "w");
                    fprintf(txt, "%s\n", "PAKRIZA");
                    fprintf(txt, "%s\n", "LOVE");
                    fprintf(txt, "%s\n", "ALSTRUKDAT");
                    fprintf(txt, "%s\n", "HAFIDZ");
                    fprintf(txt, "%s\n", "PEDRO");
                    fprintf(txt, "%s\n", "SYAFIQ");
                    fprintf(txt, "%s\n", "ONCAR");
                    fprintf(txt, "%s\n", "MARVEL");
                    bukaAwal = true;
                }
                char newKamus[21];
                printf("Silahkan masukkan kamus baru : ");
                scanf(" %s", &newKamus);
                fprintf(txt, "%s\n", newKamus);
            }
            if(cmd[0] == 'N')
            {
                fclose(txt);
                isNewKamus = true;
            }
        }
    }

    TabChr history, tebak, kamus;
    CreateArr(&kamus);
    STARTWORD("../data/hangman.txt", "r");
    int i = 0;
    for(i; i < currentWord.Length; i++)
    {
        SetArr(&kamus, i, currentWord.TabWord[i]);
    }
    int poin = 0;
    int chance = 10;
    char body[11] = "          ";
    boolean win = false;
    tebak = createBlankKata(kamus);
    history = createHistory();
    while (chance != 0)
    {
        char maxHuruf[10];
        char huruf;
        // Display
        displayHangman(10-chance, body);
        printf("\n");
        displayHistory(history);
        displayTebak(tebak);
        printf("Kesempatan: %d\n", chance);

        // Proses
        boolean isValid = false;
        while (!isValid)
        {
            printf("Masukkan tebakan: ");
            scanf(" %s", &maxHuruf);
            if(lengthStr(maxHuruf) > 1)
            {
                printf("Silahkan input huruf bertipe char (1 huruf)!\n");
            }
            else
            {
                huruf = maxHuruf[0];
                if(isCharInArr(history, toLower(huruf)) || isCharInArr(history, toUpper(huruf)))
                {
                    printf("Tidak boleh menebak huruf yang sama!\n");
                }
                else
                {
                    isValid = true;
                }
            }
        }
        setHistory(&history, huruf);
        prosesKata(&tebak, kamus, huruf, &chance);
        printf("\n");

        if(isSameArr(tebak, kamus))
        {
            printf("Berhasil menebak kata ");
            int j = 0;
            for(j; j < LengthArr(kamus); j++)
            {
                printf("%c", kamus.TI[j]);
            }
            printf(". Kamu mendapatkan %d poin!\n", kamus.Neff);
            poin = poin + kamus.Neff;
            ADVLINE();
            CreateArr(&kamus);
            int i = 0;
            for(i; i < currentWord.Length; i++)
            {
                SetArr(&kamus, i, currentWord.TabWord[i]);
            }

            printf("\n");
            tebak = createBlankKata(kamus);
            history = createHistory();
        }
    }

    printf("=================================\n"
           "GAME BERAKHIR. SCORE ANDA : %d\n"
           "=================================\n", poin);
}