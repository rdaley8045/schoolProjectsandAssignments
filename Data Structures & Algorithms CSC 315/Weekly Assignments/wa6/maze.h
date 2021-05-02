/********************************************************************//**
 * @file
 ***********************************************************************/
#ifndef MAZE_H
#define MAZE_H
#include <vector>
#include <utility>           // For pair, make_pair
#include <ctime>
#include <cstdlib>
#include <list>
#include "disjoint.h"

/********************************************************************//**
 * @class Maze
 **********************************************************************/
class Maze
{
   std::vector<std::pair<int,int>> edges;
   int Cols, Rows;
   Disjoint *ds;
public:
   Maze(int, int);
   ~Maze();

   std::vector<std::pair<int, int>> edgeList();
   // removeEdge returns true as long as it's able to remove an edge
   // if an edge is removed, it will be the first (and maybe the only) edge in the list
   // of pairs passed as an output parameter.  All other edges in the list were edges
   // that were tested but not removed
   bool removeEdge(list<pair<int, int>> &);
};
#endif
