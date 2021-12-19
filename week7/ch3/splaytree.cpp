#include<stdio.h>
#include<stdlib.h>
#include"splaytree.h"
struct SplayNode {
	ElemenetType Element;//����Ҫ���׽ڵ���  ����ʡ�¿ռ�
	SplayTree Left;
	SplayTree Right;
};
typedef struct SplayNode* Position;
static Position Nullnode = NULL;//ȫ�־�̬����  ��Ҫ��ʼ��
SplayTree Initialize(void)
{
	if (Nullnode == NULL)
	{
		Nullnode = (Position)malloc(sizeof(struct SplayNode));
		Nullnode->Left = Nullnode->Right = Nullnode;
	}
	return Nullnode;
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
SplayTree Splay(ElemenetType Item, Position X)
{
	static struct SplayNode Header;//ͷ�ڵ�   ע���Ǿ�̬
	Position LeftTreeMax, RightTreeMin;//��������λ��ָ�룬һ�����������һ����������С
	Header.Left = Header.Right = Nullnode;
	LeftTreeMax = RightTreeMin = &Header;//�ֱ�ָ��Header
	Nullnode->Element = Item;

	while (Item != X->Element)
	{
		if (Item < X->Element)
		{
			if (Item < X->Left->Element)//һ����
				X = SingleRoateWithLeft(X);
			if (X->Left == Nullnode)//�սڵ�
				break;


			//����Item>X->Left->Element��Item=X->Elemenet�������
			//����һ���ͣ�һ��֮���ο���ת�������ε���ת
			RightTreeMin->Left = X;//���ұߵ�����X��������
			RightTreeMin = X;//RightTreeMinָ��X
			X = X->Left;
		}
		else
		{
			if (Item > X->Right->Element)//һ����
				X = SingleRoateWithRight(X);
			if (X->Right == Nullnode)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}
		//���(��չ��ĩβ������װ֮ǰ��Header.Left��Header.Right�ֱ�ָ��L��R
		LeftTreeMax->Right = X->Left;
		RightTreeMin->Left = X->Right;
		X->Left = Header.Right;//header�Ǿ�̬���� ����һ��ʼ��ֻ��LeftTreeMax��RightTreeMin
		X->Right = Header.Left;

		return X;
	
}
SplayTree Insert(ElemenetType Item, SplayTree T)
{
	static Position NewNode = NULL;
	if (NewNode == NULL)
	{
		NewNode = (Position)malloc(sizeof(struct SplayNode));
	}
	NewNode->Element = Item;
	if (Item== NewNode->Element)
	{
		NewNode->Left = NewNode->Right = NULL;
	}
	else
	{
		T = Splay(Item, T);//Χ��Itemչ��T
		if (Item < T->Element)//���T���¸������ݴ���Item����ôT���¸����������������NewNode��һ��������
		{
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = Nullnode;
			T = NewNode;
		}
		else if (T->Element < Item)//ͬ�� ���һ��
		{
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = Nullnode;
			T = NewNode;
		}
		else
			return T;
	}
	NewNode = NULL;//Ϊ�´γ�ʼ����׼�� 
	return T;
}
SplayTree Remove(ElemenetType Item, SplayTree T)
{
	Position NewTree;
	if (T != NULL)
	{
		T = Splay(Item, T);//һ��չ�� ��Ŀ��ŵ�����
		if (Item==T->Element)
		{
			if (T->Left == Nullnode)
				NewTree = T->Right;
			else//�������������1.������û���Һ���2.���Һ��Ӷ���
			{
				NewTree = T->Left;
				NewTree = Splay(Item, NewTree);
				NewTree->Right = T->Right;
			}
			free(T);
			T = NewTree;
		}

		else
		{
			printf("������");
		}
	}
	  
	return T;
}
int main()
{



}