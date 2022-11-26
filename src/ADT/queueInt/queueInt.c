#include "queueInt.h"

void CreateQI(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean IsEmptyQI(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

int LengthQI(Queue q)
{
    if (IsEmptyQI(q))
        return 0;
    else
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void EnqueueI(Queue *q, ElTypeQue val)
{
    if (IsEmptyQI(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q)
        ++;
    }
    TAIL(*q) = val;
}

void DequeueI(Queue *q, ElTypeQue *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        int i;
        for (i = 0; i < IDX_TAIL(*q); i++)
            (*q).buffer[i] = (*q).buffer[i + 1];
        IDX_TAIL(*q) = IDX_TAIL(*q) - 1;
    }
}

void DisplayQI(Queue q)
{
    int i, len = LengthQI(q);
    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d", q.buffer[(i + IDX_HEAD(q)) % CAPACITY]);
        if (i < (len - 1))
            printf(",");
    }
    printf("]\n");
}
