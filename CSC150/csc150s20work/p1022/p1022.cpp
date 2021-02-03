/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Lab 10 - Experiment Data Analysis (p1022)          
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 4/2/2020
 *
 * @par Professor:
 *         Dr. Daniel de Castro
 *
 * @par Course:
 *         CSC 150
 *
 * @par Location:
 *         CB - 204W
 *
 * @section program_section Program Information
 *
 * @details The purpose of this program is to pull a rand set of numbers 
    created by a user inputed seed number and display the min, max, average and
    standard deviation. 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1022.exe
   d:\> c:\bin\p1022.exe
   @endverbatim
 *
 * @section todo_bugs_modification_section Todo, Bugs, and Modifications
 *
 * @bug none
 *
 * @todo none
 *
 * @par Modifications and Development Timeline:
   @verbatim
   Date           Modification
   -------------  -------------------------------------------------------------
   4/01/2020      Started program
   4/02/2020      Completed program 


   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>
#include <iomanip>

using namespace std;


/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

const int COLS = 20;
const int ROWS = 10;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void start(void);
double get_data(void);
void fill_array(double d[][COLS], int rows);
double find_min(double min[], int size);
double find_max(double max[], int size);
double find_average(double average[], int size);
double find_stdev(double stdev[], int size);
void display_stats(double s[][4], int size);

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 ****************************************************************************/


int main()
{
    double data[ROWS][COLS] = { 0 }; // Data 2D array
    double stats[ROWS][4] = { 0 }; // Stats 2D array
    double min[ROWS];// 1D array holding the min values
    double max[ROWS]; // 1D array holding the max values
    double average[ROWS]; // 1D array holding the average values
    double stdev[ROWS]; // 1D array holding the standard deviation values
    double temp[COLS];
	int i;  // Temp value
    int j; // temp value


	start();

  	//fill the data array

    fill_array(data, ROWS);

	//compute the min, max, average, stddev for each row of data
    
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            temp[j] = data[i][j];

        }

        min[i] = find_min(temp, COLS);
        max[i] = find_max(temp, COLS);
        average[i] = find_average(temp, COLS);
        stdev[i] = find_stdev(temp, COLS);
    }
    
    //storing to stats array

    for (i = 0; i < ROWS; i++)
    {
        stats[i][0] = min[i];
        stats[i][1] = max[i];
        stats[i][2] = average[i];
        stats[i][3] = stdev[i];
    }


	//display the stats array
    display_stats(stats, ROWS);

	return 0;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the start of the program and where then user sets up the seed for 
   the program.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns none.
 *
 ****************************************************************************/


void start(void)
{
	int seed;
	cout << "Data Analysis Testing";
	cout << endl << "Enter seed: ";
	cin >> seed;
	cout << endl;
	if (seed == -1)
		srand(unsigned(time(0)));
	else
		srand(seed);
	cout << setw(40) << setfill('-') << "-" << endl << endl << setfill(' ');
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is where the data column is filled. It calls the get_data function to 
   obtain the information. 

 * @param[in/out]     d[][COLS] - the data array 
 * @param[in]         rows - the number of rows that need to be filled. 
 *
 * @returns none
 *
 ****************************************************************************/


void fill_array(double d[][COLS], int rows)
{
	int i, j;

	for (i = 0; i < rows; i++)
		for (j = 0; j < COLS; j++)
			d[i][j] = get_data();
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the function that obtains the random numbers and stores each of them
   into the blank variable. 

 * @param[in]     none
 * @param[in]     none
 *
 * @returns num - the number that the random number generator produces.
 *
 ****************************************************************************/


double get_data(void)
{
	double num = 0;

	num = rand() % 5 + 1;  //range 1 to 5 inclusive

	num += rand() / (double)RAND_MAX;

	return num;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function finds the min number for each row and stores it in to an       
   array called min.

 * @param[in]     min [] - the min array that has been filled
 * @param[in]     size - the min array that has been filled
 *
 * @returns min_a - the max value of the row.
 *
 ****************************************************************************/


double find_min(double min[], int size)
{

    int i; // temp value
    double min_a; //min of the value

     //stores the first number in min
     min_a = min[0];

    //loop to look for the max value of the random numbers
    for (i = 1; i < size; i++)
    {
        if (min[i] < min_a)
        {
            min_a = min[i];
        }
    }

    return min_a;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function finds the max number for each row and stores it in to an
   array called max.

 * @param[in]     max [] - the max array that has been filled
 * @param[in]     size - the max array that has been filled
 *
 * @returns max_a - the max value of the row
 *
 ****************************************************************************/


double find_max(double max[], int size)
{

    int i; // temp value
    double max_a; //max of the value
    
    //stores the first number in max
    max_a = max[0]; 

    //loop to look for the max value of the random numbers
    for (i = 1; i < size; i++)
    {
        if (max[i] > max_a)
        {
            max_a = max[i];
        }
    }

    return max_a;

}


/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function finds the average number for each row and stores it in to an
   array called average.

 * @param[in]     average [] - the average array that has been filled
 * @param[in]     size - the average array that has been filled
 *
 * @returns the average.
 *
 ****************************************************************************/


double find_average(double average[], int size)
{
    int i; // temp value
    double sum = 0; // the sum of the row

    //for loop to calculate the sum of the row
    for (i = 0; i < size; i++)
    {
        sum += average[i];
    }

    //returns the sum divided by the size
    return sum / size;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function finds the std deviation number for each row and stores it in 
   to an array called stdev.

 * @param[in]     stdev [] - the std deviation array that has been filled
 * @param[in]     size - the std deviation array that has been filled
 *
 * @returns the standard deviation.
 *
 ****************************************************************************/


double find_stdev(double stdev[], int size)
{
    int i; //temp value
    double avg = 0; // value for the average
    double sum = 0; //the sum 

    //calls the find_average function and gets the average
    avg = find_average(stdev, size);

    //for loop that calculates the sum of the row
    for (i = 0; i < size; i++)
    {
        sum += pow((avg - stdev[i]), 2.0);
    }

    //returns the square root of the sum divided by size minus 1
    return sqrt(sum / (size - 1));

}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called and where the output occurs.

 * @param[in]     s[][4] - stats array 
 * @param[in]     size - size of the array 
 *
 * @returns none.
 *
 ****************************************************************************/


void display_stats(double s[][4], int size)
{
    int i, j;

    //set the precision of the answer for this function 
    cout << fixed << showpoint << setprecision(4);

    cout << "Showing stats" << endl << endl;
    cout << "RUN#     MIN     MAX   MEAN   STDDEV" << endl;

    //loop to get the information from the each row
    for (i = 0; i < size; i++)
    {
        cout << setw(4) << i+1;
        
        //loop to get the information from each column
        for (j = 0; j < 4; j++)
        {
            cout << setw(8) << s[i][j];
        }

        cout << endl;
    }


}



