#include "Gui.h"

Gui::Gui()
{
  scc(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS));
  scc(SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer));
  sdl_set_color_hex(BACKGROUND_COLOR);
  scc(SDL_RenderClear(renderer));
  render_grid();
  SDL_RenderPresent(renderer);
}

Gui::~Gui()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int Gui::scc(int code)
{
  if (code < 0)
  {
    fprintf(stderr, "SDL Error: %s\n", SDL_GetError());
    exit(1);
  }

  return code;
}

void Gui::sdl_set_color_hex(Uint32 hex)
{
  scc
  (
    SDL_SetRenderDrawColor
    (
      renderer,
      (hex >> 24) & 0xff,
      (hex >> 16) & 0xff,
      (hex >> 8 ) & 0xff,
      (hex      ) & 0xff
    )
  );
}

void Gui::render_grid()
{
  sdl_set_color_hex(GRID_COLOR);

  for (int x = 1; x < BOARD_WIDTH; ++x)
  {
    scc
    (
      SDL_RenderDrawLine
      (
        renderer, 
        x * CELL_WIDTH,
        0,
        x * CELL_WIDTH,
        SCREEN_HEIGHT
      )
    );
  }

  for (int y = 1; y < BOARD_HEIGHT; ++y)
  {
    scc
    (
      SDL_RenderDrawLine
      (
        renderer, 
        0,
        y * CELL_HEIGHT,
        SCREEN_WIDTH,
        y * CELL_HEIGHT
      )
    );
  }
}

int Gui::Run()
{
  SDL_bool quit = SDL_FALSE;
  
  while (!quit)
  {
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
      switch (event.type)
      {
        case SDL_QUIT:
          quit = SDL_TRUE;
          break;
      }
    }
  }

  return 0;
}
