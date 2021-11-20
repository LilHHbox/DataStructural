void PrintOut(List L)
{
	Position P;
	P = L;
	if (P->Element == NULL)
	{
		P = P->Next;
	}
	while (P->Next != NULL)
	{
		printf("%d\t", P->Element);
		P = P->Next;
	}

}
int main()
{
	List list1 = NULL;
	list1 = MakeEmpty(list1);
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	Position P = list1;
	for (int i = 10; i >= 0; i--)
	{
		Insert(a[i], list1, P);

	}
	PrintOut(list1);
	return 0;
}