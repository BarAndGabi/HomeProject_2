#ifndef ADDRESS
typedef struct {
	char* country;
	char* city;
	char* street;
	int houseNumber;
}Address;

int initAddress(Address* pA);
void printAddress(Address* pA);
void freeAddress(Address* pA);
#endif // !ADDRESS
