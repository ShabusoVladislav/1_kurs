#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
using namespace std;

struct session {char* name; int* val; float mean;};

inline void str2session(const char* s, session* pstud, int nval);	//присваивает содержимое строки полям структуры типа session

void session2scn(session *pstud, int nw, int nval, bool meanout=true);	//выводит на экран поля структуры типа session

float meanval(int*x, int nx);	//среднее арифметическое nx элементов массива x

struct stWorker {
	char* name;
	int otdel;
	double oklad;
	char pol;
	char* dat;
	char* adr;
	char* tel;	};

inline void str2worker(const char* s, stWorker* worker);

void worker2scn(stWorker* worker, int nw);

int main(){
setlocale(LC_ALL, "RUS");
srand(time(0));
{cout<<"=== Задание 1 =================\n";
	const int nname = 20, nval = 4;
	struct session {
		char name[nname]; int val[nval]; float mean;
	} stud1;
	session stud2 = {"Колесник Н.И.", 8,6,9,7, 7.5};
	stud1 = stud2;
	cout<<"Результаты сессии:\n";
	cout<<"1) "<<stud1.name; myout(stud1.val, nval, nval+1, 3);
	cout<<fixed<<setprecision(2)<<"  (средняя "<<stud1.mean<<")\n";
}
{cout<<"=== Задание 2 =================\n";
	struct stPoint2 {double x, y;};
	struct stCircle{stPoint2 center; double radius;};
	const int nc = 20; stCircle crc[nc];
	for(int i=0; i<nc; i++){
		crc[i].center.x = (rand()%19-9)/10.;
		crc[i].center.y = (rand()%19-9)/10.;
		crc[i].radius   = (rand()%9 +1)/10.;
		cout<<setprecision(1);
		cout<<"("<<setw(4)<<crc[i].center.x
			<<","<<setw(4)<<crc[i].center.y
			<<","<<setw(4)<<crc[i].radius<<")";
		if((i+1)%4==0) cout<<endl;
	}
	cout<<"Окружности в единичном круге:\n";
	/*for(int i=0; i<nc; i++) {
		double r = sqrt(crc[i].center.x*crc[i].center.x + crc[i].center.y*crc[i].center.y);
		if((r+crc[i].radius) <= 1)
			cout<<"центр = ("   <<setw(4)<<crc[i].center.x
			<<","               <<setw(4)<<crc[i].center.y
			<<"), радиус = "    <<setw(4)<<crc[i].radius<<endl;
	}*/
	for(stCircle *p = crc, *end = p+nc; p<end; p++) {
		double r = sqrt(p->center.x*p->center.x + p->center.y*p->center.y);
		if((r+p->radius) <= 1)
			cout<<"центр = ("   <<setw(4)<<p->center.x
			<<","               <<setw(4)<<p->center.y
			<<"), радиус = "    <<setw(4)<<p->radius<<endl;
	}
}
{cout<<"=== Задание 3 =================\n";
	char* s = "Панкратович К.С. 7 5 6 5";
	cout<<"Исходная строка: "<<s<<endl;
	session stud;
	int nval = 4;
	/*char* p = s;
	p += myspn (p," ");
	p += mycspn(p," "); p += myspn (p," ");
	p += mycspn(p," "); p += myspn (p," ");
	int lenfio = p-s-1;
	stud.name = new char[lenfio+1];
	mycpy(stud.name, s, lenfio, 1);
	stud.val = new int[nval];
	for(int i=0; i<nval; i++) {
		stud.val[i] = atoi(p);
		p += mycspn(p," ");
		p += myspn(p," ");
	}
	stud.mean = 0;*/
	str2session(s, &stud, nval);
	/*for(int i=0; i<nval; i++) stud.mean += stud.val[i];
	stud.mean /= nval;*/
	
	stud.mean = meanval(stud.val, nval); 
	cout<<"\nРезультаты сессии:\n";
	/*cout<<left<<setw(18)<<stud.name;
	cout<<right<<fixed<<setprecision(2);
	myout(stud.val, nval, nval+1, 3);
	cout<<"   Средняя = "<<stud.mean<<endl;*/
	session2scn(&stud, 18, nval, 1);
	delete[]stud.name; delete[]stud.val;
}
{cout<<"=== Задание 7 ============\n";
	char* s = new char[1024];
	int nstud = myinput(s,"12.7.txt");
	session* stud = new session[nstud];
	int nval = 4;
	char* p = s;
	for(int i=0; i<nstud; i++){
		str2session(p, &stud[i], nval);
		stud[i].mean = meanval(stud[i].val, nval);
		p += mylen(p)+1;
	}
	for(int i=0; i<nstud; i++)
		session2scn(&stud[i], 20, nval, 0);
	cout<<"\nОтличники:\n";
	for(int i=0; i<nstud; i++) {
		int n = mymin(stud[i].val, nval);
		if(stud[i].val[n] > 8)
			session2scn(&stud[i], 15, 0);
	}
	cout<<"\nНеуспевающие:\n";
	for(int i=0; i<nstud; i++) {
		int n = mymin(stud[i].val, nval);
		if(stud[i].val[n] < 4)
			session2scn(&stud[i], 15, 0);
	}

cout<<"=== Задание 8 ===============\n";
	session** pstud = new session*[nstud];
	char**    pname = new char*[nstud];
	for(int i=0; i<nstud; i++){
		pstud[i] = &stud[i];
		pname[i] = stud[i].name;
	}
	mysrt(pname, nstud, 1, (char**)pstud);
	cout<<"Сортировка по фамилии:\n";
	for(int i=0; i<nstud; i++)
		session2scn(pstud[i], 16, 4, 0);
	double *pmean = new double[nstud];
	for(int i=0; i<nstud; i++){
		pstud[i] = &stud[i];
		pmean[i] = stud[i].mean;
	}
	mysrt(pmean, nstud, 0, (double**)pstud);
	cout<<"Сортировка по средней оценке:\n";
	for(int i=0; i<nstud; i++)
		session2scn(pstud[i], 15, 0);
	for(int i=0; i<nstud; i++){
		delete []stud[i].name; delete []stud[i].val;
	}
	delete []s; delete []stud; delete []pstud;
	delete []pname; delete []pmean;
}
{cout<<"=== Задание 10 =================\n";
	char* s = "Никитина Раиса Николаевна 6 630,5 w 15.07.1969 33-443-55-33 Рабкоровская_улица 86 62";
	cout<<"Исходная строка:\n"<<s<<endl;
	stWorker worker;
	str2worker(s,&worker);
	cout<<"\nПоля структуры:\n";
	worker2scn(&worker, 35);
}
{cout<<"=== Задание 11 =================\n";
	char* s = new char[4096];
	int nwkr = myinput(s, "608.txt");
	stWorker* worker = new stWorker[nwkr];
	char* p = s;
	for(int i=0; i<nwkr; i++){
		str2worker(p, &worker[i]);
		p += mylen(p)+1;
	}
	stWorker** srt = new stWorker*[nwkr];
	int* otd = new int[nwkr];
	for(int i=0; i<nwkr; i++) {
		srt[i] = &worker[i];
		otd[i] = worker[i].otdel;
	}
	mysrt(otd, nwkr, 1, (int**)srt);
	int n = 0;
	while(otd[n] == 1)
		n++;
	char** pname = new char*[n];
	for(int i=0; i<n; i++)
		pname[i] = srt[i]->name;
	mysrt(pname, n, 1, (char**)srt);
	cout<<"Список сотрудников, упорядоченный по отделам (первый отдел - по ФИО):\n";
	for(int i=0; i<nwkr; i++) worker2scn(srt[i], 35);

	n = 0;
	for(int i=0; i<nwkr; i++){
		char* p = worker[i].dat;
		p = mystr(p,".")+1;
		p = mystr(p,".")+1;
		if(*(p+3) == '1'){
			srt[n]   = &worker[i];
			pname[n] = worker[i].name;
			n++;
		}
	}
	mysrt(pname, n, 1, (char**)srt);
	cout<<"\nСписок сотрудников, которые в текущем году отмечают юбилей:\n";
	for(int i=0; i<n; i++) worker2scn(srt[i], 35);
	delete []otd; delete []srt; delete []worker;
	delete []s; delete []pname;
}
system("pause"); return 0;
}

