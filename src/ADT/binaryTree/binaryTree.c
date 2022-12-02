#include "binaryTree.h"

BinTree NewBT(int root, BinTree left_tree, BinTree right_tree)
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */
{
    addressBT t = AlokasiBT(root);
    if (t != NULL)
    {
        LEFT(t) = left_tree;
        RIGHT(t) = right_tree;
    }
    return t;
}

addressBT AlokasiBT(int val)
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */
{
    addressBT p = (addressBT)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        ROOT(p) = val;
        LEFT(p) = NULL;
        RIGHT(p) = NULL;
    }
    return p;
}

boolean IsEmptyBT(BinTree p)
/* Mengirimkan true jika p adalah pohon biner yang kosong */
{
    return (p == NULL);
}

boolean IsNoneElmtBT(BinTree p)
{
    return IsEmptyBT(LEFT(p)) && IsEmptyBT(RIGHT(p));
}

void PrintBT(BinTree p, int h, int dep)
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  BP
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/
{
    if (!IsEmptyBT(p))
    {
        int i;
        for (i = 0; i < h * dep; i++)
        {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        PrintBT(LEFT(p), h, dep + 1);
        PrintBT(RIGHT(p), h, dep + 1);
    }
}
