#include<stdio.h>
#include<stdlib.h>
#include"SkipList.h"
#define Infinity 9999
struct SkipNode 
{
	ElementType Element;
	SkipList Right;
	SkipList Down;
};
static Position Bottom = NULL;//�ײ��ڵ�
static Position Tail = NULL;//ˮƽ�ڵ�
SkipList Initialize(void)
{
	SkipList L;
	if (Bottom == NULL)
	{
		Bottom = (Position)malloc(sizeof(struct SkipNode));
		Bottom->Right = Bottom->Down = Bottom;
		//Bottom->Element = Infinity;����bottom�������� ����Ϊ���治���ǲ��뻹�ǲ���  ��Ҫ�з�Խ��

		Tail = (Position)malloc(sizeof(struct SkipNode));
		Tail->Element = Infinity;
		Tail->Right = Tail;
	}
	/*����ͷ�ڵ�*/
	L = (SkipList)malloc(sizeof(struct SkipNode));
	L->Element = Infinity;
	L->Right = Tail;
	L->Down = Bottom;

	return L;
}
Position Find(ElementType Item, SkipList L)//���û�ҵ��ͷ���Bottomֵ
{
	Position Current = L;
	Bottom->Element = Item;
	while (Item != Current->Element)
	{
		if (Item < Current->Element)//�����ǴӴ�С����
			Current = Current->Down;
		else//�����Ǵ�С��������
			Current = Current->Right;
	 }
	return Current;
}
SkipList Insert(ElementType Item, SkipList L)
{
	Position Current=L;
	Position NewNode;

	Bottom->Element= Item;
	while (Current != Bottom)
	{
		while (Item > Current->Element)
			Current = Current->Right;

		/*�����϶����3����Ҫ���м�Ľڵ�θ�*/
		if (Current->Element > Current->Down->Right->Right->Element)//�ҵ��м�Ľڵ�
		{
			NewNode = (Position)malloc(sizeof(struct SkipNode));
			NewNode->Right = Current->Right;
			NewNode->Down = Current->Down->Right->Right;
			Current->Right = NewNode;
			NewNode->Element = Current->Element;
			Current->Element = Current->Down->Right->Element;
		}
		else
			Current = Current->Down;
	}

	if (L->Right != Tail)//��չ��·
	{
		NewNode = (Position)malloc(sizeof(struct SkipNode));
		NewNode->Down = L;
		NewNode->Right = Tail;
		NewNode->Element = Infinity;
		L = NewNode;
	}
	return L;
}
int main()