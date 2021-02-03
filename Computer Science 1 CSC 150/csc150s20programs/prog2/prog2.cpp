/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, and boolan
 *
 * @mainpage Program 2 - Loan Payoff Calculator
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 2/11/2020
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
 * @details The prupose of this program is to calculate the amount of money 
   that an individual owes to their loan shark. This is done by calculating the
   number of days between two user provided dates. Then the programs asks for 
   the total amount of money that the user borrowed for the loan shark. Once
   the program has all of these varabilbe it calculates the total amount due
   by adding the amount of interest due and the loan amount together.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog2.exe
   d:\> c:\bin\prog2.exe
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
   2/11/2020      Started Programs
   2/12/2020      Addded Variables
   2/13/2020	  Wrote base program
   2/14/2020      Added fucntion for verification, and time calculations
   2/15/2020	  Tested date coputation to ensure accuracy failed 3 tests
   2/16/2020      Re-wrote time calculation funcition 
   2/20/2020      Corrected time calucation function to match outline
   2/21/2020      Worked on Doxeygen and comments 
   2/24/2020      Update code to comply with fewer functions
   2/25/2020      Consolidated more functions and update comments and doxeygen

   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/
bool dates_comparison(int start_day, int start_month, int start_year,
    int end_day, int end_month, int end_year);
bool date_loop_evaluator(int month, int day, int year);
int leapyear_gernerator(int user_years);
int month_gernerator(int month, int year);

 /** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This is the main function of the program. This is where all of the input
    and output of the program happens. As well as calculateing the number 
    of days between the to date and the amount of the loan balance.

  * @param[in]     none
  * @param[in]     none
  *
  * @returns 0 program ran successful.
  *
  ****************************************************************************/

