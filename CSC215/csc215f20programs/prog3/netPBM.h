/** **************************************************************************
 * @file
 * 
 * @brief this is the header file for the program. It includes all of the 
 * programs includes, structures, enums, and function prototypes.
 ****************************************************************************/


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

#ifndef __NETPBM__H__
#define __NETPBM__H__


/**
* @brief An unsigned char that contains the value of a pixel
*/

typedef unsigned char pixel;


/**
 * @brief Holds data about an image.
 */
struct image
{
    string encodeType;  /**< The encoding type for the file */
    string comment;     /**< Any comments in the file */
    int rows;           /**< Rows for a 2d array */
    int cols;           /**< Columns for a 2d array */
    int key;            /**< hold the key value for the program */
    pixel** redgray = nullptr;    /**< Handles the red and gray channels */
    pixel** green = nullptr;      /**< Handles the green channel */
    pixel** blue = nullptr;       /**< Handles the blue channels */
    double max = 0;                  /**<Stores the max gray value*/
    double min = 255;                  /**<Holds the min gray value*/
};


/**
 * @brief Hold all of the command line arguments
 */

struct cmdArgs
{
    string fileName;     /**< Handles the input file name   */
    int row;             /**< Row in which to start fill at */
    int col;             /**< Col in which to start fill at */
    int redPixel;        /**< New red pixel value           */
    int greenPixel;      /**< New green pixel value         */
    int bluePixel;       /**< New blue pixel value          */
};

/**
 * @brief Hold all of the starting pixel values
 */

struct startColors
{
    pixel red;          /**< Holds the original red pixel value  */
    pixel green;        /**< Holds the original green pixel value*/
    pixel blue;         /**< Holds the original blue pixel value */
};

//functional prototypes
int checkedCmd(int argc, char* argv[], cmdArgs& cmd);

void alloc2dchar(pixel**& ptr, int rows, int cols);

void free2dchar(pixel**& ptr, int rows);

void invalidCmd(int errorCode);

void openFile(ifstream& file, cmdArgs& cmd);

void readImage(image& picture, ifstream& file);

void readHeader(image& picture, ifstream& file);

void readInAnscii(image& picture, ifstream& file);

void readInBinary(image& picture, ifstream& file);

void writeImage(image picture, ofstream& ofile);

void writeColorAnsciiFile(image& picture, ofstream& ofile);

void writeColorBinaryFile(image& picture, ofstream& ofile);

void alloc2dint(int**& ptr, int rows, int cols);

void free2dint(int**& ptr, int rows);

void startPixel(startColors& currColor, cmdArgs cmd, image pic);

void bucketFill(startColors& currColor, int row, int col, image &pic,
    cmdArgs &cmd);

void openoFile(ofstream& ofile, cmdArgs& cmd);


#endif // !__NETPBM__H__
