#define _CRT_SECURE_NO_WARNINGS

#include "Date.h"
#include "Utill.h"

int freeDate(Date *pD)
{
	free(&pD);
	return 1;
}

int checkValidDate(char* day,char* month,char* year)
{
	int intDay, intMonth, intYear;
	intDay = atoi(day);
	intMonth = atoi(month);
	intYear = atoi(year);
	if (intYear < 2022)
		return 0;
	switch (intMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		if (intDay > 31 || intDay < 1)
		{
			printf("INVALID DATE: day out of range\n");
			return 0;
		}
		break;
	case 2:
		if (intDay > 28 || intDay < 1)
		{
			printf("INVALID DATE: day out of range\n");
			return 0;
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		if (intDay > 30 || intDay < 1)
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

int checkDateFormat(char* date)
{
	size_t lenth = strlen(date);
	if (lenth!=13)
		return 0;
	int count = 0;
	while (count<12)
	{
		if (count == 2 || count == 3 || count == 6 || count == 7)
		{
			if (*(date + count) != '$')
				return 0;
		}
		else
		{
			if (isdigit(*(date + count)) == 0)
				return 0;
		}

		count++;
	}
	return 1;
}
int initDate(Date* pD)
{
	char* date=NULL;
	char* day=NULL;
	char* month=NULL;
	char* year=NULL;
	char* delimiters = "$$";
	int temp;
	do
	{
		date = createDynStr("Please enter the date (dd$$mm$$yyyy). Minimal year: 2022");
		if (!checkDateFormat(date))
		{
			temp = 0;
		}
		else
		{
			
			day = strtok(date, delimiters);
			month = strtok(NULL, delimiters);
			year = strtok(NULL, delimiters);
			temp = checkValidDate(day, month, year);
		}
		
	} while ( !(temp));
	pD->day = atoi(day);
	pD->month = atoi(month);
	pD->year =atoi( year);
	return 1;
}
