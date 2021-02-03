/** **************************************************************************
 * @file
 *
 * @brief   The declaration of the singly linked list for a list that
 *          is sorted.
 ****************************************************************************/

#include "prog2.h"

/**
   * @brief Hold the data for a linked list of words.
   */

class wordFreq
{
public:

    //redistribute jobs tasks

    //wordFreqB.cpp
    wordFreq();  // constructor
    ~wordFreq();  //destructor
    bool find(string word);   //find word position
    bool empty();                //list is empty
    bool insert(string word);     //insert word to list in Alpha order
    void printWord(ostream& out);    //print words in alpha order
    void clear();                    //clear list
    int sizeList();                  //size of the list


    //wordFreqA.cpp
    void printFreq(ostream& out, int max);  //print frequency list
    void printLength(ostream& out, int max);  //print word length list
    bool frequencyInc(string word); //increase frequency
    bool frequencyDec(string word); //decrease frequency
    bool remove(string word);        //remove word from list
    int maxLength();                     // the largest word
    int maxFreq();                      // the most used word.
 
private:

    void printHeader(ostream& out, char type, int num);  //prints the header

    /**
     * @brief  the storage container for each item in the list
     */
    struct node
    {

        string word;    /*!< the item */
        int frequency;  /*!< the number of times the word comes up  */
        node* next;     /*!< pointer to the remaining nodes in list */
    };
    node* headptr;      /*!< The location of the first node in the list */
}; 
