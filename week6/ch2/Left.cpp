#include<stdio.h>
#include<stdlib.h>
#include"LeapHeap.h"

struct HeapStruct//������һ����ͷ ����������ȼ����е�����
				 //��ǰ���еĴ�С,�����Ƕ������һ��Ԫ�ص�����
				 //�Լ�һ��ָ������׵�ַ��ָ��
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
//struct HeapStruct//������һ����ͷ ����������ȼ����е�����
//				 //��ǰ���еĴ�С,�����Ƕ������һ��Ԫ�ص�����
//				 //�Լ�һ��ָ������׵�ַ��ָ��
//{
//	int Capacity;
//	int Size;
//	ElementType* Elements;
//};

PriorityQueue Initialize(void)
{
	return NULL;
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
	H->Right = Change;
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
	SingleNode->Element = X; 
	SingleNode->Npl = 0;
	SingleNode->Left = SingleNode->Right = NULL;
	H = Merge(SingleNode,H);
	return H;
}
PriorityQueue DeleteMin1(PriorityQueue H)
{
	PriorityQueue LeftHeap, RightHeap;
	if (IsEmpty(H))
	{
		printf("�����ȶ���Ϊ��");
		return H;
	}
	LeftHeap = H->Left;
	RightHeap = H->Right;
	free(H);
	return Merge(LeftHeap, RightHeap);
}
int IsEmpty(PriorityQueue H)
{
	return H == NULL;
}
ElementType FindMin(PriorityQueue H)
{
	if(!IsEmpty(H))
	   return H->Element;
	return 0;
}
int main()
{
	PriorityQueue H;
	int i, j,b;

	H = Initialize();
	for (i = 0, j = 5; i < 2; i++, j = (j + 17) % 10)
		 H=Insert1(j, H);
	b = FindMin(H);
	printf("%d",b);


	j = 0;
	while (!IsEmpty(H))
		if (FindMin(H) != j++)
			printf("Error in DeleteMin, %d\n", j);
		else
			H = DeleteMin1(H);
	
	system("Pause");


	
}

