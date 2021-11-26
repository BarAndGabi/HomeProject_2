#ifndef AIRPORT_H;
#define AIRPORT_H;
#include "Address.h"

typedef struct {
	char* airPortName;
	Address airPortAddress;
}AirPort;

int initAirPort(AirPort* pAirPort);
void printAirPort(AirPort* pAirPort);
void freeAirPort(AirPort* pAirPort);
int isSameAirPort(AirPort* pAir1, AirPort* pAir2);
int isAirportName(AirPort* pAir);

#endif //AirPort