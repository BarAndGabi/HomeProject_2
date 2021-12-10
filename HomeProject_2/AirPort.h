#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "Address.h"

typedef struct
{
	char *airportName;
	Address airportAddress;
} Airport;

int initAirport(Airport *pAirport);
void printAirport(Airport *pAirport);
void freeAirport(Airport *pAirport);
int isSameAirport( const Airport* e1, const Airport* e2);
int isAirportName(const Airport *pAirport,const char* nameOfAirport);

