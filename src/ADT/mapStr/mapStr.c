#include "mapStr.h"

void InsertSB(MapStr *SB, int skor)
{
    char *str = malloc(sizeof(char) * 13);
    printf("Masukkan nama anda: ");
    STARTWORD("", "");
    while (!(!IsMemberMS(*SB, currentWord.TabWord) && stringLength(currentWord.TabWord) < 13))
    {
        printf("Nama tidak boleh sama dan panjang nama harus kurang dari 13 karakter\n");
        printf("Masukkan nama anda: ");
        STARTWORD("","");
    }
    int i = 0;
    while (currentWord.TabWord[i] != '\0')
    {
        str[i] = currentWord.TabWord[i];
        i++;
    }
    str[i] = '\0';
    InsertMS(SB, str, skor);
    printf("\nOke, nama akan dimasukkan ke scoreboard\n");

    printf("Skor akhir : %d\n", skor);
    printf("Nama       : %s\n", str);
}

void CreateMS(MapStr *M)
{
    M->Count = NilMS;
}

boolean IsEmptyMS(MapStr M)
{
    return (M.Count == NilMS);
}

boolean IsFullMS(MapStr M)
{
    return M.Count == MaxElMS;
}

void InsertMS(MapStr *M, keytypeMS k, valuetypeMS v)
{
    if (!IsFullMS(*M))
    {
        {
            M->Count++;
            M->Elements[M->Count - 1].Key = k;
            M->Elements[M->Count - 1].ValueMS = v;
        }
    }
}

void DeleteMS(MapStr *M, keytypeMS k)
{
    if (M->Count == 1)
        M->Count = NilMS;
    else
    {
        if (IsMemberMS(*M, k))
        {
            int i = 0;
            while (i < M->Count && !isEqualStr(M->Elements[i].Key, k))
                i++;
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].ValueMS = M->Elements[i + 1].ValueMS;
                i++;
            }
            M->Count--;
        }
    }
}
boolean IsMemberMS(MapStr M, keytypeMS k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (isEqualStr(M.Elements[i].Key, k))
            return true;
        i++;
    }
    return false;
}

valuetypeMS ValueMS(MapStr M, keytypeMS k)
{
    if (IsMemberMS(M, k))
    {
        int i = 0;
        boolean found = false;
        while (i < M.Count && !found)
        {
            if (isEqualStr(M.Elements[i].Key, k))
            {

                found = true;
            }
            else
            {
                i++;
            }
        }
        return M.Elements[i].ValueMS;
    }
    else
    {
        return UndefinedMS;
    }
}

int iMax(MapStr M)
{
    int max = M.Elements[0].ValueMS;
    int i = 1, j = 0;
    for (i; i < M.Count; i++)
    {
        if (max < M.Elements[i].ValueMS)
        {
            j = i;
            max = M.Elements[i].ValueMS;
        }
    }
    return j;
}