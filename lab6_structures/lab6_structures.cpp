#include "lab6_structures.h"



int main() {
	srand(time(NULL));
	unsigned short int choice;
	do {
		std::cout << std::endl << "Enter number of task << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			comparisonBetweenTwoTimes();
			break;
		case 2:
			comparisonRealPartsOfComplexNumbers();
			break;
		case 3:
			displaySensorWithMinVelocity();
			break;
		case 4:
			displaySensorWithMinDelta();
			break;
		case 5:
			displayDistanceOfMovingRobot();
			break;
		default:
			break;
		}
	} while (choice != 0);
	return 0;
}




bool isTime1MoreThenTime2(const MyTime& time1, const MyTime& time2) {
	/*
	if (time1.hours > time2.hours)
		return true;
	else if (time1.hours < time2.hours)
		return false;
	else if (time1.minutes > time2.minutes)
		return true;
	else if (time1.minutes < time2.minutes)
		return false;
	else if (time1.seconds > time2.seconds)
		return true;
	else
		return false;
	*/

	if (time1.hours != time2.hours)
		return (time1.hours > time2.hours);
	else if (time1.minutes != time2.minutes)
		return (time1.minutes > time2.minutes);
	else
		return (time1.seconds > time2.seconds);

}
void comparisonBetweenTwoTimes() {
	//В следующих задачах реализовать функции для ввода и вывода информации о 
	//структурах.
		//1. Создайте структуру, которая хранит время : часы, минуты, секунды.
	//b. Написать функцию, которая сравнивает два времени. Возвращает true, если 
	//первый аргумент больше второго.

	MyTime time1, time2;
	do {
		std::cout << "Enter time1 \"hh mm ss\" << ";
		std::cin >> time1.hours >> time1.minutes >> time1.seconds;
	} while ((time1.hours > 23) || (time1.minutes > 59) || (time1.seconds > 59));
	do {
		std::cout << "Enter time2 \"hh mm ss\" << ";
		std::cin >> time2.hours >> time2.minutes >> time2.seconds;
	} while ((time2.hours > 23) || (time2.minutes > 59) || (time2.seconds > 59));
	if (isTime1MoreThenTime2(time1, time2))
		std::cout << "time1 > time2" << std::endl;
	else
		std::cout << "time1 <= time2" << std::endl;
	return;
}

void comparisonRealPartsOfComplexNumbers() {
	//2. Создайте структуру для хранения комплексных чисел. Атрибуты: вещественная и 
	//мнимая части.Объявите два числа и получите их значения от пользователя.
	//f. Напишите функцию, которая будет сравнивать вещественную часть 
	//комплексного числа.
	ComplexNumber n1, n2;
	std::cout << "Enter complex number n1 (n1 = a + bi) \"a b\" << ";
	std::cin >> n1.re >> n1.im;
	std::cout << "Enter complex number n2 (n2 = c + di) \"c d\" << ";
	std::cin >> n2.re >> n2.im;
	std::cout << "n1 = " << n1.re << " + (" << n1.im << "i)" << std::endl;
	std::cout << "n2 = " << n2.re << " + (" << n2.im << "i)" << std::endl;
	if (n1.re > n2.re)
		std::cout << "Re(n1) > Re(n2)" << std::endl;
	else if (n1.re < n2.re)
		std::cout << "Re(n1) < Re(n2)" << std::endl;
	else
		std::cout << "Re(n1) = Re(n2)" << std::endl;
	return;


}

void fillRandomSensor(Sensor& s) {
	s.min = (rand() % 51) + ((double)rand() / RAND_MAX);
	s.max = (rand() % 500) + s.min + ((double)rand() / RAND_MAX);
	s.delta = (rand() % 11) + ((double)rand() / RAND_MAX);
	s.velocity = (rand() % 51) + ((double)rand() / RAND_MAX);
	return;
}
void displaySensor(const Sensor& s) {
	std::cout << s.min << "\t" << s.max << "\t" << s.delta << "\t" << s.velocity << std::endl;
	return;
}
void displaySensorWithMinVelocity() {
	//7. Имеется информация о датчиках: диапазон измеряемых значений (min, max), 
	//погрешность, максимальная скорость.Вывести данные о датчике с наименьшей
	//скоростью работы.
	const unsigned short int n = 10;
	std::array<Sensor, n> sensors;
	for (int i = 0; i < n; i++)
		fillRandomSensor(sensors[i]);
	std::cout << "number\t min\t max\t delta\t velocity" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << "\t";
		displaySensor(sensors[i]);
	}
	double minVelocity = sensors[0].velocity;
	unsigned short int minVelocityIndex = 0;
	for (int i = 0; i < n; i++)
		if (sensors[i].velocity < minVelocity) {
			minVelocity = sensors[i].velocity;
			minVelocityIndex = i;
		}
	std::cout << "Sensor with minimal velocity is" << std::endl;
	std::cout << minVelocityIndex + 1 << "\t";
	displaySensor(sensors[minVelocityIndex]);
	return;
}
void displaySensorWithMinDelta() {
	//6. Имеется информация о датчиках : диапазон измеряемых значений(min, max),
	//погрешность, максимальная скорость.Вывести данные о самом точном датчике.
	const unsigned short int n = 10;
	std::array<Sensor, n> sensors;
	for (int i = 0; i < n; i++)
		fillRandomSensor(sensors[i]);
	std::cout << "number\t min\t max\t delta\t velocity" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << i + 1 << "\t";
		displaySensor(sensors[i]);
	}
	double minDelta = sensors[0].delta;
	unsigned short int minDeltaIndex = 0;
	for (int i = 0; i < n; i++)
		if (sensors[i].delta < minDelta) {
			minDelta = sensors[i].delta;
			minDeltaIndex = i;
		}
	std::cout << "Sensor with minimal delta is" << std::endl;
	std::cout << minDeltaIndex + 1 << "\t";
	displaySensor(sensors[minDeltaIndex]);
	return;
}

double calculateDistance(const MovingRobotCar& car) {
	return car.velocity * car.timeOfMoving;
}

void displayDistanceOfMovingRobot() {
	//11. Робот-автомобиль описывается как структура с полями: скорость, длительность 
	//движения и номер.Напишите функцию для расчёта пройденного расстояния.
	MovingRobotCar car;
	std::cout << "Enter characteristics of moving robot-car (number velocity timeOfMoving) << ";
	std::cin >> car.number >> car.velocity >> car.timeOfMoving;
	std::cout << "Robot-car go distance: " << calculateDistance(car) << std::endl;
	return;
}
