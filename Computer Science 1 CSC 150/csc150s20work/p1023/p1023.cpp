/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Lab 11 - Counting cedits with C-Strings (p1023)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 4/7/2020
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
 * @details The purpose of this program is to calculate the total number of 
    credit hours has taken as well as how many credit hours goes to their major
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1023.exe
   d:\> c:\bin\p1023.exe
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
   4/07/2020      Started program
   4/07/2020      Completed program no errors. Need Doxygen



   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cmath>
#include <iomanip>
#include <cstring>

using namespace std;

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

const int FULL_SIZE = 80;
const int ABBR_SIZE = 3;
const int COURSE_SIZE= 7;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void abbr_subject(char fullname[], char abbrname[]);
double compute_hours(char abbrname[], int num_courses, double& maj_hours);
void display(char abbrname[], double maj_hours, double total_hours);

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
    char fullname[FULL_SIZE]; //Name of the individuals major
    char abbrname[ABBR_SIZE] = { '\0' }; // abbreviation of major
    double maj_hours=0; //Total hours completed for in the major.
    double total_hours=0; //Total of all the hours of the courses
    int num_courses; // The number of course 

    //Obtain the Major the individual is going for
    cout << "Enter your Major: ";
    cin.getline(fullname, FULL_SIZE);

    //calling the function abbr_subject to obtain the abbreviation of the major
    abbr_subject(fullname, abbrname);

    //output the abbreviation 
    cout << "Abbreviation: " << abbrname << endl;

    //Get the total number of course the student has taken
    cout << "Enter the number of courses you have taken: ";
    cin >> num_courses;
    cout << endl<<endl;

    //calls compute hour and returns the total_hours
    total_hours = compute_hours(abbrname, num_courses, maj_hours);
    
    //calls display to display the total hours and major hours
    cout << endl;
    display(abbrname, maj_hours, total_hours);

    //program runs successfully
    return 0;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in the fullname of the major and returns the abbreviated
   code.

 * @param[in]     fullname  - full name of the major
 * @param[out]     abbrname  - abbreviated code
 *
 * @returns none.
 *
 ****************************************************************************/

void abbr_subject(char fullname[], char abbrname[])
{
    int i =0; // temp val
    int j = 0; // temp val

    //First letter of the first work is stored into  abbrname
    abbrname[j] = toupper(fullname[i]);

    j++; // increase j by 1
    i++; // increase i by 1

    //loop to look at the remain char in the string ends when ASCII 0 is found
    while (fullname[i] != 0)
    {
     
        //if fullname is equal to a space the move i up by 1 and store abbrname
        if (fullname[i] == ' ')
        {
            i++;
            abbrname[j] = toupper(fullname[i]);
        }
        //move I up by 1
        i++;
    }

}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function computes the total number of hours a student has taken as well
   as the total hours of a given major.

 * @param[in]       abbrname - abbreviation code of the major
 * @param[in]       num_courses - number of courses that the student took
 * @param[in/out]   maj_hours - the number of hours that apply to the major
 *
 * @returns total_hours - total number of hours of classes taken.
 *
 ****************************************************************************/

double compute_hours(char abbrname[], int num_courses, double& maj_hours)
{
    int i; //temp val
    int j=0; // temp val
    double hours; // hours of the course
    double total_hours=0; // total hours of the courses
    char course_code[COURSE_SIZE]; //course code that the student took

    //loop that obtains course information and calculates hours 
    for (i = 0; num_courses > i; i++)
    {
        //Obtains the course code of the class the student took
        cout << "Enter course number #" << i + 1 << ": ";
        cin.ignore();
        cin.getline(course_code, COURSE_SIZE);
        cout << endl;

        //Obtains the hours earned for the course
        cout << "Enter credit hours #" << i + 1 << ": ";
        cin >> hours;
        cout << endl;

        //hour plus hour equals total_hours
        total_hours += hours;

        //if the first to char of the course code match the abbreviation then
        //add the hours to the majors hours. 
        if (strncmp(course_code, abbrname, 2)==0)
        {
            maj_hours += hours;
        }

    }
    //returns the total number of hours. 
    return total_hours;
}

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

void display(char abbrname[], double maj_hours, double total_hours)
{
    //Sets the precision of the answer to 2 decimal places. 
    cout << fixed << showpoint << setprecision(1);

    //print out the total hours for both the major and the total credits
    cout << abbrname << " major credit hours: " << maj_hours << endl;
    cout << "Total credit hours: " << total_hours << endl << endl;
}