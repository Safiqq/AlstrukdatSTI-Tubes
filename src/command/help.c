#include <stdio.h>
#include "../header/boolean.h"

void help(boolean isLogged)
{
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("|\tNo.\t|\tCommand\t\t\t\t|\t\t\tDeskripsi\t\t\t\t|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
    printf("|\t1\t|\tSTART\t\t\t\t|\tUntuk memulai aplikasi BNMO\t\t\t\t|\n");
    printf("|\t2\t|\tLOAD <filename>\t\t\t|\tUntuk membuka file data yang pernah disimpan\t\t|\n");
    if (isLogged)
    {
        printf("|\t3\t|\tSAVE <filename>\t\t\t|\tUntuk menyimpan state game saat ini ke dalam file\t|\n");
        printf("|\t4\t|\tCREATE GAME\t\t\t|\tUntuk menambahkan game baru pada daftar game\t\t|\n");
        printf("|\t5\t|\tLIST GAME\t\t\t|\tUntuk menampilkan daftar game yang tersedia\t\t|\n");
        printf("|\t6\t|\tDELETE GAME\t\t\t|\tUntuk menghapus sebuah game dari daftar game\t\t|\n");
        printf("|\t7\t|\tQUEUE GAME\t\t\t|\tUntuk mendaftarkan game kedalam list game\t\t|\n");
        printf("|\t8\t|\tPLAY GAME\t\t\t|\tUntuk memainkan sebuah permainan pada list game\t\t|\n");
        printf("|\t9\t|\tSKIP GAME <n>\t\t\t|\tUntuk melewatkan game pada list game sebanyak n\t\t|\n");
        printf("|\t10\t|\tSCOREBOARD\t\t\t|\tUntuk menampilkan scoreboard tiap game\t\t\t|\n");
        printf("|\t11\t|\tRESET SCOREBOARD\t\t|\tUntuk menghapus scoreboard game tertentu\t\t|\n");
        printf("|\t12\t|\tHISTORY <n>\t\t\t|\tUntuk melihat riwayat game yang dimainkan sejumlah n\t|\n");
        printf("|\t13\t|\tRESET HISTORY\t\t\t|\tUntuk menghapus riwayat permainan\t\t\t|\n");
    }
    printf("|\t%d\t|\tQUIT\t\t\t\t|\tUntuk keluar dari program\t\t\t\t|\n", isLogged ? 14 : 3);
    printf("-------------------------------------------------------------------------------------------------------------------------\n");
}