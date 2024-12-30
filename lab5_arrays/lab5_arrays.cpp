#include <iostream>
#include <array>
#include <ctime>
#include <string>
#define l 20
#define N 50


void fillRandomArray(std::array<int, l>& numbers, int minN, int maxN);
void fillRandomFloatArray(std::array<float, l>& nembers, int minN, int maxN);
void displayFloatArray(std::array<float, l>& floatNumbers);
void fillAndDisplayRandomArray(std::array<int, l>& numbers);
void sums3(std::array<int, l>& numbers);
unsigned int findIndexMinAbsEl(std::array<int, l>& numbers);
unsigned int findIndexMaxAbsEl(std::array<int, l>& numbers);
void findMinEl(std::array<int, l>& numbers, int& minElement, unsigned int& index);
void findMaxEl(std::array<int, l>& numbers, int& maxElement, unsigned int& index);
void negativePlus5PositiveMinus1(std::array<int, l>& numbers);
std::array<float, l> delenie(std::array<float, l>& numerator, std::array<float, l>& denominator);
void fillInformationAboutCity(std::array<std::string, N>& surnames, std::array<unsigned int, N>& ages, std::array<char, N>& pol);
void readInformationAboutCity(std::array<std::string, N>& surnames, std::array<unsigned int, N>& ages, std::array<char, N>& pol);

int main() {
	srand(time(NULL));
	std::array<int, l> numbers;
	std::array<float, l> floatNumbersNumerator;
	std::array<float, l> floatNumbersDenominator;
	std::array<float, l> floatNumbersAnsver;
	std::array<unsigned int, N> ages;
	std::array<std::string, N> surnames;
	std::array<char, N> pol;
	int element;
	unsigned int index;
	unsigned int countOfMen = 0;
	unsigned int countOfWomen = 0;
	unsigned int sumAgeOfMen = 0;
	unsigned int sumAgeOfWomen = 0;
	bool readFlag;
	fillRandomArray(numbers, -10, 20);
	fillRandomFloatArray(floatNumbersNumerator, -10, 20);
	fillRandomFloatArray(floatNumbersDenominator, -10, 20);


	unsigned short int choice;
	do {
		std::cout << "Enter number << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			fillAndDisplayRandomArray(numbers);
			break;
		case 2:
			sums3(numbers);
			break;
		case 3:
			std::cout << "Index of min abs element: " << findIndexMinAbsEl(numbers) << std::endl;
			std::cout << "Index of max abs element: " << findIndexMaxAbsEl(numbers) << std::endl;

			break;
		case 4:
			findMinEl(numbers, element, index);
			std::cout << "Min element:  numbers[" << index << "]= " << element << std::endl;
			findMaxEl(numbers, element, index);
			std::cout << "Max element:  numbers[" << index << "]= " << element << std::endl;
			break;
		case 5:
			std::cout << "Before function call: {";
			for (int i = 0; i < l; i++)
				std::cout << numbers[i] << ", ";
			std::cout << "}" << std::endl;
			negativePlus5PositiveMinus1(numbers);
			std::cout << "After function call: {";
			for (int i = 0; i < l; i++)
				std::cout << numbers[i] << ", ";
			std::cout << "}" << std::endl;
			break;
		case 6:
			fillRandomFloatArray(floatNumbersNumerator, -10, 20);
			fillRandomFloatArray(floatNumbersDenominator, 1, 20);
			std::cout << "A = ";
			displayFloatArray(floatNumbersNumerator);
			std::cout << "B = ";
			displayFloatArray(floatNumbersDenominator);
			floatNumbersAnsver = delenie(floatNumbersNumerator, floatNumbersDenominator);
			std::cout << " A / B = ";
			displayFloatArray(floatNumbersAnsver);
			break;
		case 7:
			countOfMen = 0;
			countOfWomen = 0;
			sumAgeOfMen = 0;
			sumAgeOfWomen = 0;
			std::cout << "Do you want to type information about people? (1/0)" << std::endl;
			std::cin >> readFlag;
			if (readFlag)
				readInformationAboutCity(surnames, ages, pol);
			else
				fillInformationAboutCity(surnames, ages, pol);
			for (int i = 0; i < N; i++)
				std::cout << surnames[i] << "\t\t" << ages[i] << "\t\t" << pol[i] << std::endl;
			std::cout << std::endl;
			for (int i = 0; i < N;i++) {
				if (pol[i] == 'M') {
					countOfMen++;
					sumAgeOfMen = sumAgeOfMen + ages[i];
				}
				else {
					countOfWomen++;
					sumAgeOfWomen = sumAgeOfWomen + ages[i];
				}
			}
			std::cout << "Middle age of men is " << sumAgeOfMen / countOfMen << "\t" << "Count of men is " << countOfMen << std::endl;
			std::cout << "Middle age of women is " << sumAgeOfWomen / countOfWomen << "\t" << "Count of women is " << countOfWomen << std::endl;
			std::cout << "Middle age of men ";
			if ((sumAgeOfWomen / countOfWomen) > (sumAgeOfMen / countOfMen))
				std::cout << "less then ";
			else if ((sumAgeOfWomen / countOfWomen) < (sumAgeOfMen / countOfMen))
				std::cout << "more then ";
			else
				std::cout << "equal ";
			std::cout << "middle age of women" << std::endl;
			std::cout << "Middle age of all people is " << (sumAgeOfWomen + sumAgeOfMen) / N << std::endl;
			std::cout << "These are people whose age less than common middle age:" << std::endl;
			for (int i = 0; i < N; i++) {
				if (ages[i] < (sumAgeOfMen + sumAgeOfWomen) / N)
					std::cout << surnames[i] << "\t\t" << ages[i] << "\t\t" << pol[i] << std::endl;
			}
			std::cout << "These are people whose age more than common middle age:" << std::endl;
			for (int i = 0; i < N; i++) {
				if (ages[i] > (sumAgeOfMen + sumAgeOfWomen) / N)
					std::cout << surnames[i] << "\t\t" << ages[i] << "\t\t" << pol[i] << std::endl;
			}
			break;
		default:

			break;
		}
	} while (choice != 0);

	return 0;
}