int main()
{
	/*Declares the variable date_comparision and sets the value to false.
    This variable is used to check that end dates is greater than the start 
    date.*/
    bool date_comparison = false;
    /*Declares the variable date_verification. This variable is used to set
    the condition for the date verification loop*/
    bool date_verification;
    /*Declases the variable loan_verifer and sets the value to false. This 
    variable is used to set the condition for the loan verification loop*/
    bool loan_verifer = false;  
    double amount_of_money_due; // The amount that is due with interest
    double user_loan_amount; // The amount of money that is borrowed 
    int end_day; // Ending day
    int end_difference = 0; //Set difference in day to end month to 0
    int end_month; // Ending month
    int end_year; // user entered ending year
	int i = 0; // set start month counter to 0
    int j = 0; // set end month counter to 0  
    //Creates temp variable for the starting year set after inputs 
    int k;
    int length_of_loan; // The lenght of the loan
    int start_day; // Starting day
    int start_difference = 0;//Set difference in day to for start month to 0
    int start_month; // Starting month
    int start_year; // Starting year
    //Creates variable and sets the value to 0
    int year_difference = 0;
	
	//set percision tp 2 positions
	cout << fixed << showpoint << setprecision(2);

    //Title for the program
	cout << "Sharky's Loan Payoff Calculator" << endl;
	cout << setfill('-') << setw(31) << "-" << endl << endl;
	
	/*Start of the loop that obtains the dates and verifies that the start 
    dates is less than the ending date*/
	while (date_comparison == false)
	{
		//sets date verification to false for the starting date loop.
		date_verification = false;
		
		//starts loop to verify start date infromation
		while (date_verification == false)

		{
			//Asking for start year and set value to start_year
			cout << "Enter starting year: ";
			cin >> start_year;
			cout << endl;

			//Asking for start month and set value to start_month
			cout << "Enter starting month: ";
			cin >> start_month;
			cout << endl;

			//Asking for start day and set value to start_day
			cout << "Enter starting day: ";
			cin >> start_day;
			cout << endl;

			/*Send start date values to the date loop evaluating function
            If the dates that are entered are valid inputs the condition for 
            date_verification is set to true and ends the loop. If not the 
            the function outputs what value is incorrects and keep the value of
            date_verification to false, leading to the loop running again.*/
			date_verification = date_loop_evaluator(start_month, start_day, 
                start_year);

		}

		/* Set the date_verification back to false so that date_loop_evaluartor
        function can be used again*/
		date_verification = false;
		
		//starts loop to verify end date infromation
		while (date_verification == false)
		{
			// asking for end year and set value for  end_year
			cout << "Enter ending year: ";
			cin >> end_year;
			cout << endl;

			// asking for end month and set value for end_year
			cout << "Enter ending month: ";
			cin >> end_month;
			cout << endl;

			//asking for end day and set value for end_day
			cout << "Enter ending day: ";
			cin >> end_day;
			cout << endl;
			
			//Verifies if date is a valid date
			date_verification = date_loop_evaluator(end_month, end_day,
                end_year);
		}
	
        /*Sends end date values to the date loop evaluating function
         If the dates that are entered are valid inputs the condition for
         date_verification is set to true and ends the loop. If not the
         the function outputs what value is incorrects and keep the value of
         date_verification to false, leading to the loop running again.*/
		date_comparison = dates_comparison(start_day, start_month, start_year,
			end_day, end_month, end_year);
	}
	
    /*Starts a loop to verify that the amount of the loan is a valid value
    if the loan amount is not geater than 0 then the loop continues to ask for 
    a new loan amount.*/
    while (loan_verifer == false)

    {
        //Asks the user to input the starting loan amount 
        cout << "Enter the starting loan amount: ";
        cin >> user_loan_amount;
        cout << endl;

        //Checks the loan amount and verifies that it is greater than 0.
        if (user_loan_amount > 0)
        {
            loan_verifer= true;
        }
        //if the loan amount is 0 or less than output invalid value and contiue
        //the loop
        else
        {
            cout << "Invalid value!" << endl;
        }
  
    }

    //Sets temp value of k to starting year
    k = start_year;

    //Start loop that counts the number of day from Jan 1 to start of the 
    //starting month
    while (i < start_month)
    {

        start_difference += month_gernerator(i, start_year);
        i++;
    }

    //Takes days of the months and adds the remaining days to the start date
    start_difference = start_difference + (start_day);

    // calculates the days from Jan 1 to start of the ending month.
    while (j < end_month)
    {

        end_difference += month_gernerator(j, end_year);
        j++;
    }

    //Takes days of the months and adds the remaining days to the ending date
    end_difference = end_difference + (end_day);

    if (start_year == end_year)
    {
        length_of_loan = end_difference - start_difference;
    }
    else
    {
        //Total number of days between start and ending year
        while (end_year > k)
        {

            year_difference += leapyear_gernerator(k);
            k++;
        }

        /* Takes the number of difference in years and adds the ending
        difference then subtracts the starting difference to get the today
        days between 2 dates*/
        length_of_loan = (year_difference + end_difference) -
            start_difference;

    }

    /*Calculates the amount of month due by taking the loan amount and adding 
    the interest*/
	amount_of_money_due = user_loan_amount + (length_of_loan * 0.01 *
		user_loan_amount);

    //Outputs the length of the loan and loan amount that is due
	cout << "The loan is for " << length_of_loan << " days and the ";
	cout << "customer owes Sharky $" << amount_of_money_due << ".";

	//Safely terminating program
	return 0;
}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This functuon takes that starting and ending dates and evalutes each
   component of the dates to ensure that the dates that are being inputed
   are valid. Additional if the values that are being inputed are invalid then 
   the function out puts a notice the user which of the higher values in 
   incorrect.


 * @param[in]     int month - The starting and ending month 
 * @param[in]     int day - The starting and ending day
   @param[in]     int year - The starting and ending year
 *
 * @returns validation_output - return true or false after the values are 
   evaluated.
 *
 *****************************************************************************/

