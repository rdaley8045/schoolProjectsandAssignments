#include"personnel.h"
#include <fstream>

void errorCheck(int argc);
void openFile(ifstream& fin, ofstream& fout, char* argv[]);
bool readInput(ifstream& fin, personnel& airman);



int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;
    personnel airman;
    int count = 0;
    string header;

    errorCheck(argc);

    openFile(fin, fout, argv);

    getline(fin,header);

    while (readInput(fin, airman))
    {
        count++;
    }

    fout << "SSN,Rank,Last Name,First Name, AFCS, Supervisor,EPR Score,";
    fout << "OPR Score, Commander, Date Enter Service, Date of Birth,";
    fout << "Squadron" << endl;

    airman.print(fout);

    fin.close();
    fout.close();
    return 0;
}

void errorCheck(int argc)
{
    if (argc != 3)
    {
        cout << "Usage: m0130.exe inputFile.csv outputFile.csv";
        exit(0);
    }
}

void openFile(ifstream& fin, ofstream& fout, char* argv[])
{
    fin.open(argv[1]);

    if (!fin.is_open())
    {
        cout << "Input file failed to open " << argv[1] << endl; 
        exit(0);
    }
    
    fout.open(argv[2]);

    if (!fout.is_open())
    {
        cout << "Output file failed to open " << argv[2] << endl;
        exit(0);
    }
}

bool readInput(ifstream& fin, personnel& airman)
{
    string squadron, lastName, firstName, dateService, dateBirth, rank, jobCode,
        supervisor;
    int SSN, EPRScore;
    bool commander, OPRScore;
    bool inputed;
    char peek;

    peek = fin.peek();

    if (peek != ',')
    {
        getline(fin, squadron, ',');
        getline(fin, lastName, ',');
        getline(fin, firstName, ',');
        getline(fin, rank, ',');
        getline(fin, jobCode, ',');
        getline(fin, supervisor, ',');
        getline(fin, dateService, ',');
        getline(fin, dateBirth, ',');
        fin >> EPRScore;
        fin.ignore();
        fin >> commander;
        fin.ignore();
        fin >> OPRScore;
        fin.ignore();
        fin >> SSN;
        fin.ignore();


        inputed = airman.insert(squadron, SSN, lastName, firstName, dateService,
            dateBirth, rank, jobCode, supervisor, EPRScore, commander,
            OPRScore);
    }
    else
        return false;

    return inputed;
}