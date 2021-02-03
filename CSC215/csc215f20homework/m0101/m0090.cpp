#include <iomanip>
#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;


void openFile(ifstream& fin, string inputFile);
void readWeapons(ifstream& fin, list<weapon>& weapons);


struct weapon
{
    int quanity;
    string weaponName;
    int weight;
    bool station3, station4, station5, station6, station7, station8;
    bool station9;
};

struct aircraft
{
    int id;
    int baseWeight = 24967;
    int maxWeight = 46476;
    int fuel = 11087;
    int gunAmmo = 1775;
    int total;
    string loaded1 = "AIM-9M x2";
    int weight1 = 448;
    string loaded2 = "AN/AAG-28 Litening";
    int weight2 = 661;
    string loaded3;
    int weight3;
    string loaded4;
    int weight4;
    string loaded5;
    int weight5;
    string loaded6;
    int weight6;
    string loaded7;
    int weight7;
    string loaded8;
    int weight8;
    string loaded9;
    int weight9;
    string loaded10 = "7 2.75' Hydra Laser Guided Rkts M282 MPP";
    int weight10 = 328;
    string loaded11 = "ALQ-184";
    int weight11= 474;
};

int main()
{
    int numOfACFT;
    ifstream fin;
    list<weapon> weapons;
    list<aircraft> acft;
    list<weapon>::iterator wit;
    aircraft jet;
    string header;
    string inputFile;
    int count=1;

    cout << "Enter in weapons file with .csv" << endl;
    cin >> inputFile;


    openFile(fin, inputFile);

    getline(fin, header);

    fin.ignore();

    readWeapons(fin, weapons);



    fin.close();

    return 0;
}


void openFile(ifstream& fin, string inputFile)
{
    fin.open(inputFile.c_str());

    if (!fin.is_open())
    {
        cout << "Input file failed to open " << inputFile << endl;
        exit(0);
    }
}

void readWeapons(ifstream& fin, list<weapon>& weapons)
{
    int quanity;
    string weaponName;
    int weight;
    bool station3, station4, station5, station6, station7, station8;
    bool station9;
    weapon currWeapons;

    while (fin >> quanity)
    {
        fin.ignore();
        getline(fin, weaponName, ',');
        fin >> weight;
        fin.ignore();
        fin >> station3;
        fin.ignore();
        fin >> station4;
        fin.ignore();
        fin >> station5;
        fin.ignore();
        fin >> station6;
        fin.ignore();
        fin >> station7;
        fin.ignore();
        fin >> station8;
        fin.ignore();
        fin >> station9;
        fin.ignore();
        
        currWeapons.quanity = quanity;
        currWeapons.weaponName = weaponName;
        currWeapons.station3 = station3;
        currWeapons.station4 = station4;
        currWeapons.station5 = station5;
        currWeapons.station6 = station6;
        currWeapons.station7 = station7;
        currWeapons.station8 = station8;
        currWeapons.station9 = station9;

        weapons.push_back(currWeapons);

    }
}

