/** ***************************************************************************
 * @file
 * @brief demonstrates function, if loop, and 
 *
 * @mainpage Lab 5 - Pet food calculator (p1017)
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
 * @details The purpose of this programs is to determine that amount the
   amount of money a person would have to pay for pet food based off of
   the number of pets they have and what type of pets they have.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1017.exe
   d:\> c:\bin\p1017.exe
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
   2/11/2020  Added Program documenation for the Doxygen writeups
   2/11/2020  Added Varaibles to Code
   2/11/2020  Created Functions
   2/11/2020  Created body
   2/11/2020  Completed Doxygen and notes


   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*******************************************************************************
 *                         Function Prototypes
 ******************************************************************************/
double discount_calculator(int discount_code, int num_pets);
int pet_function(string type_of_pet);
void print_totals(double purchase_price, double discount);


/** ***************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the starting point to the program.  It starts by introducing the 
   program and asking if the individual owns a pet. If not the program calls
   the print_total to complete the transaction. If yes the program goes through
   a variety of validation functions to determine the correct discount and finally
   to input the values into the print_total function. 


 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 *****************************************************************************/

int main()
{
	string yes_or_no; // User input of y, Y, n, N
	double discount; // Discount percentage
	double purchase_price; // total of purchase prior to discount and tax
	int discount_code; // Code to determine the correct discount amount
	int num_pets; // total number of pets an individual owns
	string type_of_pet; //type of pets that they owner has
	
	//set percision
	cout << fixed << showpoint << setprecision(2);
	
	//Introduction
	cout << "Pet food calculator" << endl <<endl;

	//Asks if the owner has a pet
	cout << "Do you have a pet (Y/N)? ";
	cin >> yes_or_no;

    //Main if statememt, validates if yes_or_no is not equal to  Y or y
	if  (yes_or_no == "Y" || yes_or_no == "y")
	{
		// Asks about the type of pets
		cout << endl << "What kind of pet? ";
		cin >> type_of_pet;

		//Function that generates a discount code based on type of pet
		discount_code = pet_function(type_of_pet);

		//Asking for the number of pets
		cout << endl << "How many? ";
		cin >> num_pets;

		//Function that generated the amount of discount an individual recieves
		discount = discount_calculator(discount_code, num_pets);

		//Asking for the purchase price
		cout << endl << "Enter purchase subtotal: ";
		cin >> purchase_price;

		//print function for programs
		print_totals(purchase_price, discount);

	}
	else
	{
		//Asking for the purchase price
		cout << endl << "Enter purchase subtotal: ";
		cin >> purchase_price;

		//discount for having no pets
		discount = 0;

		//print function for programs
		print_totals(purchase_price, discount);

	}
	
	//Succesful completion of the program.
	return 0;
}

/***************************************************************************//**
 * @author Raymond Daley
 *
 * @par Description:
 * This function recieves the pruchase price of the with out the discount. Then
   it recieves the discount rate and calculated what the total is with the 
   discount and the total with taxes included. 
 *
 * @param[in] purchase_price - the purchase price without the discount
 * @param[in] discount - the amount of discount that an individual receives
 *
 * @returns none
 ******************************************************************************/

void print_totals(double purchase_price, double discount)
{
	//declaired variables
	const double SALES_TAX_RATE = 0.07; //Sales Tax
	double sub_after_discount; // Sub total after discount
	double total_after_tax; // total after sub and tax combined

	//calculating sub total
	sub_after_discount = purchase_price - (purchase_price * discount);

	//output sub total
	cout << endl << "Subtotal after discount: $" << sub_after_discount;

	//calculate total
	total_after_tax = sub_after_discount + (sub_after_discount*SALES_TAX_RATE);

	//output total
	cout << endl << "Final total: $" << total_after_tax << endl;


}

/***************************************************************************//**
 * @author Raymond Daley
 *
 * @par Description:
 * Validates that type of pets the user inputs and assigns a int code for the
   discount calculator function to determine the correct discount to apply.
 *
 * @param[in] type_of_pet - The type of pet that the user inputs
 *
 * @returns discount_code - The code for which discount group to apply
 ******************************************************************************/

int pet_function(string type_of_pet)
{
	int discount_code;
	
	//Sets discount code for cat to 1
	if (type_of_pet == "cat")
	{
		discount_code = 1;
	}
	
	//Sets discount code for dog to 2
	else if (type_of_pet == "dog")
	{
		discount_code = 2;
	}
	
	//Sets discount code for other to 3
	else
	{
		discount_code = 3;
	}

	//returns the discount code to the main function
	return discount_code;
}

/***************************************************************************//**
 * @author Ryamond Daley
 *
 * @par Description:
 * This function generates the correct discount based off of the discount code
   generated by the pet function and the number of pets the individual owns.
 *
 * @param[in] discount_code - The code generated by the pet function
 * @param[in] num_pets - the number of pets an individual has
 *
 * @returns discount - the amount of discount to be applied
 ******************************************************************************/

double discount_calculator(int discount_code, int num_pets)
{
	double discount;
	
	//sets the discount rate for a Cat
	if (discount_code == 1)
	{
		if (num_pets > 5)
		{
			discount = .30;
		}
		else
		{
			discount = .25;
		}
	}
	
	//sets the discount rate for a dog
	else if (discount_code == 2)
	{
		if (num_pets >= 4)
		{
			discount = .20;
		}
		else
		{
			discount = .15;
		}
	}
	
	//sets the discount rate for Other
	else
		if (num_pets > 2)
		{
			discount = .10;
		}
		else
		{
			discount = .05;
		}

	return discount;
}