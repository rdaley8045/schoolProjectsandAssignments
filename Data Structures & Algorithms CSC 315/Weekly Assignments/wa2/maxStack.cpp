/********************************************************************//**
 * @file
 ***********************************************************************/
#include "maxStack.h"

MaxStack::MaxStack(int cap) : capacity(cap),stacksize(0)
{
   // Any initialization for your maxStack object would go here
   headptr = nullptr;
}

MaxStack::~MaxStack()
{
   node *temp = headptr;

   while (headptr != nullptr)
   {
       temp = headptr;
       headptr = headptr->next;
       delete temp;
   }
}

bool MaxStack::empty()
{
    if (headptr == nullptr)
        return true;
    else
        return false;
}

int MaxStack::size()
{
   return stacksize;
}

int MaxStack::top()
{
   return headptr->inputedNumber; 
   // you'll have to change this to return the correct boolean
}

void MaxStack::push(int item)
{
   // You will have to implement the push member function here

   node* temp, *curr;

   temp = new(nothrow) node(item,item);

   stacksize++;

   if (headptr == nullptr)
   {    
       headptr = temp;
       return;
   }

    curr = headptr;

    headptr = temp;
    temp->next = curr;

    if (temp->inputedNumber < curr->maxNumber)
        temp->maxNumber = curr-> maxNumber;

    return;


}

void MaxStack::pop()
{
   // Remove the top of the stack

   node *first;


    first = headptr;
    
    headptr = first->next;

    delete first;

    stacksize--;

    return;
}

int MaxStack::max()
{
    node *first;

    first = headptr;
   return first->maxNumber; 
   // Your code should be keeping track of the current max value
   // on the stack and you would return that here
}

ostream& operator<<(ostream &os, const MaxStack &mst)
{
   os << "MaxStack:" << endl;
   // Here you will want to output the contents of the stack to the ostream

    MaxStack  copy(mst);

    while(copy.headptr != nullptr)
    {
        os <<copy.headptr->inputedNumber << " [" << 
            copy.headptr->maxNumber<<"]\n";
        
        copy.headptr = copy.headptr->next;
    }


   return os;
}