#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
typedef short int WORD;
typedef unsigned int DWORD;

struct ZIPHeader {
	DWORD sign;
	WORD version;
	WORD flag;
	WORD comp;
	WORD lastTime;
	WORD lastDate;
	DWORD crc;
	DWORD sizec;
	DWORD sized;
	WORD lenName;
	WORD lenEf;
	std::string fName;
	std::string ef;
};

struct Command {
	int x, y;
	unsigned short int doing;
};

void readZIPHeader(std::string fileName, ZIPHeader& header);
void displayZIPHeader(ZIPHeader& header);
void writeFunctionToFile(std::string inFileName, std::string outFileName);
float chFunction(float x, unsigned int ch);
void randomFillFileOfCommands(std::string outFileName);
int max(int a, int b);
void displayCommands(std::string inFileName);
