/** ***************************************************************************
 * @file
 * 
 * @brief contains all of the function necessary to allocate memory
 *****************************************************************************/
#include"netPBM.h"

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function allocates a 2d array of type char. Allocates however many
 * rows and col that are needed.
 *
 * @param[in,out]     ptr - the address ptr for the array to be built
 * @param[in]         rows - the number of rows
 * @param[in]         cols - the number of columns
 *
 *
 *****************************************************************************/

void alloc2dchar(pixel**& ptr, int rows, int cols)
{
    int i; //temp value for a loop counter

    //creates a dynamice on 1d array for pointer
    ptr = new (nothrow) pixel* [rows];


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
        ptr[i] = new (nothrow) pixel[cols];


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
 * This function is designed to free up a 2d char array that is allocated.
 *
 * @param[in,out]     ptr - the address ptr for the array to be built
 * @param[in]         rows - the number of rows
 * 
 * @returns the value numArgs if values are 1,5 or 6.
 *
 *****************************************************************************/

void free2dchar(pixel**& ptr, int rows)
{
    int i; //temp varible for a counter

    //if the 1d array of rows is not allocated then exit program
    if (ptr == nullptr)
        exit(0);

    //if the 1d array of rows is allocated walk through each row clearing
    //the memory of columns and then clear the memory for the rows.
    for (i = 0; i < rows; i++)
        delete[] ptr[i];

    delete[] ptr;

    //set point to nullptr.
    ptr = nullptr;
}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function allocates a 2d array of type char. Allocates however many
 * rows and col that are needed.
 *
 * @param[in,out]     ptr - the address ptr for the array to be built
 * @param[in]         rows - the number of rows
 * @param[in]         cols - the number of columns
 *
 *
 *****************************************************************************/

void alloc2dint(int**& ptr, int rows, int cols)
{
    int i; //temp value for a loop counter

    //creates a dynamice on 1d array for pointer
    ptr = new (nothrow) int * [rows];


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
        ptr[i] = new (nothrow) int[cols];


        //error check to make sure that the memory was allocated
        if (ptr[i] == nullptr)
        {
            //call the function free2dchar and clear the memory that was 
            //alocated
            free2dint(ptr, i);

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
 * This function is designed to free up a 2d int array of its memory.
 *
 * @param[in,out]     ptr - the address ptr for the array to be built
 * @param[in]         rows - the number of rows
 *
 * @returns the value numArgs if values are 1,5 or 6.
 *
 *****************************************************************************/

void free2dint(int**& ptr, int rows)
{
    int i; //temp varible for a counter

    //if the 1d array of rows is not allocated then exit program
    if (ptr == nullptr)
        exit(0);

    //if the 1d array of rows is allocated walk through each row clearing
    //the memory of columns and then clear the memory for the rows.
    for (i = 0; i < rows; i++)
        delete[] ptr[i];

    delete[] ptr;

    //set point to nullptr.
    ptr = nullptr;
}