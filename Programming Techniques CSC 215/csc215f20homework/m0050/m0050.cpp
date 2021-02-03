
#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <algorithm>

using namespace std;


/**
 * @brief The 3 sort operations
 */
enum op {
    ID,      /**< Sort by ID         */
    NAME,    /**< Sort by Name     */
    SALARY     /**< Sort by Salary       */
};

//elements together.
/**
 * @brief Holds data about an the employee.
 */
struct employee
{
    int id;  /**< The employee ID */
    string firstName; /**< employee first name*/
    string lastName; /**< employee last name*/
    double salary; /**< employee salary*/
    double bonus; /**< employee bonus*/
    
};

//prototypes
int validCommand(int argc, char* argv[], op& type);

void errorCmdMessage(int errorCode);

void openFile(char* argv[], ifstream& fin, ofstream& fout);

void readFile(ifstream& fin, vector<employee>& data, string& header);

void writeFile(vector<employee>& data, string& header, ofstream& fout);

bool sortByName(employee lhs, employee rhs);

bool sortByID(employee lhs, employee rhs);

bool sortBySalary(employee lhs, employee rhs);




int main(int argc, char* argv[])
{
    int errorCode;
    op type;
    ifstream fin;
    ofstream fout;
    vector<employee> data;
    string header;

    

    //check command line
    errorCode = validCommand(argc, argv, type);

    if (errorCode == 2 || errorCode == 3)
    {
        errorCmdMessage(errorCode);
        exit(0);
    }

    //open files and check they are open
    openFile(argv, fin, fout);

    //read in data into vector
    readFile(fin, data, header);

    //sort data by id
    if (type == ID)
        sort(data.begin(), data.end(), sortByID);

    //sort data by name
    else if (type == NAME)
        sort(data.begin(), data.end(), sortByName);

    //sort data by salary
    else if (type == SALARY)
        sort(data.begin(), data.end(), sortBySalary);


    //write data
    writeFile(data, header, fout);

    //close files
    fin.close();
    fout.close();
    return 0;
}

int validCommand(int argc, char* argv[], op& type)
{
    string sargv;

    //if not 4 command lines argument then return code 2
    if (argc != 4)
        return 2;

    sargv = argv[3];

    //loop for -i, -n , -s if found then set op type return code 1, else code 3
    if ((sargv) == "-i")
        type = ID;

    else if ((sargv) == "-n")
        type = NAME;

    else if ((sargv) == "-s")
        type = SALARY;

    else
        return 3;

    return 1;


}

void errorCmdMessage(int errorCode)
{
   //if error code equals 2 then output usage statment
    if (errorCode == 2)
    {
        cout << "Usage: m0050.exe inputCSVFile outputCSVFILE sortMethod";
        cout << endl;

    }

    //if error code is 3 then out put sort method statement
    else if (errorCode == 3)
    {
        cout << "Invalid Sort Method:" << endl << "-i - sort by id";
        cout << endl << "-n - sort by name" << endl;
        cout << "-s - sort by salary" << endl;
    }
}

void openFile(char* argv[], ifstream& fin, ofstream& fout)
{
    //open input file
    fin.open(argv[1]);

    //if input file not open then output error message
    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << string(argv[1]) << endl;

        exit(0);
    }

    //open output file
    fout.open(argv[2]);

    //if output file is not open then output error message
    if (!fout.is_open())
    {
        cout << "Unable to open output file: " << string(argv[2]) << endl;

        exit(0);
    }
}

void readFile(ifstream& fin, vector<employee> &data, string& header)
{   

    employee getData;

    fin >> header;
    fin.ignore();

    while (fin >> getData.id)
    {
        fin.ignore();
        getline(fin,getData.firstName,',');
        getline(fin, getData.lastName, ',');
        fin >> getData.salary;
        fin.ignore();
        fin >> getData.bonus;

        data.push_back(getData);
    }
}

void writeFile(vector<employee>& data, string& header, ofstream &fout)
{
    int i;

    fout << header << endl;

    fout<<setprecision(2)<<fixed<<showpoint;

    for (i = 0; i < data.size(); i++)
    {
        fout << data[i].id << "," << data[i].firstName << ",";
        fout << data[i].lastName << "," << data[i].salary << ",";
        fout << data[i].bonus << endl;
    }
}

bool sortByName(employee lhs, employee rhs)
{

    if (lhs.lastName > rhs.lastName)
        return false;

    else if (lhs.lastName == rhs.lastName)
    {
        if (lhs.firstName > rhs.firstName)
            return false;
        else
            return true;
    }
    else
        return true;

}

bool sortByID(employee lhs, employee rhs)
{

    if (lhs.id > rhs.id)
        return false;
    else
        return true;
}

bool sortBySalary(employee lhs, employee rhs)
{
    if (lhs.salary > rhs.salary)
        return false;
    else
        return true;
}
