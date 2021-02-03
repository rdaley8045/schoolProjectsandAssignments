/** ***************************************************************************
 * @file
 *
 * @brief contains all of the image operations
 *****************************************************************************/
#include"netPBM.h"

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function obtains the starting pixel values of and image and stores
  * that value in a structure called currColor. These values are later used in 
  * the bucket fill function.
  *
  * @param[in,out]     currColor - structure to hold the value of the starting
  *                                position.
  * @param[in]         cmd - the command line structure the holds the starting
  *                          row and col location
  * @param[in]         pic - the images structure the holds the image
  *
  ****************************************************************************/

void startPixel(startColors& currColor, cmdArgs cmd, image pic)
{
    //the current red pixel value 
    currColor.red = pic.redgray[cmd.row][cmd.col];

    //the current green pixel value
    currColor.green = pic.green[cmd.row][cmd.col];

    //the current blue pixel value
    currColor.blue = pic.blue[cmd.row][cmd.col];
}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This is the primary function for the whole program. This function
  * recursively changes each pixel value in a image that is the same as the 
  * starting pixel value. 
  *
  * @param[in,out]     currColor - structure to hold the value of the starting
  *                                position.
  * @param[in]         row - the starting row that needs to changed
  * @param[in]         col - the starting column that needs to be changed
  * @param[in,out]     pic - the structure holding the pixel values for the 
                             image                                             
  * @param[in,out]     cmd - the structure holding the new pixel values.
  * 
  ****************************************************************************/

void bucketFill(startColors& currColor, int row, int col, image& pic,
    cmdArgs& cmd)
{
    //Base Cases
    //Case 1: if the row is less than 0 or more than the max row size or
    //the col is less than 0 or more than the max cols return the function
    if (row < 0 || row >= pic.rows || col < 0 || col >= pic.cols)
        return;

    //Case 2: if any of the pixel values does not equal the orignal starting 
    //value then return the function
    if (pic.redgray[row][col] != currColor.red ||
        pic.blue[row][col] != currColor.blue ||
        pic.green[row][col] != currColor.green)
        return;

    //Case 3: if all of the pixels already equals the value that its being 
    //changed to new value then return the function
    if (pic.redgray[row][col] == cmd.redPixel &&
        pic.blue[row][col] == cmd.bluePixel &&
        pic.green[row][col] == cmd.greenPixel)
        return;

    //replace the color at the current location
    pic.redgray[row][col] = cmd.redPixel;
    pic.blue[row][col] =cmd.bluePixel;
    pic.green[row][col] = cmd.greenPixel;

    //recursively call all in all directions
    //recursively call up a row until the function is returned
    bucketFill(currColor, row + 1, col, pic, cmd);
    //recursively call down a row until the function is returned
    bucketFill(currColor, row - 1, col, pic, cmd);
    //recursively call to the right until the function is returned
    bucketFill(currColor, row, col + 1, pic, cmd);
    //recursively call to the left until the function is returned
    bucketFill(currColor, row, col - 1, pic, cmd);

}