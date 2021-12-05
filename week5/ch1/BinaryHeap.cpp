#include<stdio.h>
#include<stdlib.h>
#include"BinaryHeap.h"


//二叉堆：一个完全二叉树，其里面的每个树的父亲节点小于他的儿子


struct HeapStruct//类似于一个表头 里面包括优先级队列的容量
	             //当前队列的大小,或者是队列最后一个元素的数字
	             //以及一个指向队列首地址的指针
{
	int Capacity;
	int Size;
	ElementType* Elements;
};

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));//因为队列是从0开始，所以MaxElements要加一
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = 0;//此时的0代表最小值MinData
	return H;
}
void Insert(ElementType X, PriorityQueue H) 
{
	int i;//注意在循环外面定义i变量
	if (IsFull(H))
	{
		printf("该队列已满");
			return;
	}
	for (i = ++H->Size; H->Elements[i / 2]; i = i / 2)//++H->Size:H->Size指向队尾的空单元
											   //H->Elements[i/2]>X:该点的父亲大于他
	{
		H->Elements[i] = H->Elements[i / 2];//避免进行交换用到的3条语句
	}
		H->Elements[i] = X;
	
 }
ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		printf("优先队列为空");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size];
	H->Size--;//因为要删除一个值，所以要--  


	for (i = 1; i * 2 <= H->Size; i = Child)//删除根节点  所以从1开始
	{
		Child = i * 2;//找到左儿子
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])//如果右儿子存在，且右儿子小于左儿子
			Child++;//Child指向右儿子
		/*这个if条件确保Child指向的是较小的儿子*/


		/*防止最后一步产生根比叶子大的情况*/
		if (LastElement > H->Elements[Child])//因为后面右一句 H->Elements[i] = LastElement;
			H->Elements[i] = H->Elements[Child];
		else break;
	}
	H->Elements[i] = LastElement;
	return MinElement;
}
ElementType FindMin(PriorityQueue H)
{
	if (!IsEmpty(H))
	{
		return H->Elements[1];
	}
	printf("优先队列为空");	
	return H->Elements[0];
}
int IsEmpty(PriorityQueue H)
{
	return H->Size == 0;
}
int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}
void Destory(PriorityQueue H)
{
	free(H->Elements);
	free(H);		  
}