#pragma once
#include <stdio.h>
typedef struct
{
	int day;
	int month;
	int year;
} Date;

int initDate(Date * pD, int Day, int Month, int Year);
void printDate(Date *pD);
