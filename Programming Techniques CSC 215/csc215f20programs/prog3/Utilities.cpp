/** ***************************************************************************
 * @file
 * 
 * @brief contains all of the background function necessary to perform 
 * the necessary functions
 *****************************************************************************/
#include"netPBM.h"

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in the command line arguments and checks that all of the
 * values are valid. Additionally the function assigns all of the values to 
 * the command line to the structure cmd. 
 *
 * @param[in]     argc - the number of argument that were passed in.
 * @param[in]     argv[] - the arguments that were passed in
 * @param[in,out] cmd - the structure that holds all of the cmd arguments
 *
 * @return 1 --command line arguments all check out
 * @return 2 --to few command line arguments
 * @return 3 --no -oa or -ob arguments found
 * @return errorCode --the error code if there is any issues with getSpecOps  
 *
 *****************************************************************************/

int checkedCmd(int argc, char* argv[], cmdArgs& cmd)
{

    //if number of argument is less than 4 and greater than 6 then return 2
    if (argc != 7)
        return 2;

    //sets the output file name to outFileName
    cmd.fileName = argv[1];

    //Get the row to start the fill at
    cmd.row = stoi((string)argv[3]);

    //Get the column to start the fill at
    cmd.col = stoi((string)argv[2]);

    //check to ensure pixel value for red is valid
    if (stoi((string)argv[4]) < 0 || stoi((string)argv[4]) > 255)
        return 3;
    else
        cmd.redPixel = stoi((string)argv[4]);

    //check to ensure pixel value for green is valid
    if (stoi((string)argv[5]) < 0 || stoi((string)argv[5]) > 255)
        return 4;
    else
        cmd.greenPixel = stoi((string)argv[5]);

    //check to ensure pixel value for blue is valid
    if (stoi((string)argv[6]) < 0 || stoi((string)argv[6]) > 255)
        return 5;
    else
        cmd.bluePixel = stoi((string)argv[6]);
    
    return 1;
}




/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This functions purpose is to output the usage statement to the user if they
 * fail to correctly input the commands required for the program to run.
 * Additional if this function is to be ran, after outputting the usage
 * statement the program will auto exit with a code 0.
 *
 * @param[in]     errorCode - the arguments that were passed in
 *
 ****************************************************************************/

void invalidCmd(int errorCode)
{
    //if the error code is 2 the print to few arguments
    if (errorCode == 2)
        cout << "Too few or too many arguments!" << endl << endl;

    //if the error code is 3 then print invalid output option
    else if (errorCode == 3)
        cout << "Invalid red pixel!" << endl << endl;

    //if the error code is 4 then print invalid special option provided
    else if (errorCode == 4)
        cout << "Invalid green pixel!" << endl << endl;

    //if the error code is 5 then print invalid brightness value
    else if (errorCode == 5)
        cout << "Invalid blue pixel!" << endl << endl;


    //output usage statement 
    cout << "prog3.exe imageFile.ppm column row redPixel greenPixel bluePixel"
        << endl << endl;
    cout << "imageFile.ppm" << setw(44) << "image file to input and output to"
        << endl;  
    cout << "column" << setw(57) << "column in which to start the fill in at"
        << endl;
    cout << "row" << setw(57) << "row in which to start the fill in at" 
        << endl;
    cout << "redPixel" << setw(40) << "the new red pixel value." <<
        " Must be between 0 and 255. " << endl;
    cout << "greenPixel" << setw(40) << "the new green pixel value." <<
        " Must be between 0 and 255. " << endl;
    cout << "bluePixel" << setw(40) << "the new blue pixel value." <<
        " Must be between 0 and 255. " << endl;
    //if function is called exit code 0
    exit(0);
}

