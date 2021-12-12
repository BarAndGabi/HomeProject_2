#pragma once
typedef struct
{
	char* country;
	char* city;
	char* street;
	char* houseNumber; 
} Address;

int initAddress(Address *pA);
void printAddress(const char *address);
void freeAddress(Address *pA);
void checkWordLen(char *word, int length, int bool);
char *addDiezBetween(char *inputStr);
char *evenOrBiggerThan2(char *str);
char *addressBuffer(Address *pA);

