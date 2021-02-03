/** **************************************************************************
 * @file
 *
 * @brief this is the main function of the program.
 ****************************************************************************/

/** **************************************************************************
 * @mainpage Program 2 - Word Frequency
 *
 * @section course_section Course Information
 *
 * @author Raymond Daley, Kevin Chamberlain
 *
 * @par Professor:
 *         Roger Schrader
 *
 * @par Course:
 *         CSC215 - M001 - Programming Techniques
 *
 * @par Location:
 *         McLaury - 103F
 *
 * @date Due November 6, 2020
 *
 * @section program_section Program Information
 *
 * @details
 * This program is a word frequency and usage counters. Its propose is to
 * process a text file and pull out every word that is in the file and sort
 * them into a singly linked list. Additionally if that word was to appear 
 * multiple times in the file then the programs in increase a frequency counter
 * that is tracked with a frequency count in the single linked list.
 * 
 * This programs starts with a command line argument that the user must enter 
 * in order for the program to run. They must include the text file that they 
 * want processed and 2 output files. Additionally the user must select an 
 * option for the statistics output, the user is give 5 options. The first in 
 * to leave the option blank and recieve the word frequency back. The second
 * is to provide the program with -f with again gives them word frequency back.
 * Third the user can put in -l and get the lengths of the words back as a 
 * statistics. The last two options for the user is the mix the l and f 
 * together to create a dual statistics file. 
 * 
 * After the user provides the command line argument the program process the
 * command line arguments to ensure that the user inputed the correct 
 * arguments. Then the program opens the files and checks to make sure that 
 * they open. After that they start to process the text file by getting the 
 * word from the file, ensuring the its all lowercase letter and that all 
 * punctuations have been removed from the front and back of the word. Once
 * the word is processed the program looks to see if the word is in the linked
 * list prior to creating an instance of the word in the list, if the word is 
 * found in the list the program increases the frequency counter by 1. Lastly 
 * after the text file and been completely read in then the program outputs
 * the information to the output file and closes all of the files and clears 
 * the linked list. 
 * 
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      none - a straight compile and link with no external libraries.
 *
 * @par Usage:
   @verbatim
   c:\> prog2.exe inputfile.txt worddata.txt stat.txt -option
            inputfile.txt - filename containing the short story
            worddate.txt - filename to write out all of the words in the story.
            stat.txt - the statistic of the short story

            options
            default is blank
            -l
            -f
            -lf
            -fl

   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 *
 * @par Modifications and Development Timeline:
 * This is a link to gitlab's commit. To view <a target="_blank"
 * href="https://gitlab.mcs.sdsmt.edu/csc215/f20team15/-/commits/master">click here.</a>
 *
 *****************************************************************************/

#include "prog2.h"
#include"wordFreq.h"

void outputFiles(cmd command, ofstream& word, ofstream& stat, wordFreq& list);

void read(ifstream& fin, wordFreq& l1);


/** ***************************************************************************
 * @author Kevin Chamberlain, Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. int main will call cmdErrorCheck
 * which will error check the input command lines for this program. 
 * Subsequently int main will also call functions to output usage statements, 
 * to open the files, to read in the files, to output the appropriate data, and
 * int main will finally close the opened files and clear the list for future 
 * use.
 *
 * @param[in]     argc - the argument counter.
 * @param[in]    argv - the arguments.
 *
 * @returns 0 program exits successfully.
 *
 *****************************************************************************/


