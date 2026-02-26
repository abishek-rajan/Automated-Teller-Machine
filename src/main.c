#include <stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum{
	BLOCKED,
	ACTIVE
}ACC_Status;

typedef enum{
	MENU=1,
	EXIT
}Goback;

typedef enum{
	Deposit =1,
	Withdraw,
	acount_detail,
	Quit
}Operation;

typedef struct Bank{
	ACC_Status status;
	char name[30];
	int Acc_No ;
	float balance;

	int (*deposit)(struct Bank*,float);
	int (*withdraw)(struct Bank*,float);
}Bank;

int deposit(Bank *b,float amount){

	system("clear");
	b-> balance += amount ;
	printf("deposited succesfully.... \n\nAcc Balance : %.2f",b->balance);

	return 0;
}

int withdraw (Bank *b,float amount)
{
system("clear");
	if(b-> balance >= amount)
	{
	b-> balance -= amount ;
	printf("\ncollect your cash.... \n\nAcc Balance : %.2f \n\n",b->balance);
	}
	else{
		printf("insufficient Balance.....\n\n");
	}
	return 0;
}

void update_detail(Bank * b)
{
	b->status = ACTIVE;
	strcpy (b->name , "Abishek");
	b->balance = 0.00;
	b->Acc_No = 123456098;

	b-> deposit = deposit;
	b-> withdraw = withdraw;


}

int Print_detail (Bank *b)
{
	printf ("\nAccount Holder : %s ",b->name);
	printf ("\nAccount status : %s ",(b->status ==1)? "ACTIVE" : "BLOCKED");
	printf ("\nAccount number : %d ",b->Acc_No);
	printf ("\nbalance : %.2f ",b->balance);
return 0 ;
}


void process(Bank * b ,Operation op);


void Option( Bank *b )
{
	int n;
	printf ("option : \n\t1.deposit \n\t2.withdraw \n\t3.Account details \n\t4.Cancel");
	printf("\nEnter the option :");
	if (scanf ("%d",&n)!=1 || n>4){
		system("clear");
		printf("Enter correctly!.....\n");
		Option(b);
	}
	Operation op = (Operation)n;
	system("clear");
	process(b ,op);

}


void goback (Bank * b,Goback x){

	switch (x)
	{
	case MENU :
	{
		Option(b);
	}
	break;
	case EXIT:
	{
		printf("Thank you !  Visit Again!");
		exit(0);
	}
	break;
	}

}


void menu_exit(Bank *b)
{
	int x;
	printf ("\n\noption :\n\t1.Menu \n\t2.Exit");
	printf ("\nEnter option : ");
	if( scanf("%d",&x )!=1 || x>2)
		{
			system("clear");
			printf("\nEnter correctly !.....");
			menu_exit(b);
		}
	system("clear");
	Goback X = (Goback) x;
	goback (b,X);
}

void process(Bank * b ,Operation op)
{
	
	switch (op)
	{
		
		case Deposit:
		{
			system("clear");
			int amount;
			printf("\nEnter the amount to deposit ");
			scanf("%d",&amount);
			deposit(b,amount);
			menu_exit(b);
		}
		break;
		case Withdraw:
		{
			
			int amount;
			printf("\nEnter the amount to withdraw ");
			if (scanf("%d",&amount)!=1 || (amount%500 != 0))
			{
				system("clear");
				printf ("\n500 denomination only! \n");

				process(b ,op);

			}
			else{
				withdraw(b,amount);
				Option( b );
			}

		}
		break;
		case acount_detail:
		{
			system("clear");
			Print_detail (b);
			menu_exit(b);
		}
		break;
		case Quit:
		{
			printf("\nThank you !  Visit Again!");
			exit(0);
		}
		break;
	}
}

int main ()
{
	int I;
	int id = 1234;
	printf("HI!...");
	printf("\nEnter you PIN :");
	if (scanf("%d",&I)!=1 || I!= id)
	{
		printf ("NO user found...");
		return 0;
	}
	else
	{
		system("clear");
	}
	Bank shek;
	update_detail(&shek);
	printf ("Hi %s! \n\n",shek.name);

	Option( &shek );

	return 0;
}
// Updated version 1
