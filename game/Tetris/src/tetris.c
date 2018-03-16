#include "../include/tetris.h"
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>

#define FRAME_X 13
#define FRAME_Y 3
#define FRAME_HEIGHT 20
#define FRAME_WIDTH 18

int Temp, Temp1, Temp2;
int a[80][80] = {0};
int b[4];

int color(int c) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
  return 0;
}

void goto_coordinate(int x, int y) {
  COORD pos;
  pos.X = (short)x;
  pos.Y = (short)y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void display_main() {
  draw_title();
  draw_flower();
  draw_welcome();
}

void draw_flower() {
  goto_coordinate(66, 11);
  color(12);
  printf("(_)");

  goto_coordinate(64, 12);
  printf("(_)");

  goto_coordinate(68, 12);
  printf("(_)");

  goto_coordinate(66, 13);
  printf("(_)");

  goto_coordinate(67, 12);
  color(6);
  printf("@");

  goto_coordinate(72, 10);
  color(13);
  printf("(_)");

  goto_coordinate(76, 10);
  printf("(_)");

  goto_coordinate(74, 9);
  printf("(_)");

  goto_coordinate(74, 11);
  printf("(_)");

  goto_coordinate(75, 10);
  color(6);
  printf("@");

  goto_coordinate(71, 12);
  printf("|");

  goto_coordinate(72, 11);
  printf("/");

  goto_coordinate(70, 13);
  printf("\\|");

  goto_coordinate(70, 14);
  printf("`|/");

  goto_coordinate(70, 15);
  printf("\\|");

  goto_coordinate(71, 16);
  printf("| /");

  goto_coordinate(71, 17);
  printf("|");

  goto_coordinate(67, 17);
  color(10);
  printf("\\\\\\\\");

  goto_coordinate(73, 17);
  printf("//");

  goto_coordinate(67, 18);
  color(2);
  printf("^^^^^^^^");

  goto_coordinate(65, 19);
  color(5);
  printf("eee");

  goto_coordinate(68, 20);
  printf("test ");
}

void draw_title() {
  color(bwhite);
  goto_coordinate(24, 3);
  printf("Tetris\n");
  color(bbgreen);
  goto_coordinate(18, 5);
  printf("■");
  goto_coordinate(18, 6);
  printf("■■");
  goto_coordinate(18, 7);
  printf("■");

  color(yellow);
  goto_coordinate(26, 6);
  printf("■■");
  goto_coordinate(28, 7);
  printf("■■"); //

  color(bgreen);
  goto_coordinate(36, 6);
  printf("■■");
  goto_coordinate(36, 7);
  printf("■■");

  color(pink);
  goto_coordinate(45, 5);
  printf("■");
  goto_coordinate(45, 6);
  printf("■");
  goto_coordinate(45, 7);
  printf("■");
  goto_coordinate(45, 8);
  printf("■");

  color(red);
  goto_coordinate(56, 6);
  printf("■");
  goto_coordinate(52, 7);
  printf("■■■");
}

void draw_welcome() {
  int n;
  int i, j = 1;
  color(yellow);
  for (i = 9; i <= 20; i++) {
    for (j = 15; j <= 60; j++) {
      goto_coordinate(j, i);
      if (i == 9 || i == 20)
        printf("=");
      else if (j == 15 || j == 59)
        printf("||");
    }
  }
  color(red);
  goto_coordinate(25, 12);
  printf("1.Start Game");
  goto_coordinate(40, 12);
  printf("2.Key Mapping");
  goto_coordinate(25, 17);
  printf("3.Game rules");
  goto_coordinate(40, 17);
  printf("4.Exit");
  goto_coordinate(21, 22);
  color(dgreen);
  printf("Please input[1 2 3 4]:[ ]\b\b");
  color(yellow);
  scanf("%d", &n);
  switch (n) {
  case 1:
    system("cls");
    draw_game_frame();
    play_game();
    break;
  case 2:
    explanation();
    break;
  case 3:
    game_rule();
    break;
  case 4:
    close();
    break;
  }
}

void draw_game_frame() {
  goto_coordinate(FRAME_X + FRAME_WIDTH - 7, FRAME_Y - 2);
  color(bbgreen);
  printf("Tetris");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 7);
  color(dblue);
  printf("**********");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 13, FRAME_Y + 7);
  color(dgreen);
  printf("next cube: ");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 13);
  color(dblue);
  printf("**********");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 17);
  color(yellow);
  printf("↑: roate cube");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 19);
  printf("space: Pause Game");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 15);
  printf("Esc: Exit Game");
  goto_coordinate(FRAME_X, FRAME_Y);
  color(red);
  printf("╔");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH - 2, FRAME_Y);
  printf("╗");
  goto_coordinate(FRAME_X, FRAME_Y + FRAME_HEIGHT);
  printf("╚");
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH - 2, FRAME_Y + FRAME_HEIGHT);
  printf("╝");
  for (int i = 2; i < 2 * FRAME_WIDTH - 2; i += 2) {
    goto_coordinate(FRAME_X + i, FRAME_Y);
    printf("═");
  }
  for (int i = 2; i < 2 * FRAME_WIDTH - 2; i += 2) {
    goto_coordinate(FRAME_X + i, FRAME_Y + FRAME_HEIGHT);
    printf("═");
    a[FRAME_X + i][FRAME_Y + FRAME_HEIGHT] = 2;
  }
  for (int i = 1; i < FRAME_HEIGHT; i++) {
    goto_coordinate(FRAME_X, FRAME_Y + i);
    printf("║");
    a[FRAME_X][FRAME_Y + i] = 2;
  }
  for (int i = 1; i < FRAME_HEIGHT; i++) {
    goto_coordinate(FRAME_X + 2 * FRAME_WIDTH - 2, FRAME_Y + i);
    printf("║");
    a[FRAME_X + 2 * FRAME_WIDTH - 2][FRAME_Y + i] = 2;
  }
}

