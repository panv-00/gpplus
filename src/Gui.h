#ifndef GUI_H
#define GUI_H

#include <stdio.h>

#include <SDL.h>
#include <SDL2_gfxPrimitives.h>

#include "Agent.h"
#include "definitions.h"

class Gui
{
public:
  Gui(Agent *agents);
  ~Gui();

  int Run();

protected:

private:
  int scc(int code);

  void sdl_set_color_hex(Uint32 hex);
  void render_grid();
  void render_agent(Agent agent);
  void render_all_agents(Agent *agents);

  float agents_dir[4][6] =  
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

  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
};

#endif
