#include <iostream>
#include <iomanip>
#include "myfunctions.h"
#include <fstream>
using namespace std;

void binout(char n, char ch){
	int nd = sizeof(n)*8;
	unsigned char m = n;
	unsigned char k = 1;
	for(int i=nd-1; i>=0; i--){
		cout<<(m&(k<<i)?1:0);
		if(i && i%8==0) cout<<' ';
	}
	cout<<ch;
}

unsigned int myrnd(){
	unsigned int res;
	char *p = (char*)&res;
	for(int i=0; i<4; i++){
		*p = rand()%256;
		p++;
	}
	return res;
}

int myrnd(int a, int b){
	if(a>b) return 0;
	return a + myrnd()%(b-a+1);
}

double myrnd(double x, double y, int n){
	if(x>y || n<0) return 0;
	double m = pow(10,n);
	int a = x * m,
		b = y * m;
	return myrnd(a,b) / m;
}

void myrnd(int *M, int size, int a, int b){
	for(int i=0; i<size; i++) M[i] = myrnd(a, b);
}

void myrnd(double *M, int size, double x, double y, int n){
	for(int i=0; i<size; i++) M[i] = myrnd(x, y, n);
}

void myout(int *M, int size, int nc, int nw){
	if(nc<=0)
		nc = size;
	for(int i=0; i<size; i++){
		cout<<setw(nw)<<M[i];
		if((i+1)%nc == 0)
			cout<<endl; }
}

void myout(double *M, int size, int nc, int nw, int nq){
	if(nc<=0)
		nc = size;
	for(int i=0; i<size; i++){
		cout<<fixed<<setw(nw)<<setprecision(nq)<<M[i];
		if((i+1)%nc == 0)
			cout<<endl; }
}
void myout(double a, double b){
	cout<<a
		<<(b>0 ? " + " : " - ")
		<<abs(b)<<'i';
}

