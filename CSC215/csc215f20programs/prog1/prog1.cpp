/** ***************************************************************************
 * @file
 * 
 * @brief contains the main function for the program.
 *****************************************************************************/

  /** *************************************************************************
   * @mainpage Program 1 - Image Manipulation
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
   * @date Due October 16, 2020
   *
   * @section program_section Program Information
   *
   * @details
   * This program is designed to take in either a binary or ascii .ppm image
   * file and perform multiple operations on it. Program initial starts by
   * taking in a color image file and storing either the ascii or binary
   * information for the image in a dynamically allocated 2d array. After
   * storing the image the user has to option to either convert the image from
   * ascii to binary or binary to ascii. Additionally the user also has the
   * option to perform various task to the image, such as Negate, Brighten,
   * Sharpen, Smooth, Grayscale, or contrast the image. After the task has been
   * completed the images in then outputted to the user using which ever file
   * formate that they choice.
   *
   * @section compile_section Compiling and Usage
   *
   * @par Compiling Instructions:
   *      none - a straight compile and link with no external libraries.
   *
   * @par Usage:
     @verbatim
     c:\> prog1.exe [option] -o[ab] basename image.ppm

                 Option code             Option Name
                         -n              Negate
                         -b #            Brighten by x factor
                         -p              Sharpen
                         -s              Smooth
                         -g              Grayscale
                         -c              Contrast

                 -o[ab] -- Determines if the file is to be output as binary
                             or ascii
                 basename -- The returning file name for the new image
                 image.ppm -- The file name of the input file

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
    int errorCode; // the error code that is returned 
    cmdArgs cmd; //structure called cmd
    ifstream fin; //input file stream
    ofstream fout; // output file stream
    image picture; //image structure

    //calling checkedCmd to error check and assign the value to cmdArg Struct
    errorCode = checkedCmd(argc, argv, cmd);

    //if error code is greater than 1 then output error message
    if (errorCode > 1)
        invalidCmd(errorCode);

    //opens the file
    openFile(fin, fout, cmd);


    //read images
    readImage(picture, fin);

    //if the Operation call is none then
    if (cmd.specOps == NONE)
    {
        //write image
        writeImage(picture, cmd, fout);
    }

    //else the operation call is other than none
    else
    {
        //perform the operation called
        performOps(picture, cmd);

        //write the image
        writeImage(picture, cmd, fout);
    }

    // cleanup files and arrays.
    //close the input file
    fin.close();
    //close the output file
    fout.close();
    //clear the char arrays for the 3 colors
    free2dchar(picture.redgray, picture.rows);
    free2dchar(picture.green, picture.rows);
    free2dchar(picture.blue, picture.rows);

    //closes program as all clear
    return 0;
}