#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"TreapTree.h"
#define Infinity 99999


struct TreapNode
{
	ElementType Element;
	Treap Left;
	Treap Right;
	int Priorty;
};
static Position NullNode = NULL;
Treap Initialize(void)
{
	if (NullNode == NULL)
	{
		NullNode = (Position)malloc(sizeof(struct TreapNode));
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Priorty = Infinity;//NullNode����Ҷ�ӽڵ�
	}
	return NullNode;
}
Position SingleRoateWithLeft(Position K1) //K2ԭ���ĸ��ڵ�
{
	Position K2;
	K2 = K1->Left;
	K1->Left = K2->Right;//K1��K2�м�� Ҫ�ҵ�K1����
	K2->Right = K1;
	return K2;//�µĸ��ڵ�  ��k1���k2

}
Position SingleRoateWithRight(Position K1)
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	return K2;
}
Treap Insert(ElementType Item,Treap T)
{
	if (T == NullNode)
	{
		T = (Treap)malloc(sizeof(struct TreapNode));
		T->Element = Item; T->Priorty = rand();//rand()�������  ��ͷ�ļ�stdlib.h����
		T->Left = T->Right = NullNode;
	}
	else if (Item < T->Element)
	{
		T->Left = Insert(Item, T->Left);
		if (T->Left->Priorty < T->Priorty)//�Ը��ڵ�Ϊ�о�����  �������T->LeftΪ�о�����Ļ� ��ȡT���游������
			T = SingleRoateWithLeft(T);
	}
	else if (Item > T->Element)
	{
		T->Right = Insert(Item, T->Right);
		if (T->Right->Priorty < T->Priorty)
			T = SingleRoateWithRight(T);
	}
	return T;
}
Treap Find(ElementType Item, Treap T)
{
	if (T != NullNode)
	{
		if (T->Element == Item)
		{
			return T;
		}
		else if (Item > T->Element)
		{
			
			T = Find(Item, T->Right);
		}
		else if (Item < T->Element)
		{
			T = Find(Item, T->Left);
		}
	}
	return T;
}
Treap Remove(ElementType Item, Treap T)
{
	/*��ΪTreap��������ʣ�����ֻ��Ҫ��Ҫɾ���Ľڵ���ת��Ҷ�ڵ��ϣ�Ȼ��ֱ��ɾ���Ϳ����ˣ�
	����ķ���������ýڵ�����ӽڵ�����ȼ�С�����ӽڵ�����ȼ��������ýڵ�,ʹ�ýڵ㽵Ϊ�������ĸ��ڵ㣬
	Ȼ������������ĸ��ڵ�,������������֮�������ýڵ�,ʹ�ýڵ㽵Ϊ�������ĸ��ڵ㣬Ȼ������������ĸ��ڵ㣬
	����������ֱ����ɿ���ֱ��ɾ���Ľڵ㡣��������С���ȼ��Ľ���������棬������С�ѵ����ʣ���*/
	if (T != NullNode)
	{
		if (Item < T->Element)
			T->Left=Remove(Item, T->Left);
		else if (Item > T->Element)
			T->Right=Remove(Item, T->Right);
		else
		{
			if (T->Left->Priorty < T->Right->Priorty)
				T = SingleRoateWithLeft(T);
			else
				T = SingleRoateWithRight(T);//�����µĸ�
			if (T!= NullNode)//��TΪҶ�ӽڵ�ʱ������Ȼ��NUllNode��Ϊ����Ӻ��Ҷ���
				T=Remove(Item, T);
			else
			{
				free(T->Left);//��Ϊ�Ǿ�����ת�� Nullnode��ת��ȥ��
				T->Left = NullNode;
			}
		}
	}
	return T;
	

}