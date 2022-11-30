#include "../header/dinerdash.h"

// FUNGSI DAN PROSEDUR UNTUK DINERDASH

// Menghasilkan angka random range min-max
int getRandom(int min, int max)
{
    return ((rand() % max) + min);
}

// Menampilkan saldo ke layar
void tampilSaldo(int saldo)
{
    printf("\nSALDO: %d\n\n", saldo);
}

// Menampilkan order ke layar
void tampilPesanan(QueueDS Q, int count)
{
    int i;
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi memasak |  Ketahanan\t|  Harga\n");
    printf("--------------------------------------------------\n");
    for (i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++)
    {
        printf("M%d\t|\t%d\t |\t%d\t|  %d\n", i, Q.buffer[i].timeC, Q.buffer[i].timeK, Q.buffer[i].price);
    }
    printf("\n");
}

// Menampilkan makanan yang sedang dimasak ke layar
void tampilMasak(Map M, int count)
{
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("---------------------------------\n");
    if (count == 0)
    {
        printf("\t|");
    }
    else
    {
        int i;
        for (i = 0; i < count; i++)
        {
            printf("M%d\t|\t%d\n", M.Elements[i].Key, M.Elements[i].ValueMS);
        }
    }
    printf("\n\n");
}

// Menampilkan makanan yang dapat disajikan ke layar
void tampilSaji(Map M, int count)
{
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("---------------------------------\n");
    if (count == 0)
    {
        printf("\t|");
    }
    else
    {
        int i;
        for (i = 0; i < count; i++)
        {
            printf("M%d\t|\t%d\n", M.Elements[i].Key, M.Elements[i].ValueMS);
        }
    }
    printf("\n\n\n");
}

// Menghasilkan order random
void enqOrder(QueueDS *q)
{
    ElTypeDS order;
    order.timeC = getRandom(1, 5);
    order.timeK = getRandom(1, 5);
    order.price = getRandom(10000, 50000);
    EnqueueDS(q, order);
}

// Mengubah string ke integer
int strToInt(char *str)
{
    int i = 1, sum = 0;

    while (str[i] != '\0')
    {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
            sum = sum * 10 + str[i] - '0';
        i++;
    }

    return sum;
}

// Mengurangkan ValueMS dari Map Masak dan Saji tiap putaran
void tickValue(Map *M)
{
    int i;
    for (i = 0; i < (*M).Count; i++)
    {
        if ((*M).Elements[i].ValueMS > 0)
        {
            (*M).Elements[i].ValueMS--;
        }
    }
}

// Delete makanan dari Map Masak lalu Insert ke Map Saji
void cookToServe(Map *Masak, keytype k, Map *Saji, QueueDS Q)
{
    InsertMI(Saji, k, Q.buffer[k].timeK);
    DeleteMI(Masak, k);
    printf("\nMakanan M%d telah selesai dimasak\n", k);
}

// Menghasilkan Map terurut berdasarkan valuenya menaik
void sortedMap(Map *M)
{
    // Bubble sort
    int count = (*M).Count, i, j;
    for (i = 1; i < count; i++)
    {
        for (j = 0; j < count - 1; j++)
        {
            if ((*M).Elements[j].ValueMS > (*M).Elements[j + 1].ValueMS)
            {
                infotype temp = (*M).Elements[j];
                (*M).Elements[j] = (*M).Elements[j + 1];
                (*M).Elements[j + 1] = temp;
            }
        }
    }
}

// Check apakah Map sudah tersort menaik
boolean isSorted(Map M, int n)
{
    // Basis
    if (n == 1 || n == 0)
        return true;

    // Kalau belum kesort, return false
    if (M.Elements[n - 1].ValueMS < M.Elements[n - 2].ValueMS)
        return false;

    // Rekurens
    return isSorted(M, n - 1);
}

