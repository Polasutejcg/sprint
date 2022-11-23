#include <common.h>
#include <cust.h>
#include <driver.h>
#include <trip.h>

int main()
{
	int ch = 0, bid=0;
	int retVal = 0, flag=0;

	CUST *hCust = NULL;
	DRIVER *hDriver = NULL;
	TRIP *hTrip = NULL;
	while(1){
		ch = mainMenu();
		switch(ch)
		{
			case 1:
				while(1)
				{
						ch = custMainMenu();
						switch(ch)
						{
							case 1:
								hCust = signUpCust(hCust);

								break;
							case 2:
								retVal = signInCust(hCust);
								if(retVal == 1)
								{
									while(1){
										ch = custMenu();
										switch(ch)
										{
											case 1:
												hTrip = bookTrip(hTrip,&bid);
												printf("\n\tYour Booking is confirmed with following details\n");
												printBook(hTrip, hCust,hDriver, bid);
												break;
											case 2:
												//checkDrv();
												break;
											case 3:
												//checkCab();
												//dispTrip(hTrip);
												break;
											case 4:
												printf("\n\tEnter the Booking ID: ");
												scanf("%d",&bid);
												printBook(hTrip, hCust,hDriver, bid);
												break;
											case 5:
												flag = 1; 
												/*printf("\n\tReturn to Main Menu");*/
												break;
											default:
												printf("\nWrong Choice\n");

										}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
								}
								break;
							case 3:
								//dispCust(hCust);
								/*printf("\n\tReturning Back to MainMenu");*/
								writeCustDetails(hCust);
								flag = 1;
								break;
							default:
								printf("\n\tSomething went wrong");
						}
					if(flag == 1)
					{
						flag = 0;
						break;
					}
				}
				break;
			case 2:
				ch = driverMenu();
				switch(ch)
				{
					case 1:
						hDriver = signUpDriver(hDriver);

						break;
					case 2:
						retVal = signInDriver(hDriver);
						//retVal = signInCust(hCust);
								if(retVal == 1)
								{
									while(1){
										ch = driverMainMenu();
										switch(ch)
										{
											case 1:
												updateDDetails(hDriver);
												dispDriver(hDriver);
												break;
											case 2:
												//checkDrv();
												dispTrip(hTrip);
												break;
											case 3:
												markCompleteTrips(hTrip);
												//checkCab();
												break;
											case 4:
												flag = 1; 
												/*printf("\n\tReturn to Main Menu");*/
												break;
											default:
												printf("\nWrong Choice\n");

										}
										if(flag == 1)
										{
											flag = 0;
											break;
										}
									}
								}
								break;
					case 3:
						dispDriver(hDriver);
						printf("\n\tReturning Back to MainMenu");
						break;
					default:
						printf("\n\tSomething went wrong");
				}
				
				break;
			case 3:
				printf("\n\tThank You\n\n");
				exit(EXIT_SUCCESS);
			default:
				printf("\n\tWrong Choice\n");

		}	
	}
	
	if(hCust != NULL)
		free(hCust);
	printf("\n\n");

	return 0;

}