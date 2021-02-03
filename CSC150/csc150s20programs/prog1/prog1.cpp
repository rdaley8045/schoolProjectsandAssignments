/** ***************************************************************************
 * @file
 * @brief demonstrates if loop, setpoint
 *
 * @mainpage Program 1 Unit Converstion
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 1/28/2020
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
 * @details The purpose of this programs is convert yards in to mile and
 *  kilometers, and to converte ounces to Gallons, quarts, pints, ounces, and
 *	liters. This is completed by asking the user to input both the yards and 
 *	ounces and running them both through an if statement to check if the value 
 *	is greater than or equal to  0. All negitive numbers will force the program 
 *	to terminate. The termination can happen at either if statement.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog1.exe
   d:\> c:\bin\prog1.exe
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
   1/28/2020  Added Program documenation for the Doxygen writeups
   1/28/2020  Added Varaibles to Code
   1/28/2020  Added Loop Statements for variable input validation
   1/28/2020  Added Math Operations
   1/28/2020  Generated output
   1/28/2020  Corrected math operation to remove all warnings
   1/29/2020  Fixed setpoint function
   1/30/2020  Corrected Doxygen file
   2/03/2020  Added additional documentation
   2/04/2020  Reviewed code and made correction to spacing


   @endverbatim
 *
 *****************************************************************************/

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
 * first input starts off by asking for the number of yards that the client  
 * would like converted to miles and kilometers. Prior to outputting
 * the value the system verifies that the value is greater than or equal to
 * zero. If the value is less than zero, the program terminates immediately. This
 * task is repeated for the second wave of the program, which asks
 * the user to input the number of ounces.
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
	const double miles_to_kilometers = 1.6093; // Conversion from M to km
	const double yards_to_miles = 1760; // Conversion from Yards to Miles
	const double ounces_to_milliters = 29.5735; // Conv from ounces to milliters
	const int ounces_to_gallons = 128; // Conversion from ounces to Gallons
	const int quarts_to_gallons = 4; // Conversion from quarts to Gallons
	const int pint_to_gallons = 8; // Conversion from pints to Gallons
	double miles; // Output of Yards to Miles
	double kilometers; // Output of Miles to kilometers
	double liters; //Output of Ounces to liters
	int gallons; //Gallon output
	int ounces; // ounces output
	int ounces_to_quarts; // conversion number of ounces to quarts
	int ounces_to_pints; // conversion number of ounces to pints
	int pints; // Pints output
	int quarts; // Quarts output
	int remainder_of_gallons; // Remaining ounces after gallons removed
	int remainder_of_quarts; // remaining ounces after quarts removed
	int user_ounces; // user input for ounces
	int user_yards; // user input for yards


	// Output of program name with line underneath 
	cout << "Measurements Conversions " << endl;
	cout << "------------------------ " << endl << endl;

	
	//setpoint function declared
	cout << setprecision ( 4 );
	cout << fixed;
	cout << showpoint;


	// Start of Yards to Mile and Kilometers function
	//User title and user input for yards
	cout << "Yards to Miles and Kilometers" << endl << endl;
	cout << "Enter the number of yards: ";
	cin >> user_yards;

	//Math functions
	//Yards divided by miles
	miles = user_yards / yards_to_miles;
	//miles time kilometers
	kilometers = miles * miles_to_kilometers;

	//Output with if statement
	//If value is less than 0 program terminates
	if ( user_yards >= 0 )
	{
		cout << "   " << user_yards << " yards = ";
		cout << miles << " miles." << endl;
		cout << "   " << user_yards << " yards = ";
		cout << kilometers << " kilometers." << endl << endl;
	}
	
	else 
	{
		cout << "Invalid input! Program terminated." << endl;

		//Terminate Program
		return 0;
	}


	//Liquid Conversions
	//Title with user input request for ounces. 
	cout << "Ounces to Gal/Qt/Pt/Oz and Liters" << endl << endl;
	cout << "Enter the number of US liquid ounces: ";
	cin >> user_ounces;

	//Math functions
	//Generate ounces to quarts conversion, 36
	ounces_to_quarts = (ounces_to_gallons / quarts_to_gallons);
	//Generate ounces to pints conversion, 16
	ounces_to_pints = (ounces_to_gallons / pint_to_gallons);
	//Gallons from user input divided by 128
	gallons = (user_ounces / ounces_to_gallons);
	remainder_of_gallons = user_ounces % ounces_to_gallons;
    /*Quarts from the remaining ounces after gallons, divided by 36. */
	quarts = remainder_of_gallons / ounces_to_quarts;
	remainder_of_quarts = remainder_of_gallons % ounces_to_quarts;
	/*pintes from the remaining ounces after quarts, divided by 16*/
	pints = remainder_of_quarts / ounces_to_pints;
	ounces = remainder_of_quarts % ounces_to_pints;
	//Converts from onunces to milliters and milliters to liters
	liters = user_ounces * (ounces_to_milliters / 1000);
	

	//Output with if statement
	//If valie is less than 0 program terminates
	if (user_ounces >= 0)
	{
		cout << "   " << user_ounces << " ounces = " << gallons;
		cout << " gallons, " << quarts << " quarts, ";
		cout << pints << " pints and " << ounces;
		cout << " ounces." << endl;
		cout << "   " << user_ounces << " ounces = " << liters << " liters";
		cout << endl << endl;
		cout << "Bye!" << endl;
	}
	
	else
	{
		cout << "Invalid input! Program terminated." << endl;

		//Tereminate program
		return 0;
	}

	// End program no issues
	return 0;
}