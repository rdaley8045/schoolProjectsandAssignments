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
 * @brief The 6 image operations, and a none spot for if there is not ops
 */
enum op {
    NONE,        /**< Blank Value               */
    NEGATE,      /**< Negates the image         */
    BRIGHTEN,    /**< Brightens the image       */
    SHARPEN,     /**< Sharpen the image         */
    SMOOTH,      /**< Smooth out the image      */                              
    GRAYSCALE,   /**< Gray out the image        */
    CONTRAST     /**< Make gray and add contrast*/
};

/**
 * @brief The 2 different types of file outputs
 */
enum codeType {
    BINARY,        /**< Binary File              */
    ANSCII         /**< Anscii file              */
};


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
//elements together.
/**
 * @brief Hold all of the command line arguments
 */

struct cmdArgs
{
    string inFileName;     /**< Handles the input file name  */
    string outFileName;    /**< Handles the output file name */
    codeType outPutType;   /**< Handles the output type for the file */
    op specOps;            /**< Handles the special operations cmds */
    int bright = 0;        /**< Handles the brightness value preset to 0*/

};

//functional prototypes
int checkedCmd(int argc, char* argv[], cmdArgs& cmd);

void alloc2dchar(pixel**& ptr, int rows, int cols);

void free2dchar(pixel**& ptr, int rows);

int getSpecOps(cmdArgs& cmd, char* argv[]);

void invalidCmd(int errorCode);

void openFile(ifstream& fin, ofstream& fout, cmdArgs& cmd);

void readHeader(image& picture, ifstream& fin);

void readImage(image& picture, ifstream& fin);

void readInAnscii(image& picture, ifstream& fin);

void readInBinary(image& picture, ifstream& fin);

void writeImage(image picture, cmdArgs cmd, ofstream& fout);

void writeColorAnsciiFile(image& picture, ofstream& fout);

void writeColorBinaryFile(image& picture, ofstream& fout);

void performOps(image& picture, cmdArgs cmd);

void negateOp(image& picture);

void brightenOp(image& picture, int bright);

void sharpenOps(image& picture);

void smoothOps(image& picture);

void grayscaleOps(image& picture);

void contrastOps(image& picture);

void writeGrayAnsciiFile(image& picture, ofstream& fout);

void writeGrayBinaryFile(image& picture, ofstream& fout);

void alloc2dint(int**& ptr, int rows, int cols);

void free2dint(int**& ptr, int rows);

void setToZero(int**& newRed, int**& newGreen, int**& newBlue, image picture);

void cropImage(int** newRed, int** newGreen, int** newBlue, image& picture);

#endif // !__NETPBM__H__
