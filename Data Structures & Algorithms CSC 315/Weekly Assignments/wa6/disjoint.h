/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef DISJOINT_H
#define DISJOINT_H
#include <vector>


using namespace std;

/********************************************************************//**
 * @class Disjoint
 **********************************************************************/
class Disjoint
{

   vector<int> sets;
   int numberOfSets;

public:
   Disjoint(int);

   int Find(int);
   void Union(int, int);
   int setCount() const;
};
#endif
