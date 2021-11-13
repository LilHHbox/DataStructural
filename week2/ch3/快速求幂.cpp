#include<stdio.h>
int main()
{
	int a, b;
	void Pow(int X, int N);
	printf("输入正整数X以及指数N：");
	scanf("%d,%d", &a, &b);
	Pow(a, b);

	return 0;
}
void Pow(int X, int N)
{
	if(N==0)//如果指数为0  结果一定等于1
	{
		printf("结果为1");
	}
	else {
		int div = N, re;
		int binary[30];//存放N的二进制数和占位符"*"
		for (int j = 0; j < 30; j++)
		{
			binary[j] = '*';
		}
		for (int i = 0; div != 1; i++)
		{
			binary[i] = div % 2;
			div = div / 2;
			if (binary[i] != '*' && binary[i + 1] == '*')
			{
				binary[i + 1] = 1;
			}
		}//求出N的二进制然后放到binary数组里面
		int array[30]; array[0] = X;
		for (int k = 1; k < 30; k++)
		{
			array[k] = array[k - 1] * array[k - 1];

		}
		int result = 1;
		//array数组里面都是放的x,x的平方，x的三次方等等
		for (int m = 0; m < 30; m++)
		{
			if (binary[m] == 1)
				result *= array[m];
		}
		//找出binary数组的非零  然后令array数组相应的元素直接乘
	
		printf("结果为%d", result);
	}
}
/*用循环做的话，当然不能直接死乘。举个例子：
3 ^ 999 = 3 * 3 * 3 * … * 3
直接乘要做998次乘法。但事实上可以这样做，先求出2^k次幂：
3 ^ 2 = 3 * 3
3 ^ 4 = (3 ^ 2) * (3 ^ 2)
3 ^ 8 = (3 ^ 4) * (3 ^ 4)
3 ^ 16 = (3 ^ 8) * (3 ^ 8)
3 ^ 32 = (3 ^ 16) * (3 ^ 16)
3 ^ 64 = (3 ^ 32) * (3 ^ 32)
3 ^ 128 = (3 ^ 64) * (3 ^ 64)
3 ^ 256 = (3 ^ 128) * (3 ^ 128)
3 ^ 512 = (3 ^ 256) * (3 ^ 256)
再相乘：
3 ^ 999 = 3 ^ (512 + 256 + 128 + 64 + 32 + 4 + 2 + 1)
            = (3 ^ 512) * (3 ^ 256) * (3 ^ 128) * (3 ^ 64) * (3 ^ 32) * (3 ^ 4) * (3 ^ 2) * 3
*/
