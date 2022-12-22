#ifndef GUI_H
#define GUI_H

#include <stdio.h>

#include <SDL.h>

#include "style.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 10

#define CELL_WIDTH ((float) SCREEN_WIDTH / BOARD_WIDTH)
#define CELL_HEIGHT ((float) SCREEN_HEIGHT / BOARD_HEIGHT)


class Gui
{
public:
  Gui();
  ~Gui();

  int Run();

protected:

private:
  int scc(int code);

  void sdl_set_color_hex(Uint32 hex);
  void render_grid();


  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
};

#endif
