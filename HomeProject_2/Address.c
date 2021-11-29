#include "Address.h"
#include <stdio.h>
#include <string.h>
int initAddress(Address *pA)
{
	pA->country = createDynStr("country name");
	pA->city = createDynStr("city name");
	pA->street = createDynStr("street name");
	printf("\nEnter house number:\n");
	scanf("%d", &pA->houseNumber);
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

char *createDynStr(const char *msg)
{
	char *str;
	char temp[255];
	printf("Enter %s: ", msg);
	scanf("%s", temp);

	str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);

	return str;
}
