/*==========================================
 Программа лабораторной работы №3 построена
         студнетом первого курса 
	      Шабусовым Владиславом
==========================================*/

//-- Заголовочная часть программы-----
#include <iostream>
#include <iomanip>

using namespace std;


// Главная функция программы-------
int main()
{
	setlocale(LC_ALL, "rus");
{	cout << "==== Задание №1 ======" << endl;
	int n;
	cout<<"Введите номер искомого числа: "; /*cin >> n;*/
	n=8; cout<<n<<endl;
	int a=0, b=1, c=a+b; int i=2;
	a=b; b=c; c= a+b; i=i++;  //C=F3, i=3
	a=b; b=c; c= a+b; i=i++;  //C=F4, i=4
	a=b; b=c; c= a+b; i=i++;  //C=F5, i=5
	a=b; b=c; c= a+b; i=i++;  //C=F6, i=6
	a=b; b=c; c= a+b; i=i++;  //C=F7, i=7
	a=b; b=c; c= a+b; i=i++;  //C=F8, i=8

	cout<<"Число Фибоначчи № "<<n<<" = "<<c<<endl;

	a=0; b=1; c=a+b; i=2; n=24;
	while(i<n)
	{
		a=b; b=c; c=a+b; i++; //c=Fi
	}
	cout<<"Число Фибоначчи № "<<n<<" = "<<c<<endl;
}
	
//--- Выход из главной функции-----
{	cout<<"===Задание 2========="<<endl;
	double x1, y1, x2, y2, x3, y3;
	cout<<"Введите координаты вершин треугольника: "<<endl;
	//cin>>x1>>y1>>x2>>y2>>x3>>y3;   //Вводим координаты вершин
	x1=3.5; y1=7.1; x2=6.8; y2=-5.4; x3=-8.2; y3=-4.7;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;

	double a, b, c;  //Вычисляем длины сторон
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	double p, s;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"Периметр треугольника = "<<p*2<<endl;
	cout<<"Площадь треугольника = "<<s<<endl;
	
}

{	cout<<"==Задание 3========="<<endl;
	int num;  //cin>>num;
	cout<<"Введите число: ";//cin>>num;
	num=1759543401; cout<<num<<endl;
	const int nd = 10;
	int D[nd] = {2,3,5,7,11,13,17,19,23,29}; int i=0;
	if(num % D[i] == 0)          //Проверяем делимость на 2
	{
		cout<<"Число"<<num<<" делится на "<<D[i]<<endl;
	}
	i++;

	if(num % D[i] == 0)          //Проверяем делимость на 3
	{
		cout<<"Число"<<num<<" делится на "<<D[i]<<endl;
	}
	i++;

	if(num % D[i] == 0)          //Проверяем делимость на 5
	{
		cout<<"Число"<<num<<" делится на "<<D[i]<<endl;
	}
	i++;

	while(i<nd)
	{
		if(num % D[i] == 0)         //Проверяем делиость на D[i]
		{
			cout<<"Число"<<num<<" делится на "<<D[i]<<endl;
		}
        i++;
	}
}

{	cout << "===Задание 4===========" << endl;
	const double pi = acos(-1);
	double x, k1, k2;
	cout << "Введите значения аргумента и двух коэффициентов:" << endl;
	//cin>>x>>k1>>k2
	x = 1.4; k1 = 6; k2 = 5 / 3.; cout << x << " " << k1 << " " << k2 << endl << endl;

	double a = pi / k1, b = pi / k2; double res;
	res = pow(abs((-5 * pow(x, 4)*sin(a) + 4 * x*x*cos(b)*cos(b)) /
		          (2 * pow(cos(a + b), 4) + 1)), 1 / 3.);

	double p, q;				//переменные для промежуточных данных
	p = (-5 * pow(x, 4)*sin(a) + 4 * x*x*cos(b)*cos(b));
	q = (2 * pow(cos(a + b), 4) + 1);
								//вывод промежуточных данных
	cout <<"Числитель подкоренного выражения   = "<< fixed << setw(16) << setprecision(6) << right << p << endl;
	cout << "Знаменатель подкоренного выражения =  " << scientific << setw(15) << setprecision(6) << right << q << endl << endl;
	res = pow(abs(p / q), 1 / 3.);

								//неформатированный вывод
	cout << "Значение выражения = " << res << endl;

								//форматированный вывод
	cout << "Значение выражения = "
		<< fixed				//вывод числа с фиксированной точкой
		<< setw(18)				//выделить для всего числа 18 знакомест
		<< setprecision(8)		//выделить для дробной части 8 знакомест
		<< left					//выравнивание по левому краю
		<< res					//вывод результата
		<< endl;				//переход на следующую строку

	cout << "Значение выражения = "
		<< scientific			//вывод числа с плавающей точкой
		<< setw(22)				//выделить для всего числа 22 знакоместа
		<< setprecision(10)		//выделить для дробной части 10 знакомест
		<< right				//выравнивание по правому краю
		<< res					//вывод результата
		<< endl;				//переход на следующую строку


}
{   cout<<"===Задание 5============"<<endl;
	const int nv=5; int V[nv]={7,9,6,9,8};
	int sum, i; sum=i=0;
	//sum+= V[i]; i++;       //+V[0]
	//sum+= V[i]; i++;       //+V[1]
	//sum+= V[i]; i++;       //+V[2]
	//sum+= V[i]; i++;       //+V[3]
	//sum+= V[i]; i++;       //+V[4], i=nv=5

	while(i<nv){
		sum +=V[i]; i++;
}

	int mx, mn; mx=mn=V[0]; 	i=1;

	//if(V[i]>mx)							//сравнение с V[1]
	//	mx=V[i];
	//
	//i++;	
	//if(V[i]>mx)							//сравнение с V[2]
	//	mx=V[i];
	//
	//i++;
	//if(V[i]>mx)							//сравнение с V[3]
	//	mx=V[i];
	//
	//i++;	
	//if(V[i]>mx)							//сравнение с V[4], i=nv=5
	//	mx=V[i];
	//
	//i++;	

	while(i<nv){
		if(V[i]>mx)							//сравнение с V[i]
			mx=V[i];
		i++;}

	i=1;
	//if(V[i]<mn)							//сравнение с V[1]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//сравнение с V[2]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//сравнение с V[3]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//сравнение с V[4]
	//	mn=V[i];
	//
	//i++;									//i=nv=5

	while(i<nv){
		if(V[i]<mn)							//сравнение с V[i]
			mn=V[i];
		i++;}

	cout<<fixed<<left<<setprecision(2);		//формат вывода
	cout<<"Максимальная оценка = "<<mx<<endl;
	cout<<"минимальная оценка  = "<<mn<<endl;
	cout<<"Средняя оценка      = "<<1.*sum/nv<<endl;

}

{ cout<<"===Задание 6============"<<endl;
 const int maxlen=32;
 char s[maxlen]="11011101001101011001";
 int ns=strlen(s), num=0, i=ns-1, weight=1;

 if(s[i]=='1')								//s[19] - разряд 0
	 num+=weight;
 i--; weight*=2;
 if(s[i]=='1')								//s[18] - разряд 1
	 num+=weight;
 i--; weight*=2;
 if(s[i]=='1')								//s[17] - разряд 2
	 num+=weight;
 i--; weight*=2;
 while(i>=0){
	 if(s[i]=='1')							//s[i] - разряд ns - i - 1
	 num+=weight;
 i--; weight*=2;
 }
 cout<<"Десятичное значение "<<s<<" = "<<num<<endl;
}
	cout << endl; system("pause");
	return 0;
}