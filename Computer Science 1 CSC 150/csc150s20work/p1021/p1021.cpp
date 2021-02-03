/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Lab 09 - Calculating route distance (p1021)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 3/26/2020
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
 * @details The purpose of this programs is to calculate to distance between
   two points, that are provide as x and y. Then to output that total distance
   of all of the point and the find the shortest and longest points
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1021.exe
   d:\> c:\bin\p1021.exe
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
   3/26/2020      Started and completed program


   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

//Max size of the array 
const int SIZE = 20;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void get_data(double x_point[], double y_point[], int& num_points);
void calculate_distances(double x_point[], double y_point[], double distance[],
    int num_points);
double total_calculate(double distance[], int num_points);
int get_longest(double distance[], int num_points);
int get_shortest(double distance[], int num_points);



 /** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This is the main function of the program. This is where all of the function
    are called and where the output occurs.

  * @param[in]     none
  * @param[in]     none
  *
  * @returns 0 program ran successful.
  *
  ****************************************************************************/

int main()
{
    //double array that contains the x-point, array is filled with 0s
    double x_point[SIZE] = { 0 };
    //double array that contains the y-point, array is filled with 0s
    double y_point[SIZE] = { 0 };
    //double array that contains the distances between two points, array filled
    //with 0s
    double distance[SIZE] = { 0 };
    //var total distance between all of the points
    double total_distance;
    //int var that holds the total number of points
    int num_points;
    //int var that holds the position of the shortest or longest distance
    int position;

    //calling function get_data to obtain the points
    get_data(x_point, y_point, num_points);
    
    //set the precision of the answer for this function 
    cout << fixed << showpoint << setprecision(2);

    //Output message showing the number of points that are being ran
    cout << "Calculating the distance between " << num_points << " points,";
    cout << " from (" << x_point[0] << "," << y_point[0] << ") to (";
    cout << x_point[num_points - 1] << "," << y_point[num_points - 1];
    cout << ")..." << endl << endl;

    //calling function calculate_distance to obtain the distance between 2
    //points 
    calculate_distances(x_point, y_point, distance, num_points);
    
    //total_distance is equal to calling function total_calulate
    total_distance = total_calculate(distance, num_points);

    //output message showing the total distance
    cout << "Total distance is " << total_distance << endl;

    //calls function get_longest and stores return as position
    position = get_longest(distance, num_points);

    //output the longest segment information
    cout << "Longest segment is " << distance[position] << ", between points";
    cout << " (" << x_point[position] << "," << y_point[position] << ") and (";
    cout << x_point[position + 1] << "," << y_point[position + 1] << ")";
    cout << endl;

    //calls function get_shortest and stores return as position
    position = get_shortest(distance, num_points);

    //output the shortest segment information
    cout << "Shortest segment is " << distance[position] << ", between points";
    cout << " (" << x_point[position] << "," << y_point[position] << ") and (";
    cout << x_point[position + 1] << "," << y_point[position + 1] << ")";
    cout << endl;

    //program terminates with no issues
    return 0;

}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is where all of the data input occurs. The user is asked to input the 
   number of points that they have and then that determines the number of
   prompts that they receive. Then the user is asked to input the number for 
   the x and y coordinates.

 * @param[in/out]     x_point[] - the x point array to be filled
 * @param[in/out]     y_point[] - the y point array to be filled
 * @param[in/out]     num_points - number of points that are inputed
 *
 * @returns none
 *
 ****************************************************************************/

