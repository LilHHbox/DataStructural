#include<stdio.h>
#include<stdlib.h>
#include"HashListOph.h"
enum KindOfEntry {
	Legitimate,Empty
};

struct HashEntry {
	ElementType Element;
	enum KindOfEntry Info;
};
typedef struct HashEntry Cell;
struct HashTbl {
	int TableSize;
	Cell* TheCells;
};
Index Hash(ElementType Key, int TableSize)
{
	return Key % 10;
}
HashTable InitializeTable1(int TableSize) {
	HashTable H;
	if (TableSize < 10)
		printf("��̫СŶ");
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize= TableSize;
	H->TheCells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	for (int i = 0; i < H->TableSize; i++)
		H->TheCells[i].Info = Empty;

	return H;
}
Position Find1(ElementType Key, HashTable H, int TableSize) {
	Position CurrentPos;
	int CollisionNum,count=0,sum=0;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{
		sum++;
     	CollisionNum++;
		CurrentPos += CollisionNum *CollisionNum;
		if (CurrentPos >= H->TableSize)
		{ 
			int i = Checklist1(H, TableSize);
			if (i != 1)
			{
				CurrentPos = CurrentPos- H->TableSize-count;
			}
			else
			{
				break;
			}
			count++;
		}
	}
	printf("�ôβ����ͻ����Ϊ%d\n", sum);
	return CurrentPos;
}
void Insert1(ElementType Key, HashTable H, int TableSize) {
	Position Pos;
	Pos = Find1(Key, H,TableSize);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
	//Check(H, TableSize);

}
int Checklist1(HashTable H,int TableSize)//����һ��Check����  �����Hash����û����
{
	int i, j = 1,k=0;
	for (int i = 0; i < TableSize; i++)
	{
		if (H->TheCells[i].Info == Empty)
		{
			break;
		}
		else
		{ 
			j++; 
		}
	}
	if (j ==TableSize)
		{
		k = 1;
		printf("�������������rehash����");
		}
	return k;
}
HashTable Rehash(HashTable H,int TableSize) {
	int i, OldSize;
	Cell* OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable1(2 * OldSize);;
	for (i = 0; i < OldSize; i++)
	{
		if (OldCells[i].Info == Legitimate)
			Insert1(OldCells[i].Element, H,TableSize);
	}
	free(OldCells);
	return H;
}
void DestoryTable(HashTable H) {
	free(H->TheCells);
	free(H);
}


Position Find2(ElementType Key, HashTable H, int TableSize) {
	Position CurrentPos;
	int CollisionNum,sum=0,count=0;
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);

	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{
		sum++;
		CurrentPos++;
		if (CurrentPos >= H->TableSize)
		{
			int i = Checklist1(H, TableSize);
			if (i != 1)
			{
				CurrentPos = CurrentPos - H->TableSize - count;
			}
			else
			{
				break;
			}
			count++;
		}
	}
	printf("�ôβ����ͻ����Ϊ%d\n", sum);
	return CurrentPos;
}
void Insert2(ElementType Key, HashTable H,int TableSize)
{
	Position Pos;
	Pos = Find2(Key, H,TableSize);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}
int main() {


	HashTable list1;
	list1 = InitializeTable1(10);//ƽ��̽�ⷨ
	int array[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	printf("ƽ��̽�⣺\n");
	for (int i = 0; i <= 6; i++)
	{
		Insert1(array[i], list1,10);
	}
	//Rehash(list);




	HashTable list2;
	list2 = InitializeTable1(10);//ƽ��̽�ⷨ
	int array1[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	printf("����̽�⣺\n");
	for (int i = 0; i <= 6; i++)
	{
		Insert2(array1[i], list2, 10);
	}
	//Rehash(list);







	return 0;
}
