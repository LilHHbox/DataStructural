void Swap(int P, List L)
{
	//for(int i=1;i<=P;i++)
	PrintOut(L);
	printf("\n");
	Position Q, R, S, T;
	Q = FindPrevious1(P, L);//按照个数查找到对应节点的前驱节点
	/*printf("%d\t", Q->Element);
	printf("%d\t", Q->Next->Element);
	printf("%d\t", Q->Next->Next->Element);
	printf("%d\t\n", Q->Next->Next->Next->Element);*/
	R = Q->Next;
	S = Q->Next->Next;
	T = Q->Next->Next->Next;

	Q->Next = S;
	S->Next = R;
	R->Next = T;
	//printf("%d\t", Q->Element);
	//printf("%d\t", Q->Next->Element);
	//printf("%d\t", Q->Next->Next->Element);
	////printf("%d\t\n", Q->Next->Next->Next->Element);
	PrintOut(L);
}
int main()
{
	List list1 = NULL;

	list1 = MakeEmpty(list1);
	list2 = MakeEmpty(list2);
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };

	Position P1 = list1;



	for (int i = 10; i >= 0; i--)
	{
		Insert(a[i], list1, P1);

	}
	

	//PrintLost(list1, list2);
	Swap(3, list1);
	//PrintOut(list2);
	return 0;
}