/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, boolan, cctype, and cmath
 *
 * @mainpage Lab 06 - Password strenght (p1018)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 2/20/2020
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
 * @details The purprose of the programs is to evaluate the strength of a 
    password. This is completed by evaluating each char to determine the 
    char pool and then evaluating the entropy of the password. Once this is 
    completed the program outputs the strength of the password.
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1018.exe
   d:\> c:\bin\p1018.exe
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
   2/20/2020      Program writen and tested

   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>

using namespace std;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/


int ch_pool_generator(bool lower, bool upper, bool digit, bool blank,
    bool punct);
void password_complexity(double entropy);

/** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This is the main function of the program. This is where all of the input
    and basic evaluation of the program occurs.

  * @param[in]     none
  * @param[in]     none
  *
  * @returns 0 program ran successful.
  *
  ****************************************************************************/

int main()
{
    //If character is lower and sets inital value to false
    bool lower = false;
    //If character is upper and sets inital value to false
    bool upper = false;
    //If character is a digit and sets the inital value to false
    bool digit = false;
    //If character is blank and sets the inital value to false
    bool blank = false;
    //If character is a punctuation and sets the inital value to false
    bool punct = false;
    char ch; //each character of the password
    double entropy_bits; //entropy value of each bit of the password
    double entropy_total; //total entropy value the whole of the password
    int ch_pool; //Total of the character pool
    int i = 0; // Character counter
  
    //set percision
    cout << fixed << showpoint << setprecision(2);
    
    //Title of the program
    cout << "Password checker" << endl;

    //Asks for the passowrd to be entered and get password
    cout << endl << "Enter password/passphrase: ";
    cin.get(ch);
    
    //Out puts the first char of the program
    cout << "Password: " << ch;
   
    //Condition loop to  evaluate check character
    while (ch != '\n')
    {

        //Adds 1 to the character counter
        i++;
        
        //Evaluated if char is lower case and set value to true
        if (islower(ch))
        {
            lower = true;
        }
        
        //Evaluated if char is upper case and set value to true
        else if (isupper(ch))
        {
            upper = true;
        }
       
        //Evaluated if char is a digit and set value to true
        else  if (isdigit(ch))
        {
            digit = true;
        }
       
        //Evaluated if char is blank and set value to true
        else  if (isblank(ch))
        {
            blank = true;
        }

        //Evaluated if char is a punctuation and set value to true
        else if (ispunct(ch))
        {
        punct = true;
        }

        //gets next value for evaluation
        cin.get(ch);

        //Out puts the next char
        cout << ch;
    }

    //Calculates and outputs the char pool
    ch_pool = ch_pool_generator(lower, upper, digit, blank, punct);
    cout << "Character pool: " << ch_pool << endl;
    
    //Outputs the password size
    cout << "Password size: " << i << endl;

    //Calculates and outputs the entropy of the password base of the char pool
    entropy_bits = log2(ch_pool);
    cout << "Entropy bits per character: " << entropy_bits << endl;

    //Calculates and outputs the total entropy for the total lenght of password
    entropy_total = entropy_bits * i;
    cout << "Password entropy value: " << entropy_total << endl;

    //Outputs the strenght of the password
    password_complexity(entropy_total);


    //program runs successfully
    return 0;

}

/** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function takes in the boolan values of the lower, upper, digit, 
    blank, and punct evaluation as assign a numerical value to each item.
    Once each value is assigned then the total of all values are calculated.

  * @param[in]     Lower - The boolan value for lower
  * @param[in]     Upper - The boolan value for upper
  * @param[in]     Digit - The boolan value for digit
  * @param[in]     Blank - The boolan value for blank
  * @param[in]     Punct - The boolan value for punct
  *
  * @returns ch_pool - The total amount of the char pool
  *
  ****************************************************************************/

int ch_pool_generator(bool lower, bool upper, bool digit, bool blank,
    bool punct)
{
    int ch_pool; // total of the char pool
    int ch_pool_lower; // value of the lower case pool
    int ch_pool_upper; // value of the upper case pool
    int ch_pool_digit; // value of the digit pool
    int ch_pool_blank; // value of the blank pool
    int ch_pool_punct; // value of the punctuation pool

    //If lower is true then set to 26 if not then set to 0
    if (lower == true)
    {
        ch_pool_lower = 26;
    }
    else
    {
        ch_pool_lower = 0;
    }

    //If upper is true then set value to 26 if not then set to 0
    if (upper == true)
    {
        ch_pool_upper = 26;
    }
    else
    {
        ch_pool_upper = 0;
    }

    //If digit is true then set value to 10 if not then set to 0
    if (digit == true)
    {
        ch_pool_digit = 10;
    }
    else
    {
        ch_pool_digit = 0;
    }

    //If digit is true then set value to 2 if not then set to 0
    if (blank == true)
    {
        ch_pool_blank = 2;
    }
    else
    {
        ch_pool_blank = 0;
    }

    //If punct is true then set value to 32 if not then set to 0
    if (punct == true)
    {
        ch_pool_punct = 32;
    }
    else
    {
        ch_pool_punct = 0;
    }

    //Calculate the total of all of the pool values 
    ch_pool = ch_pool_lower + ch_pool_upper + ch_pool_digit + ch_pool_blank +
        ch_pool_punct;

    //sents total to  the main function
    return ch_pool;
}

/** **************************************************************************
  * @author Raymond Daley
  *
  * @par Description:
  * This function looks at the total entropy of the password and outputs
    what the strength level of the password is.

  * @param[in]     total_entropy - The total amount of the entropy 
  * @param[in]     none
  *
  * @returns none. 
  *
  ****************************************************************************/

void password_complexity(double entropy)
{
    //Outputs the title of the value outputing
    cout << "Password strength: ";

    //if entropy is less than 45 output Very Weak
    if (entropy < 45)
    {
        cout << "Very weak";
    }

    //if entropy is greater than equal to 45 and less than 52 output Weak
    else if (entropy >= 45 && entropy < 52)
    {
        cout << "Weak";
    }

    //if entropy is greater than equal to 52 and less than 72 output Reasonable
    else if (entropy >= 52 && entropy < 72)
    {
        cout << "Reasonable";
    }

    //if entropy is greater than equal to 72 and less than 127 output Strong
    else if (entropy >= 72 && entropy < 127)
    {
        cout << "Strong";
    }

    //if the entropy is greater than or equal to  127 the output Very Strong
    else
    {
        cout << "Very strong";
    }

 }