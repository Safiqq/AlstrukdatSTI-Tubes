#include <stdio.h>
#include "queue.h"

void CreateQueueDS(QueueDS *q){
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
};

boolean isEmptyDS(QueueDS q){
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
};

boolean isFullDS(QueueDS q){
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
    else
        return (IDX_HEAD(q) - IDX_TAIL(q) == 1);
};

int lengthDS(QueueDS q)
{
    if (isEmptyDS(q)) 
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    else
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1);
}

void enqueueDS(QueueDS *q, ElType val)
{
    if (isEmptyDS(*q)){
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else{
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    }
    TAIL(*q) = val;
}

void dequeueDS(QueueDS *q, ElType *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
    }
}

void displayQueueDS(QueueDS q){
    if(lengthDS(q) == 0){
        printf("[]\n");
    }
    else{
        int i = 0;
        printf("[");
        for(i; i<= lengthDS(q) - 1; i++){
            printf("%d", q.buffer[(i+IDX_HEAD(q))%CAPACITY]);
            if (i <= lengthDS(q)- 2){
                printf(",");
            }
        }
        printf("]\n");
    }
};
