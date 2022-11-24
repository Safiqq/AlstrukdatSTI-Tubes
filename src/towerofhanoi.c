#include <stdio.h>
#include <stdlib.h>
#include "./ADT/stackTOH/stack.h"
#include <math.h>

// Menampilkan Status Tower of Hanoi ke layar
void displayTOH(Stack S1, Stack S2, Stack S3, int max)
{
    // Deklarasi dan inisiasi constant variabel
    int baris = 0;
    int tiangA = max-lengthStack(S1);
    int tiangB = max-lengthStack(S2);
    int tiangC = max-lengthStack(S3);
    int countA = 0;
    int countB = 0;
    int countC = 0;
    
    // Looping max baris
    for(baris; baris < max; baris++)
    {
        // Awal loop untuk tiang A
        if(tiangA != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for(spaceL; spaceL < max-1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for(spaceR; spaceR < max-1; spaceR++)
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
            for(spaceL; spaceL < ((2*max - 1) - S1.T[Top(S1)-countA] )/2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for(i; i < S1.T[Top(S1)-countA]; i++)
            {
                printf("*");
            }

            // Spasi kanan
            for(spaceR; spaceR < ((2*max - 1) - S1.T[Top(S1)-countA])/2; spaceR++)
            {
                printf(" ");
            }
            countA++;
        }
        // Akhir loop untuk tiang A

        printf("   ");

        // Awal loop untuk tiang B
        if(tiangB != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for(spaceL; spaceL < max-1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for(spaceR; spaceR < max-1; spaceR++)
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
            for(spaceL; spaceL < ((2*max - 1) - S2.T[Top(S2)-countB] )/2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for(i; i < S2.T[Top(S2)-countB]; i++)
            {
                printf("*");
            }

            // Spasi
            for(spaceR; spaceR < ((2*max - 1) - S2.T[Top(S2)-countB])/2; spaceR++)
            {
                printf(" ");
            }
            countB++;
        }
        // Akhir loop untuk tiang B

        printf("   ");

        // Awal loop untuk tiang C
        if(tiangC != 0)
        {
            int spaceR = 0;
            int spaceL = 0;

            // Spasi kiri
            for(spaceL; spaceL < max-1; spaceL++)
            {
                printf(" ");
            }
            printf("|");
            // Spasi kanan
            for(spaceR; spaceR < max-1; spaceR++)
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
            for(spaceL; spaceL < ((2*max - 1) - S3.T[Top(S3)-countC] )/2; spaceL++)
            {
                printf(" ");
            }

            // Piringan
            for(i; i < S3.T[Top(S3)-countC]; i++)
            {
                printf("*");
            }

            // Spasi
            for(spaceR; spaceR < ((2*max - 1) - S3.T[Top(S3)-countC])/2; spaceR++)
            {
                printf(" ");
            }
            countC++;
        }
        printf("\n");
    }
    // Akhir baris
    int x = 0, y = 0, z = 0, a = 0, b = 0;
    for(x; x < 2*max - 1; x++)
    {
        printf("-");
    }
    for(a; a < 3; a++)
    {
        printf(" ");
    }
    for(y; y < 2*max - 1; y++)
    {
        printf("-");
    }
    for(b; b < 3; b++)
    {
        printf(" ");
    }
    for(z; z < 2*max - 1; z++)
    {
        printf("-");
    }
    printf("\n");
    if(max == 1)
    {
        printf("A   B   C");
    }
    else if(max == 2)
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
    } else if (max == 7)
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
void move(char asal, char tujuan, Stack *S1, Stack *S2, Stack *S3)
{
    // Deklarasi nilai dari InfoTop tiang asal
    int intAsal;

    // Check tiang asal dan Pop Topnya
    if(asal == 'A')
    {
        Pop(S1, &intAsal);
    }
    else if (asal == 'B')
    {
        Pop(S2, &intAsal);
        
    }
    else if (asal == 'C')
    {
        Pop(S3, &intAsal);
    }

    // Check tower tujuan dan Push nilai Top tiang asal
    if(tujuan == 'A')
    {
        Push(S1, intAsal);
    }
    else if(tujuan == 'B')
    {
        Push(S2, intAsal);
    }
    else if(tujuan == 'C')
    {
        Push(S3, intAsal);
    }
}

// Fungsi untuk check apakah suatu move legal atau tidak
boolean legalMove(char asal, char tujuan, Stack S1, Stack S2, Stack S3)
{
    // Deklarasi intAsal yaitu InfoTop dari tiang asal
    int intAsal;

    // Check jika asal ialah tiang A
    if(asal == 'A')
    {
        intAsal = InfoTop(S1);

        // Check tiang tujuan jika asalnya tiang A
        if(tujuan == 'B')
        {
            if(IsEmpty(S2))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S2) && !IsEmpty(S2))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if(tujuan == 'C')
        {
            if(IsEmpty(S3))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S3) && !IsEmpty(S3))
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
    else if(asal == 'B')
    {
        intAsal = InfoTop(S2);

        // Check tiang tujuan
        if(tujuan == 'A')
        {
            if(IsEmpty(S1))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S1) && !IsEmpty(S1))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if(tujuan == 'C')
        {
            if(IsEmpty(S3))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S3) && !IsEmpty(S3))
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
    else if(asal == 'C')
    {
        intAsal = InfoTop(S3);

        // Check tiang tujuan
        if(tujuan == 'A')
        {
            if(IsEmpty(S1))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S1) && !IsEmpty(S1))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
        else if(tujuan == 'B')
        {
            if(IsEmpty(S2))
            {
                return true;
            }
            else
            {
                if(intAsal > InfoTop(S2) && !IsEmpty(S2))
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
}

// Program utama
void towerofhanoi()
{
    // Inisialisasi dan membuat tiang kosongyang mengimplementasikan ADT Stack
    Stack S1, S2, S3;
    CreateEmpty(&S1);
    CreateEmpty(&S2);
    CreateEmpty(&S3);

    // Inisialialisasi jumlah turn dan jumlah piringan
    int countTurn = 0;
    char strMax[10];
    int max;

    // Untuk validasi input pengguna
    boolean isValidMax = false;
    while(!isValidMax)
    {
        printf("Silahkan masukkan banyaknya piringan : ");
        scanf("%s", &strMax);
        max = atoi(strMax);
        if(max >= 1 && max <= 9)
        {
            isValidMax = true;
        }
        else
        {
            printf("Input yang valid hanya 1-9, silahkan ulangi!\n");
        }
    }

    // Inisialisasi dan deklarasi jumlah putaran minimum dan score maksimum
    int minTurn = pow(2,max)-1;
    int score;

    // Mengisikan tiang A sebanyak max piringan
    int i = 0;
    for(i; i < max; i++)
    {
        Push(&S1, 2*max - 1 - 2*i);
    }

    // Deklarasi boolean untuk validasi input pengguna
    boolean isValid = false;

    // Looping sampai permainan berakhir (tiang C penuh)
    while(Top(S3) != max-1)
    {
        // Inisiasilasi variabel untuk menampung input asal dan tujuan
        char asal, tujuan;

        // Menampilkan tower of hanoi
        displayTOH(S1, S2, S3, max);
        printf("\n\n");

        // Melakukan validasi input pengguna
        while(!isValid)
        {
            boolean isValidAsal = false, isValidTujuan = false;

            // Validasi input asal
            while(!isValidAsal)
            {
                printf("TIANG ASAL : ");
                scanf("\n%c", &asal);
                if(asal == 'A')
                {
                    if(IsEmpty(S1))
                    {
                        printf("Tower A kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else if (asal == 'B')
                {
                    if(IsEmpty(S2))
                    {
                        printf("Tower B kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else if (asal == 'C')
                {
                    if(IsEmpty(S3))
                    {
                        printf("Tower C kosong! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidAsal = true;
                    }
                }
                else
                {
                    printf("Tidak ada Tower %c, silahkan ulangi!\n", asal);
                }
                
            }

            // Validasi input tiang tujuan
            while(!isValidTujuan)
            {
                printf("TIANG TUJUAN : ");
                scanf("\n%c", &tujuan);
                if(tujuan == 'A')
                {
                    if(asal == 'A')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if(IsFull(S1))
                    {
                        printf("Tower A penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else if (tujuan == 'B')
                {
                    if(asal == 'B')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if(IsFull(S2))
                    {
                        printf("Tower B penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else if (tujuan == 'C')
                {
                    if(asal == 'C')
                    {
                        printf("Tidak boleh memindahkan piringan dari tiang asal dan tujuan yang sama!\n");
                    }
                    else if(IsFull(S3))
                    {
                        printf("Tower C penuh! Silahkan ulangi\n");
                    }
                    else
                    {
                        isValidTujuan = true;
                    }
                }
                else
                {
                    printf("Tidak ada Tower %c, silahkan ulangi!\n", tujuan);
                }  
            }

            // Check apakah input asal dan tujuan memenuhi kriteria permainan
            if(legalMove(asal, tujuan, S1, S2, S3))
            {
                isValid = true;   
            }
            else
            {
                printf("Tidak boleh memindahkan piringan yang lebih besar ke tower dengan piringan lebih kecil!\n");
            }
        }
        // Jika legalmove, maka akan melanjutkan permainan
        move(asal, tujuan, &S1, &S2, &S3);
        countTurn++;

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
    else if(countTurn > minTurn)
    {
        printf("Kamu Berhasil! Dengan turn sebanyak : %d\n", countTurn);
        score = 10 -1 -(countTurn - minTurn)/5;
    }
    printf("Skor didapatkan : %d\n", score);
    printf("=====================================\n");
}