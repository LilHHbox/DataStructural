void MidPrint(SearchTree T)
{
	if (T != NULL)
	{
		if (T->Left != NULL)
		{
			MidPrint(T->Left);
		}
		printf("%d\t", T->Element);
		x++;
		printf("�ýڵ�x����Ϊ��%d\t", x);
		printf("�ýڵ�y����Ϊ��%d\n", Height(T));
		if (T->Right != NULL)
		{
			MidPrint(T->Right);
		}
	}

}
int Height(SearchTree T) {
	if (T == NULL)
		return 0;
	else
		return 1 + max(Height(T->Left), Height(T->Right));
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
//	PrintNode(T,5,13);

	//SumNode(T);
	//printf("�����ڵ����Ϊ��%d\n", count);
	//printf("����Ҷ�Ӹ���Ϊ��%d\n", sum);
	//int i = Height(T);
	//printf("�������Ϊ��%d\n", i);
	//double j = (double)i ;//ǿ��ת�� ��Ϊpow�Ĳ���������double
	//int k = (int)(pow(2.0, j));
	//printf("���������ڵ����Ϊ��%d\n",k-1);//pow(a,b)��ʾa��b�η�
	MidPrint(T);

	return 0;
}