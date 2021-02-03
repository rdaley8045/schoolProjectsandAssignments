#ifndef __EMPLOYEE__H__
#define __EMPLOYEE__H__
#include <string>
using std::string;

class employee
{
    public:
        employee( );
        employee( int theID, string fname, string lname, double theSalary,
                  double theBonus );
        ~employee( );

        bool setID(int newID);
        int getID();

        bool setFirstName(string newFirstName);
        string getFirstName();

        bool setLastName(string newLastName);
        string getLastName();

        bool setSalary(double newSalary);
        double getSalary();

        bool setBonus(double newBonus);
        double getBonus();

    private:
        int id;
        string firstName;
        string lastName;
        double salary;
        double bonus;
};

#endif

