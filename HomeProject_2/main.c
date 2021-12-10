#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utill.h"
#include "AirportManager.h"
#include "AirLine.h"

void printOptions()
{
	printf("intro\n");
	printf("option 1 - add Flight to AirLine.\n");
	printf("option 2 - add Airport to airportManage.\n");
	printf("option 3 - print AirLine properties.\n");
	printf("option 4 - printAirportManager.\n");
	printf("option 5 - printNumOfFilghtsFromAirport.\n");
	printf("option 6 - printFilghtsWithAirplaneCode.\n");
	printf("option 7 - printFilghtsWithAirplaneKind.\n");
	printf("option 8 - exit program.\n");
}

int printFilghtsWithAirplaneKind(AirportManager *m)
{

	return 0;
}
//case 2;
int printNumOfFlightsFromAirport(AirLine* l)
{
	return 0;
}
//case 3;
int printFilghtsWithAirplaneCode(AirportManager *m)
{
	
}
//case 4;
int addFlightToAirLine(AirLine *l)
{
	if(!addFlight)
	return 0;

	return 1;
}
//case 5;
int addAirportToAirportManager(AirportManager *m)
{
	if (!addAirport(m))
		return 0;

	return 1;
}

int menu(int *pC)
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

int choosenInit(int choosen, AirportManager *m, AirLine *l)
{
	switch (choosen)
	{
	case 1:
		if (!addFlightToAirLine(l))
			printf("error in case 1\n");
		break;
	case 2:
		if (!addAirportToAirportManager(m))
			printf("error in case 2\n");
		break;
	case 3:
		printAirLine(l);
		break;
	case 4:
		printAirportManager(m);
		break;
	case 5:
		if (!printNumOfFlightsFromAirport(l))
			printf("error in case 5\n");
		break;
	case 6:
		if (!printFilghtsWithAirplaneCode(m))
			printf("error in case 6\n");
		break;
	case 7:
		if (!printFilghtsWithAirplaneKind(m))
			printf("error in case 7\n");
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
	while (choise == 0)
	{
		if (menu(&choise))
		{
			if (choise != 8)
			{
				choosenInit(choise, &m1, &l1);
				choise = 0;
			}
			else
				printf("\nthank you \n bye. \n ");
		}

	}
	system("pause");
}
