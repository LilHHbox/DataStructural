#include<stdio.h>
#include <string.h>
#include < string.h> 
int main()
{
	char* strcpy(char* dest, const char* src);
	char  table[4][4] = { 't','h','i','s','h','a','c','d','a','z','l','h','t','b','p','k' };
	char a1[4] = { 't', 'h', 'i', 's' };
	char a2[4] = { 't', 'h', 'a', 't' };
	char a3[4] = { 't', 'a', 'l','k' };
	char sum1[4] = { '*','*','*','*' };
	char sum11[] = { '*','*','*','*' };
	char sum2[4] = { '*','*','*','*' };
	char sum3[4] = { '*','*','*','*' };
	char sum4[4] = { '*','*','*','*' };
	int b1 = 0;
	int len, len1, len2;
	int r = 1, s = 1, t = 1;
	int p = 0, a, de, i, j, k,u;
	//******************��ѭ��*****************
	for (p = 0; p <= 3; p++)
	{
		for (a = 0; a <= 3; a++)//��ѭ��
		{
			sum1[a] = table[p][a];//�Ѹ��и���sum1[]
			//sum11[a] = table[a][p];//�Ѹ��и���sum2[]
		}
		for (b1 = 0; b1 <= 3; b1++)//���������Ԫ�غʹ�����ͬԪ��  ��������Ӧ��sum2 sum3 sum4
		{
			if (sum1[b1] == a1[b1])//sum1=this
				sum2[b1] = sum1[b1];//sum2=this
			if (sum1[b1] == a2[b1])
				sum3[b1] = sum1[b1];//sum3=th**
			if (sum1[b1] == a3[b1])
				sum4[b1] = sum1[b1];//sum4=t***

		}
		//�����鳤�ȸ�������len len1 len2
		len = sizeof(sum2);
		len1 = sizeof(sum3);
		len2 = sizeof(sum4);

		for (de = 0; de <= 3; de++)//�������* ���ȼ�һ 
		{
			if (sum2[de] == '*')
				len--;
			if (sum3[de] == '*')
				len1--;
			if (sum4[de] == '*')
				len2--;
		}
		if (len == 4 && r == 1)//len==4��Ϊ��ɸѡ������ƥ�������  r==1����Ϊ���滹��һ��ѭ����Ϊ��ֻ���һ�ι�ÿ�ζ�Ҫ+1   
		{
			r++;
			for (i = 0; i <= 3; i++)
			{
				printf("%c", sum2[i]);
			}
		}
		if (len1 == 4 && s == 1)
		{
			s++;
			for (j = 0; j <= 3; j++)
			{
				printf("%c", sum3[j]);
			}
		}
		if (len2 == 4 && t == 1)
		{
			t++;
			for ( k = 0; k <= 3; k++)
			{
				printf("%c", sum4[k]);
			}
		}
		for (int u = 0; u <= 3; u++)//ÿ��ѭ�������¸�Ϊ*
		{
			sum2[u] = '*';
			sum3[u] = '*';
			sum4[u] = '*';
		}
		
		
		
	}
	/**************��ѭ��******************/
	for (p = 0; p <= 3; p++)
	{
		for (a = 0; a <= 3; a++)
		{
			sum1[a] = table[a][p];//�Ѹ��и���sum1[]
		}
		for (b1 = 0; b1 <= 3; b1++)//�������Ԫ�غʹ�����ͬԪ��  ��������Ӧ��sum2 sum3 sum4
		{
			if (sum1[b1] == a1[b1])
				sum2[b1] = sum1[b1];
			if (sum1[b1] == a2[b1])
				sum3[b1] = sum1[b1];
			if (sum1[b1] == a3[b1])
				sum4[b1] = sum1[b1];
		}
		//�����鳤�ȸ�������len len1 len2
		len = sizeof(sum2);
		len1 = sizeof(sum3);
		len2 = sizeof(sum4);
		for (de = 0; de <= 3; de++)//�������* ���ȼ�һ 
		{
			if (sum2[de] == '*')
				len--;
			if (sum3[de] == '*')
				len1--;
			if (sum4[de] == '*')
				len2--;
		}
		if (len == 4 && r == 1)//len==4��Ϊ��ɸѡ������ƥ�������  r==1����Ϊ���滹��һ��ѭ����Ϊ��ֻ���һ�ι�ÿ�ζ�Ҫ+1   
		{
			r++;
			for (i = 0; i <= 3; i++)
			{
				printf("%c", sum2[i]);
			}
		}
		if (len1 == 4 && s == 1)
		{
			s++;
			for (j = 0; j <= 3; j++)
			{
				printf("%c", sum3[j]);
			}
		}
		if (len2 == 4 && t == 1)
		{
			t++;
			for (k = 0; k <= 3; k++)
			{
				printf("%c", sum4[k]);
			}
		}
		for (int u = 0; u <= 3; u++)
		{
			sum2[u] = '*';
			sum3[u] = '*';
			sum4[u] = '*';
		}
	}
/*********************��б****************************/
//for (p = 0; p <= 3; p++)

	for (a = 0; a <= 3; a++)//��ѭ��
	{
		sum1[a] = table[a][a];
	    
	}

	for (b1 = 0; b1 <= 3; b1++)//���������Ԫ�غʹ�����ͬԪ��  ��������Ӧ��sum2 sum3 sum4
	{
		if (sum1[b1] == a1[b1])
			sum2[b1] = sum1[b1];
		if (sum1[b1] == a2[b1])
			sum3[b1] = sum1[b1];
		if (sum1[b1] == a3[b1])
			sum4[b1] = sum1[b1];

	}
	//�����鳤�ȸ�������len len1 len2
	len = sizeof(sum2);
	len1 = sizeof(sum3);
	len2 = sizeof(sum4);

	for (de = 0; de <= 3; de++)//�������* ���ȼ�һ 
	{
		if (sum2[de] == '*')
			len--;
		if (sum3[de] == '*')
			len1--;
		if (sum4[de] == '*')
			len2--;
	}
	if (len == 4 && r == 1)//len==4��Ϊ��ɸѡ������ƥ�������  r==1����Ϊ���滹��һ��ѭ����Ϊ��ֻ���һ�ι�ÿ�ζ�Ҫ+1   
	{
		r++;
		for (i = 0; i <= 3; i++)
		{
			printf("%c", sum2[i]);
		}
	}
	if (len1 == 4 && s == 1)
	{
		s++;
		for (j = 0; j <= 3; j++)
		{
			printf("%c", sum3[j]);
		}
	}
	if (len2 == 4 && t == 1)
	{
		t++;
		for (k = 0; k <= 3; k++)
		{
			printf("%c", sum4[k]);
		}
	}
	for (int u = 0; u <= 3; u++)//ÿ��ѭ�������¸�Ϊ*
	{
		sum2[u] = '*';
		sum3[u] = '*';
		sum4[u] = '*';
	}




//for (p = 0; p <= 3; p++)
/*******************��б**************/
for (a = 0; a <= 3; a++)//��ѭ��
{
	sum1[a] = table[a][3-a];

}

for (b1 = 0; b1 <= 3; b1++)//���������Ԫ�غʹ�����ͬԪ��  ��������Ӧ��sum2 sum3 sum4
{
	if (sum1[b1] == a1[b1])
		sum2[b1] = sum1[b1];
	if (sum1[b1] == a2[b1])
		sum3[b1] = sum1[b1];
	if (sum1[b1] == a3[b1])
		sum4[b1] = sum1[b1];

}
//�����鳤�ȸ�������len len1 len2
len = sizeof(sum2);
len1 = sizeof(sum3);
len2 = sizeof(sum4);

for (de = 0; de <= 3; de++)//�������* ���ȼ�һ 
{
	if (sum2[de] == '*')
		len--;
	if (sum3[de] == '*')
		len1--;
	if (sum4[de] == '*')
		len2--;
}
if (len == 4 && r == 1)//len==4��Ϊ��ɸѡ������ƥ�������  r==1����Ϊ���滹��һ��ѭ����Ϊ��ֻ���һ�ι�ÿ�ζ�Ҫ+1   
{
	r++;
	for (i = 0; i <= 3; i++)
	{
		printf("%c", sum2[i]);
	}
}
if (len1 == 4 && s == 1)
{
	s++;
	for (j = 0; j <= 3; j++)
	{
		printf("%c", sum3[j]);
	}
}
if (len2 == 4 && t == 1)
{
	t++;
	for (k = 0; k <= 3; k++)
	{
		printf("%c", sum4[k]);
	}
}
for (int u = 0; u <= 3; u++)//ÿ��ѭ�������¸�Ϊ*
{
	sum2[u] = '*';
	sum3[u] = '*';
	sum4[u] = '*';
}




return 0;

}	




































