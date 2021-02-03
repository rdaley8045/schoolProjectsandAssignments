/******************************************************************************
 * @file
 * @brief demonstrates if loop, setpoint, use of CMATH and M_PI
 *
 * @mainpage Lab 4 - Guessing Game Bears (p1016)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 2/5/2020
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
 * @details The purpose of this program is to help an individual determine 
   the number of gummy bears are in a round cyclinder. Using if statement, 
   #Include<CMATH> and #Define _USE_MATH_DEFINE this program was built to 
   perform such a task. It all starts with the program asking the user to 
   input a positive values greater than zero for both the height and 
   diameter of the jar. The program checks that both answer are valid and 
   that volume of the jar is large enough for a gummy bear. Lastly it
   outputs the data.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1016.exe
   d:\> c:\bin\p1016.exe
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
   2/4/2020       Started Program layout
   2/4/2020		  Body of program built
   2/5/2020		  Updated comments and Doxygen

   @endverbatim
 *
 *****************************************************************************/

#define _USE_MATH_DEFINES
#include<iomanip>
#include<iostream>
#include<cmath>

using namespace std;

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the starting point to the program.  It starts by introducing the
 * program to the user and asking the user to for a two separate inputs. The
 * first input starts the program off by asking for the height of a giving jar.
   the second input asks for the diamater of the jar. Both values are evaluated
   to make sure that they are values greater than zero. The programs calculated 
   radius of the jar and the volume of said jar. It then evaluates to ensure that 
   they jar is big enough to fit 1 gummy bear in it. If any of the validation 
   return false the program terminates. Lastly the program output the values and 
   wishes that user luck.
 *
 * @param[in]      argc - none
 * @param[in]     argv - none
 *
 * @returns 0 program ran successful.
 *
 *
 *****************************************************************************/
int main()
{
	//Variables
	const int vol_of_bear = 4; // volume in cm3 of a gummy bear
	double radius_of_jar; // half the diameter of a circle
	double total_vol_of_jar; // Total volume of the jar
	double vol_of_jar_filled; // 70% of the total volume of the jar
	double diameter_of_jar; // Diameter of the jar
	double height_of_jar; // Height of the jar
	int num_of_bear; // Total number of gummy bears in a jar

	//setpoint function declared
	cout << setprecision(1);
	cout << fixed;
	cout << showpoint;

	// Program title
	cout << "Gummy Bear Guesser" << endl << endl;

	//Asking for user input of height
	cout << "What is the height of the jar (in cm)? ";
	cin >> height_of_jar;
	
	//Validation to ensure height of jar is larger than 0
	if ( height_of_jar <= 0 )
	{
		cout << "Invalid value!";

		//Terminates Program
		return 0;
	}
	else
	{
		cout << endl;
	}

	//Asking for user input of diameter
	cout << "What is size of the bottom(diameter) of the jar (in cm)? ";
	cin >> diameter_of_jar;
	
	//Validation to ensure height of jar is larger than 0
	if ( diameter_of_jar <= 0 )
	{
		cout << "Invalid value!";

		//Terminates Program
		return 0;
	}
	else
	{
		cout << endl;
	}

    //Calculation of total volume
	radius_of_jar = diameter_of_jar / 2;
	total_vol_of_jar = M_PI * (pow ( radius_of_jar,2 )  * height_of_jar);
	
	//Calculation of 70% of jar
	vol_of_jar_filled = total_vol_of_jar * .70;

	/*Validation that jar is big enough for 1 gummy bear 
	  terminated program is not big enough*/
	if ( vol_of_jar_filled < vol_of_bear )
	{
		cout << "Jar measurements are incorrect!";
		
		//Terminates program
		return 0;
	}

	//Calculation of total gummies
	num_of_bear = (int) vol_of_jar_filled / vol_of_bear;

	//Output of Volumes and number of bears
	cout << "The total volume of the jar is " << total_vol_of_jar;
    cout << " cm3." << endl;
	cout << "Approximately only " << vol_of_jar_filled << " cm3 of the jar ";
	cout << "contains gummy bears." << endl;
	cout << "The approximate number of gummy bears is " << num_of_bear << ".";
	cout << endl << "Good luck!";

	// End program no issues
	return 0;
}