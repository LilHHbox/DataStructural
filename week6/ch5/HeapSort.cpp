/*******������*******/
//�������������������Ͻ��еģ��Ȱ�������鹹���һ����max����Ķ���ѣ�Ȼ��ͨ��Ƶ�������˲������и��ڵ�
#define LeftChild(i) (2*(i)+1)//�����
void PercDown(int  A[], int i, int N)//////����
{
	int Child;
	int Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child)//LeftChild(i) < N��Ϊ�˷�ֹԽ��
	{
		Child = LeftChild(i);//�����������ӾͰ�ָ�������
		if (Child != N - 1 && A[Child + 1] > A[Child])//�Ҷ��Ӵ��ڵĻ���������ӱȽ�
			Child++;
		if (Tmp < A[Child])
			A[i] = A[Child];
		else
			break;
	}
	A[i] = Tmp;//���漰���������˽����õ��������������
}
void HeapSort(int A[], int N)
{
	int i, Tmp;
	for (i = N / 2; i >= 0; i--)//N/2��ԭ���� �ѵĹ����ӷ�Ҷ�ӽڵ㿪ʼ
		PercDown(A, i, N);//�ѹ������
	for (i = N - 1; i > 0; i--)
	{
		Tmp = A[i];
		A[i] = A[0];
		A[0] = Tmp;
		//�Ѵ�ʱ����  ���ڵ��Ԫ�طŵ�����ĩβ
		//��Ϊ�˽׶ε�����һ�����˺���������û�취����ǰ�ı�ݲ���ʡ��
		//ֻ��ʹ���������Ľ���

		PercDown(A, 0, i);//ÿ��һ������һ�Σ���֤����
	}
}