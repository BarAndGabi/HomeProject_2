#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Address.h"
#include "Utill.h"
int initAddress(Address *pA)
{ 
	pA->country = createDynStr("country name");
	pA->city = createDynStr("city name");
	pA->street = createDynStr("street name");
	pA->houseNumber = createDynStr("house number");
	return 0;
}

void printAddress(Address *pA)
{
	//need to fill with the assignment discription
}

void freeAddress(Address *pA)
{
}

