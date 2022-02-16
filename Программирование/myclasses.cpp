#include <iostream>
#include <iomanip>
#include "myfunctions.h"
#include "myclasses.h"
using namespace std;

void arD::set() {
	for(int i=0; i<nx; i++) cin>>x[i];
}

void arD::set(int xmin, int xmax) {
	myrnd(x, nx, xmin, xmax);
}

arD::arD(int m) {
	nx = m; x = new int[nx];
}

void  arD::get(int nc, int nw){myout(x, nx, nc, nw);  }

int   arD::max()			  {return x[mymax(x, nx)];}

int   arD::min()			  {return x[mymin(x, nx)];}

void  arD::srt(bool inc)	  {mysrt(x, nx, inc);	  }

float arD::mean()			  {return meanval(x, nx); }

arD::~arD(){delete[]x;}