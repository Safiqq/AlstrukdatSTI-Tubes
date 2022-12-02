#include "../header/findthenumber.h"

void findTheNumber(ArrayMap *arrSB)
{
    int x = (rand() % 32) + 31;
    BinTree T = NewBT(0,
                    NewBT(1,
                        NewBT(3, NewBT(7, NewBT(15, NewBT(31, NULL, NULL), NewBT(32, NULL, NULL)), NewBT(16, NewBT(33, NULL, NULL), NewBT(34, NULL, NULL))), NewBT(8, NewBT(17, NewBT(35, NULL, NULL), NewBT(36, NULL, NULL)), NewBT(18, NewBT(37, NULL, NULL), NewBT(38, NULL, NULL)))),
                        NewBT(4, NewBT(9, NewBT(19, NewBT(39, NULL, NULL), NewBT(40, NULL, NULL)), NewBT(20, NewBT(41, NULL, NULL), NewBT(42, NULL, NULL))), NewBT(10, NewBT(21, NewBT(43, NULL, NULL), NewBT(44, NULL, NULL)), NewBT(22, NewBT(45, NULL, NULL), NewBT(46, NULL, NULL))))),
                    NewBT(2,
                        NewBT(5, NewBT(11, NewBT(23, NewBT(47, NULL, NULL), NewBT(48, NULL, NULL)), NewBT(24, NewBT(49, NULL, NULL), NewBT(50, NULL, NULL))), NewBT(12, NewBT(25, NewBT(51, NULL, NULL), NewBT(52, NULL, NULL)), NewBT(26, NewBT(53, NULL, NULL), NewBT(54, NULL, NULL)))),
                        NewBT(6, NewBT(13, NewBT(27, NewBT(55, NULL, NULL), NewBT(56, NULL, NULL)), NewBT(28, NewBT(57, NULL, NULL), NewBT(58, NULL, NULL))), NewBT(14, NewBT(29, NewBT(59, NULL, NULL), NewBT(60, NULL, NULL)), NewBT(30, NewBT(61, NULL, NULL), NewBT(62, NULL, NULL))))));
    srand(time(NULL));
    printf("Gunakan full screen untuk experience yang lebih baik :)\nTekan ENTER untuk melanjutkan...\n");
    STARTWORD("", "");
    PrintBT(T, 3, 0);
    printf("Tentukan langkah yang tepat untuk mencapai angka %d\n\n", x);
    while (ROOT(T) != x && !IsNoneElmtBT(T))
    {
        printf("Kamu sekarang berada di angka %d\n", ROOT(T));
        printf("Silakan masukkan command Anda [L/R]: ");
        STARTWORD("", "");
        printf("\n");
        while (!IsEqual(currentWord, "L") && !IsEqual(currentWord, "R"))
        {
            printf("Command tidak valid! Silakan input command menggunakan huruf L/R\n");
            printf("Silakan masukkan command Anda: [L/R]: ");
            STARTWORD("", "");
            printf("\n");
        }
        T = IsEqual(currentWord, "L") ? LEFT(T) : RIGHT(T);
    }
    if (ROOT(T) == x)
        printf("Kamu berhasil menemukan angka %d!\n", x);
    else
        printf("Noob! Kamu gagal!\n");
    int score = ROOT(T) == x ? 100 : 0;
    printf("Skor: %d\n", score);
    InsertSB(&arrSB->TIMap[7], score);
}