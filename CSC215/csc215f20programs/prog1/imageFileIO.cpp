/** ***************************************************************************
 * @file
 * 
 * @brief contains all of the function required for file input and output
 *****************************************************************************/
#include"netPBM.h"

 /** **************************************************************************
   * @author Raymond Daley
   *
   * @par Description:
   * This function takes in the input and output file stream and the command
   * structures and opens up each file. If the file fails to open then output
   * an error message.
   *
   * @param[in,out]     fin - input file stream.
   * @param[in,out]     fout - output file stream
   * @param[in,out]     cmd - command line structure
   *
   ***************************************************************************/

void openFile(ifstream& fin, ofstream &fout, cmdArgs &cmd)
{
    //opens the image file
    fin.open(cmd.inFileName.c_str(), ios::in | ios::binary);
    //opens the output file
    fout.open(cmd.outFileName.c_str(), ios::out | ios::trunc | ios::binary);

    //checks to see if the file image is open
    if (!fin.is_open())
    {
        //if file failed to out output message
        cout << "Input file failed to open!" << endl;

        //close the fout file
        fout.close();

        //exit the program code 0
        exit(0);
    }

    //checks to see if the output file image is open
    if (!fout.is_open())
    {
        //if file failed to out output message
        cout << "Output file failed to open!" << endl;

        //close input file
        fin.close();

        //exit the program code 0
        exit(0);
    }

}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function reads in all of the image information. After reading in all
  * of the data then it stores the information in to a structure called picture
  * which is passed by reference.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     fin - input file stream of the file
  *
  ****************************************************************************/

void readImage(image& picture, ifstream& fin)
{
    //call readHeader which will read in the header information from the file
    readHeader(picture, fin);

    //allocate the readgray array
    alloc2dchar(picture.redgray, picture.rows, picture.cols);
    
    //allocate the green array
    alloc2dchar(picture.green, picture.rows, picture.cols);

    //allocate the blue array

    alloc2dchar(picture.blue, picture.rows, picture.cols);

    //if encodeType == P3 read ASCII
    if (picture.encodeType == "P3")
        readInAnscii(picture, fin);

    //else encodeType == P6 read Binary
    else
        readInBinary(picture, fin);


}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function read in the header information. After reading in all
  * of the data then it stores the information in to a structure called picture
  * which is passed by referrance.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     fin - the input file stream
  *
  ****************************************************************************/

void readHeader(image& picture, ifstream& fin)
{
    char check; // temp variable to hold the peek value
    string temp; //Holds the comment line after the peek value

    //gets the encoding type from the beginning of the file
    getline(fin, picture.encodeType);

    //peeks at the next charactor and stores value
    check = fin.peek();

    //while check equals # then continue to get comments until not #
    while (check == '#')
    {
        //takes in the first line and stores the value in to temp
        getline(fin, temp);

        //if the comment size is not 0 then add newline to end of line.
        if (picture.comment.size() != 0)
            picture.comment.push_back('\n');

        //append temp to comment
        picture.comment += temp;

        //peek at the next line.
        check = fin.peek();

    }

    //get the cols from the header
    fin >> picture.cols;

    //get the rows from the hearder
    fin >> picture.rows;

    //get the key from the header
    fin >> picture.key;
} 

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function reads in the ascii code in to 3 dynamically allocated arrays.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     fin - the input file stream
  *
  ****************************************************************************/

void readInAnscii(image& picture, ifstream& fin)

{
    int i, j; //temp integer variables
    int red, green, blue; //temp red, green, blue

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            fin >> red >> green >> blue;
            //get the red array filled
            picture.redgray[i][j] = red;

            //get the green array filled
            picture.green[i][j] = green;

            //get the blue array filled
            picture.blue[i][j] = blue;

        }
    }
}


/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  *This function reads in the binary code in to 3 dynamically allocated arrays.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     fin - the input file stream
  *
  ****************************************************************************/

void readInBinary(image& picture, ifstream& fin)
{
    int i, j; //temp integer variables
    int red, green, blue; //temp red, green, blue

    fin.ignore(); //ignore an blank spaces prior to the data

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //get the red array filled
            fin.read((char*) &red, sizeof(pixel));

            //get the green array filled
            fin.read((char*) &green, sizeof(pixel));

            //get the blue array filled
            fin.read((char*) &blue, sizeof(pixel));

            //copy temp values in to pixel arrays
            picture.redgray[i][j] = red;
            picture.green[i][j] = green;
            picture.blue[i][j] = blue;
        }
    }
}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  *This function looks at which type of file out put is required and calls
  * the corresponding output function. 
  *
  * @param[in]         picture - struct to hold all the data in the image
  * @param[in]         cmd - the struct that hold all of the cmd arguments
  * @param[in,out]     fout - the output file stream
  *
  ****************************************************************************/

