/********************************************************************//**
 * @file
 ***********************************************************************/
#include "player.h"

Player::Player() { }

// Simple snake driver which attempts to move the head in the general direction
// of the food.  It does not avoid its own tail or obstacles in the playfield
ValidMove Player::makeMove(const Playfield *pf)
{
   // Get the head, food and grid from the playfield
   std::pair<int, int> head = pf->headPosition();
   std::pair<int, int> food = pf->foodPosition();
   std::vector<std::vector<int>> grid = pf->getGrid();
   std::vector<std::vector<int>> paddedGrid = addPadding(grid, food, head);

   // find the node value of the head and the food.
   int start = head.first * grid[0].size() + head.second;
   int end = food.first*grid[0].size() + food.second;


   //get the height and width of the grid.
   height  = grid.size();
   width = grid[0].size();

   //get the current score of the scorce booard
   currentScore = pf->getScore();

   //if the current score is greater than prev score update tail position 
   //and update the number of Passes to 0 and the prev score.
   if (currentScore > prevScore)
   {
      prevScore = currentScore;
      numPasses = 0;  
   }

   if (coil || numPasses == 0 )
   {
      //Find a DFS path to the end of the trail
      DFSPaths dPaths(new SnakeGraph (paddedGrid), start);
      DFSPath = dPaths.pathTo(end);
      DFSHasPath = dPaths.hasPath(end);
      coil = false;
      DFSTrap = isTrapped(grid, DFSPath);
   }
   

   BFSPaths bPaths (new SnakeGraph (grid), start);
   BFSPath = bPaths.pathTo(end);
   BFSHasPath = bPaths.hasPath(end);
   BFSTrap = isTrapped(grid, BFSPath);

   numPasses ++;

   
   if(DFSHasPath && !DFSPath.empty() && !DFSTrap)
   {

      int pathID = DFSPath.front();DFSPath.pop_front();
      pathID = DFSPath.front();

      return processMove (pathID, head, grid);
   }

   else if (BFSHasPath && !BFSPath.empty() && !BFSTrap)
   {
      int pathID = BFSPath.front(); BFSPath.pop_front();
      pathID = BFSPath.front();
      
      coil = true;
      return processMove (pathID, head, grid);
   }
   else
   {          
      int xRightCounter = 0;
      int xLeftCounter = 0;
      int yDownCounter = 0;
      int yUpCounter = 0;
      std::pair <int,int> xincrease= std::pair<int,int>(head.first, head.second+1);
      std::pair <int,int> xdecrease= std::pair<int,int>(head.first, head.second-1);
      std::pair <int,int> yincrease= std::pair<int,int>(head.first+1, head.second);
      std::pair <int,int> ydecrease= std::pair<int,int>(head.first-1, head.second);

      for (int i = head.second+1; i < (int)grid[0].size(); i++)
         if (grid[head.first][i] == 0||grid[head.first][i] == 4)
            xRightCounter ++;
         else
            break;

      for (int i = head.second-1; i > 0; i--)
         if (grid[head.first][i] == 0||grid[head.first][i] == 4)
            xLeftCounter ++;
         else 
            break;

      for (int i = head.first+1; i < (int) grid.size(); i++)
         if (grid[i][head.second] == 0||grid[i][head.second] == 4)
            yDownCounter ++;
         else
            break;

      for (int i = head.first-1; i > 0; i--)
         if (grid[i][head.second] == 0||grid[i][head.second] == 4)
            yUpCounter ++;
         else
            break;

      if ((!OutOfBounds(yincrease) && (grid[head.first+1][head.second] == 0 || grid[head.first+1][head.second] == 4 ))||
         (!OutOfBounds(ydecrease)&&(grid[head.first-1][head.second] == 0||grid[head.first-1][head.second] == 4)))
      {
         if (yDownCounter >= 1 && yDownCounter > yUpCounter)        
            return DOWN;
         else
            return UP;
      }

      else if ((!OutOfBounds(xincrease) && (grid[head.first][head.second+1] == 0 ||  grid[head.first][head.second+1] == 4 ))||
         (!OutOfBounds(xdecrease) && (grid[head.first][head.second-1] == 0 || grid[head.first][head.second-1] == 4)))
      {
         if (xRightCounter >= 1 && xRightCounter > xLeftCounter)
            return RIGHT;
         else
            return LEFT;
      }
   }

               return NONE;
}


ValidMove Player::processMove(int pathID, std::pair<int, int> head, 
   std::vector<std::vector<int>> grid) 
{
   int nextX = pathID % grid[0].size();
   int nextY = pathID / grid[0].size();

   int dy = head.first - nextY;
   int dx = head.second - nextX;

   if (dx == 0) // in the correct column
   {
      if (dy > 0) // Above the food
         return UP;
      else
         return DOWN;
   }
   
   else // Not in the correct column
   { 
      if (dx > 0) // I'm to the right of the food
         return LEFT;
      else // I'm to the left of the food
         return RIGHT;
   }

}

std::vector<std::vector<int>> Player :: addPadding(std::vector<std::vector<int>>grid, 
   std::pair<int, int> food,   std::pair<int, int>head)
{
   if (head.first != 0 && food.first != 0)
   {
      for (int i = 0; i < (int)grid[0].size(); i++)
         grid[0][i] = TAIL_VALUE;
   }
   if (head.first != (int)grid.size()-1 && food.first != (int)grid.size()-1)
   {
      for (int i = 0; i <(int)grid[0].size(); i++)
         grid[grid.size()-1][i] = TAIL_VALUE;
   }
   if (head.second != 0 && food.second != 0)
   {
      for (int i = 0; i < (int)grid.size(); i++)
         grid[i][0] = TAIL_VALUE;
   }
   if (head.second != (int)grid[0].size()-1 && food.second != (int)grid[0].size()-1)
   {
      for (int i = 0; i < (int)grid.size(); i++)
         grid[i][grid[0].size()-1] = TAIL_VALUE;
   }

   return grid;
}


bool Player::isTrapped (std::vector<std::vector<int>>grid, std::list <int> path)
{  
int xRightCounter = 0;
int xLeftCounter = 0;
int yDownCounter = 0;
int yUpCounter = 0;

for (int node : path)
{
   int X = node % grid[0].size();
   int Y = node / grid[0].size();

   for (int i = X+1; i < (int)grid[0].size(); i++)
      if (grid[Y][i] == 0||grid[Y][i] == 4)
         xRightCounter ++;
      else
         break;

   for (int i = X-1; i > 0; i--)
      if (grid[Y][i] == 0||grid[Y][i] == 4)
         xLeftCounter ++;
      else 
         break;

   for (int i = Y+1; i < (int) grid.size(); i++)
      if (grid[i][X] == 0||grid[i][X] == 4)
         yDownCounter ++;
      else
         break;

   for (int i = Y-1; i > 0; i--)
      if (grid[i][X] == 0||grid[i][X] == 4)
         yUpCounter ++;
      else
         break;

   if (xRightCounter > 0 && xLeftCounter == 0 && yDownCounter == 0 && yUpCounter == 0)
      return true;
   else if (xRightCounter == 0 && xLeftCounter > 0 && yDownCounter == 0 && yUpCounter == 0)
      return true;
   else if (xRightCounter == 0 && xLeftCounter == 0 && yDownCounter > 0 && yUpCounter == 0)
      return true;  
   else if (xRightCounter == 0 && xLeftCounter == 0 && yDownCounter == 0 && yUpCounter > 0)   
      return true;
   else 
      return false;

}

return false;
}