bool date_loop_evaluator(int month, int day, int year)
{
    /*Declares a variable of validation_output and sets the intial value to 
    true*/
    bool validation_output = true;
	
	//Checks to years to see if the inputed value is greater than 0
	if (year < 0)
	{
		//outputs Invalid and sets validation_output to false
        cout << "Invalid year!" << endl;
		validation_output = false;
	}
    //If the year is greater than 0
	else
	{
		//Sets validation_output to true
        validation_output = true;
	}

	//validates the number of days per month
	if (month > 0 && month <= 12)
	{
		
		//validates the month of Febuary
		if (month == 2)
		{
			// Inspects if the year is not a leap year then 28 is the max 
            // number of days.
			 if (leapyear_gernerator(year) == 365)
			{
                /*If the day is great than 0 and less than or equal to  28
                and the year is not a leapyear */
				if (day > 0 && day <= 28)
				{
					//Return positive if true
                    validation_output = true;
				}
				//If input is 30 or more days outputs a Invalid day notice
				else if (day < 0 || day > 29)
				{
					//output if day is are greater than 30
                    cout << "This is not a valid day!" << endl;
					validation_output = false;
				}

				// if user inputs 29 days prompts "This is not a leap year" 
				else
				{
					//output if the day is not a leap year
                    cout << "This is not a leap year!" << endl;
					validation_output = false;
				}
			}

			 //evaluates Month 2 for leap year with days between 1 and 29
			 else if (leapyear_gernerator(year) == 366)
			 {
				 //If its a leap year and the dates are between 1 and 29
                 if (day > 0 && day <= 29)
				 {
					 //Output of if the statement is true
                     validation_output = true;
				 }
				 else
				 {
					 //Output if the day  is 30 or more or 0 or less
                     cout << "This is not a valid day!" << endl;
					 validation_output = false;
				 }
			 }
		}

		// Evaluateds if month 4,6,9,or 10 have 30 days
		else if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			//Validates that the days are between 1 and 30
            if (day > 0 && day <= 30)
			{
				//Sets the variable to true
                validation_output = true;
			}
            // Ensures the days are not less than 0 and greater than 30
			else if (day < 0 || day > 30)
			{
				//Output that the day is invalid and sets variable to false    
                cout << "This is not a valid day!" << endl;
				validation_output = false;
			}
		}

		//evaluates remaining months have 31 days
		else 
		{
            //Validates that the days are between 1 and 31
            if (day > 0 && day <= 31)
			{
                //Sets the variable to true
                validation_output = true;
			}
            //Ensures the days are not less than 0 and greater than 31
			else if (day < 0 || day > 31)
			{
                //Output that the day is invalid and sets variable to false
                cout << "This is not a valid day!" << endl;
				validation_output = false;
			}
		}
	}
	
	//If Month is greater than 12 and less than 1 marks as invalid
	else
	{
		//Outputs that the month is invalid and sets value to false
        cout << "Invalid month!" << endl;
		validation_output = false;
	}

    //Returns if the test is true or false
	return validation_output;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function take in both the valid starting and ending dates and 
   compares the two date to ensure that the starting date is less than the 
   ending date.


 * @param[in]     int start_day - the starting day
 * @param[in]     int start_month - the starting month
 * @param[in]     int start_year - the starting year
 * @param[in]     int end_day - the ending day
 * @param[in]     int end_month - the ending month
 * @param[in]     int end_year - the ending year

 * @returns validation_output - return true or false after the values are
   evaluated.
 *****************************************************************************/

bool dates_comparison(int start_day, int start_month, int start_year,
	int end_day, int end_month, int end_year)
{
	// sets variable and condition to true
    bool validation_output = true;
	
	//verifies that start year is less than end year
	if (end_year < start_year)
	{
		//Output if the value is false 
        cout << "Starting date must be earlier than ending date!" << endl;
		validation_output = false;
	}
	
	// If start year is equal to end year verification
	else if (end_year == start_year)
	{
		//varifies end month is in the future
		if (end_month < start_month)
		{
			//Output if the value is false
            cout << "Starting date must be earlier than ending date!" << endl;
			validation_output = false;
		}
	}
	
	// checks months and years are equal
	else if (end_year == start_year && end_month == start_month)
	{
		//verifies that end day is in future
		if (end_day < start_day)
		{
			//Output if the value is false
            cout << "Starting date must be earlier than ending date!" << endl;
			validation_output = false;
		}
		else
		{
			//If true sets condition to true
            validation_output = true;
		}
	}
	else
	{
		//sets variable to true if all conditions are true
        validation_output = true;
	}
	//returns true or false
	return validation_output;
}


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This fucntion looks at a single year and determines if that year is a 
   either a leap year or not. If it's a leap year then it outputs 366 day if 
   not then the day is set to 365.


 * @param[in]     int year - looks at the given year that is provided
 *
 * @returns year_in_days - the number of days in a given year.
 *
 *****************************************************************************/

int leapyear_gernerator(int year)
{
	// Set year to day variable
	int year_in_days;

	/* Evaluates year to determine if its a leap year by seeing its divisible 
	by 400 or divisible by 4 and not by 100 */

	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
	{
		year_in_days = 366;
	}
	//If the year is not divisible by 400 or 4 and not 100
    else
	{
		year_in_days = 365;
	}

	// returens the number of days per year
	return year_in_days;
}

/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function looks at a given month and year and returns corret number of 
   days that month has. 


 * @param[in]     int year- looks at what year the month is in
 * @param[in]     int month - looks at the month that is provided
 *
 * @returns  month_in_days - the difference is days between the 2 months.
 *
 *
 *****************************************************************************/

int month_gernerator(int month,int year)
{
	int month_in_days = 0;

	//checks if the months are between 1 and 12
	if (month > 0 && month <= 12)
	{
		// if the month are 4,6,9,or 11, the days are set to 30
		if (month == 4 || month == 6 || month == 9 || month == 11)
		{
			month_in_days = 30;
		}
		//If the month is 2
		else if (month == 2)
		{
			// If the year in days is 366 then days are set to 29
			if (leapyear_gernerator(year) == 366)
			{
				month_in_days = 29;
			}
			
			// If the year in days is 365 then days are set to 28
			else
			{
				month_in_days = 28;
			}
		}
		
		//set all remaining days to 31
		else
		{
			month_in_days = 31;
		}
	}
	
	//returns month is day 
	return month_in_days;
}
