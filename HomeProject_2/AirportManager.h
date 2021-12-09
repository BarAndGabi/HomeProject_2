#define _CRT_SECURE_NO_WARNINGS
#ifndef _AIRPORTMANGER
#include "Airport.h"
#define _AIRPORTMANGER

typedef struct
{
	Airport** airports;
	int airportsCounter;
} AirportManager;

void initAirportManager(AirportManager *pAirportManager);
void checkFromUser(AirportManager* pAirportManager);
void printAirportManager(AirportManager* pAirportManager);
void freeAirportManager(AirportManager* pAirportManager);
int addAirport(AirportManager* pAirportManager);
Airport* findAirportByName(char* airportName,AirportManager* pA);
#endif // _AIRPORTMANGER
