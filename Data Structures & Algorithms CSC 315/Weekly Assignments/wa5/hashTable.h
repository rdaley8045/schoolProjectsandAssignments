/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <vector>
#include <utility>
#include <iostream>
#include <cmath>

using namespace std;

/********************************************************************//**
 * @class HashTable
 **********************************************************************/
class HashTable
{
   // You will need some private data members here

   struct node
   {
      string key;
      int value;
   };
   vector < vector < node > > table;
   int dummyValue =0;
   int numInList = 0;
   int capacity;
   double loadFactor = 0;
public:
   HashTable(int cap = 10);
   ~HashTable();

   void insert(string key, int value); 
   void remove(string key);
   int &operator[](string key);
   bool containsKey(string key) const;
   list<string> getKeys() const;
   int size() const;
   int size(int) const;
   size_t hashFn(string) const;
   int tableSize() const;

private:
   // You will likely also need some private member functions here as well

   void rehash();
};
#endif


