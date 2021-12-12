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
	S[Root2] = Root1;//�򵥵Ľ����ಢ���Ѹ����ĸ���Ϊroot2
}
void SetUnion1(DisjSet S, SetType Root1, SetType Root2)//���߶���
{
	if (S[Root2] < S[Root1])//����������Ϊ�����������  ˭С֤��˭��������
	{
		S[Root1] = Root2;//ͬ���ǰ�С�ĸ����������
	}
	else {
		if (S[Root1] == S[Root2])//���߶���
			S[Root1]--;//ֻ���������ĸ߶�һ����ʱ��Ż�����һ  ��Ϊ�Ǹ���������--
		S[Root2] = Root1;
	}
}
SetType Find(ElementType X, DisjSet S)
{
	if (S[X] <= 0)//Ҳ����S[X]Ϊ��,��ʱXΪ��
		return X;
	else return Find(S[X], S);//�ݹ�ķ���X�����ĸ�
}
SetType Find1(ElementType X, DisjSet S)//ѹ��·��
{
	if (S[X] <= 0)
		return X;
	else
		return S[X] = Find(S[X], S);
}
int main()
{
	DisjSet S;//����һ����12��Ԫ�ص�����
	int i = 1, j = 1, k = 1, Set1, Set2;

	Initialize(S);
	while (k <= 3) 
	{//��һ�֣�1��2    3��4   5��6   7��8   9��10  11
     //�ڶ��֣�1��3    5��7   9��11  
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