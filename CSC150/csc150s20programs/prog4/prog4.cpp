/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, for, and arrays
 *
 * @mainpage Caesar Cipher Codec
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
 * @details The purpose of this program is us a Cearsor Cypher to encrypt and 
   decrypt messages. This is accomplished through the use of cstring inputs, 
   command line arguments, and file input/output. 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> prog4.exe
   d:\> c:\bin\prog4.exe
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
   4/08/2020      Rotate message function built
   4/09/2020      File input function built
   4/10/2020      File rotate function built
   4/13/2020      Update to comments and doxegyn 
   4/14/2020      Working on command line arguments
   4/17/2020      Command line argument are built and running
   4/18/2020      Updated comments for the program.
   4/21/2020      Update comment for the program



   @endverbatim
 *
 *****************************************************************************/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <fstream>

using namespace std;

/******************************************************************************
 *             Constant Variables, defines and Enums
 *****************************************************************************/
 /*!
  * @brief How many elements in array
  */

const int MESSAGE_SIZE = 1025;
const char ALPHABET[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

/******************************************************************************
 *                         Function Prototypes
 *****************************************************************************/

char show_menu(void);
void get_message(char user_message[]);
int get_key(void);
void get_filename(char user_filename[]);
void rotate_message(char user_message[], char out_message[], int key);
char rotate_char(char temp, int key);
int open_file(char user_filename[], ifstream &fin);
void rotate_file(ifstream &fin, int key);
void command_fail(char program[]);

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called and where the command line functions are checked.
 * @param[in]     int argc
 * @param[in]     char argv
 *
 * @returns 0 program ran successful.
   @return -1 program fails command line
 *
 *****************************************************************************/

int main(int argc, char *argv[])
{
    bool user_choose = false; //var if the user input is true or not
    char user_input; //var for which program that the user wants 
    char user_message[MESSAGE_SIZE]; //user message that they input
    char user_filename[MESSAGE_SIZE]; // file name of that the user inputs
    char out_message[MESSAGE_SIZE] = { 0 }; // output of the rotated message
    int key; //the encryption key that the user chooses.
    int open = 0; // if the file open correctly or not. 
    ifstream fin; // file stream that was opened. 

    //if there is more or less than 1 argument passed. 
    if (argc != 1)
    {
        //if there is more than 1 and less than 4 arguments passed then
        if (argc != 4)
        {
            //call command_fail and terminate with -1
            command_fail(argv[0]);

            return -1;
        }
        //if there are 4 argument passed then 
        else
        {
            //convert argument 2 into a int
            key = atoi(argv[2]);

            //if the key is less than -25 and not 0 and greater than 25
            if (key <= -25 && key != 0 && key >= 25)
            {
                //call command_fail and terminate with -1 
                command_fail(argv[0]);

                return -1;
            }

            //if the second argument is "-e" then encrypt message
            if (strcmp(argv[1], "-e") == 0)
            {
                //call rotate message and rotate message in 4th argument
                rotate_message(argv[3], out_message, key);
               
                //output the rotated message
                cout << endl << out_message;

                //return 0 and terminates programs successfully
                return 0;
            }
            //if the second argument is "-E" then encrypt file
            else if (strcmp(argv[1], "-E") == 0)
            {
                //call open file
                open = open_file(argv[3], fin);

                //if open file is equal to 0 then 
                if (open == 0)
                {
                    //rotate file and output message
                    rotate_file(fin, key);
                }

                //close file
                fin.close();

                //return 0 and terminates programs successfully
                return 0;
            }
            //if the second argument is "-d" then decrypt message
            else if (strcmp(argv[1], "-d") == 0)
            {
                //call rotate message and rotate message in 4th argument 
                rotate_message(argv[3], out_message, key);

                //output decrypted message
                cout << endl << out_message;

                //return 0 and terminates programs successfully
                return 0;
            }
            //if the second argument is "-D" then decrypt file
            else if (strcmp(argv[1], "-D") == 0)
            {
                //call open file
                open = open_file(argv[3], fin);
                
                //if open file is equal to 0 then 
                if (open == 0)
                {
                    //rotate file and output message
                    rotate_file(fin, key);
                }

                //close file
                fin.close();

                //return 0 and terminates programs successfully
                return 0;
            }
            //if any other second argument is anything other then e,E,d,or D 
            else
            {
                //call command_fail and terminate with -1 
                command_fail(argv[0]);

                return -1;
            }
        }
    }
    //if there is 1 argument then 
    else if (argc == 1)
    {
        //While loop to get a valid users input
        while (user_choose == false)
        {
            //calls show_menu and returns a user_input
            user_input = show_menu();

            //if input is 1,2,3,4, or 0 then exit loop
            if (user_input == '1' || user_input == '2' || user_input == '3'
                || user_input == '4' || user_input == '0')
            {
                user_choose = true;
            }
            //if input is anything other than 1,2,3,4,or 0 then output Invalid 
            //message and run loop again
            else
            {
                cout << endl << "Invalid Operation!";
            }

        }



        //if user input was 1 then run Encrypt message
        if (user_input == '1')
        {
            //calls get_message and gets the message from the user
            get_message(user_message);

            //calls get key and receives the key for the user
            key = get_key() * -1;

            //calls rotate message and encrypts the message
            rotate_message(user_message, out_message, key);

            //output the encrypted message
            cout << endl << "Encrypted message: " << out_message;
        }
        //if the user choose to run decrypt the message program
        else if (user_input == '2')
        {
            //calls get_message and gets the message from the user
            get_message(user_message);
            
            //calls get key and receives the key for the user
            key = get_key();

            //calls rotate message and encrypts the message
            rotate_message(user_message, out_message, key);

            //output the Decrypted message
            cout << endl << "Decrypted message: " << out_message;
        }
        //if the user choose to run the encrypt file message program
        else if (user_input == '3')
        {
            //call get filename
            get_filename(user_filename);

            //calls get key and receives the key for the user
            key = get_key() * -1;

            //output title message of function performed
            cout << endl << "Encrypted data: " << endl;

            //call open file
            open = open_file(user_filename, fin);

            //if file is open 
            if (open == 0)
            {
                //call rotate file 
                rotate_file(fin, key);
            }
            else
            {
                return 0;
            }

            //close file
            fin.close();
        }
        //if the user choose to run the decrypt file message program
        else if (user_input == '4')
        {
            //call get filename
            get_filename(user_filename);

            //calls get key and receives the key for the user
            key = get_key();

            //output title message of function performed
            cout << endl << "Decrypted data: " << endl;

            //if file is open
            if (open == 0)
            {
                //call rotate file 
                rotate_file(fin, key);
            }
            else
            {
                return 0;
            }

            //close file
            fin.close();
        }
        //if user does not input 0 then terminate program. 
        else
        {
            //output bye
            cout << endl << "Bye!";

            //return 0 and program closed successful
            return 0;
        }
    }
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function displays the information for the menu and gets the users input

 * @param[in]     none
 * @param[in]     none
 *
 * @returns user_input - the program the user whats to run.
 *
 *****************************************************************************/

char show_menu(void)
{
    char user_input; //var for the users input

    //output the menu iformation
    cout << endl << "*** Caesar Cipher Codec ***";
    cout << endl << "1. Encrypt message";
    cout << endl << "2. Decrypt Message";
    cout << endl << "3. Encrypt file";
    cout << endl << "4. Decrypt file";
    cout << endl << "0. Cancel / Exit";
    cout << endl << "Enter your operation: ";
    
    //input for the users choose
    cin >> user_input;

    //the user choice back to main.
    return user_input;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function gets the message the user wants to encrypt or decrypt.
 
 * @param[out]     user_message - the message that the user inputs
 * @param[in]      none
 *
 * @returns none.
 *
 *****************************************************************************/

void get_message( char user_message[])
{
    //output asking the user for there message
    cout << endl << "Enter your message: ";
   
    //clears cin
    cin.ignore();

    //gets the usermessage and inputs it into a cstring called user_message
    cin.getline(user_message, MESSAGE_SIZE);
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in nothing and gets the the user to input a key that is 
   between -25 and 25. Also it disludes 0.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns user_input - the key that the user wants to use.
 *
 *****************************************************************************/

int get_key(void)
{
    bool valid_key = false; //var to determine if the input is valid
    int key; //the key that the user inputs
    
    //loop to obtain a valid key for encryption
    while (valid_key == false)
    {
        //output and input looking for the key the user wants to enter
        cout << endl << "Enter your key: ";
        cin >> key;

        //if the key is greater than -25, not 0, and less than 25   
        if (key >= -25 && key != 0 && key <= 25)
        {
            //set user_choose to true
            valid_key = true;
        }
        //if the key is less than -25, 0 or greater than 25
        else
        {
            //output that a invalid key was entered. 
            cout << endl << "Invalid key!";
        }
    }

    //returns that the key to the calling function
    return key;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function gets the filename that the user wants to have encrypted or 
   decrypted.

 * @param[out]     user_filename- the file name the user inputs
 * @param[in]      none
 *
 * @returns none.
 *
 *****************************************************************************/

void get_filename(char user_filename[])
{
    //output asking the user for a filename
    cout << endl << "Enter your filename: ";

    //clears the cache of cin
    cin.ignore();

    //gets the filename and stores it into a cstring called user_filename
    cin.getline(user_filename, MESSAGE_SIZE);
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function takes in a message and encrypts or decrypts the message.
 * @param[in]     user_message - the message that the user inputs to encryption
 * @param[in]     key - the number of shits that needs to happen
 * @param[out]    out_message - meesage that was ran through the encyption
 *
 * @returns none.
 *
 *****************************************************************************/

void rotate_message(char user_message[], char out_message[], int key)
{
    int i = 0; // temp var
    char temp; //temp place holder for a single character.

    //voids out all of the characters that are in the out_message string
    memset(out_message, 0, MESSAGE_SIZE);
    
    //loop that checks the user input message char is not a null.
    while (user_message[i] != 0)
    {
        //converts user message char to a upper case letter
        user_message[i] = toupper(user_message[i]);
       
        //moves i by 1 
        i++;
    }

    //reset i to 0
    i = 0;

    //loop that checks the user input message char is not a null
    while (user_message[i] != 0)
    {
       
        //if the user char was is a letter 
        if (isalpha(user_message[i]))
        {
            //store the char into a temp holder
            temp = user_message[i];
            
            //rotates the char and stores it into the out message
            out_message[i] = rotate_char(temp, key);
        }

        //if the user char is not a letter
        else
        {
            //output the next char to the out message
            out_message[i] = user_message[i];
        }

        //increase the i by 1
        i++;
    }

}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Moves the char by however many steps the user key states.
 * @param[in]     temp - the char that needs to be rotated
 * @param[in]     key - the number of shift to the left or right
 *
 * @returns rotated - the rotated char.
 *
 *****************************************************************************/

char rotate_char(char temp, int key)
{
    int pos; // initial position of the char
    char rotated; // position of the char after the rotate

    // the intital postion of the char
    pos = temp - 'A';
   
    // the postion of the char after the shift
    pos = pos - key;

    //ensure the positiion of the char is with in the alphabet.
    pos = (pos + 26) % 26;

    //thats the position of the the rotate letter and gets the new letter
    rotated = ALPHABET[pos];
    
    //returns the rotated letter. 
    return rotated;
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function opens a file. 

 * @param[in]     user_filename - file name that needs to be open
 * @param[out]    fin - the input file stream 
 *
 * @returns 0 file opened successfully.
 * @returns -1 file failed to open successfully.
 *
 *****************************************************************************/

int open_file(char user_filename[], ifstream &fin)
{
    //opens the file
    fin.open(user_filename);
    
    //if the file did not open
    if (!fin)
    {

        //return -1
        return -1;
    }

    //if the file did open
    else
    {
        //return 0
        return 0;
    }

}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function  takes in a file and rotates the file message and output the 
   the message.
 * @param[in]     fin - the file input stream
 * @param[in]     key - the number of shifts that need to occur 
 *
 * @returns none.
 *
 *****************************************************************************/

void rotate_file(ifstream &fin, int key)
{
    //the var that obtains the file stream. 
    char input[MESSAGE_SIZE] = { 0 };

    //the var that outputs the file stream.
    char print_message[MESSAGE_SIZE] = { 0 };

    //loop that while there is a line to get 
    while (fin.getline(input, MESSAGE_SIZE))
    {
        //calls rotate message and rotates line
        rotate_message(input, print_message, key);

        //output the rotated message
        cout << endl << print_message << endl;

        //resets the input string to null
        memset(input, 0, MESSAGE_SIZE);
    }
}

/******************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This message displays when the command line fails to execute property.

 * @param[in]     program - the program that is be executed 
 * @param[in]     none
 *
 * @returns none
 *
 *****************************************************************************/

void command_fail(char program[])
{
    //output when the command line fails
    cout << endl << "Invalid argument(s).";
    cout << endl << "Syntax: " << program << "[ACTION KEY OBJECT]";
    cout << endl << "Where :";
    cout << endl << "-ACTION must be :";
    cout << endl << "\t -e to encrypt message";
    cout << endl << "\t- E to encrypt file";
    cout << endl << "\t- d to decrypt message";
    cout << endl << "\t- D to decrypt file";
    cout << endl <<
        "- KEY must be a non - zero integer between - 25 and (inclusive)";
    cout << endl <<
        "-OBJECT must be a string or an existing file, according to ACTION.";

}
