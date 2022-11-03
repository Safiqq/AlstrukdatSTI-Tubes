#include <stdio.h>

void help(){
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|\tNo.\t|\tCommand\t\t\t|\t\t\tDeskripsi\t\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
    printf("|\t1\t|\tSTART\t\t\t|\tUntuk memulai aplikasi BNMO\t\t\t\t|\n");
    printf("|\t2\t|\tLOAD <filename>\t\t|\tUntuk membuka file data yang pernah disimpan\t\t|\n");
    printf("|\t3\t|\tSAVE <filename>\t\t|\tUntuk menyimpan state game saat ini ke dalam file\t|\n");
    printf("|\t4\t|\tCREATEGAME\t\t|\tUntuk menambahkan game baru pada daftar game\t\t|\n");
    printf("|\t5\t|\tLISTGAME\t\t|\tUntuk menampilkan daftar game yang tersedia\t\t|\n");
    printf("|\t6\t|\tDELETEGAME\t\t|\tUntuk menghapus sebuah game dari daftar game\t\t|\n");
    printf("|\t7\t|\tQUEUEGAME\t\t|\tUntuk mendaftarkan game kedalam list game\t\t|\n");
    printf("|\t8\t|\tPLAYGAME\t\t|\tUntuk memainkan sebuah permainan pada list game\t\t|\n");
    printf("|\t9\t|\tSKIPGAME <n>\t\t|\tUntuk melewatkan game pada list game sebanyak n\t\t|\n");
    printf("|\t10\t|\tQUIT\t\t\t|\tUntuk keluar dari program\t\t\t\t|\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}