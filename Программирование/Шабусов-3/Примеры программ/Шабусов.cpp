/*==========================================
 ��������� ������������ ������ �3 ���������
         ��������� ������� ����� 
	      ��������� �����������
==========================================*/

//-- ������������ ����� ���������-----
#include <iostream>
#include <iomanip>

using namespace std;


// ������� ������� ���������-------
int main()
{
	setlocale(LC_ALL, "rus");
{	cout << "==== ������� �1 ======" << endl;
	int n;
	cout<<"������� ����� �������� �����: "; /*cin >> n;*/
	n=8; cout<<n<<endl;
	int a=0, b=1, c=a+b; int i=2;
	a=b; b=c; c= a+b; i=i++;  //C=F3, i=3
	a=b; b=c; c= a+b; i=i++;  //C=F4, i=4
	a=b; b=c; c= a+b; i=i++;  //C=F5, i=5
	a=b; b=c; c= a+b; i=i++;  //C=F6, i=6
	a=b; b=c; c= a+b; i=i++;  //C=F7, i=7
	a=b; b=c; c= a+b; i=i++;  //C=F8, i=8

	cout<<"����� ��������� � "<<n<<" = "<<c<<endl;

	a=0; b=1; c=a+b; i=2; n=24;
	while(i<n)
	{
		a=b; b=c; c=a+b; i++; //c=Fi
	}
	cout<<"����� ��������� � "<<n<<" = "<<c<<endl;
}
	
//--- ����� �� ������� �������-----
{	cout<<"===������� 2========="<<endl;
	double x1, y1, x2, y2, x3, y3;
	cout<<"������� ���������� ������ ������������: "<<endl;
	//cin>>x1>>y1>>x2>>y2>>x3>>y3;   //������ ���������� ������
	x1=3.5; y1=7.1; x2=6.8; y2=-5.4; x3=-8.2; y3=-4.7;
	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;

	double a, b, c;  //��������� ����� ������
	a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	b=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	c=sqrt((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));
	
	double p, s;
	p=(a+b+c)/2;
	s=sqrt(p*(p-a)*(p-b)*(p-c));
	cout<<"�������� ������������ = "<<p*2<<endl;
	cout<<"������� ������������ = "<<s<<endl;
	
}

{	cout<<"==������� 3========="<<endl;
	int num;  //cin>>num;
	cout<<"������� �����: ";//cin>>num;
	num=1759543401; cout<<num<<endl;
	const int nd = 10;
	int D[nd] = {2,3,5,7,11,13,17,19,23,29}; int i=0;
	if(num % D[i] == 0)          //��������� ��������� �� 2
	{
		cout<<"�����"<<num<<" ������� �� "<<D[i]<<endl;
	}
	i++;

	if(num % D[i] == 0)          //��������� ��������� �� 3
	{
		cout<<"�����"<<num<<" ������� �� "<<D[i]<<endl;
	}
	i++;

	if(num % D[i] == 0)          //��������� ��������� �� 5
	{
		cout<<"�����"<<num<<" ������� �� "<<D[i]<<endl;
	}
	i++;

	while(i<nd)
	{
		if(num % D[i] == 0)         //��������� �������� �� D[i]
		{
			cout<<"�����"<<num<<" ������� �� "<<D[i]<<endl;
		}
        i++;
	}
}

{	cout << "===������� 4===========" << endl;
	const double pi = acos(-1);
	double x, k1, k2;
	cout << "������� �������� ��������� � ���� �������������:" << endl;
	//cin>>x>>k1>>k2
	x = 1.4; k1 = 6; k2 = 5 / 3.; cout << x << " " << k1 << " " << k2 << endl << endl;

	double a = pi / k1, b = pi / k2; double res;
	res = pow(abs((-5 * pow(x, 4)*sin(a) + 4 * x*x*cos(b)*cos(b)) /
		          (2 * pow(cos(a + b), 4) + 1)), 1 / 3.);

	double p, q;				//���������� ��� ������������� ������
	p = (-5 * pow(x, 4)*sin(a) + 4 * x*x*cos(b)*cos(b));
	q = (2 * pow(cos(a + b), 4) + 1);
								//����� ������������� ������
	cout <<"��������� ������������ ���������   = "<< fixed << setw(16) << setprecision(6) << right << p << endl;
	cout << "����������� ������������ ��������� =  " << scientific << setw(15) << setprecision(6) << right << q << endl << endl;
	res = pow(abs(p / q), 1 / 3.);

								//����������������� �����
	cout << "�������� ��������� = " << res << endl;

								//��������������� �����
	cout << "�������� ��������� = "
		<< fixed				//����� ����� � ������������� ������
		<< setw(18)				//�������� ��� ����� ����� 18 ���������
		<< setprecision(8)		//�������� ��� ������� ����� 8 ���������
		<< left					//������������ �� ������ ����
		<< res					//����� ����������
		<< endl;				//������� �� ��������� ������

	cout << "�������� ��������� = "
		<< scientific			//����� ����� � ��������� ������
		<< setw(22)				//�������� ��� ����� ����� 22 ����������
		<< setprecision(10)		//�������� ��� ������� ����� 10 ���������
		<< right				//������������ �� ������� ����
		<< res					//����� ����������
		<< endl;				//������� �� ��������� ������


}
{   cout<<"===������� 5============"<<endl;
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

	//if(V[i]>mx)							//��������� � V[1]
	//	mx=V[i];
	//
	//i++;	
	//if(V[i]>mx)							//��������� � V[2]
	//	mx=V[i];
	//
	//i++;
	//if(V[i]>mx)							//��������� � V[3]
	//	mx=V[i];
	//
	//i++;	
	//if(V[i]>mx)							//��������� � V[4], i=nv=5
	//	mx=V[i];
	//
	//i++;	

	while(i<nv){
		if(V[i]>mx)							//��������� � V[i]
			mx=V[i];
		i++;}

	i=1;
	//if(V[i]<mn)							//��������� � V[1]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//��������� � V[2]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//��������� � V[3]
	//	mn=V[i];
	//
	//i++;	
	//if(V[i]<mn)							//��������� � V[4]
	//	mn=V[i];
	//
	//i++;									//i=nv=5

	while(i<nv){
		if(V[i]<mn)							//��������� � V[i]
			mn=V[i];
		i++;}

	cout<<fixed<<left<<setprecision(2);		//������ ������
	cout<<"������������ ������ = "<<mx<<endl;
	cout<<"����������� ������  = "<<mn<<endl;
	cout<<"������� ������      = "<<1.*sum/nv<<endl;

}

{ cout<<"===������� 6============"<<endl;
 const int maxlen=32;
 char s[maxlen]="11011101001101011001";
 int ns=strlen(s), num=0, i=ns-1, weight=1;

 if(s[i]=='1')								//s[19] - ������ 0
	 num+=weight;
 i--; weight*=2;
 if(s[i]=='1')								//s[18] - ������ 1
	 num+=weight;
 i--; weight*=2;
 if(s[i]=='1')								//s[17] - ������ 2
	 num+=weight;
 i--; weight*=2;
 while(i>=0){
	 if(s[i]=='1')							//s[i] - ������ ns - i - 1
	 num+=weight;
 i--; weight*=2;
 }
 cout<<"���������� �������� "<<s<<" = "<<num<<endl;
}
	cout << endl; system("pause");
	return 0;
}