void fillRandomArray(std::array<int, l>& numbers, int minN, int maxN) {
	for (int i = 0; i < l; i++)
		numbers[i] = (rand() % (maxN - minN + 1)) + minN;
	return;

}
void fillAndDisplayRandomArray(std::array<int, l>& numbers) {
	//1. Сгенерировать массив со случайными числами в диапазоне:
	//d. [-10,20]
	fillRandomArray(numbers, -10, 20);
	std::cout << "{ ";
	for (int i = 0; i < l; i++)
		std::cout << numbers[i] << ", ";
	std::cout << "}" << std::endl;
	return;
}


void sums3(std::array<int, l>& numbers) {
	//2. Вычислить сумму элементов массива:
	//a. больших 5, меньших 7, больших 3,

	int sumMore5 = 0;
	int sumLess7 = 0;
	int sumMore3 = 0;
	for (int i = 0;i < l; i++) {
		if (numbers[i] > 5)
			sumMore5 += numbers[i];
		if (numbers[i] < 7)
			sumLess7 += numbers[i];
		if (numbers[i] > 3)
			sumMore3 += numbers[i];
	}
	std::cout << "Sum of elements more then 5 equals " << sumMore5 << '.' << std::endl;
	std::cout << "Sum of elements less then 7 equals " << sumLess7 << '.' << std::endl;
	std::cout << "Sum of elements more then 3 equals " << sumMore3 << '.' << std::endl;
	return;

}

