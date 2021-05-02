#ifndef __PLAYER_H
#define __PLAYER_H
#include <list>
#include <queue>
#include <map>
#include <limits>
#include "playfield.h"
#include "snakeGraph.h"
#include "bfsPaths.h"
#include "defines.h"
#include "dfsPaths.h"


class Player
{
   int v;

   std::list <int> DFSPath;
   std::list <int> BFSPath;
   int currentScore;
   int prevScore = 0;
   bool DFSHasPath,BFSHasPath;
   int height, width;
   int numPasses = 0;
   bool coil = false;
   bool DFSTrap, BFSTrap;

public:
   Player ();
   ValidMove makeMove(const Playfield *);
private:
   ValidMove processMove(int,std::pair<int, int>, std::vector<std::vector<int>>);
   std::vector<std::vector<int>> addPadding(std::vector<std::vector<int>>, 
   std::pair<int, int> , std::pair<int, int>);
   bool isTrapped (std::vector<std::vector<int>>, std::list <int>);
};
#endif
