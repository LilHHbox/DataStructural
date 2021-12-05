#include<stdio.h>
#include<stdlib.h>
#include"BinaryHeap.h"


//����ѣ�һ����ȫ���������������ÿ�����ĸ��׽ڵ�С�����Ķ���


struct HeapStruct//������һ����ͷ ����������ȼ����е�����
	             //��ǰ���еĴ�С,�����Ƕ������һ��Ԫ�ص�����
	             //�Լ�һ��ָ������׵�ַ��ָ��
{
	int Capacity;
	int Size;
	ElementType* Elements;
};

PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	H = (PriorityQueue)malloc(sizeof(struct HeapStruct));
	H->Elements = (ElementType*)malloc((MaxElements + 1) * sizeof(ElementType));//��Ϊ�����Ǵ�0��ʼ������MaxElementsҪ��һ
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = 0;//��ʱ��0������СֵMinData
	return H;
}
void Insert(ElementType X, PriorityQueue H) 
{
	int i;//ע����ѭ�����涨��i����
	if (IsFull(H))
	{
		printf("�ö�������");
			return;
	}
	for (i = ++H->Size; H->Elements[i / 2]; i = i / 2)//++H->Size:H->Sizeָ���β�Ŀյ�Ԫ
											   //H->Elements[i/2]>X:�õ�ĸ��״�����
	{
		H->Elements[i] = H->Elements[i / 2];//������н����õ���3�����
	}
		H->Elements[i] = X;
	
 }
ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	if (IsEmpty(H))
	{
		printf("���ȶ���Ϊ��");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size];
	H->Size--;//��ΪҪɾ��һ��ֵ������Ҫ--  


	for (i = 1; i * 2 <= H->Size; i = Child)//ɾ�����ڵ�  ���Դ�1��ʼ
	{
		Child = i * 2;//�ҵ������
		if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])//����Ҷ��Ӵ��ڣ����Ҷ���С�������
			Child++;//Childָ���Ҷ���
		/*���if����ȷ��Childָ����ǽ�С�Ķ���*/


		/*��ֹ���һ����������Ҷ�Ӵ�����*/
		if (LastElement > H->Elements[Child])//��Ϊ������һ�� H->Elements[i] = LastElement;
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
	printf("���ȶ���Ϊ��");	
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