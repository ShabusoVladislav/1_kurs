#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
using namespace std;

void transp(int** M, int nr);	//транспонирование статической квадратной матрицы

void sum(double** M, int nr, int nc, double* X);	//вычисляет суммы строк матрицы M и помещает их в массив X

int main(){
setlocale(LC_ALL, "rus");
srand(time(0));
{cout<<"=== Задание 1 =================\n";
	const int nr = 5, nc = 10;
	int M[nr][nc];
	myrnd(M[0],nr*nc,-99,99);
	cout<<"Исходная матрица:\n";
	for(int i=0; i<nr; i++)
		myout(M[i],nc);
	int k1 = 1, k2 = 4;
	cout<<"Индексы переставляемых строк: "<<k1<<" "<<k2<<endl;
	//int *p; p=M[k1]; M[k1]=M[k2]; M[k2]=p;	//ошибка!
	int *P[nr];
	for(int i=0; i<nr; i++)
		P[i] = M[i];
	int *p; p=P[k1]; P[k1]=P[k2]; P[k2]=p;
	cout<<"Итоговая матрица:\n";
	for(int i=0; i<nr; i++)
		myout(P[i],nc);
}
{cout<<"=== Задание 2 =================\n";
	const int nr=5, nc=10; int M[nr][nc];
	myrnd(M[0],nr*nc,-99,99);
	cout<<"Исходная матрица:\n";
	for(int i=0; i<nr; i++) myout(M[i],nc);
	int X[nr];
	for(int i=0; i<nr; i++)
		X[i] = M[i][nc-1];
	int*P[nr];
	for(int i=0; i<nr; i++)
		P[i] = M[i];
	mysrt(X,nr,1,P);
	cout<<"Итоговая матрица:\n";
	for(int i=0; i<nr; i++)
		myout(P[i],nc);
}
{cout<<"=== Задание 4 =================\n";
	const int nr=5; int M[nr][nr];
	myrnd(M[0],nr*nr,-9,9);
	cout<<"Исходная матрица:\n"; myout(M[0],nr*nr,nr);
	int *A[nr],
		size[nr];
	for(int i=0; i<nr; i++) {
		size[i]=i+1;
		A[i] = new int[size[i]];
		for(int j=0; j<=i; j++)
			A[i][j] = M[i][j];
	}
	cout<<"Нижний треугольник матрицы:\n";
	for(int i=0; i<nr; i++) myout(A[i],size[i]);
	for(int i=0; i<nr; i++) delete[]A[i];
}
{cout<<"=== Задание 5 =================\n";
	float x = 2.2; float* p1 = &x; float** p2 = &p1;
	cout<<"Ячейка x  имеет адрес "<<*p2<<" и содержит значение "<<**p2<<endl;
	cout<<"Ячейка p1 имеет адрес "<<p2<<" и содержит значение "<<*p2<<endl;
	cout<<"Ячейка p2 имеет адрес "<<&p2<<" и содержит значение "<<p2<<endl;
}
{cout<<"=== Задание 6a =================\n";
	char* s = new char[128];
	int nedg = myinput(s,"11.6.txt");
	int**edg = new int*[nedg];
	int nver = 0;
	char*p = s;
	for(int i=0; i<nedg; i++){
		edg[i] = new int[2];
		int beg = atoi(p);
		p += mycspn(p," ");
		int end = atoi(p);
		if(beg>nver) nver=beg;
		if(end>nver) nver=end;
		edg[i][0] = beg;
		edg[i][1] = end;
		p += mylen(p)+1;
	}
	cout<<"Количество вершин графа = "<<nver<<endl;
	cout<<"Количество ребер графа = "<<nedg<<endl;

cout<<"=== Задание 6b =================\n";
	int**N = new int*[nver];
	for(int i=0; i<nver; i++){
		N[i] = new int[nver];
		for(int j=0; j<nver; j++)
			N[i][j] = 0;
	}
	for(int i=0; i<nedg; i++){
		int beg = edg[i][0],
			end = edg[i][1];
		N[beg-1][end-1] = 1;
	}
	cout<<"Матрица смежности графа:\n";
	for(int i=0; i<nver; i++)
		myout(N[i],nver, nver,4);

cout<<"=== Задание 6c =================\n";
	int**E = new int*[nver];
	int*size = new int[nver];
	for(int i=0; i<nver; i++){
		size[i] = 0;
		for(int j=0; j<nver; j++)
			size[i] += N[i][j];
		E[i]=new int[size[i]];
	}
	for(int i=0; i<nver; i++)
		for(int j=0, n=0; j<nver; j++)
			if(N[i][j]==1)
				E[i][n++]=j+1;
	cout<<"Матрица конечных вершин графа:\n";
	myout(E,nver,size,4);
	/*for(int i=0; i<nver; i++)
		if(size[i])
			myout(E[i],size[i],size[i],4);
		else cout<<endl;*/

	for(int i=0; i<nedg; i++) delete[]edg[i];
	for(int i=0; i<nver; i++) delete[]N[i];
	for(int i=0; i<nver; i++) delete[]E[i];
	delete[]edg; delete[]N; delete[]E;
	delete[]size; delete[]s;
}
{cout<<"=== Задание 8 =================\n";
	const int nr=5; int M[nr][nr];
	myrnd(M[0],nr*nr,-99,99);
	cout<<"Исходная матрица:\n";
	myout(M[0],nr*nr,nr);
	int* pM[nr];
	for(int i=0; i<nr; i++)
		pM[i]=M[i];
	transp(pM, nr);
	cout<<"Транспонированная матрица:\n";
	myout(M[0],nr*nr,nr);
}
{cout<<"=== Задание 12 =================\n";
	const int nr=5, nc=10; double M[nr][nc];
	myrnd(M[0],nr*nc,-0.9,0.9,1);
	double* pM[nr]; for(int i=0; i<nr; i++) pM[i] = M[i];
	double X[nr]; sum(pM,nr,nc,X);
	cout<<"Исходная матрица и суммы элементов строк:\n";
	for(int i=0; i<nr; i++) {
		myout(M[i],nc,nc+1,5,1); cout<<" |"<<setw(5)<<X[i]<<endl;
	}
	mysrt(X,nr,1,pM);
	cout<<"\nИтоговая матрица и суммы элементов строк:\n";
	for(int i=0; i<nr; i++) {
		myout(pM[i],nc,nc+1,5,1); cout<<" |"<<setw(5)<<X[i]<<endl;
	}
}
{cout<<"=== Задание 13 =================\n";
	const int nx = 50;
	int* X = new int[nx];
	myrnd(X,nx,100,999);
	cout<<"Исходный массив:\n";
	myout(X,nx,10);
	const int nr=4; int* D[nr], * size = new int[nr];
	for(int i=0; i<nr; i++) size[i]=0;
	for(int i=0; i<nx; i++) {
		int n0 = X[i]%10, n1 = X[i]/10%10, n2 = X[i]/100;
		if(n0==n1 && n1==n2) size[0]++;
		else if(n2==n1)		 size[1]++;
		else if(n2==n0)		 size[2]++;
		else if(n1==n0)		 size[3]++;
	}
	for(int i=0; i<nr; i++) D[i] = new int[size[i]];
	int i0=0, i1=0, i2=0, i3=0;
	for(int i=0; i<nx; i++) {
		int n0 = X[i]%10, n1 = X[i]/10%10, n2 = X[i]/100;
		if(n0==n1 && n1==n2) D[0][i0++] = X[i];
		else if(n2==n1)		 D[1][i1++] = X[i];
		else if(n2==n0)		 D[2][i2++] = X[i];
		else if(n1==n0)		 D[3][i3++] = X[i];
	}
	cout<<"\nЧисла с одинаковыми цифрами:\n"; myout(D,nr,size);
	for(int i=0; i<nr; i++) delete[]D[i];
	delete[]size;
}
{cout<<"=== Задание 9b =================\n";
	char*tmp = new char[1024];
	int ns = myinput(tmp,"11.9.txt");
	char **S  = new char*[ns];
	char *p   = tmp;
	for(int i=0; i<ns; i++){
		S[i] = new char[mylen(p)+1];
		mycpy(S[i],p);
		p += mylen(p)+1;
	}
	char**F = new char*[ns];
	for(int i=0; i<ns; i++) F[i] = S[i];
	mysrt(F, ns, 1, S);
	cout<<"Список студентов (сортировка по фамилии):\n";
	for(int i=0; i<ns; i++) cout<<F[i]<<endl;
cout<<"=== Задание 9c =================\n";
	char**G = new char*[ns];
	for(int i=0; i<ns; i++) {
		char*p = S[i];
		for(int j=0; j<2; j++){
			p += mycspn(p," ");
			p += myspn(p," ");
		}
		G[i] = p;
	}
	mysrt(G, ns, 1, S);
	cout<<"Список студентов (сортировка по группе):\n";
	for(int i=0; i<ns; i++) cout<<S[i]<<endl;
cout<<"=== Задание 9d =================\n";
	int*V = new int[ns];
	for(int i=0; i<ns; i++){
		char*p = S[i];
		for(int j=0; j<4; j++){
			p += mycspn(p," ");
			p += myspn(p," ");
		}
		V[i] = 0;
		for(int j=0; j<5; j++){
			V[i] += atoi(p);
			p += mycspn(p," ");
			p += myspn(p," ");
		}
	}
	mysrt(V, ns, 0, (int**)S);
	cout<<"Список студентов (сортировка по оценкам):\n";
	for(int i=0; i<ns; i++) cout<<S[i]<<endl;
	for(int i=0; i<ns; i++) delete[]S[i];
	delete[]S; delete[]F; delete[]G; delete[]V; delete[]tmp;
}
{cout<<"=== Задание 10 =================\n";
	char str[16]="4321"; int n=atoi(str);		//1
	cout<<"str = "<<str<<endl
		<<"atoi(str) = "<<n<<endl<<endl;

	n = 1234; itoa(n,str,10);					//2
	cout<<"n = "<<n<<endl
		<<"itoa(n,str,10) = "<<str<<endl<<endl;

	mycpy(str,"54,032"); double d = atof(str);	//3
	cout<<"str = "<<str<<endl
		<<"atof(str) = "<<setprecision(3)<<d<<endl<<endl;

	d = 71.593267; ftoa(d,str,3);				//4
	cout<<"d = "<<fixed<<setprecision(6)<<d<<endl
		<<"ftoa(d,str,3) = "<<str<<endl<<endl;

	mycpy(str,"461qwe"); n = atoi(str);			//5
	cout<<"str = "<<str<<endl
		<<"atoi(str) = "<<n<<endl;
	mycpy(str,"zxc940"); n = atoi(str);			
	cout<<"str = "<<str<<endl
		<<"atoi(str) = "<<n<<endl<<endl;
	
	mycpy(str,"54.032"); d = atof(str);			//6
	cout<<"str = "<<str<<endl
		<<"atof(str) = "<<setprecision(3)<<d<<endl;
	setlocale(LC_NUMERIC, "C");
	mycpy(str,"54.032"); d = atof(str);
	cout<<"str = "<<str<<endl
		<<"atof(str) = "<<d<<endl;
	setlocale(LC_ALL, "RUS");
}
{cout<<"=== Задание 14 =================\n";
	char* s = new char[128];
	int nr = myinput(s,"14.txt");
	int nv = 6;
	int** N = new int*[nv];
	for(int i=0; i<nv; i++){
		N[i] = new int[nv];
		for(int j=0; j<nv; j++)
			N[i][j] = 0;
	}
	char*p = s;
	for(int i=0; i<nr; i++){
		int n0 = atoi(p);
		p += mycspn(p," ");
		int n1 = atoi(p);
		N[n0-1][n1-1] = 1;
		p += mylen(p)+1;
	}
	cout<<"Матрица смежности графа:\n";
	for(int i=0; i<nv; i++)
		myout(N[i],nv,nv);
	int i, j;
	cout<<"Начальные вершины графа: ";
	for(j=0; j<nv; j++) {
		for(i=0; i<nv; i++)
			if(N[i][j]==1) break;
		if(i==nv) cout<<j+1<<" ";
	}
	cout<<"\nКонечные вершины графа:  ";
	for(i=0; i<nv; i++) {
			for(j=0; j<nv; j++)
				if(N[i][j]==1) break;
			if(j==nv) cout<<i+1<<" ";
		}
	for(int i=0; i<nv; i++) delete[]N[i];
	delete[]N; delete[]s;
}
{cout<<"\n=== Задание 15 =================\n";
	char*s = new char[1024];
	int ns = myinput(s,"951.txt");
	char** stud = new char*[ns];
	int* numG = new int[ns];
	char* p = s;
	for(int i=0; i<ns; i++) {
		stud[i] = new char[mylen(p)+1];
		mycpy(stud[i],p);
		for(int j=0; j<3; j++){
			p += mycspn(p," ");
			p += myspn(p," ");
		}
		numG[i] = atoi(p+1);
		p += mylen(p)+1;
	}
	mysrt(numG, ns, 1, (int**)stud);
	char** fam = new char*[ns];
	const int ng = 3; int sizeG[ng] = {};
	for(int i=0; i<ns; i++){
		fam[i] = stud[i];
		sizeG[numG[i]-1]++;
	}
	int n = 0;
	for(int i=0; i<ng; i++){
		mysrt(&fam[i], sizeG[i], 1, &stud[i]);
		n += sizeG[i];
	}
	cout<<"Итоговый список:\n";
	for(int i=0; i<ns; i++) {
		p = mystr(stud[i],"группа")-1;
		int lenfio = p - stud[i];
		myout(stud[i], lenfio, lenfio+1);
		cout<<setw(27-lenfio)<<" "
			<<p<<endl;
	}
	for(int i=0; i<ns; i++) delete[]stud[i];
	delete[]stud; delete[]numG; delete[]fam; delete[]s;
}
system("pause"); return 0;
}

void transp(int** M, int nr){
	for(int i=0; i<nr; i++)
		for(int j=i+1; j<nr; j++)
			swap(M[i][j], M[j][i]);
}

void sum(double** M, int nr, int nc, double* X){
	for(int i=0; i<nr; i++){
		X[i] = 0;
		for(int j=0; j<nc; j++) X[i] += M[i][j];
	}
}