#include <iostream>
#include <iomanip>
#include <conio.h>
#include <consoleapi.h>

using namespace std;

int nn=1;

void title(int, int=3, int=17, char='=');

void binout(int, char='\n');

void binout(char, char='\n');

void binout(short, char='\n');

void binout(long long, char='\n');

bool realequal(float, float, double=1e-6);

bool realequal(double, double, double=1e-12);

enum colors {
		 black,      blue,
		 green,      cyan,
		 red,		 magenta,
		 brown,		 lightgray,
		 darkgray,	 lightblue,
		 lightgreen, lightcyan,
		 lightred,   lightmagenta,
		 yellow,	 white
	};

void getcolor(colors&, colors&);

void setcolor(colors, colors);

int main() {
setlocale(LC_ALL, "rus");
{title(nn++);
	unsigned char n=0;
	//short n=0;
	int nmin, nmax;
	int m = sizeof(n);
	cout<<"Размер памяти для данных типа "
		<<typeid(n).name()
		<<" = "<<m<<" байт"
		<<(m>1 && m<5 ? "а" : "")<<endl;
	while(1){
		n++;
		if(n<=0) {
			nmin = n;
			nmax = --n;
			break;
		}
	}
	cout<<"Числовой диапазон данных типа "<<typeid(n).name()
		<<": от "<<nmin<<" до "<<nmax<<endl;
}
{title(nn++);
	char      a = 100;
	short     b = 10000;
	int       n = 1000000000;
	long long c = 1000000000000000000;
	cout<<setw(19)<<1*a<<" = "; binout(a);
	cout<<setw(19)<<b<<" = "; binout(b);
	cout<<setw(19)<<n<<" = "; binout(n);
	cout<<setw(19)<<c<<" = \n"; binout(c);
}
{title(nn++);
	short m = 923, n = 21707;
	short a = m & n, b = m | n, c = m ^ n;
	cout<<"a = "<<m<<" & "<<n<<" = "; binout(a);
	cout<<"b = "<<m<<" | "<<n<<" = "; binout(b);
	cout<<"c = "<<m<<" ^ "<<n<<" = "; binout(c);
}
{title(nn++);
	short n = 18294; binout(n);
	cout<<"Применяем ~, <<5, >>2:\n";
	n = ~n; n = n<<5; n = n>>2; binout(n);
}
{title(nn++);
	char n = 75; binout(n);
	cout<<"Устанавливаем четвертый бит:\n";
	char k = 1; k = k<<4; n = n | k; binout(n);
}
{title(nn++);
	char n = 75; binout(n);
	cout<<"Сбрасываем шестой бит:\n";
	char k = 1; k = k<<6; k = ~k; n = n & k; binout(n);
}
{title(nn++);
	char k = 75; binout(k);
	cout<<"Инверсия второго и третьего битов:\n";
	char n = 3; n = n<<2; k = k^n; binout(k);
}
{title(nn++);
	char n = 75; binout(n); char k = 1;
	cout<<"Бит №5 = "<<(n & (k<<5) ? 1 : 0)<<endl;
	cout<<"Бит №6 = "<<(n & (k<<6) ? 1 : 0)<<endl;
}
{title(nn++);
	short n = -5718;
	cout<<"n = "<<n<<" = "; binout(n);

	n = abs(n); n = ~n; n++;
	binout(n);
}
{title(nn++);
	short n = -12805; cout<<"Двоичное представление числа: "; binout(n);
	n--; n = ~n; n = -n;
	cout<<"Десятичное представление числа: "<<n<<endl;
}
{title(nn++);
	short k1 = 30, k2 = -1707; short r = k1 | k2;
	 cout<<k1<<" | "<<k2<<" = "<<r<<endl;
}
{title(nn++);
	short k1 =  30, r1 = ~k1;
	char  k2 = -42, r2 = k2>>2;
	cout<<'~'<<k1<<" = "<<r1<<endl
		<<short(k2)<<">>2 = "<<short(r2)<<endl;
}
nn++;
{title(nn++);
	float a=0, b=1, h=0.1, x=a; cout<<fixed;
	while(1){
		cout<<setw(4)<<setprecision(1)<<x
			<<setw(12)<<setprecision(5)<<sin(x)<<endl;
		if(realequal(x,b))
			break;
		x += h;
	}
	cout<<"Задание №14c\n";
	double c=0, d=1, h2=0.1, y=c; cout<<fixed;
	while(1){
		cout<<setw(4)<<setprecision(1)<<y
			<<setw(12)<<setprecision(5)<<sin(y)<<endl;
		if(realequal(y,d))
			break;
		y += h2;
	}
}
nn=17;
{title(nn++);
	int n = 1803521649;
	cout<<"Исходное число: "; binout(n);
	for(int i=29; i>=0; i--){
		int k1 = 1 << i;
		int k2 = 1 << i+1;
		int k3 = 1 << i+2;
		if((n & k1) && (n & k2) && (n & k3))
		{
			cout<<"Разряды первой слева комбинации цифр 111: "
				<<i+2<<" "<<i+1<<" "<<i<<endl;
			break;
		}
	}
}
{title(nn++);
	char a = 'z', b = 75;
	cout<<a<<' '<<b<<' '<<a*1<<' '<<b+0<<endl;
	a = 122; b = 'K';
	cout<<(char)a<<' '<<(char)b<<' '<<(int)a<<' '<<(int)b<<endl;
}
cout<<"\nВыполнить задание 19(y/n)?\n";
if(_getch()=='y')
{cout<<"\n=== Задание 19 =================\n";
	cout<<setfill('0');
	char ch = 0;
	for(int i=0; i<16; i++) {
		cout<<setw(3)<<i*16<<".."
			<<setw(3)<<i*16+15<<"| ";
		for(int j=0; j<16; j++){
			if (ch== 7 || ch==9  ||
				ch==10 || ch==13 ||
				ch==(char)149      )
				cout<<' ';
			else
				cout<<ch;
			cout<<' ';
			ch++;
		}
		cout<<endl;
	}
	cout<<setfill(' ');
}
cout<<"\nВыполнить задание 20(y/n)?\n";
if(_getch()=='y')
{cout<<"\n=== Задание 20 =================\n";
	const int ns=32; char S[ns];
	for(int i=0; i<ns; i++) S[i] = '*';
	cout<<"Ввод текста в строку S:\n";
	//cin>>S;
	cin.getline(S,ns);
	cout<<"Строка S:\n";
	for(int i=0; i<ns; i++)
		if(S[i]>=0 && S[i]<=31)
			cout<<'\\'<<(int)S[i];
		else
			cout<<S[i];
	cout<<"\nstrlen(S) = "
		<<strlen(S)<<endl;
	for(int i=0; i<ns; i++)
		if(S[i]==0) {cout<<"Длина строки = "<<i; break;}
}
cout<<"\nВыполнить задание 21(y/n)?\n";
if(_getch()=='y')
{cout<<"\n=== Задание 21 =================\n";
	const int snum=10,
			  slen=16;
	char S1[snum][slen] = {
		"нуль",   "один",  "два",  "три",    "четыре",
		"пять",  "шесть", "семь", "восемь", "девять"
	};
	int n=1;
	while(n) {
		cout<<"n = "; cin>>n;
		if(n<0) {
			cout<<"минус ";
			n=-n;
		}
		n = n % 10;
		cout<<S1[n]<<endl;
	}
}
cout<<"\nВыполнить задание 22(y/n)?\n";
if(_getch()=='y')
{cout<<"\n=== Задание 22 =================\n";
	const int snum=10,
			  slen=16;
	char S1[snum][slen] = {
		"нуль",  "один",  "два",  "три",    "четыре",
		"пять",  "шесть", "семь", "восемь", "девять" };
	char S2a[snum][slen] = {
		"десять",  "одиннадцать",  "двенадцать",  "тринадцать",
		"четырнадцать", "пятнадцать", "шестнадцать", "семнадцать",
		"восемнадцать", "девятнадцать" };
	char S2b[snum][slen] = {
		"двадцать ", "тридцать ",  "сорок ",  "пятьдесят ",
		"шестьдесят ", "семьдесят ", "восемьдесят ", "девяносто " };
	char S3[snum][slen] = {
		"сто ", "двести ", "триста ", "четыреста ", "пятьсот ",
		"шестьсот ", "семьсот ", "восемьсот ", "девятьсот " };
	const int ns=64; char s[ns];
	int n=1;
	while(n) {
		cout<<"n = "; cin>>n;
		strcpy(s,"");
		if(n<0) {
			strcpy(s,"минус ");
			n = -n;
		}
		int n1 = n%10, n2 = n/10%10, n3 = n/100%10;
		if(n3>0)
			strcat(s,S3[n3-1]);
		if(n2==1)
			strcat(s,S2a[n2]);
		else if(n2>1)
			strcat(s,S2b[n2-2]);
		if(n1>0 && n2!=1)
			strcat(s,S1[n1]);
		cout<<s<<endl;
	}
}
nn=23;
{title(nn++);
	int b1 = 15<0xF, b2 = 0x25, res;
	cout<<"res = "<<(res = b1 || b2 && 10)<<endl;
}
{title(nn++);
	enum coins {penny=1,    nickel=5, dime=10,
				quarter=25, half=50,  dollar=100};
	coins  coin1, coin2, coin3;
	coin1 = dime;
	coin2 = nickel;
	coin3 = penny;
	cout<<"Один dime равен "
		<<coin1/coin2<<" nickel и "
		<<coin1/coin3<<" penny\n";
	coins C[3];
	C[0] = half;
	C[1] = quarter;
	C[2] = nickel;
	int N[3] = {74, 51, 162},
		sum = 0;
	for(int i=0; i<3; i++)
		sum += N[i]*C[i];
	cout<<"Сумма равна "
		<<sum / dollar<<" долларов и "
		<<sum % dollar<<" центов\n";

	coin1 = quarter;
	//coin1 = 25;	//ошибка, так как переменным перечисляемого типа можно присваивать лишь те именованные константы, которые входят в перечисление
	coin2 = dollar;
	//coin2 = "dollar";	//вновь ошибка, так как переменным перечисляемого типа можно присваивать лишь те именованные константы, которые входят в перечисление
}
{title(nn++);
	colors text0,
		   back0;
	getcolor(text0, back0);
	setcolor(lightgreen, yellow);
	cout<<"светло-зеленый текст на желтом фоне";
	setcolor(text0, back0);cout<<endl;
	setcolor(lightred, white);
	cout<<"светло-красный текст на белом фоне";
	setcolor(text0, back0);cout<<endl;
	cout<<"исходные цвета восстановлены\n";
}
nn++; 		//так как задания 26 нет
{title(nn++);
	const int nv=5; int V[nv]={6,9,4,7,8}, sum=0;
	for (int i=0; i<nv; i++) sum +=V[i];
	cout<<"средняя оценка = "<<sum/nv<<endl;
	cout<<"средняя оценка = "<<1.*sum/nv<<endl;
	cout<<"средняя оценка = "<<(double)sum/nv<<endl;
}
{title(nn++);
	float f=100.5;
	cout<<(int)f/6<<' '<<(int)f/6.<<' '<<f/6<<' '<<f/6.<<endl;
}
{title(nn++);
	char c; short s; int i; float f;
	s=0x2b72; i=0x41d57a63;
	cout<<"1) "<<(int)(c=s)<<" "; cout<<(int)(c=i)<<endl;
	i=0x610d71a3;
	cout<<"2) "<<(s=i)<<endl;
	f=117.6204;
	cout<<"3) "<<(int)(c=f)<<" "; cout<<(s=f)<<" "; cout<<(i=f)<<endl;
	c=89; s=28904; i=1234512345;
	cout<<"4) "<<(f=c)<<" "; cout<<(f=s)<<" "; cout<<(f=i)<<endl;	//у меня код точно такой же, как у Вас, но вывод в четвертой строке отличается.
}

system("pause"); return 0;
}

