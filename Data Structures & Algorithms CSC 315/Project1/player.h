
#ifndef __PLAYER_H
#define __PLAYER_H
#include <list>
#include "board.h"
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

class Player
{
   Board board;
public:
   Player ();
   ValidMove makeMove(const Board);
private:
   ValidMove bestMove(Board);


};

#endif