void make_tetris(tetris_p tetris) {
  a[tetris->x][tetris->y] = b[0];
  switch (tetris->flag) {
  case 1: {
    color(bgreen);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x + 2][tetris->y - 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 2: {
    color(pink);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x + 2][tetris->y] = b[2];
    a[tetris->x + 4][tetris->y] = b[3];
    break;
  }
  case 3: {
    color(pink);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y - 2] = b[2];
    a[tetris->x][tetris->y + 1] = b[3];
    break;
  }
  case 4: {
    color(bbgreen);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x + 2][tetris->y] = b[2];
    a[tetris->x][tetris->y + 1] = b[3];
    break;
  }
  case 5: {
    color(bbgreen);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y + 1] = b[2];
    a[tetris->x - 2][tetris->y] = b[3];
    break;
  }
  case 6: {
    color(bbgreen);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x - 2][tetris->y] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 7: {
    color(bbgreen);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y + 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 8: {
    color(yellow);
    a[tetris->x][tetris->y + 1] = b[1];
    a[tetris->x - 2][tetris->y] = b[2];
    a[tetris->x + 2][tetris->y + 1] = b[3];
    break;
  }
  case 9: {
    color(yellow);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x - 2][tetris->y] = b[2];
    a[tetris->x - 2][tetris->y + 1] = b[3];
    break;
  }
  case 10: {
    color(yellow);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x - 2][tetris->y - 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 11: {
    color(yellow);
    a[tetris->x][tetris->y + 1] = b[1];
    a[tetris->x - 2][tetris->y - 1] = b[2];
    a[tetris->x - 2][tetris->y] = b[3];
    break;
  }
  case 12: {
    color(red);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y + 1] = b[2];
    a[tetris->x - 2][tetris->y - 1] = b[3];
    break;
  }
  case 13: {
    color(red);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x + 2][tetris->y - 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 14: {
    color(red);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y + 1] = b[2];
    a[tetris->x + 2][tetris->y + 1] = b[3];
    break;
  }
  case 15: {
    color(red);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x - 2][tetris->y + 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 16: {
    color(red);
    a[tetris->x][tetris->y + 1] = b[1];
    a[tetris->x][tetris->y - 1] = b[2];
    a[tetris->x + 2][tetris->y - 1] = b[3];
    break;
  }
  case 17: {
    color(red);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x + 2][tetris->y + 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  case 18: {
    color(red);
    a[tetris->x][tetris->y - 1] = b[1];
    a[tetris->x][tetris->y + 1] = b[2];
    a[tetris->x - 2][tetris->y + 1] = b[3];
    break;
  }
  case 19: {
    color(red);
    a[tetris->x - 2][tetris->y] = b[1];
    a[tetris->x - 2][tetris->y - 1] = b[2];
    a[tetris->x + 2][tetris->y] = b[3];
    break;
  }
  }
}

