#define _CRT_SECURE_NO_WARNINGS
#include "AirPort.h"
#include "Address.h"
#include"Utill.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int initAirport(Airport * pAirport)
{
	printf("You are about to init Airport get ready:\n");
	pAirport->airportName = createDynStr("airport name");
	printf("Please init Address:\n");
	Address pAddress;
	if (!initAddress(&pAddress))
	{
		freeAddress(&pAddress);
		return 0;
	}
	pAirport->airportAddress = addressBuffer(&pAddress);
	return 1;
}

void printAirport(Airport * pAirport)
{
	printf("The Airport name is:%s\n", pAirport->airportName);
	printAddress(pAirport->airportAddress);
}

void freeAirport(Airport * pAirport)
{
	free(pAirport->airportAddress);
	free(pAirport->airportName);
}

int isSameAirport(const Airport * e1, const Airport * e2)
{
	if ((strcmp(e1->airportName,e1->airportName)) == 0)
		return 1;
	
	return 0;
}



int isAirportName(const Airport * pAirport,const char* nameOfAirport)
{
		int check=strcmp(pAirport->airportName, nameOfAirport);
		if (check != 0)
			return 0;

		return 1;
}

