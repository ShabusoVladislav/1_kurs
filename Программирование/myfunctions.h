//========================================================================
// ������������ ���� ������ ��������� ������ �10 ��������� �����������
//========================================================================
#pragma once

void binout(char, char='\n');

unsigned int myrnd();

int myrnd(int, int);

double myrnd(double x, double y, int n=3);

void myrnd(int *, int, int, int);

void myrnd(double *, int, double, double, int);

void myout(int *, int, int=-1, int=4);

void myout(double *, int, int=-1, int=8, int=3);

void myout(double a, double b);

void mysrt(int *M, int size, bool inc=true);

void mysrt(double *M, int size, bool inc=true);

int mymax(int *M, int size);

int mymin(int *M, int size);

int mymax(double *M, int size);

int mymin(double *M, int size);

int mylen(const char*s);		//���������� ����� ������ � ������ s

char* mycpy(char*s, const char*t);		//�������� ������ t � ������ s

char* mycat(char*s, const char*t);		//���������� ������ s � t

char* mycpy(char*s, const char*t, int n, bool addNull=false);		//�������� �� ������ t � ������ s n ������ ��������

bool mycmp(const char*s, const char*t, int n=0);		//���������� ������ n �������� ����� s, t � ���������� false, ���� ==; true, ���� !=

char* mystr(const char*s, const char*t, int n=0);	//���������� ����� ������� ��������� ��������� t � ������ s

int myinput(char *s, const char *fname, const char sep='\0');	//������ ���������� ����� fname � ������ s, �������� �������� ������ �������� sep

void myout(char *M, int size, int nc=-1, int nw=1);	//

void mydel(char*s, int ndel);	//������� � ������ ������ s ndel ��������

void myins(char*s, const char*t);	//��������� � ������ ������ s ������ t

int myspn(const char*s, const char*sep);	//���������� ���-�� ������ ������ ������������ sep, ������������� � ������ ������ s

int mycspn(const char*s, const char*sep);	//���������� ���-�� ������ ������ ��������� �������� sep, ������������� � ������ ������ s

void mysrt(int*X, int nx, bool inc, int*P[]);	//��������� nx ��������� ������� X �� ����������� (inc=true) � �������� (inc=false)

void mysrt(double*X, int nx, bool inc, double*P[]);	//��������� nx ��������� ������� X �� ����������� (inc=true) � �������� (inc=false)

void myout(int** M, int nr, int* size, int nw=4); //������� �� ����� ������������ ������� M, ������� nw ��������� ������� ��������

void mysrt(char**X, int nx, bool inc, char**P);	//������� ��������� ������ ������� X

char* ftoa(double d, char* str, int nf);	//����������� ������������ ����� d � �������� ���������� � �������� ��������� � �������� ������ str

char* str2int(const char* s, int nw, int* X=NULL);	//��������� nw ���� ������ s � ����� ����� � ����������� �� �������� ��������� ������� X

char* str2dbl(const char* s, int nw, double* X=NULL);	//��������� nw ���� ������ s � ������������ ����� � ����������� �� �������� ��������� ������� X

bool realequal(float, float, double=1e-6);	//���������� ��� ������������ ����� a, b c ������ ����������� e

bool realequal(double, double, double=1e-12);	//���������� ��� ������������ ����� a, b c ������ ����������� e

float meanval(int*x, int nx);	//������� �������������� nx ��������� ������� x

void mysrt(char**X, int nx, bool inc);	//������� ��������� ������ ������� X