#include <iostream>
#include <iomanip>
#include <fstream>
#include "..\\..\\myfunctions.h"
#include "..\\..\\myclasses.h"

using namespace std;

struct student{
	char fio[32]; int group; float val;
	char dat[12]; char tel[14];
};

void myopen(ifstream &fin, const char* fname, const int mode=ios::in);	//открытвает файл fname во входном потоке fin

void myopen(ofstream &fout, const char* fname, const int mode=ios::out);	//открытвает файл fname во входном потоке fout

void file2scn(ifstream &fin, const char* fname, const int maxlen=128);	//выводит на экран содержимое текстового файла fname

int main(){
setlocale(LC_ALL, "RUS");
srand(time(0));
{cout<<"=== Задание 2 =================\n";	//ВОПРОС №1
	ifstream fin;	//объявлчем входной поток для чтения файла. Входной поток  это объект класса
	const char* fname1 = "14.2.txt"; fin.open(fname1); //мы объявляем пременную  fname1 и присваимваем ей название файла 14 2 тхт а затем ф ин это объект, опен это метод а в скобках мы указываем имя файла которое открываем
	if(fin.is_open()) //проверяем открылся ли файл метод ис опен дает тру если файл открылся. Если ошика то выводится элс
		cout<<"Файл "<<fname1<<" открыт"<<endl;
	else
		cout<<"\nОшибка открытия файла "<<fname1<<endl;
	fin.close(); //просто закрываю файл в скобках пусто потому что туда не передаются никакие параметры

	const char* fname2 = "abc.txt"; fin.open(fname2);//в строку ф нейм 2 заносим имя файла и открываем его в поток
	if(fin.is_open())//делаем такую же проверку как и выше
		cout<<"Файл "<<fname2<<" открыт"<<endl;//такого файла у нас нет и выводит ошибку
	else
		cout<<"\nОшибка открытия файла "<<fname2<<endl;
	fin.close();
}
{cout<<"=== Задание 3 =================\n";
	ofstream fout;	//ВОПРОС №2  //o это чтобы записывать в файл. мы объявляем выходной поток
	const char* fname = "14.3.txt"; fout.open(fname);//чар* это динамическая строка, а так тут все тоже что и во 2 задании
	if(!fout.is_open())	//проверяем открылся ли файл
		cout<<"\nОшибка открытия файла "<<fname<<endl;
	cout<<"Посимвольная запись в файл первой строки.\n";
	char s[32] = "1) Моя первая запись в файл.";	//объявляем строку s и записываем туда строку
	for(char *p = s; *p; p++)	//цикл for по строке, обявляем указатель на начало строки (char *p = s), идем по каждому символу до конца строки
		fout.put(*p);	//записываем в файл, который открыт в потоке fout, текущий символ строки s
	fout.put('\n'); fout.close();	//записываем в файл символ перевода строки а затем закрываем его
	fout.open(fname, ios_base::app);	//ВОПРОС №3.	//так же открываем файл, но открываем с параметром "app", этот параметр говорит о том, что запись будет производиться в конец файла
	if(!fout.is_open())	//проверяем открытие файла
		cout<<"\nОшибка открытия файла "<<fname<<endl;
	cout<<"Посимвольное добавление в файл второй строки.\n";
	mycpy(s,"2) Это вторая строка файла.");	//функция mycpy записывает в строку s строку 2) Это вторая...
	for(char *p = s; *p; p++)	//здесь так же, как и выше
		fout.put(*p);	//...
	fout.put('\n'); fout.close();	//...
	ifstream fin; fin.open(fname);	//ВОПРОС №4.	//объяевляем входной поток и открываем в нем файл, в который мы записали две строки
	if(!fin.is_open())	//проверка, открылся ли
		cout<<"\nОшибка открытия файла "<<fname<<endl;
	cout<<"\nПосимвольное чтение файла:\n";
	while(!fin.eof()) {		//цикл while будет выполняться, пока не достигнут конец файла(метод eof отдает тру, если файл закончился)
		char ch; fin.get(ch); cout<<ch;	//читаем каждый символ ch из файла методом гет и выводим его на экран 
	}
	fin.close();	//закрываем файл
}
{cout<<"=== Задание 4 =================\n"; //ВОПРОС 5 //
	ofstream fout; const char* fname = "14.4.txt"; /*fout.open(fname);
	if(!fout.is_open())
		cout<<"\nОшибка открытия файла "<<fname<<endl;*/
	myopen(fout,fname);	// мы в неё передаем поток ф аут и название файла ф нейм
	fout<<"=======================\n";
	int m = 12345; float x = acos(-1);
	fout<<fixed<<setprecision(2)
		<<"m  ="<<setw(7)<<m<<"\n"
		<<"x  ="<<setw(7)<<x<<"\n";
	fout<<"=======================\n";
	fout.close();

	ifstream fin; /*fin.open(fname);	//ВОПРОС 6 объявляем поток 
	if(!fin.is_open())
		cout<<"\nОшибка открытия файла "<<fname<<endl;*/
	myopen(fin,fname); // Открываем в потоке fin файл fname 
	const int maxlen = 32; char s[maxlen], t[maxlen]; // объявляем константу типа инт это короч длина строки и затем объявляю сами две строки с и т как массив и в квадратных скобках длинна строки
	int n; float y; // задаем переменные чтобы в них считать данные из файла
	fin>>s; cout<<s<<endl; //фин это поток, в котором открыт файл, мы оператором стреклка стрелка считываем из потока строку  в строку с
	fin>>s>>t>>n; // кстати это считывание происходит до слеш эна или до пробела
	cout<<s<<" "<<t<<" "<<n<<" "<<endl;
	fin>>s>>t>>y;
	cout<<s<<" "<<t<<" "<<y<<" "<<endl;
	fin>>s; cout<<s<<endl; //строка из знаков равно
	fin.close();

	/*fin.open(fname);
	if(!fin.is_open())
		cout<<"\nОшибка открытия файла "<<fname<<endl;*/
	myopen(fin,fname);	// ВОПРОС 7
	fin.getline(s, maxlen); fin.getline(s, maxlen); //Метод гетлайн считывает 2 раза из файла который открыт в потоке в строку с число симоволов макслен
	char* p = str2int(s, 2); n = atoi(p); //затем мы объявляем указатель п и переводим его на третье слово строки с то есть первое слово м второе = и третье 12345 и у нас указатель находится на 12345
	//в переменную н мы записываем число 12345 с помощью функции эй ту и   эй - строку, ту - ту, и строка. П указывает на слово 12345 и текст надо перевести в число с помощью данной функции
	fin.getline(s, maxlen);// считываем след строку
	setlocale(LC_NUMERIC, "C");// 7 страница лабы
	p = str2int(s, 2); y = atof(p);// снова указатель п и снова переводим его на 3 слово строки с и в переменную игрик записываем функцией фтуэй  число 314
	setlocale(LC_NUMERIC, "RUS");
	fin.close();
	cout<<"Числовые значения в файле задания: "<<n<<" "<<y<<endl;
}
{cout<<"=== Задание 6 =================\n";
	ifstream fin; const char* fname = "14.4.txt";
	file2scn(fin, fname);
}
{cout<<"=== Задание 7 =================\n";
	const int maxlen=128; char s[maxlen];//чар с строка куда мы будем записывать фамилию студента
	const int nval =   4; int val[nval];//нвал количесвто оценок, объявляем массив вал в котором будут вписаны оценки каждого студента
	const int ngr =    3; const char* fname[ngr] = { //нгр это количесвто групп и затем мы создаем массив в котором записываем название файлов по группам
		"Группа 1.txt", "Группа 2.txt", "Группа 3.txt"
	};
	ifstream fin; ofstream fout; //вопрос 10 11 и 12
	myopen(fout, "Отличники.txt"); //мы открываем в поток фаут файл отличники 
	char io[5]; int nstud = 0; //объявляем массив ио имя отчество а нстуд количество отличников
	for(int i=0; i<ngr; i++){//цикл фор по гурппам, сначала 1 потом 2 и тд
		myopen(fin,fname[i]);//мы открываем вхоной поток файл фнейм итое, фнейм массив 
		while(!fin.eof()){//цикл проверяет достигнут ли конец файла
			fin>>s>>io;//мы из потока сначала записываем в строку с фамилию студента. и мы записываем инициалы в ио
			for(int j=0; j<nval; j++)//
				fin>>val[j];//из потока фин мы записываем в массив вал каждую оценку
			if(val[mymin(val,nval)]>8){//мы проверяем на отличника. нам нужно найти  индекс минимальный элемент то бишь мин оценку
				mycat(s, " "); mycat(s, io);//функция майкет записывает в конец строки с заишет пробел, та же самая функция майкет в конец строки с запишет уже инициалы
				fout<<left<<setw(18)<<s<<" группа "<<i+1<<endl;//в потоке мы запишем фамилию и инициалы студента, потом слово группа и затем номеер группы i начинается с 0
				nstud++;//нстуд ++ это количсевто отличников. Если это отличник то счетчик мы увеличиываем на елиницу
			}
		}
		fin.close();//закрываем поток с файлом группа 1 потом 2 потом 3
	}
	fout.close();//когда прошлись по всем группам и записали отличников закрываем файл отличники
	file2scn(fin, "Отличники.txt");//а затем функцикй файл ту скрин открываем файл отличники во входном потоке и выводим на экран
}
{cout<<"=== Задание 8 =================\n";
	char* s = new char[128];
	int nstud = myinput(s, "Отличники.txt");
	char** srt = new char*[nstud];
	char* p = s;
	for(int i=0; i<nstud; i++){
		srt[i] = p;
		p += mylen(p)+1;
	}
	mysrt(srt,nstud,1);
	ofstream fout; myopen(fout, "Отличники.txt");
	for(int i=0; i<nstud; i++)
		fout<<srt[i]<<endl;
	fout.close();
	ifstream fin; file2scn(fin, "Отличники.txt");
	delete[]s; delete[]srt;
}
{//cout<<"=== Задание 9 =================\n";
	ofstream fout; myopen(fout, "14.9.bin", ios_base::binary);
	int m = 100;		fout.write((char*)&m, sizeof(m));
	double a = 173.904; fout.write((char*)&a, sizeof(a));

	int X[] = {1, 2, 3, 5, 7, 11, 13, 17, 19};
	int nx = sizeof(X)/sizeof(X[0]);
	fout.write((char*)&nx, sizeof(nx));
	fout.write((char*)X, nx*sizeof(X[0]));

	char *s = "*********************";
	int ns = mylen(s)+1;
	fout.write((char*)&ns, sizeof(ns));
	fout.write(s, ns);

	student st1 = {"Липницкий А.Н.", 5, 7.25, "2001.04.17", "29-361-90-14"};
	fout.write((char*)&st1, sizeof(st1));

	fout.close();
}
{cout<<"=== Задание 10 =================\n";
	ifstream fin; myopen(fin, "14.9.bin", ios_base::binary);
	int m;	  fin.read((char*)&m, sizeof(m));
	double a; fin.read((char*)&a, sizeof(a)); cout<<m<<" "<<a<<endl;

	int nx; fin.read((char*)&nx, sizeof(nx));
	int* X = new int[nx]; fin.read((char*)X, nx*sizeof(X[0]));
	myout(X, nx, nx, 3);

	int ns; fin.read((char*)&ns, sizeof(ns));
	char *s = new char[ns]; fin.read(s, ns); cout<<s<<endl;

	student st1; fin.read((char*)&st1, sizeof(st1));
	cout<<st1.fio<<" "<<st1.group<<" "<<st1.val<<" "
		<<st1.dat<<" "<<st1.tel<<endl;
	
	fin.close();
	delete[]X; delete[]s;
}
system("pause"); return 0;
}


//ЗАДАНИЕ 5 и 8
void myopen(ifstream &fin, const char* fname, const int mode){ //тут указываются параметры, ссылка на поток, потом название файла и метод открытия файла
	fin.open(fname, mode);
	if(!fin.is_open())
		cout<<"\nОшибка открытия файла "<<fname<<endl;
}

void myopen(ofstream &fout, const char* fname, const int mode){
	fout.open(fname, mode);
	if(!fout.is_open())
		cout<<"\nОшибка открытия файла "<<fname<<endl;
}

//Задание 9
void file2scn(ifstream &fin, const char* fname, const int maxlen){	//мы передаем в функцию ссылку на вхожной поток, имя файла и максимальную длину строки которую нужно вывести
	char* s = new char[maxlen];//создаем динамическую строку s и присваиваем ей память макс лен
	myopen(fin, fname);//открываем файл с помощью клубничной функции
	while(!fin.eof()){	//цикл вайл выполняется пока файл не закончился так как еоф проверяет на конец файла
		fin.getline(s,maxlen);//мы буем считывать строку из файла в ф ин в строку с и затем выводим строку
		cout<<s<<endl;
	}
	fin.close(); delete[]s;//закрываем поток и удаляем динамическую строку 
}