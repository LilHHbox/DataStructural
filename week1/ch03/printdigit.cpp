#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{   /*��������*/
	extern int m,l;
	int m = 1;
	int a = 1;
	int b = 1;//����С����
	void PrintDigit(double n,int m);
	void PrintDigit_p(double n,int m,int l);//ֻ��һ���ַ�һ���ַ����  ��������
	void PrintDigit_n(double n,int m, int l);//��������
	void PrintDigit_zz(double n,int m);//��������
	void PrintDigit_xx(double n,int m,int l);//С������
	
	//double num1[2]
	double num,nnum,pnum;//pnum������  nnum:����
	int z, x=1;//z:�������֣�xС������
	printf("����3λ����С��������:");
	scanf("%lf",&num);
	if (num < 0)
	{
		nnum = fabs(num);
		PrintDigit_n(nnum,a,b);//����ֵ���� ���������������
	}
	else
	{
		pnum = num;
		PrintDigit_p(pnum,a,b);
	}
	
	return 0;
}
void PrintDigit(int n, int m)
{    
	printf("%d", n);
}
void PrintDigit_zz(int n, int m)//��������
{
	//printf("%d", n);
	if (n > 10)
	
		PrintDigit_zz(n / 10,m);
	PrintDigit(n % 10,m);
	
	
	
}
void PrintDigit_xx(double n,int m,int l)//С������
{
	
	if (l == 1)//����С����
	{
		char w = '.';
		printf("%c", w);
		l++;
	}
	double c, d, f,g;
	int b; 
	int temp = (int)(n * 1000000000);
	
	n = temp / 1000000000.0f;
	c = n * 10.0;//c=2.23
	b = (int)c;//b=2
	d = (double)b;//d=2

	if (c - d != 0 && m <= 5)
	{

		printf("%d", b);
		m++;
		PrintDigit_xx(c - d, m,l);
	}

}

void PrintDigit_p(double n,int m, int l)//ֻ��һ���ַ�һ���ַ����  ��������
{   
	double p,q;
	int o;
	o = (int)n;//ǿ��ת�� ������������
	p = (double)o;
	q = n - p;//qΪС������
	if (q != 0)
	{
		PrintDigit_zz(o, m);
		PrintDigit_xx(q, m, l);
	}
	else{ PrintDigit_zz(o, m); }
}
void PrintDigit_n(double n,int m, int l)//��������
{
	char s = '-';
	printf("%c", s);
	PrintDigit_p(n, m, l);
}
