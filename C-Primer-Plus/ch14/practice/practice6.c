#include <stdio.h>
#include <stdlib.h>

#define LEN 18

struct player {
  int id;
  char fName[10];
  char lName[10];
  int appearances;
  int hits;
  int wBases;
  int rbi;
};

void initData(int size, const char *);

int main(int argc, char **argv) {
  FILE *fb;
  int count = 0;
  int size = sizeof(struct player);
  char *path = "players.dat";

  initData(size, path);

  struct player team[LEN];

  if ((fb = fopen(path, "rb")) == NULL) {
    fprintf(stderr, "I couldn't open the file \"%s\"\n", path);
    exit(EXIT_FAILURE);
  }

  // rewind(fb); /* go to start of file     */
  while (count < LEN && fread(&team[count], size, 1, fb) == 1) {
    if (count == 0) {
      puts("Current contents of book.dat:");
    }
    printf("%d by %s %s\n", team[count].id, team[count].fName,
           team[count].lName);
    count++;
  }

  fclose(fb);

  if (remove(path) == 0) {
    printf("removed %s!", path);
  }
  return 0;
}

void initData(int size, const char *path) {
  struct player originTeam[LEN] = {
      {4, "Jessie", "Joybat4", 5, 2, 1, 1},
      {1, "Jessie", "Joybat1", 5, 2, 1, 1},
      {2, "Jessie", "Joybat2", 5, 3, 1, 1},
      {3, "Jessie", "Joybat3", 5, 15, 0, 0},
      {4, "Jessie", "Joybat4", 5, 2, 1, 1},
      {2, "Jessie", "Joybat2", 5, 2, 2, 1},
      {1, "Jessie", "Joybat1", 5, 2, 1, 4},
      {3, "Jessie", "Joybat3", 5, 6, 0, 0},
      {2, "Jessie", "Joybat2", 5, 2, 1, 4},
      {4, "Jessie", "Joybat4", 2, 2, 1, 2},
      {5, "Jessie", "Joybat5", 5, 2, 1, 1},
      {6, "Jessie", "Joybat6", 5, 2, 1, 1},
      {7, "Jessie", "Joybat7", 1, 2, 1, 0},
      {7, "Jessie", "Joybat7", 5, 2, 1, 1},
      {6, "Jessie", "Joybat6", 2, 2, 4, 1},
      {5, "Jessie", "Joybat5", 5, 2, 1, 1},
      {1, "Jessie", "Joybat1", 5, 2, 1, 1},
      {1, "Jessie", "Joybat1", 1, 1, 0, 1},
  };

  FILE *pl;
  if ((pl = fopen(path, "a+b")) == NULL) {
    fprintf(stderr, "I couldn't open the file \"%s\"\n", path);
    exit(EXIT_FAILURE);
  }

  for (int i = LEN; i >= 0; i--) {
    fwrite(originTeam, size, i, pl);
  }

  fclose(pl);
}
