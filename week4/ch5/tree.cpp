#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
#include<windows.h>//����max min��ͷ�ļ�
#include< windef.h >
#include<math.h>
int deep = 0;
//extern int count;
//int count= 0;
//int sum = 0;
struct TreeNode {
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
	int Height;//���ĸ߶�
	int Deep;//�ڵ����
};
SearchTree MakeEmpty(SearchTree T) {
	if (T != NULL) {
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}
Position Find(ElementType X, SearchTree T) {
	if (T == NULL)return NULL;
	if (X < T->Element)
		return Find(X, T->Left);
	if (X > T->Element)
		return Find(X, T->Right);
	else
		return T;
}
Position FindMin(SearchTree T) {
	if (T == NULL)
		return NULL;
	else if (T->Left == NULL)
		return T;
	else
		return FindMin(T->Left);
}
Position FindMax(SearchTree T) 
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;
	return T;
}//���õݹ� ��ѭ��ʵ��
SearchTree Insert(ElementType X, SearchTree T) {
	if (T == NULL) {
		T = (SearchTree)malloc(sizeof(struct TreeNode));
		T->Element = X;
		
		T->Left = T->Right = NULL;
	}
	else if (X < T->Element)
	{
		T->Left = Insert(X, T->Left);
	}
	else if (X > T->Element)
	{
		T->Right = Insert(X, T->Right);
	}
	return T;
}
SearchTree Delete(ElementType X, SearchTree T) {
	Position TmpCell;
	if (T == NULL)
		printf("Element not founf");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else if (T->Left && T->Right)//�������ڵ㣺��������������С�����ݴ���ýڵ�����ݲ��ݹ��ɾ���Ǹ��ڵ�
	{
		TmpCell = FindMin(T->Right);
		T->Element = TmpCell->Element;
		T->Right = Delete(T->Element, T->Right);
	}
	else
	{
		TmpCell = T;
		if (T->Left == NULL)//Ҷ�ӽڵ�ֱ��ɾ��
			T = T->Right;
		else if (T->Right == NULL)//��һ�����ӽڵ�
			T = T->Left;
		free(TmpCell);
	}
	return T;
}
//void SumNode(SearchTree T,int coun) {
//	
//	if (T != NULL)
//	{
//		if (T->Left == NULL && T->Right == NULL)
//		{
//			sum++;
//			count++;
//		}
//		else {
//			SumNode(T->Left/*,count*/);
//			SumNode(T->Right/*,count*/);
//			count++;
//		}
//	}
//	else if(T->Left==NULL&&T->Right==NULL)
//	{
//		sum++;
//	}
//	return count;
//	
//}*/
//void PrintNode(SearchTree T, int I, int J)
//{
//	if (T != NULL)
//	{
//		if (T->Element >= I && T->Element <= J)
//		{
//			printf("%d\t", T->Element);
//		}
//		PrintNode(T->Left, I, J);
//		PrintNode(T->Right, I, J);
//	}
//	
//
//}
//void MidPrint(SearchTree T)
//{
//	if (T != NULL)
//	{
//		if (T->Left != NULL)
//		{
//			MidPrint(T->Left);
//		}
//		printf("%d\t", T->Element);
//		x++;
//		printf("�ýڵ�x����Ϊ��%d\t", x);
//		printf("�ýڵ�y����Ϊ��%d\n", Height(T));
//		if (T->Right != NULL)
//		{
//			MidPrint(T->Right);
//		}
//	}
//}
void PrintTree(SearchTree T)
{
	if (T != NULL)
	{
		//PrintDeep(T);
		PrintDeep(T);
		PrintTree(T->Left);
		PrintTree(T->Right);
		
	}
}
//void PrintDeep(SearchTree T)
//{
//	int a=0, b=0, c=0, d=0;
//	
//	if (Deep(T) == 0 && a == 0)
//	{
//		a++;
//		printf("���Ϊ0�Ľڵ��У�%d", T->Element);
//	}
//	else if(Deep(T) == 0&&a!=0)
//	{
//		printf("%d\t", T->Element);
//    }
//	0
//	printf("\n");
//
//	if (Deep(T) == 1 && b == 0)
//	{
//		b++;
//		printf("���Ϊ1�Ľڵ��У�%d", T->Element);
//	}
//	else if (Deep(T) == 1 && b != 0)
//	{
//		printf("%d\t", T->Element);
//	}
//	printf("\n");
//	if (Deep(T) == 2 && c == 0)
//	{
//		printf("���Ϊ2�Ľڵ��У�%d", T->Element);
//	}
//	else if (Deep(T) == 2 && c != 0)
//	{
//		printf("%d\t", T->Element);
//	}
//	printf("\n");
//	if (Deep(T) == 3 && d == 0)
//	{
//		printf("���Ϊ0�Ľڵ��У�%d", T->Element);
//	}
//	else if (Deep(T) == 3 && d != 0)
//	{
//		printf("%d\t", T->Element);
//	}
//
//
//}
int Height(SearchTree T) {
	if (T == NULL)
		return 0;
	else
		return 1 + max(Height(T->Left), Height(T->Right));
}
int Deep(SearchTree T) {

		return 4-Height(T);
	
}

int main()
{
	SearchTree T = NULL;
	T = MakeEmpty(T);
	int array[10] = { 9,5,6,3,11,1,7,15,16,13};
	for (int i = 0; i < 10; i++)
	{
		T = Insert(array[i], T);
	}
	PrintTree(T);
	/*MidPrint(T);*/

	return 0;
}