#ifndef ADDRESS
#define ADDRESS
typedef struct
{
	char* country;
	char* city;
	char* street;
	int houseNumber; 
} Address;

int initAddress(Address *pA);
void printAddress(Address *pA);
void freeAddress(Address *pA);
int compareAddress(const Address *pA1, const Address *pA2);
#endif // !ADDRESS
