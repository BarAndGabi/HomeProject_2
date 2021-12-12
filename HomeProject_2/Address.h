#pragma once
typedef struct
{
	char* country;
	char* city;
	char* street;
	int houseNumber; 
} Address;

int initAddress(Address *pA);
void printAddress(const char *address);
void freeAddress(Address *pA);
void checkWordLen(char *word, int length, int bool);
char *addDiezBetween(char *inputStr);
char* checkAtrribute(Address *pA, char* fullAddress, char* addToStr);
char *evenOrBiggerThan2(char *str);
char *addressBuffer(Address *pA);
