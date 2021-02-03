/** ***************************************************************************
 * @file
 *
 * @brief contains the main function for the program.
 *****************************************************************************/

 /** *************************************************************************
  * @mainpage Program 3 - Flood Fill
  *
  * @section course_section Course Information
  *
  * @author Raymond Daley
  *
  * @par Professor:
  *         Roger Schrader
  *
  * @par Course:
  *         CSC215 - M001 - Programming Techniques
  *
  * @par Location:
  *         McLaury - 103F
  *
  * @date Due November 24, 2020
  *
  * @section program_section Program Information
  *
  * @details
  * This program is designed to take in an ASCII or binary image fill and 
  * perform a recursive bucket fill on the image. This is completed by running 
  * the program using command lines. Where the user must first enter in the 
  * file name of image, the row and column that they want to start the fill in
  * at and the color values that the user wants to select. Once the user enters
  * in the correct command is when the program starts running. 
  * 
  * Once the program starts running the first task that is performed is an 
  * error check of the command lines. After the command lines are verified then
  * the program opens up the files, then reads in the file information. After 
  * the file is read in then it closes the file in order for it to be open up
  * again as an output file stream. Additionally after closing the input file
  * stream the program obtains the starting values for the 3 pixels and then 
  * sends the image to the recursive algorithm that will fill in all of the 
  * space with one color. Once the program has completed the fill the output
  * file is open then written to. After everything has been written back to the
  * file the program close and returns code 0.
  *
  * @section compile_section Compiling and Usage
  *
  * @par Compiling Instructions:
  *        Set Stack Reserve Size and Stack Commit Size to 4000000000.
  * 
  * @par Usage:
    @verbatim
    c:\> prog3.exe imageFile.ppm column row redPixel greenPixel bluePixel

            imageFile.ppm              -image file to input and output to
            column                     -the column to start the fill at
            row                        -the row to start the fill at
            redPixel                   -red pixel value between 0 and 255
            greenPixel                 -green pixel value between 0 and 255
            bluePixel                  -blue pixel value between 0 and 255

    @endverbatim
  *
  * @section todo_bugs_modification_section Todo, Bugs, and Modifications
  *
  * @bug None
  *
  * @todo None
  *
  * @par Modifications and Development Timeline:
  * This is a link to gitlab's commit. To view <a target="_blank"
  * href = "https://gitlab.mcs.sdsmt.edu/101064397/csc215f20programs/-/commits/master"> click here.</a>
  *
  ****************************************************************************/

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
  * @param[in]      argv - the arguments that are passed in.
  *
  * @returns code 0 program ran successfully.
  *
  ****************************************************************************/


int main(int argc, char* argv[])
{
    int errorCode; //int variable for errorCode
    cmdArgs cmd; //structure of cmdArgs called cmd
    ifstream file; // input file stream
    ofstream ofile; //output file stream
    image picture; // structure of image called picture 
    startColors currColor; //structure of colors called currColor


    //check command line arguments
    errorCode = checkedCmd(argc, argv, cmd);

    //if error code is anything other than 1 output usage statement
    if (errorCode != 1)
        invalidCmd(errorCode);

    //open the file 
    openFile(file, cmd);

    //read the file
    readImage(picture, file);

    //close the input file stream
    file.close();

    //get starting values
    startPixel(currColor, cmd, picture);

    //perform the fill function
    bucketFill(currColor,cmd.row, cmd.col, picture, cmd);

    //open the output file
    openoFile(ofile, cmd);

    //write the image back to the file
    writeImage(picture, ofile);

    //close the output file stream
    ofile.close();

    //clear the char arrays for the 3 colors
    free2dchar(picture.redgray, picture.rows);
    free2dchar(picture.green, picture.rows);
    free2dchar(picture.blue, picture.rows);

}