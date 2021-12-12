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

/******��������******/
void InsertionSort(int A[], int N)
{
	int j,P;
	int Tmp;
	for (P = 1; P < N; P++)
	{
		Tmp = A[P];//����һ��Ҫ�����Ԫ��

		/*���漸��������ʹ�ý���3�����*/
		for (j = P; j > 0 && A[j - 1] > Tmp; j--)//�������ǰ���Ԫ�ش��ڸ�Ԫ��
		{
			A[j] = A[j - 1];//������ǰ�ƶ�
		}
		A[j] = Tmp;//�����Ԫ�أ�forѭ������ı���������Ȼ��Ч
	}
}



/******ϣ������******/
void ShellSort(int A[], int N)//ϣ������
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










