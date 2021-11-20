#include<stdio.h>
#include<stdlib.h>
#include"list.h"
struct Node {
	ElementType Element;//��ʾint�͵�ֵ
	Position Next;//ָnextָ��
};
List MakeEmpty(List L)//����ֵΪListָ�����͵ĺ���������һ��������
{
	L = (List)malloc(sizeof(struct Node));//�����СΪNode���ڴ�ռ�
	                                      //�������ɹ��򷵻�ָ�򱻷����ڴ��ָ��
	                                      //����ڴ��������List�͵�ָ������
	                                      //��List���൱��Node  ��Element��Next
	L->Element = NULL;
	L->Next = NULL;
	return L;

}
int IsEmpty(List L)
{
	return L->Next == NULL;//Return true if L is empty
}
int IsLast(Position P,List L)
{
	return P->Next == NULL;
}
Position Find(ElementType X, List L)
{
	Position P;
	P = L->Next;
	while (P != NULL && P->Element != X)
		P = P->Next;
	return P;
}
void Delete(ElementType X, List L) 
{
	Position  P,TmpCell;
	P= FindPrevious( X, L);
	if (!IsLast(P,L))
	{
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
	//PrintOut(L);
}
Position FindPrevious(ElementType X, List L) 
{
	Position P;
	P = L;//Pָ���ͷ
	while (P->Next != NULL && P->Next->Element != X)
	{
		P = P->Next;
	}
	return P;
}
Position FindPrevious1(int P, List L) 
{
	Position Q;
	Q = L->Next;
	for (int i = 1; i <P; i++)
	{
		Q = Q->Next;
	}
	return Q;
}
void Insert(ElementType X,List L,Position P)
{
	Position Tmpcell;
	Tmpcell = (Position)malloc(sizeof(struct Node));
	Tmpcell->Element = X;
	Tmpcell->Next = P->Next;
	P->Next = Tmpcell;

}
void DeleteList(List L)
{
	Position P, Tmp;
	P = L->Next;
	L->Next = NULL;
	while (P!=NULL)
	{
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}
Position Header(List L)
{
	return L;
}
Position Advance(Position P)
{
	return P->Next;
}
ElementType Retrieve(Position P)
{
	return P->Element;
}
void PrintLost(List L,List P)
{
	int Q, count = 0;
	Position Head = L;
	P = P->Next;
	while (P->Next!=NULL)
	{
		Q = P->Element;//Q��������Ԫ��
		printf("%d\t", Q);
		for (int i = 1; i <=Q; i++)
		{
			L = L->Next;
		}
		printf("%d\n", L->Element);
		P = P->Next;
		L = Head;
		/*while (count != Q)
		
			if (count == Q)
			{
				printf("%d", L->Element);
				break;
			}
			count++;
			L = L->Next;
			P = P->Next;
		*/
	}


}
void PrintOut(List L) 
{
	Position P;
	P = L;
	if (P->Element== NULL)
	{
		P = P->Next;
	}
	while (P->Next != NULL)
	{
		printf("%d\t", P->Element);
		P = P->Next;
	}
}
void Swap(int P, List L)
{
	//for(int i=1;i<=P;i++)
	PrintOut(L);
	printf("\n");
	Position Q,R,S,T;
	Q=FindPrevious1(P, L);
	/*printf("%d\t", Q->Element);
	printf("%d\t", Q->Next->Element);
	printf("%d\t", Q->Next->Next->Element);
	printf("%d\t\n", Q->Next->Next->Next->Element);*/
	R = Q->Next;
	S= Q->Next->Next;
	T = Q->Next->Next->Next;
	
	Q->Next = S;
	S->Next = R;
	R->Next= T;
	//printf("%d\t", Q->Element);
	//printf("%d\t", Q->Next->Element);
	//printf("%d\t", Q->Next->Next->Element);
	////printf("%d\t\n", Q->Next->Next->Next->Element);
	PrintOut(L);
}
void Inter(List L, List P)
{
	L = L->Next;
	P = P->Next;
	Position J = P;//��¼��ͷλ��
	
	while (L->Next != NULL)
	{
		while (P->Next != NULL)
		{
			if (L->Element == P->Element)
			{
				printf("%d\t",L->Element);
			}
			P = P->Next;
		}
		P = J;
		L = L->Next;
	}
}
void Union(List L, List P,int N)
{
	List list = NULL;
	list = MakeEmpty(list);//�½�һ�������Ž���
	//Position Q = list;

	Position J = P;//��¼��ͷλ��
	Position R = L;
	L = L->Next;//������ͷ

	while (L->Next != NULL)
	{
		while (P->Next != NULL)
		{

			if (L->Element == P->Element)
			{
				//printf("%d\t", L->Element);
				Insert(L->Element, list, list);

				//printf("%d\t", list->Next->Element);
			}
			P = P->Next;

		}
		P = J;
		L = L->Next;
	}
	
	//list = list->Next;
	L = R;
	P = J;
	//PrintOut(L);
	//printf("\n");
	//PrintOut(P);
	//printf("\n");
	//PrintOut(list);
	//printf("\n");
	int count = 0;

	P = P->Next;////������ͷ
	list = list->Next;
	Position Q = list;
	while (P->Next != NULL )
	{
		while (list->Next != NULL)
		{
			if (P->Element == list->Element)
			{
				Delete(P->Element, P);
			}
			list = list->Next;
		}
			list = Q;
			P = P->Next;
		
	}
     PrintOut(P);
	 PrintOut(L);
}
int main()
{
	List list1 = NULL;
	List list2 = NULL;
	list1= MakeEmpty(list1);
	list2 = MakeEmpty(list2);

	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[5] = { 1,2,4,52,10 };
	
	Position P1 = list1;
	Position P2 = list2;

	
	for (int i = 10; i >= 0; i--)
	{
		Insert(a[i], list1, P1);//��10��ʼ  ��˼���Ǹ�ͷԪ�ظ���ֵ

	}
	for (int i = 5; i >= 0; i--)
	{
		Insert(b[i], list2, P2);
		
	}

	//PrintLost(list1, list2);
	//Swap(3, list1);
	//
	//PrintOut(list2);
	//Inter(list1, list2);
	Union(list1, list2,5);
	//Delete(1, list1);
   //PrintOut(list1);
	return 0;
}
