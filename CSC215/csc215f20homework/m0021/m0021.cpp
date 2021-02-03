#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;


void alloc2d(float**& ptr, unsigned int rows,  unsigned int cols); 
void free2d(float**& ptr, unsigned int rows); //Frees up the memory
//Fill up the 2d array with values
void fill2d(float**& ptr, unsigned int rows, unsigned int cols, ifstream& fin); 
//prints out the Arry
void outputArray(float**& ptr, unsigned int rows, unsigned int cols,
    ofstream& out);
//Prints out the sum, min, and max
void outputValues(float arr[], unsigned int row, float sum, float* min, 
    float* max, ofstream& out);
//total up the values and get the sum
float sumArray(float arr[], unsigned int cols);
//finds the Min pointer in the array
float* findMin(float arr[], unsigned int cols);
//finds the Max pointer in the array
float* findMax(float arr[], unsigned int cols);


//calls for command line argument
int main(int argc, char* argv[])
{
    int open = 0; // If a file opens correctly or not
    unsigned int rows, cols, i; //int values for the program
    float* min;
    float* max;
    float sum; // sum of all the row values
    float** ptr = nullptr; // dynamicaly allocated 2d array
    ifstream inputFile; //file steam that is opened
    ofstream outputFile; //File stream for file going out

    //set percision of the output file to 3 digits
    outputFile << fixed << showpoint << setprecision(3);

    //If the command line argument has less than 3 command then prompts message
    if (argc != 3)
    {
        cout << "Usage: m0021.exe inputfile outputfile" << endl;
        return 0;
    }

    //opens the input file
    inputFile.open(argv[1]);

    //checks to see if input file opens and prompts message if it fail to open
    if (!inputFile)
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        return 0;
    }

    //Opens the output file
    outputFile.open(argv[2]);

    //checks to see if output file opens and prompts message if it fail to open
    if (!outputFile)
    {
        cout << "Unable to open output file: " << argv[2] << endl;
        return 0;
    }

    inputFile >> rows; // Get rows from the file

    inputFile >> cols; // Get columnes from the file

    alloc2d(ptr, rows, cols); //allocate memory for 2d array

    fill2d(ptr, rows, cols, inputFile); //fills the 2d array with values
    
    outputFile << rows << " " << cols << endl;

    //Calculates the sum, find min and max, and prints out the values to file
    for (i = 0; i < rows; i++)
    {
       sum = sumArray(ptr[i], cols);
       min = findMin(ptr[i], cols);
       max = findMax(ptr[i], cols);
       outputValues(ptr[i], i, sum, min, max, outputFile);

    }

    outputArray(ptr, rows, cols, outputFile);

    free2d(ptr, rows); //clears the 2d araay

    inputFile.close(); //Close the input file

    outputFile.close(); //Close the output file

    return 0;
}


//Code obtained from Roger Schrader Slide show "Dynamic 2d array"
void alloc2d(float**& ptr, unsigned int row, unsigned int cols)
{
    unsigned int i;
    
    ptr = new (nothrow) float* [row];
    
    if (ptr == nullptr)
    {
        cout << "Not enough memory to run program" << endl;
        exit(0);
    }

    for (i = 0; i < row; i++)
    {
        ptr[i] = new(nothrow) float[cols];
        if (ptr[i] == nullptr)
        {
            free2d(ptr, i);
            cout << "Not enough memory to run program" << endl;
            exit(0);
        }
    }
}

//Code obtained from Roger Schrader Slide Show "Dynamic 2d Arrays"
void free2d(float**& ptr, unsigned int rows)
{
    unsigned int i;

    if (ptr == nullptr)
        exit (0);

    for (i = 0; i < rows; i++)
        delete[] ptr[i];

    delete[]ptr;

    ptr = nullptr;
}

void fill2d(float**& ptr, unsigned int rows, unsigned int cols, ifstream& fin)
{
    unsigned int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
            fin >> ptr[i][j];
    }
}

float sumArray(float* arr, unsigned int cols)
{
    float sum =0;
    unsigned int i;

    for (i = 0; i < cols; i++)
        sum += arr[i];

    return sum;
}

float* findMin(float* arr, unsigned int cols)
{
    unsigned int min, i=0, j = 1;


    if (arr[i] < arr[j])
        min = i;
    else
        min = j;

    i = 2;

    while (i < cols)
    {
        if (arr[i] < arr[min])
            min = i;
        i++;
    }

    return &arr[min];
}

float* findMax(float arr[], unsigned int cols)
{
    unsigned int max, i =0, j=1;


    if (arr[i] > arr[j])
        max = i;
    else
        max = j;

    i = 2;

    while (i < cols)
    {
        if (arr[i] > arr[max])
            max = i;
        else
            max = max;
        i++;
    }

    return &arr[max];
}

void outputValues(float arr[], unsigned int row, float sum, float* min, 
    float* max, ofstream& out)
{
    
    out << "Row:" <<std::setw(10) << row << " Sum:" << setw(15) << sum << 
        " Minimum:" << setw(15) << *min << " Maximum:" << setw(15)
        << *max << endl;

}

void outputArray(float**& ptr, unsigned int rows, unsigned int cols, 
    ofstream& out)
{
    unsigned int i, j;

    out << endl;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            out << setw(15) << ptr[i][j];
        }
        out << endl;
    }
}