void print_tetris(tetris_p tetris) {
  for (int i = 0; i < 4; i++) {
    b[i] = 1;
  }
  make_tetris(tetris);
  for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
    for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
      if (a[i][j] == 1 && j > FRAME_Y) {
        goto_coordinate(i, j);
        printf("■");
      }
    }
  }

  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 1);
  color(dbgreen);
  printf("level : ");
  color(red);
  printf(" %d", tetris->level);
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 3);
  color(dbgreen);
  printf("score : ");
  color(red);
  printf(" %d", tetris->score);
  goto_coordinate(FRAME_X + 2 * FRAME_WIDTH + 3, FRAME_Y + 5);
  color(dbgreen);
  printf("speed : ");
  color(red);
  printf(" %dms", tetris->speed);
}

int if_move(tetris_p tetris) {
  if (a[tetris->x][tetris->y] != 0) {
    return 0;
  } else {
    if ((tetris->flag == 1 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x + 2][tetris->y - 1] == 0 &&
                               a[tetris->x + 2][tetris->y] == 0)) ||

        (tetris->flag == 2 && (a[tetris->x - 2][tetris->y] == 0 &&
                               a[tetris->x + 2][tetris->y] == 0 &&
                               a[tetris->x + 4][tetris->y] == 0)) ||
        (tetris->flag == 3 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x][tetris->y - 2] == 0 &&
                               a[tetris->x][tetris->y + 1] == 0)) ||
        (tetris->flag == 4 && (a[tetris->x - 2][tetris->y] == 0 &&
                               a[tetris->x + 2][tetris->y] == 0 &&
                               a[tetris->x][tetris->y + 1] == 0)) ||
        (tetris->flag == 5 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x][tetris->y + 1] == 0 &&
                               a[tetris->x - 2][tetris->y] == 0)) ||
        (tetris->flag == 6 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x - 2][tetris->y] == 0 &&
                               a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 7 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x][tetris->y + 1] == 0 &&
                               a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 8 && (a[tetris->x][tetris->y + 1] == 0 &&
                               a[tetris->x - 2][tetris->y] == 0 &&
                               a[tetris->x + 2][tetris->y + 1] == 0)) ||
        (tetris->flag == 9 && (a[tetris->x][tetris->y - 1] == 0 &&
                               a[tetris->x - 2][tetris->y] == 0 &&
                               a[tetris->x - 2][tetris->y + 1] == 0)) ||
        (tetris->flag == 10 && (a[tetris->x][tetris->y - 1] == 0 &&
                                a[tetris->x - 2][tetris->y - 1] == 0 &&
                                a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 11 && (a[tetris->x][tetris->y + 1] == 0 &&
                                a[tetris->x - 2][tetris->y - 1] == 0 &&
                                a[tetris->x - 2][tetris->y] == 0)) ||
        (tetris->flag == 12 && (a[tetris->x][tetris->y - 1] == 0 &&
                                a[tetris->x][tetris->y + 1] == 0 &&
                                a[tetris->x - 2][tetris->y - 1] == 0)) ||
        (tetris->flag == 15 && (a[tetris->x - 2][tetris->y] == 0 &&
                                a[tetris->x - 2][tetris->y + 1] == 0 &&
                                a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 14 && (a[tetris->x][tetris->y - 1] == 0 &&
                                a[tetris->x][tetris->y + 1] == 0 &&
                                a[tetris->x + 2][tetris->y + 1] == 0)) ||
        (tetris->flag == 13 && (a[tetris->x - 2][tetris->y] == 0 &&
                                a[tetris->x + 2][tetris->y - 1] == 0 &&
                                a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 16 && (a[tetris->x][tetris->y + 1] == 0 &&
                                a[tetris->x][tetris->y - 1] == 0 &&
                                a[tetris->x + 2][tetris->y - 1] == 0)) ||
        (tetris->flag == 19 && (a[tetris->x - 2][tetris->y] == 0 &&
                                a[tetris->x - 2][tetris->y - 1] == 0 &&
                                a[tetris->x + 2][tetris->y] == 0)) ||
        (tetris->flag == 18 && (a[tetris->x][tetris->y - 1] == 0 &&
                                a[tetris->x][tetris->y + 1] == 0 &&
                                a[tetris->x - 2][tetris->y + 1] == 0)) ||
        (tetris->flag == 17 && (a[tetris->x - 2][tetris->y] == 0 &&
                                a[tetris->x + 2][tetris->y + 1] == 0 &&
                                a[tetris->x + 2][tetris->y] == 0))) {
      return 1;
    }
  }
  return 0;
}

