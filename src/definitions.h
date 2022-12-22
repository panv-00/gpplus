#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#define BACKGROUND_COLOR 0x2a3d45ff
#define GRID_COLOR       0x7a6c5dff
#define AGENT_COLOR      0xda2c38ff

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

#define BOARD_WIDTH 15
#define BOARD_HEIGHT 15

#define CELL_WIDTH ((float) SCREEN_WIDTH / BOARD_WIDTH)
#define CELL_HEIGHT ((float) SCREEN_HEIGHT / BOARD_HEIGHT)

#define AGENTS_COUNT 21
#define AGENT_PADDING 15.0f

typedef enum
{
  DIR_RT = 0,
  DIR_UP,
  DIR_LT,
  DIR_DN

} Dir;


#endif
