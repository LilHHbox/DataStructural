#define NumSets 11
#include<stdio.h>
typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Initialize(DisjSet S) {
	int i;
	for (i = NumSets; i > 0; i--)
		S[i] = 0;
}
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
	S[Root2] = Root1;//简单的进行相并，把该树的根改为root2
}
void SetUnion1(DisjSet S, SetType Root1, SetType Root2)//按高度求并
{
	if (S[Root2] < S[Root1])//当两个数都为负数的情况下  谁小证明谁的子树多
	{
		S[Root1] = Root2;//同样是把小的附到大的上面
	}
	else {
		if (S[Root1] == S[Root2])//按高度求并
			S[Root1]--;//只有两棵树的高度一样的时候才会增加一  因为是负数所以是--
		S[Root2] = Root1;
	}
}
SetType Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)//也就是S[X]为空,此时X为根
		return X;
	else return Find(S[X], S);//递归的返回X的树的根
}
SetType Find1(ElementType X, DisjSet S)//压缩路径
{
	if (S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}
int main()
{
	DisjSet S;//定义一个有12个元素的数组
	int i = 1, j = 1, k = 1, Set1, Set2;

	Initialize(S);
	while (k <= 3) 
	{//第一轮：1，2    3，4   5，6   7，8   9，10  11
     //第二轮：1，3    5，7   9，11  
		j = 1;
		while (j < NumSets)
		{
			Set1 = Find(j, S);
			Set2 = Find(j + k, S);
			SetUnion(S, Set1, Set2);
			j += 2 * k;
		}
		k *= 2;
	}
	for (i = 1; i <= NumSets; i++)
	{
		Set1 = Find(i, S);
		printf("%d**", Set1);
	}
	return 0;
}