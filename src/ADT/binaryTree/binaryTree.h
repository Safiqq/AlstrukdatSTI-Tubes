/* File : bintree.h */
/* ADT pohon biner */
/* Representasi addressBT dengan pointer */

#ifndef __BINARYTREE_H__
#define __BINARYTREE_H__

#include <stdio.h>
#include <stdlib.h>
#include "../../header/boolean.h"

/* Selektor */
#define ROOT(p) (p)->info
#define LEFT(p) (p)->left
#define RIGHT(p) (p)->right

typedef struct treeNode *addressBT;
typedef struct treeNode
{
    int info;
    addressBT left;
    addressBT right;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef addressBT BinTree;

BinTree NewBT(int root, BinTree left_tree, BinTree right_tree);
/* Menghasilkan sebuah pohon biner dari root, left_tree, dan right_tree, jika alokasi berhasil
   Menghasilkan pohon kosong (NULL) jika alokasi gagal */

addressBT AlokasiBT(int val);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */

boolean IsEmptyBT(BinTree p);
/* Mengirimkan true jika p adalah pohon biner yang kosong */

boolean IsNoneElmtBT(BinTree p);
/* Mengirimkan true jika left dan right dari p adalah kosong */

void PrintBT(BinTree p, int h, int dep);
/* I.S. p terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul p sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2:
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
Note: Anda boleh membuat fungsi tambahan untuk membuat implementasi fungsi ini jika diperlukan
*/

#endif