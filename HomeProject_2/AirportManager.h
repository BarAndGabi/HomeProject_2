#pragma once
#ifndef _AIRPORTMANGER
#include "Airport.h"
#define _AIRPORTMANGER

typedef struct
{
	Airport* airports;
	int AirportsCounter;
} AirportManager;

int initAirportManager(AirportManager *pAirportManager);

#endif // !_AIRPORTMANGER
