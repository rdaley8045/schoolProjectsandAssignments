#ifndef __DFSPATHS_H
#define __DFSPATHS_H
#include <list>
#include <map>
#include <vector>
#include "snakeGraph.h"

class DFSPaths
{
   std::map<int, bool> marked;
   std::map<int, int> prev;
   int s;

public:
   DFSPaths(SnakeGraph *G, int s);

   bool hasPath(int v);
   std::list<int> pathTo(int v);

private:
   void dfs(SnakeGraph *, int);
};
#endif