void clean_tetris(tetris_p tetris) {
  for (int i = 0; i < 4; i++) {
    b[i] = 0;
  }
  make_tetris(tetris);
  for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
    for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
      if (a[i][j] == 0 && j > FRAME_Y) {
        goto_coordinate(i, j);
        printf("  ");
      }
    }
  }
}

void del_full_line(tetris_p tetris) {
  int k, del_rows = 0;
  for (int j = FRAME_Y + FRAME_HEIGHT - 1; j >= FRAME_Y + 1; j--) {
    k = 0;
    for (int i = FRAME_X + 2; i < FRAME_X + 2 * FRAME_WIDTH - 2; i += 2) {
      if (a[i][j] == 1) {
        k++;
        if (k == FRAME_WIDTH - 2) {
          for (k = FRAME_X + 2; k < FRAME_X + 2 * FRAME_WIDTH - 2; k += 2) {
            a[k][j] = 0;
            goto_coordinate(k, j);
            printf("  ");
          }

          for (k = j - 1; k > FRAME_Y; k--) {
            for (i = FRAME_X + 2; i < FRAME_X + 2 * FRAME_WIDTH - 2; i += 2) {
              if (a[i][k] == 1) {
                a[i][k] = 0;
                goto_coordinate(i, k);
                printf("  ");
                a[i][k + 1] = 1;
                goto_coordinate(i, k + 1);
                printf("■");
              }
            }
          }
          j++;
          del_rows++;
        }
      }
    }
  }
  tetris->score += 100 * del_rows;
  if (del_rows > 0 &&
      (tetris->score % 1000 == 0 || tetris->score / 1000 > tetris->level - 1)) {
    tetris->speed -= 20;
    tetris->level++;
  }
}

void flag(tetris_p tetris) {
  tetris->number++;
  srand(time(NULL));
  if (tetris->number == 1) {
    tetris->flag = rand() % 19 + 1;
  }
  tetris->next = rand() % 19 + 1;
}

void play_game() {
  int n;
  struct Tetris t, *tetris = &t;
  char ch;
  tetris->number = 0;
  tetris->speed = 300;
  tetris->score = 0;
  tetris->level = 1;
  while (1) {
    flag(tetris);
    Temp = tetris->flag;
    tetris->x = FRAME_X + 2 * FRAME_WIDTH + 6;
    tetris->y = FRAME_Y + 10;
    tetris->flag = tetris->next;
    print_tetris(tetris);
    tetris->x = FRAME_X + FRAME_WIDTH;
    tetris->y = FRAME_Y - 1;
    tetris->flag = Temp;
    while (1) {
    label:
      print_tetris(tetris);
      Sleep(tetris->speed);
      clean_tetris(tetris);
      Temp1 = tetris->x;
      Temp2 = tetris->flag;
      if (kbhit()) {
        ch = getch();
        if (ch == 75) {
          tetris->x -= 2;
        }
        if (ch == 77) {
          tetris->x += 2;
        }
        if (ch == 80) {
          if (if_move(tetris) != 0) {
            tetris->y += 2;
          }
          if (if_move(tetris) == 0) {
            tetris->y = FRAME_Y + FRAME_HEIGHT - 2;
          }
        }
        if (ch == 72) {
          if (tetris->flag >= 2 && tetris->flag <= 3) {
            tetris->flag++;
            tetris->flag %= 2;
            tetris->flag += 2;
          }
          if (tetris->flag >= 4 && tetris->flag <= 7) {
            tetris->flag++;
            tetris->flag %= 4;
            tetris->flag += 4;
          }
          if (tetris->flag >= 8 && tetris->flag <= 11) {
            tetris->flag++;
            tetris->flag %= 4;
            tetris->flag += 8;
          }
          if (tetris->flag >= 12 && tetris->flag <= 15) {
            tetris->flag++;
            tetris->flag %= 4;
            tetris->flag += 12;
          }
          if (tetris->flag >= 16 && tetris->flag <= 19) {
            tetris->flag++;
            tetris->flag %= 4;
            tetris->flag += 16;
          }
        }
        if (ch == 32) {
          print_tetris(tetris);
          while (1) {
            if (kbhit()) {
              ch = getch();
              if (ch == 32) {
                goto label;
              }
            }
          }
        }
        if (ch == 27) {
          system("cls");
          memset(a, 0, 6400 * sizeof(int));
          draw_welcome();
        }
        if (if_move(tetris) == 0) {
          tetris->x = Temp1;
          tetris->flag = Temp2;
        } else {
          goto label;
        }
      }
      tetris->y++;
      if (if_move(tetris) == 0) {
        tetris->y--;
        print_tetris(tetris);
        del_full_line(tetris);
        break;
      }
    }
    for (int i = tetris->y - 2; i < tetris->y + 2; i++) {
      if (i == FRAME_Y) {
        system("cls");
        goto_coordinate(29, 7);
        printf("   \n");
        color(red);
        printf("\t\t\t■■■■   ■     ■   ■■     \n");
        printf("\t\t\t■         ■■   ■   ■  ■   \n");
        printf("\t\t\t■■■     ■  ■ ■   ■   ■  \n");
        printf("\t\t\t■         ■   ■■   ■  ■   \n");
        printf("\t\t\t■■■■   ■     ■   ■■     \n");
        goto_coordinate(17, 18);
        color(yellow);
        printf("replay game-------1");
        goto_coordinate(44, 18);
        printf("exit game-------2\n");
        int n;
        goto_coordinate(32, 20);
        printf("select [1/2] ：");
        color(bbgreen);
        scanf("%d", &n);
        switch (n) {
        case 1:
          system("cls");
          replay(tetris);
          break;
        case 2:
          exit(0);
          break;
        }
      }
    }
    tetris->flag = tetris->next;
    tetris->x = FRAME_X + 2 * FRAME_WIDTH + 6;
    tetris->y = FRAME_Y + 10;
    clean_tetris(tetris);
  }
}

