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

void myopen(ifstream &fin, const char* fname, const int mode=ios::in);	//���������� ���� fname �� ������� ������ fin

void myopen(ofstream &fout, const char* fname, const int mode=ios::out);	//���������� ���� fname �� ������� ������ fout

void file2scn(ifstream &fin, const char* fname, const int maxlen=128);	//������� �� ����� ���������� ���������� ����� fname

int main(){
setlocale(LC_ALL, "RUS");
srand(time(0));
{cout<<"=== ������� 2 =================\n";	//������ �1
	ifstream fin;	//��������� ������� ����� ��� ������ �����. ������� �����  ��� ������ ������
	const char* fname1 = "14.2.txt"; fin.open(fname1); //�� ��������� ���������  fname1 � ������������ �� �������� ����� 14 2 ��� � ����� � �� ��� ������, ���� ��� ����� � � ������� �� ��������� ��� ����� ������� ���������
	if(fin.is_open()) //��������� �������� �� ���� ����� �� ���� ���� ��� ���� ���� ��������. ���� ����� �� ��������� ���
		cout<<"���� "<<fname1<<" ������"<<endl;
	else
		cout<<"\n������ �������� ����� "<<fname1<<endl;
	fin.close(); //������ �������� ���� � ������� ����� ������ ��� ���� �� ���������� ������� ���������

	const char* fname2 = "abc.txt"; fin.open(fname2);//� ������ � ���� 2 ������� ��� ����� � ��������� ��� � �����
	if(fin.is_open())//������ ����� �� �������� ��� � ����
		cout<<"���� "<<fname2<<" ������"<<endl;//������ ����� � ��� ��� � ������� ������
	else
		cout<<"\n������ �������� ����� "<<fname2<<endl;
	fin.close();
}
{cout<<"=== ������� 3 =================\n";
	ofstream fout;	//������ �2  //o ��� ����� ���������� � ����. �� ��������� �������� �����
	const char* fname = "14.3.txt"; fout.open(fname);//���* ��� ������������ ������, � ��� ��� ��� ���� ��� � �� 2 �������
	if(!fout.is_open())	//��������� �������� �� ����
		cout<<"\n������ �������� ����� "<<fname<<endl;
	cout<<"������������ ������ � ���� ������ ������.\n";
	char s[32] = "1) ��� ������ ������ � ����.";	//��������� ������ s � ���������� ���� ������
	for(char *p = s; *p; p++)	//���� for �� ������, �������� ��������� �� ������ ������ (char *p = s), ���� �� ������� ������� �� ����� ������
		fout.put(*p);	//���������� � ����, ������� ������ � ������ fout, ������� ������ ������ s
	fout.put('\n'); fout.close();	//���������� � ���� ������ �������� ������ � ����� ��������� ���
	fout.open(fname, ios_base::app);	//������ �3.	//��� �� ��������� ����, �� ��������� � ���������� "app", ���� �������� ������� � ���, ��� ������ ����� ������������� � ����� �����
	if(!fout.is_open())	//��������� �������� �����
		cout<<"\n������ �������� ����� "<<fname<<endl;
	cout<<"������������ ���������� � ���� ������ ������.\n";
	mycpy(s,"2) ��� ������ ������ �����.");	//������� mycpy ���������� � ������ s ������ 2) ��� ������...
	for(char *p = s; *p; p++)	//����� ��� ��, ��� � ����
		fout.put(*p);	//...
	fout.put('\n'); fout.close();	//...
	ifstream fin; fin.open(fname);	//������ �4.	//���������� ������� ����� � ��������� � ��� ����, � ������� �� �������� ��� ������
	if(!fin.is_open())	//��������, �������� ��
		cout<<"\n������ �������� ����� "<<fname<<endl;
	cout<<"\n������������ ������ �����:\n";
	while(!fin.eof()) {		//���� while ����� �����������, ���� �� ��������� ����� �����(����� eof ������ ���, ���� ���� ����������)
		char ch; fin.get(ch); cout<<ch;	//������ ������ ������ ch �� ����� ������� ��� � ������� ��� �� ����� 
	}
	fin.close();	//��������� ����
}
{cout<<"=== ������� 4 =================\n"; //������ 5 //
	ofstream fout; const char* fname = "14.4.txt"; /*fout.open(fname);
	if(!fout.is_open())
		cout<<"\n������ �������� ����� "<<fname<<endl;*/
	myopen(fout,fname);	// �� � �� �������� ����� � ��� � �������� ����� � ����
	fout<<"=======================\n";
	int m = 12345; float x = acos(-1);
	fout<<fixed<<setprecision(2)
		<<"m  ="<<setw(7)<<m<<"\n"
		<<"x  ="<<setw(7)<<x<<"\n";
	fout<<"=======================\n";
	fout.close();

	ifstream fin; /*fin.open(fname);	//������ 6 ��������� ����� 
	if(!fin.is_open())
		cout<<"\n������ �������� ����� "<<fname<<endl;*/
	myopen(fin,fname); // ��������� � ������ fin ���� fname 
	const int maxlen = 32; char s[maxlen], t[maxlen]; // ��������� ��������� ���� ��� ��� ����� ����� ������ � ����� �������� ���� ��� ������ � � � ��� ������ � � ���������� ������� ������ ������
	int n; float y; // ������ ���������� ����� � ��� ������� ������ �� �����
	fin>>s; cout<<s<<endl; //��� ��� �����, � ������� ������ ����, �� ���������� �������� ������� ��������� �� ������ ������  � ������ �
	fin>>s>>t>>n; // ������ ��� ���������� ���������� �� ���� ��� ��� �� �������
	cout<<s<<" "<<t<<" "<<n<<" "<<endl;
	fin>>s>>t>>y;
	cout<<s<<" "<<t<<" "<<y<<" "<<endl;
	fin>>s; cout<<s<<endl; //������ �� ������ �����
	fin.close();

	/*fin.open(fname);
	if(!fin.is_open())
		cout<<"\n������ �������� ����� "<<fname<<endl;*/
	myopen(fin,fname);	// ������ 7
	fin.getline(s, maxlen); fin.getline(s, maxlen); //����� ������� ��������� 2 ���� �� ����� ������� ������ � ������ � ������ � ����� ��������� �������
	char* p = str2int(s, 2); n = atoi(p); //����� �� ��������� ��������� � � ��������� ��� �� ������ ����� ������ � �� ���� ������ ����� � ������ = � ������ 12345 � � ��� ��������� ��������� �� 12345
	//� ���������� � �� ���������� ����� 12345 � ������� ������� �� �� �   �� - ������, �� - ��, � ������. � ��������� �� ����� 12345 � ����� ���� ��������� � ����� � ������� ������ �������
	fin.getline(s, maxlen);// ��������� ���� ������
	setlocale(LC_NUMERIC, "C");// 7 �������� ����
	p = str2int(s, 2); y = atof(p);// ����� ��������� � � ����� ��������� ��� �� 3 ����� ������ � � � ���������� ����� ���������� �������� �����  ����� 314
	setlocale(LC_NUMERIC, "RUS");
	fin.close();
	cout<<"�������� �������� � ����� �������: "<<n<<" "<<y<<endl;
}
{cout<<"=== ������� 6 =================\n";
	ifstream fin; const char* fname = "14.4.txt";
	file2scn(fin, fname);
}
{cout<<"=== ������� 7 =================\n";
	const int maxlen=128; char s[maxlen];//��� � ������ ���� �� ����� ���������� ������� ��������
	const int nval =   4; int val[nval];//���� ���������� ������, ��������� ������ ��� � ������� ����� ������� ������ ������� ��������
	const int ngr =    3; const char* fname[ngr] = { //��� ��� ���������� ����� � ����� �� ������� ������ � ������� ���������� �������� ������ �� �������
		"������ 1.txt", "������ 2.txt", "������ 3.txt"
	};
	ifstream fin; ofstream fout; //������ 10 11 � 12
	myopen(fout, "���������.txt"); //�� ��������� � ����� ���� ���� ��������� 
	char io[5]; int nstud = 0; //��������� ������ �� ��� �������� � ����� ���������� ����������
	for(int i=0; i<ngr; i++){//���� ��� �� �������, ������� 1 ����� 2 � ��
		myopen(fin,fname[i]);//�� ��������� ������ ����� ���� ����� ����, ����� ������ 
		while(!fin.eof()){//���� ��������� ��������� �� ����� �����
			fin>>s>>io;//�� �� ������ ������� ���������� � ������ � ������� ��������. � �� ���������� �������� � ��
			for(int j=0; j<nval; j++)//
				fin>>val[j];//�� ������ ��� �� ���������� � ������ ��� ������ ������
			if(val[mymin(val,nval)]>8){//�� ��������� �� ���������. ��� ����� �����  ������ ����������� ������� �� ���� ��� ������
				mycat(s, " "); mycat(s, io);//������� ������ ���������� � ����� ������ � ������ ������, �� �� ����� ������� ������ � ����� ������ � ������� ��� ��������
				fout<<left<<setw(18)<<s<<" ������ "<<i+1<<endl;//� ������ �� ������� ������� � �������� ��������, ����� ����� ������ � ����� ������ ������ i ���������� � 0
				nstud++;//����� ++ ��� ���������� ����������. ���� ��� �������� �� ������� �� ������������ �� �������
			}
		}
		fin.close();//��������� ����� � ������ ������ 1 ����� 2 ����� 3
	}
	fout.close();//����� �������� �� ���� ������� � �������� ���������� ��������� ���� ���������
	file2scn(fin, "���������.txt");//� ����� �������� ���� �� ����� ��������� ���� ��������� �� ������� ������ � ������� �� �����
}
{cout<<"=== ������� 8 =================\n";
	char* s = new char[128];
	int nstud = myinput(s, "���������.txt");
	char** srt = new char*[nstud];
	char* p = s;
	for(int i=0; i<nstud; i++){
		srt[i] = p;
		p += mylen(p)+1;
	}
	mysrt(srt,nstud,1);
	ofstream fout; myopen(fout, "���������.txt");
	for(int i=0; i<nstud; i++)
		fout<<srt[i]<<endl;
	fout.close();
	ifstream fin; file2scn(fin, "���������.txt");
	delete[]s; delete[]srt;
}
{//cout<<"=== ������� 9 =================\n";
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

	student st1 = {"��������� �.�.", 5, 7.25, "2001.04.17", "29-361-90-14"};
	fout.write((char*)&st1, sizeof(st1));

	fout.close();
}
{cout<<"=== ������� 10 =================\n";
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


//������� 5 � 8
void myopen(ifstream &fin, const char* fname, const int mode){ //��� ����������� ���������, ������ �� �����, ����� �������� ����� � ����� �������� �����
	fin.open(fname, mode);
	if(!fin.is_open())
		cout<<"\n������ �������� ����� "<<fname<<endl;
}

void myopen(ofstream &fout, const char* fname, const int mode){
	fout.open(fname, mode);
	if(!fout.is_open())
		cout<<"\n������ �������� ����� "<<fname<<endl;
}

//������� 9
void file2scn(ifstream &fin, const char* fname, const int maxlen){	//�� �������� � ������� ������ �� ������� �����, ��� ����� � ������������ ����� ������ ������� ����� �������
	char* s = new char[maxlen];//������� ������������ ������ s � ����������� �� ������ ���� ���
	myopen(fin, fname);//��������� ���� � ������� ���������� �������
	while(!fin.eof()){	//���� ���� ����������� ���� ���� �� ���������� ��� ��� ��� ��������� �� ����� �����
		fin.getline(s,maxlen);//�� ���� ��������� ������ �� ����� � � �� � ������ � � ����� ������� ������
		cout<<s<<endl;
	}
	fin.close(); delete[]s;//��������� ����� � ������� ������������ ������ 
}