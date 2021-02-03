#include <iostream>
#include <string>
using namespace std;

class officer
{
public:

    officer();
    ~officer();

    int officerSize();
    bool officerEmpty();

    bool insertOfficer(string jobCode, string supervisor,
        bool OPRScore, bool commander, int SSN);

    bool officerRemove(int SSN);
    void officerClear();

    bool officerFind(int SSN);

    string getOJobCode(int SSN);
    string getOSupervisor(int SSN);
    bool getOPRScore(int SSN);
    bool getCommander(int SSN);



private:

    struct node
    {
        string jobCode;
        string supervisor;
        bool performanceReport;
        bool commander;
        int SSN;
        node* next;
    };

    node* oheadptr;
};

