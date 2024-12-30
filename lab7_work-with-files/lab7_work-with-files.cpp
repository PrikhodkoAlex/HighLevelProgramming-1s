#include "lab7_work-with-files.h"

int main() {
	srand(time(NULL));
	//1. Реализовать чтение заголовков файлов форматов. Проверить работоспособность 
	//можно по примерам.
	//b. ZIP: Local File Header
	ZIPHeader head1;
	std::string fileName1 = "files.zip";
	readZIPHeader(fileName1, head1);
	std::cout << "1) " << fileName1 << std::endl;
	displayZIPHeader(head1);
	std::cout << std::endl;


	// 3.Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
	//считывать из файла in.txt.Результат записывать в текстовый файл out.txt.Формат
	//записи данных :
	//x0, y(x0)
	//x1, y(x1)
	//x2, y(x2)
	//и т.д.
	//a.    y = x + 2x + 3x + ... + Чx
	writeFunctionToFile("in.txt", "out.txt");
	std::cout << std::endl;

	//6. Разработать программу для считывания полётных данных о квадрокоптерах из
	//файла.Одна строка содержит : Х, У, Команда, где ХУ – координаты, а Команда – это
	//набор чисел, характеризующих действие коптера : 10 – взлёт, 20 – посадка, 50 –
	//полёт, 60 – набрать высоту, 70 снизить высоту.Каждая новая строка содержит
	//новый набор координат и команд.Организовать переменные для хранения
	//информации.
	std::cout << "6) Commands for quadcopters" << std::endl;
	std::string fileName3 = "fileWithCommandsTask6.txt";
	randomFillFileOfCommands(fileName3);
	displayCommands(fileName3);
	char end;
	std::cin >> end;
	return 0;
}


void readZIPHeader(std::string fileName, ZIPHeader& header) {
	//1. Реализовать чтение заголовков файлов форматов. Проверить работоспособность 
	//можно по примерам.
	//b. ZIP: Local File Header

	std::ifstream file;
	file.open(fileName, std::ios::in | std::ios::binary);
	if (!file.is_open()) {
		std::cout << "Error open " << fileName << std::endl;
		return;
	}
	file.read((char*)&header, 30);
	//header.fName.resize(header.lenName);
	//header.ef.resize(header.lenEf);
	file.read((char*)(&header.fName), header.lenName);
	file.read((char*)(&header.ef), header.lenEf);
	file.close();
	return;
}

void displayZIPHeader(ZIPHeader& header) {
	std::cout << "Local File Header:" << std::endl;
	std::cout << "sign: " << header.sign << std::endl;
	std::cout << "version: " << header.version << std::endl;
	std::cout << "flag: " << header.flag << std::endl;
	std::cout << "comp: " << header.comp << std::endl;
	std::cout << "lastTime: " << (unsigned short int)header.lastTime << std::endl;
	std::cout << "lastDate: " << header.lastDate << std::endl;
	std::cout << "crc: " << header.crc << std::endl;
	std::cout << "sizec: " << header.sizec << std::endl;
	std::cout << "sized: " << header.sized << std::endl;
	std::cout << "lenName: " << header.lenName << std::endl;
	std::cout << "lenEf: " << (unsigned short int) header.lenEf << std::endl;
	std::cout << "fName: " << header.fName << std::endl;
	std::cout << "ef: " << header.ef << std::endl;
	return;
}

void writeFunctionToFile(std::string inFileName, std::string outFileName) {
	// Протабулировать функцию. Начальную и финальную точки, шаг, параметр Ч
	//считывать из файла in.txt.Результат записывать в текстовый файл out.txt.Формат
	//записи данных :
	//x0, y(x0)
	//x1, y(x1)
	//x2, y(x2)
	//и т.д.
	//a.    y = x + 2x + 3x + ... + Чx
	std::ifstream inFile;
	inFile.open(inFileName.c_str(), std::ios::in);
	if (!inFile.is_open()) {
		std::cout << "Error open " << inFileName << std::endl;
		return;
	}
	float begin, end, step;
	unsigned int ch;
	inFile >> begin >> end >> step >> ch;
	inFile.close();

	std::ofstream outFile;
	outFile.open(outFileName.c_str(), std::ios::out);
	if (!outFile.is_open()) {
		std::cout << "Error open " << outFileName << std::endl;
		return;
	}
	float x = begin;
	while (x <= end) {
		outFile << x << ", " << chFunction(x, ch) << std::endl;
		x += step;
	}
	std::cout << "3) chFunction (ch = " << ch << ") has been tabulated in file \"" << outFileName <<
		"\" from " << begin << " to " << end << " with step " << step << std::endl;
	outFile.close();
	return;
}