unsigned int findIndexMinAbsEl(std::array<int, l>& numbers) {
	//6. Найти номер минимального / максимального по модулю элемента
	unsigned int minimum = abs(numbers[0]);
	unsigned int minI = 0;
	for (int i = 1; i < l; i++)
		if (abs(numbers[i]) < minimum) {
			minimum = abs(numbers[i]);
			minI = i;
		}
	return minI;
}
unsigned int findIndexMaxAbsEl(std::array<int, l>& numbers) {
	//6. Найти номер минимального / максимального по модулю элемента
	unsigned int maximum = abs(numbers[0]);
	unsigned int maxI = 0;
	for (int i = 1; i < l; i++)
		if (abs(numbers[i]) > maximum) {
			maximum = abs(numbers[i]);
			maxI = i;
		}
	return maxI;
}


void findMinEl(std::array<int, l>& numbers, int& minElement, unsigned int& index) {
	//5. Найти наибольший/наименьший элемент массива и его номер по порядку
	minElement = numbers[0];
	index = 0;
	for (int i = 1; i < l; i++)
		if (numbers[i] < minElement) {
			minElement = numbers[i];
			index = i;
		}
	return;

}
void findMaxEl(std::array<int, l>& numbers, int& maxElement, unsigned int& index) {

	//5. Найти наибольший/наименьший элемент массива и его номер по порядку
	maxElement = numbers[0];
	index = 0;
	for (int i = 1; i < l; i++)
		if (numbers[i] > maxElement) {
			maxElement = numbers[i];
			index = i;
		}
	return;
}


void negativePlus5PositiveMinus1(std::array<int, l>& numbers) {
	//13. Увеличить все отрицательные элементы на 5, а положительные уменьшить на 1
	for (int i = 0; i < l; i++) {
		if (numbers[i] < 0)
			numbers[i] += 5;
		else if (numbers[i] > 0)
			numbers[i] -= 1;
	}
	return;
}

void fillRandomFloatArray(std::array<float, l>& numbers, int minN, int maxN) {
	for (int i = 0; i < l; i++)
		numbers[i] = (rand() % (maxN - minN)) + minN + ((float)rand() / RAND_MAX);
	return;
}
void displayFloatArray(std::array<float, l>& floatNumbers) {
	for (int i = 0;i < l; i++)
		std::cout << floatNumbers[i] << "; ";
	std::cout << std::endl;
}

std::array<float, l> delenie(std::array<float, l>& numerator, std::array<float, l>& denominator) {
	//14. Создать новый массив из двух других массивов путём операций над элементами 
	//массивов:
	//d. деления
	std::array<float, l> chastnoe;
	for (int i = 0; i < l; i++)
		chastnoe[i] = numerator[i] / denominator[i];
	return chastnoe;
}

void fillInformationAboutCity(std::array<std::string, N>& surnames, std::array<unsigned int, N>& ages, std::array<char, N>& pol) {
	std::array<char, 18> soglasnue = { 'W','R','T','P','S','D','F','G','H','K','L','Z','X','C','V','B','N','M' };
	std::array<char, 6> glasnue = { 'E','Y','U','I','O','A' };
	std::array<std::string, 10> ends = { "NOV", "LOW", "WICH", "KO", "EV", "NOVA", "LOWA", "WICH", "KO", "EVA" };
	for (int i = 0; i < N;i++) {
		unsigned int letters = (rand() % 4) + 1;
		std::string surname0;
		for (int j = 0; j < letters; j++) {
			surname0 = surname0 + soglasnue[rand() % 18];
			surname0 = surname0 + glasnue[rand() % 6];
		}
		surname0 = surname0 + ends[rand() % 10];
		surnames[i] = surname0;
		ages[i] = (rand() % 80) + 1;
		bool pol0 = (rand() % 2);
		if (pol0)
			pol[i] = 'M';
		else
			pol[i] = 'W';
	}
	return;
}
void readInformationAboutCity(std::array<std::string, N>& surnames, std::array<unsigned int, N>& ages, std::array<char, N>& pol) {
	std::cout << "Enter << SURNAME AGE POL(M/W)" << std::endl;
	for (int i = 0; i < N; i++) {
		std::cout << (i + 1) << ") ";
		std::cin >> surnames[i] >> ages[i] >> pol[i];
	}
	return;
}
