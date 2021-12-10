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

int initFlight(Flight* pF);
void PrintFlight(Flight* pF);
void freeFlight(Flight* pF);
int isFlightFromSourceName(Flight* pF,const char* sourceName);
int isFlightToDestName(Flight* pF,const char* destinationName);
int isPlaneCodeInFlight(Flight* pF,const char* planeCode);
int isPlaneTypeInFlight(Flight* pF,const airplaneType type);
