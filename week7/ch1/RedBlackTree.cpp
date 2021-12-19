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
		NullNode->Color = Black;//空节点视为黑色的
		NullNode->Element = Infinity;
	}
	T = (RedBlackTree)malloc(sizeof(struct RedBlackNode));
	T->Element = -Infinity;
	T->Left = T->Right = NullNode;
	T->Color = Black;

	return T;
}
Position SingleRoateWithLeft(Position K1) //K2原来的根节点
{
	Position K2;
	K2 = K1->Left;
	K1->Left = K2->Right;//K1和K2中间的 要挂到K1上面
	K2->Right = K1;
	return K2;//新的根节点
}
Position SingleRoateWithRight(Position K1)
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	return K2;
}

//插入过程
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
//用于存放当前节点  父节点  祖父节点  曾祖父节点  
static void HandleReorient(ElementType Item, RedBlackTree T)
{
	X->Color = Red;//当前节点改为红色
	X->Left->Color = Black;//当且节点的左右节点都改为黑色
	X->Right->Color = Black;
	if (P->Color == Red)//如果爸爸是红色，肯定得旋转，因为插入的节点是红色的
	{
		GP->Color = Red;//因为是连续两个红  所以首先把曾祖赋为红色
		if ((Item < GP->Element)!=(Item < P->Element))//之字形
			P = Rotate(Item, GP);//准备双旋转
		X = Rotate(Item, GGP);//之所以是GGP的原因 是因为上面返回的是Parent->Right
		X->Color = Black;
	}
	T->Right->Color = Black;//根节点为黑
}
RedBlackTree Insert(ElementType Item, RedBlackTree T)
{
	X = P = GP = T;
	NullNode->Element = Item;
	while (X->Element != Item)
	{
		GGP = GP; GP = P; P = X;//依次向下移动
		if (Item < X->Element)
			X = X->Left;
		else
			X = X->Right;
		if (X->Left->Color == Red && X->Right->Color == Red)//自上而下的情况下 两个儿子为红色 要旋转
			HandleReorient(Item, T);
	}
	if (X != NullNode)
		return NullNode;//节点已存在

	//节点不存在的情况
	X = (Position)malloc(sizeof(struct RedBlackNode));
	X->Element = Item;
	X->Left = X->Right = NullNode;

	if (Item < P->Element)
		P->Left = X;
	else
		P->Right = X;
	HandleReorient(Item, T);//最后一步插入也要判断一下  该节点肯定是红色的

	return T;

}
