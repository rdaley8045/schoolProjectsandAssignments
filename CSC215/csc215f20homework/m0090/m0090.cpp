#include<vector>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include <algorithm>
#include<list>
#include<string>

using namespace std;

enum op {
    NAME, IP, ROOM
};

struct IPAddress
{
    unsigned int Address;
    int roomNumber;
    string computerName;
    string IP;
};

int validCommand(int argc, char* argv[], op& type);
void errorCmdMessage(int errorCode);
void openFile(char* argv[], ifstream& fin, ofstream& fout);
void readFile(ifstream& fin, list<IPAddress>& data, string& header);
unsigned int compressOctets(string& ip);
bool sortByIP(IPAddress lhs, IPAddress rhs);
bool sortByRoom(IPAddress lhs, IPAddress rhs);
bool sortyByName(IPAddress lhs, IPAddress rhs);
void writeFile(list<IPAddress>& data, ofstream& fout, op type);

int main(int argc, char* argv[])
{
    int errorCode;
    op type;
    ifstream fin;
    ofstream fout;
    list<IPAddress> data;
    string header;


    errorCode = validCommand(argc, argv, type);

    if (errorCode == 2 || errorCode == 3)
    {
        errorCmdMessage(errorCode);
        exit(0);
    }

    openFile(argv, fin, fout);

    readFile(fin, data, header);

    if (type == IP)
        data.sort(sortByIP);

    else if (type == NAME)
        data.sort(sortyByName);

    else if (type == ROOM)
        data.sort(sortByRoom);

    writeFile(data, fout, type);

    fin.close();
    fout.close();

    return 0;    
}


int validCommand(int argc, char* argv[], op& type)
{
    string sargv;

    if (argc != 4)
        return 2;

    sargv = argv[3];

    if ((sargv) == "-i")
        type = IP;

    else if ((sargv) == "-n")
        type = NAME;

    else if ((sargv) == "-r")
        type = ROOM;

    else
        return 3;

    return 1;
}

void errorCmdMessage(int errorCode)
{
    if (errorCode == 2)
    {
        cout << "Usage: m0090.exe inputCSVFile outputCSVFILE sortMethod";
        cout << endl;

    }

    else if (errorCode == 3)
    {
        cout << "Invalid Sort Method:" << endl << "-i - sort by IP";
        cout << endl << "-n - sort by name" << endl;
        cout << "-r - sort by room" << endl;
    }
}

void openFile(char* argv[], ifstream& fin, ofstream& fout)
{
    fin.open(argv[1]);

    if (!fin.is_open())
    {
        cout << "Unable to open input file: " << string(argv[1]) << endl;

        exit(0);
    }

    fout.open(argv[2]);

    if (!fout.is_open())
    {
        cout << "Unable to open output file: " << string(argv[2]) << endl;

        exit(0);
    }
}

void readFile(ifstream& fin, list<IPAddress>& data, string& header)
{

    IPAddress getData;
    int room;
    string computerName, ipAddress;

    getline(fin, header);

    while (fin >> room)
    {
        fin.ignore();
        getline(fin, ipAddress, ',');
        getline(fin, computerName, '\n');

        getData.IP = ipAddress;
        getData.Address = compressOctets(ipAddress);
        getData.roomNumber = room;
        getData.computerName = computerName;

        data.push_back(getData);
    }

    
}


unsigned int compressOctets(string& ip)
{
    unsigned int oct[4];
    int j;
    string scot[4];
    size_t octet, position;
    unsigned int address;

    position = 0;
    octet = 0;

    j = 0;
    scot[j] = ip;
    octet = scot[j].find_first_of(".");

    for (j = 0; j < 4; j++)
    {
        scot[j] = ip;
        oct[j] = stoi(scot[j].substr(position, octet));
        position = octet + 1;
        octet = scot[j].find_first_of(".", position);
    }

    for (j = 0; j < 4; j++)
    {
        if (j == 0)
            address = oct[j];

        address = address << 8;

        address = address | oct[j];

    }

    return address;
}

bool sortByIP(IPAddress lhs, IPAddress rhs)
{
    if (lhs.Address > rhs.Address)
        return false;
    else
        return true;
}

bool sortByRoom(IPAddress lhs, IPAddress rhs)
{
    if (lhs.roomNumber >= rhs.roomNumber)
        return false;
    else
        return true;
}

bool sortyByName(IPAddress lhs, IPAddress rhs)
{
    if (lhs.computerName > rhs.computerName)
        return false;
    else
        return true;
}

void writeFile(list<IPAddress> &data, ofstream &fout, op type)
{
    list<IPAddress>::iterator it;

    if (type == NAME)
    {
        fout << "Computer Name, IP Address, Room Number" << endl;

        for (it = data.begin(); it != data.end(); it++)
        {
            fout << it->computerName << "," << it->IP << "," << it->roomNumber;
            fout << endl;
        }
    }
    else if (type == IP)
    {
        fout << "IP Address, Computer Name, Room Number" << endl;
        
        for(it = data.begin(); it!=data.end(); it++)
        {
            fout << it->IP << "," << it->computerName << "," << it->roomNumber;
            fout << endl;
        }
    }
    else if (type == ROOM)
    {
        fout << "Room Number, IP Address, Computer Name" << endl;

        for (it = data.begin(); it != data.end(); it++)
        {
            fout << it->roomNumber << "," << it->IP << "," << it->computerName;
            fout << endl;
        }
    }
}