#ifndef _TETRIS_H
#define _TETRIS_H

struct Tetris {
  int x;
  int y;
  int flag;
  int next;
  int speed;
  int number;
  int score;
  int level;
} tetris_t;

typedef struct Tetris *tetris_p;

enum color {
  black = 0,
  dblue,   /*dark blue*/
  dgreen,  /*dark green*/
  dbgreen, /*dark blue gren*/
  scarlet, /*scarlet*/
  purple,  /*purple*/
  dyellow, /*dark yellow*/
  white,   /*white*/
  bblue,   /*bright blue*/
  bgreen,  /*bright green*/
  bbgreen, /*bright blue green*/
  red,     /*red*/
  pink,    /*pink*/
  yellow,  /*yellow*/
  bwhite,  /*bright white*/
};

int color(int c);
void goto_coordinate(int x, int y);
void draw_game_frame();
void flag(tetris_p t);
void make_tetris(tetris_p t);
void print_tetris(tetris_p t);
void clear_tetris(tetris_p t);
int if_move(tetris_p t);
void del_full_line(tetris_p t);
void play_game();
void game_rule();
void explation();
void replay(tetris_p t);
void draw_title();
void draw_flower();
void close();

#endif
