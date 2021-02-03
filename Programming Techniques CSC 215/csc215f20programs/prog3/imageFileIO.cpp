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
   * This function purpose is strictly to open the file that was passed in 
   * from the command line. It opens the file using a ifstream so that the file
   * can be read in. Added feature to the file
   * opening is the binary operations.
   *
   * @param[in,out]     file - input/output file stream.
   * @param[in,out]     cmd - command line structure
   *
   ***************************************************************************/

void openFile(ifstream& file, cmdArgs &cmd)
{
    //opens the image file
    file.open(cmd.fileName.c_str(), ios::in | ios::binary);


    //checks to see if the file image is open
    if (!file.is_open())
    {
        //if file failed to out output message
        cout << "File failed to open!" << endl;

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
  * @param[in,out]     picture - structure to hold all the data in the image
  * @param[in,out]     file - file stream
  *
  ****************************************************************************/

void readImage(image& picture, ifstream& file)
{
    //call readHeader which will read in the header information from the file
    readHeader(picture, file);

    //allocate the read gray array
    alloc2dchar(picture.redgray, picture.rows, picture.cols);
    
    //allocate the green array
    alloc2dchar(picture.green, picture.rows, picture.cols);

    //allocate the blue array

    alloc2dchar(picture.blue, picture.rows, picture.cols);

    //if encodeType == P3 read ASCII
    if (picture.encodeType == "P3")
        readInAnscii(picture, file);

    //else encodeType == P6 read Binary
    else
        readInBinary(picture, file);


}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function read in the header information. After reading in all
  * of the data then it stores the information in to a structure called picture
  * which is passed by reference.
  *
  * @param[in,out]     picture - structure to hold all the data in the image
  * @param[in,out]     file - the file stream
  *
  ****************************************************************************/

void readHeader(image& picture, ifstream& file)
{
    char check; // temp variable to hold the peek value
    string temp; //Holds the comment line after the peek value

    //gets the encoding type from the beginning of the file
    getline(file, picture.encodeType);

    //peeks at the next charactor and stores value
    check = file.peek();

    //while check equals # then continue to get comments until not #
    while (check == '#')
    {
        //takes in the first line and stores the value in to temp
        getline(file, temp);

        //if the comment size is not 0 then add newline to end of line.
        if (picture.comment.size() != 0)
            picture.comment.push_back('\n');

        //append temp to comment
        picture.comment += temp;

        //peek at the next line.
        check = file.peek();

    }

    //get the cols from the header
    file >> picture.cols;

    //get the rows from the hearder
    file >> picture.rows;

    //get the key from the header
    file >> picture.key;
}

/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function reads in the ascii code in to 3 dynamically allocated arrays.
  *
  * @param[in,out]     picture - structure to hold all the data in the image
  * @param[in,out]     file - the file stream
  *
  ****************************************************************************/

void readInAnscii(image& picture, ifstream& file)

{
    int i, j; //temp integer variables
    int red, green, blue; //temp red, green, blue

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            file >> red >> green >> blue;
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
  * @param[in,out]     picture - structure to hold all the data in the image
  * @param[in,out]     file - the file stream
  *
  ****************************************************************************/

void readInBinary(image& picture, ifstream& file)
{
    int i, j; //temp integer variables
    int red, green, blue; //temp red, green, blue

    file.ignore(); //ignore an blank spaces prior to the data

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //get the red array filled
            file.read((char*) &red, sizeof(pixel));

            //get the green array filled
            file.read((char*) &green, sizeof(pixel));

            //get the blue array filled
            file.read((char*) &blue, sizeof(pixel));

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
  * This function looks at which type of input file the original image was and
  * writes the output file to match the input file.
  *
  * @param[in]         picture - struct to hold all the data in the image
  * @param[in,out]     ofile - the file stream
  *
  ****************************************************************************/

void writeImage(image picture, ofstream& ofile)
{
    
        //if the output type is ANSCII then output anscii file
    if (picture.encodeType == "P3")
    {
        //write the colored image as an Anscii
        writeColorAnsciiFile(picture, ofile);
    }
        //else output image as binary
    else
    {
        //write the color image as a binary file
        writeColorBinaryFile(picture, ofile);
    }
  

}




/** ***************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function writes the color ascii image.
  *
  * @param[in,out]     picture - sturcture to hold all the data in the image
  * @param[in,out]     ofile - the file stream
  *
  ****************************************************************************/

void writeColorAnsciiFile(image& picture, ofstream& ofile)
{
    int i, j; //temp  integer variables


    //output the header information
    ofile << picture.encodeType << endl;
    ofile << picture.comment << endl;
    ofile << picture.cols << " " << picture.rows << endl;
    ofile << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //get the red array filled
            ofile << (int)picture.redgray[i][j] << " ";

            //get the green array filled
            ofile << (int)picture.green[i][j] << " ";

            //get the blue array filled
            ofile << (int)picture.blue[i][j] << endl;

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
  * @param[in,out]     ofile - the file stream
  *
  ****************************************************************************/

void writeColorBinaryFile(image& picture, ofstream& ofile)
{
    int i, j; //temp  integer variables
    int red, green, blue; //temp value that hold the values for red,green,blue


    //print out the header information
    ofile << picture.encodeType << endl;
    ofile << picture.comment << endl;
    ofile << picture.cols << " " << picture.rows << endl;
    ofile << picture.key << endl;

    //loop to get the rows filled up
    for (i = 0; i < picture.rows; i++)
    {
        //loop to get the columns filled up
        for (j = 0; j < picture.cols; j++)
        {
            //copy pixel value to red then output as binary
            red = picture.redgray[i][j];
            ofile.write((char*)&red, sizeof(pixel));

            //copy pixel value to green then output as binary
            green = picture.green[i][j];
            ofile.write((char*)&green, sizeof(pixel));

            //copy pixel value to blue then output as binary
            blue = picture.blue[i][j];
            ofile.write((char*)&blue, sizeof(pixel));
            
        }
    }
}


/** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function purpose is strictly to open the file that was passed in
  * from the command line. It opens the file using a ofstream so that the file
  * can be written back out on. Added feature to the file opening is the trunc 
  * and binary operations.
  *
  * @param[in,out]     ofile - input/output file stream.
  * @param[in,out]     cmd - command line structure
  *
  ***************************************************************************/

void openoFile(ofstream& ofile, cmdArgs& cmd)
{
    //opens the image output file
    ofile.open(cmd.fileName.c_str(), ios::out | ios::trunc | ios::binary);


    //checks to see if the file image is open
    if (!ofile.is_open())
    {
        //if file failed to out output message
        cout << "File failed to open!" << endl;

        //exit the program code 0
        exit(0);
    }


}

