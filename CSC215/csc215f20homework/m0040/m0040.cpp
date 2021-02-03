#include<cstring>
#include<string>
#include<iomanip>
#include<fstream>
#include<iostream>

using namespace std;

struct empData
{
    int id;
    char firstname[20];
    char lastname[40];
    double salary;
    double bonus;
};

void printFile(fstream& file);

bool applyBonus(fstream& file, int empID);

int main(int argc, char* argv[])
{
    fstream file;
    string empIDS;
    int empID;
    bool applied;

    cout.setf(ios::fixed | ios::showpoint);
    cout.precision(2);

    //checks to see if the file is has the correct number of command lines
    if (argc != 3)
    {
        cout << "Usage: m0040.exe binaryData employeeID" << endl;

        exit(0);
    }

    //opens the file
    file.open(argv[1], ios::in | ios::out | ios::ate | ios::binary);

    //checks if the file is open
    if (! file.is_open())
    {
        cout << "Unable to open binary file: " << argv[1] << endl;

        exit(0);
    }

    //converts cstring id to a C++ string
    empIDS.assign(argv[2]);

    //converts C++ string to int
    empID = stoi(empIDS);

    printFile(file);
    
    //applied = applyBonus(file, empID);

    if (applyBonus(file, empID))
        cout << endl<< "Employee ID " << empID << " has been updated." << endl;
    else
        cout << endl << "Employee ID " << empID << " was not found." << endl;

    cout << endl;

    printFile(file);

    //closes the file
    file.close();

    return 0;
}

void printFile(fstream& file)
{
    empData data;

    file.seekg(0, ios::beg);
    while (file.read((char*)&data, sizeof(data)))
    {
        cout << setw(7) << data.id << " " << left << setw(20) << data.firstname
            << setw(40) << data.lastname << right << " Salary: " << setw(10) <<
            data.salary << " Bonus: " << setw(10) << data.bonus << endl;
    }

    file.clear();
}

bool applyBonus(fstream& file, int empID)
{
    bool applied = false;
    empData data;
    unsigned int i = 0;


    file.seekg(0, ios::beg);
    while (file.read((char*)&data, sizeof(data)) && applied == false)
    {
        i++;

        if (data.id == empID)
        {
            i--;
            data.bonus += 500.00;
            file.seekp((i) * sizeof(data), ios::beg);
            file.write((char*) &data, sizeof(data));

            return true;

        }
        else
            applied = false;
     }

    file.clear();

    return applied;
}