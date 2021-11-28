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
		printf("该节点x坐标为：%d\t", x);
		printf("该节点y坐标为：%d\n", Height(T));
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
	//printf("该树节点个数为：%d\n", count);
	//printf("该树叶子个数为：%d\n", sum);
	//int i = Height(T);
	//printf("该树深度为：%d\n", i);
	//double j = (double)i ;//强制转换 因为pow的参数必须是double
	//int k = (int)(pow(2.0, j));
	//printf("满二叉树节点个数为：%d\n",k-1);//pow(a,b)表示a的b次方
	MidPrint(T);

	return 0;
}