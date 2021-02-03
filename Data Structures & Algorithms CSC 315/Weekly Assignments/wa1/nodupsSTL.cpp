#include <iostream>
#include <vector>

using namespace std; 

int main()
{
    vector <int> listOfNumbers;
    vector <int> :: iterator it;
    int number, i;

    while (cin>>number)
    {
        if(listOfNumbers.size()>0)
        {
            for(i=0; i< listOfNumbers.size(); i++)
            {
                if(number != listOfNumbers.at(i) && 
                    (listOfNumbers.size()-1) ==i)
                    listOfNumbers.push_back(number);
                else if (number == listOfNumbers.at(i))
                    i = listOfNumbers.size();   
            }
        }
        else
            listOfNumbers.push_back(number);
    }

    for (it=listOfNumbers.begin(); it != listOfNumbers.end(); it++)
    {
        cout << *it << endl;
    }


    return 0;
}