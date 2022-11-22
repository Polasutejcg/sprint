/*************************************************************************
** 
**  FILE NAME    : app.c
**
**  DESCRIPTION  : Program to to extract Customer and cab driver details and perform login operation
**                
**
**  Revision History:
**  DATE         NAME                REFERENCE          REASON
**
**  21-11-22    Polasu Teja Sri      New           Initial creation
**
**  Copyright 2022, Altran Group All Rights Reserved
**
***************************************************************************
**                    STANDARD HEADER FILES
*****************************************************************************/
#include<app.h>
/**************************************************************************
**
** FUNCTION NAME: signUpCustomer
**
** DESCRIPTION:  It read the data from Customer
**
** RETURNS:  SUCCESS 
*****************************************************************************/


CD* signUpCustomer(CD *cd, int *_id)
{
	CD *newNode =NULL;
	CD *head = NULL;
	head = cd;

	newNode = (CD *)malloc(sizeof(CD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		cd = newNode;
	}
	else
	{
		while(cd->next != NULL)
			cd = cd->next;

		cd->next = newNode;
		cd = cd->next;
	}
	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
    printf("\n\tEnter Passwrd: ");
	getchar();
	scanf("%[^\n]s",newNode->_passwrd);
    printf("\n\tEnter your Place: ");
	getchar();
	scanf("%[^\n]s",newNode->_place);
    printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	*_id = newNode->_id;
	
	return head;
    
}

/**************************************************************************
**
** FUNCTION NAME: signUpDriver
**
** DESCRIPTION:  It read the data from Cab Driver
**
** RETURNS:  SUCCESS 
*****************************************************************************/


DD* signUpDriver(DD *dd, int *_id)
{
	DD *newNode =NULL;
	DD *head = NULL;
	head = dd;
	newNode = (DD *)malloc(sizeof(DD));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		dd = newNode;
	}
	else
	{
		while(dd->next != NULL)
			dd = dd->next;

		dd->next = newNode;
		dd = dd->next;
	}
	printf("\n\tEnter ID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tEnter Name: ");
	getchar();
	scanf("%[^\n]s",newNode->_name);
	printf("\n\tEnter Passwrd: ");
	getchar();
	scanf("%[^\n]s",newNode->_passwrd);
    printf("\n\tEnter Phone Number: ");
	getchar();
	scanf("%d",&newNode->_phonenum);
	printf("\n\tEnter Gender (M/F/O): ");
	getchar();
	scanf("%c",&newNode->_gender);
	*_id = newNode->_id;

	
	return head;
}
int signInCustomer(CD *head)
{
	CD _cd;
	int flag = 0;
	
	printf("\n\tEnter User Name: ");
    getchar();
    scanf("%[^\n]",_cd._name);
	//scanf("%s", _cd._name);
	printf("\n\tEnter Password: ");
	//scanf("%s",_cd._passwrd);
    getchar();
    scanf("%[^\n]",_cd._passwrd);
	while(head != NULL)
	{
		if((strcmp(head->_name, _cd._name)==0)&&(strcmp(head->_passwrd, _cd._passwrd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}

int signInDriver(DD *head)
{
	DD _dd;
	int flag = 0;
	
	printf("\n\tEnter User Name: ");
	getchar();
    scanf("%[^\n]",_dd._name);
    printf("\n\tEnter Password: ");
	getchar();
    scanf("%[^\n]",_dd._passwrd);
	while(head != NULL)
	{
		if((strcmp(head->_name, _dd._name)==0)&&(strcmp(head->_passwrd, _dd._passwrd)==0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	if(flag == 1)
		return 1;
	return 0;
}


DD* loadDD()
{
	FILE *fp = NULL;
	DD *newNode = NULL;
	DD *head = NULL;
	DD *dd; 
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };
	
	fp = fopen("./data/DD.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		// head = newNode;
		while(fgets(tmpBuff, 256, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				head = newNode;
				dd = newNode;
				tokenizeDD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (DD *)malloc(sizeof(DD));
				newNode->next = NULL;
				dd->next = newNode;
				tokenizeDD(newNode, tmpBuff);
				dd = dd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}


CD* loadCD()
{
	FILE *fp = NULL;
	CD *newNode = NULL;
	CD *head = NULL;
	CD *cd; 
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };
	
	fp = fopen("./data/CD.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		// head = newNode;
		while(fgets(tmpBuff, 256, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CD *)malloc(sizeof(CD));
				newNode->next = NULL;
				head = newNode;
				cd = newNode;
				tokenizeCD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CD *)malloc(sizeof(CD));
				newNode->next = NULL;
				cd->next = newNode;
				tokenizeCD(newNode, tmpBuff);
				cd = cd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}



int tokenizeDD(DD *dd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	dd->_id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,dd->_name);
	
	tokens = strtok(NULL, ",");
    removeLeading(tokens,dd->_passwrd);
	removeTrailing(dd->_passwrd);
	tokens = strtok(NULL, ",");
	dd->_phonenum =  atoi(tokens);
	tokens = strtok(NULL, ",");
	dd->_gender =  atoi(tokens);
	//dd->_gender = tokens[0];
    return 0;
}

int tokenizeCD(CD *cd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	cd->_id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,cd->_name);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,cd->_passwrd);
	removeTrailing(cd->_passwrd);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cd->_place);
	tokens = strtok(NULL, ",");
	cd->_phonenum =  atoi(tokens);
    tokens = strtok(NULL, ",");
	cd->_gender =  atoi(tokens);
	//cd->_gender = tokens[0];
    return 0;
}

int writeDD(DD *dd)
{
	FILE *fp = NULL;

	fp = fopen("./data/DD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(dd == NULL)
		printf("\n\t NULL Write pd");
	while(dd != NULL){
		fprintf(fp,"%d, %s, %s, %d, %c\n",dd->_id,dd->_name,dd->_passwrd,dd->_phonenum,dd->_gender);
		dd = dd->next;
	}

	fclose(fp);
    return 0;

}



int writeCD(CD *cd)
{
	FILE *fp = NULL;

	fp = fopen("./data/CD.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	fseek(fp, 0L, SEEK_END);
	if(cd == NULL)
		printf("\n\t NULL Write pd");
	while(cd != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%d, %s, %s, %s, %d, %c\n",cd->_id,cd->_name,cd->_passwrd,cd->_place,cd->_phonenum,cd->_gender);
		cd = cd->next;
	}

	fclose(fp);
    return 0;
}

void removeLeading(char *str, char *str1)
{
    int idx = 0, j, k = 0;
 
    // Iterate String until last
    // leading space character
    while (str[idx] == ' ' || str[idx] == '\t' || str[idx] == '\n')
    {
        idx++;
    }
 
    // Run a for loop from index until the original
    // string ends and copy the content of str to str1
    for (j = idx; str[j] != '\0'; j++)
    {
        str1[k] = str[j];
        k++;
    }
 
    // Insert a string terminating character
    // at the end of new string
    str1[k] = '\0';
 
}

void removeTrailing(char *str)
{
	if((str[strlen(str)-1] == ' ' || str[strlen(str)-1] == '\t' || str[strlen(str)-1] == '\n'))
    {
    	str[strlen(str)-1] = '\0';
    }

}

void dispDD(DD *dd)
{
	while(dd != NULL){
		printf("\n\tID: ");
		printf("%d",dd->_id);
		printf("\tName: ");
		printf("%s",dd->_name);
        printf("\tpasswrd: ");
		printf("%s",dd->_passwrd);
        printf("\n\tphone number: ");
		printf("%d",dd->_phonenum);
		printf("\tGender (M/F/O): ");
		printf("%c",dd->_gender);
		dd = dd->next;
	}
}

Customer_Car_Details* addCustomerCarDetails(Customer_Car_Details *ccd, int *_id)
{
	Customer_Car_Details *newNode =NULL;
	Customer_Car_Details *head = NULL;
	head = ccd;
	int _status;

	newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		head = newNode;
		ccd = newNode;
	}
	else
	{
		while(ccd->next != NULL)
			ccd = ccd->next;

		ccd->next = newNode;
		ccd = ccd->next;
	}
	printf("\n\tEnter Car ID: ");
	getchar();
	scanf("%s",&newNode->car_id);
	printf("\n\tEnter Customer Name: ");
	getchar();
	scanf("%[^\n]s",newNode->cust_name);
    printf("\n\tEnter Pick address: ");
	getchar();
	scanf("%[^\n]s",newNode->pick);
    printf("\n\tEnter drop address: ");
	getchar();
	scanf("%[^\n]s",newNode->drop);
	printf("\n\tEnter 1/0 for booking : ");
	//getchar();
	scanf("%d",&_status);
	if(_status == 1){
		printf("\n\tBooking succesfull");
	}
	else{
		printf("\n Booking cancelled");
	}
	*_id = newNode->car_id;
	
	return head;
    
}



Customer_Car_Details* loadccD()
{
	FILE *fp = NULL;
	Customer_Car_Details *newNode = NULL;
	Customer_Car_Details *head = NULL;
	Customer_Car_Details *ccd; 
	int _fSize = 0;
	char tmpBuff[256] = {'\0', };
	
	fp = fopen("./data/Customer_Car_Details.dat","r");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return NULL;
	}

	fseek(fp, 0L, SEEK_SET);
	fseek(fp, 0L, SEEK_END);
	_fSize = ftell(fp);
	if(_fSize == 0) /* No records */
	{
		head = NULL;
	}
	else
	{
		fseek(fp, 0L, SEEK_SET);
		memset(tmpBuff,'\0', 256);
		// head = newNode;
		while(fgets(tmpBuff, 256, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
				newNode->next = NULL;
				head = newNode;
				ccd = newNode;
				tokenizeccD(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (Customer_Car_Details *)malloc(sizeof(Customer_Car_Details));
				newNode->next = NULL;
				ccd->next = newNode;
				tokenizeccD(newNode, tmpBuff);
				ccd = ccd->next;	
			}
			

		}

	}

	fclose(fp);
	return head;

}

int writeccD(Customer_Car_Details *ccd)
{
	FILE *fp = NULL;

	fp = fopen("./data/Customer_Car_Details.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}

	//fseek(fp, 0L, SEEK_END);
	if(ccd == NULL)
		printf("\n\t NULL Write pd");
	while(ccd != NULL){
		//printf("\n%d = %c", ld->_passwd[strlen(ld->_passwd)-1],ld->_passwd[strlen(ld->_passwd)-1]);
		fprintf(fp,"%s, %s, %s, %s\n\t",ccd->car_id,ccd->cust_name,ccd->pick,ccd->drop);
		ccd = ccd->next;
	}

	fclose(fp);
    //return 0;
}


int tokenizeccD(Customer_Car_Details *ccd, char *tmpBuff)
{
	char *tokens;
	tokens = strtok(tmpBuff, ",");
	//tokens = strtok(NULL, ",");
	removeLeading(tokens,ccd->car_id);
	//ccd->car_id = atoi(tokens);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,ccd->cust_name);

	tokens = strtok(NULL, ",");
	removeLeading(tokens,ccd->pick);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,ccd->drop);
	//removeTrailing(cd->_passwrd);
    //cd->_gender = tokens[0];
    return 0;
}
