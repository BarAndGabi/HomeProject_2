#include "Flight.h"

int initFlight(Flight * pF)
{
	if (!(pF->airportSourceName = createDynStr("Enter source name")))
		return 0;
	if (!(pF->airportDestinationName = createDynStr("Enter destination name"))) 
		return 0;
	Airplane newAirplane;
	initAirplane(&newAirplane);
	pF->airplaneDetails = newAirplane;
	return 1;
}

void PrintFlight(Flight * pF)
{
	printf("Flight from %s to %s ", pF->airportSourceName, pF->airportDestinationName);
	printDate(&pF->date);
	printAirplane(&pF->airplaneDetails);
}

void freeFlight(Flight * pF)
{
	freeDate(pF->date);
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
