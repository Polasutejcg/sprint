#include <common.h>
#include <driver.h>

int driverMainMenu()
{
	int ch = 0;
	printf("\n\t===============Customer Trip Menu==========\n");
	printf("\n\tPress,");
	printf("\n\t1. Update or Manage");
	printf("\n\t2. Check Booked cab details");
	printf("\n\t3. Mark complete trip");
	printf("\n\t4. Return Back to Main Menu");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

DRIVER* signUpDriver(DRIVER *head)
{
	int ch;
	DRIVER *newNode = NULL;
	DRIVER *tmpNode = head;

	newNode = (DRIVER*)malloc(sizeof(DRIVER));
	newNode->next = NULL;
	printf("\n\tEnter Driver Details,");
	printf("\n\tName: ");
	getchar();
	scanf("%[^\n]s", newNode->name);
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);

	printf("\n\tGender: ");
	getchar();
	scanf("%c",&newNode->gender);
	printf("\n\tPhone Number: ");
	scanf("%d",&newNode->phone);
	printf("\n\tCAB Details");
	printf("\n\tChoose Car Model: ");
	printf("\n\t1. Alto ");
	printf("\n\t2. Mahindra");
	printf("\n\t3. Honda");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			strcpy(newNode->CAR.carModel,"Alto");
			break;
		case 2:
			strcpy(newNode->CAR.carModel,"Mahindra");
			break;
		case 3:
			strcpy(newNode->CAR.carModel,"Honda");
			break;
		default:
			strcpy(newNode->CAR.carModel,"Alto");

	}
	
	printf("\n\tCar Reg No: ");
	getchar();
	scanf("%[^\n]s",newNode->CAR.carRegNo);
	printf("\n\tUser Name: ");
	scanf("%s", newNode->dName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->dPasswd);

	if(head == NULL)
	{
		head = newNode;
		tmpNode = newNode;
	}
	else
	{
		while(tmpNode->next != NULL){
			tmpNode = tmpNode->next;
		}
		tmpNode->next = newNode;
		tmpNode = tmpNode->next;
	}

	return head;
}


int signInDriver(DRIVER *head)
{
	char lName[20], lPasswd[20];
	int ret = 0;
	printf("\n\t===============Driver Login=================\n");
	printf("\n\tEnter,");
	printf("\n\tUser Name: ");
	scanf("%s",lName);
	printf("\n\tPassword: ");
	scanf("%s",lPasswd);

	ret = findLRecDrv(head, lName, lPasswd);
	if(ret == 1)
		printf("\n\tLogged In");
	else
		printf("\n\tTry Again");

	return ret;
}

int findLRecDrv(DRIVER *head, char *lName, char *lPasswd)
{
	int flag = 0;
	while(head != NULL)
	{
		if((strcmp(head->dName, lName) == 0)&&(strcmp(head->dPasswd, lPasswd) == 0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	return flag;	
}


void dispDriver(DRIVER *head)
{
	while(head != NULL)
	{
		printf("\n\t%d",head->_id);
		printf("\n\t%d",head->phone);
		printf("\n\t%s",head->name);
		printf("\n\t%c",head->gender);
		printf("\n\t%s",head->dName);
		printf("\n\t%s",head->dPasswd);
		printf("\n\t%s",head->CAR.carRegNo);
		printf("\n\t%s",head->CAR.carModel);
		head = head->next;
	}
}

int updateDDetails(DRIVER *head)
{
	//int _id;
	DRIVER _dd;
	int flag = 0;
	int ch=0;
	printf("\n Enter your id to update:");
	getchar();
	//scanf("%d",&newNode->_id);
	scanf("%d",&_dd._id);
	while(head != NULL)
	{
		if(head->_id == _dd._id)
		{
			printf("\n\tChoose: ");
			printf("\n\t1. upadte name ");
			printf("\n\t2. update phone number");
			printf("\n\t3. update driver user name");
			printf("\n\t4. update driver passwrd");
			printf("\n\t5. update cab reg no");
			printf("\n\t6. Update car model");
			printf("\n\tChoice: ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					printf("\n Enter name to update:");
					getchar();
					scanf("%[^\n]s",_dd.name);
					strcpy(head->name,_dd.name);
					break;
				case 2:
					printf("\n Enter phone number to update:");
					getchar();
					scanf("%d",&_dd.phone);
					head->phone ==_dd.phone;
					break;
				case 3:
					printf("\n Enter user name to update:");
					getchar();
					scanf("%[^\n]s",_dd.dName);
					strcpy(head->dName,_dd.dName);
					break;
				case 4:
					printf("\n Enter user passwrd to update:");
					getchar();
					scanf("%[^\n]s",_dd.dPasswd);
					strcpy(head->dPasswd,_dd.dPasswd);
					break;
				case 5:
				    printf("\n\tUpdate Car Reg No: ");
					getchar();
					scanf("%[^\n]s",_dd.CAR.carRegNo);
					strcpy(head->CAR.carRegNo,_dd.CAR.carRegNo);
					break;
				case 6:
				    printf("\n\tUpdate Car Model: ");
					getchar();
					scanf("%[^\n]s",_dd.CAR.carModel);
					strcpy(head->CAR.carModel,_dd.CAR.carModel);
					break;

				

				}
			break;
		}
		head = head->next;
	}
	//writeDD(head);

	if(flag == 1)
		return 1;
	return 0;
}
