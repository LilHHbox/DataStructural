#include<stdio.h>
#include<stdlib.h>
#include"ChildBrotherTree.h"


struct TreeNode
{
	ElementType Element;
	ElementType Number;
	ChildBrotherTree FistChild;
	ChildBrotherTree  NextSibling;
 };
ChildBrotherTree MakeEmpty(ChildBrotherTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->FistChild);
		MakeEmpty(T->NextSibling);
		free(T);
	}
	return NULL;
}
ChildBrotherTree InsertSon(ElementType X,Position T)
{	
	if(T==NULL)
	 {
		Position Q;
		Q = (ChildBrotherTree)malloc(sizeof(struct TreeNode));
		Q->Element = X;
		Q->FistChild = Q->NextSibling = NULL;
		return Q;
	}
	else 
	{
		Position P;
		P = (ChildBrotherTree)malloc(sizeof(struct TreeNode));
		P->Element = X;
		P->FistChild = P->NextSibling = NULL;
		T->FistChild = P;

		return P;
	}
}
ChildBrotherTree InsertBrother(ElementType X,ChildBrotherTree T)
{
	{
		if (T == NULL)
		{
			//Position Q;
			T = (ChildBrotherTree)malloc(sizeof(struct TreeNode));
			T->Element = X;
			T->FistChild = T->NextSibling = NULL;
			return T;
		}
		else if (T->NextSibling != NULL)//连接的brother只能有一个
		{
			printf("该节点已经有兄弟了\n");
			return T;
		}
		else
		{
			Position P;
			P = (ChildBrotherTree)malloc(sizeof(struct TreeNode));
			P->Element = X;
			P->FistChild = P->NextSibling = NULL;
			T->NextSibling = P;
			return P;
		}
	}
	/*int i;
	printf("你插入做兄弟节点还是做孩子节点？兄弟扣1，孩子扣2\n");
	scanf_s("%d", &i);
	if (i == 1)
	{
		if()
		printf("kkk");
	}
	return T;*/
}
int main()
{
	ChildBrotherTree T = NULL;
	T = MakeEmpty(T);
	ChildBrotherTree Q;
	ChildBrotherTree P;
	ChildBrotherTree O;
	ChildBrotherTree U;

	T = InsertBrother(0, T);
	Q= InsertSon(1, T);
    
	P= InsertSon(4, Q);
	Q = InsertBrother(2, Q);
	O= P = InsertSon(6, Q);
	Q = InsertBrother(3, Q);
	U= InsertSon(7, Q);
	P = InsertBrother(5, P);






	return 0;
}