#define OLC_PGE_APPLICATION
#include <iostream>
#include "application.h"

using namespace std;

int main(int argc, char *argv[])
{
   Application demo;

   if (demo.Construct(900, 900, 1, 1))
      demo.Start();

   return 0;
}