void replay(tetris_p tetris) {
  system("cls");
  memset(a, 0, 6400 * sizeof(int));
  draw_game_frame();
  play_game();
}

void explanation() {
  int i, j = 1;
  system("cls");
  color(pink);
  goto_coordinate(32, 3);
  printf("Key Mapping");
  color(dblue);
  for (i = 6; i <= 16; i++) {
    for (j = 15; j <= 60; j++) {
      goto_coordinate(j, i);
      if (i == 6 || i == 16)
        printf("=");
      else if (j == 15 || j == 59)
        printf("||");
    }
  }
  color(dgreen);
  goto_coordinate(18, 7);
  printf("tip1:  ← → to move cube");
  color(bgreen);
  goto_coordinate(18, 9);
  printf("tip2:  ↑ to roate cube");
  color(yellow);
  goto_coordinate(18, 11);
  printf("tip3:  ↓ to accelerate down speed");
  color(bbgreen);
  goto_coordinate(18, 13);
  printf("tip4: space to pause or resume game");
  color(dbgreen);
  goto_coordinate(18, 15);
  printf("tip5: ESC to exit game");
  getch();
  system("cls");
  display_main();
}

void game_rule() {
  int i, j = 1;
  system("cls");
  color(13);
  goto_coordinate(34, 3);
  printf("游戏规则");
  color(2);
  for (i = 6; i <= 18; i++) //输出上下边框===
  {
    for (j = 12; j <= 70; j++) //输出左右边框||
    {
      goto_coordinate(j, i);
      if (i == 6 || i == 18)
        printf("=");
      else if (j == 12 || j == 69)
        printf("||");
    }
  }
  color(12);
  goto_coordinate(16, 7);
  printf("tip1: 不同形状的小方块从屏幕上方落下，玩家通过调整");
  goto_coordinate(22, 9);
  printf("方块的位置和方向，使他们在屏幕底部拼出完整的");
  goto_coordinate(22, 11);
  printf("一条或几条");
  color(14);
  goto_coordinate(16, 13);
  printf("tip2: 每消除一行，积分增加100");
  color(11);
  goto_coordinate(16, 15);
  printf("tip3: 每累计1000分，会提升一个等级");
  color(10);
  goto_coordinate(16, 17);
  printf("tip4: 提升等级会使方块下落速度加快，游戏难度加大");
  getch(); //按任意键返回主界面
  system("cls");
  draw_welcome();
}

void close() { exit(0); }
