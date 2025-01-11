#include <iostream>
//#include <locale.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <array>
#include <ctime>

void writeToFile(std::string fileName);
void getTextFromFileToString(std::string fileName, std::string& str);
void replaceTrueToFalse(std::string& str);
int count6LetteryWords(const std::string& str);
bool isNumber(char ch);
int countNumberCharsInString(const std::string& str);
void replaceNumberCharsToWords(std::string& str);
void getProgramFromFileToString(const std::string& inFileName, std::string& str);
bool isBracketsCorrect(const std::string& str);
void checkBracketsInFile(const std::string& inFileName, const std::string& outFileName);