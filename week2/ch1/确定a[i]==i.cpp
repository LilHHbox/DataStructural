#include <stdio.h>
int main()
{
	int A[10] = { -2,-1,0,3,7,9,11,20,21,30 };
	/**************方法一***************/
	for (int i = 0; i <= 9; i++)
	{
		if (A[i] == i)
			printf("1.i=%d\n", i);
	}
	//所用时间为O(N)



	/**************方法二***************/
	for (int j = 0; j <= 9; j++)
	{
		if (A[j] > j)
		{
			
			break;
		}
		 //此处用到了数列是从小到大排列，如果碰到A[j]>j,则证明一定不存在
		else if (A[j] == j)
			printf("2.j=%d\n", j);
	}
	//所用时间为O(N)
	void way3(int array[], int N);
	way3(A, 10);
	//所用时间为O(N/2)




	return 0;

}
void way3(int array[], int N)//二分法
{
	int M,l;
	if (N % 2 == 1)//奇数
	{
		M = (N + 1) / 2;
		if(array[M]>M)//则一定在0~M范围内
			for(l=0;l<=M;l++)
				if (array[l] > l)
				{
				
					break;
				}//此处用到了数列是从小到大排列，如果碰到A[l]>l,则证明一定不存在
				else if (array[l] == l)
				{
					printf("3.l=%d\n", l);
				}

	}
	else if (N % 2 == 0)//偶数
		M = N  / 2;
	if (array[M] > M)//则一定在0~M范围内
		for (l = 0; l <= M; l++)
			if (array[l] > l)
			{
	
				break;
			}//此处用到了数列是从小到大排列，如果碰到A[l]>l,则证明一定不存在
			else if (array[l] == l)
			{
				printf("3.l=%d\n", l);
			}

}