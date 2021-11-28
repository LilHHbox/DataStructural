typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;//表示指向一个节点
typedef struct TreeNode* SearchTree;//表示指向的树
SearchTree MakeEmpty(SearchTree T);//空树
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);



int count = 0;
int sum = 0;//定义全局变量
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
	SumNode(T);
	printf("该树节点个数为：%d\n", count);
	printf("该树叶子个数为：%d\n", sum);
	int i = Height(T);
	printf("该树深度为：%d\n", i);
	double j = (double)i;//强制转换 因为pow的参数必须是double
	int k = (int)(pow(2.0, j));
	printf("满二叉树节点个数为：%d\n", k - 1);//pow(a,b)表示a的b次方

}