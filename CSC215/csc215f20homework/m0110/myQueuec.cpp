/** ***************************************************************************
 * @file
 *
 * @brief   Implements my Queue classes copy constructor.
 *****************************************************************************/
#include "myQueue.h"


/** ***************************************************************************
 * @brief   Copy from one Queue to another at instantiation time.
 *
 * @param [in,out]  q   A Queue to be duplicate.
 *****************************************************************************/
Queue::Queue( Queue &q )
{
    node* src, * dest ;

    headptr = nullptr;
    tailptr = nullptr;

    if (q.headptr == nullptr)
        return;

    headptr = new(nothrow)node;
    if (headptr == nullptr)
        exit(0);
    headptr->item = q.headptr->item;
    headptr->next = nullptr;
    tailptr = headptr;

    src = q.headptr->next;
    dest = headptr;

    while (src != nullptr)
    {
        dest->next = new(nothrow)node;
        if (dest == nullptr)
            exit(0);
        dest = dest->next;
        dest->item = src->item;
        dest->next = nullptr;
        src = src->next;
        tailptr = dest;
    }
    return;
}


