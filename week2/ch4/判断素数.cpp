#include<stdio.h>
int main()
{
	void PrimeNumber1(int n);//way1:令n除以（2，n-1)，都有余数则为素数，若有一个没有余数，则不是素数
	void PrimeNumber2(int n);//way2:偶数一定不是素数，奇数可能是素数
	int N;
	printf("输入正整数N：");
	scanf("%d",&N);
	PrimeNumber1(N);
	PrimeNumber2(N);





	return 0;

}
void PrimeNumber1(int n)
{
	int re;
	if (n <= 3)
	{
		printf("1.该正整数是素数\n");

	}
	else
	{
		for (int i = 2; i <= n - 1; i++)
		{

			re = n % i;
			if (re == 0)
			{
				printf("1.该正整数不是素数\n");
				break;
			}
			else if (i == n - 1)
			{
				printf("1.该正整数是素数\n");
			}
		}

	}
}
void PrimeNumber2(int n)
{
	if (n <=3)
	{
		printf("2.该正整数是素数\n");
		
	 }
	else if (n % 2 == 0)
	{
		printf("2.该正整数不是素数\n");

	}

	else
	{
		int re;
		for (int i = 3; i <= n ; i=i+2)
		{
			if (n <= 3)
			{
				printf("2.该正整数是素数\n");
				break;

			}
			re = n % i;
			if (re == 0)
			{
				printf("2.该正整数不是素数\n");
				break;
			}
			else if (i == n)
			{
				printf("2.该正整数是素数\n");
			}

		}
	}

}