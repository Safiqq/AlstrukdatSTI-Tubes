#include "map.h"
#include <stdio.h>

int main()
{
    Map M;
    //Membuat array kosong
    CreateMap(&M);
    //Menambahkan element ke Map sehinggaa 10 menjadi anggota dari M dengan key 1
    InsertMap(&M, 1, 10);
    //Menambahkan element ke Map sehinggaa 6 menjadi anggota dari M dengan key 2
    InsertMap(&M, 2,6);
    //Menghapus element dari Map yang memiliki key 2
    DeleteMap(&M, 1);
    //Mengecek apakah terdapat key 1 di Map
    printf("%d\n",IsMemberMap(M, 1));
    //Mengecek apakah terdapat key 2 di Map
    printf("%d\n",IsMemberMap(M, 2));
    //Bila output 0 berarti key tidak berada di map dan 1 berarti key berada di map
    return 0;
}