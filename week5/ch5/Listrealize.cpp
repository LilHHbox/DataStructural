//分离链接散列表
//主函数
int main(){
HashTable list;
list = InitializeTable(10);
int array[7] = { 4371,1323,6173,4199,4344,9679,1989 };
for (int i = 0; i <= 6; i++)
{
	Insert(array[i], list);
}
return 0;
}
//初始化函数
HashTable InitializeTable(int TableSize) {
	HashTable H; int i;//HashTable==HashTbl* 

	//H为hash表的表头 指向hash表

	if (TableSize < 10) {
		printf("表太小");
		return NULL;
	}
	H = (HashTable)malloc(sizeof(struct HashTbl));
	H->TableSize = TableSize;
	H->TheLists = (List*)malloc(sizeof(List) * H->TableSize);//List*代表的是返回的指针类型是List型
															 //第二个*H->TableSize 指的是乘以H->TableSize    

	for (int i = 0; i < H->TableSize; i++)//hash表的每一个节点又指向一个链表
	{
		//Position==List==ListNode*
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));//List是个指针，H->TheLists[i]相当于一个数组
		if (H->TheLists[i] != NULL)
		{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;
}

//插入函数
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





//开放定制散列表

//线性探测
Position Find(ElementType Key, HashTable H) {
	Position CurrentPos;
	int CollisionNum;
	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{
		CurrentPos++;
		if (CurrentPos >= H->TableSize)
		{
			CurrentPos -= H->TableSize;
		}
	}
	return CurrentPos;
}
void Insert(ElementType Key, HashTable H) 
{
	Position Pos;
	Pos = Find(Key, H);
	if (H->TheCells[Pos].Info != Legitimate) {
		H->TheCells[Pos].Info = Legitimate;
		H->TheCells[Pos].Element = Key;
	}
}


//平方探测
int Checklist(HashTable H, int TableSize)//多了一个Check函数  来检测Hash表有没有满
{
	int i, j = 1, k = 0;
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
	if (j == TableSize)
	{
		k = 1;
		printf("表已满，请调用rehash函数");
	}
	return k;
}
Position Find(ElementType Key, HashTable H, int TableSize) {
	Position CurrentPos;
	int CollisionNum, count = 0;

	CollisionNum = 0;
	CurrentPos = Hash(Key, H->TableSize);
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
	{

		CollisionNum++;
		CurrentPos += CollisionNum * CollisionNum;
		if (CurrentPos >= H->TableSize)
		{
			int i = Checklist(H, TableSize);
			if (i != 1)
			{
				CurrentPos = CurrentPos - H->TableSize - count;//count每次++
			}
			else
			{
				break;
			}
			count++;//此时count++在第一次检查结束后要加1
		}
	}

	return CurrentPos;
}
int main() {
	HashTable list;
	list = InitializeTable(10);
	int array[7] = { 4371,1323,6173,4199,4344,9679,1989 };
	for (int i = 0; i <= 6; i++)
	{
		Insert(array[i], list);
	}
	return 0;
}


//再散列

HashTable Rehash(HashTable H, int TableSize) {
	int i, OldSize;
	Cell* OldCells;

	OldCells = H->TheCells;
	OldSize = H->TableSize;

	H = InitializeTable(2 * OldSize);;
	for (i = 0; i < OldSize; i++)
	{
		if (OldCells[i].Info == Legitimate)
			Insert(OldCells[i].Element, H, TableSize);
	}
	free(OldCells);
	return H;
}