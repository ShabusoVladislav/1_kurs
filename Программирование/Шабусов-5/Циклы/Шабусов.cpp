#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
	{cout<<"==== Задание 1 ==========\n";
	 int n=100, sum=0, i=1; //cin>>n;
	 cout<<"n = "<<n<<endl; //присваивание вместо cin
	 while (i<=n) {  //выполнять, пока i не превышает n
		 sum+=i;
		 i++;
	 }
	 cout<<"Сумма 1+2+...+"<<n<<" = "<<sum<<endl;
	}
	{cout << "==== Задание 2 ==========\n"; cout.flags(0);
	 int n=100, sum=0, i=1;
	 cout<<"n="<<n<<endl;
	 while (i<=n)
		 sum+=++i;
	cout<<"Сумма 2+3+...+"<<n+1<<" = "<<sum<<endl;
	}
	{cout<<"==== Задание 3 ==========\n"; cout.flags(0);
	 const int na = 10;
	 int A[na] = {4,2,0,8,0,4,9,-3,5,-1};
	 int i = 0;
	 while (A[i]>=0 && i++<na);
	 cout<<"Первый отрицательный элемент массива A["<<i<<"] = "
		 <<A[i]<<endl;
	}
	{cout<<"==== Задание 4 ==========\n"; cout.flags(0);
	 double x = 1.5,
		    sum = 0,
			a = 1;
	int     i = 0,
		    n = 30;
	cout<<"x = "<<x<<", n = "<<n<<endl;

	while (i<=n) {
		sum+=a;
		a*=-x;
		i++;
	}
	cout<<"Сумма = "<<fixed<<setprecision(4)<<sum<<endl;
	}
	{cout << "==== Задание 5 ==========\n"; cout.flags(0);
	 double x = 5,
			sum = 0,
			a = 1,
			e = 1e-9,
			b = 1;
	int		i = 0;
	cout << "x = " << x << ", e = " << e << endl;

	while (abs(a) > e) {
		sum += a;
		b *= -x*x / (2 * i + 1) / (2 * i + 2);
		a = b*cos((i+1)*x);
		i++;
	}
	cout << "Сумма = " << fixed << setprecision(9) << sum << endl;
	}
	{cout << "==== Задание 6 ==========\n"; cout.flags(0);
	const int na = 32; int A[na];
	int i = 0;

	do {
		cin >> A[i];
		if (A[i] == 0) break;
		i++;
	} while (i < na);
	cout << "Ввод массива заверешен\n";
	}
	{cout << "==== Задание 7 ==========\n"; cout.flags(0);
	int n = 1305709, m = 8;
	const int na = 32; int A[na];
	int i = 0;
	cout << n << "(10) = ";
	do {
		A[i] = n % m;
		n = n / m;
		if (n == 0) break;
		i++;
	} while (i < na);

	do {
		cout << A[i];
		i--;
	} while (i >= 0);
	cout << "(" << m << ")\n";
	}
	{cout << "==== Задание 8 ==========\n"; cout.flags(0);
	int n = 10, p = 1;
	for (int i = 2; i <= n; i++)
		p *= i;
	cout << n << "! = " << p << endl;
	}
	{cout << "==== Задание 9 ==========\n"; cout.flags(0);
	int n = 50; cout << "n = " << n << endl;
	int i;

	for (i = 1; i <= n; i++) {
		cout << "(" << setw(2) << i << "," << setw(6) << i*i*i << ")   ";
		if (i % 5 == 0) cout << endl;
	}
	}
	{cout << "==== Задание 10 ==========\n"; cout.flags(0);
	double a = 0, b = 1, h = 0.1;
	cout << "Введите a, b, h: "
		<< a << " " << b << " " << h << endl;
	for (int i = 0; i < 24; i++) cout << "-";
	cout << "\n    x           y        \n";
	for (int i = 0; i < 24; i++) cout << "-";

	for (double x = 0; x <= 1; x += h)
		cout<<endl<<fixed
			<<setw(6) << setprecision(1) << x
			<<setw(14)<< setprecision(6) << sin(x);
	}
	{cout << "\n==== Задание 11 ==========\n"; cout.flags(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			cout << "*";
		}
		cout << endl;
	}
	}
	{cout << "\n==== Задание 12 ==========\n"; cout.flags(0);
	int n = 10; cout << "n = " << n << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == 2 * n - 1)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	}
	system("pause"); return 0;
}