void get_data(double x_point[], double y_point[], int& num_points)
{
    //temp var i
    int i = 1;
    //temp var j
    int j;

    //output message asking for number of points and input of points.
    cout << "Enter number of route points: ";
    cin >> num_points;
    cout << endl;
    
    //for loop for the entry of the 7 points
    for (j = 0; j < num_points; j++)
    {
        //output asking for the points for x and y
        cout << "Enter point " << i << " in the format \"x y\":";
        //input of x point and y point
        cin >> x_point[j] >> y_point[j];
        //enter space after input
        cout << endl;
        //increase i by 1
        i++;
    }

}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * The propose of this function is to calculated the distance between 2 point. 

 * @param[in/out]     x_point - the x points that are to be calculated
 * @param[in/out]     y_point - the y points that are to be calculated
 * @param[in/out]     distance - the distance between two x and y points
 * @param[in]         num_points - the number of point that are inputed
 *
 * @returns none
 *
 ****************************************************************************/

void calculate_distances(double x_point[], double y_point[], double distance[],
    int num_points)
{
    //temp var x
    double x;
    //temp var y
    double y;
    //temp var i
    int i;
    //temp var j and set to 0;
    int j = 0;


    //for loop to calculate the distance between 2 points
    for (i = 1; i < num_points; i++)
    {
        //calculate the square of two x points
        x = pow((x_point[j] - x_point[i]), 2.0);
        //calculate the square of two y points
        y = pow((y_point[j] - y_point[i]), 2.0);
        //distance is equal to square root of 2 x point and 2 y point squared
        distance[j] = sqrt((x + y));

        //increase j by 1
        j++;

    }
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called and where the output occurs.

 * @param[in/out]     distance - the array that is being totaled
 * @param[in]         num_points - the number of point that are inputed
 *
 * @returns 0 program ran successful.
 *
 ****************************************************************************/

 double total_calculate(double distance[], int num_points)
 {
     //var total for the total distance and set value to 0
     double total=0;
     //temp var i and set value to 0
     int i=0;
     
     //while i is less than num_points minus 1
     while (i < num_points - 1)
     {
         //total is equal to total plus distance
         total += distance[i];
         //increase i by one
         i++;
     }

     //returns total back to main.
     return total;

 }

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function looks at all of the distances that were calculated and 
   determines which is the longest distance and returns the position that 
   distance resides in the array.

 * @param[in/out]     distance - the array that is being looked at
 * @param[in]         num_points - the number of point that are inputed
 *
 * @returns position - the position of the value in the array.
 *
 ****************************************************************************/

 int get_longest(double distance[], int num_points)
 {
     //temp var i and is set to 0
     int i = 0;
     //temp var j and is set to 1
     int j = 1;
     //var position for the position in the array
     int position;

     //if distance in position 0 is greater than position 1 then position is 
     //set to position 0 else it is position 1
     if (distance[i] > distance[j])
     {
         position = i;
     }
     else
     {
         position = j;
     }

     //set i to 2
     i+=2;

     // while loop that looks at the remaining position in the array
     while (i < num_points - 1)
     {
         //if the distance is greater than the greatest position then position
         //is updated to the new position
         if (distance[i] > distance[position])
         {
             position = i;
         }
         i++;
     }

     //returns the position of the array
     return position;
 }

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function looks at all of the distances that were calculated and
   determines which is the shortest distance and returns the position that
   distance resides in the array.

 * @param[in/out]     distance - the array that is being looked at
 * @param[in]         num_points - the number of point that are inputed
 *
 * @returns position - the position of the value in the array.
 *
 ****************************************************************************/

 int get_shortest(double distance[], int num_points)

 {
     //temp var i and is set to 0
     int i = 0;
     //temp var j and is set to 1
     int j = 1;
     //var position for the position in the array
     int position;

     //if distance in position 0 is less than position 1 then position is 
     //set to position 0 else it is position 1
     if (distance[i] < distance[j])
     {
         position = i;
     }
     else
     {
         position = j;
     }

     //set i to 2
     i += 2;

     // while loop that looks at the remaining position in the array
     while (i < num_points - 1)
     {
         //if the distance is less than the smallest position then position
         //is updated to the new position
         if (distance[i] < distance[position])
         {
             position = i;
         }
         i++;
     }

     //returns the position of the array
     return position;

 }
