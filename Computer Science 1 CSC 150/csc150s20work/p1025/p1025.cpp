/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Lab 13 - Song Rankings (p1025)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 4/22/2020
 *
 * @par Professor:
 *         Dr. Daniel de Castro
 *
 * @par Course:
 *         CSC 150
 *
 * @par Location:
 *         CB - 204W
 *
 * @section program_section Program Information
 *
 * @details The purpose of this program is us a Cearsor Cypher to encrypt and
   decrypt messages. This is accomplished through the use of cstring inputs,
   command line arguments, and file input/output.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1025.exe
   d:\> c:\bin\p1025.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 * @todo none
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date           Modification
   -------------  -------------------------------------------------------------
   4/07/2020      Started program
   4/08/2020      Rotate message function built
   4/09/2020      File input function built
   4/10/2020      File rotate function built
   4/13/2020      Update to comments and doxegyn
   4/14/2020      Working on command line arguments
   4/17/2020      Command line argument are built and running
   4/18/2020      Updated comments for the program.
   4/21/2020      Update comment for the program



   @endverbatim
 *
 *****************************************************************************/

 //This define is needed to avoid Visual Studio cstring function warnings
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>

using namespace std;

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

const int SONGS = 100;
const int LENGTH = 81;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void swap_integers(int& n1, int& n2);
void swap_strings(char s1[], char s2[]);
int read_song_and_ranks(ifstream &file_songs, ifstream &file_ranks,
    char songs[][LENGTH], int ranks[]);
void sort_songs_by_rank(char songs[][LENGTH], int ranks[], int num_songs);
void write_list(char songs[][LENGTH], int ranks[], ofstream &out,
    int num_songs);




/** ***************************************************************************
* @author K. Corwin (Modified by Dr. De Castro)
*
* @par Description:
*   Declares arrays
    Checks value of argc; if incorrect, terminates program
    Opens two input files and one output file
    Checks file success;  if incorrect, terminates program
    Reads from input files, obtaining number of data items read
    Sorts the song titles and ranking data based on rankings,
        in ascending order
    Writes the rankings and song titles, in ascending order,
        to the output file
    Closes all files
*
* @param[in] argc - the number of arguments from the command line.
* @param[in] argv - a 2d array of char containing the command line arguments.
*
* @returns 0 in all cases - a message to stdout describes any error states.
*
*****************************************************************************/
int main(int argc, char* argv[])
{
    //Declare two input file objects
    ifstream file_songs;
    ifstream file_ranks;
    //Declare one output file object
    ofstream out;
    //Holds the song titles
    char songs[SONGS][LENGTH];
    //Holds the song rankings 
    int ranks[SONGS];
    //The actual number of songs read from the files.
    int numSongs;

    //Always error check argc before doing anything else!!
    if (argc != 4)
    {
        cout << "Usage: p1025.exe <song filename> "
            << "<rank filename> <final list filename>" << endl;

        return -1;
    }

    //now try to open all 3 files
    file_songs.open(argv[1]);
    file_ranks.open(argv[2]);
    out.open(argv[3]);

    //if any file fails to open, stop the program    
    if (!file_songs)
    {
        cout << "File error; program exiting." << endl;
        return -2;
    }

    if (!file_ranks)
    {
        cout << "File error; program exiting." << endl;
        return -2;
    }

    if (!out)
    {
        cout << "File error; program exiting." << endl;
        return -2;
    }

    //Read from both files, storing to arrays
    // and getting the actual value of numSongs
    numSongs = read_song_and_ranks(file_songs, file_ranks, songs, ranks);

    //Sort song and ranking data by rank
    sort_songs_by_rank(songs, ranks, numSongs);

    //Write the output to a new file
    write_list(songs, ranks, out, numSongs);

    //close all files
    file_songs.close();
    file_ranks.close();
    out.close();

    return 0;
}

/** ***************************************************************************
* @author K. Corwin
*
* @par Description:
* This function takes in two integers by reference
    and swaps them.  When the function is done,
    n1 contains the original value of n2, and
    n2 contains the original value of n1.

    Note: this is a great example of [in,out] params!
*
* @param[in,out] n1 - at the call, this contains the first integer value;
                      at return, this contains the second integer value.
* @param[in,out] n2 - at the call, this contains the second integer value;
                      at return, this contains the first integer value.
*
* @returns none
*****************************************************************************/
void swap_integers(int& n1, int& n2)
{
    //need a temporary integer for swapping,
    // then perform the 3 swap actions
    int swap = n2;
    n2 = n1;
    n1 = swap;

    return;
}

/** ***************************************************************************
* @author K. Corwin (Modified by Dr. De Castro)
*
* @par Description:
* This function takes in two C strings
    and swaps them.  When the function is done,
    s1 contains the original value of s2, and
    s2 contains the original value of s1.

    Note: this is a great example of [in,out] params!
*
* @param[in,out] s1 - at the call, this contains the first C string value;
                        at return, this contains the second C string value.
* @param[in,out] s2 - at the call, this contains the second C string value;
                        at return, this contains the first C string value.
*
* @returns none
*****************************************************************************/
void swap_strings(char s1[], char s2[])
{
    //need a temporary C string for swapping
    // TODO: Declare your TEMP variable with the appropriate size
    char temp[ LENGTH ] = "";

    //perform the 3 actions to swap 2 values
    strcpy(temp, s2);
    strcpy(s2, s1);
    strcpy(s1, temp);

    return;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function  takes in a file and rotates the file message and output the
   the message.
 * @param[in]     fin - the file input stream
 * @param[in]     key - the number of shifts that need to occur
 *
 * @returns none.
 *
 *****************************************************************************/

int read_song_and_ranks(ifstream &file_songs, ifstream &file_ranks,
    char songs[][LENGTH], int ranks[])
{
    int number_songs = 0;
    int i = 0;

    while (file_songs.getline(songs[i], LENGTH))
    {
        i++;
        number_songs++;
    }
    
    i = 0;

    while (file_ranks >> ranks[i])
    {
        i++;

    }

    return number_songs;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function  takes in a file and rotates the file message and output the
   the message.
 * @param[in]     fin - the file input stream
 * @param[in]     key - the number of shifts that need to occur
 *
 * @returns none.
 *
 *****************************************************************************/

void sort_songs_by_rank(char songs[][LENGTH], int ranks[], int num_songs)
{
    int i;
    int j;
  
    for (i = 0; i < num_songs; i++)
    {
        for (j = 0; j < (num_songs - i); j++)
        {
            if (ranks[i] < ranks[i + 1])
            {
                swap_integers(ranks[i], ranks[i + 1]);
                swap_strings(songs[i], songs[i + 1]);

            }
        }
    }
}


/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function  takes in a file and rotates the file message and output the
   the message.
 * @param[in]     fin - the file input stream
 * @param[in]     key - the number of shifts that need to occur
 *
 * @returns none.
 *
 *****************************************************************************/

void write_list(char songs[][LENGTH], int ranks[], ofstream &out,
    int num_songs)
{
    int i;

    for (i = 0 ; i < num_songs; i++)
    {
        out << ranks[i] << " " << songs[i] << endl;
    }
}