#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
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
	int length = strlen(str);
	for (int i = 0; i < length; i++)
		if (isupper(str[i]) != 1)
			return 0;
	return 1;
}
