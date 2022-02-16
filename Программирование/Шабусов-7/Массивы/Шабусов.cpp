#include <iostream>
#include <iomanip>
using namespace std;
int nn=1;

void title(int, int=3, int=17, char='=');

void myrnd(int[], int, int, int);

void myrnd(double[], int, int, int);

void myout(int[], int, int=-1, int=4);

void myswap(int &, int &);

void mysrt(int[], int, bool=true);

void transp(int[][10], int);

void transp(int[][8], int);

int mymax(int[], int);

int mymin(int[], int);

int main() {
setlocale(LC_ALL, "rus");
srand(time(0));

{title(nn++);
	const int nv=100;
	int V[nv];
	const int nrows=20,
			  ncols=50;
	double M[nrows][ncols];
	cout<<"Размер массива V = "<<sizeof(V)<<endl;
	cout<<"Размер массива M = "<<sizeof(M)<<endl;
}
{title(nn++);
	const int nx=5; int X[nx];
	cout<<"Укажите количество входных данных (max="<<nx<<"): ";
	int n; cin>>n;
	for(int i=0; i<n; i++){
		if(i>=nx)
			break;
		cout<<"X["<<i<<"] = ";
		cin>>X[i];
	}
	cout<<"Ввод данных завершен\n";
}
{title(nn++);
	int Z[] = {13,5,0,-3,21,-8,0,7,0,-16,2,0,11,0,-15};
	int nz  = sizeof(Z)/sizeof(Z[0]);
	int sp  = 0, sn = 0,
		n   = 0;
	cout<<"Массив:";
	for(int i=0; i<nz; i++) {
		cout<<setw(4)<<Z[i];
		if(Z[i]>0)
			sp += Z[i];
		else if(Z[i]<0)
			sn += Z[i];
		else n++;
	}
	cout<<"\nСумма положительных  ="<<setw(4)<<sp
		<<"\nСумма отрицательных  ="<<setw(4)<<sn
	    <<"\nЧисло нулей          ="<<setw(4)<<n<<endl;
}
{title(nn++);
	int Z[] = {13,5,0,-3,21,-8,0,7,0,-16,2,0,11,0,-15};
	int nz  = sizeof(Z)/sizeof(Z[0]);
	int sp  = 0, sn = 0, 
		n   = 0;
	cout<<"Массив:";
	for(int i=0; i<nz; i++) {
		cout<<setw(4)<<Z[i];
		if(Z[i]>0) {
			sp+=Z[i];
			continue;
		}
		if(Z[i]<0) {
			sn+=Z[i];
			continue;
		}
		n++;
	}
	cout<<"\nСумма положительных  ="<<setw(4)<<sp
		<<"\nСумма отрицательных  ="<<setw(4)<<sn
	    <<"\nЧисло нулей          ="<<setw(4)<<n<<endl;
}
{title(nn++);
	const int nz = 5; int Z[nz];
	cout<<"Массив случайных чисел от -100 до 100:\n";
	for(int i=0; i<nz; i++){
		Z[i]= rand()%201 - 100;
		cout<<setw(5)<<Z[i];
	}
	cout<<endl;
}
{title(nn++);
	const int nx=20; double X[nx];
	cout<<"Массив случайных чисел от -3.000 до 5.000: \n";
	for (int i=0; i<nx; i++) {
		X[i] = (rand()%8001 - 3000) / 1000.;
		cout<<fixed<<setw(10)<<setprecision(3)<<X[i];
		if((i+1)%5==0)
			cout<<endl;
	}
}
{title(nn++);
	const int na = 20; int A[na];
	cout<<"Массив случайных одноразрядных чисел: \n";
	myrnd(A, na, -9, 9);
	for(int i=0; i<na; i++) cout<<setw(3)<<A[i];

	const int nb = 10; double B[nb]; cout<<"\n\n";
	cout<<"Массив случайных вещественных чисел от -37.82 до 69.54\n"
		<<"с двумя цифрами в дробной части:\n";
	myrnd(B, nb, -3782, 6954);
	for(int i=0; i<nb; i++) {
		B[i] /= 100.;
		cout<<fixed<<setw(7)<<setprecision(2)<<B[i];
	}
	cout<<endl;
}
{title(nn++);
	const int na = 21; int A[na];
	myrnd(A,na,-9,9);
	cout<<"Вывод в одну строку (4 знакоместа на число): \n";
	myout(A,na);
	myrnd(A,na,-99,99);
	cout<<"Вывод в 6 столбцов (5 знакомест на число): \n";
	myout(A,na,6,5);
	myrnd(A,na,-999,999);
	cout<<"\nВывод в 7 столбцов (8 знакомест на число): \n";
	myout(A,na,7,8);
}
{title(nn++);
	int M[5]={3,7,2,5,0};
	cout<<"Исходный массив:     "; myout(M, 5);
	if(M[0]>M[1]) myswap(M[0],M[1]);
	if(M[1]>M[2]) myswap(M[1],M[2]);
	if(M[2]>M[3]) myswap(M[2],M[3]);
	if(M[3]>M[4]) myswap(M[3],M[4]);
	myout(M,5);
	if(M[0]>M[1]) myswap(M[0],M[1]);
	if(M[1]>M[2]) myswap(M[1],M[2]);
	if(M[2]>M[3]) myswap(M[2],M[3]);
	myout(M,5);
	if(M[0]>M[1]) myswap(M[0],M[1]);
	if(M[1]>M[2]) myswap(M[1],M[2]);
	myout(M,5);
	if(M[0]>M[1]) myswap(M[0],M[1]);
	myout(M,5);
	cout<<"Упорядоченный массив:"; myout(M,5);
}
{title(nn++);
	const int na=10; int A[na]={6,-5,7,2,-7,-3,8,5,0,4};
	cout<<"Исходный массив:          "; myout(A,na);
	for(int i=na; i>1; i--)
		for(int j=0; j<i-1; j++)
			if(A[j]>A[j+1]) myswap(A[j],A[j+1]);
	cout<<"Сортировка по возрастанию:"; myout(A,na);
	cout<<"Сортировка по убыванию:   "; mysrt(A,na,false); myout(A,na);
}
{title(nn++);
	const int nrows = 3, ncols = 5;
	int A[nrows][ncols] = {
		{ 31,  74, -58,   7,  16},
		{ 74,  26, -59, -61, -96},
		{-88,   7,  14,  85,  -8}
	};
	cout<<"Исходная матрица A:\n";
	for (int i=0; i<nrows; i++) {
		for (int j=0; j<ncols; j++)
			cout<<setw(5)<<A[i][j];
		cout<<endl;
	}
	int mx=A[0][0], imx=0, jmx=0;
	for(int i=0; i<nrows; i++)
		for(int j=0; j<ncols; j++)
			if(A[i][j]>mx){
				mx=A[i][j]; imx=i; jmx=j;
			}
	cout<<"Максимальный элемент A["<<imx<<"]["<<jmx<<"] = "<<mx;
	cout<<endl;
}
{title(nn++);
	const int nrows = 3, ncols = 5;
	int A[nrows][ncols], B[nrows][ncols];
	for(int i=0; i<nrows; i++) {
		myrnd(A[i],ncols,-99,99);
		myrnd(B[i],ncols,-99,99);
	}
	cout<<"Матрицы A и B:\n";
	for(int i=0; i<nrows; i++) {
		myout(A[i], ncols, ncols+1);
		cout<<"         ";
		myout(B[i], ncols);
	}
	cout<<"Сумма матриц A+B:\n";
	for(int i=0; i<nrows; i++){
		for(int j=0; j<ncols; j++)
			cout<<setw(5)<<(A[i][j]+B[i][j]);
		cout<<endl;
	}

}
{title(nn++);
	const int nr = 20;
	const int nc=10;
	int A[nr][nc];
	int m=3;
	for(int i=0; i<m; i++)
		myrnd(A[i], m, -9, 9);
	cout<<"Исходная матрица 3х3:"<<endl;
	for(int i=0; i<m; i++) myout(A[i], m);
	transp(A,m);
	cout<<"Транспонированная матрица 3х3:"<<endl;
	for(int i=0; i<m; i++) myout(A[i],m);
	m=10;
	for(int i=0; i<m; i++)
		myrnd(A[i], m, -9, 9);
	cout<<"Исходная матрица 10х10:"<<endl;
	for(int i=0; i<m; i++) myout(A[i], m);
	transp(A,m);
	cout<<"Транспонированная матрица 10х10:"<<endl;
	for(int i=0; i<m; i++) myout(A[i],m);
}
{title(nn++);
	int X[] = {31, 24, 17, 36, 13, 27, 14, 22, 16, 39,
			   27, 20, 13, 25, 41, 32, 19, 17, 34, 28};
	int nx=sizeof(X)/sizeof(X[0]);
	cout<<"Исходный массив:\n"; myout(X, nx);
	int mx = X[0]+X[1]+X[2],
		mn = mx,
		imx = 0, imn = 0;
	for(int i=1; i<nx-2; i++) {
		int sum = X[i]+X[i+1]+X[i+2];
		if(sum>mx) {
			mx=sum; imx=i;
		}
		else if(sum<mn) {
			mn=sum; imn=i;
		}
	}
	cout<<"\nНаибольшая сумма трех соседних элементов: "
		<<X[imx]<<'+'<<X[imx+1]<<'+'<<X[imx+2]<<" = "<<mx;
	cout<<"\nНаименьшая сумма трех соседних элементов: "
		<<X[imn]<<'+'<<X[imn+1]<<'+'<<X[imn+2]<<" = "<<mn;
	cout<<endl;
}
{title(nn++);
	const int nv=5; int V[nv];
	int n;
	while(1){
		cout<<"Введите количество оценок (max="<<nv<<"): ";
		cin>>n;
		if(n<=nv) break;
		else cout<<"Ошибка! \n";
	}
	for(int i=0; i<n; i++) {
		cout<<"Оценка №"<<i+1<<" = ";
		cin>>V[i];
		if(V[i]<1 || V[i]>10) {
			cout<<"Ошибка! \n";
			i--;
		}
	}
	int sum=0;
	for(int i=0; i<n; i++) sum+=V[i];
	cout<<"\nСредняя экзаменационная оценка = "<<1.*sum/n<<endl;
}
{title(nn++);
	const int nr=8; int A[nr][nr];
	cout<<"Матрица A:\n";
	for(int i=0; i<nr; i++) myrnd(A[i], nr, 100, 999);
	for(int i=0; i<nr; i++) myout(A[i],nr,nr,6);
	int M[nr];
	transp(A,nr);
	for(int i=0; i<nr; i++)
		M[i]=A[i][mymin(A[i],nr)];
	transp(A,nr);
	cout<<"Минимумы столбцов:\n"; myout(M,nr,nr,6);
	cout<<"Максимум минимумов столбцов:\n";
	cout<<setw(6)<<M[mymax(M,nr)]<<endl;
}
{title(nn++);									//решенное задание 17
	const int n = 21; int A[n][n] = {};
	int i = n/2, j = n/2, k = 1; A[i][j] = k;
	while(1) {
		int i0 = i, j0 = j,
			r = rand()%4;
		if(r==1)      i0--;
		else if(r==2) j0++;
		else if(r==3) i0++;
		else		  j0--;
		if(A[i0][j0]==0) {
			i = i0; j = j0;
			A[i][j]=++k;
			if(i==0||i==n-1||j==0||j==n-1)
				    break;
			if(A[i+1][j]!=0 && A[i-1][j]!=0 &&
			   A[i][j+1]!=0 && A[i][j-1]!=0)
					break;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			if(A[i][j]!=0) cout<<setw(3)<<A[i][j];
			else    cout<<"   ";
		cout<<endl;
	}
}

system("pause"); return 0;
}

void title(int nn, int a, int b, char ch) {
	for(int i=0; i<a; i++) cout<<ch;
	cout<<" Задание "<<nn<<' ';
	for(int i=0; i<b; i++) cout<<ch;
	cout<<endl;
}

void myrnd(int M[], int nm, int rmin, int rmax){
	for(int i=0; i<nm; i++)
		M[i] = rmin + rand()%(rmax-rmin+1);
}

void myrnd(double M[], int nm, int rmin, int rmax){
	for(int i=0; i<nm; i++)
		M[i] = rmin + rand()%(rmax-rmin+1);
}

void myout(int M[], int nm, int nc, int nw){
	if(nc<=0)
		nc = nm;
	for(int i=0; i<nm; i++){
		cout<<setw(nw)<<M[i];
		if((i+1)%nc == 0)
			cout<<endl; }
}

void myswap(int &u, int &v) {
	if(u==v) return;
	int t=u; u=v; v=t;
}

void mysrt(int X[], int nx, bool inc){
	if(inc){
		for(int i=nx; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(X[j]>X[j+1])
					myswap(X[j],X[j+1]);
	}
	else{
		for(int i=nx; i>1; i--)
			for(int j=0; j<i-1; j++)
				if(X[j]<X[j+1])
					myswap(X[j],X[j+1]);
	}
}

void transp(int M[][10], int n){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			myswap(M[i][j],M[j][i]);
}

void transp(int M[][8], int n){
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			myswap(M[i][j],M[j][i]);
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