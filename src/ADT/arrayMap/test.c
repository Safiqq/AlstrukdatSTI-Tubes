#include "arrayMap.h"
#include <stdio.h>

int main(){
    ArrayMap arrm;
    CreateAM(&arrm);
    printf("%d",NbElmtAM(arrm));
    InsertLastAM(&arrm);
    printf("%d",NbElmtAM(arrm));
    DeleteAtAM(&arrm,3);
    printf("%d",NbElmtAM(arrm));
}
