#include "Flight.h"


int initFlight(Flight * pF,AirportManager* pA)
{
	printf("This are the airports available:\n");

	for (size_t i = 0; i < pA->airportsCounter; i++)
	{
		printAirport(&pA->airports[i]);
	}
	printOnlyAirPortNames(pA);

	if (!(pF->airportSourceName = createDynStr("source name")))
		if(findAirportByName(pF->airportSourceName,pA)==NULL)
		return 0;
	if (!(pF->airportDestinationName = createDynStr("destination name"))) 
		if (findAirportByName( pF->airportDestinationName,pA) == NULL)
		return 0;
	Airplane newAirplane;
	initAirplane(&newAirplane);
	pF->airplaneDetails = newAirplane;
	Date newDate;
	if (!initDate(&newDate)) {
		freeDate(&newDate);
		return 0;
	}
	pF->date = newDate;
	return 1;
}


void PrintFlight(Flight * pF)
{
	printf("Flight from %s to %s ", pF->airportSourceName, pF->airportDestinationName);
	printDate(&pF->date);
	printAirplane(&pF->airplaneDetails);
}

int freeFlight(Flight * pF)
{
	Date freedate1 = pF->date;
	if (!freeDate(&freedate1))
		return 0;
	return 1;

}

int isFlightFromSourceName(Flight * pF, const char * sourceName)
{

	if (strcmp(pF->airportSourceName, sourceName)==0)
		return 1;

	return 0;
}

int isFlightToDestName(Flight * pF, const char * destinationName)
{
	if (strcmp(pF->airportDestinationName, destinationName)==0)
		return 1;

	return 0;
}

int isPlaneCodeInFlight(Flight * pF, const char * planeCode)
{
	if(strcmp(pF->airplaneDetails.code, planeCode)==0);
 	  return 1;
}

int isPlaneTypeInFlight(Flight * pF, const airplaneType type)
{
	if(pF->airplaneDetails.type==type)
	return 1;

	return 0;
}
