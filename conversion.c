#include <stdio.h>

int main()
{ 
char input;
float first;
float product;
float kmtomi = 0.621371;
float intofo=  0.0833333;
float cmtoin=  0.393701;
float potokg = 0.453592;
float intome = 0.0254;
while (1)
{

	printf(" enter the character q to quit. \n 	1. km to mile \n 	2. inch to feet \n	3. cm to inch\n	4. pound to kg\n	5. inch to meter\n");
	scanf("%c", &input); 
	switch (input)
	{
	
	case 'q':
	printf(" quitting the program. \n");
	goto end;
	break;
	case '1':
	
	printf(" enter the value in first unit");
	scanf("%f", &first);
	product= first * kmtomi;
	printf(" the value of %f km into miles is %f", first, product);
	break;
case '2':
	
	printf(" enter the value in first unit");
	scanf("%f", &first);
		product=first * intofo;
	printf(" the value of %f inch into feet is %f", first, product);
		break;
case '3':
	
	printf(" enter the value in first unit");
	scanf("%f", &first);
		product= first * cmtoin;
	printf(" the value of %f cm into inch is %f", first, product);
		break;
case '4':
	
	printf(" enter the value in first unit");
	scanf("%f",& first);
		product= first * potokg;
	printf(" the value of %f pound into kg is %f", first, product);
		break;
	
case '5':
		
	printf(" enter the value in first unit");
	scanf("%f", &first);
	product= first * intofo;
	printf(" the value of %f inches into meters is %f", first, product);
		break;
		default:
			break;
	}
}
	end:
		return 0;
}