void writeImage(image picture, cmdArgs cmd, ofstream& fout)
{
    //if the special operations code is not gray scale or contrast
    if (cmd.specOps != GRAYSCALE && cmd.specOps != CONTRAST)
    {
        //if the output type is ANSCII then output anscii file
        if (cmd.outPutType == ANSCII)
        {
            //if picture encode type is p6 or p5 then subtract by 3
            if (picture.encodeType == "P6" || picture.encodeType == "P5")
                picture.encodeType.at(1) -= 3;

            //write the colored image as an Anscii
            writeColorAnsciiFile(picture, fout);
        }
        //else output image as binary
        else
        {
            //if picture encode type is p3 or p2 then add by 3
            if (picture.encodeType == "P3" || picture.encodeType == "P2")
                picture.encodeType.at(1) += 3;

            //write the color image as a binary file
            writeColorBinaryFile(picture, fout);
        }
    }
    //if grayscale or contrast
    else 
        //if the output type is ANSCII then output anscii file
        if (cmd.outPutType == ANSCII)
        {
            //change encode type to P2
            picture.encodeType = "P2";

            //write the gray image as anscii
            writeGrayAnsciiFile(picture, fout);
        }
        //else output image as binary
        else
        {
            //change encode type to  P5
            picture.encodeType = "P5";
            
            //write the gray image as a binary file
            writeGrayBinaryFile(picture, fout);
        }

}




/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function writes the color ascii image.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     fout - the output file stream
  *
  ****************************************************************************/

void writeColorAnsciiFile(image& picture, ofstream& fout)
{
    int i, j; //temp  integer variables


    //output the header information
    fout << picture.encodeType << endl;
    fout << picture.comment << endl;
    fout << picture.cols << " " << picture.rows << endl;
    fout << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //get the red array filled
            fout << (int)picture.redgray[i][j] << " ";

            //get the green array filled
            fout << (int)picture.green[i][j] << " ";

            //get the blue array filled
            fout << (int)picture.blue[i][j] << endl;

        }
    }

}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  *This function outputs the a binary color image
  *
  * @param[in,out]     picture - structure to hold all the data in the image
  * @param[in,out]     fout - the output file stream
  *
  ****************************************************************************/

void writeColorBinaryFile(image& picture, ofstream& fout)
{
    int i, j; //temp  integer variables
    int red, green, blue; //temp value that hold the values for red,green,blue


    //print out the header information
    fout << picture.encodeType << endl;
    fout << picture.comment << endl;
    fout << picture.cols << " " << picture.rows << endl;
    fout << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //copy pixel value to red then output as binary
            red = picture.redgray[i][j];
            fout.write((char*)&red, sizeof(pixel));

            //copy pixel value to green then output as binary
            green = picture.green[i][j];
            fout.write((char*)&green, sizeof(pixel));

            //copy pixel value to blue then output as binary
            blue = picture.blue[i][j];
            fout.write((char*)&blue, sizeof(pixel));
            
        }
    }
}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  *This function writes the gray ascii image.
  *
  * @param[in,out]     picture - struct to hold all the data in the image
  * @param[in,out]     fout - the output file stream
  *
  ****************************************************************************/

void writeGrayAnsciiFile(image& picture, ofstream& fout)
{
    int i, j; //temp  integer variables

    //print out the header information
    fout << picture.encodeType << endl;
    fout << picture.comment << endl;
    fout << picture.cols << " " << picture.rows << endl;
    fout << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //get the red array filled
            fout << (int)picture.redgray[i][j] << endl;

        }
    }

}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  *This function outputs the a binary color image
  *
  * @param[in,out]     picture - struct to hold all the data in the image
  * @param[in,out]     fout - the output file stream
  *
  ****************************************************************************/

void writeGrayBinaryFile(image& picture, ofstream& fout)
{
    int i, j; //temp  integer variables
    int gray; //temp value to hold the pixel value

    //print out the header information
    fout << picture.encodeType << endl;
    fout << picture.comment << endl;
    fout << picture.cols << " " << picture.rows << endl;
    fout << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //copy pixel value to gray then output as binary
            gray = picture.redgray[i][j];
            fout.write((char*)&gray, sizeof(pixel));

        }
    }
}