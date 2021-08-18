#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct book
{
	char code[20];
	char name[100];
	int date;
	int cost;
};
struct old
{
    char nam[100];
    char mob[100];
    char moviename[100];
    int total;
    int seats;
    int booked[20];
};
struct login
{
    char fname[30];
    char lname[30];
    char username[30];
    char password[20];
};

int seat = 60 ;
void login (void);
void registration (void);
void loginre();
void insert_details();//for inserting movie details
void viewAll(); // for view all data
void find(); // for finding data
void book_ticket(); //for booking tickets
void old_record(); //for view old recorrds of users,booked tickets
void support();

int main(void)
{
 system("color 2");


	 int ch,z;
 	do{
            printf("\t\t\t\t\t ===================================\n");
     printf("\t\t\t\t\t\t WELCOME TO THEATRE C\n");
      printf("\t\t\t\t\t===================================\n");
    printf("\n");
	printf("\n\t\t\t====================================================================\n");
	printf("\n");
	printf("\t\t\t\t\t\tMOVIE TICKET BOOKING SYSTEM ");
	printf("\n");
	printf("\n\t\t\t====================================================================");
printf("\n\n\n\n");
	printf("\n\t\t\t\t\tPress <1> LOGIN AS ADMIN\n");
   	printf("\n\t\t\t\t\tPress <2> SIGN IN OR REGISTER\n");
	printf("\n\t\t\t\t\tPress <3> SUPPORT\n");
printf("\n\t\t\t\t\tPress <4> ABOUT US\n");
    printf("\n\t\t\t\t\tPress <0> EXIT\n");

   	printf("\n\t\t\tEnter your Choice ::");
   	scanf("%d",&ch);

   	switch (ch)
   	{
    		case 1 :
    		    printf("ENTER <1> TO INSERT DETAILS\n");
    		    printf("ENTER <2> TO VIEW ALL TRANSACTIONS\n");
    		    printf("ENTER <0> TO EXIT\n");
    		   scanf("%d",&z);
    		    if (z==1)
                {
    		    insert_details();
                }
                else if (z==2)
                {
                    old_record();
                }
                else if (z==0)
                {
                    return 0;
                }
                else
                {
                    printf("invalid entery");
                }
   		break;
		case 2:
    		loginre();
   		break;

		case 3:
    		support();
    		return 0;
   		break;

		case 4:
		printf("\n\t\t\t\t OUR GOAL: CUSTOMER SATISFACTION\n\t\t\t ESTABLISHED: 1990\t\t WE HAVE MORE THAN 30 YEARS OF SERVICE\n MESSAGE FROM THE OWNER:\n WE ALWAYS TRY OUR BEST TO GIVE QUALTITY SERVICE TO OUR CUSTOMERS.CUSTOMER IS THE KING. IF YOU HAVE ANY COMPLAINS AND QUERIES YOU CAN CONTACT OUR SUPPORTING TEAM.\N ");
		return 0;


		break;
		case 5:
            return 0;


    		default:
    		printf("Wrong choice !");
    		break;
   	}
 }while(ch!=0);

}
void loginre()
{
     int option;

    printf("Press '1' to Register\nPress '2' to Login\n\n");
    scanf("%d",&option);

    getchar();

    if(option == 1)
        {
            system("CLS");
            registration();
        }

    else if(option == 2)
        {
            system("CLS");
            login();
        }
}
void login (void)
{
    struct login l;
    char username[30],password[20];
    FILE *log;

    log = fopen("login.txt","r+b");
    if (log == NULL)
    {
        printf("Error opening file!");
        exit(1);
    }
    else{
    printf("\nPlease Enter your login credentials below\n\n");
    printf("PLEASE ENTER YOUR USERNAME: ");
    gets(username);
    printf("\nPLEASE ENTER PASSWORD: ");
    gets(password);
    while(fread(&l,sizeof(struct login),1,log))
        {
        if(strcmp(username,l.username)==0 && strcmp(password,l.password)==0)

            {
                printf("\nSuccessful Login\n");
                int main();
            }
        else
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
                printf("\nPlease TRY AGAIN or REGISTER FIRST if you haven't yet\n");
                login();
            }
        }

    fclose(log);
    }
    printf("ENTER <1> TO VIEW ALL MOVIES\n");
      printf("ENTER <2> TO FIND MOVIES\n");
      printf("ENTER <3> TO BOOK A TICKET\n");
        printf("ENTER <4> FOR SUPPORT\n");
          printf("ENTER <0> TO EXIT\n");
          int v;
          scanf("%d",&v);
        switch (v)
        {
        case 1:
            viewAll();
        case 2:
            find();
        case 3:
              book_ticket();
        case 4:
            support();
        case 5:
            exit(1);
        default:
            printf(" invalid entry");
        }



    return;

}
void support()
{
    printf("\n\t\tIF YOU HAVE ANY QUERIES YO CAN CONTACT US\n \t\t+977-9862262314\n \t\t+977-9841097032\n \t\t01-6630491\n\t\tAlso you can email us at: attidamiproject23@cmail.com\n");
}
void insert_details()
{

	FILE *fp;
	struct book b;
	printf("Enter movie code :- ");
	scanf("%s",b.code);
	printf("Enter  name :- ");
	gets(b.name);
	gets(b.name);
	printf("Enter Release Year:- ");
	scanf("%d",&b.date);
	printf("Enter Ticket Price:- ");
	scanf("%d",&b.cost);

	fp=fopen("data.txt","a+b");

	if(fp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fwrite(&b,sizeof(struct book),1,fp);
		printf("Record insert Successful");
	}
		printf("\n");
	fclose(fp);
}
void registration(void)
{
    char firstname[15];
    FILE *log;

    log=fopen("login.txt","w+b");
    if (log == NULL)
    {
        printf("Error opening File");
        exit(1);
    }


    struct login l;

    printf("\nWelcome to Theatre C. We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:");
    gets(l.fname);
    printf("\nEnter Surname:");
    gets(l.lname);
    printf("\nNow please choose a USERNAME and PASSWORD as credentials for system login.\n\n");
    printf("Ensure the username is no more than 30 characters long\n\n");
    printf("Ensure your PASSWORD is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n\n");
    printf("\nEnter Username:");
    gets(l.username);
    printf("\nEnter Password:");
    gets(l.password);
    fwrite(&l,sizeof(struct login),1,log);
    fclose(log);
     printf("\n\t\t\t\tREGISTRATION COMPLETE\n");
    printf("Press any key to continue...");
        getchar();
    system("CLS");
    printf("Enter <1> FOR LOGIN");
    printf("ENTER ANY KEY fOR EXIT");
    int v;
    scanf("%d",&v);
    if (v==1)
    {
    login();
    }
    else{
        exit(1);
    }
}
void find() //find details
{
	struct book b;
	FILE *fp;
	int tempprice;
    char ch[20];
	printf("Enter movie code :");
	scanf("%s",ch);
	//system("clear");
	fp = fopen("data.txt","r+b");
	if(fp == NULL)
	{
		printf("file not found !");
		exit(1);

	}
	else
	{
		    system("cls");
		    while(fread(&b, sizeof(struct book), 1, fp))
	    {
		  if(strcmp(ch,b.code)==0)
          {
				printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Ticket Price:NRs %d\t",b.cost);
                printf("\n");
                printf("\n");
          }
            }
}

	fclose(fp);
}
void viewAll()
{
    struct book b;
	char ch;
	FILE *fp;

	fp = fopen("data.txt","r+b");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
	    system("cls");
	    while(fread(&b, sizeof(struct book), 1, fp))
	    {
		        printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Per Ticket Price:NRs %d\t",b.cost);
                printf("\n");
                printf("\n");
            }
	}
	fclose(fp);
}
//for ticket booking
void book_ticket()
{
system("cls");
 struct book b;
 struct old o;
 int c=0,d=0;
	FILE *fp;
    FILE *ufp;

	int total_seat,total_amount;
	char mobile[50];
	int m,i,j,k,seat[20],tempprice;
	int store[100];
	char name[50],tempname[50];
	char ch; //used in display all movies
	char movie_code[20]; //for searching

	// disply all moives by default for movie code
	fp = fopen("data.txt","r+b");
	ufp=fopen("oldTransaction.txt","r+b");
	printf("\n");
 while(fread(&b, sizeof(struct book), 1, fp))
	    {
		        printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Per Ticket Price:NRs %d\t",b.cost);
                printf("\n");
                printf("\n");
            }


	//display ends
	printf("\n For booking Ticket choose Movie.\n");
	printf("\n Enter movie code :");
	scanf("%s",movie_code);
	//system("clear");
	fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
	    system("cls");
		 while(fread(&b, sizeof(struct book), 1, fp))
	    {
	        if(strcmp(movie_code,b.code)==0)
            {
		        printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        strcpy(tempname,b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Per Ticket Price:NRs %d\t",b.cost);
                tempprice=b.cost;
                printf("\n");
                printf("\n");
            }
            }

	}
	printf("\n* Fill Details  *");
	printf("\n Please Enter Your name :");
	gets(name);
	gets(name);
	printf("\n Mobile number :");
	gets(mobile);
	printf("\n Total number of tickets :");
	scanf("%d",&total_seat);
	system("cls");
	printf("\n");
		 while(fread(&b, sizeof(struct book), 1, fp))
	    {
	        if(strcmp(movie_code,b.code)==0)
            {
		        printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        strcpy(tempname,b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Ticket Price:NRs %d\t",b.cost);
                tempprice=b.cost;
                printf("\n");
                printf("\n");
            }
            }
		fp = fopen("data.txt","r");
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else
	{
		 while(fread(&b, sizeof(struct book), 1, fp))
	    {
	        if(strcmp(movie_code,b.code)==0)
            {
		        printf("%Movie Code:%s\t",b.code);
		        printf("Movie Name: %s\t",b.name);
		        strcpy(tempname,b.name);
		        printf("Movie Release Date: %d\t",b.date);
                printf("Ticket Price:NRs %d\t",b.cost);
                tempprice=b.cost;
                printf("\n");
                printf("\n");
            }
            }

	}
printf("\t\t\t\t\t||SCREEN||\n\n");
fclose(ufp);
fclose(fp);
ufp=fopen("oldTransaction.txt","r+b");
 while(fread(&o, sizeof(struct old), 1, ufp))
{
    if(strcmp(o.moviename,tempname)==0)
    {
        for(i=0; i<o.seats; i++)
        {
        store[c]=o.booked[i];
        c=c+1;
        }
    }
}
for(i=0; i<100; i=i+10)
{
    for(j=i; j<i+10; j++)
    {
        for(k=0; k<c; k++)
        {
         if(store[k]==j+1)
         {
             printf("\t*");
             d=d+1;
         }
        }
        if(d!=1)
        {
        printf("\t%d",j+1);
        }
        d=0;
    }
printf("\n");
printf("\n");
}
fclose(ufp);
printf("\n\n\t\t\t\t *-->NOT AVILABLE\n\n\n");
    printf("\n Please Choose the Seat Number:\n");
    for(i=0; i<total_seat; i++)
    {
        printf("Seat %d:",i+1);
        scanf("%d",&seat[i]);
    }
	total_amount = tempprice * total_seat;

system("cls");
	printf("\n\t\t\t\t\t\t ***** ENJOY THE MOVIE ****\n");
	printf("\n\t\t\t\t\t\t-------Costumer Details:-------\n");
	printf("\n\t\t\t\t\t\tName : %s\n",name);
	printf("\n\t\t\t\t\t\tMobile Number:");
	puts(mobile);
	printf("\n\t\t\t\t\t\tMovie Name:");
	puts(tempname);
	printf("\n\t\t\t\t\t\tTotal Seats : %d\n",total_seat);
	printf("\n\t\t\t\t\t\tCost per ticket : %d\n",tempprice);
	printf("\n\t\t\t\t\t\tTotal Amount : %d\n",total_amount);
	printf("\n\t\t\t\t\t\tSeats Chosen:\n");
	printf("\t\t\t\t\t\t\t");
    for(i=0; i<total_seat; i++)
    {
        printf("\t%d",seat[i]);
        o.booked[i]=seat[i];
    }
    strcpy(o.nam,name);
    strcpy(o.mob,mobile);
    strcpy(o.moviename,tempname);
    o.seats=total_seat;
    o.total=total_amount;

	ufp=fopen("oldTransaction.txt","a+b");
	if(ufp == NULL)
	{
		printf("File not Found");
	}
	else
	{
		fwrite(&o,sizeof(struct old),1,ufp);
		printf("\nSUCCESSFULLY RECORDED");
	}
    printf("\n");
	fclose(ufp);
	fclose(fp);

}
//for view all user transactions
void old_record()
{
    struct old o;
	char ch;
	int i;
	FILE *fp;
     fp=fopen("oldTransaction.txt","r+b");
	 system("cls");
	    while(fread(&o, sizeof(struct old), 1, fp))
	    {
    printf("_________________________________");
    printf("\nName : %s\n",o.nam);
	printf("\nMobile Number:");
    printf("%s",o.mob);
	printf("\n\nMovie Name:");
	puts(o.moviename);
	printf("\nTotal Seats : %d\n",o.seats);
	printf("\nTotal Amount : %d\n",o.total);
	printf("\nSelected Seats:\n");
	for(i=0; i<o.seats; i++)
    {
        printf("\t%d",o.booked[i]);
    }
    printf("\n");
	printf("__________________________________");
	      }
	fclose(fp);
}
