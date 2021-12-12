#define _CRT_SECURE_NO_WARNINGS
#include "AirLine.h"
int initAirLine(AirLine * pAirLine)
{
	pAirLine->numberOfFlights = 0;
	if (!(pAirLine->name = createDynStr("airline name"))) {
		free(pAirLine->name);
		return 0;
	}
	pAirLine->allFlights = NULL;
	return 1;
}


void printAirLine(AirLine* pAirLine) {
	if (pAirLine->numberOfFlights == 0)
		printf("\nAirline name:%s and has no flights.\n", pAirLine->name);

	printf("Airline name:%s and has %d flights :\n", pAirLine->name, pAirLine->numberOfFlights);
	for (size_t i = 0; i < pAirLine->numberOfFlights; i++)
	{
		PrintFlight(pAirLine->allFlights[i]);
	}
}

int addFlight(AirLine * pAirLine, AirportManager* pAirportManager)
{
	Flight* pF = (Flight*)malloc(sizeof(Flight));
	if (!pF) {
		free(pF);
		return 0;
	}

	if (!initFlight(pF, pAirportManager)) {
		freeFlight(pF);
		free(pF);
	}
	pAirLine->allFlights = (Flight**)realloc(pAirLine->allFlights, (pAirLine->numberOfFlights + 1) * sizeof(Flight*));

	if (!pAirLine->allFlights)
	{
		for (int i = 0; i < pAirLine->numberOfFlights; i++)
			freeFlight(pF);
		free(pF);
	}

	pAirLine->allFlights[pAirLine->numberOfFlights] = pF;
	pAirLine->numberOfFlights++;
	return 1;
}

void doPrintFlightsWithPlaneCode(AirLine * pAirLine, const char * code)
{
	char* temp = NULL;
	int counter = 0;
	for (size_t i = 0; i < pAirLine->numberOfFlights; i++)
	{
		if (isPlaneCodeInFlight(pAirLine->allFlights[i], code) == 1)
		{
			PrintFlight(pAirLine->allFlights[i]);
			counter++;
		}
		
	}
	if (counter == 0)
	{
		printf("\nthere are no flights with this code\n");
	}

}

void doPrintFlightsWithPlaneType(AirLine * pAirLine, const airplaneType type)
{
	int counter = 0;
	for (size_t i = 0; i < pAirLine->numberOfFlights; i++)
	{
		if (isPlaneTypeInFlight(pAirLine->allFlights[i], type)) {
			PrintFlight(pAirLine->allFlights[i]);
			counter++;
		}
	}
	if (counter == 0)
		printf("There are no planes with this type in this airline");
}

int doCountFlightsFromName(AirLine * pAirLine, const char* name)
{
	int counter = 0;
	for (int i = 0; i < pAirLine->numberOfFlights; i++) {
		if (isFlightFromSourceName(pAirLine->allFlights[i], name))
			counter++;
	}
	return counter;
}

void freeAirLine(AirLine * pAirLine)
{
	for (size_t i = 0; i < pAirLine->numberOfFlights; i++)
	{
		freeFlight(pAirLine->allFlights[i]);
		free(pAirLine->allFlights);
	}
}



