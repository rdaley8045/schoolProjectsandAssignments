/** **************************************************************************
 * @file
 *
 * @brief this is the .ccp part 2 of the class function.
 ****************************************************************************/

#include"wordFreq.h"

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This the constructor of the wordFreq class. This builds an empty linked 
 * list.
 *
 *****************************************************************************/

wordFreq::wordFreq()
{

    //set the headptr to nullptr. 
    headptr = nullptr;

}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the destructor of the wordFreq class. This clears the linked list
 * of any data and unallocates the memory 
 *
 *****************************************************************************/

wordFreq::~wordFreq()
{
    //calls the clear function to remove all data
    clear();
}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function finds the word in the link list returns true or false if the 
 * word is located in the list. 
 *
 * @param[in]     word - the string word that is being inputed.
 *
 * @returns true  - word is located in the list
 * @returns false - word is not located in the list
 *
 *****************************************************************************/

bool wordFreq::find(string word)
{
    //create node structures called curr and prev
    node* curr, * prev;

    //set curr and prev to the headptr address
    curr = headptr;
    prev = headptr;

    //while curr is not equale to nullptr and curr word is not equal to word
    while (curr != nullptr && curr->word != word)
    {
        //set prev to currents address
        prev = curr;
        //set curr to the next address set in curr next
        curr = curr->next;
    }

    //if curr is not nullptr and curr word is equalt to word then return true
    //else return false
    if (curr != nullptr && curr->word == word)
        return true;
    else
        return false;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function checks the linked list to see if the list is empty.
 *
 * @returns true if successful and false otherwise.
 *
 *****************************************************************************/

bool wordFreq::empty()
{
    //if the headptr address is equal to nullptr return true else false
    if (headptr == nullptr)
        return true;
    else
        return false;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function inserts a word in a sorted linked list of word. The words are 
 * sorted and stored in an alphabetically order
 *
 * @param[in]     word - the word that needs to be added.
 *
 * @returns true if successful and false otherwise.
 *
 *****************************************************************************/

bool wordFreq::insert(string word)
{

    //create 3 node structurs called tmep, curr, and prevs
    node* temp, * curr, * prev;

    //allocate temp with new address
    temp = new(nothrow) node;

    //temp is equal to nullptr return false.
    if (temp == nullptr)
        return false;

    //set temp word to word frequency to 1 and next to nullptr
    temp->word = word;
    temp->frequency = 1;
    temp->next = nullptr;

    //if the list is temp then set headptr to temp and return true.
    if (empty())
    {
        headptr = temp;
        return true;
    }

    //set curr to headptr
    curr = headptr;

    //if curr word is greater then temp word
    if (curr->word > temp->word)
    {
        //set temp next to headptr
        temp->next = headptr;
        //set headptr to temp
        headptr = temp;
        //return true
        return true;
    }

    //set curr and prev to headptr
    curr = headptr;
    prev = headptr;

    //while the curr pointer in not nullptr and the curr word is less than 
    //the temp word then move the temp word down the list to the middle 
    // or end of the list
    while (curr != nullptr && curr->word < temp->word)
    {
        prev = curr;
        curr = curr->next;
    }
    
    //set prev pointer to temp and temp next to the curr pointer
    prev->next = temp;
    temp->next = curr;

    //return true.
    return true;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function prints the list of word out in groups of there alphabet. 
 * Additionally the output will exclude an letter that are not found in the 
 * the list. 
 * 
 * @param[in,out]    out - the output file stream.
 *
 *****************************************************************************/

void wordFreq::printWord(ostream& out)
{
    int i = 0; //temp variable
    int lineLength = 80; //max length of the output message
    node* curr, * prev; //link lists to be walked through
    char alpha; //the letter of the words that are being outputted
    string header(lineLength, '*'); // creates a header line 80 long with *'s
    string title; //variable to hold the starting header information

    curr = headptr; // set curr to headptr
    prev = headptr; // set prev to headptr

    alpha = curr->word.at(0); //get the first letter in the list of words

    title = "Word(s) Starting with "; // set header information

    //while curr is not nullptr process information
    while (curr!= nullptr)
    {
        //output the header information to the user with what letter is being
        //displayed
        out << header << endl << "*" << setw(79) << "*" << endl;
        out <<"*"<< setw(40) << title << alpha<<  endl;
        out << "*" << setw(79) << "*" << endl << header << endl;
        
        //while curr is not nullptr and curr word firts letter matches alpha
        //then process the informatiopn
        while (curr != nullptr && curr->word.at(0) == alpha)
        {
            //move i counter up by one
            i++;
            //print out the word with a starting at 20 spaces in
            out << setw(20) << curr->word;

            //if i = 4 then output a endline and start a new line
            if (i == 4)
            {
                i = 0;
                out << endl;
            }

            //move curr to previous curr to the next address
            prev = curr;
            curr = curr->next;
        }
        
        i = 0;
        //out put 2 new lines
        out << endl <<endl;

        // if curr is still not equal to nullptr then get the next letter in
        //the list
        if (curr != nullptr)
            alpha = curr->word.at(0);
    }

}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function when called will remove all items in the list and free up the
 * memory allocation that was assigned to each list item.
 *
 *****************************************************************************/

void wordFreq::clear()
{
    //temp node value to transverse through the link list
    node* temp = headptr;

    //while headptr has an address
    while (headptr != nullptr)
    {
        //headptr is equal headptr next
        headptr = headptr->next;
        //delete temp position
        delete temp;
        //move temp to the next headptr
        temp = headptr;
    }
}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * 
 * This function counts the total number of unique words that is in the list.
 * 
 * @returns size - the size of the link list
 *
 *****************************************************************************/

int wordFreq::sizeList()
{

    //int value to hold the size of the link list
    int size=0;

    //initialized two temp node variables.
    node* curr, * prev;

    //set curr and prev to headptr
    curr = headptr;
    prev = headptr;

    //while curr in not equal to nullptr
    while (curr != nullptr)
    {
        //then set prev to curr, curr to next, and increase size
        prev = curr;
        curr = curr->next;
        size++;
    }

    //return size to the calling function.
    return size;
}

