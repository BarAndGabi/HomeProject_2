#ifndef _DATE
#define _DATE
typedef struct
{
	int day;
	int month;
	int year;
} Date;

int initDate(Date *pD);
void printDate(Date *pD);

#endif // !_DATE
