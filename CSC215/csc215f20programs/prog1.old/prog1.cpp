/** ***************************************************************************
 * @file
 *****************************************************************************/
#include"netPBM.h"

 /** **************************************************************************
  * @author Your Raymond Daley
  *
  * @par Description:
  * This is the main function and where the program is ran through. The
  * function starts by taking in the a command line argument and has the 
  * arguments checked for correctness. Additionally the function process all of
  * the primary function of the program calling upon all the different 
  * function.
  *
  * @param[in]     argc - Number of argument that are passed in.
  * @param[int]    argv - the arguments that are passed in.
  * 
  * @returns code 0 program ran successfully.
  *
  ****************************************************************************/

int main(int argc, char* argv[])
{
    //1d array of string for holding the cmd arguments
    string* cmdLine;

    //integer variables
    int i, numArgs;

    //bool
    bool checked;

    ifstream fin;

    ofstream fout;


    //call the alloc1dString function to create a 1d array.
    alloc1dString(cmdLine, argc);

    //for loop to assign all of the c string values to a c++ string
    for (i = 0; i < argc; i++)
    {
        cmdLine[i].assign(argv[i]);
    }

    //calls the numCmdLines function to check the number of arguments and 
    //return back the number of arguments
    numArgs = numCmdLines(argc);

    //calls the cmdCheck function to determine if the cmd argument is valid
    //it returned back if the function is valid or not.
    checked = cmdCheck(cmdLine, numArgs);


    //if checked is equal to vales then run invalidCmd
    if (checked == false)
        invalidCmd();



    switch (numArgs)
    {
        case 4:
            //handles 4 command line arguments

            //if the argument 1 is -oa then run ASCII else run binary
            if (cmdLine[1] == "-oa")
                //optColorASCII() 
                cout << "test";
            else
                //optColorBinary()
                cout << "fail";

            break;

        case 5:
            //handles 5 command line arguments

            break;
            
        case 6:
            //handles 6 command line arguments
            
            break;

    }



    //close file
    fin.close();

    //program complete
    return 0;
}
