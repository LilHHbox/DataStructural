#include<stdio.h>
int main()
{
	int array[8] = { 4,-2,1,-2,-1,2,6,-2 };
	printf("******��С�����кͣ����ϵ����ַ�����******\n");//���տα�����
	void MinSumSequance1(int A[], int N);
	MinSumSequance1(array,8);


	printf("******��С�������кͣ����ϵڶ��ַ�����******\n");//ʱ�临�Ӷ�n��
	int MinSumSequance2_1(int A[], int N);
	int a=MinSumSequance2_1(array, 8);
	printf("��С�������к�Ϊ%d\n", a);


//	printf("******��С���������кͣ����ϵĵ����ַ�����******\n");
// int MinSumSequance2_2(int A[], int left,int right);
//	int b = MinSumSequance2_2(array, 0,7);
//	printf("%d", b);
	printf("******��������г˻�******\n");
	void MaxMupSequence(int A[], int N);
	MaxMupSequence(array, 8);
	return 0; 
}
void MinSumSequance1(int A[], int N)
{
	int TheMin=0, MinSum=0;
	for (int i = 0; i <= N-1; i++)
	{
		TheMin += A[i];
		if (TheMin <= 0)
		{
			if (TheMin < MinSum)
			{
				MinSum = TheMin;
			}
		}
		else
			TheMin = 0;
        
	}
	printf("��С�����к�Ϊ%d\n", MinSum);
}
int MinSumSequance2_1(int A[], int N)
{
	int ThisSum, MinSum, i, j, k;
	for (int m = 1; m < N; m++)//����������ֵ
	{
		if (A[m] > A[0])
		{
			k = A[0];
			A[0] = A[m];
			A[m] = k;
		}
	}
	MinSum = A[0];
	for (i = 0; i < N; i++)
	{
		ThisSum = 0;
		for (j = i; j < N; j++)
		{
			ThisSum += A[j];
			if (ThisSum < MinSum && ThisSum>0)
				MinSum = ThisSum;
		}
	}
	return MinSum;
}
/*int MinSumSequance2_2(int A[], int left, int right)
{
	if (left == right)
		if (A[left] > 0)
			return A[left];
		else
			return 0;
	int center = (left + right) / 2;
	int LeftSum = MinSumSequance2_2(A, left, center);
	int RightSum = MinSumSequance2_2(A, center+1,right);*/
void MaxMupSequence(int A[], int N)
{
	int TheMax ,MaxSum=1;
	for (int i = 0; i < N; i++)
	{
		TheMax = 1;
		for (int j = i; j < N; j++)
		{
			TheMax *= A[j];
			if (TheMax > MaxSum)
			{
				MaxSum = TheMax;
			}
		}
		
	}
printf("��������г˻�Ϊ%d",MaxSum);









}