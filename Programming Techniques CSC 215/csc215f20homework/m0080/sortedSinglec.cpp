#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node* temp, * curr, * prev;
    int position, count = 1;
    
    position = retrievePosition(item);

    if (headptr == nullptr)
        return false;

    curr = headptr;
    if (curr->theItem == item)
    {
        temp = headptr;
        headptr = temp->next;
        delete temp;
        return true;
    }

    curr = headptr;
    prev = headptr;

    while (curr != nullptr && count != position)
    {
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr || count != position)
        return false;

    prev->next = curr->next;
    delete curr;

    return true;
}


void sortedSingle::clear()
{
    node* temp = headptr;

    while (headptr != nullptr)
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr;
    }
}