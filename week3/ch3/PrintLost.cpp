void PrintLost(List L, List P)
{
	int Q��
	Position Head = L;//�ѱ�ͷ����Head �������
	P = P->Next;//����P��ı�ͷ
	while (P->Next != NULL)//P��ѭ��
	{
		Q = P->Element;//Q��������Ԫ��
		for (int i = 1; i <= Q; i++)//ѭ��Q��
		{
			L = L->Next;
		}
		printf("%d\n", L->Element);
		P = P->Next;
		L = Head;//ÿ��ѭ����Ҫ������ͷ



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