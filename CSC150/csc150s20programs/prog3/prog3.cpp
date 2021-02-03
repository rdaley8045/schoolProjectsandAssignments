/** ***************************************************************************
 * @file
 * @brief demonstrates arrays, functions, while, if, and boolean
 *
 * @mainpage Program 3 - 32-digits calculator
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
 * @details The purpose of this program is to calculate large 32 digit 
   numbers together using arrays and functions. The program starts by asking
   the user to choice between 4 options addition, subtraction, multiplication, 
   or to terminate the program. Once the user choice which program they would
   like to run then the program asks the user for then to input 2 large digits.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog3.exe
   d:\> c:\bin\prog3.exe
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
   3/03/2020      Started Programs
   3/04/2020      Modified menu and program selection
   3/05/2020      Worked on Input of numbers
   3/06/2020      Worked on Input of numbers tuning for variations of input
   3/07/2020      Started work on the addition section of the program
   3/08/2020      Finished the addition section starting on the subtraction
   3/09/2020      Completed the subtraction section starting on multiplication
   3/18/2020      Completed the multiplication function
   3/20/2020      Completed the program reworked to matched program requirement
   3/22/2020      Fixed program errors
   3/23/2020      Completed program with successful run
   3/25/2020      Completed program and all documentation 

   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;
/*******************************************************************************
 *             Constant Variables, defines and Enums
 ******************************************************************************/
 /*!
  * @brief How many elements in array
  */

//create constant var SIZE and set to 32
const int SIZE = 32;
//create constant var MULT_SIZE and set to 64
const int MULT_SIZE = 64;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

bool add(int num_1[], int num_2[], int answer[], int& answer_counter);
bool is_larger(int num_1[], int num_2[], int count_1, int count_2);
char get_menu_choice(void);
int get_number(int num[]);
int sub(int num_1[], int num_2[], int count_1, int count_2, int answer[],
    int& answer_counter);
void clear_array(int num[], int size);
void disp_right(int num[], int size, int counter);
void mult(int num_1[], int count_1, int num_2[], int count_2, int answer[],
    int& answer_counter);

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This where all of the functions
   are called and returned to. 

 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 *****************************************************************************/


