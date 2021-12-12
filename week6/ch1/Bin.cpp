#include<stdio.h>
#include<stdlib.h>
#include "BinNode.h"

struct BinNode {
	ElementType Elemenet;
	Position LeftChild;//兄弟儿子
	Position NextSibling;
};
struct Colloction
{
	int CurrentSize;//树的高度
	BinTree TheTrees[MaxTrees];
};

BinTree CombineTree(BinTree T1, BinTree T2)
{
	if (T1->Elemenet > T2->Elemenet)
		return CombineTree(T2, T1);
	T2->NextSibling = T1->LeftChild;
	T1->LeftChild = T2;
	return T1;
}
BinQueue Merge(BinQueue H1, BinQueue H2)
{
	BinTree T1, T2, Carry = NULL;//T1，T2为对应位置的树，Carry为进位
	int i, j;
	if (H1->CurrentSize + H2->CurrentSize > Capacity)
		printf("合并超过范围");
	H1->CurrentSize += H2->CurrentSize;//CurrentSize表示该位置树的高度
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
	{
		//因为每次循环的时候Carry不会更新，除非经过case4会变成NULL
		T1 = H1->TheTrees[i]; T2 = H2->TheTrees[i];
		switch (!!T1+2*!!T2+4*!!Carry)//！！用来把T1等的空和非空的状态变成数字量0，1，然后整个表达式变成二进制000，1代表该元素存在，0代表该元素不存在
		{
		case 0:/*no Trees*/
		case 1:break;/*only H1*/
		case 2:/*only H2*/
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4:/*only Carry*///表示的是i这个位置H1和H2都没有树   只有上一次循环i-1的两棵树的进位Carry
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3:/*H1 and H2*/
			Carry = CombineTree(T1, T2);//产生一个进位
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 5:/*H1 and Carry*///一但有进位产生，它的1+1=10，当前为必设为空
			Carry = CombineTree(T1, T2);
			H1->TheTrees[i] =NULL;
			break;
		case 6:/*H2 and Carry*/
			Carry = CombineTree(T2, Carry);
			H2->TheTrees[i] = NULL;
			break;
		case 7:/*All Tree*/
			H1->TheTrees[i] = Carry;
			Carry = CombineTree(T1, T2);
			H2->TheTrees[i] = NULL;
			break;
		}
	}
	return H1;
}
ElementType DeleteMin(BinQueue H)
{
	int i, j;
	int MinTree;
	BinQueue DeletedQueue;
	Position DeletedTree, OldRoot;
	ElementType MinItem;
	if (!IsEmpty(H))
	{
		printf("队列为空");
	}
	MinItem = Inf;
	for (i = 0; i < MaxTrees; i++)
	{
		if (H->TheTrees[i] && H->TheTrees[i]->Elemenet < MinItem)
		{
			MinTree = i;
		}
	} 
	DeletedTree = H->TheTrees[MinTree];//相当于把首地址给DeletedTree
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot); //这里用来释放最小值节点的地址，不能直接直接释放DeleteTree，会丢掉信息。

	DeletedQueue = Initialize();//新建一个队列
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--)//此循环把一颗去掉根的树得到的很多子树分别装入一个新的二项队列
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;//置空该最小树
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;//因为上面减了一个1 所以要加上1

	Merge(H, DeletedQueue);
	return MinItem;
}