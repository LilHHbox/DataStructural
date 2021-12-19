#include<stdio.h>
#include<stdlib.h>
#include"splaytree.h"
struct SplayNode {
	ElemenetType Element;//不需要父亲节点了  可以省下空间
	SplayTree Left;
	SplayTree Right;
};
typedef struct SplayNode* Position;
static Position Nullnode = NULL;//全局静态变量  需要初始化
SplayTree Initialize(void)
{
	if (Nullnode == NULL)
	{
		Nullnode = (Position)malloc(sizeof(struct SplayNode));
		Nullnode->Left = Nullnode->Right = Nullnode;
	}
	return Nullnode;
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
SplayTree Splay(ElemenetType Item, Position X)
{
	static struct SplayNode Header;//头节点   注意是静态
	Position LeftTreeMax, RightTreeMin;//定义两个位置指针，一个是左树最大，一个是右树最小
	Header.Left = Header.Right = Nullnode;
	LeftTreeMax = RightTreeMin = &Header;//分别指向Header
	Nullnode->Element = Item;

	while (Item != X->Element)
	{
		if (Item < X->Element)
		{
			if (Item < X->Left->Element)//一字型
				X = SingleRoateWithLeft(X);
			if (X->Left == Nullnode)//空节点
				break;


			//包括Item>X->Left->Element和Item=X->Elemenet两种情况
			//除了一字型，一次之字形可以转化成两次单旋转
			RightTreeMin->Left = X;//把右边的树和X连接起来
			RightTreeMin = X;//RightTreeMin指向X
			X = X->Left;
		}
		else
		{
			if (Item > X->Right->Element)//一字型
				X = SingleRoateWithRight(X);
			if (X->Right == Nullnode)
				break;
			LeftTreeMax->Right = X;
			LeftTreeMax = X;
			X = X->Right;
		}
	}
		//组合(当展开末尾重新组装之前，Header.Left和Header.Right分别指的L，R
		LeftTreeMax->Right = X->Left;
		RightTreeMin->Left = X->Right;
		X->Left = Header.Right;//header是静态变量 所以一开始就只想LeftTreeMax和RightTreeMin
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
		T = Splay(Item, T);//围绕Item展开T
		if (Item < T->Element)//如果T的新根的数据大于Item，那么T的新根和它的右子树变成NewNode的一棵右子树
		{
			NewNode->Left = T->Left;
			NewNode->Right = T;
			T->Left = Nullnode;
			T = NewNode;
		}
		else if (T->Element < Item)//同理 左边一样
		{
			NewNode->Right = T->Right;
			NewNode->Left = T;
			T->Right = Nullnode;
			T = NewNode;
		}
		else
			return T;
	}
	NewNode = NULL;//为下次初始化做准备 
	return T;
}
SplayTree Remove(ElemenetType Item, SplayTree T)
{
	Position NewTree;
	if (T != NULL)
	{
		T = Splay(Item, T);//一次展开 把目标放到根处
		if (Item==T->Element)
		{
			if (T->Left == Nullnode)
				NewTree = T->Right;
			else//包括两种情况：1.有左孩子没有右孩子2.左右孩子都有
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
			printf("不存在");
		}
	}
	  
	return T;
}
int main()
{



}