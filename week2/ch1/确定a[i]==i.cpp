#include <stdio.h>
int main()
{
	int A[10] = { -2,-1,0,3,7,9,11,20,21,30 };
	/**************����һ***************/
	for (int i = 0; i <= 9; i++)
	{
		if (A[i] == i)
			printf("1.i=%d\n", i);
	}
	//����ʱ��ΪO(N)



	/**************������***************/
	for (int j = 0; j <= 9; j++)
	{
		if (A[j] > j)
		{
			
			break;
		}
		 //�˴��õ��������Ǵ�С�������У��������A[j]>j,��֤��һ��������
		else if (A[j] == j)
			printf("2.j=%d\n", j);
	}
	//����ʱ��ΪO(N)
	void way3(int array[], int N);
	way3(A, 10);
	//����ʱ��ΪO(N/2)




	return 0;

}
void way3(int array[], int N)//���ַ�
{
	int M,l;
	if (N % 2 == 1)//����
	{
		M = (N + 1) / 2;
		if(array[M]>M)//��һ����0~M��Χ��
			for(l=0;l<=M;l++)
				if (array[l] > l)
				{
				
					break;
				}//�˴��õ��������Ǵ�С�������У��������A[l]>l,��֤��һ��������
				else if (array[l] == l)
				{
					printf("3.l=%d\n", l);
				}

	}
	else if (N % 2 == 0)//ż��
		M = N  / 2;
	if (array[M] > M)//��һ����0~M��Χ��
		for (l = 0; l <= M; l++)
			if (array[l] > l)
			{
	
				break;
			}//�˴��õ��������Ǵ�С�������У��������A[l]>l,��֤��һ��������
			else if (array[l] == l)
			{
				printf("3.l=%d\n", l);
			}

}