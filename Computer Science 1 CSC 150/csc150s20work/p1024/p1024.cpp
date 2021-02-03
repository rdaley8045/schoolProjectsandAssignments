/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Lab 12 - Finding debtors (p1024)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 4/16/2020
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
 * @details The purpose of this program is to take in a file, compare the data,
    and print out the information in a selected file. 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1024.exe
   d:\> c:\bin\p1024.exe
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
   4/16/2020      Started program
   4/16/2020      Completed program no errors.


   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

const int NAME_SIZE = 51;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

int read_file(ifstream &fin, int &date, char name[]);
void write_report(ofstream &fout, int date, char name[]);

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called.
 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 *****************************************************************************/

int main(int argc, char *argv[])
{
    ifstream fin; // file input stream
    ofstream fout; // file output stream
    int file_date = 0; // The date that is read in
    int comp_date; // the date that the user inputs in the command line
    int file_information = 0; // If there is information coming from the file
    int counter = 0; //count of the number of files past due
    char name[NAME_SIZE]; // name of the individual


    if (argc != 4)
    {
        //output message if command line does not have 4 arguments
        cout << "Usage: lab12.exe date inputfile outputfile";
        
        //return -1 if not enough variables
        return -1;
    }

    fin.open(argv[2]);

    if (!fin)
    {
        //output message if input file does not open
        cout << "Unable to open the input file " << argv[2];

        //close file
        fin.close();
        
        //return -2 if input file does not open
        return -2;
    }

    fout.open(argv[3]);

    if (!fout)
    {
        //output message if output files does not open
        cout << "Unable to open the output file " << argv[3];

        //closes file
        fout.close();

        return -3;
    }

    comp_date = atoi(argv[1]);

    //loop to get file information and compare that dates prior to output
    while (file_information == 0)
    {
        //gets information for the input file
        file_information = read_file(fin, file_date, name);

        //compares the dates 
        if (comp_date > file_date && file_information ==0)
        {
            //output name and date of individuals that are pasted the input day
            write_report(fout, file_date, name);

            //increase count by 1
            counter++;
        }
    }
    
    //output of the number of saved files. 
    cout << "Report saved with " << counter << " clients listed.";

    //close input file
    fin.close();

    //close output file
    fout.close();

    //returns 0 if program closes successfully
    return 0;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function reads in the information of the file.
 * @param[in]      fin - input file stream
 * @param[out]     date - date of that is shown in file
 * @param[out]     name - name of the individual that has the loan
 *
 * @returns 0 if the information is not a blank line.
 * @returns -1 if the information is a blank line.
 *
 *****************************************************************************/

int read_file(ifstream &fin, int &date, char name[])
{
    int result; // result of the comparison of cstring in name

    //input of date
    fin >> date;

    //clear in cache
    fin.ignore();

    //get name of individual with spaces
    fin.getline(name, NAME_SIZE);

    //compares name with a blank space
    result = strcmp(name, " ");

    //if the results of the comparison is greater than 0 then return 0
    if (result >= 0)
    {
        return 0;
    }
    //if the results of the comparison is less than 0 then return -1
    else
    {
        return -1;
    }

}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes file output stream, date, and name and prints it to the
   output file
 * @param[in]     fout - file output stream
 * @param[in]     date - date that the client took out the loan
 * @param[in]     name - name of the client
 *
 * @returns none.
 *
 *****************************************************************************/

void write_report(ofstream &fout, int date, char name[])
{
    //output the date and name of the individual 
    fout << date << " " << name << endl;
}