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
	//******************行循环*****************
	for (p = 0; p <= 3; p++)
	{
		for (a = 0; a <= 3; a++)//列循环
		{
			sum1[a] = table[p][a];//把该行赋给sum1[]
			//sum11[a] = table[a][p];//把该列赋给sum2[]
		}
		for (b1 = 0; b1 <= 3; b1++)//如果该行有元素和答案由相同元素  都赋给相应的sum2 sum3 sum4
		{
			if (sum1[b1] == a1[b1])//sum1=this
				sum2[b1] = sum1[b1];//sum2=this
			if (sum1[b1] == a2[b1])
				sum3[b1] = sum1[b1];//sum3=th**
			if (sum1[b1] == a3[b1])
				sum4[b1] = sum1[b1];//sum4=t***

		}
		//把数组长度赋给变量len len1 len2
		len = sizeof(sum2);
		len1 = sizeof(sum3);
		len2 = sizeof(sum4);

		for (de = 0; de <= 3; de++)//如果存在* 长度减一 
		{
			if (sum2[de] == '*')
				len--;
			if (sum3[de] == '*')
				len1--;
			if (sum4[de] == '*')
				len2--;
		}
		if (len == 4 && r == 1)//len==4是为了筛选掉部分匹配的数组  r==1是因为外面还有一层循环，为了只输出一次故每次都要+1   
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
		for (int u = 0; u <= 3; u++)//每次循环完重新赋为*
		{
			sum2[u] = '*';
			sum3[u] = '*';
			sum4[u] = '*';
		}
		
		
		
	}
	/**************列循环******************/
	for (p = 0; p <= 3; p++)
	{
		for (a = 0; a <= 3; a++)
		{
			sum1[a] = table[a][p];//把该行赋给sum1[]
		}
		for (b1 = 0; b1 <= 3; b1++)//如果该行元素和答案由相同元素  都赋给相应的sum2 sum3 sum4
		{
			if (sum1[b1] == a1[b1])
				sum2[b1] = sum1[b1];
			if (sum1[b1] == a2[b1])
				sum3[b1] = sum1[b1];
			if (sum1[b1] == a3[b1])
				sum4[b1] = sum1[b1];
		}
		//把数组长度赋给变量len len1 len2
		len = sizeof(sum2);
		len1 = sizeof(sum3);
		len2 = sizeof(sum4);
		for (de = 0; de <= 3; de++)//如果存在* 长度减一 
		{
			if (sum2[de] == '*')
				len--;
			if (sum3[de] == '*')
				len1--;
			if (sum4[de] == '*')
				len2--;
		}
		if (len == 4 && r == 1)//len==4是为了筛选掉部分匹配的数组  r==1是因为外面还有一层循环，为了只输出一次故每次都要+1   
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
/*********************左斜****************************/
//for (p = 0; p <= 3; p++)

	for (a = 0; a <= 3; a++)//列循环
	{
		sum1[a] = table[a][a];
	    
	}

	for (b1 = 0; b1 <= 3; b1++)//如果该行有元素和答案由相同元素  都赋给相应的sum2 sum3 sum4
	{
		if (sum1[b1] == a1[b1])
			sum2[b1] = sum1[b1];
		if (sum1[b1] == a2[b1])
			sum3[b1] = sum1[b1];
		if (sum1[b1] == a3[b1])
			sum4[b1] = sum1[b1];

	}
	//把数组长度赋给变量len len1 len2
	len = sizeof(sum2);
	len1 = sizeof(sum3);
	len2 = sizeof(sum4);

	for (de = 0; de <= 3; de++)//如果存在* 长度减一 
	{
		if (sum2[de] == '*')
			len--;
		if (sum3[de] == '*')
			len1--;
		if (sum4[de] == '*')
			len2--;
	}
	if (len == 4 && r == 1)//len==4是为了筛选掉部分匹配的数组  r==1是因为外面还有一层循环，为了只输出一次故每次都要+1   
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
	for (int u = 0; u <= 3; u++)//每次循环完重新赋为*
	{
		sum2[u] = '*';
		sum3[u] = '*';
		sum4[u] = '*';
	}




//for (p = 0; p <= 3; p++)
/*******************右斜**************/
for (a = 0; a <= 3; a++)//列循环
{
	sum1[a] = table[a][3-a];

}

for (b1 = 0; b1 <= 3; b1++)//如果该行有元素和答案由相同元素  都赋给相应的sum2 sum3 sum4
{
	if (sum1[b1] == a1[b1])
		sum2[b1] = sum1[b1];
	if (sum1[b1] == a2[b1])
		sum3[b1] = sum1[b1];
	if (sum1[b1] == a3[b1])
		sum4[b1] = sum1[b1];

}
//把数组长度赋给变量len len1 len2
len = sizeof(sum2);
len1 = sizeof(sum3);
len2 = sizeof(sum4);

for (de = 0; de <= 3; de++)//如果存在* 长度减一 
{
	if (sum2[de] == '*')
		len--;
	if (sum3[de] == '*')
		len1--;
	if (sum4[de] == '*')
		len2--;
}
if (len == 4 && r == 1)//len==4是为了筛选掉部分匹配的数组  r==1是因为外面还有一层循环，为了只输出一次故每次都要+1   
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
for (int u = 0; u <= 3; u++)//每次循环完重新赋为*
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



		//*****************列循环*********************
			/*for (int o = 0; o <= 3; o++)
			{
				//for(int u=0;u<=3;u++)
				//{ }
				for (int i = 0; i <= 3; i++)
				{
					if (table[0][o] != answer[i][0])//如果第一个字母不一样，终止循环，证明此行没有
						break;
					else
					{
						for (int c = 0; c <= 3; c++)//列循环
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
			//数组转字符串   用字符串相等
			   /*if (sum1[4] == a1[4])
				   printf("%c", sum1[4]);
			   if (sum1[4] == a2[4])
				   printf("%c", sum1[4]);
			   if (sum1[4] == a3[4])
				   printf("%c", sum1[4]);
			   if (sum1 == a4)
	}			   printf("%c", sum1[4]);*/
	/*列*/


