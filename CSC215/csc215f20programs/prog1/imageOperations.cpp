/** ***************************************************************************
 * @file
 * 
 * @brief contains all of the function necessary to perform image operations
 *****************************************************************************/
#include"netPBM.h"

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function is designed take in the picture and the command line 
 * arguments and choose the correct function to perform the operation with. 
 *
 * @param[in,out]     picture - the image struct needing to be modified
 * @param[in]         cmd - the command struct that contains the operation code 
 * 
 *****************************************************************************/

void performOps(image& picture, cmdArgs cmd)
{
    //if the operation code is NEGATE then run negateOp
    if (cmd.specOps == NEGATE)
        negateOp(picture);
    //if the operation code is BRIGHTEN then run brightenOp
    else if (cmd.specOps == BRIGHTEN)
        brightenOp(picture, cmd.bright);
    //if the operation code is SHARPEN then run sharpenOps
    else if (cmd.specOps == SHARPEN)
        sharpenOps(picture);
    //if the operation code is SMOOTH then run smoothOps
    else if (cmd.specOps == SMOOTH)
        smoothOps(picture);
    //if the operation code is GRAYSCALE then run grayscaleOps
    else if (cmd.specOps == GRAYSCALE)
        grayscaleOps(picture);
    //if the operation code is CONTRAST then run contrastOps
    else if (cmd.specOps == CONTRAST)
        contrastOps(picture);
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in a image and negates the image file. 
 *
 * @param[in,out]     picture - the image struct needing to be modified
 *
 *****************************************************************************/


void negateOp(image& picture)
{
    int i, j; // temp integer files

    //for i is 0 or greater and less than rows perform operation
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 or greater and less then cols perform operation
        for (j = 0; j < picture.cols; j++)
        {
            //subtract 255 from a the pixel value that need to be type casted
            picture.redgray[i][j] = 255 - (int)picture.redgray[i][j];
            picture.green[i][j] = 255 - (int)picture.green[i][j];
            picture.blue[i][j] = 255 - (int)picture.blue[i][j];
        }
    }
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in an image and brightens it by a power of what ever 
 * the user inputs in the cmd line. 
 *
 * @param[in,out]     picture - the image struct needing to be modified
 * @param[in]         bright - the value the image need to be modified by
 *
 *****************************************************************************/


void brightenOp(image& picture, int bright)
{
    int i, j; //temp integer values

    //for i is 0 or greater and less than rows perform operation
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 or greater and less then cols perform operation
        for (j = 0; j < picture.cols; j++)
        {
            //if brighten red pixel is greater than 255 crop to 255
            if (((int)picture.redgray[i][j] + bright) > 255)
                picture.redgray[i][j] = 255;
            //if brighten red pixel is less than 0 then crop to 0
            else if (((int)picture.redgray[i][j] + bright) < 0)
                picture.redgray[i][j] = 0;
            //else brighten pixel is the new value
            else
                picture.redgray[i][j] = (int)picture.redgray[i][j] + bright;
            
            //if brighten green pixel is greater than 255 crop to 255
            if (((int)picture.green[i][j] + bright) > 255)
                picture.green[i][j] = 255;
            //if brighten green pixel is less than 0 then crop to 0
            else if (((int)picture.green[i][j] + bright) < 0)
                picture.green[i][j] = 0;
            //else brighten pixel is the new value
            else
                picture.green[i][j] = (int)picture.green[i][j] + bright;

            //if brighten blue pixel is greater than 255 crop to 255
            if (((int)picture.blue[i][j] + bright) > 255)
                picture.blue[i][j] = 255;
            //if brighten blue pixel is less than 0 then crop to 0
            else if (((int)picture.blue[i][j] + bright) < 0)
                picture.blue[i][j] = 0;
            //else brighten pixel is the new value
            else
                picture.blue[i][j] = (int)picture.blue[i][j] + bright;
        }
    }
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function is designed take in the picture and sharpen the image.
 *
 * @param[in,out]     picture - the image struct needing to be modified
 * 
 *****************************************************************************/


void sharpenOps(image& picture)
{
    int** newRed = nullptr; //temp 2d array for red
    int** newGreen = nullptr; //temp 2d array for green 
    int** newBlue = nullptr; //temp 2d array for blue
    int i, j; //temp integer values

    //allocate the memory for the 3 new pixel 2d arrays
    alloc2dint(newRed, picture.rows, picture.cols);
    alloc2dint(newGreen, picture.rows, picture.cols);
    alloc2dint(newBlue, picture.rows, picture.cols);
    
    setToZero(newRed, newGreen, newBlue, picture);

    //for i is 1 or greater and less than rows perform operation
    for (i = 1; i < picture.rows - 1; i++)
    {
        //for j is 1 or greater and less then cols perform operation
        for (j = 1; j < picture.cols - 1; j++)
        {
            /*newRed is equal to the top, bottom, left and right values 
            subtracted from the middle value that is  multiplied by 5*/
            newRed[i][j] = 5 * (int)picture.redgray[i][j] -
                (int)picture.redgray[i - 1][j] - (int)picture.redgray[i][j - 1]
                - (int)picture.redgray[i][j + 1] -
                (int)picture.redgray[i + 1][j];
            
            /*newGreen is equal to the top, bottom, left and right values
            subtracted from the middle value that is  multiplied by 5*/
            newGreen[i][j] = 5 * (int)picture.green[i][j] -
                (int)picture.green[i - 1][j] - (int)picture.green[i][j - 1]
                - (int)picture.green[i][j + 1] -
                (int)picture.green[i + 1][j];

            /*newBlue is equal to the top, bottom, left and right values
            subtracted from the middle value that is  multiplied by 5*/
            newBlue[i][j] = 5 * (int)picture.blue[i][j] -
                (int)picture.blue[i - 1][j] - (int)picture.blue[i][j - 1]
                - (int)picture.blue[i][j + 1] -
                (int)picture.blue[i + 1][j];
        }
    }


    //run cropImage to store the values in the original arrays and crop if need
    //it
    cropImage(newRed, newGreen, newBlue, picture);

    //clear the new 2d arrays memory
    free2dint(newRed, picture.rows);
    free2dint(newGreen, picture.rows);
    free2dint(newBlue, picture.rows);

}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function is designed take in the picture and performs the smoothing 
 * operation.
 *
 * @param[in,out]     pic - the image struct needing to be modified
 *
 *****************************************************************************/

void smoothOps(image& pic)
{
    int** newRed = nullptr; //temp 2d array for red
    int** newGreen = nullptr; //temp 2d array for green
    int** newBlue = nullptr; //temp 2d array for blue
    int i, j; //temp integer values

    //allocate the memory for the 3 new pixel 2d arrays
    alloc2dint(newRed, pic.rows, pic.cols);
    alloc2dint(newGreen, pic.rows, pic.cols);
    alloc2dint(newBlue, pic.rows, pic.cols);

    //set all of the new arrays to  0
    setToZero(newRed, newGreen, newBlue, pic);

    //for i is 1 or greater and less than rows perform operation
    for (i = 1; i < pic.rows - 1; i++)
    {
        //for j is 1 or greater and less then cols perform operation
        for (j = 1; j < pic.cols - 1; j++)
        {
            /*newRed pixel array is equal to the all of the adjacent values
            summed together and divided by 9*/
            newRed[i][j] = (int)round((pic.redgray[i - 1][j - 1] +
                (int)pic.redgray[i - 1][j] + (int)pic.redgray[i - 1][j + 1]
                + (int)pic.redgray[i][j - 1] + (int)pic.redgray[i][j] +
                (int)pic.redgray[i][j + 1] + (int)pic.redgray[i + 1][j - 1]
                + (int)pic.redgray[i + 1][j] + (int)pic.redgray[i + 1][j + 1])
                / 9.0);

            /*newGreen pixel array is equal to the all of the adjacent values
            summed together and divided by 9*/
            newGreen[i][j] = (int)round((pic.green[i - 1][j - 1] +
                (int)pic.green[i - 1][j] + (int)pic.green[i - 1][j + 1]
                + (int)pic.green[i][j - 1] + (int)pic.green[i][j] +
                (int)pic.green[i][j + 1] + (int)pic.green[i + 1][j - 1]
                + (int)pic.green[i + 1][j] + (int)pic.green[i + 1][j + 1])
                / 9.0);

            /*newBlue pixel array is equal to the all of the adjacent values
            summed together and divided by 9*/  
            newBlue[i][j] = (int)round((pic.blue[i - 1][j - 1] +
                (int)pic.blue[i - 1][j] + (int)pic.blue[i - 1][j + 1]
                + (int)pic.blue[i][j - 1] + (int)pic.blue[i][j] +
                (int)pic.blue[i][j + 1] + (int)pic.blue[i + 1][j - 1]
                + (int)pic.blue[i + 1][j] + (int)pic.blue[i + 1][j + 1])
                / 9.0);
        }
    }
   //run cropImage to store the values in the original arrays and crop if need
    //it
    //run cropImage to store the values in the original arrays and crop if need
    //it
    cropImage(newRed, newGreen, newBlue, pic);

    //clear the new 2d arrays memory
    free2dint(newRed, pic.rows);
    free2dint(newGreen, pic.rows);
    free2dint(newBlue, pic.rows);

}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in a colored image and turns in into a gray image
 *
 * @param[in,out]     picture - the image struct needing to be modified
 *
 *****************************************************************************/


void grayscaleOps(image& picture)
{
    int i, j; //temp integer values

    //for i is 0 or greater and less than rows perform operation
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 or greater and less then cols perform operation
        for (j = 0; j < picture.cols; j++)
        {
            /*new gray pixel is equal to red time .3, green time .6 and 
            blue time .1*/
            picture.redgray[i][j] = (pixel)round(.3 * 
                (double)picture.redgray[i][j] + .6 *
                (double)picture.green[i][j] + .1 * (double)picture.blue[i][j]);

            //if gray pixel value is greater than max then max equals gray
            if (picture.redgray[i][j] > picture.max)
                picture.max = picture.redgray[i][j];
            //else if gray pixel value is less than min then min equals gray
            else if (picture.redgray[i][j] < picture.min)
                picture.min = picture.redgray[i][j];
        }
    }

}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function is designed take in the picture and covert it to grayscale
 * then adds contrast to the image. 
 *
 * @param[in,out]     picture - the image struct needing to be modified
 *
 *****************************************************************************/


