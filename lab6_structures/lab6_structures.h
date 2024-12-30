#include <array>
#include <ctime>
#include <iostream>

struct MyTime {
	unsigned short int hours;
	unsigned short int minutes;
	unsigned short int seconds;
};
struct ComplexNumber {
	double re;
	double im;
};
struct Sensor {
	double min;
	double max;
	double delta;
	double velocity;
};
struct MovingRobotCar {
	double velocity;
	double timeOfMoving;
	unsigned int number;
};
bool isTime1MoreThenTime2(const MyTime& time1, const MyTime& time2);
void comparisonBetweenTwoTimes();
void comparisonRealPartsOfComplexNumbers();
void fillRandomSensor(Sensor& s);
void displaySensor(const Sensor& s);
void displaySensorWithMinVelocity();
void displaySensorWithMinDelta();
double calculateDistance(const MovingRobotCar& car);
void displayDistanceOfMovingRobot();
