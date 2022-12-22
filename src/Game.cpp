#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

int Game::random_int_range(int low, int high)
{
  return rand() % (high - low) + low;
}

Dir Game::random_dir(void)
{
  return (Dir) random_int_range(0, 4);
}

Agent Game::random_agent(int index)
{
  bool available = false;
  int x, y;
  
  Agent agent;
  
  while (!available)
  {
    x = random_int_range(0, BOARD_WIDTH);
    y = random_int_range(0, BOARD_HEIGHT);
    available = true;

    for (int i = 0; i < index; i++)
    {
      if (agents[i].get_pos_x() == x && agents[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }
  }

  agent.set_pos_x(x);
  agent.set_pos_y(y);
  agent.set_dir(random_dir());

  return agent;
}

void Game::init_game()
{
  for (size_t i = 0; i < AGENTS_COUNT; ++i)
  {
    agents[i] = random_agent(i);
  }
}

void Game::step_game()
{
  // Do nothing for now
}

