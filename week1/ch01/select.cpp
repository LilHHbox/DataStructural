#include<stdio.h>
int main()
{   /*ð������k=n/2*/
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
	printf("ð������k=n/2  ���Ĵ����Ϊ%d\n", a[3]);
	

	/*��������*/
	int n, m, l, q,b[] = { 55,46,89,25,66,52,68,15 };
	int c[4] = {};
	for (int change1 = 0; change1 <= 3; change1++)
	{
		c[change1] = b[change1];//ͨ��forѭ����b����ǰ�������c���飬���ź���
	}

	for (int change2 = 0; change2 < 3; change2++)//ǰ�����������ɴ�С����
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
		
	
	for (m = 4; m <= 7; m++)//�������������ʱ���Ⱥ͵�����Ƚ�
	{
		if (b[m] > c[3])//�������ð�����򷨰�ǰ������������
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
		printf("��������k=n/2\t������Ĵ����Ϊ % d", c[3]);
		return 0;



}
