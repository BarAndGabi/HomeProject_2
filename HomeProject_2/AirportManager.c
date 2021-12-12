#define _CRT_SECURE_NO_WARNINGS

#include "AirportManager.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int initManagerMenu()
{
	char choise;
	printf("enter 1 if you wish to add airport , enything else will abort\n");
	scanf("%c", &choise);
	while (choise =='\n') {
		clearInputBuffer();
		printf("you didnt enter anything enter a choise again:\n");
		scanf("%c", &choise);
	}
	if (choise == '1') {
		clearInputBuffer();
		return 1;
	}

	else
		clearInputBuffer();
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
	printLine();
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
	if ((findAirportByName(pA.airportName, pAirportManager) != NULL)) 
	{
		freeAirport(&pA);
		printf("There is an airport with this name\n");
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

int checkIfEnoughAirports(AirportManager * pA)
{
	if (pA->airportsCounter > 1)
		return 1;
	return 0;
}

void printOnlyAirPortNames(AirportManager * pA)
{
	if (pA->airportsCounter == 0)
		printf("There are no airports currently\n");

	for (size_t i = 0; i < pA->airportsCounter; i++)
	{
		printf("Airport %zd is %s",i,pA->airports[i].airportName) ;
	}
}




