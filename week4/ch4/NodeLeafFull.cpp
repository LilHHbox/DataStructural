typedef int ElementType;
struct TreeNode;
typedef struct TreeNode* Position;//��ʾָ��һ���ڵ�
typedef struct TreeNode* SearchTree;//��ʾָ�����
SearchTree MakeEmpty(SearchTree T);//����
Position Find(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);



int count = 0;
int sum = 0;//����ȫ�ֱ���
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
	printf("�����ڵ����Ϊ��%d\n", count);
	printf("����Ҷ�Ӹ���Ϊ��%d\n", sum);
	int i = Height(T);
	printf("�������Ϊ��%d\n", i);
	double j = (double)i;//ǿ��ת�� ��Ϊpow�Ĳ���������double
	int k = (int)(pow(2.0, j));
	printf("���������ڵ����Ϊ��%d\n", k - 1);//pow(a,b)��ʾa��b�η�

}