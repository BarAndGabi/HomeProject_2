#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Utill.h"
#include "AirportManager.h"
#include "AirLine.h"

int menu(int* pC)
{
	printf("here wil be the menu :  \n1\n2\n3\n4\n5\n6\n7\n8\n");
	scanf("%d",pC);
	if (*(pC) < 1 || *(pC) > 8)
	{
		printf("try again\n");
		*pC = 0;
		return 0;
	}
	return 1;
}

void main()
{
	AirportManager m1;
	AirLine l1;
	int choise=0;
	if (!initAirportManager(&m1))
		printf("Error\n");
	if (!initAirLine(&l1))
		printf("Error\n");
	while (choise == 0)
	{
		menu( &choise);
	}
	system("pause");
}
