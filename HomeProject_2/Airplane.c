#define _CRT_SECURE_NO_WARNINGS
#include "Airplane.h"
#include <stdlib.h>
#include <stdio.h>

const char* types[eNofTypes]={ "Passangers", "Cargo","Military"};
void initAirplane(Airplane *pAirplane)
{
	pAirplane->type = getTypeFromUser();
	clearInputBuffer();
	char* temp = createDynStr("the code");
	if (!temp) {
		free(temp); 
	}
	while (checkCorrectCode(temp)==0)
	{
		free(temp);
		temp = createDynStr("code again please");
		if (!temp) {
		free(temp);
		}
		checkCorrectCode(temp);
	}
	strcpy(pAirplane->code, temp);;
}

void printAirplane(Airplane * pAirplane)
{
	printf("Plane: type %s \ncode %s\n",types[pAirplane->type], pAirplane->code);
}

int checkCorrectCode(char* string)
{   
	if (strlen(string) == 5 && isUpperCase(string))
		return 1;
	return 0;
}

airplaneType getTypeFromUser()
{
	int i, t;
	printf("Enter airplane type:\n");
	do {
		for (i = 0; i < eNofTypes; i++)
			printf("Enter %d for %s\n", i, types[i]);
		scanf("%d", &t);
	} while (t < 0 || t >= eNofTypes);
	return (airplaneType)t;
}