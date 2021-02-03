#include "officer.h"

officer::officer()
{
    oheadptr = nullptr;
}

officer::~officer()
{
    officerClear();
}

void officer::officerClear()
{
    node* head = oheadptr;

    while (oheadptr != nullptr)
    {
        oheadptr = oheadptr->next;

        delete head;

        head = oheadptr;
    }
}

int officer::officerSize()
{
    int count = 0;
    node* head = oheadptr;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

bool officer::officerEmpty()
{
    if (oheadptr == nullptr)
        return true;
    else
        return false;
}

bool officer::officerRemove(int SSN)
{
    node* head, * curr, * prev;

    if (oheadptr == nullptr)
        return false;

    curr = oheadptr;

    if (curr->SSN == SSN)
    {
        head = oheadptr;
        oheadptr = head->next;
        delete head;
        return true;
    }

    curr = oheadptr;
    prev = oheadptr;

    while (curr != nullptr && SSN != curr->SSN)
    {
        prev = curr;
        curr = curr->next;
    }

    if (curr == nullptr)
        return false;

    prev->next = curr->next;
    delete curr;

    return true;
}


bool officer::insertOfficer(string jobCode, string supervisor,
    bool OPRScore, bool commander, int SSN)
{
    node* temp, * curr, * prev;

    temp = new(nothrow) node;

    if (temp == nullptr)
        return false;

    temp->jobCode = jobCode;
    temp->supervisor = supervisor;
    temp->performanceReport = OPRScore;
    temp->commander = commander;
    temp->SSN = SSN;
    temp->next = nullptr;

    if (oheadptr == nullptr)
    {
        oheadptr = temp;
        return true;
    }

    curr = oheadptr;
    if (curr->SSN < temp->SSN)
    {
        temp->next = oheadptr;
        oheadptr = temp;
        return true;
    }

    curr = oheadptr;
    prev = oheadptr;

    while (curr != nullptr && curr->SSN >= temp->SSN)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = temp;
    temp->next = curr;

    return true;
}


bool officer::officerFind(int SSN)
{
    node* head = oheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return true;

        head = head->next;
    }

    return "0";
}

string officer::getOJobCode(int SSN)
{
    node* head = oheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->jobCode;

        head = head->next;
    }
    return "0";
}
string officer::getOSupervisor(int SSN)
{
    node* head = oheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->supervisor;

        head = head->next;
    }
    return "0";
}
bool officer::getOPRScore(int SSN) 
{
    node* head = oheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->performanceReport;

        head = head->next;
    }
    return false;

}
bool officer::getCommander(int SSN)
{
    node* head = oheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->commander;

        head = head->next;
    }
    return false;

}