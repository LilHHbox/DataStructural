/*******快速排序******/
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
	/*经过多次交换之后保证A[Left]<=A[Center]<=A[Right]*/

	return A[Right - 1];//把枢纽元和倒数第二个元素呼唤
}
#define Cutoff (3);
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if (Left + 3 <= Right)//保证元素个数大于4
	{
		Pivot = Median3(A, Left, Right);//枢纽元 
		i = Left; j = Right - 1;
		for (;;)//即使A[i]=A[j]=Pivot也能正常退出
		{
			while (A[++i] < Pivot) {}//i从Left+1开始
			while (A[--j] > Pivot) {}//j从Right-2开始
			if (i < j)
			{
				Swap(&A[i], &A[j]);
			}
			else
				break;//for循环终止条件：i>j
					  //因为是从Left+1开始的 所以就算i一次都不动，j疯狂左移
					  //也一定会出现j=left<i的情况 避免越界 
					  //同理i也是类似的情况
		}
		/*
		如果写成：
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
		出现的结果就是当A[i]=A[j]=Pivot时
		1和2语句永远不会执行
		而会一直有i<j,从而反复执行3和4语句
		当然也不用考虑A[i+1]=A[j-1]=Pivot的情况
		因为只要循环执行一次，要么i右移，要么j左移，而且肯定有一个移动
		所以不会陷入死循环
		*/
		Swap(&A[i], &A[Right - 1]);

		Qsort(A, Left, i - 1);
		Qsort(A, i + 1, Right);
	}
	else//如果元素个数较少 直接用插入排序
		InsertionSort(A + Left, Right - Left + 1);
}
/*函数入口*/
void Quicksort(int A[], int N)
{
	Qsort(A, 0, N - 1);
}