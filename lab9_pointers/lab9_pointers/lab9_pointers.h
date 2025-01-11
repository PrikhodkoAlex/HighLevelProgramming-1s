#include <iostream>
#include <array>
#include <string>
#include <ctime>


struct RGB {
	unsigned short int r, g, b;
};
struct Fruit {
	std::string name;
	unsigned short int weight;
	RGB color;
	bool isEatable;
};
void sumRaznWithPointers(bool doSwap);
void swap(short* x, short* y);
void randomFillArray(short* ar, unsigned int length, short minEl, short maxEl);
void showArray(short* arr, unsigned int length);
void announceAndShowDynamicArray();
void randomFruit(Fruit* fr);
void randomFillArrayOfFruit(Fruit* ar, unsigned int length);
void showArrayOfFruit(Fruit* arr, unsigned int length);
void replaceFruitInArrayByUser(Fruit* ar, unsigned int length);
void declarateShowAndReplaceArrayOfFruit();

