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
		printf("表太小哦");
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
	printf("该次插入冲突次数为%d\n", sum);
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
int Checklist1(HashTable H,int TableSize)//多了一个Check函数  来检测Hash表有没有满
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
		printf("表已满，请调用rehash函数");
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
	printf("该次插入冲突次数为%d\n", sum);
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
	list1 = InitializeTable1(10);//平方探测法
	int array[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	printf("平方探测：\n");
	for (int i = 0; i <= 6; i++)
	{
		Insert1(array[i], list1,10);
	}
	//Rehash(list);




	HashTable list2;
	list2 = InitializeTable1(10);//平方探测法
	int array1[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	printf("线性探测：\n");
	for (int i = 0; i <= 6; i++)
	{
		Insert2(array1[i], list2, 10);
	}
	//Rehash(list);







	return 0;
}
