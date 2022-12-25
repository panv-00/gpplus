#include "Game.h"

Game::Game()
{

}

Game::~Game()
{

}

Point Game::get_free_location()
{
  int x, y;
  bool available = false;

  while (!available)
  {
    x = random_int_range(0, BOARD_WIDTH);
    y = random_int_range(0, BOARD_HEIGHT);
    available = true;

    // Loop through Agents, Foods, and walls
    for (size_t i = 0; i < AGENTS_COUNT; i++)
    {
      if (agents[i].get_pos_x() == x && agents[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }

    for (size_t i = 0; i < FOODS_COUNT; i++)
    {
      if (foods[i].get_pos_x() == x && foods[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }

    for (size_t i = 0; i < WALLS_COUNT; i++)
    {
      if (walls[i].get_pos_x() == x && walls[i].get_pos_y() == y)
      {
        available = false;
        break;
      }
    }
  }

  return Point(x, y);
}

void Game::init_game()
{
  Gene *gene;

  srand(time(0));

  // Init Agents
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    agents[i].set_pos(get_free_location());
    agents[i].set_dir((Dir) random_int_range(0, 4));
    agents[i].set_hunger(100);
    agents[i].set_health(100);
    agents[i].set_lifetime(0);
   
    // Init Genes
    for (size_t j = 0; j < GENES_COUNT; j++)
    {
      gene = chromos[i].get_gene(j);

      gene->set_state((State) random_int_range(0, STATES_COUNT));
      gene->set_env((Env) random_int_range(0, ENV_COUNT));
      gene->set_action((Action) random_int_range(0, ACTION_COUNT));
      gene->set_next_state((State) random_int_range(0, STATES_COUNT));
    }
  }

  // Init Foods
  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    foods[i].set_pos(get_free_location());
  }

  // Init Walls
  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    walls[i].set_pos(get_free_location());
  }

}

int Game::agent_at(int pos_x, int pos_y)
{
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    if (agents[i].get_pos_x() == pos_x
        && agents[i].get_pos_y() == pos_y)
    {
      return i;
    }
  }
  
  return -1;
}

Point Game::point_infront_of_agent(Agent *agent)
{
  Point d = points_dir[agent->get_dir()];
  Point result(agent->get_pos()->get_x(), agent->get_pos()->get_y());

  result.set_x(mod_int(result.get_x() + d.get_x(), BOARD_WIDTH));
  result.set_y(mod_int(result.get_y() + d.get_y(), BOARD_HEIGHT));

  return result;
}

int Game::food_infront_of_agent(size_t agent_index)
{
  Point infront = point_infront_of_agent(&agents[agent_index]);

  for (size_t i = 0; i < FOODS_COUNT; i++)
  {
    if (!foods[i].get_eaten()
        && infront.get_x() == foods[i].get_pos_x()
        && infront.get_y() == foods[i].get_pos_y()) { return i; }
  }

  return -1;
}

int Game::agent_infront_of_agent(size_t agent_index)
{
  Point infront = point_infront_of_agent(&agents[agent_index]);
  
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    if (i != agent_index
        && agents[i].get_health() > 0
        && infront.get_x() == agents[i].get_pos_x()
        && infront.get_y() == agents[i].get_pos_y()) { return i; }
  }

  return -1;
}

int Game::wall_infront_of_agent(size_t agent_index)
{
  Point infront = point_infront_of_agent(&agents[agent_index]);

  for (size_t i = 0; i < WALLS_COUNT; i++)
  {
    if (infront.get_x() == walls[i].get_pos_x()
        && infront.get_y() == walls[i].get_pos_y()) { return i; }
  }

  return -1;
}

Env Game::env_infront_of_agent(size_t agent_index)
{
  if (food_infront_of_agent(agent_index)  >= 0) { return ENV_FOOD;  }
  if (wall_infront_of_agent(agent_index)  >= 0) { return ENV_WALL;  }
  if (agent_infront_of_agent(agent_index) >= 0) { return ENV_AGENT; }

  return ENV_NOTHING;
}

void Game::execute_action(size_t agent_index, Action action)
{
  switch (action)
  {
    case ACTION_NOP:
      break;

    case ACTION_STEP:
    {
      if (env_infront_of_agent(agent_index) != ENV_WALL)
      {
        Point d = points_dir[agents[agent_index].get_dir()];
        Point e(0, 0);

        int old_x = agents[agent_index].get_pos_x();
        int old_y = agents[agent_index].get_pos_y();

        e.set_x(mod_int(old_x + d.get_x(), BOARD_WIDTH ));
        e.set_y(mod_int(old_y + d.get_y(), BOARD_HEIGHT));

        agents[agent_index].set_pos(e);
      }

    } break;

    case ACTION_EAT:
    {
      int food_index = food_infront_of_agent(agent_index);
      if (food_index >= 0)
      {
        int old_hunger = agents[agent_index].get_hunger();

        foods[food_index].set_eaten(true);
        agents[agent_index].set_hunger(old_hunger + FOOD_VALUE);
      }

    } break;

    case ACTION_ATTACK:
    {
      int other_agent_index = agent_infront_of_agent(agent_index);

      if (other_agent_index >= 0)
      {
        int old_health = agents[other_agent_index].get_health();

        agents[other_agent_index].set_health(old_health - ATTACK_DAMAGE);
      }

    } break;

    case ACTION_TURN_LT:
    {
      Dir new_direction = (Dir) mod_int(agents[agent_index].get_dir() + 1, 4);

      agents[agent_index].set_dir(new_direction);

    } break;

    case ACTION_TURN_RT:
    {
      Dir new_direction = (Dir) mod_int(agents[agent_index].get_dir() - 1, 4);
      
      agents[agent_index].set_dir(new_direction);

    } break;

    case ACTION_COUNT:
    { } break;
  }
}

void Game::step_game()
{
  for (size_t i = 0; i < AGENTS_COUNT; i++)
  {
    if (agents[i].get_health() > 0)
    {

      // Interprete genes
      for (size_t j = 0; j < GENES_COUNT; j++)
      {
        Gene *gene = chromos[i].get_gene(j);

        if (gene->get_state() == agents[i].get_state()
            && gene->get_env() == env_infront_of_agent(i))
        {
          execute_action(i, chromos[i].get_gene(j)->get_action());
          agents[i].set_state(chromos[i].get_gene(j)->get_next_state());
          break;
        }
      }

      // Handle Hunger
      agents[i].set_hunger(agents[i].get_hunger() - HUNGER_STEP);

      if (agents[i].get_hunger() <= 0)
      {
        agents[i].set_health(0);
      }

      // Update lifetime
      agents[i].set_lifetime(agents[i].get_lifetime() + 1);
    }
  }
}
