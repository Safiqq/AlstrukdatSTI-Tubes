#include <stdio.h>
#include "./ADT/arrayOfChar/array.h"
#include <stdlib.h>

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
	       "\t|             ", body[1], body[2], body[3],
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
    printf("Tebakan sebelumnya:");
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
    printf("Kata:");
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
        if(kamus.TI[i] == huruf)
        {
            kata->TI[i] = huruf;
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
            if(kata1.TI[i] != kata2.TI[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
}

void hangman()
{
    TabChr kamus1, kamus2, history, tebak;
    CreateArr(&kamus1);
    CreateArr(&kamus2);
    SetArr(&kamus1, 0, 'M');
    SetArr(&kamus1, 1, 'A');
    SetArr(&kamus1, 2, 'T');
    SetArr(&kamus1, 3, 'A');

    SetArr(&kamus2, 0, 'A');
    SetArr(&kamus2, 1, 'L');
    SetArr(&kamus2, 2, 'S');
    SetArr(&kamus2, 3, 'T');
    SetArr(&kamus2, 4, 'R');
    SetArr(&kamus2, 5, 'U');
    SetArr(&kamus2, 6, 'K');
    SetArr(&kamus2, 7, 'D');
    SetArr(&kamus2, 8, 'A');
    SetArr(&kamus2, 9, 'T');

    int poin = 0;
    int chance = 10;
    char body[11] = "          ";
    boolean win = false;
    // Kamus 1
    history = createHistory();
    tebak = createBlankKata(kamus1);
    while (chance != 0 && !win)
    {
        char huruf;
        // Display
        displayHangman(10-chance, body);
        printf("\n");
        displayHistory(history);
        displayTebak(tebak);
        printf("Kesempatan:%d\n", chance);
        printf("Masukkan tebakan:");

        // Proses
        scanf(" %c", &huruf);
        setHistory(&history, huruf);
        prosesKata(&tebak, kamus1, huruf, &chance);
        printf("\n");

        if(isSameArr(tebak, kamus1))
        {
            win = true;
            printf("Berhasil menebak kata MATA! Kamu mendapatkan %d poin!\n", kamus1.Neff);
            poin = poin + kamus1.Neff;
        }
    }

    //Kamus 2
    win = false;
    history = createHistory();
    tebak = createBlankKata(kamus2);
    while (chance != 0 && !win)
    {
        char huruf;
        // Display
        displayHangman(10-chance, body);
        printf("\n");
        displayHistory(history);
        displayTebak(tebak);
        printf("Kesempatan:%d\n", chance);
        printf("Masukkan tebakan:");

        // Proses
        scanf(" %c", &huruf);
        setHistory(&history, huruf);
        prosesKata(&tebak, kamus2, huruf, &chance);
        printf("\n");

        if(isSameArr(tebak, kamus2))
        {
            win = true;
            printf("Berhasil menebak kata ALSTRUKDAT! Kamu mendapatkan %d poin!\n", kamus2.Neff);
            poin = poin + kamus2.Neff;
        }
    }

    printf("=================================\n"
           "GAME BERAKHIR. SCORE ANDA : %d\n"
           "=================================\n", poin);
}