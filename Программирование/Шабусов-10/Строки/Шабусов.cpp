#include <iostream>
#include <iomanip>
#include "..\\..\\myfunctions.h"
#include <fstream>                  //fstream �������� ����������� ��� ������ � ������� 
using namespace std;

int main(){
setlocale(LC_ALL, "rus");
srand(time(0));
{cout<<"=== ������� 2� =================\n";
	const int np = 6;
	const char* P[np] = {
		"������������","�����������","���������",
		"�����������","������������","����������" };
	const char* F[np] = {
		"��","���","���","���","����","���" };
	const char* N[np] = {
		"","�","�","�","��","�" };
	const int nt=20; char* t=new char[nt];
	const int ns=22; char* s=new char[ns];
	cout<<left<<"��������� ������� � �����:\n";
	for(int i=0; i<np; i++){
		mycpy(t,P[i]); mycat(t," �����:");
		i!=5 ? mycpy(s,"�����") : mycpy(s, "� �����");
		mycat(s,F[i]); mycat(s," ���������"); mycat(s,N[i]);
		cout<<setw(20)<<t<<setw(24)<<s<<"len(s) = "<<mylen(s)<<endl;
	}
	delete[]t; delete[]s;
}
{cout<<"=== ������� 3 =================\n";
	const int ns=20; char *s = new char[ns];
	strcpy(s,"-57012.3971 259.184");
	cout<<"�������� ������:\n"<<s<<endl;
	char *p = s;
	while(*p!=' ') p++;
	int n = p-s;
	p++;
	char *t = new char[ns];
	strncpy(t, s, n);
	t[n]='\0';
	strcpy(s, p);
	strcat(s, " ");
	strcat(s, t);
	cout<<"�������� ������:\n"<<s<<endl;
	delete[]s; delete[]t;
}
{cout<<"=== ������� 5 =================\n";
	const int ns = 128; char *s = new char[ns];
	mycpy(s,"��������������� ������ ���������� ������:\n���� ������ ������ ����");
	const int nv = 10;
	const char* V[nv] = {
	   "����",  "���",  "���",    "������", "����",
	   "�����", "����", "������", "������", "������" };
	int sum = 0, n = 0;
	char *p = mystr(s,"\n")+1;
	while(1){
		for(int i=0; i<nv; i++)
			if(!mycmp(p, V[i], mylen(V[i]))){
				n++; sum+=(i+1);
				break;
			}
		p = mystr(p," ");
		if(p==NULL) break;
		p++;
	}
	cout<<s<<"\n������� ������ = "<<(double)sum/n<<endl;
	delete[]s;
}
{cout<<"=== ������� 6 =================\n";
	const int ns=1024; char *s=new char[ns];
	const int nt=128;  char *t=new char[nt];
	*s = '\0';
	/*while(1){
		cin.getline(t,nt);
		if(*t=='\0')
			break;
		mycat(s, t);
		mycat(s, "\n");
	}*/
	/*mycpy(s,
"�������� ������ ������\n\
�������� �����  ������\n\
����� �����     ������\n\
��������� ����  ������\n\
����� �������   ������\n\
���� �����      ������\n\
����� ����      ������\n\
������� ������� ������\n" );*/
	myinput(s, "10.6.txt", '\n');
	cout<<s<<endl;
cout<<"=== ������� 6b =================\n";
	cout<<"�������� ������ ������:\n";
	char *p = s;
	while(1){
		char *end=mystr(p,"\n");
		if(end==NULL) break;
		char *q=mystr(p,"������");
		if(q!=NULL && q<end)
			myout(p, 16);
		p = end+1;
	}
	delete[]s; delete[]t;
}	
{cout<<"=== ������� 8 =================\n";
	const int ns=1024; char *s=new char[ns];
	myinput(s,"10.8.txt",'\n');
	cout<<"�������� �����:\n"<<s;
	char*p = mystr(s,"  ");
	while(p!=NULL){
		mydel(p, 1);
		p = mystr(s,"  ");
	}
	for(char*p=s; *p; p++)
		if((*p==',' || *p=='.') && *(p+1)!=' ')
			myins(p+1," ");
	cout<<"�������� �����:\n"<<s;
	delete[]s;
}
{cout<<"=== ������� 10 =================\n";
	const int ns=2048; char*s=new char[ns];
	myinput(s,"10.10.txt",'\n'); cout<<s<<endl;
	const char *sep = " .,-*\'\n";
	int nw  = 0, maxlen = 0;
	char *p = s,
		 *pmax;
	while(1){
		int nsel = myspn(p,sep);
		p += nsel;
		int nword = mycspn(p,sep);
		if(nword==0) break;
		nw++;
		if(nword>maxlen) {
			pmax=p; maxlen=nword;
		}
		p+=nword;
	}
	cout<<"���������� ����: "<<nw<<endl;
	cout<<"������� �����: "; myout(pmax,maxlen);
	delete[]s;
}
{cout<<"=== ������� 15 =================\n";
	const int ns = 2048;
	char *s = new char[ns];
	mycpy(s,
"������ ������� � ��� ���������� ��� ���������.\n\
������� � ������������� �������� ���������� ������������.\n\
������� ����� ����� ����, ��� � ����� ������������.\n\
���������� ����������� ������ ��������� ��������� �������:\n\
   ��� ��� [������];\n\
��� ���������� ���������� ������������ ������� ���������\n\
��� ������� � ���������� ����� � ��������:\n\
   ��� ��� [������ 1][������ 2];");	const int nt = 512;	char *t = new char[nt];	myinput(t, "10.15.txt", '\n');	char *p = s;	for(int i=0; i<5; i++) {		p = mystr(p, "\n");		p++;
	}
	myins(p, t); cout<<s<<endl;
	delete[]s; delete[]t;
}
{cout<<"=== ������� 16 =================\n";
	const int ns = 2048; char *s = new char[ns];
	myinput(s,"479.txt",'\n');
	cout<<"������������ �����������:\n";
	char *p = s;
	while(1){
		p = mystr(p, "//");
		if(!p)
			break;
		char *q = mystr(p,"\n");
		myout(p, q-p);
		p = q++;
	}
	delete[]s;
}
{cout<<"=== ������� 13 =================\n";
	const int ns=16; char*s=new char[ns];
	strcpy(s,"4dE93aF2c");
	strupr(s);
	strrev(s);
	long long k = 1, n = 0;
	for(char *p=s; *p; p++)
		if(isdigit(*p)) {
			n += k*(*p-'0');	
			k *= 16;
		}
		else if(isupper(*p)) {
			n += k*(*p-'A'+10);
			k *= 16;
		}
	cout<<"n(16) = "<<strrev(s)<<endl
		<<"n(10) = "<<n<<endl;
	delete[]s;
}
{cout<<"=== ������� 14 =================\n";
	long long n = 238510754827509, m = n;
	const int ns=16; char*s = new char[ns];
	strnset(s,'\0',ns);
	char *p = s;
	while(m) {
		int k = m % 16;
		if(k<10) *p = '0' + k;
		else	 *p = 'A' + k-10;
		m /= 16;
		p++;
	}
	cout<<"n(10) = "<<n<<endl
		<<"n(16) = "<<strrev(s)
		<<endl;
	delete[]s;
}
{cout<<"=== ������� 17 =================\n";
	char* s = new char[1024];
	int ns = myinput(s, "483.txt", '\n');
	cout<<"�������� ������:\n"<<s<<endl;
	char*p = s;
	char* t = new char[4];
	for(int i=1; i<=ns; i++){
		int nsel = myspn(p," ");
		mydel(p, nsel);
		itoa(i, t, 10);
		mycat(t,") ");
		myins(p,t);
		p = mystr(p,"\n")+1;
	}
	p = mystr(s,"�������� �����");
	if(p) {
		mydel(p,mylen("�������� �����"));
		myins(p,"���������� �������");
	}
	cout<<"�������� ������:\n"<<s;
	delete[]s; delete[]t;
}
{cout<<"=== ������� 18 =================\n";
	char* s = new char[4096];
	int nstr = myinput(s, "348.txt", '\n');
	const char* sep = " ";
	char* p = mystr(s,"\n") + 1;
	for(int i=1; i<nstr-1; i++) {
		char* end = mystr(p,"\n");
		if(*(end+1) != ' '){
			int len = end-p;
			while(len<64) {
				p += myspn(p,sep);
				p += mycspn(p,sep);
				if(p>=end) break;
				myins(p," ");
				len++;
				end++; }
		}
		p = end+1;
	}
	cout<<s<<endl; delete[]s;
}


{cout<<" ================================ ������� 16 ��� ================================\n";
	const int ns = 2048;
	char *s = new char[ns];
	mycpy(s,
"������ � ��������� ������� �������� ����� �� ��������� ��������.\n\
1) � ������� ������� � ����������� ������ �������� (������� � ����).\n\
������ ������ ����� ����� ��� ����������� � ��� ���. ������ ��-\n\
����������� ���� � �������� ������� ������������ ������.\n\
2) � ������� ��������� � ������������ ���� ������, ������� �����-\n\
��� ����� ������ ������. ���� ������ ����� ���������� � ���������\n\
��������.\n");
	const int nt = 512;	char *t = new char[nt];	myinput(t, "���.txt", '\n');
	mycat(s, t);
	int n=0;
	char *p = s;
	while(1){
		p = mystr(p,"\n");
		if(!p) break;
		p++;
		n++;
	}
	cout<<s<<"\n����� ������� �� "<<n<<" �����\n";
	delete[]s; delete[]t;
}

system("pause"); return 0;
}