void Union(List L, List P)
{
	List list = NULL;
	list = MakeEmpty(list);
	Position Q = list;//新建一个链表存放交集


	//L = L->Next;
	P = P->Next;
	Position J = P;//记录表头位置
	Position R = L;
	Insert(0, list, list);
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


	list = Q;
	list = list->Next;
	L = R;
	P = J;
	PrintOut(L);
	printf("\n");
	int count = 0;
	while (P->Next != NULL)
	{
		while (list->Next != NULL)
		{
			if (P->Element == list->Element)
			{
				Delete(P->Element, P);
			}
			list = list->Next;
		}
		count++;
		list = Q;
		P = P->Next;
	}
	PrintOut(P);
}
int main()
{
	List list1 = NULL;
	List list2 = NULL;
	list1 = MakeEmpty(list1);
	list2 = MakeEmpty(list2);

	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int b[4] = { 1,2,4,10 };

	Position P1 = list1;
	Position P2 = list2;


	for (int i = 10; i >= 0; i--)
	{
		Insert(a[i], list1, P1);//从10开始  意思就是给头元素赋空值

	}
	for (int i = 4; i >= 0; i--)
	{
		Insert(b[i], list2, P2);

	}

	//PrintLost(list1, list2);
	//Swap(3, list1);
	//
	//PrintOut(list2);
	//Inter(list1, list2);
	Union(list1, list2);
	//Delete(1, list1);
   //PrintOut(list1);
	return 0;
}
