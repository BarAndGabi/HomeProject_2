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
int compareAddress(const Address *pA1, const Address *pA2);
void checkWordLen(char *word, int length, int bool);
char *addDiezBetween(char *inputStr);
void checkAtrribute(Address *pA, char* fullAddress, char* addToStr);
char *evenOrBiggerThan2(char *str);
char *addressBuffer(Address *pA);
