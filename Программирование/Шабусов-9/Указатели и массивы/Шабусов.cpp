#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
using namespace std;

void title(int, int=3, int=17, char='=');
int nn=1;

void myswap(int*, int*);

void fun16(double a, double b, double c, double d, double *p, double *q);

bool arrcmp(char *, char *, int);

void arrini(int *X, int nx, int m);

int main(){
setlocale(LC_ALL, "rus");
srand(time(0));
{title(nn++);
	int n, *p = &n; *p = 12;
	cout<<"2) Значение n = "<<n <<", адрес n = "   <<&n<<endl;
	cout<<"3) Значение n = "<<*p<<", адрес n = "   <<p <<endl;
	cout<<"4) Адрес p = "   <<&p<<endl;
}
{//Задание 2;
	int n,*p = &n;
	int *q; q = p;
	//int m = &n;	   //присваивание неуказателю адресного значения
	//float *r = 100;  //присваивание указателю неадресного значения
	//q = 200;		   //присваивание указателю неадресного значения
	//double *u, x = *u; //использование случайного адреса
	char *s, *t;
	//s = &x; t = &n; //присваивание указателю адреса другого типа
	t = (char*)&n;
}
nn++;
{title(nn++);
	double x=37.2095;
	char *p;
	p = (char*)&x;
	p += 7;
	cout<<"Двоичное представление x = "<<x<<":\n";
	for(int i=0; i<8; i++) {
		binout(*p, ' ');
		p--;
	}
}
{cout<<endl;
title(nn++);
	int a=3, b=7;
	cout<<"Начальные данные:       "<<a<<' '<<b<<endl;
	myswap(&a, &b);
	cout<<"Результат перестановки: "<<a<<' '<<b<<endl;
}
{title(nn++);
	double *p = new double(1.25), *q = new double(2.75);
	if(!q || !p) {
		cout<<"\nОшибка! Недостаточно памяти.\n";
		system("pause"); exit(1);  }
	cout<<"Указателю p выделена ячейка "<<p
		<<", содержащая число "<<*p<<endl;
	cout<<"Указателю q выделена ячейка "<<q
		<<", содержащая число "<<*q<<endl;
	delete p; delete q;
	cout<<"Выделенная указателям динамическая память освобождена.\n";
}
{cout<<"=== Задание 6а =================\n";
	const int nz=30; double Z[nz];
	double *p = Z, *q = &Z[10], *r = &Z[20];
	for(int i=0; i<10; i++){
		p[i] =       rand()%10  + rand()%1000/1000.;
		q[i] = 10  + rand()%90  + rand()%100/100.;
		r[i] = 100 + rand()%900 + rand()%10/10.;
	}
	cout<<fixed<<setprecision(3);
	for(int i=0; i<10; i++) cout<<setw(7)<<p[i];
	cout<<endl<<setprecision(2);
	for(int i=0; i<10; i++) cout<<setw(7)<<q[i];
	cout<<endl<<setprecision(1);
	for(int i=0; i<10; i++) cout<<setw(7)<<r[i];
	cout<<endl;

	cout<<"=== Задание 6b =================\n";
	myrnd(p, 10,   0, 9.999, 3); myout(p, 10, 0, 7, 3);
	myrnd(q, 10,  10, 99.99, 2); myout(q, 10, 0, 7, 2);
	myrnd(r, 10, 100, 999.9, 1); myout(r, 10, 0, 7, 1);
}
nn++;

{cout<<"=== Задание 14 =================\n";
	float f1 = 4.9, f2 = 7.8, *pf1 = &f2, *pf2;
	char c1 = 'A', c2 = 'B', *pc1 = &c2, *pc2;
	int n1 = 580, n2 = -50, *pn1 = &n1, *pn2;
	double d1 = 6.4, d2 = 8.5, *pd1 = &d2, *pd2;
	short s1 = -57, s2 = 328, *ps1 = &s1, *ps2;
	//f2 = *pf2;			//использование случайного адреса
	//pn2 = &d1;		//присваивание указателю адреса другого типа
	//s2 = ps1;			//присваивание неуказателю адресного значения
	//pd1 = d1;			//присваивание указателю неадресного значения
	//ps2 = pn1;		//присваивание указателю ps2 адреса из указателя pn1 другого типа 
	//pf2 = 162.8;		//присваивание указателю неадресного значения
	//pd1 = pd2;			//использование случайного адреса
	//c1 = &c2;			//присваивание неуказателю адресного значения
}
{cout<<"=== Задание 15 =================\n";
	double d = 379052943.34160918;
	char *p;
	p = (char*)&d;
	cout<<"d = "<<setw(18)<<setprecision(8)<<d<<endl
		<<"Обнуляем байт №7:\n";
	p += 7;
	*p = 0;
	for(int i=0; i<8; i++) {
		binout(*p, ' ');
		p--;
	}
}
{cout<<"\n=== Задание 16 ==============="<<endl;
	double a = 3, b = -5, c = 7, d = 4, e, f, *p = &e, *q = &f;
	cout<<setprecision(0)<<'('; myout(a,b);
	cout<<")("; myout(c,d); cout<<") = ";
	fun16(a,b,c,d,p,q);
	myout(*p, *q);
	cout<<endl;
}

{title(nn++);
	const int nrows=6, ncols=10; double M[nrows][ncols];
	myrnd(M[0],nrows*ncols, 0.5, 4.5, 1);
	cout<<"До упорядочивания:\n";
	myout(M[0], nrows*ncols, ncols, 5, 1);
	for(int i=0; i<nrows; i++)
		mysrt(M[i], ncols, i%2);
	cout<<"После упорядочивания:\n";
	myout(M[0], nrows*ncols, ncols, 5, 1);
}
{title(nn++);
	const int nrows=6, ncols=10; double M[nrows][ncols];
	myrnd(M[0],nrows*ncols,-9.99, 9.99, 2);
	myout(M[0],nrows*ncols, ncols, 7, 2);
	cout<<"Диаметры столбцов матрицы:\n";
	double A[nrows];
	for(int j=0; j<ncols; j++){
		for(int i=0; i<nrows; i++)
			A[i] = M[i][j];
		cout<<setw(7)
			<<A[mymax(A, nrows)] - A[mymin(A, nrows)];
	}
	cout<<endl;
}
{title(nn++);
	int nd = 5; cout<<"Размер динамического массива: "<<nd<<endl;
	double *D = new double[nd];
	if(!D) {
		cout<<"\nОшибка! Недостаточно памяти.";
		system("pause"); return 1;  }
	myrnd(D, nd, 0, 9.99, 2);
	for(int i=0; i<nd; i++){
		cout<<"D["<<i<<"] = "<<setw(4)<<D[i]
		<<" (адрес "<<&D[i]<<")\n";
	}
	cout<<"Размер массива D = "<<sizeof(D)/sizeof(D[0])<<" ?\n";
	delete[] D;
	cout<<"Выделенная динамическому массиву память освобождена\n";
}
//{cout<<"=== Задание 17 =================\n";
//	int lens=128; char *s = new char[lens];
//	int lent=3;   char *t = new char[lent];
//	if(!s || !t) {
//		cout<<"\nОшибка! Недостаточно памяти.\n";
//		system("pause"); return 1;  }
//	strcpy(t,"202");
//	strcpy(s,"Оценки группы №2 за зимнюю сессию 2020/2021 учебного года.");
//	cout<<"Исходный текст:\n"<<s<<endl
//		<<"Искомый участок:\n"<<t<<endl;
//	int ns = strlen(s),
//		nt = strlen(t);
//	int m = 0;
//	for(int i=0; i<lent; i++)
//		if(arrcmp(s,t,ns)) {
//			m = i;
//			cout<<"Индекс искомого участка = "<<m;
//		}
//	if(m==0)
//		cout<<"Искомый участок не найден\n";
//	delete[]s; delete[]t;
//}
//{cout<<"=== Задание 18 =================\n";
//	const int nr=10; int M[nr][nr];
//	arrini(M,nr*nr,0);
//	cout<<"Инициализация нижнего побочного треугольника\n";
//	for(int i=0; i<nr; i++) {
//		int *p = &M[nr][nr-1];
//		myrnd(p,i,1,9);
//	}
//}
{title(nn++);
	int nd = 60; int* D = new int[nd];
	myrnd(D, nd, -9, 9);
	myout(D, nd, 20, 3);
	int m = -5, n = 5;
	int *p   = D,
		*end = D+nd;
	while(p<end){
		if(*p==m) break;
		p++;
	}
	int *q = end-1;
	while(q>=D){
		if(*q==n) break;
		q--;
	}
	if(p<end && q>=D){
		cout<<"Индекс первого слева элемента " <<m<<" = "<<p-D<<endl;
		cout<<"Индекс первого справа элемента "<<n<<" = "<<q-D<<endl;
		cout<<"Элемент "<<(p<q ? m : n)<<" расположен ближе к началу массива\n";
	}
	delete[] D;
}
{title(nn++);
	int nx = 10; int *X = new int[nx];
	myrnd(X, nx, -99, 99);
	cout<<"Массив X:"; myout(X, nx);
	int s1=0, s2=0, s3=0;
	for(int i=0; i<nx; i++) s1+=X[i];
	for(int i=0; i<nx; i++) s2+=*(X+i);
	for(int *p=X, *end=X+nx; p<end; p++) s3+=*p;
	cout<<"s1 = "<<s1<<endl
		<<"s2 = "<<s2<<endl
		<<"s3 = "<<s3<<endl;
	cout<<"Индексы элементов >10:";
	for(int *p=X, i=0, *end=X+nx; p<end; p++, i++)
		if(*p>10) cout<<setw(3)<<i;
	cout<<endl;
}
{title(nn++);
	const int nr = 5; int M[nr][nr];
	myrnd(*M,nr*nr,-9,9);
	cout<<"Матрица M:\n"; myout(*M,nr*nr,nr);
	int sumP = 0, sumN = 0;
	for(int *p = M[0], *end = p+nr*nr; p<end; p++)
		if(*p>0) sumP += *p;
		else	 sumN += *p;
	cout<<"Сумма положительных элементов = "<<setw(4)<<sumP<<endl
		<<"Сумма отрицательных элементов = "<<setw(4)<<sumN<<endl;
	int max = M[0][0], imax = 0;
	for(int *p = &M[1][1], i = 1, *end = M[0]+nr*nr; p<end; p += nr+1, i++)
		if(*p>max) {max=*p; imax=i;}
	cout<<"Максимум главной диагонали M["<<imax<<"]["<<imax<<"] = "<<max<<endl;
}
{cout<<"=== Задание 19 =================\n";	cout.flags(0);
	int nx=20; int *X = new int[nx];
	if(!X){
		cout<<"\nОшибка! Недостаточно памяти.\n";
		system("pause"); return 1;  }
	myrnd(X,nx,0,99);
	cout<<"Исходный массив:\n"; myout(X,nx);
	while(1){
		int n=0;
		for(int *p=X, *end=X+nx-1; p<end; p++)
			if(*p%2==1 && *(p+1)%2==0){
				myswap(p,p+1);
				n++;
			}
		if(!n) break;
	}
	for(int *p=X, *end=X+nx; p<end; p++)
		if(*p%2!=0) {
			mysrt(X,p-X);
			mysrt(p,end-p,0);
			break;
		}
	cout<<"Итоговый массив:\n"; myout(X,nx);
	delete[]X;
}
{cout<<"=== Задание 20 =================\n";
	const int nr=6; int M[nr][nr];
	myrnd(M[6],nr*nr,-9,9);
	cout<<"Исходная матрица:\n";
	myout(M[6],nr*nr,nr);
	int sumUp = 0, sumLow = 0;
	for(int *p = M[0], *end = p+nr*nr; p < end; p+=nr+1) {
		for(int *r = p-nr; r >= M[0]; r -= nr)
			sumUp += *r;
		for(int *r = p+nr, *end = M[0]+nr*nr; r < end; r += nr)
			sumLow += *r;
	}
	cout<<"Сумма элементов над главной диагональю = "<<sumUp<<endl
		<<"Сумма элементов под главной диагональю = "<<sumLow<<endl;
}
system("pause"); return 0;
}

void title(int nn, int a, int b, char ch) {
	for(int i=0; i<a; i++) cout<<ch;
	cout<<" Задание "<<nn<<' ';
	for(int i=0; i<b; i++) cout<<ch;
	cout<<endl;
}

void myswap(int *m, int *n){
	if(*m!=*n) {int t=*m; *m=*n; *n=t;}
}

void fun16(double a, double b, double c, double d, double *p, double *q){
	*p = a*c-b*d;
	*q = a*d+b*c;
}

bool arrcmp(char *s, char *t, int ns){
	for(int i=0; i<ns; i++)
		if(s[i]!=t[i]) return false;
	return true;
}

void arrini(int *X, int nx, int m){
	for(int i=0; i<nx; i++)
		X[i] = m;
}