#ifndef GUI_H
#define GUI_H

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "definitions.h"
#include "Game.h"

class Gui
{
public:
  Gui();
 ~Gui();

  void redraw();
  void print_agent_at(int x, int y);
  int  run();

protected:

private:
  Game  *game;

  int   scc(int code);
  void  render_grid();
  void  render_agent(Agent *agent);
  void  render_game();
  
  float agents_dir[DIR_COUNT][6] =  
  {
    // DIR_RT
    {0.0, 0.0, 1.0, 0.5, 0.0, 1.0},

    // DIR_UP
    {0.0, 1.0, 0.5, 0.0, 1.0, 1.0},
  
    // DIR_LT
    {1.0, 0.0, 1.0, 1.0, 0.0, 0.5},

    // DIR_DN
    {0.0, 0.0, 1.0, 0.0, 0.5, 1.0}
  };

  SDL_Window   *window   = NULL;
  SDL_Renderer *renderer = NULL;
};

#endif
