#include <string>
#include <algorithm>
#include <iomanip>
#include "m0070.h"

using namespace std;

int main(int argc, char **argv)
 {
    ifstream fin;
    ofstream fout;
    string method;
    string headers;
    employee empD;
    vector<employee> allEmp;
    vector<employee>::iterator it;

    checkArguments( argc, argv );

    openFiles( fin, fout, argv );

    // read in the data
    getline(fin, headers);
    while (inputEmployee( fin, empD) )
    {
        allEmp.push_back(empD);
    }

    
    method = argv[3];
    if( method == "-i" )
        sort(allEmp.begin(), allEmp.end(), compareID);
    else if (method == "-n")
        sort(allEmp.begin(), allEmp.end(), compareName);
    else if( method == "-s" )
        sort(allEmp.begin(), allEmp.end(), compareSalary);


    fout << fixed << showpoint << setprecision( 2 );
    fout << headers << endl;
    for( it = allEmp.begin( ); it != allEmp.end( ); it++ )
    {
        outputEmployee( fout, it );
    }
        
    fin.close();
    fout.close();
    return 0;
}

void checkArguments( int argc, char **argv )
{
    string method;
    if (argc != 4)
    {
        cout << "Usage: m0070.exe inputCSVFile outputCSVFILE sortMethod" 
             << endl;
        exit( 0 );
    }

    method = argv[3];
    if (method != "-n" && method != "-s" && method != "-i")
    {
        cout << "Invalid Sort Method:" << endl;
        cout << "-i - sort by id" << endl;
        cout << "-n - sort by name" << endl;
        cout << "-s - sort by salary" << endl;
        exit( 0 );
    }
}
void openFiles( ifstream &fin, ofstream &fout, char **argv )
{
    fin.open(argv[1]);
    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << argv[1] << endl;
        exit( 0 );
    }


    fout.open(argv[2]);
    if (!fout.is_open())
    {
        fin.close();
        cout << "Unable to open output file: " << argv[2] << endl;
        exit( 0 );
    }
}


bool inputEmployee(istream &in, employee &anEmployee)
{
    int id;
    string fname, lname;
    double annualSalary, yearlyBonus;
    if( in >> id )
    {
        in.ignore( );
        getline( in, fname, ',' );
        getline( in, lname, ',' );
        in >> annualSalary;
        in.ignore( );
        in >> yearlyBonus;

        // insert your member function calls to fill the employee object or
        // change the data with the object
        anEmployee.setID(id);
        anEmployee.setFirstName(fname);
        anEmployee.setLastName(lname);
        anEmployee.setSalary(annualSalary);
        anEmployee.setBonus(yearlyBonus);

        return true;
    }


    return false;
}
void outputEmployee( ofstream &out, vector<employee>::iterator it )
{
    // output a single employee's data with an endline
    out << it->getID() <<"," << it->getFirstName() <<",";
    out << it->getLastName() << "," << it->getSalary() << ",";
    out << it->getBonus() << endl;

}

bool compareID( employee &lhs,  employee &rhs)
{
    
    if (lhs.getID() > rhs.getID())
    {
        return false;
    }
    else
        return true;
}

bool compareName( employee &lhs,  employee &rhs)
{
    if (lhs.getLastName() > rhs.getLastName())
        return false;

    else if (lhs.getLastName() == rhs.getLastName())
    {
        if (lhs.getFirstName() > rhs.getFirstName())
            return false;
        else
            return true;
    }
    else
        return true;
}

bool compareSalary( employee &lhs,  employee &rhs)
{
    if (lhs.getSalary() < rhs.getSalary())
        return false;
    else
        return true;
}