/** ***************************************************************************
 * @file
 *****************************************************************************/
#include"netPBM.h"


 /** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function is designed to take in the number of cmd line arguments that
  * were passed in and check to make sure that the user put in the correct
  * number of arguments.
  *
  * @param[in]     numArgs - the number of argument that were passed in.
  *
  * @returns the value numArgs if values are 1,5 or 6.
  *
  ****************************************************************************/

int numCmdLines(int numArgs)
{
    //the number of arguments are either 4 or 5 then return that value back to 
    //the calling function.
    if (numArgs == 4 || numArgs == 5 || numArgs == 6)
        return numArgs;

    //if the number of arguments is not 4 or 5 then call the invalidCMD 
    //that prints out the usage message and then exits the program.
    else
    {
        invalidCmd();

        exit(0);
    }
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function will take in a C++ string and check each argument to
 * ensure that the correct option are being called. 
 *
 * @param[in,out]     arg - the arguments from the command line
 * @param[in]         numArgs - the number of argument that were passed in.

 * 
 * @returns  the values true or false depending if all the command line 
 * arguments are entered correctly.
 *
 ****************************************************************************/

bool cmdCheck(string*& arg, int numArgs)
{
    bool check; //if argument is true or false;

    //checks to make sure that the last part of the name is a .ppm file
    if (arg[numArgs - 1].assign(arg[numArgs - 1].end() - 4, arg[numArgs - 1]
        .end()) == ".ppm")
        check = true;

    //check that filename does not start with '-'
    if (arg[numArgs - 2][0] != '-')
        check = true;

    //checks to make sure that the 3 argument form the end is always -oa or -ob
    if (arg[numArgs - 3] == "-oa" || arg[numArgs - 3] == "-ob")
        check = true;

    //if the number of arguments are either 5 or 6
    if (numArgs == 5 || numArgs == 6)
    {
        //if the number of arguments are 6 and the 1st argument is a -b command
        if (numArgs == 6 && arg[1] == "-b")
        {
            //then check to make sure that the number is between -255 and 255
            if (stoi(arg[2]) > -255 && stoi(arg[2]) < 255)
                check = true;
        }
        
        //argument is equal to -n then true
        else if (arg[1] == "-n")
            check = true;

        //argument is equal to -b then true
        else if (arg[1] == "-b")
            check = true;

        //argument is equal to -p then true
        else if (arg[1] == "-p")
            check = true;

        //argument is equal to -s then true
        else if (arg[1] == "-s")
            check = true;

        //argument is equal to -g then true
        else if (arg[1] == "-g")
            check = true;

        //argument is equal to -c then true
        else if (arg[1] == "-c")
            check = true;
    }

    //Returns true or false back to the calling function.
    return check;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 *This functions purpose is to output the usage statement to the user if they
 * fail to correctly input the commands required for the program to run.
 * Additional if this function is to be ran, after outputting the usage
 * statement the program will auto exit with a code 0.
 *
 *
 ****************************************************************************/

void invalidCmd()
{
    //output usage statement 
    cout << "prog1.exe [option] -o[ab] basename image.ppm" << endl << endl;
    cout << "Option Codes" << setw(22) << "Option Name" << endl;
    cout << setw(10) << "-n" << setw(19) << "Negate" << endl;
    cout << setw(12) << "-b #" << setw(28) << "Brighten by 0-255" << endl;
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

