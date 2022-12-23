#include "Game.h"

Game::Game()
{
  // DIR_RT
  points_dir[0].set_x(1); points_dir[0].set_y(0);

  // DIR_UP
  points_dir[0].set_x(0); points_dir[0].set_y(-1);
  
  // DIR_LT
  points_dir[0].set_x(-1); points_dir[0].set_y(0);

  // DIR_DN
  points_dir[0].set_x(0); points_dir[0].set_y(1);

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

  point.set_x(x);
  point.set_y(y);

  return point;
}

void Game::init_game()
{
  Point point;

  // Init Agents
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    point = get_free_location();
    
    agents[i].set_pos(point);
    agents[i].set_dir((Dir) random_int_range(0, 4));
    agents[i].set_hunger(100);
    agents[i].set_health(100);
    agents_count++;
  }

  // Init Foods
  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    point = get_free_location();

    foods[i].set_pos(point);
    foods_count++;
  }

  // Init Walls
  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    point = get_free_location();

    walls[i].set_pos(point);
    walls_count++;
  }
}

Point Game::point_infront_of_agent(Agent *agent)
{
  Point d = points_dir[agent->get_dir()];
  Point result = agent->get_pos();
  result.set_x(mod_int(result.get_x() + d.get_x(), BOARD_WIDTH));
  result.set_y(mod_int(result.get_y() + d.get_y(), BOARD_HEIGHT));

  return result;
}

Env Game::env_of_agent(size_t agent_index)
{
  Point infront = point_infront_of_agent(&agents[agent_index]);

  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    if (foods[i].get_pos_x() == infront.get_x() && foods[i].get_pos_y() == infront.get_y())
    {
      return ENV_FOOD;
    }
  }
  
  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    if (walls[i].get_pos_x() == infront.get_x() && walls[i].get_pos_y() == infront.get_y())
    {
      return ENV_WALL;
    }
  }

  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    if (agents[i].get_pos_x() == infront.get_x() && agents[i].get_pos_y() == infront.get_y())
    {
      return ENV_AGENT;
    }
  }

  return ENV_NOTHING;
}

void Game::perform_action(size_t agent_index, Action action)
{
  switch (action)
  {
    case ACTION_NOP:
      break;

    case ACTION_STEP:
      if (env_of_agent(agent_index) != ENV_WALL)
      {
        Point d = points_dir[agents[agent_index].get_dir()];
        agents[agent_index].set_pos_x(mod_int(agents[agent_index].get_pos_x() + d.get_x(), BOARD_WIDTH));
        agents[agent_index].set_pos_y(mod_int(agents[agent_index].get_pos_y() + d.get_y(), BOARD_HEIGHT));
      }
      break;

    case ACTION_EAT:
      if (env_of_agent(agent_index) == ENV_WALL)
      {
        // EAT IT
      }
      break;

    case ACTION_ATTACK:
      if (env_of_agent(agent_index) == ENV_AGENT)
      {
        // ATTACK IT
      }
      break;

    case ACTION_TURN_LT:
      break;

    case ACTION_TURN_RT:
      break;
  }
}

void Game::step_game()
{
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    for (size_t j = 0; j < GENES_COUNT; j++)
    {
      if (chromos[i].get_gene(j).get_state() == agents[i].get_state()
          && chromos[i].get_gene(j).get_env() == env_of_agent(i))        
      {
        perform_action(i, chromos[i].get_gene(j).get_action());
        agents[i].set_state(chromos[i].get_gene(j).get_next_state());
      }
    }
  }
}
