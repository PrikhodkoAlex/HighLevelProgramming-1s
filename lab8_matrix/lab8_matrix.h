#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <ctime>

#define robotStateCount 8
struct RobotState {
	int x;
	int y;
	int power;
	int speed;
};


void randomFillMatrix(int* addr, int n, int m, int minElem, int maxElem);
void printMatrix(int* addr, int n, int m);

void task1();
int getSumOfNegativeElementsOnMainDiagonal(int* addr, int n);
void swap(int* a, int* b);
void task2SwapElementes();
void task3();
int min(int a, int b);
int max(int a, int b);
void fillFileToRobot(std::string fileName);
void ReadFileToRobot(std::string fileName);
void task5();
void fillMaxElements(int* mat, int n, int m, int* arr);
int L1norm(int* matrix, int n, int m);
int LInfinityNorm(int* matrix, int n, int m);
int maxAbsElemNorm(int* matrix, int n, int m);
int trackMatrix(int* matrix, int n, int m);
int sumAllElements(int* matrix, int n, int m);
int sumAllSquareOfElements(int* matrix, int n, int m);

void randomFillMatrix2(std::vector<std::vector<int>*>& address, int n, int m, int minElem, int maxElem);
void printMatrix2(std::vector<std::vector<int>*>& address, int n, int m);
void task6proizvedenie();
void proizvedenieOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m, int l);
void task6summa(bool isPlus);
void sumOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m);
void differenceOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m);
void transposeMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixC, int n, int m);
void task6transpose();
void task7fillSkinFile(std::string fileName, int n, int m);
void task7readSkinFile(std::string fileName);

