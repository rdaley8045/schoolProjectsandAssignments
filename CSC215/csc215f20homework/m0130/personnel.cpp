#include "personnel.h"

personnel::personnel()
{
    headptr = nullptr;
}

personnel::~personnel()
{
    clear();
}

bool personnel::empty()
{
    if (headptr == nullptr)
        return true;
    else
        return false;
}

int personnel::size()
{
    int count = 0;
    node* head = headptr;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

bool personnel::find(int SSN)
{
    node* head = headptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            if (enlistedFind(SSN))
                return true;
            else if (officerFind(SSN))
                return true;

        head = head->next;
    }

    return false;
}

void personnel::clear()
{
    node* head = headptr;

    while (headptr != nullptr)
    {
        headptr = headptr->next;
        if (head->rank.at(0) == 'E')
            enlistedClear();
        else
            officerClear();

        delete head;

        head = headptr;
    }
}

bool personnel::remove(int SSN)
{
    node* head, * curr, * prev;

    if (headptr == nullptr)
        return false;

    curr = headptr;

    if (curr->SSN == SSN)
    {
        head = headptr;
        headptr = head->next;
        if (curr->rank.at(0) == 'E')
            enlistedRemove(SSN);
        else
            officerRemove(SSN);
        delete head;
        return true;
    }

    curr = headptr;
    prev = headptr;

    while (curr != nullptr && curr->SSN != SSN)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
        return false;

    prev->next = curr->next;

    if (curr->rank.at(0) == 'E')
        enlistedRemove(SSN);
    else
        officerRemove(SSN);

    delete curr;

    return true;
}


bool personnel::insert(string squadron, int SSN, string lastName,
    string firstName, string dateEnterService, string dateOfBirth, string rank,
    string jobCode, string supervisor, int ERPScore, bool commander,
    bool OPRScore)
{
    node* temp, * curr, * prev;


    if (rank.at(0) == 'E')
        insertEnlisted(jobCode, supervisor, ERPScore, SSN);
    else
        insertOfficer(jobCode, supervisor, OPRScore, commander, SSN);

    temp = new(nothrow) node;

    if (temp == nullptr)
        return false;

    temp->squadron = squadron;
    temp->SSN = SSN;
    temp->lastName = lastName;
    temp->firstName = firstName;
    temp->dateEnterService = dateEnterService;
    temp->dateOfBirth = dateOfBirth;
    temp->rank = rank;
    temp->next = nullptr;


    if (headptr == nullptr)
    {
        headptr = temp;
        return true;
    }

    curr = headptr;
    if (curr->SSN < temp->SSN )
    {
        temp->next = headptr;
        headptr = temp;
        return true;
    }

    curr = headptr;
    prev = headptr;
    while (curr != nullptr && curr->SSN >= temp->SSN)
    {
        prev = curr;
        curr = curr->next;
    }

        prev->next = temp;
        temp->next = curr;


    return true;
}

void personnel::print(ostream& fout)
{
    node* curr, * prev;

    curr = headptr;
    prev = headptr;

    while (curr != nullptr)
    {
        fout << curr->SSN << "," << curr->rank << ",";
        fout << curr->lastName << "," << curr->firstName << ",";
        if (curr->rank.at(0) == 'E')
        {
            fout << getEJobCode(curr->SSN) << "," << getESupervisor(curr->SSN);
            fout << "," << getEPRScore(curr->SSN) << ", , ,";
        }
        else
        {
            fout << getOJobCode(curr->SSN) << "," << getOSupervisor(curr->SSN);
            if (getOPRScore(curr->SSN))
                fout << ", ," << "Pass" << ",";
            else
                fout << ", ," << "Fail" << ",";

            if (getCommander(curr->SSN))
                fout << "Commander" << ",";
            else
                fout << "Not Commander" << ",";
        }
        fout << curr->dateEnterService << "," << curr->dateOfBirth << ",";
        fout << curr->squadron << endl;

        prev = curr;
        curr = curr->next;
    }

}