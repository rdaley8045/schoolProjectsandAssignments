#include"disjoint.h"

Disjoint :: Disjoint(int n)
{
    for (int i = 0; i < n; i++)
    {
        sets.push_back(-1);
    }
    
    numberOfSets = n;
}

int Disjoint :: Find(int item)
{
    if (sets[item] <0)
        return item;
    else
        return Find(sets[item]);
}

void Disjoint :: Union (int root1, int root2)
{
    int firstNumber = Find (root1);
    int secondNumber = Find (root2);

    if ( sets[secondNumber] < sets[firstNumber])
    {
        --sets[firstNumber];
        sets[secondNumber] = firstNumber;
    }
    else
    {
        --sets[firstNumber] = secondNumber;
    }

    numberOfSets --;
}

int  Disjoint :: setCount() const
{
    return numberOfSets;
}