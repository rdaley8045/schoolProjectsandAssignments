#ifndef MAXSTACK_H
#define MAXSTACK_H
#include <iostream>
// might need additional #include statements here

using namespace std;

class MaxStack
{
   int capacity;
   int stacksize;
   // You'll probably need some container here to store the items on the
   // stack


public:
   MaxStack(int cap = 10);
   ~MaxStack();

   bool empty();
   int size();
   int top();
   void push(int);
   void pop();
   int max();
   friend ostream& operator<<(ostream &, const MaxStack &);

private:
   struct node
   {
       int inputedNumber;
       int maxNumber;
       node* next;

       node(int i, int m, node* n=nullptr):inputedNumber(i),maxNumber(m),
         next(n){}
   };

   node* headptr;

   void print();
   
};
#endif