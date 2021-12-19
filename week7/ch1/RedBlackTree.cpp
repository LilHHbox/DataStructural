#include<stdio.h>
#include<stdlib.h>
#include"RedBlackTree.h"
#define Infinity 99999
struct RedBlackNode
{
	ElementType Element;
	RedBlackTree Left;
	RedBlackTree Right;
	ColorType Color;
};
Position NullNode = NULL;
RedBlackTree Initialize(void)
{
	RedBlackTree T;
	if (NullNode == NULL)
	{
		NullNode = (Position)malloc(sizeof(struct RedBlackNode));
		NullNode->Left = NullNode->Right = NullNode;
		NullNode->Color = Black;//�սڵ���Ϊ��ɫ��
		NullNode->Element = Infinity;
	}
	T = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
	T->Element = -Infinity;
	T->Left = T->Right = NullNode;
	T->Color = Black;

	return T;
}
Position SingleRoateWithLeft(Position K1) //K2ԭ���ĸ��ڵ�
{
	Position K2;
	K2 = K1->Left;
	K1->Left = K2->Right;//K1��K2�м�� Ҫ�ҵ�K1����
	K2->Right = K1;
	return K2;//�µĸ��ڵ�
}
Position SingleRoateWithRight(Position K1)
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	return K2;
}

//�������
static Position X, P, GP, GGP;
static Position Rotate(ElementType Item, Position Parent)
{
	if (Item < Parent->Element)
		return Parent->Left = ((Item < Parent->Left->Element) ?
		SingleRoateWithLeft(Parent->Left):SingleRoateWithRight(Parent->Left));
	else
		return Parent->Right = Item < Parent->Right->Element ?
		SingleRoateWithLeft(Parent->Right) : SingleRoateWithRight(Parent->Right);
	
}
//���ڴ�ŵ�ǰ�ڵ�  ���ڵ�  �游�ڵ�  ���游�ڵ�  
static void HandleReorient(ElementType Item, RedBlackTree T)
{
	X->Color = Red;//��ǰ�ڵ��Ϊ��ɫ
	X->Left->Color = Black;//���ҽڵ�����ҽڵ㶼��Ϊ��ɫ
	X->Right->Color = Black;
	if (P->Color == Red)//����ְ��Ǻ�ɫ���϶�����ת����Ϊ����Ľڵ��Ǻ�ɫ��
	{
		GP->Color = Red;//��Ϊ������������  �������Ȱ����渳Ϊ��ɫ
		if ((Item < GP->Element)!=(Item < P->Element))//֮����
			P = Rotate(Item, GP);//׼��˫��ת
		X = Rotate(Item, GGP);//֮������GGP��ԭ�� ����Ϊ���淵�ص���Parent->Right
		X->Color = Black;
	}
	T->Right->Color = Black;//���ڵ�Ϊ��
}
RedBlackTree Insert(ElementType Item, RedBlackTree T)
{
	X = P = GP = T;
	NullNode->Element = Item;
	while (X->Element != Item)
	{
		GGP = GP; GP = P; P = X;//���������ƶ�
		if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;
		if (X->Left->Color == Red && X->Right->Color == Red)//���϶��µ������ ��������Ϊ��ɫ Ҫ��ת
			HandleReorient(Item, T);
	}
	if (X != NullNode)
		return NullNode;//�ڵ��Ѵ���

	//�ڵ㲻���ڵ����
	X = (Position)malloc(sizeof(struct RedBlackNode));
	X->Element = Item;
	X->Left = X->Right = NullNode;

	if (Item < P->Element)
		P->Left = X;
	else
		P->Right = X;
	HandleReorient(Item, T);//���һ������ҲҪ�ж�һ��  �ýڵ�϶��Ǻ�ɫ��

	return T;

}
