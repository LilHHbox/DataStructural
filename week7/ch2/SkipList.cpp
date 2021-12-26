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
static Position Bottom = NULL;//底部节点
static Position Tail = NULL;//水平节点
SkipList Initialize(void)
{
	SkipList L;
	if (Bottom == NULL)
	{
		Bottom = (Position)malloc(sizeof(struct SkipNode));
		Bottom->Right = Bottom->Down = Bottom;
		//Bottom->Element = Infinity;不把bottom赋成无穷 是因为后面不管是插入还是查找  都要有防越界

		Tail = (Position)malloc(sizeof(struct SkipNode));
		Tail->Element = Infinity;
		Tail->Right = Tail;
	}
	/*创建头节点*/
	L = (SkipList)malloc(sizeof(struct SkipNode));
	L->Element = Infinity;
	L->Right = Tail;
	L->Down = Bottom;

	return L;
}
Position Find(ElementType Item, SkipList L)//如果没找到就返回Bottom值
{
	Position Current = L;
	Bottom->Element = Item;
	while (Item != Current->Element)
	{
		if (Item < Current->Element)//纵向是从大到小排列
			Current = Current->Down;
		else//横向是从小到大排列
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

		/*如果间隙大于3，需要把中间的节点拔高*/
		if (Current->Element > Current->Down->Right->Right->Element)//找到中间的节点
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

	if (L->Right != Tail)//扩展线路
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