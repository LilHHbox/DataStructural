#include<stdio.h>
int main()
{
	void PrimeNumber1(int n);//way1:��n���ԣ�2��n-1)������������Ϊ����������һ��û����������������
	void PrimeNumber2(int n);//way2:ż��һ��������������������������
	int N;
	printf("����������N��");
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
		printf("1.��������������\n");

	}
	else
	{
		for (int i = 2; i <= n - 1; i++)
		{

			re = n % i;
			if (re == 0)
			{
				printf("1.����������������\n");
				break;
			}
			else if (i == n - 1)
			{
				printf("1.��������������\n");
			}
		}

	}
}
void PrimeNumber2(int n)
{
	if (n <=3)
	{
		printf("2.��������������\n");
		
	 }
	else if (n % 2 == 0)
	{
		printf("2.����������������\n");

	}

	else
	{
		int re;
		for (int i = 3; i <= n ; i=i+2)
		{
			if (n <= 3)
			{
				printf("2.��������������\n");
				break;

			}
			re = n % i;
			if (re == 0)
			{
				printf("2.����������������\n");
				break;
			}
			else if (i == n)
			{
				printf("2.��������������\n");
			}

		}
	}

}