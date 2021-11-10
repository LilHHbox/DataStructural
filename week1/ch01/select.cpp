#include<stdio.h>
int main()
{   /*冒泡排序法k=n/2*/
	int i, j, k, a[] = {55,46,89,25,66,52,68,15};
	for (i = 0; i < 7; i++)
	{
		for (j = i + 1; j <= 7; j++)
		{
			if (a[i] < a[j])
			{
				k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	for (int v = 0; v <= 3; v++)
	{
		printf("%d\n", a[v]);
	}
	printf("冒泡排序法k=n/2  第四大的数为%d\n", a[3]);
	

	/*数组排序法*/
	int n, m, l, q,b[] = { 55,46,89,25,66,52,68,15 };
	int c[4] = {};
	for (int change1 = 0; change1 <= 3; change1++)
	{
		c[change1] = b[change1];//通过for循环将b数组前四项放入c数组，并排好序
	}

	for (int change2 = 0; change2 < 3; change2++)//前四项先排序由大到小排序
	{
		for (int change3 = 1 + change2; change3 <= 3; change3++)
		{
			if (c[change2] < c[change3])
			{
				n = c[change2];
				c[change2] = c[change3];
				c[change3] = n;

			}
		}
	}   
		
	
	for (m = 4; m <= 7; m++)//当地五项进来的时候，先和第四项比较
	{
		if (b[m] > c[3])//如果大，用冒泡排序法把前四项重新排序
		{   
			c[3] = b[m];
			for(l=0;l<3;l++)
				for (int p = l + 1; p <= 3; p++)
				{
					if (c[l] < c[p])
					{
						q = c[l];
						c[l] = c[p];
						c[p] = q;
					}
				}
			/*for (l = 3; l >= 0; l--)
			{
				if (b[m] <= c[l - 1]&&b[m] > c[l])
				{  
 					c[l] = b[m]
				}
			}*/
		}	
	}
	for (int p = 0; p <= 3; p++)
	{
		printf("%d\n", c[p]);
	}
		printf("数组排序法k=n/2\t输出第四大的数为 % d", c[3]);
		return 0;



}
