#include <stdio.h>
#include <stdlib.h>
#include "ADT/queueDS/queue.h"
#include "ADT/map/map.h"

// FUNGSI DAN PROSEDUR UNTUK DINERDASH

// Menghasilkan angka random range min-max
int getRandom(int min, int max){
    return ((rand()%max) + min);
}

// Menampilkan saldo ke layar
void tampilSaldo(int saldo){
    printf("SALDO: %d\n\n", saldo);
}

// Menampilkan order ke layar
void tampilPesanan(QueueDS Q, int count){
    int i;
    printf("Daftar Pesanan\n");
    printf("Makanan\t| Durasi memasak |  Ketahanan\t|  Harga\n");
    printf("--------------------------------------------------\n");
    for(i = IDX_HEAD(Q); i <= IDX_TAIL(Q); i++){
        printf("M%d\t|\t%d\t |\t%d\t|  %d\n", i, Q.buffer[i].timeC, Q.buffer[i].timeK, Q.buffer[i].price);
    }
    printf("\n");
}

// Menampilkan makanan yang sedang dimasak ke layar
void tampilMasak(Map M, address count){
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan\t| Sisa durasi memasak\n");
    printf("---------------------------------\n");
    if(count == 0){
        printf("\t|");
    }
    else{
        int i;
        for(i = 0; i < count; i++){
            printf("M%d\t|\t%d\n", M.Elements[i].Key, M.Elements[i].Value);
        }
    }
    printf("\n\n");
}

// Menampilkan makanan yang dapat disajikan ke layar
void tampilSaji(Map M, address count){
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan\t| Sisa ketahanan makanan\n");
    printf("---------------------------------\n");
    if(count == 0){
        printf("\t|");
    }
    else{
        int i;
        for(i = 0; i < count; i++){
        printf("M%d\t|\t%d\n", M.Elements[i].Key, M.Elements[i].Value);
        }
    }
    printf("\n\n\n");
}

// Menghasilkan order random
void enqOrder(QueueDS*q){
    ElType order;
    order.timeC = getRandom(1,5);
    order.timeK = getRandom(1,5);
    order.price = getRandom(10000,50000);
    enqueueDS(q,order);
}

// Check kedua string apakah sama
boolean checkSame(char *str1, char *str2, int len){
    int i = 0;
    while (i < len){
        if(str1[i] != str2[i]){
            return false;
        }
        i++;
    }
    return true;
}

// Mengubah string ke integer
int strToInt(char*str){
    int i, sum = 0;

    for(i = 1; i<3;i++){
        if(str[i]-'0' >= 0 && str[i]-'0' <=99){
            sum = sum*10 + (str[i] - '0');
        }
    }
    return sum;
}

// Mengurangkan value dari Map Masak dan Saji tiap putaran
void tickValue(Map*M){
    int i;
    for(i = 0; i<(*M).Count; i++){
        if((*M).Elements[i].Value >0){
            (*M).Elements[i].Value--;
        }
    }
}

// Delete makanan dari Map Masak lalu Insert ke Map Saji
void cookToServe(Map*Masak, keytype k, Map*Saji, QueueDS Q){
    Insert(Saji, k, Q.buffer[k].timeK);
    Delete(Masak, k);
    printf("\nMakanan M%d telah selesai dimasak\n", k);
}

// Menghasilkan Map terurut berdasarkan valuenya menaik
void sortedMap(Map *M){
    // Bubble sort
    int count = (*M).Count, i, j;
    for(i =1; i < count; i++){
        for(j = 0; j < count - 1; j++){
            if((*M).Elements[j].Value > (*M).Elements[j+1].Value){
                infotype temp = (*M).Elements[j];
                (*M).Elements[j] = (*M).Elements[j+1];
                (*M).Elements[j+1] = temp;
            }
        }
    }
}

