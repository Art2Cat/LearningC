#ifndef __GOLF_H__
#define __GOLF_H__
#include <cstring>

const int LEN = 40;
class Golf {
	private:
		char fullname[LEN];
		int handicap;
	public:
		Golf();
		Golf(const char *name, int hc);

		int setGolf();

		void setFullName(const char * name);

		const char * getFullName() const;

		void setHandicap(int hc);

		int getHandicap() const;

		void showGolf();

};

#endif
