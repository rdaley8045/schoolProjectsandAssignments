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
    int errorCode = 1; // the error code that is returned 

    //if number of argument is less than 4 and greater than 6 then return 2
    if (argc < 4 || argc > 6)
        return 2;

    //set special ops value to none
    cmd.specOps = NONE;

    //sets the output file name to outFileName
    cmd.inFileName = argv[argc - 1];

    //sets the input file name to inFileName
    cmd.outFileName = argv[argc - 2];

    //add .ppm to the end of the output file
    cmd.outFileName += ".ppm";

    //if argument is not -oa or -ob then return 3
    if ((string)argv[argc - 3] != "-oa" && (string) argv[argc - 3] != "-ob")
        return 3;

    //if argument is -ob the set outPutType to Binary else Anscii
    if (string(argv[argc - 3]) == "-ob")
        cmd.outPutType = BINARY;
    else
        cmd.outPutType = ANSCII;

    //if there are more than 4 arguments then find special ops
    if (argc > 4 )
        //calls specOp to get the correct special op function
        errorCode = getSpecOps(cmd, argv);
    
    //if the specOps is not Brighten and has more than 5 arguments the return 6
    if (cmd.specOps != BRIGHTEN && argc == 6)
       return 6;

    //return error code to the calling function
    return errorCode;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function check the special operation and assigns the correct enum value
 * to each argument. If there are any issues with the input values then the
 * function returns the correct error code for the error.
 *
 * @param[in]     argv[] - the arguments that were passed in
 * @param[in,out] cmd - the structure that holds all of the cmd arguments
 *
 * @return 1 --command line arguments all check out
 * @return 4 --incorrect options were provided
 * @return 5 --brightness is less than -255 or greater than 255.
 *
 *****************************************************************************/

int getSpecOps(cmdArgs& cmd, char* argv[])
{
    
    //if the argument is equal to -n then set specOps to NEGATE
    if (string(argv[1]) == "-n")
        cmd.specOps = NEGATE;

    //if the argument is equal to -p then set specOps to SHARPEN
    else if (string(argv[1]) == "-p")
        cmd.specOps = SHARPEN;

    //if the argument is equal to -s then set specOps to SMOOTH
    else if (string(argv[1]) == "-s")
        cmd.specOps = SMOOTH;

    //if the argument is equal to -b then set specOps to Brighten and get
    //the amount of brighting
    else if (string(argv[1]) == "-b")
    {
        cmd.specOps = BRIGHTEN;
        cmd.bright = stoi(string(argv[2]));

        //checks the brighten score is between -255 and 255
        if (cmd.bright < -255 || cmd.bright > 255)
            return 5;
    }

    //if the argument is equal to -g or -c
    else if (string(argv[1]) == "-g" || string(argv[1]) == "-c")
    {
        //change file extension from .ppm to .pgm
        cmd.outFileName[cmd.outFileName.size() - 2] = 'g';

        //if argument is -g then set specOps to Grayscale
        if (string(argv[1]) == "-g")
            cmd.specOps = GRAYSCALE;

        //if argument is -c then set specOps to Contrast
        else if (string(argv[1]) == "-c")
            cmd.specOps = CONTRAST;
    }

    //if specOps is anything other than NONE return code 1.
    if (cmd.specOps != NONE)
        return 1;

    //else return code 4 no command giving
    else
        return 4;
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
        cout << "Invalid output option!" << endl << endl;

    //if the error code is 4 then print invalid special option provided
    else if (errorCode == 4)
        cout << "Invalid special option provided!" << endl << endl;

    //if the error code is 5 then print invalid brightness value
    else if (errorCode == 5)
        cout << "Invalid brightness value!" << endl << endl;

    //if the error code is 6 then the print invalid option
     else if (errorCode == 6)
        cout << "Brightness value with invalid option!" << endl << endl;

    //output usage statement 
    cout << "prog1.exe [option] -o[ab] basename image.ppm" << endl << endl;
    cout << "Option Codes" << setw(22) << "Option Name" << endl;
    cout << setw(10) << "-n" << setw(19) << "Negate" << endl;
    cout << setw(12) << "-b #" << setw(34)<< "Brighten by -255 to 255" << endl;
    cout << setw(10) << "-p" << setw(20) << "Sharpen" << endl;
    cout << setw(10) << "-s" << setw(19) << "Smooth" << endl;
    cout << setw(10) << "-g" << setw(22) << "GrayScale" << endl;
    cout << setw(10) << "-c" << setw(21) << "Contrast" << endl << endl;
    cout << "-o[ab]" << setw(51) << "--Determines if the file is to be ";
    cout << "output as binary or ASCII" << endl;
    cout << setw(10) << "a" << setw(25) << "ASCII output" << endl;
    cout << setw(10) << "b" << setw(26) << "Binary output" << endl << endl;
    cout << "basename" << setw(48) << "--The returning file name for the";
    cout << "new image" << endl;
    cout << "image.ppm" << setw(47) << "--The file name of the input file";
    cout << endl;

    //if function is called exit code 0
    exit(0);
}


/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This functions purpose is to zero out the new arrays that are required for
 * the smoothing and sharpening functions. 
 *
 * @param[in,out]     newRed - the new red 2d array
 * @param[in,out]     newGreen - the new green 2d array
 * @param[in,out]     newBlue - the new blue 2d array
 * @param[in]         picture - picture struct with the number of cols and rows
 *
 ****************************************************************************/

void setToZero(int**& newRed, int**& newGreen, int**& newBlue, image picture)
{
    int i, j; // temp int variables 

    //for i is 0 and less than rows run code
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 and less than cols run code
        for (j = 0; j < picture.cols; j++)
        {
            //set newRed, newBlue, and newGreen to 0;
            newRed[i][j] = 0;
            newBlue[i][j] = 0;
            newGreen[i][j] = 0;
        }
    }
}



