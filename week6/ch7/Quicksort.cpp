/*******��������******/
int	Median3(int A[], int Left, int Right)
{

	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
	{
		Swap(&A[Left], &A[Center]);

	}
	if (A[Left] > A[Right])
	{
		Swap(&A[Left], &A[Right]);

	}
	if (A[Center] > A[Right])
	{
		Swap(A[Center], A[Right]);

	}
	Swap(&A[Center], &A[Right - 1]);
	/*������ν���֮��֤A[Left]<=A[Center]<=A[Right]*/

	return A[Right - 1];//����ŦԪ�͵����ڶ���Ԫ�غ���
}
#define Cutoff (3);
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if (Left + 3 <= Right)//��֤Ԫ�ظ�������4
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
		Swap(&A[i], &A[Right - 1]);

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