#include "mapInt.h"

int main()
{
    Map M;
    // Membuat array kosong
    CreateMI(&M);
    // Menambahkan element ke Map sehinggaa 10 menjadi anggota dari M dengan key 1
    InsertMI(&M, 1, 10);
    // Menambahkan element ke Map sehinggaa 6 menjadi anggota dari M dengan key 2
    InsertMI(&M, 2, 6);
    // Menghapus element dari Map yang memiliki key 2
    DeleteMI(&M, 1);
    // Mengecek apakah terdapat key 1 di Map
    printf("%d\n", IsMemberMI(M, 1));
    // Mengecek apakah terdapat key 2 di Map
    printf("%d\n", IsMemberMI(M, 2));
    // Bila output 0 berarti key tidak berada di map dan 1 berarti key berada di map
    return 0;
}