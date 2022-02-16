#pragma once 

class arD {
	int *x, nx;
public:
	arD(int m);
	void set();
	void set(int xmin, int xmax);
	void get(int nc = -1, int nw = 4);
	int max();
	int min();
	float mean();
	void srt(bool inc = true);
	~arD();
};