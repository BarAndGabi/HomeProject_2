#pragma once
#include <stdio.h>
typedef struct
{
	int day;
	int month;
	int year;
} Date;

int initDate(Date *pD);
void printDate(Date *pD);
void freeDate(Date *pD);
int checkValidDate(Date *pD);