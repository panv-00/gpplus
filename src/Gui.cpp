#include "Gui.h"

Gui::Gui()
{
  game = new Game();

  scc(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS));
  scc
  (
    SDL_CreateWindowAndRenderer
    (
      SCREEN_WIDTH,
      SCREEN_HEIGHT,
      0,
      &window,
      &renderer
    )
  );
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

void Gui::render_grid()
{
  SDL_SetRenderDrawColor(renderer, HEX_COLOR(GRID_COLOR));

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

void Gui::render_agent(Agent *agent)
{
  float x1 = agents_dir[agent->get_dir()][0] *
    (CELL_WIDTH - AGENT_PADDING * 2) +
    agent->get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  
  float y1 = agents_dir[agent->get_dir()][1] *
    (CELL_HEIGHT - AGENT_PADDING * 2) +
    agent->get_pos_y() * CELL_HEIGHT + AGENT_PADDING;
  
  float x2 = agents_dir[agent->get_dir()][2] *
    (CELL_WIDTH - AGENT_PADDING * 2) +
    agent->get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  
  float y2 = agents_dir[agent->get_dir()][3] *
    (CELL_HEIGHT - AGENT_PADDING * 2) +
    agent->get_pos_y() * CELL_HEIGHT + AGENT_PADDING;
  
  float x3 = agents_dir[agent->get_dir()][4] *
    (CELL_WIDTH - AGENT_PADDING * 2) +
    agent->get_pos_x() * CELL_WIDTH + AGENT_PADDING;
  
  float y3 = agents_dir[agent->get_dir()][5] *
    (CELL_HEIGHT - AGENT_PADDING * 2) +
    agent->get_pos_y() * CELL_HEIGHT + AGENT_PADDING;

  Uint32 color = agent->get_health() > 0 ? AGENT_COLOR : AGENT_DEAD_COLOR;

  filledTrigonRGBA(renderer, x1, y1, x2, y2, x3, y3, HEX_COLOR(color));
  aatrigonRGBA    (renderer, x1, y1, x2, y2, x3, y3, HEX_COLOR(color));
}

void Gui::render_game()
{
  Agent *agent;
  Food  *food;
  Wall  *wall;

  // Render Agents
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    agent = game->get_agent(i);
    render_agent(agent);
  }

  // Render Foods
  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    food = game->get_food(i);

    if (!food->get_eaten())
    {
      filledCircleRGBA
      (
        renderer,
        (int) floorf(food->get_pos_x() * CELL_WIDTH  + CELL_WIDTH  * 0.5f),
        (int) floorf(food->get_pos_y() * CELL_HEIGHT + CELL_HEIGHT * 0.5f),
        (int) floorf(fminf(CELL_WIDTH, CELL_HEIGHT) * 0.5f - FOOD_PADDING),
        HEX_COLOR(FOOD_COLOR)
      );
    }
  }

  // Render Walls
  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    wall = game->get_wall(i);

    SDL_Rect rect =
    {
      (int) floorf(wall->get_pos_x() * CELL_WIDTH  + WALL_PADDING),
      (int) floorf(wall->get_pos_y() * CELL_HEIGHT + WALL_PADDING),
      (int) floorf(CELL_WIDTH  - WALL_PADDING * 2),
      (int) floorf(CELL_HEIGHT - WALL_PADDING * 2)
    };
    
    SDL_SetRenderDrawColor(renderer, HEX_COLOR(WALL_COLOR));
    SDL_RenderFillRect    (renderer, &rect);
  }
}

void Gui::redraw()
{
  SDL_SetRenderDrawColor(renderer, HEX_COLOR(BACKGROUND_COLOR));
  scc(SDL_RenderClear(renderer));
  render_grid();
  render_game();
  SDL_RenderPresent(renderer);
}

void Gui::print_agent_at(int x, int y)
{
  int pos_x = (int) floorf(x / CELL_WIDTH );
  int pos_y = (int) floorf(y / CELL_HEIGHT);

  int index = game->agent_at(pos_x, pos_y);
  
  if (index >= 0)
  {
    printf("\n\nAgent # %3d:\n", index);
    game->get_agent(index)->print();
    game->get_chromo(index)->print();
  }
}

int Gui::run()
{
  game->init_game();

  redraw();
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

        case SDL_KEYDOWN:
          switch (event.key.keysym.sym)
          {
            case SDLK_q:
              quit = SDL_TRUE;
              break;

            case SDLK_SPACE:
              game->step_game();
              redraw();
              break;

            case SDLK_r:
              game->init_game();
              redraw();
              break;
          }
          break;

        case SDL_MOUSEBUTTONDOWN:
          print_agent_at(event.button.x, event.button.y);
          break;
      }
    }
  }

  return 0;
}
