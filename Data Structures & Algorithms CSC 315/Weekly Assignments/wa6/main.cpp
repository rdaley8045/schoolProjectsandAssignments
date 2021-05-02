#define OLC_PGE_APPLICATION
#include <iostream>
#include "application.h"

using namespace std;

int main(int argc, char *argv[])
{
   int N = 15;
   int delay = 0;
   if (argc != 1 && argc != 2 && argc != 3)
   {
      cout << "Usage: " << argv[0] << "[N] [delay]" << endl;
      cout << "optional: N = build an N x N maze (default 15)" << endl;
      cout << "optional: delay in milliseconds between animation steps" << endl;
   }
   else
   {
      if (argc > 1)
      {
         try
         {
            N = stoi(argv[1]);
         }
         catch (...)
         {
            cout << "Usage: " << argv[0] << "[N] [delay]" << endl;
            cout << "optional: N = build an N x N maze (default 15)" << endl;
            cout << "optional: delay in milliseconds between animation steps" << endl;
            return -1;
         }
      }
      if (argc > 2)
      {
         try
         {
            delay = stoi(argv[2]);
         }
         catch (...)
         {
            cout << "Usage: " << argv[0] << "[N] [delay]" << endl;
            cout << "optional: N = build an N x N maze (default 15)" << endl;
            cout << "optional: delay in milliseconds between animation steps" << endl;
         }
      }
      Application demo(N, N, delay);
      if (demo.Construct(500, 500, 1, 1))
         demo.Start();
   }
   return 0;
}
