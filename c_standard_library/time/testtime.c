#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void) {
  char buf[32];
  clock_t tc = clock();

  struct tm ts1;
  time_t tt1, tt2;
  static char *dstr = "Tue Apr  3 19:20:11 2018\n";

  tt1 = time(&tt2);
  assert(tt1 == tt2);
  ts1.tm_sec = 11;
  ts1.tm_min = 20;
  ts1.tm_hour = 19;
  ts1.tm_mday = 3;
  ts1.tm_mon = 3;
  ts1.tm_year = 118;
  ts1.tm_isdst = -1;
  tt1 = mktime(&ts1);
  assert(ts1.tm_wday == 2);
  assert(ts1.tm_yday == 92);
  ++ts1.tm_sec;
  tt2 = mktime(&ts1);
  assert(difftime(tt1, tt2) < 0.0);
  assert(strcmp(asctime(localtime(&tt1)), dstr) == 0);
  assert(strftime(buf, sizeof(buf), "%S", gmtime(&tt2)) == 2);
  assert(strcmp(buf, "12") == 0);
  assert(tc <= clock());
  fputs("Current date -- ", stdout);
  time(&tt1);
  fputs(ctime(&tt1), stdout);
  puts("SUCCESS testing <time.h>");
  return 0;
}
