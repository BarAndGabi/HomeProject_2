#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utill.h"
#include "AirportManager.h"
#include "AirLine.h"
void printOptions()
{
	printf("intro");
	printf("option 1 - add Flight to AirLine.\n");
	printf("option 2 - add Airport to airportManage.\n");
	printf("option 3 - print AirLine properties.\n");
	printf("option 1 - add flight to airLine.\n");
	printf("option 1 - add flight to airLine.\n");
	printf("option 1 - add flight to airLine.\n");
	printf("option 1 - add flight to airLine.\n");
	printf("option 1 - add flight to airLine.\n");


}
int menu(int* pC)
{
	printOptions();
	scanf("%d", pC);
	if (*(pC) < 1 || *(pC) > 8)
	{
		printf("try again\n");
		*pC = 0;
		return 0;
	}
	return 1;
}
int choosenInit(int choosen)
{
	switch (choosen)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	case 8:
		printf("exiting program.......\n");
		break;
	default:
		return 0;
	}
	return 1;
}
void main()
{
	AirportManager m1;
	AirLine l1;
	int choise = 0;
	if (!initAirportManager(&m1))
		printf("Error\n");
	if (!initAirLine(&l1))
		printf("Error\n");
	while (choise == 0)
	{
		menu(&choise);
		choosenInit(choise);
		if (choise != 8)
			choise = 0;
	}
	system("pause");
}
