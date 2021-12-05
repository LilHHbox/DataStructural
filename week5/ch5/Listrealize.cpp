//��������ɢ�б�
//������
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
//��ʼ������
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
		H->TheLists[i] = (List)malloc(sizeof(struct ListNode));//List�Ǹ�ָ�룬H->TheLists[i]�൱��һ������
		if (H->TheLists[i] != NULL)
		{
			H->TheLists[i]->Next = NULL;
		}
	}
	return H;
}

//���뺯��
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





//���Ŷ���ɢ�б�

//����̽��
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


//ƽ��̽��
int Checklist(HashTable H, int TableSize)//����һ��Check����  �����Hash����û����
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
		printf("�������������rehash����");
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
				CurrentPos = CurrentPos - H->TableSize - count;//countÿ��++
			}
			else
			{
				break;
			}
			count++;//��ʱcount++�ڵ�һ�μ�������Ҫ��1
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


//��ɢ��

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