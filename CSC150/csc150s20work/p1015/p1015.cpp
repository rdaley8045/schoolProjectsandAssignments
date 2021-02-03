/** ***************************************************************************
 * @file
 * @brief demonstrates do while loop, setpoint, explicit type casting
 *
 * @mainpage Lab 03 - Donut Calculator (p1015)
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
 * @details This program take is looking a a group of people that want to order
 * donuts. The group of individual have decided to combine all of their money 
 * together. They will use this program to determine the max number of donuts 
 * that they can purchase. It will also calculate the number of donuts each 
 * individual recieves and how much money the group will get back.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1015.exe
   d:\> c:\bin\p1015.exe
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
   1/30/2020      Generated program
   1/30/2020      List of Variables generated
   1/31/2020      Corrected Math functions
   1/31/2020      Fix Doxygen code



   @endverbatim
 *
 *****************************************************************************/

#include<iomanip>
#include<iostream>

using namespace std;

/***************************************************************************//**
 * @author Raymond Daley
 *
 * @par Description:
 * This is the starting point to the program.  It starts by introducing the 
 * program to the user and asking the user to for three inputs; number of people,
 * how much money the groups have, and the cost per each donut. It then out puts 
 * the money on hand, the total number of donuts that can be purchased, the amount
 * of change due back to the group, and how many donuts each member of the group 
 * recieve. The program does have a validation so that if an individual attempts
 * to put in 0 or a negitive number the program will ask the user for a new number
 * greater than 0.
 *
 * @param[in] argc - none
 * @param[in] argv - none
 *
 * @returns 0 program runs succesfully
 ******************************************************************************/

int main()
{

	double change_left_over; //Total change due back to clients
	double cost_per_donut; //Cost per donut
	double total_money_on_hand; // Total money on hand
	int num_donut; // Total number of donuts that can be purchased
	int num_of_donut_per_person; //Total number of donuts each client recieves
	int num_people; //Total number of clients looking for donuts
	int remainder_of_donut; //Remaining number of donuts after each individual get
	                       //there equal share

	cout << "Donut Calculator" << endl << endl;

	/*Do, While loop asking for how many people wants donuts
	Validates that the number is never a negitive number or 0 */
	do
	{
		cout << "How many people? ";
		cin >> num_people;
		if (num_people <= 0)
			cout << "Please provide a number greater than zero." << endl;
	} 
	while (num_people <= 0);

	/*Do, While Loop asking for the total Money the group has
	Validates that the number is never a negitive number or 0*/

	do 
	{
		cout << "How much money does the group have? ";
		cin >> total_money_on_hand;
		if (total_money_on_hand <= 0)
			cout << "Please provide a number greater than zero" << endl;
	}
	while (total_money_on_hand <= 0);

	/*Do, While Loop asking for the total Money the group has
	Validates that the number is never a negitive number or 0*/
	do 
	{
		cout << "How much does a donut cost? ";
		cin >> cost_per_donut;
		if (cost_per_donut <= 0)
			cout << "Please provide a number greater than zero" << endl;
	} 
	while (cost_per_donut <= 0);

	//Math Operations
	num_donut =  (int) (total_money_on_hand / cost_per_donut); 
	//Changed typecasting from inplecit to explecit
	change_left_over = total_money_on_hand - (cost_per_donut*num_donut);
	num_of_donut_per_person = (num_donut) / num_people;
	remainder_of_donut = (num_donut) % num_people;

	//Creates the set precision to standardized demciel outputs 
	cout << fixed << showpoint << setprecision(2);
    
	//Output of information 
	cout << "With $" << total_money_on_hand << " you can purchase ";
	cout << (num_donut) << " donuts and have $" << change_left_over;
	cout << " left over." << endl;
	cout << "Each person gets " << num_of_donut_per_person;
	cout << " donuts and there will be " << remainder_of_donut;
	cout << " donuts left over." << endl;

	return 0;
}