void mysrt(int *M, int size, bool inc){
	if(inc){
		for(int i=size; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(M[j]>M[j+1]) swap(M[j], M[j+1]); }
	else{
		for(int i=size; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(M[j]<M[j+1]) swap(M[j], M[j+1]); }
}

void mysrt(double *M, int size, bool inc){
	if(inc){
		for(int i=size; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(M[j]>M[j+1]) swap(M[j], M[j+1]); }
	else{
		for(int i=size; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(M[j]<M[j+1]) swap(M[j], M[j+1]); }
}

int mymax(int *M, int size){
	int mx  = M[0],
		imx = 0;
	for(int i=1; i<size; i++)
		if(M[i]>mx) {
			mx=M[i]; imx=i;
		}
	return imx;
}

int mymin(int *M, int size){
	int mn  = M[0],
		imn = 0;
	for(int i=1; i<size; i++)
		if(M[i]<mn) {
			mn=M[i]; imn=i;
		}
	return imn;
}

int mymax(double *M, int size){
	int mx  = M[0],
		imx = 0;
	for(int i=1; i<size; i++)
		if(M[i]>mx) {
			mx=M[i]; imx=i;
		}
	return imx;
}

int mymin(double *M, int size){
	int mn  = M[0],
		imn = 0;
	for(int i=1; i<size; i++)
		if(M[i]<mn) {
			mn=M[i]; imn=i;
		}
	return imn;
}

int mylen(const char*s) {
	char*p = (char*)s;
	while(*p!=0)
		p++;
	return p-s;
}

char* mycpy(char*s, const char*t) {
	char *p = s,
		 *q = (char*)t;
	while(1) {
		*p = *q;
		if(*q==0) break;
		p++; q++;
	}
	return s;
}

char* mycat(char*s, const char*t) {
	char *p = s + mylen(s),
		 *q = (char*)t;
	while(1) {
		*p = *q;
		if(*q==0) break;
		p++; q++;
	}
	return s;
}

char* mycpy(char*s, const char*t, int n, bool addNull){
	char *p = s,
		 *q = (char*)t;
	for(int i=0; i<n; i++){
		*p = *q;
		if(*q==0) break;
		p++; q++;
	}
	if(addNull) *p = '\0';
	return s;
}

bool mycmp(const char*s, const char*t, int n){
	char *p = (char*)s,
		 *q = (char*)t;
	int ns = mylen(s),
		nt = mylen(t);
	if(n<=0)
		n = ns>nt?ns:nt;
	for(int i=0; i<n; i++,p++,q++)
		if(*p!=*q)
			return true;
	return false;
}

char* mystr(const char*s, const char*t, int n){
	if(n<=0)
		n = mylen(t);
	char *end = (char*)s + mylen(s) - n;
	for(char*p=(char*)s; p<=end; p++)
		if(!mycmp(p,t,n))
			return p;
	return NULL;
}

int myinput(char *s, const char *fname, const char sep){
	ifstream fin;                   //объ€вл€ем fin - поток данных из файла
    fin.open(fname, ios_base::in);  //св€зываем поток fin с файлом fname
    const int nt=256; char t[nt];   //t - дл€ ввода одной строки файла
    int nstr=0;                     //счетчик строк файла
    char *p = s;                    //указатель на начало строки s
    while(!fin.eof()){              //выполн€ем цикл, пока не достигнут конец файла
        fin.getline(t,nt);          //читаем в t текущую строку файла
        if(*t=='\0') break;         //если t - пуста€ строка, выходим из цикла
        mycpy(p, t);                //копируем строку t по адресу указател€ p
        nstr++;                     //увеличиваем счетчик строк
        p += mylen(t)+1;            //перемещаем p на новое место вставки
        *(p-1) = sep;               //вставл€ем между строками разделитель sep
    }
    *p = '\0';                      //завершаем строку s
    fin.close();                    //закрываем поток fin
    return nstr;                    //возвращаем количество считанных строк
}

void myout(char *M, int size, int nc, int nw){
	if(nc<=0)
		nc = size;
	for(int i=0; i<size; i++){
		cout<<setw(nw)<<M[i];
		if((i+1)%nc == 0)
			cout<<endl; }
}

void mydel(char*s, int ndel){
	if(ndel<=0) return;
	mycpy(s, s+ndel);
}

void myins(char*s, const char*t){
	int ns = mylen(s), nt = mylen(t);
	for(char *p = s+ns; p >= s; p--)
		*(p+nt) = *p;
	mycpy(s, t, nt);
}

int myspn(const char*s, const char*sep){
	char *p = (char*)s;
	while(mystr(sep,p,1)) p++;
	return p-s;
}

int mycspn(const char*s, const char*sep){
	char *p = (char*)s;
	while(*p && !mystr(sep,p,1)) p++;
	return p-s;
}

void mysrt(int*X, int nx, bool inc, int*P[]){
	for(int i=0; i<nx; i++)
		for(int j=0; j<nx-1; j++) {
			if(inc==true) {
				if(X[j]>X[j+1]) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
			else {
				if(X[j]<X[j+1]) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
		}
}

void mysrt(double*X, int nx, bool inc, double*P[]){
	for(int i=0; i<nx; i++)
		for(int j=0; j<nx-1; j++) {
			if(inc==true) {
				if(X[j]>X[j+1]) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
			else {
				if(X[j]<X[j+1]) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
		}
}

void myout(int** M, int nr, int* size, int nw){
	for(int i=0; i<nr; i++)
		if(size[i])
			myout(M[i], size[i], size[i], nw);
		else
			cout<<endl;
}

void mysrt(char**X, int nx, bool inc, char**P){
	for(int i=0; i<nx; i++)
		for(int j=0; j<nx-1; j++) {
			if(inc==true) {
				if(strcmp(X[j],X[j+1])>0) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
			else {
				if(strcmp(X[j],X[j+1])<0) {
					swap(X[j], X[j+1]);
					swap(P[j], P[j+1]);
				}
			}
		}
}

char* ftoa(double d, char* str, int nf){
	for(int i=0; i<nf; i++) d*=10;
	itoa(d,str,10); myins(str+mylen(str)-nf,".");
	return str;
}

char* str2int(const char* s, int nw, int* X){
	char* p = (char*)s;
	p += myspn(p," ");
	for(int i=0; i<nw; i++){
		if(X)
			X[i] = atoi(p);
		p += mycspn(p," ");
		p += myspn(p," ");
	}
	return p;
}

char* str2dbl(const char* s, int nw, double* X){
	char* p = (char*)s;
	p += myspn(p," ");
	for(int i=0; i<nw; i++){
		if(X)
			X[i] = atof(p);
		p += mycspn(p," ");
		p += myspn(p," ");
	}
	return p;
}

bool realequal(float a, float b, double e){
	if(abs(a-b)<e) return true;
	else return false;
}

bool realequal(double a, double b, double e){
	if(abs(a-b)<e) return true;
	else return false;
}

float meanval(int*x, int nx){
	float s=0;
	for(int i=0; i<nx; i++) s += x[i];
	s /= nx;
	return s;
}

void mysrt(char**X, int nx, bool inc){
	for(int i=0; i<nx; i++)
		for(int j=0; j<nx-1; j++) {
			if(inc==true) {
				if(strcmp(X[j],X[j+1])>0)
					swap(X[j], X[j+1]);
			}
			else {
				if(strcmp(X[j],X[j+1])<0)
					swap(X[j], X[j+1]);
			}
		}
}