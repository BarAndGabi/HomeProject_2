#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Airport.h"
#include "Utill.h"
#define _AIRPORTMANGER

typedef struct
{
	Airport* airports;
	int airportsCounter;
} AirportManager;

void initAirportManager(AirportManager *pAirportManager);
void checkFromUser(AirportManager* pAirportManager);
void printAirportManager(AirportManager* pAirportManager);
void freeAirportManager(AirportManager* pAirportManager);
int addAirport(AirportManager* pAirportManager);
Airport* findAirportByName(const char* airportName,const AirportManager* pA);
int checkIfEnoughAirports(AirportManager* pA);
void printOnlyAirPortNames(AirportManager* pA);