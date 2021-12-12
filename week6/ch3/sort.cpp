#include<stdio.h>
#include<stdlib.h>
#include"sort.h"

void Swap(int *a, int *b)
{
	int* Tmp;
	Tmp = a;
	a = b;
	b = Tmp;
}

/******插入排序******/
void InsertionSort(int A[], int N)
{
	int j,P;
	int Tmp;
	for (P = 1; P < N; P++)
	{
		Tmp = A[P];//放下一个要处理的元素

		/*下面几条语句避免使用交换3条语句*/
		for (j = P; j > 0 && A[j - 1] > Tmp; j--)//如果存在前面的元素大于该元素
		{
			A[j] = A[j - 1];//整体向前移动
		}
		A[j] = Tmp;//放入该元素；for循环里面的变量计算仍然有效
	}
}



/******希尔排序******/
void ShellSort(int A[], int N)//希尔排序
{
	int i, j, Increment;
	int Tmp;
	for (Increment=N/2;Increment>0;Increment/=2)
		for (i = Increment; i < N; i++)
		{
			Tmp = A[i];
			for (j = i; j >= Increment; j -= Increment)
			{
				if (Tmp < A[j - Increment])
					A[j] = A[j - Increment];
				else
					break;
				A[j] = Tmp;
			}
		}
}