void contrastOps(image& picture)
{
    int i, j; //temp integer values
    double scale, gray; //temp double variable to hold pixel and scale value

    //calls grayscaleOps and converts the image into a gray image
    grayscaleOps(picture);

    //scale is equal 255.0 divided by max pixel minus min pixel 
    scale = 255.0 / (picture.max - picture.min);
    
    //for i is 0 or greater and less than rows perform operation
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 or greater and less then cols perform operation
        for (j = 0; j < picture.cols; j++)
        {
            //gray is equal to scale time gray pixel minus the min
            gray =scale * ((double)picture.redgray[i][j] - picture.min);

            //if gray is greater then 255 then crop to 255
            if (gray > 255.0)
                picture.redgray[i][j] = 255;
            //if gray is less than 0 then crop to 0
            else if (gray < 0)
                picture.redgray[i][j] = 0;
            //else copy gray to 2d array
            else
                picture.redgray[i][j] = (int)gray;
        }
    }
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function is designed take in the red, green, and blue arrays from the 
 * smooth and sharpen function and copy their values into the original 
 * arrays. If they are above 255 and below 0 then the image gets cropped
 *
 * @param[in]         newRed - the new red pixel array
 * @param[in]         newGreen - the new green pixel array
 * @param[in]         newBlue - the new blue pixel array
 * @param[in,out]     picture - the image struct needing to be modified
 *
 *****************************************************************************/

