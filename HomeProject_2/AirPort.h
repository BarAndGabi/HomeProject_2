#ifndef AIRPORT_H;
#define AIRPORT_H ;
#include "Address.h"

typedef struct
{
	char *airportName;
	Address airportAddress;
} Airport;

int initAirport(Airport *pAirport);
void printAirport(Airport *pAirport);
void freeAirport(Airport *pAirport);
int isSameAirport(const void* e1, const void* e2);
int isAirportName(Airport *pAirport);

#endif //AirPort