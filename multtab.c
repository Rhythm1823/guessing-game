#include <stdio.h>
#include <conio.h>
int main()
{
int n;
int f;
int i;
int v=1;
printf(" enter any number");
scanf("%d",&n);
for (i=1; i<=n; i++)
{
	f= n* i;
	
	v= v*f;
}
printf("%d",v);
return 0;

}
