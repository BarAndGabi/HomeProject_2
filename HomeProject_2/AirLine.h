#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "Flight.h"
typedef struct
{
	char* name;
	int numberOfFlights;
	Flight** allFlights;

} AirLine;

int initAirLine(AirLine *pAirLine);
void printAirLine(AirLine* pAirLine);
int addFlight(AirLine* pAirLine,AirportManager* pAirportManager);
void doPrintFlightsWithPlaneCode(AirLine* pAirLine,const char* Code);
void doPrintFlightsWithPlaneType(AirLine* pAirLine,const airplaneType type);
int  doCountFlightsFromName(AirLine* pAirLine,const char* name);
void freeAirLine(AirLine* pAirLine);

