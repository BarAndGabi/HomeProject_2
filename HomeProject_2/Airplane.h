#pragma once
#include <string.h>
#include <stdio.h>
#include "Utill.h"
# define CODE 5
typedef enum { ePassangers, eCargo, eMilitary, eNofTypes } airplaneType;
const char* types[eNofTypes];

typedef struct
{
	airplaneType type;
	char code[CODE];
} Airplane;

void initAirplane(Airplane* airplane);
void printAirplane(Airplane* airplane);
int checkCorrectCode(char* string);
airplaneType getTypeFromUser();


