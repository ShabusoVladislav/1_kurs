#include <iostream>
#include <iomanip>
using namespace std;

void line1 ();

void line2(int, char);

void title(int, int=3, int=17, char='=');

int nod(int, int);

bool QE(double, double, double, double &, double &);

void fun5(double, char='*', int=2);

int nn = 1;

void myswap(int &, int &);

void myswap(double &, double &);

void myswap(char &, char &);

void tmout(int, int, double);

void tmout(int, int);

void tmout(int, double);

void myout(int[], int, int=4);

int mymax(int[], int);

int mymin(int[], int);

void z13(int&, char&);

double myexp(double, double e=1e-7);

inline int factorial(int n) {
	int res=1;
	for(int i=2; i<=n; i++) res*=i;
	return res;
}

void dblout(double);

void dblout(double, int);

void dblout(double, int, int);

double arrGeo (int[], int);

int main() {
setlocale(LC_ALL, "rus");

{title(nn++);
	int  n = 50;
	char ch = '-',
	s[30] = "Модульное построение программ";

	for (int i = 0; i < n; i++) cout << ch;
	cout << endl;
	cout << setw(39) << s << endl;
	for (int i = 0; i < n; i++) cout << ch;
	cout << endl;

	line1();
	cout << setw(39) << s << endl;
	line1();

	n  = 70;
	ch = '=';
	line2(n, ch);
	int ln = strlen(s);
	cout << setw(n / 2 + ln / 2)
		<< s << endl;
	line2(70, '~');
}
{title(nn++);
	title(15, 10, 10, '-');
	title(10, 6, 12, '~');
}
{title(nn++);
	int m = 17599692, n = 709927218;
	cout << "НОД(" << m << "," << n << ") = " << nod(m, n) << endl;
	m = 514396, n = 309603;
	cout << "НОД(" << m << "," << n << ") = " << nod(m, n) << endl;
}
{title(nn++);
	double a = 5.3, b = 8.1, c = 6.5;
	double root1, root2;
	cout<<"Коэффициенты: "<<a<<" "<<b<<" "<<c
		<<", корни: "<<fixed<<setprecision(6);
	if(QE(a,b,c,root1,root2))
		cout<<root1<<", "<<root2<<endl;
	else
		cout<<"нет вещественных корней"<<endl;
}
{title(nn++);
	fun5(2.5, '-', 11);
	fun5(2.5, '-');
	fun5(2.5);
	fun5(3.85, '*', 33);
}

	nn=8;	//так как в двух заданиях пропущен вывод

{title(nn++);
	int u=517, v=2063;
	cout<<"Целые:        "<<u<<" "<<v<<endl;
	myswap(u, v);
	cout<<"Перестановка: "<<u<<" "<<v<<endl;

	double a=3.48, b=-5.6;
	cout<<"Вещественные: "<<a<<" "<<b<<endl;
	myswap(a, b);
	cout<<"Перестановка: "<<a<<" "<<b<<endl;

	char c='~', d='&';
	cout<<"Символы:      "<<c<<" "<<d<<endl;
	myswap(c, d);
	cout<<"Перестановка: "<<c<<" "<<d<<endl;
}
{title(nn++);
	int h = 14, m = 7; double s = 9.45;
	cout<<"Формат 1: "; tmout(h,m,s);

	cout<<"Формат 2: "; tmout(h,m);

	cout<<"Формат 3: "; tmout(m,s);
}
{title(nn++);
	int n=8,m=3;

	int res1=1;
	for(int i=2; i<=n; i++) res1*=i;
	int res2=1;
	for(int i=2; i<=m; i++) res2*=i;
	int res3=1;
	for(int i=2; i<=n-m; i++) res3*=i;

	cout<<"Количество сочетаний "<<m<<" из "<<n<<" равно "
		<<res1/res2/res3;
}

cout<<endl;

{title(nn++);
	const int na = 10; int A[na] = {6,-5,7,2,-7,-3,8,5,0,4};
	cout<<"Исходный массив: "; myout(A, na);

	int i = mymax(A,na);
	cout<<"Элемент А["<<i<<"]="<<setw(2)<<A[i]<<" максимальный\n";

	int j = mymin(A,na);
	cout<<"Элемент А["<<j<<"]="<<setw(2)<<A[j]<<" минимальный\n";
}
{title(nn++);
	int M[5]={3,7,2,0,5};
	cout<<"Исходный массив:     "; myout(M,5);

	int n=mymax(M,5);
	myswap(M[n], M[4]);
	myout(M,5);
	
	n=mymax(M,4); myswap(M[n], M[3]); myout(M,5);
	n=mymax(M,3); myswap(M[n], M[2]); myout(M,5);
	n=mymax(M,2); myswap(M[n], M[1]); myout(M,5);
	
	cout<<"Упорядоченный массив "; myout(M,5);

	const int na=10; int A[na]={6,-5,7,2,-7,-3,8,5,0,4};
	cout<<"Исходный массив:     "; myout(A,na);
	
	for(int i=na; i>0; i--) {
		n=mymax(A, i);
		myswap(A[n], A[i-1]);
	}
	cout<<"Упорядоченный массив:"; myout(A,na);
}
{title(nn++);
	int n; char ch;
	z13(n, ch);
}
{title(nn++);
	for(int i=0; i<24; i++)
		cout<<'-';
	cout<<endl;
	cout<<setw(6)<<'x'<<setw(16)<<"exp(x)\n";
	for(int i=0; i<24; i++)
		cout<<'-';
	cout<<endl;

	double x;
	for(x=0; x<=1; x+=0.1) {
		cout<<fixed<<setw(7)<<setprecision(1)<<x;
		cout<<setw(14)<<setprecision(5); cout<<myexp(x);	//здесь я добавил оператор cout для функции myexp
		cout<<endl;
	}
}
{title(nn++);
	double a=-173.40718;
	cout<<setprecision(5); dblout(a);

	int b=12;
	dblout(a, b);

	a=-173.4071835291; b=16; int c=10;
	dblout(a, b, c);
}
{title(nn++);
	int nx=10;
	int X[10]={64, 92, 19, 36, 73, 14, 19, 85, 79, 54};
	cout<<"Исходный массив: \n"; myout(X, nx);
	cout<<"Среднее геометричское = "<<arrGeo(X, nx)<<endl;
}
system("pause"); return 0;
}

