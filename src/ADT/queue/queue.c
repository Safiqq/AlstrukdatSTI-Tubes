#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean IsEmptyQueue(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean IsFullQueue(Queue q)
{
    return IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1;
}

int LengthQueue(Queue q)
{
    if (IsEmptyQueue(q))
        return 0;
    else
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
}

void Enqueue(Queue *q, ElTypeQue val)
{
    if (IsEmptyQueue(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        IDX_TAIL(*q)++;
    }
    TAIL(*q) = val;
}

void Dequeue(Queue *q, ElTypeQue *val)
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

void DisplayQueue(Queue q)
{
    int i, len = LengthQueue(q);
    printf("[");
    for (i = 0; i < len; i++)
    {
        printf("%d", q.buffer[(i + IDX_HEAD(q)) % CAPACITY]);
        if (i < (len - 1))
            printf(",");
    }
    printf("]\n");
}