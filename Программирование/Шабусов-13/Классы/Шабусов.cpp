#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
#include "..\\..\\myclasses.h"
using namespace std;

class AB {
	int a, b;
public:
	AB() {a = 5; b = 8;};
	AB(int x, int y=25){a = x; b = y;};
	void set(){		//���� �������� ����� � ����������
		cout<<"������� �������� ����� a, b: "; cin>>a>>b;
	};
	void get(){	cout<<"a = "<<a<<", b = "<<b<<endl;};	//����� �������� ����� �� �����
	int sum() {return a+b;};	//���������� ����� �����
	int mult() {return a*b;};	//���������� ������������ �����
	void set(int amin, int amax, int bmin, int bmax){	//����������� ����� ��������� ��������
		a = rand() % (amax - amin + 1) + amin;
		b = rand() % (bmax - bmin + 1) + bmin;
	};
};

class clCircle {
	double x, y, radius;
public:
	clCircle(double a = 0, double b = 0, double r = 1) {
		x = a; y = b; radius = r;
	}
	void set() {cin>>x>>y>>radius;};
	void set(double x0, double x1,
			 double y0, double y1,
			 double r0, double r1) {
		myrnd(&x,      1, x0, x1, 1);
		myrnd(&y,      1, y0, y1, 1);
		myrnd(&radius, 1, r0, r1, 1);
	};
	double len()  {return 2*acos(-1)*radius;     };
	double area() {return acos(-1)*radius*radius;};
	double dist(double a, double b) {
		double res = sqrt((x-a)*(x-a)+(y-b)*(y-b)) - radius;
		return (res>0 ? res : 0);
	};
	void get(int sw, int sp) {
		cout<<right<<fixed<<setprecision(sp);
		cout<<"("<<setw(sw)<<x
			<<","<<setw(sw)<<y
			<<","<<setw(sw)<<radius<<")";
	};
	void set(const char* s, const char* sep) {
		char* p=(char*) s; p+=myspn(s, sep);
		x = atof(p);
		p+=mycspn(p, sep); p+=myspn(p, sep);
		y = atof(p);
		p+=mycspn(p, sep); p+=myspn(p, sep);
		radius = atof(p);
	};
	void get5(int sw, int sp) {
		cout<<fixed<<right<<setprecision(sp);
		cout<<setw(sw)<<x<<" |"
			<<setw(sw)<<y<<" |"
			<<setw(sw-1)<<radius<<" |  ";
		cout<<"���������� ����������� =";
	};
	int intersection(clCircle *crc, int ncrc) {
		int n=0;
		for(int i=0; i<ncrc; i++)
			if(crc[i].dist(x, y) <= radius) n++;
		return n;
	};
};

class clSession {
	char* name;
	int ng;
	int nval;
	int* val;
public:
	clSession() {name = NULL; ng = 0; nval = 0; val = NULL;};
	void set(const char *s) {
		char* p = str2int(s,2) - 1;
		name = new char[p-s+1]; mycpy(name, s, p-s, 1);
		p = str2int(p, 1, &ng); p = str2int(p, 1, &nval);
		val = new int [nval]; str2int(p, nval, val);
	};
	void setname(const char* newname) {
		if(name!=NULL) delete[]name;
		name = new char[mylen(newname)+1];
		mycpy(name, newname);
	};
	void setval(int ind, int newval) {
		if(val==NULL) val = new int[nval];
		if(ind >= 0 && ind <nval) val[ind] = newval;
	};
	float mean() {if(nval) return meanval(val, nval);};
	void get(int nw, int nv, bool grout=false, bool meanout=false) {
		cout<<left<<setw(nw)<<name<<fixed;
		if(grout) cout<<"������ �"<<ng<<"  ";
		for(int i=0; i<nv; i++) cout<<setw(3)<<val[i];
		if(meanout) cout<<"  ������� = "<<mean();
		cout<<endl;
	};
	bool nameis(const char* s) {
		return !mycmp(name, s);
	};
	~clSession() {delete[]name, delete[]val;};
};

