#ifndef __GOLF_H__
#define __GOLF_H__
const int LEN = 40;
struct golf {
	char fullname[LEN];
	int handicap;
};

void setGolf(golf &g, const char *name, int hc);

int setGolf(golf &g);

void handicap(golf &g, int hc);

void showGolf(const golf &g);

#endif
