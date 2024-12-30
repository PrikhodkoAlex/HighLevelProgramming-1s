#include <iostream>
#include <cmath>

void displayNulls(unsigned int H);
float function2J(float x);
float function2N(float x);
float stepen(float x, int n);
float function3j(float x, unsigned int ch);
float function3d(float x, unsigned int ch);

int main() {
	unsigned short int choice;
	unsigned int h;
	float Xstart, Xend, x, d;
	unsigned int n, m, ch, sh;
	int s;
	do {
		std::cout << "Enter number of the task(1-7) << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			//1. Вывести на экран Н строк из нулей, причем количество нулей в каждой строке
			//равно номеру строки.Количество строк Н вводит пользователь(можно из файла).
			std::cout << "Enter h << ";
			std::cin >> h;
			displayNulls(h);
			break;
		case 2:
			//2. Протабулировать функцию (шаг и диапазон задаёт пользователь):
			//j. y = (5+4x)^2 + 8x + cos(21x+10);
			std::cout << "Enter Xstart << ";
			std::cin >> Xstart;
			std::cout << "Enter Xend << ";
			std::cin >> Xend;
			std::cout << "Enter d << ";
			std::cin >> d;
			x = Xstart;
			while (x <= Xend) {
				std::cout << x << "\t|" << function2J(x) << std::endl;
				x = x + d;
			}
			break;
		case 3:
			//2. Протабулировать функцию (шаг и диапазон задаёт пользователь):
			//j. y = (5+4x)^2 + 8x + cos(21x+10);
			std::cout << "Enter Xstart << ";
			std::cin >> Xstart;
			std::cout << "Enter Xend << ";
			std::cin >> Xend;
			std::cout << "Enter d << ";
			std::cin >> d;
			x = Xstart;
			while (x <= Xend) {
				std::cout << x << "\t|" << function2N(x) << std::endl;
				x = x + d;
			}
			break;
		case 4:
			//4. Вывести на экран ряд натуральных чисел от Н до М с шагом Ш. Например, если
			//Н = 10, М = 35, Ш = 5, то вывод должен быть таким : 10 15 20 25 30 35. Значения Н, М,
			//Ш указываются пользователем(считываются с клавиатуры или из файла).
			std::cout << "Enter N << ";
			std::cin >> n;
			std::cout << "Enter M << ";
			std::cin >> m;
			std::cout << "Enter SH << ";
			std::cin >> sh;

			while (n <= m) {
				std::cout << n << ", ";
				n = n + sh;
			}
			std::cout << std::endl;
			break;
		case 5:
			//6. Вычислить степень введенного числа (с помощью циклов).
			std::cout << " x^n = " << std::endl;
			std::cout << "Enter x << ";
			std::cin >> x;
			std::cout << "Enter n << ";
			std::cin >> s;
			std::cout << x << "^" << s << " = " << stepen(x, s) << std::endl;
			break;
		case 6: //3. Пользователь задаёт число Ч и Х. Посчитать y:
			//j. y = x + (x^2)/3 + (x^3)/4 + ... + (x^ch)/(ch + 1)
			std::cout << "Enter x << ";
			std::cin >> x;
			std::cout << "Enter ch << ";
			std::cin >> ch;
			std::cout << "        x^2   x^3          x^ch  " << std::endl;
			std::cout << "y = x + --- + --- + ... + ------ = " << function3j(x, ch) << std::endl;
			std::cout << "         3     4          ch + 1" << std::endl;
			break;
		case 7:////3. Пользователь задаёт число Ч и Х. Посчитать y:
			//d. y = 3 / (7x) + 4 / (9x) + 5 / (11x) + ... + (...) / (ch*x)
			std::cout << "Enter x << ";
			std::cin >> x;
			std::cout << "Enter ch << ";
			std::cin >> ch;
			std::cout << "    3    4     5          ..." << std::endl;
			std::cout << "y = -- + -- + --- + ... + ----  = " << function3d(x, ch) << std::endl;
			std::cout << "    7x   9x   11x         ch*x" << std::endl;
			break;



		default:
			break;
		}
	} while (choice != 0);

	return 0;
}



void displayNulls(unsigned int H) {
	//1. Вывести на экран Н строк из нулей, причем количество нулей в каждой строке
	//равно номеру строки.Количество строк Н вводит пользователь(можно из файла).
	for (unsigned int i = 1; i < H + 1; i++) {
		for (int j = 1; j < i + 1; j++)
			std::cout << '0';
		std::cout << std::endl;
	}
}

float function2J(float x) {
	//2. Протабулировать функцию (шаг и диапазон задаёт пользователь):
	//j. y = (5+4x)^2 + 8x + cos(21x+10)
	return (5 + 4 * x) * (5 + 4 * x) + 8 * x + cos(21 * x + 10);
}

float function2N(float x) {
	//2. Протабулировать функцию (шаг и диапазон задаёт пользователь):
	//y = sqrt(2 + 3*x) + 72*x + tg(4*x + 31)
	return sqrt(2 + 3 * x) + 72 * x + tanf(4 * x + 31);
}

float stepen(float x, int n) {
	//6. Вычислить степень введенного числа (с помощью циклов).
	float result = 1;
	if (n > 0) {
		for (int i = 0; i < n; i++)
			result = result * x;
	}
	else if ((x > 0) || (x < 0)) {
		for (int i = n; i < 0;i++)
			result = result / x;
	}
	else
		result = 1000000000;

	return result;

}


float function3j(float x, unsigned int ch) {
	//3. Пользователь задаёт число Ч и Х. Посчитать y:
	//j. y = x + (x^2)/3 + (x^3)/4 + ... + (x^ch)/(ch + 1)
	if (ch == 0)
		return 0;
	float result = x;
	for (unsigned int i = 2; i <= ch; i++)
		result = result + (stepen(x, i) / (i + 1));
	return result;
}

float function3d(float x, unsigned int ch) {
	//3. Пользователь задаёт число Ч и Х. Посчитать y:
	//d. y = 3 / (7x) + 4 / (9x) + 5 / (11x) + ... + (...) / (ch*x)
	float result = 0;
	unsigned int n = 3;

	for (unsigned int i = 7; i <= ch; i = i + 2) {
		result = result + (n / (i * x));
		n = n + 1;
	}
	return result;

}
