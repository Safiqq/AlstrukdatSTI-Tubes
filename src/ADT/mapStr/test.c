#include "mapStr.h"

int main()
{
    MapStr M;
    CreateMS(&M);
    InsertMS(&M, "BNMO", 10);
    InsertMS(&M, "JAKE", 30);
    printf("%d\n", iMax(M));
    DeleteMS(&M, "BNMO");
    printf("%d\n", IsMemberMS(M, "BNMO"));
    printf("%d\n", IsMemberMS(M, "JAKE"));
    printf("%d", ValueMS(M, "JAKE"));
    printf("%d\n", IsFullMS(M));
    printf("%d\n", IsEmptyMS(M));
    return 0;
}