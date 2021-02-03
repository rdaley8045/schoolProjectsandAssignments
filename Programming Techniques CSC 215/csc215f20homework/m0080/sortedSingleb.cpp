#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
    node* temp, * curr, * prev;

    temp = new (nothrow) node;

    if (temp == nullptr)
        return false;

    temp->theItem = item;
    temp->next = nullptr;

    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }
    curr = headptr;
    if (curr->theItem >= temp->theItem)
    {
        temp->next = headptr;
        headptr = temp;
        return true;
    }


    curr = headptr;
    prev = headptr;
    while (curr != nullptr && curr->theItem <= temp ->theItem)
    {
    
        prev = curr;
        curr = curr->next;
    }

    prev->next = temp;
    temp->next = curr;

    return true;
}


void sortedSingle::print(ostream& out, string seperator)
{
    node* temp;
    temp = headptr;

    while (temp != nullptr)
    {
        out << temp->theItem;
        if (temp -> next != nullptr)
            out << seperator;
        temp = temp->next;
    }
}
