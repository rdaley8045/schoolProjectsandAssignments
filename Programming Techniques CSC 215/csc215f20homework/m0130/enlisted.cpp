#include "enlisted.h"

enlisted::enlisted()
{
    eheadptr = nullptr;
}

enlisted::~enlisted()
{
    enlistedClear();
}

void enlisted::enlistedClear()
{
    node* temp = eheadptr;

    while (eheadptr != nullptr)
    {
        eheadptr = eheadptr->next;
        delete temp;
        temp = eheadptr;
    }
}

int enlisted::enlistedSize()
{
    int count = 0;
    node* head = eheadptr;

    while (head != nullptr)
    {
        count++;
        head = head->next;
    }

    return count;
}

bool enlisted::enlistedEmpty()
{
    if (eheadptr == nullptr)
        return true;
    else
        return false;
}

bool enlisted::enlistedRemove(int SSN)
{
    node* head, * curr, * prev;

    if (eheadptr == nullptr)
        return false;

    curr = eheadptr;

    if (curr->SSN == SSN)
    {
        head = eheadptr;
        eheadptr = head->next;
        delete head;
        return true;
    }

    curr = eheadptr;
    prev = eheadptr;

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

bool enlisted::insertEnlisted(string jobCode, string supervisor,
    int EPRScore, int SSN)
{
    node* temp, * curr, * prev;

    temp = new(nothrow) node;

    if (temp == nullptr)
        return false;

    temp->jobCode = jobCode;
    temp->supervisor = supervisor;
    temp->performanceReport = EPRScore;
    temp->SSN = SSN;
    temp->next = nullptr;

    if (eheadptr == nullptr)
    {
        eheadptr = temp;
        return true;
    }

    curr = eheadptr;
    if (curr->SSN >= temp->SSN)
    {
        temp->next = eheadptr;
        eheadptr = temp;
        return true;
    }

    curr = eheadptr;
    prev = eheadptr;

    while (curr != nullptr && curr->SSN <= temp->SSN)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = temp;
    temp->next = curr;

    return true;
}

bool enlisted::enlistedFind(int SSN)
{
    node* head = eheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return true;

        head = head->next;
    }

    return false;
}

string enlisted::getEJobCode(int SSN)
{
    node* head = eheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->jobCode;

        head = head->next;
    }

    return "0";
}


string enlisted::getESupervisor(int SSN)
{
    node* head = eheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->supervisor;

        head = head->next;
    }

    return "0";
}

int enlisted::getEPRScore(int SSN)
{
    node* head = eheadptr;

    while (head != nullptr)
    {
        if (SSN == head->SSN)
            return head->performanceReport;

        head = head->next;
    }

    return  0;

}

