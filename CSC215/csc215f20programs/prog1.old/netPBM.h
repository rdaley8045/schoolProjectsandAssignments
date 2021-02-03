/** **************************************************************************
 * @file
 ****************************************************************************/
 /** **************************************************************************
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
  * This is a link to gitlab's commit as an example. To view <a target="_blank"
  * href = "https://gitlab.mcs.sdsmt.edu/101064397/csc215f20programs/-/commits/master"> click here.</a>
  *
  ****************************************************************************/


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

#ifndef __NETPBM__H__
#define __NETPBM__H__


/**
* @brief An unsigned char that contains the value of a pixel
*/

typedef unsigned char pixel;


//date structure called image combining row, cols, redgray, green, and blue
//elements together.
/**
 * @brief Holds data about an image.
 */
struct image
{
    string encodeType; /**< The encoding type for the file */
    string comment; /**< Any comments in the file */
    int rows;  /**< Rows for a 2d array */
    int cols;  /**< Columns for a 2d array */
    int key; /**< hold the key value for the program */
    pixel** redgray; /**< Handles the red and gray channels */
    pixel** green; /**< Handles the green channel */
    pixel** blue; /**< Handles the blue channels */
};

//functional prototypes
void alloc1dString(string*& ptr, int size);

void alloc2dchar(char**& ptr, int rows, int cols);

void free2dchar(char**& ptr, int networkNum);

void invalidCmd();

int numCmdLines(int numArgs);

bool cmdCheck(string*& arg, int numArgs);



#endif // !__NETPBM__H__
