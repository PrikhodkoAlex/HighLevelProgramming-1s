#include "lab10_string.h"
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	srand(time(NULL));
	std::string file1234Name = "input1234.txt";
	writeToFile(file1234Name);
	std::string str;
	getTextFromFileToString(file1234Name, str);
	
	
	unsigned short int choice;
	do {
		std::cout << "Enter a number of task << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << std::endl << "Task 1 (12)"<< std::endl << str << std::endl;
			replaceTrueToFalse(str);
			std::cout << std::endl << "After calling replaceTrueToFalse(str):" << std::endl << str << std::endl;;

			break;
		case 2:
			std::cout << std::endl << "Task 2 (3)" << std::endl << str << std::endl;
			std::cout << "In this string " << count6LetteryWords(str) << " words which contain 6 letters" << std::endl;
			break;
		case 3:
			std::cout << std::endl << "Task 3 (16)" << std::endl << str << std::endl;
			std::cout << "In this string " << countNumberCharsInString(str) << " number characters('0','1','2','3','4','5','6','7','8','9')" << std::endl;
			break;
		case 4:
			std::cout << std::endl << "Task 4 (21)" << std::endl << str << std::endl;
			replaceNumberCharsToWords(str);
			std::cout <<std::endl << "After replacement number characters to words:" << std::endl;
			std::cout << str << std::endl;
			break;
		case 5:
			std::cout << std::endl << "Task 5 (23)" << std::endl;
			checkBracketsInFile("programText0.txt", "outIsBracketsProgramsCorrect.txt");
			checkBracketsInFile("programTextWithMistakes.txt", "outIsBracketsProgramsCorrect.txt");
			break;
		default:
			break;

		}
	} while (choice != 0);

	return 0;
}

void writeToFile(std::string fileName) {
	std::ofstream oFile;
	oFile.open(fileName, std::ios::out);
	if (!oFile.is_open()) {
		std::cout << "Error open file " << fileName << std::endl;
		return;
	}
	else {
		std::array<std::string, 35> words = { "правда", "ложь", "плохо", "  ", "ум", "мир", "раз", "понедельник", "конец", "массив", "символ", "пробел", " цифра", "группа", "результат проверки", "программа", "задачи", "алгоритм", "оценка", "экзамен", "сайт", "курс", "матрица", "  ", "  ", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0"};
		std::array<std::string, 2> commentSymbols = { "/*", "*/" };
		int n = 60;
		bool isCommentStart = false;
		int index = 0;
		for (int i = 0; i < n; i++) {
			index = rand() % (words.size() + 1);
			if (index == words.size()) {
				oFile << commentSymbols[isCommentStart];
				isCommentStart = !isCommentStart;
			}
			else {
				oFile << words[index] << ' ';
			}


		}
		std::cout << "words written to file \"" << fileName << "\"" << std::endl;
		oFile.close();
	}
}

void getTextFromFileToString(std::string fileName, std::string& str) {
	std::ifstream iFile;
	iFile.open(fileName, std::ios::in);
	if (!iFile.is_open()) {
		std::cout << "Error open file \"" << fileName << "\"." << std::endl;
		return;
	}
	else {
		std::getline(iFile, str, '\n');
		std::cout << "String got from \"" << fileName << "\"." << std::endl;
		iFile.close();
	}
}

void replaceTrueToFalse(std::string& str) {
	//12. Составить алгоритм, заменяющий в тексте слова “правда” на “ложь”
	int start = str.find("правда");
	while (start != std::string::npos) {
		str.replace(start, 6, "ложь");
		start = str.find("правда", start);
	}
	return;

}

int count6LetteryWords(const std::string& str) {
	//3. Составить алгоритм, находящий, сколько слов в тексте состоит из 6 символов.
	int start = 0;
	int end = str.find(' ');
	int count = 0;
	while (end != std::string::npos) {
		if (end - start == 6)
			count++;
		start = end + 1;
		end = str.find(' ', start);
	}
	if (str.size() - start == 6)
		count++;
	return count;
}

int countNumberCharsInString(const std::string& str) {
	//16    В данной строке найти количество цифр.
	int countOfNumbChar = 0;
	for (int i = 0; i < str.size(); i++) {
		if (isNumber(str[i]))
			countOfNumbChar++;
	}
	return countOfNumbChar;

}

bool isNumber(char ch) {
	return ((ch == '0') || (ch == '1') || (ch == '2') || (ch == '3') || (ch == '4') ||
		(ch == '5') || (ch == '6') || (ch == '7') || (ch == '8') || (ch == '9'));
}

void replaceNumberCharsToWords(std::string& str) {
	//21. Дан текст. Заменить все цифры соответствующими словами
	std::array<std::string, 10> numberWords = { "нуль", "один", "два","три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
	for (int i = 0; i < str.size(); i++) {
		if (isNumber(str[i])) {
			str.replace(i, 1, numberWords[std::stoi(str.substr(i, 1))]);
		}
	}
	return;
}

void getProgramFromFileToString(const std::string& inFileName, std::string& str) {
	std::ifstream iFile;
	iFile.open(inFileName, std::ios::in);
	if (!iFile.is_open()) {
		std::cout << "Error open file \"" << inFileName << "\"" << std::endl;
		return;
	}
	else {
		std::string oneString;
		while (!iFile.eof()) {
			std::getline(iFile, oneString, '\n');
			str.append(oneString);
			str.append("\n");
		}
		//std::cout << "Program has been red from file \"" << inFileName << "\"" << std::endl;
		return;
		iFile.close();
	}

}

bool isBracketsCorrect(const std::string& str) {
	int stackCount = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '{')
			stackCount++;
		else if (str[i] == '}') {
			stackCount--;
			if (stackCount < 0)
				return false;
		}
	}
	return (stackCount == 0);
}

void checkBracketsInFile(const std::string& inFileName, const std::string& outFileName) {
	//23. Задача*. В текстовом файле, содержащем текст программы на языке С++, проверить соответствие
	//открывающихся и закрывающихся фигурных скобок { и }. Результат проверки вывести на экран и
	//записать в виде фразы в текстовый файл. Результат работы программы (вывод) поместить в 
	//отдельный текстовый файл (например, "out . txt " ), продублировав на экране.
	std::string str;
	getProgramFromFileToString(inFileName, str);
	//std::cout << str << std::endl;
	bool isBrCorrect = isBracketsCorrect(str);
	if (isBrCorrect) 
		std::cout << "In file " << inFileName << " {, } brackets used right" << std::endl;
	
	else
		std::cout << "In file " << inFileName << " {, } brackets are not used right. There are mistakes" << std::endl;
	std::ofstream oFile;
	oFile.open(outFileName, std::ios::app);
	if (!oFile.is_open()) {
		std::cout << "Error open file \"" << outFileName << "\"" << std::endl;
		return;
	}
	else {
		if (isBrCorrect)
			oFile << "Ok.  In file " << inFileName << " {, } brackets used right" << std::endl;
		else
			oFile << "No. In file " << inFileName << " {, } brackets are not used right. There are mistakes" << std::endl;
		oFile.close();
	}
	return;
		
}