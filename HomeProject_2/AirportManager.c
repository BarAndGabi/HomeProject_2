#define _CRT_SECURE_NO_WARNINGS

#include "AirportManager.h"
#include "AirPort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


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
void initAirportManager(AirportManager * pAirportManager)
{
	pAirportManager->airportsCounter = 0;
	pAirportManager->airports = NULL;

}

void checkFromUser(AirportManager * pAirportManager)
{
	int ok = initManagerMenu();
	while (ok)
	{
		addAirport(pAirportManager);
		ok = initManagerMenu();
	}
}


void printAirportManager(AirportManager * pAirportManager)
{
	printf("The number of airports are:%d\n The airports are:\n",pAirportManager->airportsCounter);
	for (size_t i = 0; i < pAirportManager->airportsCounter; i++)
	{
		printAirport(&pAirportManager->airports[i]);
	}
}

void freeAirportManager(AirportManager * pAirportManager)
{
	for (size_t i = 0; i < pAirportManager->airportsCounter; i++)
	{
		freeAirport(&pAirportManager->airports[i]);
		free(&pAirportManager->airports[i]);
	}
}

int addAirport(AirportManager * pAirportManager)
{
	Airport pA;
	
	if (!initAirport(&pA)) {
		freeAirport(&pA);
		free(&pA);
		return 0;
	}

	pAirportManager->airports = (Airport*)realloc(pAirportManager->airports, (pAirportManager->airportsCounter + 1)*sizeof(Airport));
	if (!pAirportManager->airports) {
		for (size_t i = 0; i < pAirportManager->airportsCounter; i++)
		{
			freeAirport(&pA);
			free(&pA);
		}
		return 0;
	}

	pAirportManager->airports[pAirportManager->airportsCounter] = pA;
	pAirportManager->airportsCounter++;
	return 1;
}

Airport * findAirportByName(const char * airportName,const AirportManager * pA)
{
	
	for (size_t i = 0; i < pA->airportsCounter; i++)
	{
		if (isAirportName(&pA->airports[i],airportName)==1) {
			return &pA->airports[i];
		}
		
	}

	return NULL;

}



