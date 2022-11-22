#include <app.h>

int main()
{
	DD *dd = NULL;
	DD *headdd = NULL;
	CD *cd = NULL;
	CD *headcd = NULL;
    Customer_Car_Details *ccd = NULL;
	Customer_Car_Details *headccd = NULL;
	int ch = 0, _id=0;
    char _name[256] = {'\0', };
    memset(_name, '\0', 256);
   // char _name[30];
    //char _passwrd[30];
	headdd = loadDD(dd);/*loading driver details from DD.dat*/
	headcd = loadCD(cd);/*loading Customer details from CD.dat*/
    headccd = loadccD(ccd);
    while(1)
    {
        printf("\n\t           *************************  Welcome  ************************   \n\t");
        printf("\n\t                            CAB BOOKING MANAGEMENT SYSTEM                       \n\t");
        printf("\n\t           ************************************************************    \n\t");
        printf("\n\tPress\n\t1. Register new Customer\n\t2. Register new Cab Driver\n\t3. login as Customer\n\t4. login as Cab Driver\n\t0. Quit\n\tChoice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    headcd = signUpCustomer(headcd,&_id);
                    writeCD(headcd);
                    printf("\n\tSuccessfully Registered\n");
                    sleep(2);
                    break;
            case 2:
                    headdd = signUpDriver(headdd,&_id);
                    writeDD(headdd);
                    printf("\n\tSuccessfully Registered\n");
                    sleep(2);
                    break;

            case 3:
                    if(signInCustomer(headcd) == 0){
                        printf("\n\tUser/password does not match db\n");

                    }
                    else{
                        printf("\n\tLogged In\n");
                        printf("\n\t           *************************  Welcome  ************************   \n\t");
                        printf("\n\t                                    USER SCREEN                      \n\t");
                        printf("\n\t           ************************************************************    \n\t");
                        printf("\n\tPress\n\t1. Schedule Trip\n\t2. Book Trip\n\t3. Check cab Driver Details\n\t4. Check cab Details\n\t5. Check Bill\n\t6. Make Payment\n\t0. Quit\n\tChoice: ");
                         scanf("%d",&ch);
                        switch(ch)
                        {
                            case 1:
                                /*headccd=addCustomerCarDetails(headccd, &_id);
                                writeccD(headccd);
                                sleep(1);
                                break;*/
                                exit(EXIT_SUCCESS);
                            case 2:
                                headccd=addCustomerCarDetails(headccd, &_id);
                                writeccD(headccd);
                                sleep(1);
                                break;
                            case 0:
                                exit(EXIT_SUCCESS);
                    
                            default:
                                printf("Incorrect Choice:");

                        }
                    }
                    sleep(2);
                    break;
            case 4:
                    if(signInDriver(headdd) == 0){
                        printf("\n\tUser/password does not match db\n");

                    }
                    else{
                        dispDD(headdd);
                        printf("\n\tLogged In\n");
                        printf("\n\t           *************************  Welcome  ************************   \n\t");
                        printf("\n\t                                    CAB DRIVER SCREEN                      \n\t");
                        printf("\n\t           ************************************************************    \n\t");
                        printf("\n\tPress\n\t1. Update Profile\n\t2. Manage Car dDetails\n\t3. Check Schedule Trip\n\t4. Check Book Trip\n\t5. Marked completed\n\t0. Quit\n\tChoice: ");
                        scanf("%d",&ch);
                        switch(ch)
                        {
                            case 1:
                                dispDD(headdd);
                            case 0:
                                exit(EXIT_SUCCESS);
                    
                            default:
                                printf("Incorrect Choice:");

                        }
                    }
                    sleep(2);
                    break;

            case 0:
                    exit(EXIT_SUCCESS);
                    
            default:
                    printf("Incorrect Choice:");
        }
    }
    
	printf("\n\n");

	return 0;
}