void dinerdash(){
    // Deklarasi Variabel bertipe integer
    int saldo = 0;
    int totalSaji = 0;
    int i;

    // Deklarasi ADT
    QueueDS Q;
    Map Masak;
    Map Saji;

    // Deklarasi Variabel bertipe string
    char cmd[6];
    char icmd[4];

    // Deklarasi Variabel bertipe boolean
    boolean isValid = false;
    boolean flag = false;

    // Membuat Queue order kosong, Map Masak kosong, Map Saji kosong
    CreateQueueDS(&Q);
    CreateEmptyDS(&Masak);
    CreateEmptyDS(&Saji);

    // Membuat 3 order pertama sesuai pada deskripsi yang diberikan
    for(i = 0; i < 3; i++){
        enqOrder(&Q);
    }

    // Program Utama
    printf("\nSelamat Datang di Diner Dash!\n\n");

    while(lengthDS(Q) <= 7 &&  totalSaji < 15){
        // Menampilkan ke layar
        tampilSaldo(saldo);
        tampilPesanan(Q, lengthDS(Q));
        sortedMap(&Masak);   // Sorting Map Masak agar lebih mudah dipindahkan ke Map Saji jika sudah dimasak
        sortedMap(&Saji);   // Sorting Map Saji agar lebih mudah dihapus jika waktu ketahanan habis
        tampilMasak(Masak, Masak.Count);
        tampilSaji(Saji, Saji.Count);

        // Melakukan validasi input command
        while(!isValid){
            printf("\nMASUKKAN COMMAND: ");
            scanf("%s", &cmd);
            if(checkSame(cmd, "COOK", 4) || checkSame(cmd, "cook", 4)){
                scanf("%s", &icmd);
                if(strToInt(icmd) <= IDX_TAIL(Q) && icmd[0] == 'M'){
                    isValid = true;
                }
                else{
                    printf("M%d tidak ada pada daftar! Silahkan ulangi\n", strToInt(icmd));
                }
            }
            else if(checkSame(cmd, "SERVE",5) || checkSame(cmd, "serve",5)){
                scanf("%s", &icmd);
                if(IsMember(Saji,strToInt(icmd))){
                    isValid = true;
                }
                else{
                    printf("M%d belum dapat disajikan! Silahkan ulangi\n", strToInt(icmd));
                }
            }
            else if(checkSame(cmd, "SKIP",4) || checkSame(cmd, "skip", 4)){
                isValid  = true;
                printf("Putaran telah dilewati tanpa melakukan apa-apa\n");
            }
            else{
                printf("Input salah! Silahkan ulangi\n");
            }
        }

        // Check apakah ada daftar makanan yang sudah dapat disajikan
        if(Saji.Count>0){
            // Tiap putaran akan mengurangi waktu ketahanan
            tickValue(&Saji);
            // Menghapus dari Map Saji jika waktu ketahanan = 0
            while(Masak.Elements[0].Value == 0 && Masak.Count > 0){
                Delete(&Saji, Saji.Elements[0].Key);
            }
        }
        
        // Check apakah ada daftar makanan yang sedang dimasak
        if(Masak.Count >0){
            // Tiap putaran akan mengurangi waktu memasak
            tickValue(&Masak);
            // Menghapus dari Map Masak dan memindahkan ke Map Saji jika sudah selesai dimasak
            while(Masak.Elements[0].Value == 0 && Masak.Count > 0){
                cookToServe(&Masak, Masak.Elements[0].Key, &Saji, Q);
            }
        }

        // Jika command = "COOK" maka akan memasak makanan dengan id dari input user
        if(checkSame(cmd, "COOK", 4) || checkSame(cmd, "cook", 4)){
            keytype k = strToInt(icmd);
            valuetype v = Q.buffer[k].timeC;
            Insert(&Masak,k,v);
            printf("\nBerhasil memasak M%d\n", k);
        }
        // Jika command = "SERVE" maka akan menyajikan makanan dengan id dari input user
        if(checkSame(cmd, "SERVE",5) || checkSame(cmd, "serve",5)){
            // Check apakah makanan yang akan disajikan merupakan IDX_HEAD dari Queue order
            if (strToInt(icmd) == IDX_HEAD(Q)){
                int z;
                for (z = 0; z < Saji.Count; z++){
                    if(strToInt(icmd) == Saji.Elements[z].Key){  // Jika ada maka sajikan makanannya
                        Delete(&Saji, Saji.Elements[z].Key);
                        ElType val;
                        saldo += Q.buffer[IDX_HEAD(Q)].price;
                        totalSaji+=1;
                        dequeueDS(&Q,&val);
                    }
                }
                printf("\nBerhasil mengantar M%d\n", strToInt(icmd));
            }
            else{  // Jika tidak maka akan menampilkan pesan belum dapat disajikan
                printf("\nM%d belum dapat disajikan karena M%d belum selesai\n", strToInt(icmd), IDX_HEAD(Q));
            }
        }
       
       // Tiap putaran maka order akan bertambah
        enqOrder(&Q);

        // Mengupdate kondisi untuk validasi input command putaran selanjutnya
        isValid = false;
        flag = false;

        printf("==========================================================\n\n");
    }
}