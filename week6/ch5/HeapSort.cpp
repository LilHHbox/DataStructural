/*******堆排序*******/
//整个操作都是在数组上进行的，先把这个数组构造成一个有max堆序的二叉堆，然后通过频繁的下滤操作排列根节点
#define LeftChild(i) (2*(i)+1)//左儿子
void PercDown(int  A[], int i, int N)//////下滤
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)//LeftChild(i) < N是为了防止越界
	{
		Child = LeftChild(i);//如果存在左儿子就把指向左儿子
		if (Child != N - 1 && A[Child + 1] > A[Child])//右儿子存在的话就与左儿子比较
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;//上面及条语句避免了交换用到的三条繁琐语句
}
void HeapSort(int A[], int N)
{
	int i, Tmp;
	for (i = N / 2; i >= 0; i--)//N/2的原因是 堆的构建从非叶子节点开始
		PercDown(A, i, N);//堆构建完成
	for (i = N - 1; i > 0; i--)
	{
		Tmp = A[i];
		A[i] = A[0];
		A[0] = Tmp;
		//把此时最大的  根节点的元素放到数组末尾
		//因为此阶段调用了一次下滤函数，所以没办法用以前的便捷操作省略
		//只能使用三条语句的交换

		PercDown(A, 0, i);//每换一次下滤一次，保证堆序
	}
}