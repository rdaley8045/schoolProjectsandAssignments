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

void openFile(ifstream& fin, int numArgs, string*& cmdLine)
{
    //opens the image file
    fin.open(cmdLine[numArgs - 1].c_str(), ios::in | ios::out | ios::ate |
        ios::binary);

    //checks to see if the file image is open
    if (fin.is_open())
    {
        //if file failed to out output message
        cout << "File failed to open!";

        //clear the cmdLine array
        delete[] cmdLine;

        //exit the program code 0
        exit(0);
    }
}