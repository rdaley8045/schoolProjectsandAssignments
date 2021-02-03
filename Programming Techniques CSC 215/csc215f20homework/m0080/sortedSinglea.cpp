#include "sortedSingle.h"

sortedSingle::sortedSingle()
{
    headptr = nullptr;
}

sortedSingle::~sortedSingle()
{
    clear();
}

bool sortedSingle::find(int item)
{
    node *temp = headptr;

    while (temp != nullptr)
    {
        if (item == temp->theItem)
            return true;
        else
            temp = temp->next;
    }

    return false; 
}

bool sortedSingle::empty()
{
    if (headptr == nullptr)
        return true;
    else
        return false;
}

int sortedSingle::size()
{
    int count=0;
    node* temp = headptr;

    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

int sortedSingle::retrievePosition(int item)
{
    
    int count = 0;
    node* temp = headptr;

    while (temp != nullptr)
    {
        count++;

        if (temp->theItem == item)
            return count;

        temp = temp->next;
    }
    
    return 0;
}