#include "binaryTree.h"

int main(){
    // Inisialisasi Variabel
    BinTree left, right, BT;
    int root=5;
    // Membuat BT baru dan alokasi node
    left= AlokasiBT(2);
    right=AlokasiBT(7);
    BT = NewBT(root,left,right);
    //Mengecek apakah pohon biner kosong dan elemennya one
    if (IsEmptyBT(BT))
    {
        printf("Pohon kosong\n");
    }
    else{
        printf("Pohon tidak kosong\n");
    }
    if (IsNoneElmtBT(BT)){
        printf("Pohon satu elemen\n");
    }
    else{
        printf("Pohon tidak satu elemen\n");
    }
    //Melakukan display pohon
    PrintBT(BT, 2, 2);
}