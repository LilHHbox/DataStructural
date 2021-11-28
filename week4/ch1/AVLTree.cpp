#include<stdio.h>
#include<stdlib.h>
#include"AVLTree.h"
#include<math.h>
#include<windows.h>//引用max min的头文件
#include< windef.h >

struct AvlNode {
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;//高度
};
AvlTree MakeEmpty(AvlTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Left);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X, AvlTree T) {
	if (T == NULL)
		return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else 
		return T;
}
Position FindMin(AvlTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
	/*
	if(T!=NULL)
	while(T->left!=NULL)
	   T=T->Left;
	return T;
	*/
}
Position FindMax(AvlTree T) {
	if (T != NULL)
		while (T->Right = NULL)
			T = T->Right;
	return T;
	/*
	if(T==NULL)
	return NULL;
	else if(T->Right==NULL)
	      return T;
    else 
	    return FindMax(T->Right);
	*/
}
int Height(Position P) {
	if (P == NULL)return -1;
	else return P->Height;
}
Position SingleRoateWithLeft(Position K1) //K2原来的根节点
{
	Position K2;
	K2 = K1->Left;
	K1->Left = K2->Right;//K1和K2中间的 要挂到K1上面
	K2->Right = K1;

	K1->Height = max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = max(Height(K2->Left), K1->Height) + 1;

	return K2;//新的根节点
}
Position SingleRoateWithRight(Position K1) 
{
	Position K2;
	K2 = K1->Right;
	K1->Right = K2->Left;
	K2->Left = K1;

	K1->Height= max(Height(K1->Left), Height(K1->Right)) + 1;
	K2->Height = max(Height(K2->Left), K1->Height) + 1;

	return K2;
}
Position DoubleRoateWithLeftRight(Position K1)
{
	K1->Left = SingleRoateWithRight(K1->Right);
	return SingleRoateWithLeft(K1);
}
Position DoubleRoateWithRightLeft(Position K1)
{
	K1->Right = SingleRoateWithLeft(K1->Left);
	return SingleRoateWithRight(K1);
}
AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)//递归终止条件，创建一个叶子节点
	{
		T = (AvlTree)malloc(sizeof(struct AvlNode));
		T->Element = X; 
		T->Height = 0;
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);//寻找插入位置
		if (Height(T->Left) - Height(T->Right) == 2)
			if (X < T->Left->Element)
				T = SingleRoateWithLeft(T);
			else
				T = DoubleRoateWithLeftRight(T);
	}
	else
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
			if (X > T->Left->Element)
				T = SingleRoateWithRight(T);
			else
				T = DoubleRoateWithRightLeft(T);
	}
	/*Else X is in the tree already: we will do nothing*/
	T->Height = max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}  
int main()
{
	return 0;
}