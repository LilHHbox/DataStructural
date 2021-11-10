#include<math.h>
#include<stdio.h>
int main()
{
	void printout(double n,int m);
	int b,d,l=1;
	
	float  a = 0.2223;
	printout(a,l);

	return 0;
}
void printout(double n,int m)//n=0.223  
{   
	double c,d,f;
	int b;
	c = n * 10;//c=2.23
	b = (int)c;//b=2
	d = (double)b;//d=2

	if (c-d!=0&&m<=3)
	{ 
		
		printf("%d", b);
		m++;
		printout(c - d,m);
	}

} 
//printf("%d", a );}