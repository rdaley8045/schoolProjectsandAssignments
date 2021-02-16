#include "util.h"

void keyboard(unsigned char key, int x, int y)
{
   utilityCentral(new KeyboardEvent(key, x, y));
}

void display()
{
   glClear(GL_COLOR_BUFFER_BIT);
   utilityCentral(new DisplayEvent); 
   glutSwapBuffers();
}

void reshape(int w, int h)
{
   glLoadIdentity();           // initialize transformation matrix
   gluOrtho2D(0.0,w,0.0,h);
   glViewport(0,0,w,h);        // adjust viewport to new window
   glutPostRedisplay();
   utilityCentral(new ReshapeEvent(w, h));
}

void ticktock(int value)
{
   utilityCentral(new TickTockEvent);
   glutTimerFunc(value, ticktock, value);
}

void cleanUpAndCloseDown(Game *game)
{
   std::cout << "Final Score: " << game->getScore() << std::endl;
   delete game;
   glutLeaveMainLoop();
} 

void updateScore(Game *game)
{
   stringstream ss;
   ss << "Score = " << game->getScore();
   glutSetWindowTitle(ss.str().c_str());
}

void utilityCentral(Event *event)
{
   static Player *player = new Player();
   static Game *game = new Game(player);

   if (game->isGameOver()) 
   {
      std::cout << "GAME OVER!" << std::endl ; 
      cleanUpAndCloseDown(game);
   }
   else
   {
      event->doAction(game);
      updateScore(game);
   }
   delete event;
}
