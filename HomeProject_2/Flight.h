#pragma once
#include "Date.h"
#include "Airplane.h"

typedef struct
{
	char* airportSourceName;
	char* airportDestinationName;
	Airplane airplaneDetails;
	Date date;
} Flight;

int initFligt(Flight* pF);
void printFlight(Flight* pF);
void freeFlight(Flight* pF);
int isFlightFromSourceName(Flight* pF);
int isFlightToDestName(Flight* pF);
int isPlaneCodeInFlight(Flight* pF);
int isPlaneTypeInFlight(Flight* pF);
