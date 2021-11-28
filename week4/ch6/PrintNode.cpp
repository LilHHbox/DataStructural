void PrintNode(SearchTree T, int I, int J)
{
	if (T != NULL)
	{
		if (T->Element >= I && T->Element <= J)
		{
			printf("%d\t", T->Element);
		}
		PrintNode(T->Left, I, J);//与遍历节点相类似
		PrintNode(T->Right, I, J);
	}

int main()
{
	SearchTree T = NULL;
	T = MakeEmpty(T);
	int array[10] = { 9,5,6,3,11,1,7,15,16,13 };
	for (int i = 0; i < 10; i++)
	{
		T = Insert(array[i], T);
	}
	//printf("%d", T->Left->Element);
	PrintNode(T, 5, 13);



	return 0;
}