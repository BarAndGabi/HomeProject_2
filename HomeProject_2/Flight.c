#include "Flight.h"


int initFlight(Flight * pF,AirportManager* pA)
{
	printf("This are the airports available:\n");
	printOnlyAirPortNames(pA);
	clearInputBuffer();

	if (!(pF->airportSourceName = createDynStr("source name"))) {
			return 0;
	}
	if (checkSource(pF, pA) == 0)
		return 0;
	if (!(pF->airportDestinationName = createDynStr("destination name"))) {
		return 0;
	}
	if (checkDest(pF, pA) == 0)
		return 0;
	removeChar(pF->airportSourceName, '\n');
	removeChar(pF->airportDestinationName, '\n');
	Airplane newAirplane;
	initAirplane(&newAirplane);
	pF->airplaneDetails = newAirplane;
	Date newDate;
	if (!initDate(&newDate)) {
		freeDate(&newDate);
		return 0;
	}
	pF->date = newDate;
	clearInputBuffer();
	return 1;
}


void PrintFlight(Flight * pF)
{
	removeChar(pF->airportSourceName, '\n');
	removeChar(pF->airportDestinationName, '\n');
	printf("\nFlight from %s to %s :\n", pF->airportSourceName, pF->airportDestinationName);
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

int isFlightFromSourceName(Flight * pF, const char * name)
{
	if (strcmp(pF->airportSourceName, name)==0)
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
	if(strcmp(pF->airplaneDetails.code, planeCode)==0)
 	  return 1;
	  return 0;
}

int isPlaneTypeInFlight(Flight * pF, const airplaneType type)
{
	if(pF->airplaneDetails.type==type)
	return 1;

	return 0;
}

int checkSource(Flight * pF, AirportManager * pA)
{
		while (findAirportByName(pF->airportSourceName, pA) == NULL) {
			printf("There isn't an airport with this name\n");
			if (!(pF->airportSourceName = createDynStr("source name")))
				return 0;
		}
	return 1;
}

int checkDest(Flight* pF,AirportManager* pA)
{
	while (findAirportByName(pF->airportDestinationName, pA) == NULL) {
			printf("There isn't an airport with this name\n");
			if (!(pF->airportDestinationName = createDynStr("Destenation")))
				return 0;
		}
	while (isFlightFromSourceName(pF, pF->airportDestinationName) ) {
		printf("choose diffrent from source\n");
		if (!(pF->airportDestinationName = createDynStr("destenation")));
			return 0;
	}
	

	return 1;
}


