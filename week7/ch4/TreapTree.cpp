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
		NullNode->Priorty = Infinity;//NullNode就是叶子节点
	}
	return NullNode;
}
Position SingleRoateWithLeft(Position K1) //K2原来的根节点
{
	Position K2;
	K2 = K1->Left;
	K1->Left = K2->Right;//K1和K2中间的 要挂到K1上面
	K2->Right = K1;
	return K2;//新的根节点  把k1变成k2

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
		T->Element = Item; T->Priorty = rand();//rand()随机函数  在头文件stdlib.h里面
		T->Left = T->Right = NullNode;
	}
	else if (Item < T->Element)
	{
		T->Left = Insert(Item, T->Left);
		if (T->Left->Priorty < T->Priorty)//以父节点为研究对象  如果是以T->Left为研究对象的话 获取T的祖父较困难
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
	/*因为Treap满足堆性质，所以只需要把要删除的节点旋转到叶节点上，然后直接删除就可以了，
	具体的方法：如果该节点的左子节点的优先级小于右子节点的优先级，右旋该节点,使该节点降为右子树的根节点，
	然后访问右子树的根节点,继续操作；反之，左旋该节点,使该节点降为左子树的根节点，然后访问左子树的根节点，
	继续操作，直到变成可以直接删除的节点。（即：让小优先级的结点旋到上面，满足最小堆的性质）。*/
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
				T = SingleRoateWithRight(T);//返回新的根
			if (T!= NullNode)//当T为叶子节点时，它仍然有NUllNode作为左儿子和右儿子
				T=Remove(Item, T);
			else
			{
				free(T->Left);//因为是经过旋转的 Nullnode被转上去了
				T->Left = NullNode;
			}
		}
	}
	return T;
	

}