#include "../header/towerofhanoi.h"

// Menampilkan Status Tower of Hanoi ke layar
void displayTOH(StackInt S1, StackInt S2, StackInt S3, int max)
{
    // Deklarasi dan inisiasi constant variabel
    int baris = 0;
    int tiangA = max - LengthSI(S1);
    int tiangB = max - LengthSI(S2);
    int tiangC = max - LengthSI(S3);
    int countA = 0;
    int countB = 0;
    int countC = 0;

    // Looping max baris
    for (baris; baris < max; baris++)
    {
        // Awal loop untuk tiang A
        if (tiangA != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for (spaceL; spaceL < max - 1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for (spaceR; spaceR < max - 1; spaceR++)
            {
                printf(" ");
            }
            tiangA--;
        }
        else
        {
            // Deklarasi dan inisiasi index untuk looping
            int spaceR = 0;
            int spaceL = 0;
            int i = 0;

            // Spasi kiri
            for (spaceL; spaceL < ((2 * max - 1) - S1.T[TopSI(S1) - countA]) / 2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for (i; i < S1.T[TopSI(S1) - countA]; i++)
            {
                printf("*");
            }

            // Spasi kanan
            for (spaceR; spaceR < ((2 * max - 1) - S1.T[TopSI(S1) - countA]) / 2; spaceR++)
            {
                printf(" ");
            }
            countA++;
        }
        // Akhir loop untuk tiang A

        printf("   ");

        // Awal loop untuk tiang B
        if (tiangB != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for (spaceL; spaceL < max - 1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for (spaceR; spaceR < max - 1; spaceR++)
            {
                printf(" ");
            }
            tiangB--;
        }
        else
        {
            // Deklarasi dan inisiasi index untuk looping
            int spaceR = 0;
            int spaceL = 0;
            int i = 0;

            // Spasi
            for (spaceL; spaceL < ((2 * max - 1) - S2.T[TopSI(S2) - countB]) / 2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for (i; i < S2.T[TopSI(S2) - countB]; i++)
            {
                printf("*");
            }

            // Spasi
            for (spaceR; spaceR < ((2 * max - 1) - S2.T[TopSI(S2) - countB]) / 2; spaceR++)
            {
                printf(" ");
            }
            countB++;
        }
        // Akhir loop untuk tiang B

        printf("   ");

        // Awal loop untuk tiang C
        if (tiangC != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for (spaceL; spaceL < max - 1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for (spaceR; spaceR < max - 1; spaceR++)
            {
                printf(" ");
            }
            tiangC--;
        }
        else
        {
            // Deklarasi dan inisiasi index untuk looping
            int spaceR = 0;
            int spaceL = 0;
            int i = 0;

            // Spasi
            for (spaceL; spaceL < ((2 * max - 1) - S3.T[TopSI(S3) - countC]) / 2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for (i; i < S3.T[TopSI(S3) - countC]; i++)
            {
                printf("*");
            }

            // Spasi
            for (spaceR; spaceR < ((2 * max - 1) - S3.T[TopSI(S3) - countC]) / 2; spaceR++)
            {
                printf(" ");
            }
            countC++;
        }
        printf("\n");
    }
    // Akhir baris
    int x = 0, y = 0, z = 0, a = 0, b = 0;
    for (x; x < 2 * max - 1; x++)
    {
        printf("-");
    }
    for (a; a < 3; a++)
    {
        printf(" ");
    }
    for (y; y < 2 * max - 1; y++)
    {
        printf("-");
    }
    for (b; b < 3; b++)
    {
        printf(" ");
    }
    for (z; z < 2 * max - 1; z++)
    {
        printf("-");
    }
    printf("\n");
    if (max == 1)
    {
        printf("A   B   C");
    }
    else if (max == 2)
    {
        printf(" A     B     C");
    }
    else if (max == 3)
    {
        printf("Tower A Tower B Tower C");
    }
    else if (max == 4)
    {
        printf("Tower A   Tower B   Tower C");
    }
    else if (max == 5)
    {
        printf("Tower A     Tower B     Tower C");
    }
    else if (max == 6)
    {
        printf("Tower A       Tower B       Tower C");
    }
    else if (max == 7)
    {
        printf("Tower A         Tower B         Tower C");
    }
    else if (max == 8)
    {
        printf("Tower A           Tower B           Tower C");
    }
    else if (max == 9)
    {
        printf("Tower A             Tower B             Tower C");
    }
}

// Prosedur memindahkan piringan dari tiang asal ke tiang tujuan
void move(char asal, char tujuan, StackInt *S1, StackInt *S2, StackInt *S3)
{
    // Deklarasi nilai dari InfoTop tiang asal
    int intAsal;

    // Check tiang asal dan PopSI Topnya
    if (asal == 'A')
    {
        PopSI(S1, &intAsal);
    }
    else if (asal == 'B')
    {
        PopSI(S2, &intAsal);
    }
    else if (asal == 'C')
    {
        PopSI(S3, &intAsal);
    }

    // Check tower tujuan dan PushSI nilai Top tiang asal
    if (tujuan == 'A')
    {
        PushSI(S1, intAsal);
    }
    else if (tujuan == 'B')
    {
        PushSI(S2, intAsal);
    }
    else if (tujuan == 'C')
    {
        PushSI(S3, intAsal);
    }
}

// Fungsi untuk check apakah suatu move legal atau tidak
boolean legalMove(char asal, char tujuan, StackInt S1, StackInt S2, StackInt S3)
{
    // Deklarasi intAsal yaitu InfoTop dari tiang asal
    int intAsal;

    // Check jika asal ialah tiang A
    if (asal == 'A')
    {
        intAsal = InfoTopSI(S1);

        // Check tiang tujuan jika asalnya tiang A
        if (tujuan == 'B')
        {
            if (IsEmptySI(S2))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S2) && !IsEmptySI(S2))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if (tujuan == 'C')
        {
            if (IsEmptySI(S3))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S3) && !IsEmptySI(S3))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }

    // Check Jika asal merupakan tiang B
    else if (asal == 'B')
    {
        intAsal = InfoTopSI(S2);

        // Check tiang tujuan
        if (tujuan == 'A')
        {
            if (IsEmptySI(S1))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S1) && !IsEmptySI(S1))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if (tujuan == 'C')
        {
            if (IsEmptySI(S3))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S3) && !IsEmptySI(S3))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }

    // Check jika tiang asal merupakan tiang C
    else if (asal == 'C')
    {
        intAsal = InfoTopSI(S3);

        // Check tiang tujuan
        if (tujuan == 'A')
        {
            if (IsEmptySI(S1))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S1) && !IsEmptySI(S1))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if (tujuan == 'B')
        {
            if (IsEmptySI(S2))
            {
                return true;
            }
            else
            {
                if (intAsal > InfoTopSI(S2) && !IsEmptySI(S2))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    else if(asal == 'G')
    {
        if(tujuan == 'G')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

// Program utama
void towerofhanoi(ArrayMap *arrSB)
{
    // Inisialisasi dan membuat tiang kosongyang mengimplementasikan ADT Stack
    StackInt S1, S2, S3;
    CreateSI(&S1);
    CreateSI(&S2);
    CreateSI(&S3);

    // Inisialialisasi jumlah turn dan jumlah piringan
    int countTurn = 0;
    char strMax[10];
    int max;

    // Untuk validasi input pengguna
    boolean isValidMax = false;
    while (!isValidMax)
    {
        printf("Silahkan masukkan banyaknya piringan : ");
        STARTWORD("","");
        max = atoi(currentWord.TabWord);
        if (max >= 1 && max <= 9 && isStrAllDigit(currentWord.TabWord))
        {
            isValidMax = true;
        }
        else
        {
            printf("Input yang valid hanya 1-9, silahkan ulangi!\n");
        }
    }

    // Inisialisasi dan deklarasi jumlah putaran minimum dan score maksimum
    int minTurn = pow(2, max) - 1;
    int score;

    // Mengisikan tiang A sebanyak max piringan
    int i = 0;
    for (i; i < max; i++)
    {
        PushSI(&S1, 2 * max - 1 - 2 * i);
    }

    // Deklarasi boolean untuk validasi input pengguna
    boolean isValid = false;
    boolean isNyerah = false;
    boolean isSalahNyerah = false;

    // Looping sampai permainan berakhir (tiang C penuh)
    while (TopSI(S3) != max - 1 && !isNyerah)
    {
        // Inisiasilasi variabel untuk menampung input asal dan tujuan
        char asal, tujuan;

        // Menampilkan tower of hanoi
        displayTOH(S1, S2, S3, max);
        printf("\n\n");

        // Melakukan validasi input pengguna
        while (!isValid)
        {
            boolean isValidAsal = false, isValidTujuan = false;

            // Validasi input asal
            while (!isValidAsal)
            {
                printf("TIANG ASAL : ");
                STARTWORD("","");
                asal = *currentWord.TabWord;
                if (asal == 'A' && currentWord.Length == 1)
                {
                    if (IsEmptySI(S1))
                    {
                        printf("Tower A kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else if (asal == 'B' && currentWord.Length == 1)
                {
                    if (IsEmptySI(S2))
                    {
                        printf("Tower B kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else if (asal == 'C' && currentWord.Length == 1)
                {
                    if (IsEmptySI(S3))
                    {
                        printf("Tower C kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else if(asal == 'G' && currentWord.Length == 1)
                {
                    printf("Jika Anda ingin menyerah, silahkan input tujuan = 'G'\n");
                    isValidAsal = true;
                }
                else
                {
                    printf("Input salah silahkan ulangi!\n");
                }
            }

            // Validasi input tiang tujuan
            while (!isValidTujuan)
            {
                printf("TIANG TUJUAN : ");
                STARTWORD("","");
                tujuan = *currentWord.TabWord;
                if (tujuan == 'A' && currentWord.Length == 1)
                {
                    if (asal == 'A')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if (IsFullSI(S1))
                    {
                        printf("Tower A penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else if (tujuan == 'B' && currentWord.Length == 1)
                {
                    if (asal == 'B')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if (IsFullSI(S2))
                    {
                        printf("Tower B penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else if (tujuan == 'C' && currentWord.Length == 1)
                {
                    if (asal == 'C')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if (IsFullSI(S3))
                    {
                        printf("Tower C penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else if(tujuan == 'G' && currentWord.Length == 1)
                {
                    if (asal == 'G')
                    {
                        isNyerah = true;
                    }
                    isValidTujuan = true;
                }
                else if(tujuan != 'G' && currentWord.Length == 1 && asal == 'G' && tujuan >= 65 && tujuan <=90) 
                {
                    isSalahNyerah = true;
                    isValidTujuan = true;
                }
                else
                {
                    printf("Input salah silahkan ulangi!\n");
                }
            }

            // Check apakah input asal dan tujuan memenuhi kriteria permainan
            if (legalMove(asal, tujuan, S1, S2, S3))
            {
                isValid = true;
            }
            else if(isSalahNyerah == true)
            {
                printf("Input salah! Jika Anda ingin menyerah pastikan input tiang tujuan dan asal = 'G'\n");
                isSalahNyerah = false;
            }
            else
            {
                printf("Tidak boleh memindahkan piringan yang lebih besar ke tower dengan piringan lebih kecil!\n");
            }
        }
        // Jika legalmove, maka akan melanjutkan permainan
        if(!isNyerah)
        {
            move(asal, tujuan, &S1, &S2, &S3);
            countTurn++;
        }

        // Untuk mengvalidasi input pengguna di putaran selanjutnya
        isValid = false;
        printf("\n");
    }

    printf("=====================================\n");
    // Hitung score berdasarkan turn
    if (countTurn == minTurn)
    {
        printf("Kamu Perfect! Dengan turn sebanyak (minimum turn): %d\n", countTurn);
        score = 10;
    }
    else if (countTurn > minTurn)
    {
        printf("Kamu Berhasil! Dengan turn sebanyak : %d\n", countTurn);
        score = 10 - 1 - (countTurn - minTurn) / 5;
    }
    else
    {
        printf("Kamu Berhasil Gagal! Dengan turn sebanyak : %d\n", countTurn);
        score = 0;
    }
    InsertSB(&arrSB->TIMap[3], score);
    printf("=====================================\n");
}