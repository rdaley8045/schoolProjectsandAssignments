#include "employee.h"
employee::employee( )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;
}
employee::employee( int theID, string fname, string lname, double theSalary,
                    double theBonus )
{
    id = 0;
    firstName = "";
    lastName = "";
    salary = 0.0;
    bonus = 0.0;

    if( theID > 0 && theSalary >= 0.0 && theBonus >= 0.0 && 
        !fname.empty() && !lname.empty() )
    {
        id = theID;
        firstName = fname;
        lastName = lname;
        salary = theSalary;
        theBonus = theBonus;
    }
}
employee::~employee( )
{

}

bool employee::setID(int newID)
{
    if (newID > 0)
    {
        id = newID;
        return true;
    }
    else
        return false;   
}

int employee::getID()
{
    return id;
}

bool employee::setFirstName(string newFirstName)
{
    if (newFirstName != "")
    {
        firstName = newFirstName;
        return true;
    }
    else
        return false;
}
string employee::getFirstName()
{
    return firstName;
}

bool employee::setLastName(string newLastName)
{
    if (newLastName != "")
    {
        lastName = newLastName;
        return true;
    }
    else
        return false; 
}
string employee::getLastName()
{
    return lastName;
}

bool employee::setSalary(double newSalary)
{
    if (newSalary >= 0)
    {
        salary = newSalary;
        return true;
    }
    else
        return false; 
}
double employee::getSalary()
{
    return salary;
}

bool employee::setBonus(double newBonus)
{
    if (newBonus >= 0)
    {
        bonus = newBonus;
        return true;
    }
    else
        return false; 
}
double employee::getBonus()
{
    return bonus;
}
