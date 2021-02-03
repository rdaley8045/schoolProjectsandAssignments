#include <iostream>
#include <string>

using namespace std;



class enlisted
{
public:

    enlisted();
    ~enlisted();

    int enlistedSize();
    bool enlistedEmpty();

    bool insertEnlisted(string jobCode, string supervisor,
        int EPRScore, int SSN);

    bool enlistedRemove(int SSN);
    void enlistedClear();

    bool enlistedFind(int SSN);

    string getEJobCode(int SSN);
    string getESupervisor(int SSN);
    int getEPRScore(int SSN);


private:

    struct node
    {
        int SSN;
        string jobCode;
        string supervisor;
        int performanceReport;
        node* next;
    };

    node* eheadptr;
};