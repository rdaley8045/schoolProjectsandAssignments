#include "enlisted.h"
#include "officer.h"

class personnel : public enlisted, public officer
{
public:

    personnel();
    ~personnel();

    bool find(int SSN);
    int size();
    bool empty();

    bool insert(string squadron, int SSN, string lastName, string firstName,
        string dateEnterService, string dateOfBirth, string rank,
        string jobCode, string supervisor, int ERPScore, bool commander, 
        bool OPRScore);

    bool remove(int SSN);

    void clear();

    void print(ostream& fout);




private:

    struct node
    {
        string squadron;
        string rank;
        int SSN;
        string lastName;
        string firstName;
        string dateEnterService;
        string dateOfBirth;
        node* next;
    };

    node* headptr;
};