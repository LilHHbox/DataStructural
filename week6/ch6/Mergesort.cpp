void Merge(int A[], int TmpArray[], int Lpos, int Rpos, int RightEnd)//Lpos：左边的位置，刚开始指向的是左边部分的第一个元素，也是数组的第一个元素 
																	 //Rpos：右边的位置，刚开始指向的是右边部分的第一个元素 
																	 //RightEnd：右边界，防止越界
{
	int i, LeftEnd, NumElements, TmpPos;//LeftEnd:左边界防越界
	LeftEnd = Rpos - 1;//初始化
	TmpPos = Lpos;//刚开始指向数组的第一个元素
	NumElements = RightEnd - Lpos + 1;//元素的个数

	while (Lpos <= LeftEnd && Rpos <= RightEnd)//循环终止条件：左右其中一个部分比较完
	{
		if (A[Lpos] <= A[Rpos])
		{
			TmpArray[TmpPos++] = A[Lpos++];//后++，先赋值后++
		}
		else
		{
			TmpArray[TmpPos++] = A[Rpos++];
		}
	}//全部赋给TmpArray

	while (Lpos <= LeftEnd)//把左边剩余部分赋给TmpArray数组
	{
		TmpArray[TmpPos++];
	}
	while (Rpos <= RightEnd)//把右边剩余部分赋给TmpArray数组
	{
		TmpArray[TmpPos++] = A[Rpos++];
	}

	for (i = 0; i < NumElements; i++, RightEnd--)//把该数组拷贝回原数组
	{
		A[RightEnd] = TmpArray[RightEnd];
	}
}