int main(int argc, char* argv[])
{
    cmd command;
    int errorCode;
    ifstream fin;
    ofstream word, stat;
    wordFreq list;

    //Error Checking of the CMD lines
    errorCode = cmdErrorCheck(command, argc, argv);

    //If  Output Usage state for invalid command lines
    if (errorCode != 1)
        usageStatement(errorCode);

    //Open files
    openFiles(command, fin, word, stat);

    //Read in input File and store information in to linked list

    read(fin, list);

    //Output the data to the appropriate files
    outputFiles(command, word, stat, list);

    //close files
    fin.close();
    word.close();
    stat.close();

    //clear files
    list.clear();
    
    return 0;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function  is designed to take in the command line arguments, the 
 * two output file streams and the linked list and create the necessary files. 
 * This starts by getting the max length and frequency of the word. Then it 
 * output the word list to the users. After the word list has been created. 
 * The function looks at which statistic output file needs to be created and 
 * calls the appropriate function from the wordFreq class to process that
 * information. 
 *
 * @param[in]          command -  the code that the cmd line failed with.
 * @param[in,out]      word - word output file stream
 * @param[in,out]      stat - stat output file stream
 * @param[in]          list - the linked list that was created.
 *
 *
 *****************************************************************************/

void outputFiles(cmd command, ofstream& word, ofstream& stat, wordFreq& list)
{
    //initialized two int values called maxLenght and maxFreq
    int  maxLength, maxFreq;

    //call the maxLength and maxFreq function to get the int values
    maxLength = list.maxLength();
    maxFreq = list.maxFreq();

    //print out the file with all of the words in alphabetic order
    list.printWord(word);

    //if the statType is Frequency then output the frequency of words
    if (command.statType == FREQUENCY)
        list.printFreq(stat, maxFreq);
    
    //if the statType is Length the output the length of words
    else if (command.statType == LENGTH)
        list.printLength(stat, maxLength);

    //if the statType is FreqeuncyLenght then output the freq and length of
    //words
    else if (command.statType == FREQEUNCYLENGTH)
    {
        list.printFreq(stat, maxFreq);
        list.printLength(stat, maxLength);
    }

    //if the statType is LenghtFrequency then output the length and freq of
    //words
    else if (command.statType == LENGTHFREQUENCY)
    {
        list.printLength(stat, maxLength);
        list.printFreq(stat, maxFreq);

    }
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function takes in a given word from the read function crops the word 
 * of any punctuation on either end of the word. The function does this 
 * iteratively by walking through each character and removing the punctuation 
 * at the beginning and end. This function will not however remove the 
 * punctuation in the middle of the word (or string). 
 * 
 * @param[in,out]          str -  the word that need to be processed. 
 *
 *
 *****************************************************************************/

void process(string& str)
{
    //initializes at string iterator
    string::iterator it;

    //set it to the being of the word
    it = str.begin();

    //while the word it is not the end of the word & a punt the increase
    //it by 1
    while (it != str.end() && ispunct(*it))
    {
        it++;
    }
    
    //erase any spaces or puncts from the beginning of the word
    str.erase(str.begin(), it);

    //set it to the end of the word
    it = str.end();

    //if the word begin is not equal to the end the process ahead
    if (str.begin() != str.end())
    {
        //move it down by 1
        it--;

        //while it is not equal to begin and punct then move it by 1
        while (it != str.begin() && ispunct(*it))
        {
            it--;
        }

        //if it is a punct then erase everything behind the punctuation 
        if (ispunct(*it))
        {
            str.erase(it, str.end());
        }
        //else move back one position then erase the white space
        else
        {
            it++;
            str.erase(it, str.end());
        }
    }

    //set it at the beginning of the word
    it = str.begin();

    //while it is not end of the word and it is an alpha then process to 
    //lowercase
    while (it != str.end())
    {
        if (isalpha(*it))
        {
            *it=tolower(*it);
        }
        it++;
    }
}

/** ***************************************************************************
 * @author Kevin Chamberlain
 *
 * @par Description:
 * This function reads in the original document and calls the process word 
 * function prior to inputing the word in the linked list. 
 *
 * @param[in,out]      fin - word output file stream
 * @param[in,out]      l1 - stat output file stream
 *
 *
 *****************************************************************************/

void read(ifstream& fin, wordFreq& l1)
{
    //temp variable for the word that is read in.
    string temp;

    //while able to read in a word then complete tasks
    while (fin >> temp)
    {

        //calls process function to remove punctuation and white space. 
        process(temp);

        if (temp.size() != 0)
        {

            //if word is found in list then increase the frequency 
            if (l1.find(temp))
            {
                l1.frequencyInc(temp);
            }
            //else insert the word into the linked list.
            else
            {
                l1.insert(temp);
            }
        }
    }
}
