#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Address.h"
#include "Utill.h"
int initAddress(Address *pA)
{ 
	pA->country = createDynStr("country name");
	pA->city = createDynStr("city name");
	pA->street = createDynStr("street name");
	printf("enter house number : ");
	scanf("%d", &pA->houseNumber);
	printf("\n");
	return 1;
}
char *addDiezBetween(char *inputStr)
{
	char *editedStr = NULL;
	char *words;
	char *space = " ";
	size_t stringSize = 0;
	size_t lenth;
	words = strtok(inputStr, space);
	while (words != NULL)
	{
		lenth = strlen(words);
		if (editedStr == NULL)
		{
			editedStr = (char *)malloc((lenth + 1) * sizeof(char));
			strcpy(editedStr, words);
			stringSize += lenth;
		}
		else
		{
			stringSize += (lenth + 2);
			editedStr = (char *)realloc(editedStr, stringSize * sizeof(char));
			strcat(editedStr, "#");
			strcat(editedStr, words);
		}
		words = strtok(NULL, space);
	}

	return evenOrBiggerThan2(editedStr);
}
void checkAtrribute(Address *pA, char* fullAddress, char* addToStr)
{
	fullAddress = (char *)realloc(fullAddress, (strlen(addToStr) + 2) * sizeof(char));
	strcpy(fullAddress, addToStr);
	strcat(fullAddress, "@");
}
char *evenOrBiggerThan2(char *str)
{
	int counter = 0;
	int current = 0;
	int isLastWord = 0;
	if (strstr(str, "#") != NULL)
	{
		while (*str)
		{
			while (*str != '#' && *str != '\0')
			{
				str++;
				current++;
				counter++;
			}
			if (*str == '\0')
				isLastWord = 1;
			checkWordLen((str - counter), counter, isLastWord);
			if (isLastWord)
				return str - current;
			str++;
			current++;

			counter = 0;
		}
	}
	else
		*str = tolower(*str);

	return str - current;
}

void checkWordLen(char *word, int length, int bool)
{
	if (length % 2 == 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (i % 2 == 0)
				*(word + i) = toupper(*(word + i));
			else
				*(word + i) = tolower(*(word + i));
		}
	}
	else
	{
		if (bool == 0)
			*(word) = toupper(*(word));
		else
			*(word) = tolower(*(word));
	}
}
char *addressBuffer(Address *pA)
{
	char *fullAddress = NULL;
	char *addToStr;
	addToStr = addDiezBetween(pA->country);
	checkAtrribute(pA, fullAddress, addToStr);
	addToStr = addDiezBetween(pA->city);
	checkAtrribute(pA, fullAddress, addToStr);
	addToStr = addDiezBetween(pA->street);
	checkAtrribute(pA, fullAddress, addToStr);
	sprintf(addToStr, "%d", pA->houseNumber);
	checkAtrribute(pA, fullAddress, addToStr);
	return fullAddress;
}
void printAddress(const char *address)
{
	printf("%s\n", address);
}

void freeAddress(Address *pA)
{
	free(pA->city);
	free(pA->country);
	free(pA->street);
}

int compareAddress(const Address * pA1, const Address * pA2)
{
	int check[] = {1,1,1};
	if (pA1->houseNumber != pA2->houseNumber)
		return 0;
	check[0] = strcmp(pA1->city,pA2->city);
	check[1] = strcmp(pA1->country, pA2->country);
	check[2] = strcmp(pA1->street, pA2->street);
	for (size_t i = 0; i < 3; i++)
	{
		if (check[i] != 0)
			return 0;
	}
	return 1;
}

