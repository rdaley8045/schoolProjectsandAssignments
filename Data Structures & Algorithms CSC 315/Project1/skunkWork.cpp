#include <iostream>
#include "board.h"

using namespace std;

#include "player.h"

Player::Player() { }

ValidMove Player::makeMove(const Board b)
{

   int steps = 1000;

   return bestMove(b, steps);
}

ValidMove Player::bestMove(Board b, int steps)
{
   int upMoveScore =0;
   int upMoveCount =0;

   int downMoveScore = 0;
   int downMoveCount = 0;

   int leftMoveScore = 0;
   int leftMoveCount = 0;

   int rightMoveScore = 0;
   int rightMoveCount = 0;
   
   int maxScore;

   for (int i = 0; i < steps; i++)
   {
      Board board(b);
      int count = 0;
      ValidMove firstMove = UP;
      bool moveMade = false;

      while(!board.isGameOver())
      {

         ValidMove move = ValidMove(rand()%5);

         if(board.makeMove(move))
            moveMade = true;
         else
            moveMade = false;

         if (move == UP && moveMade == true && count ==0 )
         {
            upMoveCount ++;
         }
         else if (move == DOWN&& moveMade == true && count == 0)
         {
            downMoveCount ++;

         }
         else if (move == LEFT&& moveMade == true && count == 0)
         {
            leftMoveCount ++;

         }
         else if (move == RIGHT&& moveMade == true && count == 0)
         {
            rightMoveCount ++;
         }


         if (count == 0)
            firstMove = move;

 
         count ++;
         
      }


      if (firstMove == UP)
      {
         upMoveScore += board.getScore();
      }
      else if (firstMove == DOWN)
      {
         downMoveScore += board.getScore();
      }
      else if (firstMove == LEFT)
      {
         leftMoveScore += board.getScore();
      }
      else if (firstMove == RIGHT)
      {
         rightMoveScore += board.getScore();
      }
   }

   if (upMoveCount != 0)
      upMoveScore = upMoveScore/upMoveCount;
   else 
      upMoveScore =0;

   if (downMoveCount != 0)
      downMoveScore = downMoveScore/downMoveCount;
   else 
      downMoveScore =0;

   if (leftMoveCount != 0)
      leftMoveScore = leftMoveScore/leftMoveCount;
   else 
      leftMoveScore =0;

   if (rightMoveCount != 0)
      rightMoveScore = rightMoveScore/rightMoveCount;
   else 
      rightMoveScore =0;

   maxScore = max(upMoveScore, max(downMoveScore, max(leftMoveScore, rightMoveScore)));

   if (maxScore == upMoveScore)
   {
      return UP;
   }
   else if (maxScore == downMoveScore)
   {
      return DOWN;
   }
   else if (maxScore == leftMoveScore)
   {
      return LEFT;
   }
      else if (maxScore == rightMoveScore)
   {
      return RIGHT;
   }

   return UP;
}
