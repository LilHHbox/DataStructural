#include<stdio.h>
#include<stdlib.h>
#include"hashlistsep.h"
 

//�������ӷ�


//#define MinTableSize(10)

struct ListNode {
	ElementType Element;
	Position Next;
};
typedef Position List;
struct HashTbl {
	int TableSize;
	List* TheLists;//����������TheLists:ָ��ָ���ָ��
};
ElementType Hash(ElementType Key, int TableSize) //hash����
{
	return Key % 10;
}
HashTable InitializeTable(int TableSize) {
	HashTable H; int i;//HashTable==HashTbl* 

	//HΪhash��ı�ͷ ָ��hash��

	if (TableSize < 10) {
		printf("��̫С");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = TableSize;
	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);//List*������Ƿ��ص�ָ��������List��
		 													 //�ڶ���*H->TableSize ָ���ǳ���H->TableSize    

	for (int i = 0; i < H->TableSize; i++)//hash���ÿһ���ڵ���ָ��һ������
	{
		//Position==List==ListNode*
		H->TheLists[i] =(List)malloc(sizeof(struct ListNode));//List�Ǹ�ָ�룬H->TheLists[i]�൱��һ������
		if (H->TheLists[i] != NULL)
		{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;
}
Position Find(ElementType Key, HashTable H) {
	Position P; List L;
	L = H->TheLists[Hash(Key, H->TableSize)];
	P = L->Next;
	while (P != NULL && P->Element != Key)
		P = P->Next;
	return P;
}
void Insert(ElementType Key, HashTable H) {
	Position Pos, NewCell;
	List L;
	Pos = Find(Key, H);
	if (Pos == NULL)
	{
		NewCell = (Position)malloc(sizeof(struct ListNode));
		L = H->TheLists[Hash(Key, H->TableSize)];
		NewCell->Next = L->Next;
		NewCell->Element = Key;
		L->Next = NewCell;
	}
}
void DestoryTable(HashTable H) {
	for (int i = 0; i < H->TableSize; i++)
	{
		Position P = H->TheLists[i];
		Position Tmp;
		while (P != NULL)
		{
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->TheLists);
	free(H);
}
int main()
{
	HashTable list;
	list = InitializeTable(10);
	int array[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	for (int i = 0; i <= 6; i++)
	{
		Insert(array[i], list);
	}
	return 0;
}