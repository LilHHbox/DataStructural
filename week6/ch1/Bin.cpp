#include<stdio.h>
#include<stdlib.h>
#include "BinNode.h"

struct BinNode {
	ElementType Elemenet;
	Position LeftChild;//�ֵܶ���
	Position NextSibling;
};
struct Colloction
{
	int CurrentSize;//���ĸ߶�
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
	BinTree T1, T2, Carry = NULL;//T1��T2Ϊ��Ӧλ�õ�����CarryΪ��λ
	int i, j;
	if (H1->CurrentSize + H2->CurrentSize > Capacity)
		printf("�ϲ�������Χ");
	H1->CurrentSize += H2->CurrentSize;//CurrentSize��ʾ��λ�����ĸ߶�
	for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
	{
		//��Ϊÿ��ѭ����ʱ��Carry������£����Ǿ���case4����NULL
		T1 = H1->TheTrees[i]; T2 = H2->TheTrees[i];
		switch (!!T1+2*!!T2+4*!!Carry)//����������T1�ȵĿպͷǿյ�״̬���������0��1��Ȼ���������ʽ��ɶ�����000��1�����Ԫ�ش��ڣ�0�����Ԫ�ز�����
		{
		case 0:/*no Trees*/
		case 1:break;/*only H1*/
		case 2:/*only H2*/
			H1->TheTrees[i] = T2;
			H2->TheTrees[i] = NULL;
			break;
		case 4:/*only Carry*///��ʾ����i���λ��H1��H2��û����   ֻ����һ��ѭ��i-1���������Ľ�λCarry
			H1->TheTrees[i] = Carry;
			Carry = NULL;
			break;
		case 3:/*H1 and H2*/
			Carry = CombineTree(T1, T2);//����һ����λ
			H1->TheTrees[i] = H2->TheTrees[i] = NULL;
			break;
		case 5:/*H1 and Carry*///һ���н�λ����������1+1=10����ǰΪ����Ϊ��
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
		printf("����Ϊ��");
	}
	MinItem = Inf;
	for (i = 0; i < MaxTrees; i++)
	{
		if (H->TheTrees[i] && H->TheTrees[i]->Elemenet < MinItem)
		{
			MinTree = i;
		}
	} 
	DeletedTree = H->TheTrees[MinTree];//�൱�ڰ��׵�ַ��DeletedTree
	OldRoot = DeletedTree;
	DeletedTree = DeletedTree->LeftChild;
	free(OldRoot); //���������ͷ���Сֵ�ڵ�ĵ�ַ������ֱ��ֱ���ͷ�DeleteTree���ᶪ����Ϣ��

	DeletedQueue = Initialize();//�½�һ������
	DeletedQueue->CurrentSize = (1 << MinTree) - 1;
	for (j = MinTree - 1; j >= 0; j--)//��ѭ����һ��ȥ���������õ��ĺܶ������ֱ�װ��һ���µĶ������
	{
		DeletedQueue->TheTrees[j] = DeletedTree;
		DeletedTree = DeletedTree->NextSibling;
		DeletedQueue->TheTrees[j]->NextSibling = NULL;
	}
	H->TheTrees[MinTree] = NULL;//�ÿո���С��
	H->CurrentSize -= DeletedQueue->CurrentSize + 1;//��Ϊ�������һ��1 ����Ҫ����1

	Merge(H, DeletedQueue);
	return MinItem;
}