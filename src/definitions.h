#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BACKGROUND_COLOR 0x2a3d45ff
#define GRID_COLOR       0x7a6c5dff
#define AGENT_COLOR      0xda2c38ff
#define WALL_COLOR       0x7a6c5dff
#define FOOD_COLOR       0x87c38fff

#define HEX_COLOR(hex)  \
  ((hex) >> 24) & 0xff, \
  ((hex) >> 16) & 0xff, \
  ((hex) >>  8) & 0xff, \
  ((hex) >>  0) & 0xff

#define SCREEN_WIDTH     800
#define SCREEN_HEIGHT    800

#define BOARD_WIDTH      8
#define BOARD_HEIGHT     8

#define CELL_WIDTH       ((float) SCREEN_WIDTH  / BOARD_WIDTH )
#define CELL_HEIGHT      ((float) SCREEN_HEIGHT / BOARD_HEIGHT)

#define AGENTS_COUNT     3
#define AGENT_PADDING    (fminf(CELL_WIDTH, CELL_HEIGHT) / 5.0f)
#define ATTACK_DAMAGE    10

#define FOODS_COUNT      5
#define FOOD_PADDING     (fminf(CELL_WIDTH, CELL_HEIGHT) / 8.0f)
#define FOOD_VALUE       10
#define HUNGER_MAX       100
#define HUNGER_STEP      5

#define WALLS_COUNT      5
#define WALL_PADDING     0

#define GENES_COUNT      20
#define STATES_COUNT     4


typedef enum
{
  DIR_RT = 0,
  DIR_UP    ,
  DIR_LT    ,
  DIR_DN

} Dir;

const char *dir_to_cstr(Dir dir);

typedef int State;

typedef enum
{
  ACTION_NOP = 0,
  ACTION_STEP   ,
  ACTION_EAT    ,
  ACTION_ATTACK ,
  ACTION_TURN_LT,
  ACTION_TURN_RT,
  ACTION_COUNT

} Action;

const char *action_to_cstr(Action action);

typedef enum
{
  ENV_NOTHING = 0,
  ENV_AGENT      ,
  ENV_FOOD       ,
  ENV_WALL       ,
  ENV_COUNT

} Env;

const char *env_to_cstr(Env env);

#endif
