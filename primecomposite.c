#include <stdio.h>
int main()
{
    int n;
    int c;
    int i=2;
	printf(" enter any number");
	scanf("%d", &n);
while (i<n)
{
    c= n%i;
    if (c==0)
    {

    printf(" composite ");
    goto end;
    }
    i++;
}
printf(" prime ");
end:
    return 0;
}
