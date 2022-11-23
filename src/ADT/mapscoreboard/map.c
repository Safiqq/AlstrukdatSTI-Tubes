#include "map.h"
#include "../mesinkata/mesinkata.h"

void insertSB(MapSB *SB,int skor){
    char *str=malloc(sizeof(char)*13);
    printf("Masukkan nama anda: ");
    scanf("%s", str);
    while(!(!IsMemberMapSB(*SB,str)&& StringLength(str)<13)){
        printf("Nama tidak boleh sama dan panjang kurang dari 13\n");
        printf("Masukkan nama anda: ");
        scanf("%s", str);
    }
    InsertMapSB(SB,str,skor);
    printf("\nOke, nama akan dimasukkan ke scoreboard\n");

    printf("Skor akhir : %d\n", skor);
    printf("Nama       : %s\n", str);
}

boolean stringEqual(char *a,char*b){
    boolean beda=false;
    if(StringLength(a)==StringLength(b)){
        while(*a!='\0' && !beda){
            if(*a!=*b){
                beda = true;
            }
            *a++;
            *b++;
        }
        return !beda;
    }
    else{
        return beda;
    }
}

void CreateMapSB(MapSB *M)
{
    M->Count = Nill;
}

boolean IsEmptyMapSB(MapSB M){
    return (M.Count == Nill);
}

boolean IsFullMapSB(MapSB M)
{
    return M.Count == MaxEle;
}

void InsertMapSB(MapSB *M, keytype k, valuetype v)
{
    if (!IsFullMap(*M))
    {
        {
            M->Count++;
            M->Elements[M->Count - 1].Key = k;
            M->Elements[M->Count - 1].Value = v;
        }
    }
}

void DeleteMapSB(MapSB *M, keytype k)
{
    if (M->Count == 1)
        M->Count = Nill;
    else
    {
        if (IsMemberMap(*M, k))
        {
            int i = 0;
            while (i < M->Count && !stringEqual(M->Elements[i].Key, k))
                i++;
            while (i < M->Count)
            {
                M->Elements[i].Key = M->Elements[i + 1].Key;
                M->Elements[i].Value = M->Elements[i + 1].Value;
                i++;
            }
            M->Count--;
        }
    }
}
boolean IsMemberMapSB(MapSB M, keytype k)
{
    int i = 0;
    while (i < M.Count)
    {
        if (stringEqual(M.Elements[i].Key, k))
            return true;
        i++;
    }
    return false;
}



valuetype Value(MapSB M, keytype k){
    if(IsMemberMap(M,k)){
        int i = 0;
        boolean found=false;
        while(i<M.Count && !found){
            if(stringEqual(M.Elements[i].Key,k)){

                found = true;
            }
            else{
                i++;
            }
        }
        return M.Elements[i].Value;
    }
    else{
        return Undefined;
    }  
}

