#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Utill.h"

char *createDynStr(const char *msg)
{
	char *str;
	char temp[255];
	printf("Enter %s: ", msg);
	fgets(temp,255,stdin);
	while (strcmp(temp, "") == 0) {
		printf("You didn't enter anything enter again: ");
		fgets(temp, 255, stdin);
	}
	str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);
	return str;
}

int isUpperCase(const char* str)
{
	size_t length = strlen(str);
	for (size_t i = 0; i < length-1; i++)
		if (isupper(str[i]) != 1)
			return 0;
	return 1;
}

void clearInputBuffer(void) {
	int c;
	do {
		c = getchar();
	} while (c != '\n');
}

void removeChar(char * str, char charToRemmove)
{
	int i, j;
	size_t len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == charToRemmove)
		{
			for (j = i; j < len; j++)
			{
				str[j] = str[j + 1];
			}
			len--;
			i--;
		}
	}

}
void printLine()
{
	printf("\n");
}