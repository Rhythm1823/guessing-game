#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
	int n;
	int m;
	int i=0;
	int decimal;
	int rem;
	int finaldecimal=0;
	printf(" enter any binary number: ");
	scanf(" %d", &n);
	while (n!=0) 
	{
		rem= n % 10;
	
	
		decimal= rem*pow(2,i);
		finaldecimal= finaldecimal+decimal;
		i=i+1;
			n= n/10;
	}
	printf(" the decimal is %d", finaldecimal);
	return 0;
}

