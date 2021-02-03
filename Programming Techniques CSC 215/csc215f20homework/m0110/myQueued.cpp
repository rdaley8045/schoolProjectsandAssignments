/** ***************************************************************************
 * @file
 *
 * @brief   Implements my Queue classes opertors.
 *****************************************************************************/
#include "myQueue.h"

Queue &Queue::operator = (Queue &q)
{
  
    if (this != nullptr)
        clear();

    if (*this == q)
        return *this;


    Queue q2(q);
    swap(q2);
    return *this;
}

bool Queue::operator == (Queue& rhs)
{
    node* src1, * src2;

    if (size() != rhs.size())
        return false;

    src1 = headptr;
    src2 = rhs.headptr;

    while (src1 != nullptr && src1->item == src2->item)
    {
        src1 = src1->next;
        src2 = src2->next;
    }

    if (src1 != nullptr)
        return false;

    else
        return true;
}

bool Queue:: operator != (Queue& rhs)
{
    node* src1, * src2;

    if (size() != rhs.size())
        return true;

    src1 = headptr;
    src2 = rhs.headptr;

    while (src1 != nullptr && src1->item == src2->item)
    {
        src1 = src1->next;
        src2 = src2->next;
    }

    if (src1 != nullptr)
        return true;

    else
        return false;
}
