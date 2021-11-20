void PrintLost(List L, List P)
{
	int Q；
	Position Head = L;//把表头赋给Head 后面会用
	P = P->Next;//跳过P表的表头
	while (P->Next != NULL)//P表循环
	{
		Q = P->Element;//Q接收数组元素
		for (int i = 1; i <= Q; i++)//循环Q次
		{
			L = L->Next;
		}
		printf("%d\n", L->Element);
		P = P->Next;
		L = Head;//每次循环后要跳到表头



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
int main()
{
	List list1 = NULL;
	List list2 = NULL;
	list1 = MakeEmpty(list1);
	list2 = MakeEmpty(list2);
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[4] = { 1,2,4,6 };
	Position P1 = list1;
	Position P2 = list2;


	for (int i = 10; i >= 0; i--)
	{
		Insert(a[i], list1, P1);

	}
	for (int i = 4; i >= 0; i--)
	{
		Insert(b[i], list2, P2);

	}

	PrintLost(list1, list2);

	//PrintOut(list2);
	return 0;
}