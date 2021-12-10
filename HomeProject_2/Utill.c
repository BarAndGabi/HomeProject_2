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
	scanf("%s", temp);
	str = (char *)malloc((strlen(temp) + 1) * sizeof(char));
	if (!str)
		return NULL;
	strcpy(str, temp);

	return str;
}

int isUpperCase(const char* str)
{
	size_t length = strlen(str);
	for (size_t i = 0; i < length; i++)
		if (isupper(str[i]) != 1)
			return 0;
	return 1;
}
