#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <stdio.h>
#include <stdlib.h>

#define BACKGROUND_COLOR 0x2a3d45ff
#define GRID_COLOR       0x7a6c5dff
#define AGENT_COLOR      0xda2c38ff
#define WALL_COLOR       0x544544ff
#define FOOD_COLOR       0x87c38fff

#define HEX_COLOR(hex)  \
  ((hex) >> 24) & 0xff, \
  ((hex) >> 16) & 0xff, \
  ((hex) >>  8) & 0xff, \
  ((hex) >>  0) & 0xff

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define BOARD_WIDTH 12
#define BOARD_HEIGHT 12

#define CELL_WIDTH ((float) SCREEN_WIDTH / BOARD_WIDTH)
#define CELL_HEIGHT ((float) SCREEN_HEIGHT / BOARD_HEIGHT)

#define AGENTS_COUNT 21
#define AGENT_PADDING 15.0f

#define FOODS_COUNT 10
#define FOOD_PADDING 20.0f

#define WALLS_COUNT 21
#define WALL_PADDING 8.0f

typedef enum
{
  DIR_RT = 0,
  DIR_UP,
  DIR_LT,
  DIR_DN

} Dir;


#endif
