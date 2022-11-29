#include "stackStr.h"

int main(){
    //Inisialisasi variabel
    StackStr SS;
    infotypeSS a, b, c, d;
    //Membuat Stack SS kosong
    CreateSS(&SS);
    //Mengecek apakah SS sekarang kosong
    if (IsEmptySS(SS)){
        printf("Stack SS terbentuk dan isinya kosong.\n");
    }
    //Melakukan Push ke Stack dan mengecek apakah masih kosong dan menampilkan jumlah elemennya
    a="Test aja";
    PushSS(&SS,a);
    if (!IsEmptySS(SS)){
        printf("Push ke Stack SS berhasil. Jumlah elemen stack sekarang: %d\n",NbElmtSS(SS));
    }
    //Melakukan Pop dan mengecek variabel outputnya
    PopSS(&SS, &b);
    printf("Hasil Pop yang keluar adalah '%s'.\n",b);
    //Melakukan push sebanyak 3 kali dengan infotype berbeda dan melakukan reverse kemudian melakukan Pop untuk mengecek apakah reverse berhasil
    a="Test";
    b="Alstru";
    c="Hai";
    PushSS(&SS,a);
    PushSS(&SS,b);
    PushSS(&SS,c);
    ReverseSS(&SS);
    PopSS(&SS,&d);
    printf("Hasil Pop yang keluar adalah '%s'.\n",d);
    return 0;
}