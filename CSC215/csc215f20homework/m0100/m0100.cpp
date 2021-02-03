#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;


enum trait {POTENCY, ESSENCE, ASPECT};

struct rune {
    string name;
    trait type;
};

string errorCheck(int argc, char* argv[]);
void openFiles(ifstream& fin, string inputFile);
int readRune(ifstream& fin, vector<rune> &runes);
bool sortByType(rune lhs, rune rhs);
void permut(vector<int>solution, vector<bool>used, int count, int pos, int k,
    vector<rune>runes);



int main(int argc, char* argv[])
{
    ifstream fin;
    string inputFile;
    vector<rune> runes;
    vector<int>solution;
    vector<bool> used;
    int count, pos = 0;
    int k = 3;
    int counter = 1;


    
    inputFile = errorCheck(argc, argv);
    openFiles(fin, inputFile);
    count = readRune(fin, runes);
    used.resize(count, false);
    solution.resize(count, 0);

    permut(solution, used, count, pos, k, runes);


    fin.close();
    return 0;
}

string errorCheck(int argc, char* argv[])
{
    string inputFile;
    
    if (argc != 2)
    {
        cout << "m0100.exe csvdatafile" << endl;
        exit(0);
    }

    return argv[1];

}

void openFiles(ifstream& fin, string inputFile)
{
    fin.open(inputFile.c_str());

    if (!fin.is_open())
    {
        cout << "Unable to open: " << inputFile << endl;
        exit(0);
    }
}

int readRune(ifstream& fin, vector<rune> &runes)
{
    int count = 0;
    rune temp;
    string runeTrait;
    getline(fin,temp.name);
    while (getline(fin, temp.name, ','))
    {
        getline(fin, runeTrait);

        if (runeTrait == "Potency")
        {
            temp.type = POTENCY;
        }
        else if (runeTrait == "Essence")
        {
            temp.type = ESSENCE;
        }
        else
            temp.type = ASPECT;

        runes.push_back(temp);

        count++;
    }

    return count;
}

bool sortByType(rune lhs, rune rhs)
{
    if (lhs.type > rhs.type)
        return false;

    else if (lhs.type == rhs.type)
    {
        if (lhs.name > rhs.name)
            return false;
        else
            return true;

    }
    else
        return true;

}

void permut(vector<int>solution, vector<bool>used, int count, int pos, int k,
    vector<rune>runes)
{
    int i;


    //base case
    if (pos == k)
    {
        if (runes.at(solution.at(0)).type == POTENCY && 
            runes.at(solution.at(1)).type == ESSENCE && 
            runes.at(solution.at(2)).type == ASPECT)
        {
            for (i = 0; i < k; i++)
            {
                cout << runes.at(solution.at(i)).name << " ";
            }
            cout << endl;
        }
        return;
    }

    //filling with all possibilities 
    for (i = 0; i < count; i++)
    {
        if (used.at(i) == false)
        {
            solution.at(pos)=i;
            used.at(i)=true;

            permut(solution, used, count, pos+1, k, runes);

            used.at(i) = false;

        }
    }

}