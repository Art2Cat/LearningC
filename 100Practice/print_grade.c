#include <stdio.h>

int main(int argc, char **argv) {
  int score;
  char grade;
  printf("请输入分数： ");
  scanf("%d", &score);
  grade = score >= 90 ? 'A' : score >= 60 ? 'B' : 'C';
  printf("%c\n", grade);
  return 0;
}