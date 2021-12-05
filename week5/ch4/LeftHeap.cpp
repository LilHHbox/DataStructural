#include<stdio.h>
#include<stdlib.h>
#include"LeapHeap.h"

struct HeapStruct//类似于一个表头 里面包括优先级队列的容量
				 //当前队列的大小,或者是队列最后一个元素的数字
				 //以及一个指向队列首地址的指针
{
	int Capacity;
	int Size;
	ElementType* Elements;
};
struct TreeNode
{
	ElementType Element;
	PriorityQueue Left;
	PriorityQueue Right;
	int Npl;
};
//struct HeapStruct//类似于一个表头 里面包括优先级队列的容量
//				 //当前队列的大小,或者是队列最后一个元素的数字
//				 //以及一个指向队列首地址的指针
//{
//	int Capacity;
//	int Size;
//	ElementType* Elements;
//};

PriorityQueue Initialize(PriorityQueue H)
{
	H = (PriorityQueue)malloc(sizeof(struct TreeNode));
	H->Element = NULL;
	H->Left = NULL;
	H->Right = NULL;
	H->Npl = 0;
	return H;
}
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
	if (H1 == NULL)
		return H2;
	if (H2 == NULL)
		return H1;
	if (H1->Element < H2->Element)
		return Merge1(H1, H2);
	else
		return Merge1(H1, H2);
}
void SwapChildren(PriorityQueue H)
{
	PriorityQueue Change;
	Change = H->Left;
	H->Left = H->Right;
	H->Right = H->Left;
}
PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
	if (H1->Left == NULL)
		H1->Left = H2;
	else
	{
		H1->Right = Merge(H1->Right, H2);
		if (H1->Left->Npl < H1->Right->Npl)
		{
			SwapChildren(H1);
		}
		H1->Npl = H1->Right->Npl + 1;
	}
	return H1;
}
PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
	PriorityQueue SingleNode;
	SingleNode = (PriorityQueue)malloc(sizeof(struct TreeNode));
	SingleNode->Element = X; SingleNode->Npl = 0;
	SingleNode->Left = SingleNode->Right = NULL;
	H = Merge(SingleNode,H);
	return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	if (IsEmpty(H))
	{
		printf("该优先队列为空");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
int IsEmpty(PriorityQueue H)
{
	return H->Element == NULL;
}
ElementType FindMin(PriorityQueue H)
{
	return H->Element;
}
int main()
{
	PriorityQueue H=NULL;
	H = Initialize(H);
	PriorityQueue C ;
	int a[8] = { 3,10,8,21,14,17,23,5 };
	for (int i = 0; i <= 7; i++)
	{
		C = Insert1(a[i], H);
	}
	int b;
	b = FindMin(H);
	printf("%d", b);
}

