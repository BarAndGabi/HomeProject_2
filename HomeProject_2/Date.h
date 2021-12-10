#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int day;
	int month;
	int year;
} Date;

int checkValidDate(Date *pD);
int initDate(Date * pD);
int printDate(Date *pD);
int freeDate(Date *pD);
int checkDateFormat(char *d);

