/** ***************************************************************************
 * @file
 *****************************************************************************/
#include"netPBM.h"



 /** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function allocates a 1d array of type string. Allocates however many 
  * rows that the string needs to have inorder to store all of its data.
  *
  * @param[in,out]     prt - the address ptr for the array to be built
  * @param[in]         size - the size the array need to be
  *
  *
  ****************************************************************************/

void alloc1dString(string*& ptr, int size)
{
    //allocate a memory for a 1d array of string
    ptr = new(nothrow) string[size];

    //if unable to allocate the 1d array then clear memory, out put message,
    //exit and close the program.
    if (ptr == nullptr)
    {
        cout << "Unable to allocate memory!" << endl;
        delete[] ptr;
        exit(0);
    }
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function allocates a 2d array of type char. Allocates however many
 * rows and col that are needed.
 *
 * @param[in,out]     prt - the address ptr for the array to be built
 * @param[in]         row - the number of rows
 * @param[in]         cols - the number of columns 
 *
 *
 *****************************************************************************/

void alloc2dchar(char**& ptr, int rows, int cols)
{
    int i; //temp value for a loop counter

    //creates a dynamice on 1d array for pointer
    ptr = new (nothrow) char * [rows];


    //error check to make sure that the memory was allocated
    if (ptr == nullptr)
    {
        //if memory was not allocated then output "Unable to allocate mem"
        cout << "Unable to allocate memory!" << endl;

        //clear the 1d array
        delete[] ptr;

        //exit the program 
        exit(0);

    }


    //loop to create a list of 1d arrays that are attached to another 1d array
    //making a dynamic 2d array
    for (i = 0; i < rows; i++)
    {
        //allocats the memroy for a 1d array for each row that was created.
        ptr[i] = new (nothrow) char[cols];


        //error check to make sure that the memory was allocated
        if (ptr[i] == nullptr)
        {
            //call the function free2dchar and clear the memory that was 
            //alocated
            free2dchar(ptr, i);
            
            //if memory was not allocated then output "Unable to allocate mem"
            cout << "Unable to allocate memory!" << endl;

            //exit the program 
            exit(0);
        }

    }
}

/** ***************************************************************************
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
 *****************************************************************************/

void free2dchar(char**& ptr, int networkNum)
{
    int i; //temp varible for a counter

    //if the 1d array of rows is not allocated then exit program
    if (ptr == nullptr)
        exit(0);

    //if the 1d array of rows is allocated walk through each row clearing
    //the memory of columns and then clear the memory for the rows.
    for (i = 0; i < networkNum; i++)
        delete[] ptr[i];

    delete[] ptr;

    //set point to nullptr.
    ptr = nullptr;
}