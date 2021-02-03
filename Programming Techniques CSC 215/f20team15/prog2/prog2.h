/** **************************************************************************
 * @file
 *
 * @brief this is the header file for the program. It includes all of the
 * programs includes, structures, enums, and function prototypes.
 ****************************************************************************/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include <sstream>

using namespace std;


#ifndef __PROG2__H__
#define __PROG2__H__


/**
 * @brief The 4 output operations, the default value is FREQUENCY
 */
enum statOutput 
{
    LENGTH,              /**< Length as stat output               */
    FREQUENCY,           /**< Frequency as stat output            */
    LENGTHFREQUENCY,     /**< Length then Frequency as stat output*/
    FREQEUNCYLENGTH      /**< Frequency then Length as stat output*/
};

/**
  * @brief Holds the data for the command line arguments.
  */

struct cmd {

    string inputFile;       /**< Holds the inputFile name */
    string outputFile;      /**< Holds the outputFile name */
    string statFile;        /**< Holds the statFile name */
    statOutput statType;    /**< Holds the stat output type options */
};

int cmdErrorCheck(cmd& Command, int argc, char* argv[]);

void usageStatement(int errorCode);

void openFiles(cmd Command, ifstream& fin, ofstream& word, ofstream& stat);


#endif