void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)//Lpos����ߵ�λ�ã��տ�ʼָ�������߲��ֵĵ�һ��Ԫ�أ�Ҳ������ĵ�һ��Ԫ�� 
																	 //Rpos���ұߵ�λ�ã��տ�ʼָ������ұ߲��ֵĵ�һ��Ԫ�� 
																	 //RightEnd���ұ߽磬��ֹԽ��
{
	int i, LeftEnd, NumElements, TmpPos;//LeftEnd:��߽��Խ��
	LeftEnd = Rpos - 1;//��ʼ��
	TmpPos = Lpos;//�տ�ʼָ������ĵ�һ��Ԫ��
	NumElements = RightEnd - Lpos + 1;//Ԫ�صĸ���

	while (Lpos <= LeftEnd && Rpos <= RightEnd)//ѭ����ֹ��������������һ�����ֱȽ���
	{
		if (A[Lpos] <= A[Rpos])
		{
			TmpArray[TmpPos++] = A[Lpos++];//��++���ȸ�ֵ��++
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}//ȫ������TmpArray

	while (Lpos <= LeftEnd)//�����ʣ�ಿ�ָ���TmpArray����
	{
		TmpArray[TmpPos++];
	}
	while (Rpos <= RightEnd)//���ұ�ʣ�ಿ�ָ���TmpArray����
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}

	for (i = 0; i < NumElements; i++, RightEnd--)//�Ѹ����鿽����ԭ����
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}