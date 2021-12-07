#pragma once
# define CODE 5
typedef enum { ePassangers, eCargo, eMilitary, eNofTypes } airplaneType;
const char* types[eNofTypes];

typedef struct
{
	airplaneType type;
	char code[CODE];
} Airplane;

