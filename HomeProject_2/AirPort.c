#include "AirPort.h"

int initAirport(Airport * pAirport)
{
	printf("You are about to init Airport get ready:\n");
	printf("Enter Airpot name:\n ");
	printf("Please init Addres :\n");
	return 0;
}

int isSameAirport(const void* e1, const void* e2)
{
	const Airport* pE1 = (const Airport*)e1;
	const Airport* pE2 = (const Airport*)e2;

	return strcmp(pE1->airportName, pE2->airportName);
}

