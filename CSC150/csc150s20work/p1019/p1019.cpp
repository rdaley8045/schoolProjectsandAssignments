/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while,for, if, and boolan
 *
 * @mainpage Lab 07 - Mathematical Loop - (p1019)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 2/25/2020
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
 * @details The prupose of this program is to illustrate the multiple uses of
   loops in a program. This is done by having a basic menu created that loops 
   until the user intup the quit command of Q. This program also  shows that 
   loops can be used to perform both basic math and complex math equations.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1019.exe
   d:\> c:\bin\p1019.exe
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
   2/25/2020      Started Programs
   2/26/2020      Program completed 

   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

void calculate_pi(void);
void calculate_sqr(void);
void multiplication_table(void);



/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This s where the program menu 
   lives. This is also where each function  is called to be completed

 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 ****************************************************************************/


int main()
{
 
    string program_choice; //The letter for which program the user wants to run
    bool menu_loop = false; // Creates a loop variable and sets it to false
    
    //Creates a while loop that continues to run program until quit is choicen
    while (menu_loop == false)
    {
        //Program title
        cout << "Mathematical loops" << endl << endl;

        //Outputs the list of sub programs that can be ran
        cout << "P - Calculate PI" << endl;
        cout << "S - Calculate square root of 2" << endl;
        cout << "M - Print multiplication table" << endl;
        cout << "Q - quit" << endl << endl << "Choice: ";

        //User input of menu choice
        cin >> program_choice;

        //if user choices P then the pi calculating function runs
        if (program_choice == "P" || program_choice == "p")
        {
            calculate_pi();

            //set menu_loop variable to false to keep loop running
            menu_loop = false;
        }

        //if user choices S then the square root calculation function runs
        else if (program_choice == "S" || program_choice == "s")
        {
            calculate_sqr();

            //set menu_loop variable to false to keep loop running
            menu_loop = false;
        }

        //if user choices M then the multiplication table function runs
        else if (program_choice == "M" || program_choice == "m")
        {
            multiplication_table();

            //set menu_loop variable to false to keep loop running
            menu_loop = false;
        }

        //if the user choices Q then this terminates the program
        else if (program_choice == "Q" || program_choice == "q")
        {
            //set mean_loop variable to true and terminates the loop
            menu_loop = true;
        }
        
        //if the user inputs anything other than S, M, Q, and P
        else
        {
            
            //Outputs if the user input is incorrect
            cout << "Invalid selection!" << endl << endl << endl;
            
            //set menu_loop variable to false to keep loop running
            menu_loop = false;
        }
    }

    //Message that the program is terminating.
    cout << "Program ending, goodbye.";

    //Program runs successfully 
    return 0; 
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This funcation takes in the number terms a user wants to give in order to 
   find pi. After calcuating the value it output the value and then terminates
   itself.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns  none
 *
 ****************************************************************************/

void calculate_pi(void)
{
    int num_terms; //number of terms the user would like ran
    double n; // Temp variable for which the equation uses to be ran
    double calculation = 1; // the answer to what the equation outputs
    
    //set the precision of the answer for this function 
    cout << fixed << showpoint << setprecision(4);
    
    //Asks the user for the number terms that they want run
    cout << "Enter number of terms to use: ";
    cin >> num_terms;

    /*As long as the temp varable of n is less than or equal to the number
    of terms the user inputs then the equations will run. After check run is 
    complete then n is moved 1 place up.*/
    for (n = 1; n <= num_terms; n++)
    {
        calculation *= (((2 * n) / ((2 * n) - 1)) * ((2 * n) / ((2 * n) + 1)));
    }

    //multiples the answer by 2
    calculation *= 2;

    //Outputs the answer and the number of terms
    cout << "Calculated value of PI with " << num_terms << " terms is ";
    cout << calculation << endl << endl << endl;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This funcation calculated what the value of the square root of 2 is. This
   also allows the user to set the tolerance level for how close the user
   wants their answer to be. 

 * @param[in]     none
 * @param[in]     none
 *
 * @returns none
 *
 ****************************************************************************/

void calculate_sqr(void)
{
    double num_limitation; //User inputed limits
    double n=1.0; // Temp Variable 
    double calculation = 1.0; // Answer for equation
    int i = 0; // counter

    //sets the  percision for this function
    cout << fixed << showpoint << setprecision(4);

    //asks the user for the tolerance value
    cout << "Enter tolerance value: ";
    cin >> num_limitation;

    /*While the square of the answer -2 is greater than the limitation the 
    equations is ran.*/
    while (fabs ((calculation*calculation) - 2) > num_limitation)
    {
        calculation *= (((2 * n) / ((2 * n) - 1)) * ((2 * n) / ((2 * n) + 1)));
        
        //the variable is increase by 2 to keep it odd.
        n += 2;

        //increases the counter
        i++;
    }

    //output the answers to the user
    cout << "Calculated square root of 2 is " << calculation;
    cout << " using " << i << " interactions" << endl << endl << endl;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function produces a multiplication table based on who many number the 
    user want to see up to. 

 * @param[in]     none
 * @param[in]     none
 *
 * @returns none
 *
 ****************************************************************************/

void multiplication_table(void)
{
    int user_num; // user input for the amount of number that they want to see
    int i; // Temp valiue 
    int j = 1; // temp value
    int k; // Temp value

    //asks the user for the number of value they want to see
    cout << "Enter value of n: ";
    cin >> user_num;
    cout << "Multiplication table" << endl;

    //When I is less than or equal to  the user number than the loop runs
    for (i = 1; i <= user_num; i++)
    {
        
        //If the when both I and J are set to the same number then outputs 
        //the header row of the table
        if (i == j)
        {

            //set inital spacing to 10 spaces wide
            cout << setw(10);

            //While the I is less than user_number print I and increase by 1
            for (i = 1; i <= user_num; i++)
            {
                cout << i << setw(5);
            }

            //print new line an reset I to 1
            cout << endl;
            i = 1;
        }

        //While J is less than the user number then it prints out the remainder
        //of the table
        for (j = 1; j <= user_num; j++)
        {
            //if I and J are that same number then sets the column to 5 
            //wide and print out the first number of each row
            if (i == j)
            {
              
                cout << setw(5) << j;
              
            }
             
            // while J is larger of I the perform multiplication and output 
            //amount.
            for (i = 1; j >= i; i++)
            {
                k = i * j;

                cout << setw(5) << k;
            }

                cout << endl;

        }

    }

    //ends program and adds new lines 
    cout << endl << endl;
}
