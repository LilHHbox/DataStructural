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




/*******������*******/
//�������������������Ͻ��еģ��Ȱ�������鹹���һ����max����Ķ���ѣ�Ȼ��ͨ��Ƶ�������˲������и��ڵ�
#define LeftChild(i) (2*(i)+1)//�����
void PercDown(int  A[], int i, int N)//////����
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)//LeftChild(i) < N��Ϊ�˷�ֹԽ��
	{
		Child = LeftChild(i);//�����������ӾͰ�ָ�������
		if (Child != N - 1 && A[Child + 1] > A[Child])//�Ҷ��Ӵ��ڵĻ���������ӱȽ�
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;//���漰���������˽����õ��������������
}
void HeapSort(int A[], int N)
{
	int i,Tmp;
	for (i = N / 2; i >= 0; i--)//N/2��ԭ���� �ѵĹ����ӷ�Ҷ�ӽڵ㿪ʼ
		PercDown(A, i, N);//�ѹ������
	for (i = N - 1; i > 0; i--)
	{
		Tmp = A[i];
		A[i] = A[0];
		A[0] = Tmp;
		//�Ѵ�ʱ����  ���ڵ��Ԫ�طŵ�����ĩβ
		//��Ϊ�˽׶ε�����һ�����˺���������û�취����ǰ�ı�ݲ���ʡ��
		//ֻ��ʹ���������Ľ���

		PercDown(A, 0, i);//ÿ��һ������һ�Σ���֤����
	}
}





/*****�鲢����********/
void MSort(int A[], int TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)//���޵ݹ�ֱ�����Ҹ���һ��Ԫ�ص�ʱ��Left==Right
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);//���
		MSort(A, TmpArray, Center + 1, Right);//�ұ�
		Merge(A, TmpArray, Left, Center + 1, Right);//���Һϲ�
	}
}
/*�������*/
void Mergesort(int A[], int N)
{
	int* TmpArray;
	TmpArray =(int*) malloc(N * sizeof(int));//����һ����ȴ�С�����鲢���ص�ַ
	MSort(A, TmpArray, 0, N - 1);
	free(TmpArray);
	
}
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)//Lpos����ߵ�λ�ã��տ�ʼָ�������߲��ֵĵ�һ��Ԫ�أ�Ҳ������ĵ�һ��Ԫ�� 
                                                                     //Rpos���ұߵ�λ�ã��տ�ʼָ������ұ߲��ֵĵ�һ��Ԫ�� 
	                                                                 //RightEnd���ұ߽磬��ֹԽ��
{                                                        
	int i, LeftEnd, NumElements, TmpPos;//LeftEnd:��߽��Խ��
	LeftEnd = Rpos - 1;//��ʼ��
	TmpPos = Lpos;//�տ�ʼָ������ĵ�һ��Ԫ��
	NumElements = RightEnd - Lpos + 1;//Ԫ�صĸ���

	while (Lpos <= LeftEnd && Rpos <= RightEnd)//ѭ����ֹ��������������һ�����ֱȽ���
	{
		if (A[Lpos] <= A[Rpos])
		{
			TmpArray[TmpPos++] = A[Lpos++];//��++���ȸ�ֵ��++
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}//ȫ������TmpArray

	while (Lpos <= LeftEnd)//�����ʣ�ಿ�ָ���TmpArray����
	{
		TmpArray[TmpPos++];
	}
	while (Rpos <= RightEnd)//���ұ�ʣ�ಿ�ָ���TmpArray����
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}

	for (i = 0; i < NumElements; i++, RightEnd--)//�Ѹ����鿽����ԭ����
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}



/*******��������******/
int	Median3(int A[], int Left, int Right)
{
	
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
	{
		Swap(&A[Left],&A[Center]);
		
	}
	if (A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]);
		
	}
	if (A[Center] > A[Right])
	{
		Swap( A[Center],A[Right]);
	
	}
	Swap(&A[Center],&A[Right - 1]);
	/*������ν���֮��֤A[Left]<=A[Center]<=A[Right]*/

	return A[Right - 1];//����ŦԪ�͵����ڶ���Ԫ�غ���
}
#define Cutoff (3);
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if(Left+3<=Right)//��֤Ԫ�ظ�������4
	{
		Pivot = Median3(A, Left, Right);//��ŦԪ 
		i = Left; j = Right - 1;
		for (;;)//��ʹA[i]=A[j]=PivotҲ�������˳�
		{
			while (A[++i] < Pivot) {}//i��Left+1��ʼ
			while (A[--j] > Pivot) {}//j��Right-2��ʼ
			if (i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
				break;//forѭ����ֹ������i>j
			          //��Ϊ�Ǵ�Left+1��ʼ�� ���Ծ���iһ�ζ�������j�������
                      //Ҳһ�������j=left<i����� ����Խ�� 
			          //ͬ��iҲ�����Ƶ����
		}
		/*
		���д�ɣ�
		i=Left;j=Right-2;
		for(;;)
		{
		   1.   while(A[i]<Pivot)i++;
		   2.   while(A[j]>Pivot)j++;
		   3.   if(i<j)
		   4.   Swap(&A[i],,&A[j]);
			else 
		       break;

		}
		���ֵĽ�����ǵ�A[i]=A[j]=Pivotʱ
		1��2�����Զ����ִ��
		����һֱ��i<j,�Ӷ�����ִ��3��4���
		��ȻҲ���ÿ���A[i+1]=A[j-1]=Pivot�����
		��ΪֻҪѭ��ִ��һ�Σ�Ҫôi���ƣ�Ҫôj���ƣ����ҿ϶���һ���ƶ�
		���Բ���������ѭ��
		*/
		Swap(&A[i],&A[Right - 1]);

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else//���Ԫ�ظ������� ֱ���ò�������
		InsertionSort(A + Left, Right - Left + 1);
}
/*�������*/
void Quicksort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}