void dinerdash(ArrayMap *arrSB)
{
    // Deklarasi Variabel bertipe integer
    int saldo = 0;
    int totalSaji = 0;
    int i;

    // Deklarasi String
    char *inp;

    // Deklarasi ADT
    QueueDS Q;
    Map Masak;
    Map Saji;

    // Deklarasi Variabel bertipe boolean
    boolean isValid = false;
    boolean flag = false;
    boolean isSkip = false;

    // Membuat Queue order kosong, Map Masak kosong, Map Saji kosong
    CreateQDS(&Q);
    CreateMI(&Masak);
    CreateMI(&Saji);

    // Membuat 3 order pertama sesuai pada deskripsi yang diberikan
    for (i = 0; i < 3; i++)
    {
        enqOrder(&Q);
    }

    // Program Utama
    printf("\nSelamat Datang di Diner Dash!\n\n");

    while (LengthQDS(Q) <= 7 && totalSaji < 15)
    {
        // Menampilkan ke layar
        tampilSaldo(saldo);
        tampilPesanan(Q, LengthQDS(Q));
        while (!(isSorted(Masak, Masak.Count)))
        {
            sortedMap(&Masak); // Sorting Map Masak agar lebih mudah dipindahkan ke Map Saji jika sudah dimasak
        }
        while (!(isSorted(Saji, Saji.Count)))
        {
            sortedMap(&Saji); // Sorting Map Saji agar lebih mudah dihapus jika waktu ketahanan habis
        }
        tampilMasak(Masak, Masak.Count);
        tampilSaji(Saji, Saji.Count);

        // Melakukan validasi input command
        while (!isValid)
        {
            printf("MASUKKAN COMMAND: ");
            STARTWORD("", "");
            if (IsEqual(currentWord, "COOK") || IsEqual(currentWord, "cook"))
            {
                inp = (char *)malloc(sizeof(char) * 10);
                inp[0] = 'C';
                inp[1] = 'O';
                inp[2] = 'O';
                inp[3] = 'K';
                inp[4] = '\0';
                ADVWORD();
                if (strToInt(currentWord.TabWord) <= IDX_TAIL(Q) && strToInt(currentWord.TabWord) >= IDX_HEAD(Q) && currentWord.TabWord[0] == 'M')
                {
                    isValid = true;
                }
                else
                {
                    printf("M%d tidak ada pada daftar! Silahkan ulangi\n", strToInt(currentWord.TabWord));
                }
            }
            else if (IsEqual(currentWord, "SERVE") || IsEqual(currentWord, "serve"))
            {
                inp = (char *)malloc(sizeof(char) * 10);
                inp[0] = 'S';
                inp[1] = 'E';
                inp[2] = 'R';
                inp[3] = 'V';
                inp[4] = 'E';
                inp[5] = '\0';
                ADVWORD();
                if (IsMemberMI(Saji, strToInt(currentWord.TabWord)) && strToInt(currentWord.TabWord) == IDX_HEAD(Q))
                {
                    isValid = true;
                }
                else if (IsMemberMI(Saji, strToInt(currentWord.TabWord)) && strToInt(currentWord.TabWord) != IDX_HEAD(Q))
                {
                    printf("M%d belum dapat disajikan karena M%d belum disajikan. Silahkan ulangi!\n", strToInt(currentWord.TabWord), IDX_HEAD(Q));
                }
                else
                {
                    printf("M%d belum dapat disajikan! Silahkan ulangi\n", strToInt(currentWord.TabWord));
                }
            }
            else if (IsEqual(currentWord, "SKIP") || IsEqual(currentWord, "skip"))
            {
                isValid = true;
                isSkip = true;
                printf("Putaran telah dilewati tanpa melakukan apa-apa\n");
            }
            else
            {
                printf("Input salah! Silahkan ulangi\n");
            }
        }

        // Check apakah ada daftar makanan yang sudah dapat disajikan
        if (Saji.Count > 0)
        {
            // Tiap putaran akan mengurangi waktu ketahanan
            tickValue(&Saji);
        }

        // Check apakah ada daftar makanan yang sedang dimasak
        if (Masak.Count > 0)
        {
            // Tiap putaran akan mengurangi waktu memasak
            tickValue(&Masak);
            // Menghapus dari Map Masak dan memindahkan ke Map Saji jika sudah selesai dimasak
            while (Masak.Elements[0].ValueMS == 0 && Masak.Count > 0)
            {
                cookToServe(&Masak, Masak.Elements[0].Key, &Saji, Q);
            }
        }

        if (!isSkip)
        {
            // Jika command = "COOK" maka akan memasak makanan dengan id dari input user
            if (inp[0] == 'C' || inp[0] == 'c')
            // if (IsEqual(currentWord, "COOK") || IsEqual(currentWord, "cook"))
            {
                keytype k = strToInt(currentWord.TabWord);
                valuetype v = Q.buffer[k].timeC;
                InsertMI(&Masak, k, v);
                printf("\nBerhasil memasak M%d\n", k);
            }
            // Jika command = "SERVE" maka akan menyajikan makanan dengan id dari input user
            if (inp[0] == 'S' || inp[0] == 's' && (inp[1] == 'E' || inp[1] == 'e'))
            // if (IsEqual(currentWord, "SERVE") || IsEqual(currentWord, "serve"))
            {
                // Check apakah makanan yang akan disajikan merupakan IDX_HEAD dari Queue order
                if (strToInt(currentWord.TabWord) == IDX_HEAD(Q))
                {
                    int z;
                    for (z = 0; z < Saji.Count; z++)
                    {
                        if (strToInt(currentWord.TabWord) == Saji.Elements[z].Key)
                        { // Jika ada maka sajikan makanannya
                            DeleteMI(&Saji, Saji.Elements[z].Key);
                            ElTypeDS val;
                            saldo += Q.buffer[IDX_HEAD(Q)].price;
                            totalSaji += 1;
                            DequeueDS(&Q, &val);
                        }
                    }
                    printf("\nBerhasil mengantar M%d\n", strToInt(currentWord.TabWord));
                }
                else
                { // Jika tidak maka akan menampilkan pesan belum dapat disajikan
                    printf("\nM%d belum dapat disajikan karena M%d belum selesai\n", strToInt(currentWord.TabWord), IDX_HEAD(Q));
                }
            }
        }

        // Check saji lebih dari 0
        if (Saji.Count > 0)
        {
            // Menghapus dari Map Saji jika waktu ketahanan = 0
            while (Saji.Elements[0].ValueMS == 0 && Saji.Count > 0)
            {
                printf("M%d telah expired, silahkan masak kembali!\n", Saji.Elements[0].Key);
                DeleteMI(&Saji, Saji.Elements[0].Key);
            }
        }

        // Tiap putaran maka order akan bertambah
        enqOrder(&Q);

        // Mengupdate kondisi untuk validasi input command putaran selanjutnya
        isValid = false;
        flag = false;
        isSkip = false;

        printf("==========================================================\n");
    }
    printf("Game berakhir dan score Anda : %d\n", saldo);
    InsertSB(&arrSB->TIMap[1], saldo);
    printf("==========================================================\n\n");
}