/*{ if (table[p][a] == a1[a])//|| table[p][a] ==a2[a]|| table[p][a] == a3[a])
		printf("%c", table[p][a]);}
for (int b = 0; b <= 3; b++)
{if (table[p][b] == a2[b])
{printf("%c", table[p][b]);}}
for (int c = 0; c <= 3; c++)
{if (table[p][c] == a3[c])
{printf("%c", table[p][c]);}}
for (int d = 0; d <= 3; d++)
{if (table[p][d]== a4[d])
	{printf("%c", table[p][d]);}}
if (table[p][a] == answer[p][a])
	for (int c = 0; c <= 3; c++)
	{
		sum1[a] = table[p][a];
						}
			}
 for (int b = 0; b <= 3; b++)
			{
				if (sum1[b] != a1[b] && sum1[b] != a2[b] && sum1[b] != a3[b])
					break;
				else
					printf("%c", sum1[b]);
			}



		//*****************��ѭ��*********************
			/*for (int o = 0; o <= 3; o++)
			{
				//for(int u=0;u<=3;u++)
				//{ }
				for (int i = 0; i <= 3; i++)
				{
					if (table[0][o] != answer[i][0])//�����һ����ĸ��һ������ֹѭ����֤������û��
						break;
					else
					{
						for (int c = 0; c <= 3; c++)//��ѭ��
						{
							if (table[c][o] = answer[o][c])
							{                                       //for(int c=0;c<=3)
								sum2[c] = table[c][o];
							}
						}

						for (int d = 0; d <= 3; d++)
						{
							if (sum1[d] != a1[d] && sum1[d] != a2[d] && sum1[d] != a3[d])
								break;
							else
								printf("%c", sum1[d]);
						}

					}
				}
			}
			*
			//����ת�ַ���   ���ַ������
			   /*if (sum1[4] == a1[4])
				   printf("%c", sum1[4]);
			   if (sum1[4] == a2[4])
				   printf("%c", sum1[4]);
			   if (sum1[4] == a3[4])
				   printf("%c", sum1[4]);
			   if (sum1 == a4)
	}			   printf("%c", sum1[4]);*/
	/*��*/