void line1() {
	char ch = '-'; int n = 50;
	for (int i = 0; i < n; i++) cout << ch;
	cout<<endl;
}

void line2(int len, char c) {
	for (int i = 0; i < len; i++) cout << c;
	cout << endl;
}

void title(int n, int len1, int len2, char ch) {
	cout.flags(0); cout << endl;
	for (int i = 0; i < len1; i++) cout << ch;
	cout << " Задание №" << n << " ";
	for (int i = 0; i < len2; i++) cout << ch;
	cout << endl;
}

int nod(int m, int n) {
	int res;
	while (1) {
		if (m > n) {
			m %= n;
			if (!m) {
				res = n;
				break;
			}
		}
		else {
			n %= m;
			if (!n) { res = m; break; }
		}
	}
	return res;
}

bool QE (double a, double b, double c,
		 double &x1, double &x2)
{   bool out = false;
	double d = b*b-4*a*c;
	if(d>=0) {
		d = sqrt(d); x1 = (-b+d)/2/a; x2 = (-b-d)/2/a;
		out = true;
	}
	return out;
}

void fun5(double f, char ch, int i) {
	cout<<setw(6)<<f<<setw(6)<<ch<<setw(6)<<i<<endl;
}

void myswap(int &u, int &v) {
	if(u==v) return;
	int t=u; u=v; v=t;
}

void myswap(double &u, double &v) {
	if(u==v) return;
	double t=u; u=v; v=t;
}

void myswap(char &u, char &v) {
	if(u==v) return;
	char t=u; u=v; v=t;
}

void tmout(int h, int m, double s) {
	cout<<h<<"h:"
		<<setfill('0')
		<<setw(2)<<m<<"m:"
		<<fixed<<setprecision(2)<<setw(5)<<s<<"s\n"
		<<setfill(' ');
}

void tmout(int h, int m){
	cout<<h<<"h:"
		<<setfill('0')
		<<setw(2)<<m<<"m"<<endl
		<<setfill(' ');
}

void tmout(int m, double s) {
	cout<<setfill('0')
		<<setw(2)<<m<<"m:"
		<<fixed<<setprecision(2)<<setw(5)<<s<<"s\n"
		<<setfill(' ');
}

void myout(int M[], int nm, int nw) {
	for(int i=0; i<nm; i++)
		cout<<setw(nw)<<M[i];
	cout<<endl;
}

int mymax(int M[],int nm) {
	int mx  = M[0],
		imx = 0;
	for(int i=1; i<nm; i++)
		if(M[i]>mx) {
			mx=M[i]; imx=i;
		}
	return imx;
}

int mymin(int M[],int nm) {
	int mn  = M[0],
		imn = 0;
	for(int i=1; i<nm; i++)
		if(M[i]<mn) {
			mn=M[i]; imn=i;
		}
	return imn;
}

void z13(int& n, char& ch){
	 n=7; ch='*';
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(i==j)
				cout<<ch;
			else if(j==0)
				cout<<ch;
			else if(i==n-1)
				cout<<ch;
			else
				cout<<' ';
		cout<<endl;
	}

	n=12; ch='#';
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(i==j)
				cout<<ch;
			else if(j==0)
				cout<<ch;
			else if(i==n-1)
				cout<<ch;
			else
				cout<<' ';
		cout<<endl;
	}
}

double myexp(double x, double e){
	double y = 0,
		   a = 1;
	int	   i = 0; 
	while(abs(a)>e){
		y += a;
		a *= x/(i+1);
		i++;
	}
	return y;
}

void dblout(double a) {
	cout<<"без манипуляторов: \n"<<fixed<<a<<endl;
}

void dblout(double a, int b) {
	cout<<"setw=12: \n"<<fixed<<setw(b)<<a<<endl;
}

void dblout(double a, int b, int c) {
	cout<<"setw=16, setprecision=10: \n"<<fixed<<setw(b)<<setprecision(c)<<a;
}

double arrGeo (int X[] , int nx) {
	double res=1;
	for(int i=0; i<nx; i++)
		res *=X[i];
	return pow(res, 1./nx);
}