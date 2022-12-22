#include "Gui.h"

Gui::Gui()
{
  game = new Game();

  scc(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS));
  scc(SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &renderer));
}

Gui::~Gui()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  delete game;
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

void Gui::render_agent(Agent agent)
{
  float x1 = agents_dir[agent.get_dir()][0] * (CELL_WIDTH - AGENT_PADDING * 2) + agent.get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  float y1 = agents_dir[agent.get_dir()][1] * (CELL_HEIGHT - AGENT_PADDING * 2) + agent.get_pos_y() * CELL_HEIGHT + AGENT_PADDING;
  float x2 = agents_dir[agent.get_dir()][2] * (CELL_WIDTH - AGENT_PADDING * 2) + agent.get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  float y2 = agents_dir[agent.get_dir()][3] * (CELL_HEIGHT - AGENT_PADDING * 2) + agent.get_pos_y() * CELL_HEIGHT + AGENT_PADDING;
  float x3 = agents_dir[agent.get_dir()][4] * (CELL_WIDTH - AGENT_PADDING * 2) + agent.get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  float y3 = agents_dir[agent.get_dir()][5] * (CELL_HEIGHT - AGENT_PADDING * 2) + agent.get_pos_y() * CELL_HEIGHT + AGENT_PADDING;

  filledTrigonColor(renderer, x1, y1, x2, y2, x3, y3, AGENT_COLOR);
  aatrigonColor(renderer, x1, y1, x2, y2, x3, y3, AGENT_COLOR);

}

void Gui::render_game()
{
  for (size_t i = 0; i < AGENTS_COUNT; ++i)
  {
    render_agent(game->get_agent(i));
  }
}

int Gui::Run()
{
  game->init_agents();

  sdl_set_color_hex(BACKGROUND_COLOR);
  scc(SDL_RenderClear(renderer));
  render_grid();
  render_game();
  SDL_RenderPresent(renderer);

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
