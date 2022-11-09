#include "queue.h"

void CreateQueueDS(QueueDS *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
};

boolean IsEmptyQueueDS(QueueDS q)
{
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
};

boolean IsFullQueueDS(QueueDS q)
{
    if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) == CAPACITY - 1);
    else
        return (IDX_HEAD(q) - IDX_TAIL(q) == 1);
};

int LengthQueueDS(QueueDS q)
{
    if (IsEmptyQueueDS(q))
        return 0;
    else if (IDX_TAIL(q) >= IDX_HEAD(q))
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    else
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY + 1);
}

void EnqueueDS(QueueDS *q, ElTypeDS val)
{
    if (IsEmptyQueueDS(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
    TAIL(*q) = val;
}

void DequeueDS(QueueDS *q, ElTypeDS *val)
{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
}