int main()
{
    //create var overflow and set to false
    //Changed 1/15/2021
    bool doesAnswerOverflow = false; 
    // create var choice set to 'A'
    char userInputedChoice; 
    //create array answer and set size to SIZE and fill with 0's
    int answer[SIZE] = { 0 };
    //create array multi_answer and set size to MULT_SIZe and fill with 0's
    int multi_answer[MULT_SIZE] = { 0 };
    //create var answer_counter and set to 0
    int answer_counter = 0;
    //create temp var of i
    int i;
    //create var of negative
    int negative;
    //create array num_1 and set size to SIZE and fill with 0's
    int num_1[SIZE] = { 0 };
    //create var num_1_count and set to 0
    int num_1_count = 0;
    //create array num_2 and set size to SIZE and fill with 0's
    int num_2[SIZE] = { 0 };
    //create var num_2_count and set to 0
    int num_2_count = 0;

    //Get the menu choice that the user would like to run
    userInputedChoice = get_menu_choice();


    //While choice is equal to A, S, or M them run on of the options
    while (userInputedChoice == 'A' || userInputedChoice == 'S' || userInputedChoice == 'M')
    {
        //if user inputed A the run addition 
        if (userInputedChoice == 'A')
        {
          /*Message that asks the user to input the number, also
           set up so that the Size of the array is the size number that is
           asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";

            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_1 additional
            it returns the counter to num_1_count*/
            num_1_count = get_number(num_1);


            /*Message that asks the user to input the number, also
            set up so that the Size of the array is the size number that is
            asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";
            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_2 additional
            it returns the counter to num_2_count*/
            num_2_count = get_number(num_2);


            //Outputs the result of the function being performed
            cout << "The result of adding" << endl;

            //Displays the number to the right of the program
            disp_right(num_1, SIZE, num_1_count);

            //Displays the number to the right of the program
            disp_right(num_2, SIZE, num_2_count);

            //Creates a dashed line that is 40 char wide 
            cout << setfill('-') << setw(40) << "-" << endl;

            /*Calls the function add to add the two numbers together
            this function pass the answer and answer counter back by
            reference and returns if the number overflows the array*/
            doesAnswerOverflow = add(num_1, num_2, answer, answer_counter);

            // If the number overflows the array
            if (doesAnswerOverflow == true)
            {
                //Output message if an overflow has occurred. 
                cout << "Overflow occurred; result is incomplete." << endl;

                //Displays the answer to the right of the program
                disp_right(answer, SIZE, answer_counter);
            }
            //If the number does not overflow the array
            else
            {
                //Displays the answer to the right of the program
                disp_right(answer, SIZE, answer_counter);
            }

            //provides the correct number of space been the answer and the next
            //run of the program. 
            cout << endl;

            //Clear num_1 array
            clear_array(num_1, SIZE);

            //Clear num_2 array
            clear_array(num_2, SIZE);

            //Clear answer array
            clear_array(answer, SIZE);


        }

        // If user choose S then run subtraction
        else if (userInputedChoice == 'S')
        {

            /*Message that asks the user to input the number, also
            set up so that the Size of the array is the size number that is
            asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";

            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_1 additional
            it returns the counter to num_1_count*/
            num_1_count = get_number(num_1);

            /*Message that asks the user to input the number, also
            set up so that the Size of the array is the size number that is
            asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";
            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_2 additional
            it returns the counter to num_2_count*/
            num_2_count = get_number(num_2);


            //Outputs the result of the function being performed
            cout << "The result of subtracting" << endl;

            //Displays the number to the right of the program
            disp_right(num_1, SIZE, num_1_count);


            //Displays the number to the right of the program
            disp_right(num_2, SIZE, num_2_count);


            //Creates a dashed line that is 40 char wide 
            cout << setfill('-') << setw(40) << "-" << endl;

            //Run sub function and return if the number is negative or not
            negative = sub(num_1, num_2, num_1_count, num_2_count, answer,
                answer_counter);

            //If negative returned 1 then print answer like normal
            if (negative == 1)
            {
                disp_right(answer, SIZE, answer_counter);
            }

            //If negative return -1 then print answer with - in front of answer
            else
            {
                cout << setfill(' ') << setw(40 - answer_counter) << "-";
                for (i = SIZE - answer_counter; i <= SIZE - 1; i++)
                {
                    cout << answer[i];
                }
                cout << endl;
            }

            //provides the correct number of space been the answer and the next
            //run of the program. 
            cout << endl;

            //Clear num_1 array
            clear_array(num_1, SIZE);

            //Clear num_2 array
            clear_array(num_2, SIZE);

            //Clear answer array
            clear_array(answer, SIZE);




        }

        //if the user choice M for from the menu    
        else if (userInputedChoice == 'M')
        {

            /*Message that asks the user to input the number, also
            set up so that the Size of the array is the size number that is
            asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";

            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_1 additional
            it returns the counter to num_1_count*/
            num_1_count = get_number(num_1);


            /*Message that asks the user to input the number, also
            set up so that the Size of the array is the size number that is
            asked for*/
            cout << "Enter a number, up to " << SIZE << " digits: ";

            /*Calls function get_number that taking in the values inputed
            into the system and stores them into array num_2 additional
            it returns the counter to num_2_count*/
            num_2_count = get_number(num_2);


            //Outputs the result of the function being performed
            cout << "The result of multiplying" << endl;

            //Displays the number to the right of the program
            disp_right(num_1, SIZE, num_1_count);


            //Displays the number to the right of the program
            disp_right(num_2, SIZE, num_2_count);



            //Creates a dashed line that is 40 char wide 
            cout << setfill('-') << setw(40) << "-" << endl;

            //Call multiply function 
            mult(num_1, num_1_count, num_2, num_2_count, multi_answer,
                answer_counter);

            //Display the answer to the right
            disp_right(multi_answer, MULT_SIZE, answer_counter);

            //provides the correct number of space been the answer and the next
            //run of the program. 
            cout << endl;

            //Clear num_1 array
            clear_array(num_1, SIZE);

            //Clear num_2 array
            clear_array(num_2, SIZE);

            //Clear answer array
            clear_array(multi_answer, MULT_SIZE);

        }

        //Get the menu choice that the user would like to run
        userInputedChoice = get_menu_choice();


    }

    cout << "Bye";

    return 0;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main menu for the program. I is asking the user to choice which
   operation that they would like to perform. This function continues in a
   loop until the user inputs that they would like to quit by pressing X.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns choice - this is which program the user wants to run.
 *
 ****************************************************************************/

char get_menu_choice(void)
{
    //Declares variable choice and sets the value to 0
    char choice = '0';

    /*While the choices are not A, S, M, and X then continue the loop*/
    while (choice != 'A' && choice != 'S' && choice != 'M' && choice != 'X')
    {
        //out put title and menu choices
        cout << "*** Mines Big Number Calculator ***" << endl;
        cout << "A. Add two numbers" << endl;
        cout << "S. Subtract two numbers" << endl;
        cout << "M. Multiply two numbers" << endl;
        cout << "X. Exit program" << endl;
        cout << "Your choice: ";

        //gets the variable choice from the user
        cin >> choice;

        //if choice is an letter then 
        if (isalpha(choice))
        {
            //make the char an capatil letter.
            choice = toupper(choice);
        }

        //If the choice is not A,S,M,or X then output this is not valid.
        if (choice != 'A' && choice != 'S' && choice != 'M' && choice != 'X')
        {
            cout << choice << " is not a valid option." << endl;
            cout << endl;
        }
    }

    //return the user choice
    return choice;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Gets the number

 * @param[in/out]     int num[] - number array that requires to be filled
 *
 * @returns counter - the number of numbers in the user inputs 
 *
 ****************************************************************************/ 

int get_number(int num[])
{
    //create user_input var ans set to ' '
    char user_input; 
    //create input array and set to size SIZE and fill with ' '
    char input[SIZE];
    //create var counter and set to 0
    int counter = 0;
    //create temp var i and set to 0
    int i = 0;
    //create temp var j
    int j;


    //clears the num of any possible values 
    clear_array(num, SIZE);
    
    //Gets the user input
    cin >> user_input;

    //if the user input is a digit or a ","
    if (isdigit(user_input) || user_input == ',')
    {
        //while the user doesn't press enter
        while (user_input != '\n')
        {
            //if the input is a digit
            if (isdigit(user_input))
            {
                //store char into input array 
                input[i] = user_input;

                //move i up by one
                i++;

                //moves counter by one
                counter++;

                //get the next char in line
                cin.get(user_input);

            }

            //if the char is a "," then get next char
            else if (user_input == ',')
            {
                cin.get(user_input);
            }

        }
    }

    //sets i to 0
    i = 0;

    //generate loop to transfer char to an int array
    for (j = SIZE - counter; j < SIZE; j++)
    {
        num[j] = input[i] - '0';
        i++;
    }

    //returns the counter
    return counter;

}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Takes 2 digits and adds them together will show an overflow if the answer
   is greater than 32 digits

 * @param[in/out]     int num_1[] - num 1 array
 * @param[in/out]     int num_2[] - num 2 array
 * @param[in/out]     int answer[] - answer array
 * @param[out]        int answer_counter - answer counter passed by reference
 *
 * @returns overflow - tells if the answer is greater than 32 digits
 *
 ****************************************************************************/

bool add(int num_1[], int num_2[], int answer[], int& answer_counter)
{
    //create var overflow and set to false
    bool overflow = false;
    //create var carry and set to 0
    int carry = 0;
    //create var counter and set to 0
    int counter = 0;
    //create temp var i
    int i;
    //create temp var k
    int k;

    //set answer counter to 0
    answer_counter = 0;

    //clears answer array of any possible values
    clear_array(answer, SIZE);

    //loop for performing the addition
    for (i = SIZE - 1; i >= 0; i--)
    {
        //Adds num_1, num_2, and carry and stores answer in k
        k = num_1[i] + num_2[i] + carry;

        //stores remainder of 10 in the answer array 
        answer[i] = k % 10;

        //Carry is 10 / k which produces the carry over in addition
        carry = k / 10;

    }

    // Sets i to 0
    i = 0;

    //while the answer in array is 0 then count
    while (answer[i] == 0)
    {
        counter++;
        i++;
    }

    //answer_counter is size of array - counter
    answer_counter = SIZE - counter;

    //if carry is greater than 0 then set overflow to true
    if (carry > 0)
    {
        overflow = true;
    }

    //return overflow to main
    return overflow;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Displays the number in the array and justifies the number to the right

 * @param[in]     int num[] - num array that need to justified to the right
 * @param[in]     int size - size of the array
 * @param[in]     int counter - the counter of the array being printed

 *
 * @returns none.
 *
 ****************************************************************************/

void disp_right(int num[], int size, int counter)
{
    //create temp var i
    int i;

    //set blank space between the left and where the number begins
    cout << setfill(' ') << setw(41 - counter);

    //loop to output each digit one at a time from left to right. 
    for (i = size - counter; i < size; i++)
    {
        cout << num[i];
    }

    //outputs a new line
    cout << endl;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Takes 2 digits and subtracts them returns a -1 or 1 to indicate if the 
   answer is an negative number or not. 

 * @param[in/out]     int num_1[] - num 1 array 
 * @param[in/out]     int num_2[] - num 2 array
 * @param[in]         int count_1 - num 1 count
 * @param[in]         int count_2 - num 2 count
 * @param[in/out]     int answer[] - answer array
 * @param[in/out]     int answer_counter - number of digits in answer
 *
 * @returns negative - This is an indicator if the answer is negative
 *
 ****************************************************************************/

int sub(int num_1[], int num_2[], int count_1, int count_2, int answer[],
    int& answer_counter)
{
    //create var larger
    bool larger;
    //create var counter and set to 0
    int counter = 0;
    //create temp var i
    int i;
    //create var negative and set to 0
    int  negative = 0;
        
    //choices which number is larger
    larger = is_larger(num_1, num_2, count_1, count_2);

    //if num 2 is large then answer is going to be negative
    if (larger == true)
    {

        //loop to subtract num2 from num1 
        for (i = SIZE - 1; i >= 0; i--)
        {
            //subtract num2 from num1 and store in answer
            answer[i] = num_2[i] - num_1[i];

            //If the answer is than 0
            if (answer[i] < 0)
            {
                //subtract 1 form the next number that needs to be subtracted
                num_2[i - 1] -= 1;

                //add ten to the current answer
                answer[i] += 10;
            }
        }

        //make negative -1
        negative = -1;

    }
    //if num 1 is large then the answer will be positive
    else
    {

        //loop to subtract num2 from num1 
        for (i = SIZE - 1; i >= 0; i--)
        {
            //subtract num1 from num2 and store in answer
            answer[i] = num_1[i] - num_2[i];
            
            //If the answer is than 0
            if (answer[i] < 0)
            {
                //subtract 1 form the next number that needs to be subtracted
                num_1[i - 1] -= 1;

                //add ten to the current answer
                answer[i] += 10;
            }

        }

        //make negative equal to 1
        negative = 1;
    }

    //set i to 0
    i = 0;

    //while the answer in array is 0 then count
    while (answer[i] == 0)
    {
        counter++;
        i++;
    }

    //answer counter is equal to mult_size - counter
    answer_counter = SIZE - counter;


    //return negative to main
    return negative;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This takes in 2 digits and multiples them together. The answer can be twice
   the size of the original inputed numbers

 * @param[in/out]     int num_1[] - num 1 array
 * @param[in/out]     int num_2[] - num 2 array
 * @param[in]         int count_1 - num 1 count
 * @param[in]         int count_2 - num 2 count
 * @param[in/out]     int answer[] - answer array
 * @param[in/out]     int answer_counter - number of digits in answer
 *
 * @returns none
 *
 ****************************************************************************/

void mult(int num_1[], int count_1, int num_2[], int count_2, int answer[],
    int& answer_counter)
{
    //create array ans and set size MULT_SIZE and fill with 0
    int ans[MULT_SIZE] = { 0 };
    //create var carry and set to 0
    int carry = 0;
    //create var counter and set to 0
    int counter = 0;
    //create temp var i
    int i;
    //create temp var j
    int j;
    //create temp var k and equal to 0
    int k = 0;
    //create temp var l
    int l;
    //create temp var m
    int m;
    //create temp n and set to MULT_SIZE minus 1
    int n = MULT_SIZE - 1;
    

    //start of the loop that gets the last number of num 2
    for (i = SIZE - 1; i >= 0; i--)
    {

        //start of the loop that performs the multiplication and get num 1
        for (j = SIZE - 1; j >= 0; j--)
        {

            //creates variable for storing the answer in ans variable
            m = n - k;

            //multiples num 1 and num 2 and add the carry and stores in l
            l = (num_1[j] * num_2[i]) + carry;

            //carry is equal to l divided by 10
            carry = l / 10;

            //ans is equals to l remainder 10
            ans[m] = l % 10;

            //reduce by n
            n--;
        }

        //sets l to 0
        l = 0;

        //sets carry to 0
        carry = 0;


        //create for loop for storing the answer and adding them together
        for (j = MULT_SIZE - 1; j >= 0; j--)
        {

            //adds answer, ans and carry stores answer to l
            l = (answer[j] + ans[j]) + carry;

            //carry is equal to l divided by 10
            carry = l / 10;

            //answer is equals to l remainder 10
            answer[j] = l % 10;
        }

        //clear ans array of any possible numbers
        clear_array(ans, MULT_SIZE);

        //add 1 to k
        k++;

        //set n back the mult_size minus 1
        n = MULT_SIZE - 1;
    }

    //set l to 0
    l = 0;

    //while the answer in array is 0 then count
    while (answer[l] == 0)
    {
        counter++;
        l++;
    }

    //answer counter is equal to mult_size - counter
    answer_counter = MULT_SIZE - counter;
}


/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Clears the array of any possible numbers

 * @param[in/out]     int num[] - num array to be cleared
 * @param[out]        int size - size of array that need to be cleared
 *
 * @returns none.
 *
 ****************************************************************************/

void clear_array(int num[], int size)
{
    //create temp var i
    int i;

    //for loop that sets all array positions to zero
    for (i = 0; i < size; i++)
    {
        num[i] = 0;
    }
}


/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Determines if num 1 is larger than num 2 and returns true or false

 * @param[in/out]     int num_1[] - num 1 array
 * @param[in/out]     int num_2[] - num 2 array
 * @param[in]         int count_1 - num 1 count
 * @param[in]         int count_2 - num 2 count
 *
 * @returns is_larger - if num 1 is larger than num 2.
 *
 ****************************************************************************/

bool is_larger(int num_1[], int num_2[], int count_1, int count_2)
{
    //create var is_larger and set to false
    bool is_larger = false;
    //create temp var 
    int i;

    //if count 1 is larger than count 2 then is_larger is equal to false
    if (count_1 > count_2)
    {
        is_larger = false;
    }

    // if count 2 is larger than count 1 then is_larger is equal to true
    else if (count_2 > count_1)
    {
        is_larger = true;
    }

    //if count 1 is equal to count 2 then create loop to look at each digit
    else if (count_1 == count_2)
    {
        //loop to look at each digit individually
        for (i = SIZE - 1; i >= 0; i--)
        {

            //if num 2 is larger than num 1 then is_larger is equal to true
            if (num_2[i] > num_1[i])
            {
                is_larger = true;
            }

            //if num 1 is larger than num 2 then is_larger is equal to false
            if (num_1[i] > num_2[i])
            {
                is_larger = false;
            }
        }
    }

    //return is_larger back to calling function
    return is_larger;
}


