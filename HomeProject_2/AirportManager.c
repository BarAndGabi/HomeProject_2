#include "AirportManager.h"
int initManagerMenu()
{
	int choise;
	printf("enter 1 if you wish to add airport , enything else will abort\n");
	scanf("%d", &choise);
	if (choise == 1)
		return 1;
	else
		return 0;
}
int initAirportManager(AirportManager * pAirportManager)
{
	while (initManagerMenu() == 1)
	{
		//init airport
	}
	
	return 1;
}
