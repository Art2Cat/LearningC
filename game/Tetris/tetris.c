#include "tetris.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define FRAME_X 13
#define FRAME_Y 3
#define FRAME_HEIGHT 20
#define FRAME_WIDTH 18

int color(int c) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUT_HANDLE), c);
  return 0;
}
