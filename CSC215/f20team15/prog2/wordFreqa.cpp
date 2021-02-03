/** **************************************************************************
 * @file
 *
 * @brief this is the .cpp part 1 of the class function. This file contains the
 * class functions written by Kevin Chamberlain. 
 ****************************************************************************/

//Kevin's functions

#include"wordFreq.h"


/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function prints out the words in a document sorted by frequency in 
 * decreasing order. It will do this by accessing a linked list stored in the
 * wordFreq class. printFreq will walk through comparing the frequencies of the
 * words in the linked list outputing a header, by calling the printHeader
 * function. The header will be printed out before the words that occur that 
 * often. This function will take in the ostream in order to output the data to
 * the outgoing file. The function will also take in the max frequency in order
 * to format the data appropriately in decending order. 
 * 
 * @param[in,out] out - the output file stream.
 * @param[in]     max - the max number of occurances a word will appear.
 * 
 *****************************************************************************/
void wordFreq::printFreq(ostream& out, int max)
{
    int minFreq = 1; //minimum frequency
    int n = max,i; //variable for maximum
    char type = 'F'; //type of operation
    node* curr; //current variable for node
    node* prev; //previous variable for node
    string temp; //temporary string variable
   
    while (n >= minFreq) //while n is greater than or equal to min frequency
    {
        curr = headptr; //current varaible set to headpointer
        prev = headptr; //previous variable set to headpointer

        while (curr != nullptr ) //while current is not a nullptr
        {
            
            if (curr->frequency == n) //if the current frequency equals to max
            {
                out << endl; //outputs new line
                printHeader(out, type, n); //prints header
                break; //breaks out of while
            }

            prev = curr; //previous set equal to current
            curr = curr->next; //current set equal to current next
            
        }

        curr = headptr; //current set equal to headptr
        prev = headptr; //previous set equal to headptr
        i = 0; //i variable set equal to 0

        while (curr != nullptr) //while current is not equal to nullptr
        {
            
            if (curr->frequency == n) //if current frequency equals max
            {
                i++; //adds to increment of i

                out << setw(20) << curr->word; //outputs current word width 20

                if (i == 4) //if i is 4
                {
                    i = 0; //set i to 0
                    out << endl; //output newline
                }
                
            }
            prev = curr; //previous equals to current
            curr = curr->next; //current equals current next
        }
        n--; //subracts from increment of max

    }
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function prints out the words in a document sorted by length in 
 * decreasing order. It will do this by accessing a linked list stored in the
 * wordFreq class. printLength will walk through comparing the length of the
 * words in the linked list outputing a header, by calling the printHeader
 * function. The header will be printed out before the words of that length
 * This function will take in the ostream in order to output the data to
 * the outgoing file. The function will also take in the max length in order
 * to format the data appropriately in decending order. 
 * 
 * @param[in,out] out - the output file stream.
 * @param[in]     max - the max length of any word in the text.
 *
 *****************************************************************************/

void wordFreq::printLength(ostream& out, int max)
{
    int minLength = 1; //minimum length
    int n = max, i; //sets n variable to max
    char type = 'L'; //sets type of sorting to length
    node* curr; //declares current node
    node* prev; //declares previous node
    string temp; //declares temporary string variable
    

    while (n >= minLength) //while max is greater than or equal to min length
    {
        curr = headptr; //current set equal to headptr
        prev = headptr; //previous set equal to headptr

        while (curr != nullptr) //while curr doesn't equal nullptr
        {
            temp = curr ->word; //temp set equal to current word

            if (temp.size() == n) //if temp size is equal to max
            {
                out << endl; //output newline
                printHeader(out,type, n); //print header
                break; //breaks out of while loop
            }
            prev = curr; //previous equals current
            curr = curr->next; //current equals current next
        }
        
        curr = headptr; //current equals headpointer
        prev = headptr; //previous equals headpointer
        i = 0; //i variable equals 0

        while (curr != nullptr) //while current doesnt equal nullpointer
        {

            if (size(curr->word) == n) //if the size of current word equals n
            {
                i++; //adds increment to i

                out << setw(20) << curr->word; //outputs current word
                
                if (i == 4) //if i equals 4
                {
                    i = 0; //i variable equals 0
                    out << endl; //output newline
                }
            }
            prev = curr; //previous equals current
            curr = curr->next; //current equals current next
        }
        n--;//decrease n increment
    }
        
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function increases the frequency counter by 1 every time a word appears
 * It will do this by looking through the linked list and when it finds a word 
 * that is already inserted, it will increase the attatched frequency of that
 * word. 
 * 
 * @param[in]     theWord - the word that is being increased
 *
 * @returns true if successful and false otherwise.
 *
 *****************************************************************************/


bool wordFreq::frequencyInc(string theWord)
{
    node* curr = headptr; //current node equals headpointer
    node* prev = headptr; //previous node equals headpointer
    
    while (curr != nullptr) //while current doesn't equal nullpointer
    {
        if (theWord == curr->word) //if the word equals current word
        {
            //adds to current frequency by 1
            curr->frequency = curr->frequency + 1; 

            return true; //returns true
        }
        prev = curr; //previous equals current
        curr = curr->next; //current equals current next
    }
    return false; //returns false
}

/** ***************************************************************************
 * @author Your Name
 *
 * @par Description:
 * This function decrease the frequency counter by the user direction. It does
 * this by searching through the linked list, in the wordFreq class. If the
 * function finds the word in the linked list it will decrease to frequency
 * attatched to the word in the linked list. If the word the user has input
 * that they wish to decrease only appears once, the word will be removed. This
 * function will call the remove function in those cases where the word only 
 * occurs once.
 *
 * @param[in]     theWord - the word being decreased
 *
 * @returns true if successful and false otherwise.
 *
 *****************************************************************************/

bool wordFreq::frequencyDec(string theWord)
{
    node* curr = headptr; //sets the current node equal to the headpointer
    node* prev = headptr; //sets the previous node equal to the headpointer
    bool occur = false; //sets the occur boolean equal to false

    while (curr != nullptr) //while the current node isn't equal to nullpointer
    {
        if (curr->word == theWord) //if the current word equals the input word
        {
            if (curr->frequency <= 1) //checks the frequency of current word
            {
                remove(curr->word); //removes the word
            }
            //subracts one from the current frequency
            curr->frequency = curr->frequency - 1;

            return true; //returns true
        }
    }

    return false; //returns false
}


/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function will allow a user to remove a word from the word list. The 
 * function accomplishes this by walking through the linked list, and if the 
 * word is found then the word is removed. This function will also patch the 
 * linked list so that ther will be no disruption of the list. This function is
 * also called in the decreaseFreq function in those cases where the word
 * appears once.
 *
 * @param[in]     theWord - word that the user wants to remove.
 *
 * @returns true if successful and false otherwise.
 *
 *****************************************************************************/

bool wordFreq::remove(string theWord)
{
    node* curr = headptr; //sets current node equal to headpointer
    node* prev = headptr; //sets previous node equal to heapointer

    if (curr == nullptr) //if the current node is equal to nullpointer
    {
        return false; //Return false
    }
    if (curr->word == theWord) //if the current word is equal to the input word
    {
        headptr = curr->next; //sets headpointer equal to the next
        delete curr; //deletes the current node

        return true; //return true
    }

    while (curr != nullptr && curr->word != theWord) //while the current node
      //is not equal to nullpointer and the current word is not the input word
    {
        prev = curr; //sets the previous node equal to the current node
        curr = curr->next; //sets the current node equal to the next
    }

    if (curr == nullptr) //if the current node if equal to a nullpointer
    {
        return false; //Return false
    }

    prev->next = curr->next; //points the previous pointer to the current ptr

    delete curr; //deletes the current

    return true; //returns true
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function will print the a formated header to organize data. It will 
 * take in ostream out in order to output to the file. It wil also take in a 
 * type, this type tells the function which varriant of the header to output.
 * If the type is F, the frequency header will be output; if the type is L the
 * length header will be output.
 *
 * @param[in,out] out - the output file stream.
 * @param[in]     type - the option type (either frequency or length).
 * @param[in]     num - the interger corresponding to type (if length the
 *                      number of characters. if frequency, the number of times
 *                      the word occurs).
 *
 *****************************************************************************/

void wordFreq::printHeader(ostream& out, char type, int num)
{
    int i = 0; //temp variable
    int lineLength = 80; //Setting the line length max to 80
    node* curr = headptr; //This will be a temp variable for current position
    node* prev = headptr; //This will be a temp variable for previous postion
    string header(lineLength, '*'); //Header will be a line of *
    string title = "Word(s) with the "; //Repeated string
    string flType; //Repeated string

    if (type == 'L') //This if will check the type and set the flType string
        flType = " length of "; //Sets string to " length of "
    else if (type == 'F') //This if will check the type and set the flType string
        flType = " frequency of "; //Sets string to " frequency of "
    
    if (type == 'F') //if the type is F output the header for Frequency
    {
        out << header << endl << "*" << setw(79) << "*" << endl;
        out << "*" << setw(40) << title << flType << num << endl;
        out << "*" << setw(79) << "*" << endl << header << endl;
    }
    if (type == 'L') //if the type is L output the header for Length
    {
        out << header << endl << "*" << setw(79) << "*" << endl;
        out << "*" << setw(40) << title << flType << num << endl;
        out << "*" << setw(79) << "*" << endl << header << endl;
    }

}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function will return the length of the longest word. The function will
 * accomplish this by searching throuhg the linked list and updating its max 
 * accordingly. After it has gone through the list it will return the length of
 * the longest word in the list.
 *
 * @returns length of the longest word.
 *
 *****************************************************************************/
int wordFreq::maxLength()
{
    int max =0; //max set to lowest positive integer
    node* prev=headptr; //Setting temp variable for previous node to headptr
    node* curr=headptr; //Setting temp variable for current node to headpty
    string temp; //Holds a temperary string

    while (curr != nullptr) //As long as curr node is not a nullpointer
    {
        temp = curr->word; //set the temp value to the current word
        if (temp.size() > max) //if the size of the string is greater than max
        {
            max = (int)temp.size(); //Sets the max equal to the string length
        }
        prev = curr; //Sets the previous node to the current node
        curr = curr->next; //Set the current node to the next string
    }

    return max; //Returns max value
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function will return the greatest occurance of a word found in the 
 * file. The function will accomplish this by walking through the linked list 
 * and updating the max accordingly. After it has gone through the list it will
 * return the greatest occurance of a word.
 *
 * @returns max the number of the max number of times the word appeaser.
 *
 *****************************************************************************/
int wordFreq::maxFreq()
{
    int max = 0; //temp value
    node* prev = headptr; //sets previous node equal to headpointer
    node* curr = headptr; //sets the current node equal to headpointer
    string temp; //temperary string variable

    while (curr != nullptr) //while the current node is not a nullpointer
    {
        temp = curr->word; //set temp string equal to the current word

        //if the current frequency is greater than the max
        if (curr->frequency > max)  
        {
            max = curr->frequency; //set max equal to the current frequency
        }

        prev = curr; //set previous node equal to the current node
        curr = curr->next; //set current node equal to the next
    }

    return max; //return max value
}