void title(int nn, int a, int b, char ch) {
	for(int i=0; i<a; i++) cout<<ch;
	cout<<" Задание "<<nn<<' ';
	for(int i=0; i<b; i++) cout<<ch;
	cout<<endl;
}

void binout(int n, char ch){
	int nd = sizeof(n)*8;
	unsigned int m = n;
	unsigned int k = 1;
	for(int i=nd-1; i>=0; i--){
		cout<<(m&(k<<i)?1:0);
		if(i && i%8==0) cout<<' ';
	}
	cout<<ch;
}

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

void binout(short n, char ch){
	int nd = sizeof(n)*8;
	unsigned short m = n;
	unsigned short k = 1;
	for(int i=nd-1; i>=0; i--){
		cout<<(m&(k<<i)?1:0);
		if(i && i%8==0) cout<<' ';
	}
	cout<<ch;
}

void binout(long long n, char ch){
	int nd = sizeof(n)*8;
	unsigned long long m = n;
	unsigned long long k = 1;
	for(int i=nd-1; i>=0; i--){
		cout<<(m&(k<<i)?1:0);
		if(i && i%8==0) cout<<' ';
	}
	cout<<ch;
}

bool realequal(float a, float b, double e){
	if(abs(a-b)<e) return true;
	else return false;
}

bool realequal(double a, double b, double e){
	if(abs(a-b)<e) return true;
	else return false;
}
void getcolor(colors &text, colors &background) {
    CONSOLE_SCREEN_BUFFER_INFO sbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &sbi);
	int n = sbi.wAttributes; 
	text = (colors)(n%16); background = (colors)(n/16%16); 
}

void setcolor(colors text, colors background) {
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(hStdOut, (WORD)((background<<4)|text));
}