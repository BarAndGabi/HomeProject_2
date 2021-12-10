#include "Date.h"

int initDate(Date * pD,int Day,int Month,int Year)
{
	pD->day = Day;
	pD->month = Month;
	pD->year = Year;
}

void printDate(Date * pD)
{
	int day = pD->day;
	int month = pD->month;
	if (month < 10 && day < 10)
		printf("0%d/0%d/%d", day, month, pD->year);
	if (month<10)
	{
		printf("%d/0%d/%d", day, month, pD->year);
	}
	if (day < 10)
		printf("0%d/%d/%d", day, month, pD->year);

	printf("%d/%d/%d", pD->day, pD->month, pD->year);
	
}

