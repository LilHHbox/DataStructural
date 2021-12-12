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




/*******堆排序*******/
//整个操作都是在数组上进行的，先把这个数组构造成一个有max堆序的二叉堆，然后通过频繁的下滤操作排列根节点
#define LeftChild(i) (2*(i)+1)//左儿子
void PercDown(int  A[], int i, int N)//////下滤
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)//LeftChild(i) < N是为了防止越界
	{
		Child = LeftChild(i);//如果存在左儿子就把指向左儿子
		if (Child != N - 1 && A[Child + 1] > A[Child])//右儿子存在的话就与左儿子比较
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;//上面及条语句避免了交换用到的三条繁琐语句
}
void HeapSort(int A[], int N)
{
	int i,Tmp;
	for (i = N / 2; i >= 0; i--)//N/2的原因是 堆的构建从非叶子节点开始
		PercDown(A, i, N);//堆构建完成
	for (i = N - 1; i > 0; i--)
	{
		Tmp = A[i];
		A[i] = A[0];
		A[0] = Tmp;
		//把此时最大的  根节点的元素放到数组末尾
		//因为此阶段调用了一次下滤函数，所以没办法用以前的便捷操作省略
		//只能使用三条语句的交换

		PercDown(A, 0, i);//每换一次下滤一次，保证堆序
	}
}





/*****归并排序********/
void MSort(int A[], int TmpArray[], int Left, int Right)
{
	int Center;
	if (Left < Right)//无限递归直到左右各有一个元素的时候即Left==Right
	{
		Center = (Left + Right) / 2;
		MSort(A, TmpArray, Left, Center);//左边
		MSort(A, TmpArray, Center + 1, Right);//右边
		Merge(A, TmpArray, Left, Center + 1, Right);//左右合并
	}
}
/*函数入口*/
void Mergesort(int A[], int N)
{
	int* TmpArray;
	TmpArray =(int*) malloc(N * sizeof(int));//分配一个相等大小的数组并返回地址
	MSort(A, TmpArray, 0, N - 1);
	free(TmpArray);
	
}
void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)//Lpos：左边的位置，刚开始指向的是左边部分的第一个元素，也是数组的第一个元素 
                                                                     //Rpos：右边的位置，刚开始指向的是右边部分的第一个元素 
	                                                                 //RightEnd：右边界，防止越界
{                                                        
	int i, LeftEnd, NumElements, TmpPos;//LeftEnd:左边界防越界
	LeftEnd = Rpos - 1;//初始化
	TmpPos = Lpos;//刚开始指向数组的第一个元素
	NumElements = RightEnd - Lpos + 1;//元素的个数

	while (Lpos <= LeftEnd && Rpos <= RightEnd)//循环终止条件：左右其中一个部分比较完
	{
		if (A[Lpos] <= A[Rpos])
		{
			TmpArray[TmpPos++] = A[Lpos++];//后++，先赋值后++
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}//全部赋给TmpArray

	while (Lpos <= LeftEnd)//把左边剩余部分赋给TmpArray数组
	{
		TmpArray[TmpPos++];
	}
	while (Rpos <= RightEnd)//把右边剩余部分赋给TmpArray数组
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}

	for (i = 0; i < NumElements; i++, RightEnd--)//把该数组拷贝回原数组
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}



/*******快速排序******/
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
	/*经过多次交换之后保证A[Left]<=A[Center]<=A[Right]*/

	return A[Right - 1];//把枢纽元和倒数第二个元素呼唤
}
#define Cutoff (3);
void Qsort(int A[], int Left, int Right)
{
	int i, j;
	int Pivot;
	if(Left+3<=Right)//保证元素个数大于4
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
		Swap(&A[i],&A[Right - 1]);

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