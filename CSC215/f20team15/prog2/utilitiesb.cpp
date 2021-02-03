/** **************************************************************************
 * @file
 *
 * @brief  this is the part 1 of the main functions for the program.
 ****************************************************************************/

#include "prog2.h"
#include "wordFreq.h"


 /** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This program is designed to  take in the command line arguments and 
  * error check them. If there is a fault the program will return and error 
  * code to main.
  *
  * @param[in, out] command - the command struct that hold the cmd values.
  * @param[in]      argc -  the number of cmd line arguments
  * @param[in]      argv -  the arguments that were passed in
  * 
  * @return 1 no error noted.
  * @return 2 to few or to many argument inputed 
  * @return 3 incorrect stat options. 
  *
  ****************************************************************************/


int cmdErrorCheck(cmd& command, int argc, char* argv[])
{
    //if there is less than  4 argument or more than 5 return code 2
    if (argc < 4 || argc > 5)
        return 2;

    //set inputfile, outputFile, and statFile to the arguments that came in.
    command.inputFile = argv[1];
    command.outputFile = argv[2];
    command.statFile = argv[3];

    //if the argc is 4 or the 5th argument is -f then set the statType
    //to the FREQUENCY value.
    if (argc == 4 || (string)argv[4] == "-f")
    {
        command.statType = FREQUENCY;

        //return code 1
        return 1;
    }
    //if the 5th argument is -l then set the statType to Length
    else if ((string)argv[4] == "-l")
    {
        command.statType = LENGTH;
        //return code 1
        return 1;
    }
    //if the 5th argument is -fl then set the statType to FreqeuncyLength
    else if ((string)argv[4] == "-fl")
    {
        command.statType = FREQEUNCYLENGTH;
        //return code 1
        return 1;
    }
    //if the 5th argument is -lf then set the statType to LengthFreqyency
    else if ((string)argv[4] == "-lf")
    {
        command.statType = LENGTHFREQUENCY;
        //return code 1
        return 1;
    }
    //if an incorrect output type then return code 3 to the calling function
    else
        return 3;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This program is designed to  take in the command line arguments and
 * error check them. If there is a fault the program will return and error
 * code to main.
 *
 * @param[in]      errorCode -  the code that the cmd line failed with.
 *
 *
 *****************************************************************************/

void usageStatement(int errorCode)
{
    //if the error code is 2 the print to few arguments
    if (errorCode == 2)
        cout << "Too few or too many arguments!" << endl << endl;

    //if the error code is 3 then print invalid output option
    else if (errorCode == 3)
        cout << "Invalid output option!" << endl << endl;

    //output usage statement 
    cout << "prog2.exe inputFile.txt worddata.txt stat.txt ";
    cout << "[option]"<<endl << endl;
    cout << "Option Codes" << setw(22) << "Option Name" << endl;
    cout << setw(10) << "-f" << setw(22) << "Frequency" << endl;
    cout << setw(10) << "-l" << setw(19) << "Length" << endl;
    cout << setw(10) << "-lf" << setw(33);
    cout << "Length and Frequency" << endl;
    cout << setw(10) << "-fl" << setw(34);
    cout << "Frequency then Length" << endl;
    cout << setw(10) << "BLANK" << setw(38);
    cout << "Default option, frequency" << endl;
    

    //if function is called exit code 0
    exit(0);
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This program is designed to  take in the command line arguments and
 * error check them. If there is a fault the program will return and error
 * code to main.
 *
 * @param[in]      Command -  the code that the cmd line failed with.
 * @param[in,out]  fin - input file stream
 * @param[in,out]  word - word output file stream
 * @param[in,out]  stat - stat output file stream
 *
 *
 *****************************************************************************/


void openFiles(cmd Command, ifstream &fin, ofstream &word, ofstream &stat)
{
     //opens the image file
    fin.open(Command.inputFile.c_str());
    //opens the word output file
    word.open(Command.outputFile.c_str());
    //opens the stat output file
    stat.open(Command.statFile.c_str(), ios::app);

    //checks to see if the input file is open
    if (!fin.is_open())
    {
        //if file failed to out output message
        cout << "Input file failed to open!" << endl;

        //close the word file
        word.close();
        //close the stat file
        stat.close();

        //exit the program code 0
        exit(0);
    }

    //checks to see if the word output file  is open
    if (!word.is_open())
    {
        //if file failed to open output message
        cout << "Word output file failed to open!" << endl;

        //close input file
        fin.close();
        //close the stat file
        stat.close();
      
        //exit the program code 0
        exit(0);
    }

    //checks to see if the stat output file  is open
    if (!stat.is_open())
    {
        //if file failed to open output message
        cout << "Stat output file failed to open!" << endl;

        //close input file
        fin.close();
        //close the word file
        word.close();

        //exit the program code 0
        exit(0);
    }
}

