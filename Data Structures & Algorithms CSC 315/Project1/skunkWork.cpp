/***************************************************************************\\**
 * @file skunkWork.cpp
 ******************************************************************************/

#include <iostream>
#include "board.h"

using namespace std;

#include "player.h"

Player::Player() { }

/***************************************************************************\\**
 * @brief This function determines the number of moves into the future the board
 * will look at in making the move towards an ideal gamestate.
 *
 * @param[in] b - The board to copy when constructing the new board
 ******************************************************************************/


ValidMove Player::makeMove(const Board b)
{
   //Calls the bestMove generator
   return bestMove(b);
}

/***************************************************************************\\**
 * @brief This function applies the Monte Carlo Method to determine moves with 
 * the highest probability of creating ideal gamestates. 
 *
 * @param[in] b - The board to copy when constructing the new board
 ******************************************************************************/


ValidMove Player::bestMove(Board b)
{
   //Initial values for all 4 moves scores and count numbers and combined tile 
   //value
   int upMoveScore =0;
   int upMoveCount =0;
   int upTile =0;
  
   int downMoveScore = 0;
   int downMoveCount = 0;
   int downTile= 0;
   
   int leftMoveScore = 0;
   int leftMoveCount = 0;
   int leftTile = 0;
  
   int rightMoveScore = 0;
   int rightMoveCount = 0;
   int rightTile = 0;
   
   ValidMove moves [] = {UP, DOWN, LEFT, RIGHT};
   
   //The max score of all the games combined.
   int maxScore;

   //for loop that iterates through the all of the number of steps that are 
   //provided by the calling function. 
   for (int i = 0; i < 1000; i++)
   {
      //Copys the board
      Board board(b);
      //sets a counter to 0
      int count = 0;

      //Creates a variable called firstMove and sets it to UP
      ValidMove firstMove = UP;

      bool moveMade;

      //Until all the boards moves are made 
      while(!board.isGameOver() && count != 100)
      {

         //Randomly generate a move
         ValidMove move = moves[(rand()%4)];

         if(board.makeMove(move))
         {
            moveMade = true;
         }
         else
            moveMade = false;

         //If the move is valid and the count is 0 then increease move counter
         if (move == UP && moveMade && count ==0 )
         {
            upMoveCount ++;      
         }
         else if (move == DOWN && moveMade && count == 0)
         {
            downMoveCount ++;
         }     
         else if (move == LEFT && moveMade && count == 0)
         {
            leftMoveCount ++;
         }
         else if (move == RIGHT && moveMade && count == 0)
         {
            rightMoveCount ++;
         }

         //If the count is 0 then mark the first move
         if (count == 0)
            firstMove = move;

         
         //increas counter by 1
            count ++; 

      }

      //Bases on the First move get the score for that move.
      if (firstMove == UP)
      {
         upMoveScore += board.getScore();
         upTile += board.maxVal();
      }
      else if (firstMove == DOWN)
      {
         downMoveScore += board.getScore();
         downTile += board.maxVal();
      }
      else if (firstMove == LEFT)
      {
         leftMoveScore += board.getScore();
         leftTile += board.maxVal();
      }
      else if (firstMove == RIGHT)
      {
         rightMoveScore += board.getScore();
         rightTile += board.maxVal();
      }
   }


   //Based on the number of up moves average the first moves total  scores
   if (upMoveCount != 0)
   {
      upMoveScore = upMoveScore/upMoveCount;
      upTile = upTile/upMoveCount;
   }
   else
   { 
      upMoveScore =0;
      upTile = 0;
   }

   if (downMoveCount != 0)
   {
      downMoveScore = downMoveScore/downMoveCount;
     downTile = downTile/downMoveCount;
   }
   else
   {
      downMoveScore =0;
      downTile = 0;
   }

   if (leftMoveCount != 0)
   {
      leftMoveScore = leftMoveScore/leftMoveCount;
      leftTile = leftTile/leftMoveCount;
   }
   else 
   {
      leftMoveScore =0;
      leftTile = 0;
   }

   if (rightMoveCount != 0)
   {
      rightMoveScore = rightMoveScore/rightMoveCount;
      rightTile = rightTile/rightMoveCount;
   }

   else 
   {
      rightMoveScore =0;
      rightTile = 0;
   }

   //Find the max score of all the average scores
   maxScore = max(upMoveScore, max(downMoveScore,
      max(leftMoveScore, rightMoveScore)));

   //Finds the max tile score of all the possible tile moves.
   int maxTile = max(upTile, max(downTile,
      max(leftTile, rightTile)));

   if (maxScore == upMoveScore && maxTile == upTile)
   {
      return UP;
   }
   else if (maxScore == downMoveScore && maxTile == downTile)
   {
      return DOWN;
   }
   else if (maxScore == leftMoveScore && maxTile == leftTile)
   {
      return LEFT;
   }
   else if (maxScore == rightMoveScore && maxTile == rightTile)
   {
      return RIGHT;
   }
   else if (maxScore == upMoveScore)
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
