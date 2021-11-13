#include<stdio.h>
#include<math.h>
int main()
{
	void MainEleEven(int Array[],int N);
	void MainEleOdd(int Array[], int Array1[], int N);
	int a[8] = { 3,4,2,4,4,2,4,4 };
	int b[7] = { 3,4,2,4,4,2,4 };
	int bcopy[7] = { 3,4,2,4,4,2,4 };
	MainEleEven(a,8);
	MainEleOdd(b, bcopy, 7); 
                    //奇数序列主要元素的思想：
	                //如果前N-1有主要元素，第N个造成不了影响，
	                //如果没有，第N个可能是主要元素，
	                //如果第N个不是，那就没有主要元素。
	return 0;
}
void MainEleEven(int Array[], int N)
{
		if (Array[0] == Array[1])//判断该序列第一个第二个元素是否相等
		{
			Array[1] = Array[2];
			int e = Array[2] = '*';
			for (int j = 2; j < N - 2; j++)//相等则保留一个 另一个赋为*  并放到数组最后
			{
				Array[j] = Array[j + 1];
			}
			Array[N - 1] = e;
		}
		else//若不相等直接赋为*  然后放到数组最后
		{
			Array[0] = Array[2];
			Array[1] = Array[3];
			int c = Array[2] = '*';
			int d = Array[3] = '*';
			for (int j = 2; j < N - 3; j = j + 2)
			{
				Array[j] = Array[j + 2];
				Array[j + 1] = Array[j + 3];
			}
			Array[N - 3] = c;
			Array[N - 1] = d;

		}



		if (Array[1] != '*')
		{
			if (Array[0] == '*')
				printf("1.该偶序列没有主要元素\n");
			else
			{
				MainEleEven(Array, N);
			}
		}
		else
		{
			 printf("1.该偶序列主要元素为%d\n", Array[0]);
		}

}

void MainEleOdd(int Array[], int Array1[], int N)
{

	
	if (Array[0] == Array[1])//判断该序列第一个第二个元素是否相等
	{
		Array[1] = Array[2];
		int e = Array[2] = '*';
		for (int j = 2; j < N - 3; j++)//相等则保留一个 另一个赋为*  并放到数组最后
		{
			Array[j] = Array[j + 1];
		}
		Array[N - 2] = e;
	}
	else//若不相等直接赋为*  然后放到数组最后
	{
		Array[0] = Array[2];
		Array[1] = Array[3];
		int c = Array[2] = '*';
		int d = Array[3] = '*';
		for (int j = 2; j < N - 4; j = j + 2)
		{
			Array[j] = Array[j + 2];
			Array[j + 1] = Array[j + 3];
		}
		Array[N - 3] = c;
		Array[N - 2] = d;

	}


	/*输出判断*/
	
	if (Array[1] != '*')
	{
		if (Array[0] == '*')
		{
			printf("1.该偶序列没有主要元素\n");
		}
		else
		{
			MainEleOdd(Array,Array1,N);
		}
	}
	else if(Array[0] == '*')
	{
			int count = 0;
			for (int i = 0; i < N; i++)
			{
				if (Array1[i] == Array1[N - 1])
				{
					count++;
				}
			}
			if (count > N / 2)
			{
				printf("2.该奇序列主要元素为%d\n", Array1[N - 1]);
			}
			else
			{
				printf("2.该奇序列没有主要元素\n");
			}
		}
	else
	{	printf("2.该奇序列主要元素为%d\n", Array[0]);
	}

}
	/*for (int j = 0; j < N; j++)
	{
		if (Array[j] != '*')
			count++;	
	}*/

	/*for (int j = 0; j < N; j++)
	{
		if (Array1[j] != '*')
			count++;
	}*/

/*	if (count == 1)
	{
		printf("主要元素为%d", Array[0]);
	}
	else
		MainEle(Array,N);

}*/
/*void MainEle1(int Array[], int Array1[], int N, int count)
{
	for (int i = 0; i < N - 1; i = i + 2)
	{
		if (Array[i] == Array[i + 1])
			Array1[i] = Array[i];
	}
	for (int j = 0; j < N; j++)
	{
		Array[j] = '*';

	}
	/*for (int j = 0; j < N; j++)
	{
		if (Array1[j] != '*')
			count++;
	}

	if (N == 1)
	{
		printf("主要元素为%d", Array1[0]);
	}
	else
		MainEle(Array1, Array, N / 2, count);

}*/








