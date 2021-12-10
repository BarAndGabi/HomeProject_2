#define _CRT_SECURE_NO_WARNINGS
#include "Airplane.h"
void initAirplane(Airplane *pAirplane)
{
	pAirplane->type = getTypeFromUser();
	printf("Enter the code: ");
	char* string=NULL;
	scanf("%s", string);
	while (!checkCorrectCode(string))
	{
		printf("Error,please enter code again");
		scanf("%s", string);
	}
	strcpy(pAirplane->code, string);
}

void printAirplane(Airplane * pAirplane)
{
	printf("Plane:%s,%s",types[pAirplane->type], pAirplane->code);
}

int checkCorrectCode(char* string)
{
	if(strlen(string)<0||strlen(string)>4)
	return 0;
	
	if (isUpperCase(string))
		return 1;
	
	return 0;
}

airplaneType getTypeFromUser()
{
	int i, t;
	printf("Enter airplane type\n");
	do {
		for (i = 0; i < eNofTypes; i++)
			printf("Enter %d for %s\n", i, types[i]);
		scanf("%d", &t);
	} while (t < 0 || t >= eNofTypes);
	return (airplaneType)t;
}