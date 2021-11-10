#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main()
{   /*函数声明*/
	extern int m,l;
	int m = 1;
	int a = 1;
	int b = 1;//控制小数点
	void PrintDigit(double n,int m);
	void PrintDigit_p(double n,int m,int l);//只能一个字符一个字符输出  正数处理
	void PrintDigit_n(double n,int m, int l);//负数处理
	void PrintDigit_zz(double n,int m);//整数处理
	void PrintDigit_xx(double n,int m,int l);//小数处理
	
	//double num1[2]
	double num,nnum,pnum;//pnum：正数  nnum:负数
	int z, x=1;//z:整数部分，x小数部分
	printf("输入3位以内小数或整数:");
	scanf("%lf",&num);
	if (num < 0)
	{
		nnum = fabs(num);
		PrintDigit_n(nnum,a,b);//绝对值函数 负数变成整数处理
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
void PrintDigit_zz(int n, int m)//整数处理
{
	//printf("%d", n);
	if (n > 10)
	
		PrintDigit_zz(n / 10,m);
	PrintDigit(n % 10,m);
	
	
	
}
void PrintDigit_xx(double n,int m,int l)//小数处理
{
	
	if (l == 1)//控制小数点
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

void PrintDigit_p(double n,int m, int l)//只能一个字符一个字符输出  正数处理
{   
	double p,q;
	int o;
	o = (int)n;//强制转换 保留整数部分
	p = (double)o;
	q = n - p;//q为小数部分
	if (q != 0)
	{
		PrintDigit_zz(o, m);
		PrintDigit_xx(q, m, l);
	}
	else{ PrintDigit_zz(o, m); }
}
void PrintDigit_n(double n,int m, int l)//负数处理
{
	char s = '-';
	printf("%c", s);
	PrintDigit_p(n, m, l);
}
