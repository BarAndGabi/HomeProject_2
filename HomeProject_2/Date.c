#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include "Utill.h"

int freeDate(Date *pD)
{
	free(&pD);
	return 1;
}

int checkValidDate(Date *pD)
{

	if (pD->year < 2022)
		return 0;
	switch (pD->month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (pD->day > 31 || pD->day < 1)
		{
			printf("INVALID DATE: day out of range\n");
			return 0;
		}
		break;
	case 2:
		if (pD->day > 28 || pD->day < 1)
		{
			printf("INVALID DATE: day out of range\n");
			return 0;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (pD->day > 30 || pD->day < 1)
		{
			printf("INVALID DATE: day out of range\n");
			return 0;
		}
		break;
	default:
		printf("INVALID DATE: month out of range\n");
		return 0;
	}
	return 1;
}

int printDate(Date *pD)
{
	int day = pD->day;
	int month = pD->month;
	if (month < 10 && day < 10)
		printf("0%d/0%d/%d", day, month, pD->year);
	if (month < 10)
	{
		printf("%d/0%d/%d", day, month, pD->year);
	}
	if (day < 10)
		printf("0%d/%d/%d", day, month, pD->year);

	printf("%d/%d/%d", pD->day, pD->month, pD->year);
	return 1;
}

int checkDateFormat(char *d)
{
	if (*(d + 12))
		return 0;
	int currentPlaceChecker = 0;
	while (*(d + currentPlaceChecker))
	{
		if (currentPlaceChecker == 2 || currentPlaceChecker == 3 || currentPlaceChecker == 6 || currentPlaceChecker == 7)
		{
			if (*(d + currentPlaceChecker) != '$')
				return 0;
		}
		if(currentPlaceChecker == 1 || currentPlaceChecker == 5)
		{
			if (isdigit(*(d + currentPlaceChecker)) == 0)
				return 0;
		}

		currentPlaceChecker++;
	}
	return 1;
}
int initDate(Date *pD)
{
	char *date;
	char *dayChar;
	char *monthChar;
	char *yearChar;
	char *doubleDollars = "$$";
	int check;
	do
	{
		date = createDynStr("Please enter the date (dd$$mm$$yyyy). Minimum year: 2022\n");
		if (!(checkDateFormat(date)))
			check = 0;
		else
			check = 1;
		dayChar = strtok(date, doubleDollars);
		monthChar = strtok(NULL, doubleDollars);
		yearChar = strtok(NULL, doubleDollars);
		pD->day = atoi(dayChar);
		pD->month = atoi(monthChar);
		pD->year = atoi(yearChar);
	} while (checkValidDate(pD) == 0 || !(check));
	return 1;
}