void cropImage(int** newRed, int** newGreen, int** newBlue, image& picture)
{
    int i, j; //temp integer values
    
    //for i is 0 or greater and less than rows perform operation
    for (i = 0; i < picture.rows; i++)
    {
        //for j is 0 or greater and less then cols perform operation
        for (j = 0; j < picture.cols; j++)
        {
            //if newRed is greater than 255 then original array is 255
            if (newRed[i][j] > 255.0)
                picture.redgray[i][j] = 255;
            //if newRed is less than 0 then original array is 0
            else if (newRed[i][j] < 0)
                picture.redgray[i][j] = 0;
            //else original array is equal to newRed
            else
                picture.redgray[i][j] = newRed[i][j];

            //if newGreen is greater than 255 then original array is 255
            if (newGreen[i][j] > 255.0)
                picture.green[i][j] = 255;
            //if newGreen is less than 0 then original array is 0
            else if (newGreen[i][j] < 0)
                picture.green[i][j] = 0;
            //else original array is equal to newGreen
            else
                picture.green[i][j] = newGreen[i][j];

            //if newBlue is greater than 255 then original array is 255
            if (newBlue[i][j] > 255.0)
                picture.blue[i][j] = 255;

            //if newBlue is less than 0 then original array is 0
            else if (newBlue[i][j] < 0)
                picture.blue[i][j] = 0;
            //else original array is equal to newBlue
            else
                picture.blue[i][j] = newBlue[i][j];
        }
    }
}