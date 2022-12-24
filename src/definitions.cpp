#include "definitions.h"

const char *dir_to_cstr(Dir dir)
{
  switch (dir)
  {
    case DIR_RT : return "RIGHT"; break;
    case DIR_UP : return "UP   "; break;
    case DIR_LT : return "LEFT "; break;
    case DIR_DN : return "DOWN "; break;
    default     : return "ERROR"; break;
  }
}

const char *action_to_cstr(Action action)
{
  switch (action)
  {
    case ACTION_NOP    : return "NO ACTION "; break;
    case ACTION_STEP   : return "STEP      "; break;
    case ACTION_EAT    : return "EAT       "; break;
    case ACTION_ATTACK : return "ATTACK    "; break;
    case ACTION_TURN_LT: return "TURN LEFT "; break;
    case ACTION_TURN_RT: return "TURN RIGHT"; break;
    default            : return "ERROR     "; break;
  }
}

const char *env_to_cstr(Env env)
{
  switch(env)
  {
    case ENV_NOTHING: return "NOTHING"; break;
    case ENV_AGENT  : return "AGENT  "; break;
    case ENV_FOOD   : return "FOOD   "; break;
    case ENV_WALL   : return "WALL   "; break;
    default         : return "ERROR  "; break;
  }
}
