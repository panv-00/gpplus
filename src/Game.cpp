#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

Point Game::get_free_location()
{
  Point point;
  int x, y;
  bool available = false;

  while (!available)
  {
    x = random_int_range(0, BOARD_WIDTH);
    y = random_int_range(0, BOARD_HEIGHT);
    available = true;

    // Loop through Agents, Foods, and walls
    for (size_t i = 0; i < agents_count; i++)
    {
      if (agents[i].get_pos_x() == x && agents[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }

    for (size_t i = 0; i < foods_count; i++)
    {
      if (foods[i].get_pos_x() == x && foods[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }

    for (size_t i = 0; i < walls_count; i++)
    {
      if (walls[i].get_pos_x() == x && walls[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }
  }

  point.x = x;
  point.y = y;

  return point;
}

void Game::init_game()
{
  Point point;

  // Init Agents
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    point = get_free_location();
    
    agents[i].set_pos_x(point.x);
    agents[i].set_pos_y(point.y);
    agents[i].set_dir((Dir) random_int_range(0, 4));
    agents_count++;
  }

  // Init Foods
  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    point = get_free_location();

    foods[i].set_pos_x(point.x);
    foods[i].set_pos_y(point.y);
    foods_count++;
  }

  // Init Walls
  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    point = get_free_location();

    walls[i].set_pos_x(point.x);
    walls[i].set_pos_y(point.y);
    walls_count++;
  }
}

void Game::step_game()
{
  // Do nothing for now
}

