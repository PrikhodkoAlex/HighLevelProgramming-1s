#include "lab9_pointers.h"

int main() {
	short int choice;
	srand(time(NULL));
	do {
		std::cout << "Enter number of task << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			sumRaznWithPointers(false);
			break;
		case 2:
			sumRaznWithPointers(true);
			break;
		case 3:
			announceAndShowDynamicArray();
			break;
		case 4:
			declarateShowAndReplaceArrayOfFruit();
			break;
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}

void sumRaznWithPointers(bool doSwap) {
	//1. Объявить указатели на две переменные указанного типа. Используя указатели 
	//произвести операции сложения и вычитания над переменными.Вывести адреса
	//указателей.Типы переменных указаны в таблице.
	//12 short
	short a, b;
	short* x = &a;
	short* y = &b;
	std::cout << "Enter a, b << ";
	std::cin >> *x >> *y;
	short summa, raznost;
	summa = (*x) + (*y);
	raznost = (*x) - (*y);
	std::cout << "Address of x: " << &x << "." << "\tx = " << x  << ".\t (*x) = " << *x << std::endl;
	std::cout << "Address of y: " << &y << "." << "\ty = " << y << ".\t (*y) = "<< *y << std::endl;
	std::cout << "Address of a: " << &a << ".\t a = " << a << std::endl;
	std::cout << "Address of b: " << &b << ".\t b = " << b << std::endl;
	std::cout << "a + b = " << summa << std::endl;
	std::cout << "a - b = " << raznost << std::endl;
	if (doSwap) {
		//2. Написать функцию для обмена значений переменных, указанных выше. Передача по 
		//указателю.Выполнить программу по шагам и выписать в тетрадь адреса указателей
		//и величины переменных.
		std::cout << "Call swap(&a, &b);" << std::endl;
		swap(&a, &b);
		std::cout << "Address of a: " << &a << ".\t a = " << a << std::endl;
		std::cout << "Address of b: " << &b << ".\t b = " << b << std::endl;
	}
	return;
}

void swap(short* x, short* y) {
	short temp = *x;
	*x = *y;
	*y = temp;
	return;
}

void randomFillArray(short* ar, unsigned int length, short minEl, short maxEl) {
	for (unsigned int i = 0; i < length; i++)
		ar[i] = (rand() % (maxEl - minEl + 1)) + minEl;
	return;
}

void showArray(short* arr, unsigned int length) {
	for (unsigned int i = 0; i < length; i++)
		std::cout << "arr[" << i << "] address: " << &arr[i] << "\tValue: " << arr[i] << std::endl;
}

void announceAndShowDynamicArray() {
	//3. Объявить динамический массив. Размер массива задаёт пользователь. Заполнить 
	//массив случайными числами.Вывести на экран адреса и значения элементов
	//массива.
	unsigned int n;
	std::cout << "Enter count of elements << ";
	std::cin >> n;
	short* arr = new short[n];
	short minEl, maxEl;
	std::cout << "Enter min and max elements (minEl maxEl) << ";
	std::cin >> minEl >> maxEl;
	randomFillArray(arr, n, minEl, maxEl);
	showArray(arr, n);

	delete[] arr;
	return;
}

void randomFruit(Fruit* fr) {
	std::array<std::string, 6> names = { "apple", "banana", "ananas", "apricot", "plum", "avocado"};
	fr->name = names[rand() % 6];
	fr->weight = rand() % 501;
	fr->color.r = rand() % 256;
	fr->color.g = rand() % 256;
	fr->color.b = rand() % 256;
	fr->isEatable = rand() % 2;
	return;
}

void randomFillArrayOfFruit(Fruit* ar, unsigned int length) {
	for (unsigned int i = 0; i < length; i++)
		randomFruit(&ar[i]);
	return;
}

void showArrayOfFruit(Fruit* arr, unsigned int length) {
	std::cout << "n\tname\tweight\tcolor\t\tisEateble" << std::endl;
	for (int i = 0; i < length;i++){
		std::cout << i << ")\t" << arr[i].name << "\t" << arr[i].weight << "\t(" <<
			(unsigned int)arr[i].color.r << ", " << (unsigned int)arr[i].color.g << ", " << (unsigned int)arr[i].color.b << ")\t"
			<< arr[i].isEatable << std::endl;
	}
	return;
}

void replaceFruitInArrayByUser(Fruit* ar, unsigned int length) {
	unsigned int number;
	std::string atribute;
	std::cout << "Enter a number of fruit in array to replace (0 - "  << length - 1 << ") << ";
	std::cin >> number;
	while (number >= length) {
		std::cout << "It isn't matching number. Enter ather (0 - " << length - 1 << ") << ";
		std::cin >> number;
	}
	std::cout << "Enter a atribute to replace (name, weight, color, isEatable) << ";
	std::cin >> atribute;
	bool wasReplace = false;
	while (!wasReplace) {
		if (atribute == "name") {
			std::cout << "arr[" << number << "].name = " << ar[number].name << std::endl << "Enter new name(string) << ";
			std::cin >> ar[number].name;
			wasReplace = true;
		}
		else if (atribute == "weight") {
			std::cout << "arr[" << number << "].weight = " << ar[number].weight << std::endl << "Enter new weight(unsigned short int) << ";
			std::cin >> ar[number].weight;
			wasReplace = true;
		}
		else if (atribute == "color") {
			std::cout << "arr[" << number << "].color.r = " << (unsigned int)ar[number].color.r << std::endl;
			std::cout << "arr[" << number << "].color.g = " << (unsigned int)ar[number].color.g << std::endl;
			std::cout << "arr[" << number << "].color.b = " << (unsigned int)ar[number].color.b << std::endl;
			std::cout << "Enter new color (r, g, b) << ";
			std::cin >> ar[number].color.r >> ar[number].color.g >> ar[number].color.b;
			while ((ar[number].color.r > 255) || (ar[number].color.g > 255) || (ar[number].color.b > 255)) {
				std::cout << "It isn't matching color. Use numbers r, g, b in [0; 255]. Enter ather color(r, g, b) << ";
				std::cin >> ar[number].color.r >> ar[number].color.g >> ar[number].color.b;
			}
			wasReplace = true;
		}
		else if (atribute == "isEatable") {
			std::cout << "arr[" << number << "].isEatable = " << ar[number].isEatable << std::endl << "Enter new atribute (0, 1) << ";
			std::cin >> ar[number].isEatable;
			wasReplace = true;
		}
		else {
			std::cout << "It isn't matching atribute. Enter ather atribute (name, weight, color, isEatable) << ";
			std::cin >> atribute;
		}
	}
	showArrayOfFruit(ar, length);
	return;
}

void declarateShowAndReplaceArrayOfFruit() {
	//4. Объявить сущность и описать её свойства. Объявить динамический массив 
	//сущностей.Реализовать функцию, которая изменяет значения элемента(структура)
	//массива.Заполнить атрибуты числовыми и текстовыми значениями(диапазон
	//значений определить самостоятельно).
	//d.фрукт
	unsigned int n;
	std::cout << "Enter count of fruit in array << ";
	std::cin >> n;
	Fruit* arr = new Fruit[n];
	randomFillArrayOfFruit(arr, n);
	showArrayOfFruit(arr, n);
	bool doReplace;
	do {
		std::cout << "Do you want to  replace atributes (0 / 1) << ";
		std::cin >> doReplace;
		if (doReplace)
			replaceFruitInArrayByUser(arr, n);
	} while (doReplace);
	delete[] arr;
	return;
}

