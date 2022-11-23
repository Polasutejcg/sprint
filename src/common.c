#include <common.h>


int mainMenu()
{
	int ch;
	printf("\n\t==================Main Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. Customer");
	printf("\n\t2. Cab Driver");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

int custMainMenu()
{
	int ch;
	printf("\n\t==================Customer's Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. SignUp");
	printf("\n\t2. SignIn");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;	
}



int driverMenu()
{
	int ch;
	printf("\n\t==================Driver's Menu========================\n");
	printf("\n\tEnter,");
	printf("\n\t1. SignUp");
	printf("\n\t2. SignIn");
	printf("\n\t3. Exit");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}