inline void str2session(const char* s, session* pstud, int nval){
	char* p = (char*)s;
	p += myspn (p," ");
	p += mycspn(p," "); p += myspn (p," ");
	p += mycspn(p," "); p += myspn (p," ");
	int lenfio = p-s-1;
	pstud->name = new char[lenfio+1];
	mycpy(pstud->name, s, lenfio, 1);
	pstud->val = new int[nval];
	/*for(int i=0; i<nval; i++) {
		pstud->val[i] = atoi(p);
		p += mycspn(p," "); p += myspn(p," ");
	}*/
	str2int(p,nval,pstud->val);
	pstud->mean = atof(p);
}

void session2scn(session *pstud, int nw, int nval, bool meanout){
	cout<<left<<setw(nw)<<pstud->name;
	cout<<right<<fixed<<setprecision(2);
	myout(pstud->val, nval, nval+1, 3);
	if(meanout)
		cout<<"   Средняя = "<<pstud->mean;
	cout<<endl;
}

float meanval(int*x, int nx){
	float s=0;
	for(int i=0; i<nx; i++) s += x[i];
	s /= nx;
	return s;
}

inline void str2worker(const char* s, stWorker* worker){
	char* p = str2int(s, 3);
	worker->name = new char[p-s+1];
	mycpy(worker->name, s, p-s, 1);
	p = str2int(p, 1, &worker->otdel);
	p = str2dbl(p, 1, &worker->oklad);
	worker->pol = *p;
	p = str2int(p, 1);
	char* q = p;
	p = str2int(p, 1);
	worker->dat = new char[p-q+1];
	mycpy(worker->dat, q, p-q, 1);
	q = p;
	p = str2int(p, 1);
	worker->tel = new char[p-q+1];
	mycpy(worker->tel, q, p-q, 1);
	worker->adr = new char[mylen(p)+1];
	mycpy(worker->adr,p);
}

void worker2scn(stWorker* worker, int nw){
	cout<<left<<setw(nw)<<worker->name;
	cout<<right<<fixed<<setprecision(2);
	cout<<"отдел №"<<worker->otdel;
	cout<<" оклад="<<worker->oklad;
	cout<<(worker->pol == 'w' ? " жен." : " муж.");
	cout<<" тел."<<worker->tel<<endl;
	cout<<"        дата рождения:"<<setw(12)<<worker->dat;
	cout<<"  адрес: "<<worker->adr<<endl;
}