int main(){
setlocale(LC_ALL, "RUS");
srand(time(0));
{cout<<"=== ������� 1 =================\n";
	AB ab1;
	ab1.set();
	cout<<"����� ����� = "       <<ab1.sum() <<endl;
	cout<<"������������ ����� = "<<ab1.mult()<<endl;
	ab1.set(-99, 99, -99, 99);
	cout<<"����� �������� ����� ������� ab1: "; ab1.get();
	cout<<"����� ����� = "       <<ab1.sum() <<endl;
	cout<<"������������ ����� = "<<ab1.mult()<<endl;

	AB ab2;
	cout<<"�������� ����� ������� ab2: "; ab2.get();

	AB ab3(12, -10);
	cout<<"�������� ����� ������� ab3: "; ab3.get();
	
	AB ab4(30);
	cout<<"�������� ����� ������� ab4: "; ab4.get();
}
{cout<<"=== ������� 2 =================\n";
	int n = 50;
	cout<<"������ �������: "<<n<<endl;
	arD ar1(n);
	ar1.set(-99, 99);
	cout<<"������ ��������� �����:\n";
	ar1.get(10);
	cout<<"�������� ������� = "<<ar1.min()<<".."<<ar1.max()<<endl
		<<"������� �������� = "<<ar1.mean()<<endl;
	ar1.srt();
	cout<<"���������� �� �����������:\n";
	ar1.get(10);
}
{cout<<"=== ������� 3 =================\n";
	AB *pab1 = new AB, *pab2 = new AB(1, 2);
	cout<<"���� ������� ������������� �������: "; pab1->get();
	cout<<"���� ������� ������������� �������: "; pab2->get();
	AB *pab3 = new AB[10];
	for(int i=0; i<10; i++) pab3[i].set(-9, 9, -9, 9);
	cout<<"���� ���������� �������� ������� ��������: "; pab3->get();
}
{cout<<"=== ������� 4 =================\n";
	int nc = 20; clCircle* arC = new clCircle[nc];
	cout<<"������������ ������ �� "<<nc<<" �������� clCircle:\n";
	for(int i=0; i<nc; i++) {
		arC[i].set(-9.9,9.9,-9.9,9.9,1,9.9); arC[i].get(4, 1);
		if((i+1)%5==0) cout<<endl;
	}
	clCircle* pmax = arC;
	double maxlen = 0;
	for(int i=0; i<nc; i++) {
		double len = arC[i].dist(0,0);
		if(len>maxlen) {maxlen = len; pmax = &arC[i];}
	}
	cout<<"\n����� ��������� �� ������ ��������� ���� "; pmax->get(4,1);
	cout<<" ����� ������� "<<setprecision(3)<<pmax->area()<<endl;
	delete[] arC;
}
{cout<<"=== ������� 5 =================\n";
	char* s = new char[1024];
	int nstud = myinput(s,"13.5.txt");
	clSession* stud = new clSession[nstud];
	char* p = s;
	for(int i=0; i<nstud; i++){
		stud[i].set(p);
		p += mylen(p)+1;
	}
	cout<<"�������� ������:\n";
	for(int i=0; i<nstud; i++) stud[i].get(23, 4);
	for(int i=0; i<nstud; i++)
		if(stud[i].nameis("�������� �.�.")) {
			stud[i].setname("�������� �.�.");
			break;
		}
	for(int i=0; i<nstud; i++)
		if(stud[i].nameis("����� �.�.")) {
			stud[i].setval(2, 5);
			stud[i].setval(3, 4);
			break;
		}
	clSession** srt = new clSession*[nstud];
	double*      mv = new double[nstud];
	for(int i=0; i<nstud; i++) {
		srt[i] = &stud[i];
		mv[i] = stud[i].mean();
	}
	mysrt(mv, nstud, 0, (double**)srt);
	cout<<"\n�������� ������:\n"<<fixed<<setprecision(2);
	for(int i=0; i<nstud; i++) srt[i]->get(21,0,0,1);
	delete[]s; delete[]stud; delete[]srt; delete[]mv;
}
{cout<<"=== ������� 6 =================\n";
	char* s = new char[1024*6]; int nc = myinput(s, "925.txt");
	clCircle* crc = new clCircle[nc];
	char *p = s;
	for(int i=0; i<nc; i++){
		crc[i].set(p, "( ; )");
		p += mylen(p)+1;
	}
	clCircle** srt = new clCircle *[nc];
	int*	   np = new int[nc];
	int k = 0;	//������� �������������� ������
	for(int i=0; i<nc; i++)	{
		np[i] = crc[i].intersection(crc, nc) - 1;
		srt[i] = &crc[i];
		if(np[i] > 0) k++;
	}
	mysrt(np, nc, 0, (int**)srt);
	cout<<"���������� �������������� ������ = "<<k<<endl;
	cout<<"������������� ������ �������������� ������:\n"
		<<"    X        Y       R\n";
	for(int i=0; i<k; i++){
		srt[i]->get5(7, 2);
		cout<<setw(2)<<np[i]<<endl;
	}
	delete[]s; delete[]crc; delete[]srt; delete[]np;
}
system("pause"); return 0;
}