#include "trim.h"

void cTrim(char theString[], trimType type)
{
    int i = 0;
    size_t  len, j;
    
    if (type == FRONT || type == BOTH)
    {
        while (isspace(theString[i]))
        {
            i++;
        }
        strcpy(theString, &theString[i]);
    }

    if (type == END || type == BOTH)
    {
        len = strlen(theString);
        j = len - 1;
        while (isspace(theString[j]))
        {
            j--;
        }
        j += 1;

        strcpy(&theString[j], "\0");
    }


   
}

void sTrim(string& theString, trimType type)
{
    int i=0;
    string::iterator it;

    if (type == FRONT || type == BOTH)
    {
        it = theString.begin();

        while (it != theString.end() && isspace(*it))
        {
            it++;
        }
        theString.assign(it, theString.end());
    }

    if (type == END || type == BOTH)
    {
        it = theString.end();
        if (theString.end() != theString.begin())
        {
            it--;

            while (it != theString.begin() && isspace(*it))
            {
                it--;
            }
           // if (isspace(*it))
             //   theString.erase(it, theString.end());
           // else

                theString.erase(it + 1, theString.end());
        }

    }
}