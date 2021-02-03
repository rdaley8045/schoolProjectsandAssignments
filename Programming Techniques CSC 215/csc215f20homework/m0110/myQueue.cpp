/** ***************************************************************************
 * @file    
 *
 * @brief   Implements my queue class, Contains code for the constructor, 
 *          destructor, size, empty, clear and swap.
 *****************************************************************************/
  
#include "myQueue.h"


/** ***************************************************************************
 * @brief   Default constructor
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *****************************************************************************/
Queue::Queue( )
{
    headptr = nullptr;
    tailptr = nullptr;
}


/** ***************************************************************************
 * @brief   Destructor
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *****************************************************************************/
Queue::~Queue( )
{
    clear( );
}


/** ***************************************************************************
 * @brief   Gets the number of items in the queue
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *
 * @returns The number of items in the queue 
 *****************************************************************************/
int Queue::size( )
{
    int count = 0;
    node *temp = headptr;
    while( temp != nullptr )
    {
        count += 1;
        temp = temp->next;
    }
    return count;
}


/** ***************************************************************************
 * @brief   Checks if the queue contain any items
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *
 * @returns True if it emtpy, false if it contains some items.
 *****************************************************************************/
bool Queue::empty( )
{
    return headptr == nullptr && tailptr == nullptr;
}


/** ***************************************************************************
 * @fn  void Queue::clear( )
 *
 * @brief   Clears this object to an empty state.
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *****************************************************************************/
void Queue::clear( )
{
    node *temp = headptr;
    while( headptr != nullptr )
    {
        temp = headptr;
        headptr = headptr->next;
        delete temp;
    }
    tailptr = nullptr;
}


/** ***************************************************************************
 * @brief   Swaps the given Queue with another Queue
 *
 * @author  Roger L. Schrader
 * @date    10/28/2020
 *
 * @param [in,out]  anotherQ    another Queue.
 *****************************************************************************/
void Queue::swap( Queue &anotherQ )
{
    std::swap( headptr, anotherQ.headptr );
    std::swap( tailptr, anotherQ.tailptr );
}


/** ***************************************************************************
 * @brief   Prints the Queue class item out to an ostream.
 *
 * @author  Roger L. Schrader
 * @date    10/30/2020
 *
 * @param [in,out]  out the output stream to print the data at.
 *****************************************************************************/
void Queue::print( ostream &out )
{
    node *temp = headptr;

    while( temp != nullptr )
    {
        out << temp->item;
        if( temp->next )
            out << ", ";
        temp = temp->next;
    }
}

