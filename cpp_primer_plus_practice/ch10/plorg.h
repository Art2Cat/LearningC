#ifndef __PLORG_H__
#define __PLORG_H__

class Plorg {
	private:
		enum size{MAX = 19};
		char name[MAX];
		int ci;
	public:
		Plorg(const char *n = "Plorga", int c = 50);

		void updateCI(int c);

		void show() const;

};
#endif
