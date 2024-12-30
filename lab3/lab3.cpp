#include <iostream>
#include <cmath>
#include <string>


void number1J() {
	//1. Дана функция y = f(x).Найти значение функции по x :
	//J
	//y = 3x - 5, если x > 5
	//y = 10, если x = 5
	//y = 2 * | x - 2 | +5, если x < 5
	float x, y;
	std::cout << "Enter x << ";
	std::cin >> x;
	if (x > 5) {
		y = 3 * x - 5;
		std::cout << "y = 3 * " << x << " - 5 = " << y << std::endl;
	}
	else if (x == 5) {
		y = 10;
		std::cout << "y = " << y << std::endl;
	}
	else {
		y = 2 * fabs(x - 2) + 5;
		std::cout << "y = 2 * |" << x << " - 2| + 5 = " << y << std::endl;
	}

}

void number1C() {
	//1. Дана функция y=f(x). Найти значение функции по x:
	//C
	//y = 1,5x + 5, если x > 0
	//y = -2, если x = 0
	//y = 2 * | x + 4 | -6, если x < 0
	float x, y;
	std::cout << "Enter x << ";
	std::cin >> x;
	if (x > 0) {
		y = 1.5 * x + 5;
		std::cout << "y = 1.5 * " << x << " + 5 = " << y << std::endl;
	}
	else if (x == 0) {
		y = -2;
		std::cout << "y = " << y << std::endl;
	}
	else {
		y = 2 * fabs(x + 4) - 6;
		std::cout << "y = 2 * |" << x << " + 4| - 6 = " << y << std::endl;
	}
}

void number2A() {
	//2. Напишите программу, которая принимает от пользователя координаты точки и 
	//определяет, попала ли точка в заштрихованную область.
	//A
	double x = 0.0;
	double y = 0.0;
	std::cout << "Enter x << ";
	std::cin >> x;
	std::cout << "Enter y << ";
	std::cin >> y;
	if ((x <= 2) && (y <= x) && (x * x + (y * y) >= 4) && (y >= 0)) 
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;
	double d = 0.1;
	for (double j = 4.0; j > -4.0;) {
		for (double i = -4.0; i < 4.0; ) {
			if ((i - x < d) && (i - x > -d) && (j - y < d) && (j - y > -d)) {
				std::cout << '@';
			}
			else if ((i < 2 + d) && (j < i + d) && (i * i + (j * j) > 4 - d) && (j > 0 - d)) 
				std::cout << '#';
			else {
				if (((i - 2 > -d) && (i - 2 < d)) || ((i * i + j * j - 4.0 < d) && (i * i + j * j - 4.0 > -d)) || ((i - j > -d) && (i - j < d)))
					std::cout << '*';
				else
					std::cout << ' ';
			}
			i = i + 0.1;
		}
		std::cout << std::endl;
		j = j - 0.1;
	}
}

void number3g() {
	//3. Напишите программу, которая принимает от пользователя координаты точки и 
	//определяет, попала ли точка в заштрихованную область.
	//Г
	double x = 0.0;
	double y = 0.0;
	std::cout << "Enter x << ";
	std::cin >> x;
	std::cout << "Enter y << ";
	std::cin >> y;
	if (x <= 0) {
		if ((y >= 0) && (x * x + y * y <= 1))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	else {
		if ((y >= 0) && (x * x + y * y >= sqrt(0.3)) && (x * x + y * y <= 1))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
	double d = 0.05;
	for (double j = 1.1; j > -0.4;) {
		for (double i = -1.1; i < 1.1; ) {
			if ((i - x < d) && (i - x > -d) && (j - y < d) && (j - y > -d)) {
				std::cout << '@';
			}
			else if (((i <= 0) && (j >= -d) && (i * i + j * j <= 1 + d)) || ((i > 0) && (j >= -d) && (i * i + j * j >= sqrt(0.3) - d) && (i * i + j * j <= 1 + d)))
				std::cout << '#';
			else {
				if ((j >= -d) && (((i * i + j * j - 1 < d) && (i * i + j * j - 1 > -d)) || ((i >= -1 - d) && (i <= d) && (j < d) && (j > - d)) || ((i > -d) && (i * i + j * j - sqrt(0.3) > -d) && (i * i + j * j - sqrt(0.3) < d)) || ((i <= 1 + d) && (i > 0.3) && (j < d) && (j > - d))))
					std::cout << '*';
				else
					std::cout << ' ';
			}
			i = i + 0.05;
		}
		std::cout << std::endl;
		j = j - 0.05;
	}
}

void number4_5() {
	//4. Пользователь вводит день месяца. Вывести на экран день недели. Считаем, что 1-е
	//число месяца это вторник.
	//5. Модификация задачи 4. Пользователь также вводит число от 1 до 7, обозначающее 
	//номер недели для первого числа месяца
	std::string weekDays[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
	unsigned short int dayOfMonth, firstDayOfMonth;
	std::cout << "Enter first day of month (1 - 7) << ";
	std::cin >> firstDayOfMonth;
	std::cout << "Enter day of month (1 - 31) << ";
	std::cin >> dayOfMonth;
	unsigned short int weekDay = ((firstDayOfMonth + dayOfMonth - 2) % 7) + 1;
	std::cout << weekDay << " (" << weekDays[weekDay - 1] << ')' << std::endl;

}

int main() {
	unsigned short int choice = 1;
	while (choice != 0) {
		std::cout << "Enter number of task:\n1 - 1.J\n2 - 1.C\n3 - 2.A\n4 - 3.g\n5 - 4. and 5.\n";
		std::cin >> choice;
		switch (choice) {
			case 1: number1J();
					break;
			case 2: number1C();
					break;
			case 3:number2A();
					break;
			case 4: number3g();
					break;
			case 5: number4_5();
					break;
		}
		std::cout << std::endl << std::endl  << std::endl;
	}
	return 0;
}
