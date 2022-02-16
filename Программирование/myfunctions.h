//========================================================================
// заголовочный файл создан студентом группы №10 Шабусовым Владиславом
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

int mylen(const char*s);		//возвращает длину текста в строке s

char* mycpy(char*s, const char*t);		//копирует строку t в строку s

char* mycat(char*s, const char*t);		//объединяет строки s и t

char* mycpy(char*s, const char*t, int n, bool addNull=false);		//копирует из строки t в строку s n первых символов

bool mycmp(const char*s, const char*t, int n=0);		//сравнивает первые n символов строк s, t и возвращает false, если ==; true, если !=

char* mystr(const char*s, const char*t, int n=0);	//возвращает адрес первого вхождения подстроки t в строку s

int myinput(char *s, const char *fname, const char sep='\0');	//вводит содержимое файла fname в строку s, разделяя файловые строки символом sep

void myout(char *M, int size, int nc=-1, int nw=1);	//

void mydel(char*s, int ndel);	//удаляет в начале строки s ndel символов

void myins(char*s, const char*t);	//вставляет в начало строки s строку t

int myspn(const char*s, const char*sep);	//определяет кол-во подряд идущих разделителей sep, расположенных в начале строки s

int mycspn(const char*s, const char*sep);	//определяет кол-во подряд идущих словесных символов sep, расположенных в начале строки s

void mysrt(int*X, int nx, bool inc, int*P[]);	//сортирует nx элементов массива X по возрастанию (inc=true) и убыванию (inc=false)

void mysrt(double*X, int nx, bool inc, double*P[]);	//сортирует nx элементов массива X по возрастанию (inc=true) и убыванию (inc=false)

void myout(int** M, int nr, int* size, int nw=4); //выводит на экран динамическую матрицу M, выделяя nw знакомест каждому элементу

void mysrt(char**X, int nx, bool inc, char**P);	//Функция сортирует строки массива X

char* ftoa(double d, char* str, int nf);	//Преобразует вещественное число d в строчный эквивалент и помещает результат в выходную строку str

char* str2int(const char* s, int nw, int* X=NULL);	//переводит nw слов строки s в целые числа и присваивает их значения элементам массива X

char* str2dbl(const char* s, int nw, double* X=NULL);	//переводит nw слов строки s в вещественные числа и присваивает их значения элементам массива X

bool realequal(float, float, double=1e-6);	//сравнивает два вещественных числа a, b c учетом погрешности e

bool realequal(double, double, double=1e-12);	//сравнивает два вещественных числа a, b c учетом погрешности e

float meanval(int*x, int nx);	//среднее арифметическое nx элементов массива x

void mysrt(char**X, int nx, bool inc);	//Функция сортирует строки массива X