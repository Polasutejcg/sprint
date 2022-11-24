#include <common.h>
#include <cust.h>

int custMenu()
{
	int ch = 0;
	printf("\n\t===============Customer Trip Menu==========\n");
	printf("\n\tPress,");
	printf("\n\t1. Book Trip");
	printf("\n\t2. Check Driver Details");
	printf("\n\t3. Check Cab Details");
	printf("\n\t4. Print Booking Details");
	printf("\n\t5. Return Back to Main Menu");
	printf("\n\tChoice: ");
	scanf("%d",&ch);
	return ch;
}

CUST * signUpCust(CUST *head,int * _id)
{
	CUST *newNode = NULL;
	CUST *tmpNode = NULL;
	tmpNode = head;

	newNode = (CUST*)malloc(sizeof(CUST));
	newNode->next = NULL;
	
	if(head == NULL)
	{
		tmpNode = newNode;
		head = newNode;
	}
	else
	{
		while(head->next != NULL){
			head = head->next;
		}
		head->next = newNode;
		head = head->next;
	}

	printf("\n\tEnter Customer Details,");
	printf("\n\tID: ");
	scanf("%d",&newNode->_id);
	printf("\n\tName: ");
	getchar();
	scanf("%[^\n]s",newNode->name);
	printf("\n\tPhone Number: ");
	scanf("%d", &newNode->phone);
	printf("\n\tGender: ");
	getchar();
	scanf("%c",&newNode->gender);
	printf("\n\tUser Name: ");
	scanf("%s",newNode->cName);
	printf("\n\tPassword: ");
	scanf("%s",newNode->cPasswd);
	*_id = newNode->_id;

	return tmpNode;
}

int signInCust(CUST *head)
{
	//CUST _cust;
	char lName[20], lPasswd[20];
	int ret = 0;
	printf("\n\t===============Customer Login=================\n");
	printf("\n\tEnter,");
	printf("\n\tUser Name: ");
	scanf("%s",lName);
	printf("\n\tPassword: ");
	scanf("%s",lPasswd);

	/*

	logic to find user name exists
	 */

	ret = findLRecCust(head, lName, lPasswd);
	if(ret == 1)
		printf("\n\tLogged In");
	else
		printf("\n\tTry Again");

	return ret;
}


int findLRecCust(CUST *head, char *lName, char *lPasswd)
{
	int flag = 0;
	while(head != NULL)
	{
		if((strcmp(head->cName, lName) == 0)&&(strcmp(head->cPasswd, lPasswd) == 0))
		{
			flag = 1;
			break;
		}
		head = head->next;
	}

	return flag;	
}


void dispCust(CUST *head)
{
	while(head != NULL)
	{
		printf("\n\t%d",head->_id);
		head = head->next;
	}
}

int writeCustDetails(CUST* head)
{
	FILE *fp = NULL;

	fp = fopen("./data/CUST.dat","w+");
	if(fp == NULL)
	{
		perror("\n\tfopen() ");
		return -1;
	}
	fseek(fp, 0L, SEEK_END);
	if(head == NULL){
		printf("\n\t No Records Present\n");
		return 0;
	}
	while(head != NULL){
		fprintf(fp,"%d, %s, %d, %c, %s, %s\n",head->_id,head->name,head->phone, head->gender, head->cName, head->cPasswd);
		head = head->next;
	}
	fclose(fp);
	return 0;
}


CUST* loadCustDetails()
{
	FILE *fp = NULL;
	CUST *newNode = NULL;
	CUST *head = NULL;
	CUST *cust; 
	int _fSize = 0;
	char tmpBuff[1024] = {'\0', };
	
	fp = fopen("./data/CUST.dat","r");
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
		memset(tmpBuff,'\0', 1024);
		
		while(fgets(tmpBuff, 1024, fp)){
			
			if(head == NULL) /* first record */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				head = newNode;
				cust = newNode;
				tokenizeCUST(newNode, tmpBuff);
						
			}
			else /* rest of the records */
			{
				newNode = (CUST *)malloc(sizeof(CUST));
				newNode->next = NULL;
				cust->next = newNode;
				tokenizeCUST(newNode, tmpBuff);
				cust = cust->next;	
			}
			memset(tmpBuff,'\0', 1024);
			

		}

	}

	fclose(fp);
	// printf("\n\tHead : %u\nlast node: %u\n", head, pd);
	return head;
}


int tokenizeCUST(CUST *cust, char *tmpBuff)
{
	char *tokens;
	if(tmpBuff != NULL){
		tokens = strtok(tmpBuff,",");
		cust->_id = atoi(tokens);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->name);
		tokens = strtok(tmpBuff,",");
		cust->phone = atoi(tokens);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->gender);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->cName);
		tokens = strtok(tmpBuff,",");
		removeLeading(tokens,cust->cPasswd);
	}
	return 0;
}
/*

int tokenizeCUST(CUST *cust, char *tmpBuff)
{
	char *tokens;
	//int i, count;
	//char *tmpBuff1;
	if(tmpBuff != NULL){
	tokens = strtok(tmpBuff, ",");
	cust->_id = atoi(tokens);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->name);
	tokens = strtok(tmpBuff, ",");
	cust->phone = atoi(tokens);
    tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->gender);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->cName);
	tokens = strtok(NULL, ",");
	removeLeading(tokens,cust->cPasswd);
	removeTrailing(cust->cPasswd);
    
	//tokens = strtok(NULL, ",");
	}
	//cd->_gender = tokens[0];
    return 0;

	//dispPD(pd);
}
*/