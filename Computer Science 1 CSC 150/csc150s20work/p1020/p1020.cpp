/** ***************************************************************************
 * @file
 * @brief demonstrates functions, while, if, and boolan
 *
 * @mainpage Lab 08 - Using functions (p1020)
 *
 * @section M01
 *
 * @author Raymond Daley
 *
 * @date 3/2/2020
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
   it takes to ship a package. This price depends on the weight, messurment of 
   the package and the distance. 
 *
 * @section compile_section Compiling and Usage
 *
 * @par Compiling Instructions:
 *      None
 *
 * @par Usage:
   @verbatim
   c:\> p1020.exe
   d:\> c:\bin\p1020.exe
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
   3/2/2020       Started Programs
 

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
bool get_distance(int& distance);
double cal_cost(double volume, int distance, int weight);
int get_weight();
void get_size(double& length, double& width, double& thickness);

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This is the main function of the program. This is where all of the function
   are called and where the output occurs.

 * @param[in]     none
 * @param[in]     none
 *
 * @returns 0 program ran successful.
 *
 ****************************************************************************/

int main()
{
    //Declares a double variable for lenght, width, thickness, volume and 
    //shipping cost.
    double length, width, thickness, volume, ship_cost;
    
    //Declares a int variable for weight and distance
    int weight, distance;
    
    //Declares and intialized a string for the menu answer
    string answer = "y";
    
    //Declares a bool variable for if the flat shipping rates  occur
    bool is_flat; 

    //Sets the precision of the answer to 2 decimal places. 
    cout << fixed << showpoint << setprecision(2);
    
    //Creates a while loop for the menu, answer has to equal Y or y
    while (answer ==  "Y" || answer == "y")
    {
       
        //Output the title of the program
        cout << "Ship4Money Shipping Calculator" << endl;
        cout << setfill('-') << setw(40) << '-' << endl;

        //gets the weight from the get_weight function
        weight = get_weight();
       
        //if weight is greater than 80 then get size of package
        if (weight > 80)
        {
            get_size(length, width, thickness);
        }
        else
        {
            length = 0;
            width = 0;
            thickness = 0;
        }

        //Determines if the package qualifies for flat shipping
        is_flat = get_distance(distance);

        //calculates the volume of the package
        volume = length * width * thickness;

        //Gets the shipping cost from the cal_cost function
        ship_cost = cal_cost(volume, distance, weight);

        //outputs the shipping cost
        cout << "Cost to ship your package is $" << ship_cost << endl << endl;

        //Resets answer to 0
        answer = "0";

        //creates loop to validate if the continue menu has a correct answer
        while (answer != "Y" && answer != "y" && answer != "N" &&
           answer != "n")
       {
           cout << "Calculate another package? (Y/N): ";
           cin >> answer;
           cout << endl;
           
           //if the answer is no display thank you and terminate program.
           if (answer == "N" || answer == "n")
           {
               cout << "Thank you for using Ship4Money Shipping.";
               return 0;
           }
   
       }

        //adds extra space between loops
        cout << endl;

    }
    
    //program ran successful 
    return 0;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function asks the user for the distance of package in a whole number
   and returns a T or F if its a flat rate. Addition it return the distance 
   to the calling function. 

 * @param[out]    int& distance - distance in miles the package needs to go
 * @param[in]     none
 *
 * @returns is_flat if the package is going further than 500 miles
 *
 ****************************************************************************/

bool get_distance(int& distance)
{
    //Declares a bool variable for if the flat shipping rates  occur set to 
    //false
    bool is_flat = false;
    
    //set distance to 0
    distance = 0;

    //while distance is less than 0 ask for distance
    while (distance < 1)
    {

    cout << "Delivery distance (whole miles): ";
    cin >> distance;
    cout << endl;

    }
 
    //if distance is greater than 500 then set is_flat to true
    if (distance > 500)
    {
        is_flat = true;
    }

    //returns is_flat to calling function
    return is_flat;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * Calculates and returns the shipping cost of the package

 * @param[in]     double volume - volume of the package
 * @param[in]     int distance - distance to destination
 * @param[in]     int weight - weight of the package
 * @param[in]     bool is_flat - if the package qualifies for flat shipping
 *
 * @returns ship_cost. Cost of the shipping
 *
 ****************************************************************************/

double cal_cost(double volume, int distance, int weight)
{
    //Declares a variable for shipping cost
    double ship_cost;

    // if the distance is less than 100 miles
    if (distance < 100)
    {
        //and if the weight is greater than 5 pounts
        if (weight / 16 > 5)
        {
            //and if the volume is greater than 288 in^3
            if (volume > 288)
            {
                //shipping cost is weight time $1 + 10% surcharge
                ship_cost = ((weight/16.0) * 1.0) * 1.10;
            }
            //else the volume is less than 288 in^3
            else
            {
                //Shipping cost is weight time $1
                ship_cost = ((weight / 16.0) * 1.0);

            }
        }
        //else if the shipping weight is less than 5 pounds
        else
        {
            //Shipping cost is weight time $1
            ship_cost = ((weight / 16.0) * 1.0);
        }
    }
    //if the distance is between 100 and 500 miles
    else if (distance >= 100 && distance <= 500)
    {
        //and if the weight is greater than 5 pounts
        if ((weight/ 16.0) > 5)
        {
            //and if the volume is greater than 288 in^3 and less than 576in^3
            if (volume > 288 && volume < 576)
            {
                //shipping cost is weight time $1 + 15% surcharge
                ship_cost = ((weight / 16.0) * 1.5) * 1.15;
            }
            //and if the volume is greater than 576 in^3
            else if (volume >= 576)
            {
                //shipping cost is weight time $1 + 25% surcharge
                ship_cost = ((weight / 16.0) * 1.5) * 1.25;
            }
            //else the volume is less than 288 in^3
            else
            {
                //Shipping cost is weight time $1.50
                ship_cost = ((weight / 16.0) * 1.5);
            }
        }
        //else if the shipping weight is less than 5 pounds
        else
        {
            //Shipping cost is weight time $1.50
            ship_cost = ((weight / 16.0) * 1.5);
        }
    }
    else
    {

        ship_cost = 12250.00;
    }
   
    //returns shipping cost to calling function 
    return ship_cost;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function asks the user for the package weight and get the size of the
   package and returns the values back to main.

 * @param[in - out]     double length - length of the package
 * @param[in - out]     double width - width of the package
 * @param[in - out]     double thickness - thickness of the package

 * @returns weight.
 *
 ****************************************************************************/

int get_weight()
{
    //Declares and sets a variable called weight to  0
    int weight = 0;

    //Loop to ask for the weight of the package makes sure the weight is 
    //greater than 0
    while (weight < 1)
    {
        cout << "Enter package weight, in whole ounces: ";
        cin >> weight;
        cout << endl;
    }

   //returns the weight of the package
   return weight;
}

/** **************************************************************************
 * @author Raymond Daley
 *
 * @par Description:
 * This function ask the user for the length, width, thickness in inches and
 return the values to the calling function

 * @param[out]     double length - length of the package
 * @param[out]     double width - width of the package
 * @param[out]     double thickness - thickness of the package
 *
 * @returns none
 *
 ****************************************************************************/

void get_size(double& length, double& width, double& thickness)
{
    cout << "Enter package dimensions in inches" << endl << endl;
    
    //set all values to 0
    length = 0;
    width = 0;
    thickness = 0;

    //loop asking for length
    while (length < 1)
    {
        cout << "Length: ";
        cin >> length;
        cout << endl;
    }

    //loop asking for width
    while(width < 1)
    {
        cout << "Width: ";
        cin >> width;
        cout << endl;
    }

    //loop asking for thickness
    while (thickness < 1)
    {
        cout << "Thickness: ";
        cin >> thickness;
        cout << endl;
    }

}