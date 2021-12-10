#include "Date.h"
#include "Utill.h"

int initDate(Date *pD)
{
	char *date;
	char *day;
	char *month;
	char *year;
	char *delimiters = "$$";
	int temp;
	do
	{
		date = createDynStr("Please enter the date (dd$$mm$$yyyy). Minimum year: 2022\n");
		if (!(strstr(date, delimiters)))
			temp = 0;
		else
			temp = 1;
		day = strtok(date, delimiters);
		month = strtok(NULL, delimiters);
		year = strtok(NULL, delimiters);
		pD->day = atoi(day);
		pD->month = atoi(month);
		pD->year = atoi(year);
	} while (checkValidDate(pD) == 0 || !(temp));

	return 1;
}
void freeDate(Date *pD)
{
	free(pD->day);
	free(pD->month);
	free(pD->year);
	free(pD);
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

void printDate(Date *pD)
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
}
