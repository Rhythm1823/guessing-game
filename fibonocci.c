// fibonocci series
#include <stdio.h>
int main()
{
int a=0;
int b=1;
int c;
int i;
int n;
printf(" enter the limit: ");
scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		printf("%d \t", a);
		c= a+b;
		a=b;
		b=c;
	}
	return 0;
}

