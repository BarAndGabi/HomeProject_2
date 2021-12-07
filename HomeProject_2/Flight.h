#ifndef _FLIGHT
#define _FLIGHT
#include "Date.h"
#include "Airplane.h"
typedef struct
{
	char* airportSourceName;
	char* airportDestinationName;
	Airplane airplaneDetails;
	Date date;
} Flight;
#endif // !_FLIGHT
