#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Address.h"
#include "Utill.h"
int initAddress(Address *pA)
{ 
	pA->country = createDynStr("country name");
	pA->city = createDynStr("city name");
	pA->street = createDynStr("street name");
	printf("\nenter house number : ");
	scanf("%d", &pA->houseNumber);
	return 0;
}

void printAddress(Address *pA)
{

	//need to fill with the assignment discription
}

void freeAddress(Address *pA)
{
	free(pA->city);
	free(pA->country);
	free(pA->street);
}

int compareAddress(const Address * pA1, const Address * pA2)
{
	int check[] = {0,0,0};
	if (pA1->houseNumber != pA2->houseNumber)
		return 0;
	check[0] = strcmp(pA1->city,pA2->city);
	check[1] = strcmp(pA1->country, pA2->country);
	check[2] = strcmp(pA1->street, pA2->street);
	for (size_t i = 0; i < 3; i++)
	{
		if (check[i] == 0)
			return 0;
	}
	return 1;
}

