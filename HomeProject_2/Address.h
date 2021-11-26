#ifndef ADDRESS
<<<<<<< HEAD
#define ADDRESS
=======
>>>>>>> 37b12f9e9be59bac26db9605ee684c097c75035a
typedef struct {
	char* country;
	char* city;
	char* street;
	int houseNumber;
}Address;

int initAddress(Address* pA);
void printAddress(Address* pA);
void freeAddress(Address* pA);
<<<<<<< HEAD
char*	createDynStr(const char* msg);
=======
>>>>>>> 37b12f9e9be59bac26db9605ee684c097c75035a
#endif // !ADDRESS