float chFunction(float x, unsigned int ch) {
	float sum = 0;
	for (int i = 1; i < ch + 1; i++)
		sum += i * x;
	return sum;
}

int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void randomFillFileOfCommands(std::string outFileName) {
	std::ofstream file;
	file.open(outFileName.c_str(), std::ios::out);
	if (!file.is_open()) {
		std::cout << "Error open " << outFileName << std::endl;
		return;
	}
	Command curCommand;
	curCommand.x = 0;
	curCommand.y = 0;
	curCommand.doing = 10;
	unsigned short int countOfMoving = (rand() % 6) + 1;
	for (int i = 0; i < countOfMoving; i++) {
		short int dx = (rand() % 41) - 20;
		short int dy = (rand() % 41) - 20;
		short int maxDxDy = max(abs(dx), abs(dy));
		curCommand.doing = 10;
		short int stX = curCommand.x;
		short int stY = curCommand.y;
		for (int t = 1; t < maxDxDy; t++) {
			file << curCommand.x << ' ' << curCommand.y << ' ' << curCommand.doing << std::endl;
			curCommand.x = stX + t * dx / maxDxDy;
			curCommand.y = stY + t * dy / maxDxDy;
			curCommand.doing = ((rand() % 3) + 5) * 10;
		}
		file << curCommand.x << ' ' << curCommand.y << ' ' << 20 << std::endl;
	}
	file.close();
	return;
}

void displayCommands(std::string inFileName) {
	//6. Разработать программу для считывания полётных данных о квадрокоптерах из 
	//файла.Одна строка содержит : Х, У, Команда, где ХУ – координаты, а Команда – это
	//набор чисел, характеризующих действие коптера : 10 – взлёт, 20 – посадка, 50 –
	//полёт, 60 – набрать высоту, 70 снизить высоту.Каждая новая строка содержит
	//новый набор координат и команд.Организовать переменные для хранения
	//информации.
	std::ifstream file;
	file.open(inFileName.c_str(), std::ios::in);
	if (!file.is_open()) {
		std::cout << "Error open " << inFileName << std::endl;
		return;
	}
	Command curCommand, prevCommand;
	prevCommand.x = 0;
	prevCommand.y = 0;
	prevCommand.doing = 0;
	while (!file.eof()) {
		file >> curCommand.x >> curCommand.y >> curCommand.doing;
		std::cout << "X: " << curCommand.x << ' ';
		if (curCommand.x > prevCommand.x)
			std::cout << "-> ";
		else if (curCommand.x < prevCommand.x)
			std::cout << "<- ";
		else
			std::cout << "- ";
		std::cout << "  \tY: " << curCommand.y << ' ';
		if (curCommand.y > prevCommand.y)
			std::cout << "/\\ ";
		else if (curCommand.y < prevCommand.y)
			std::cout << "\\/ ";
		else
			std::cout << "- ";
		std::cout << " \tDoing: " << curCommand.doing << " - ";
		switch (curCommand.doing) {
		case 10:
			std::cout << "Take off /\\" << std::endl;
			break;
		case 20:
			std::cout << "Landing ___" << std::endl;
			break;
		case 50:
			std::cout << "Flight -" << std::endl;
			break;
		case 60:
			std::cout << "Up /\\" << std::endl;
			break;
		case 70:
			std::cout << "Down \\/" << std::endl;
			break;
		default:
			break;
		}
		prevCommand.x = curCommand.x;
		prevCommand.y = curCommand.y;
	}
	file.close();
	return;
}

