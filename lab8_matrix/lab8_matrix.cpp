#include "lab8_matrix.h"

int main() {
	srand(time(NULL));
	unsigned short int choice = 1;
	char operat6;
	int n, m;
	std::string fileName6 = "task4.txt";
	std::string fileName7 = "tast7.txt";
	while (choice != 0) {
		std::cout << "Enter number of task << ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			task1();
			break;
		case 2:
			task2SwapElementes();
			break;
		case 3:
			task3();
			break;
		case 4:
			fillFileToRobot(fileName6);
			ReadFileToRobot(fileName6);
			break;
		case 5:
			task5();
			break;
		case 6:
			std::cout << "Enter operator (+, -, *, T) << ";
			std::cin >> operat6;
			switch (operat6) {
			case '+':
				task6summa(true);
				break;
			case '-':
				task6summa(false);
				break;
			case '*':
				task6proizvedenie();
				break;
			case 'T':
				task6transpose();
				break;
			default:
				break;
			}
			break;
		case 7:
			std::cout << "Enter n m << ";
			std::cin >> n >> m;
			task7fillSkinFile(fileName7, n, m);
			task7readSkinFile(fileName7);
			break;
		default:
			break;


		}
	}
	return 0;
}





void randomFillMatrix(int* addr, int n, int m, int minElem, int maxElem) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			*(addr + i * m + j) = (rand() % (maxElem - minElem)) + minElem;
		}
	}
	return;
}

void printMatrix(int* addr, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << *(addr + i * m + j) << "\t";
		}
		std::cout << std::endl;
	}
	return;
}

void task1() {
	//3. В квадратной матрице, найти сумму отрицательных элементов, лежащих на главной 
	//диагонали.
	const int n = 5;
	std::array<std::array<int, n>, n> matrix1;
	randomFillMatrix(matrix1.data()->data(), n, n, -10, 10);
	printMatrix(matrix1.data()->data(), n, n);
	std::cout << "sum of all negative matrix[i][i] = " << getSumOfNegativeElementsOnMainDiagonal(matrix1.data()->data(), n) << std::endl;
	return;

}
int getSumOfNegativeElementsOnMainDiagonal(int* addr, int n) {
	//3. В квадратной матрице, найти сумму отрицательных элементов, лежащих на главной 
	//диагонали.
	int summa = 0;
	for (int i = 0; i < n; i++) {
		if (*(addr + i * n + i) < 0)
			summa += *(addr + i * n + i);
	}
	return summa;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}
void task2SwapElementes() {
	//5. В квадратной матрице для каждой строки найти минимальный элемент и 
	//переставить его с элементом, стоящим в этой строке на главной диагонали.

	const int n = 5;
	std::array<std::array<int, n>, n> matrix;
	randomFillMatrix(matrix.data()->data(), n, n, -10, 10);
	std::cout << "Before replacements:" << std::endl;
	printMatrix(matrix.data()->data(), n, n);

	for (int i = 0; i < n; i++) {
		unsigned int minIndex = 0;
		for (int j = 1; j < n; j++) {
			if (matrix[i][j] < matrix[i][minIndex])
				minIndex = j;
		}
		swap(&matrix[i][minIndex], &matrix[i][i]);
	}
	std::cout << std::endl << "After replacements:" << std::endl;
	printMatrix(matrix.data()->data(), n, n);
	return;
}

void task3() {
	//8. Дана матрица. Элементы первой строки — мощность электромотора, второй строки 
	//— категория мотора(число от 1 до 3).Найти самый мощный мотор категории 3.

	const int n = 2;
	const int m = 10;
	std::array<std::array<int, m>, n> matrixOfElectromotors;
	randomFillMatrix(matrixOfElectromotors.data()->data(), 1, m, 1, 10);
	randomFillMatrix(matrixOfElectromotors[1].data(), 1, m, 1, 4);
	printMatrix(matrixOfElectromotors.data()->data(), n, m);
	unsigned int maxPower3Column = m + 1;
	int maxPower3 = 0;
	for (int i = 0; i < m; i++) {
		if ((matrixOfElectromotors[1][i] == 3) && (matrixOfElectromotors[0][i] > maxPower3)) {
			maxPower3Column = i;
			maxPower3 = matrixOfElectromotors[0][i];
		}
	}
	std::cout << "Most powerful motor which category is 3 has column number " << maxPower3Column + 1 << std::endl;
	std::cout << "Power: " << matrixOfElectromotors[0][maxPower3Column] << std::endl;
	std::cout << "Category: " << matrixOfElectromotors[1][maxPower3Column] << std::endl;
	return;


}

int min(int a, int b) {
	if (a < b)
		return a;
	else
		return b;
}
int max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void fillFileToRobot(std::string fileName) {
	std::ofstream oFile;
	oFile.open(fileName.c_str(), std::ios::out || std::ios::binary);
	if (oFile.is_open()) {
		RobotState curState;
		curState.x = rand() % 8;
		curState.y = rand() % 8;
		curState.power = 100;
		curState.speed = 0;
		oFile.write((char*)&curState, sizeof(curState));
		for (int i = 0; i < robotStateCount;i++) {
			curState.x = max(0, min(7, curState.x + ((rand() % 3) - 1)));
			curState.y = max(0, min(7, curState.y + ((rand() % 3) - 1)));
			curState.power -= 1;
			curState.speed = rand() % 5;
			oFile.write((char*)&curState, sizeof(curState));
		}
		oFile.close();
	}
	else
		std::cout << "Error: can not open file to write." << std::endl;
	return;

}
void ReadFileToRobot(std::string fileName) {
	//9. Объявить, реализовать заполнение данными с клавиатуры ИЛИ из файла и вывести
	//на экран матрицу, описывающую следующие сущности.Предложите свой вариант.
	std::ifstream iFile;
	iFile.open(fileName.c_str(), std::ios::in || std::ios::binary);
	if (iFile.is_open()) {
		std::array<std::array<int, 4>, robotStateCount> robotStates;
		iFile.read((char*)(robotStates.data()->data()), sizeof(robotStates));
		printMatrix(robotStates.data()->data(), robotStateCount, 4);
		iFile.close();
	}
	else
		std::cout << "Error: can not open file to read." << std::endl;
	return;
}
void task5() {
	//10. Реализовать вычисление матричных норм из списка выше(только для квадратных
	//матриц).
	//6. Дана матрица. Составить массив, каждый элемент которого равен максимальному 
	//элементу соответствующей строки матрица.
	const int n = 5;
	const int m = 6;
	std::array<std::array<int, m>, n> matrix;
	randomFillMatrix(matrix.data()->data(), n, m, -10, 10);
	printMatrix(matrix.data()->data(), n, m);
	std::array<int, n> maximumElementsArray;
	fillMaxElements(matrix.data()->data(), n, m, maximumElementsArray.data());
	std::cout << "Maximum elements in each row:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << i + 1 << ") " << maximumElementsArray[i] << std::endl;
	std::cout << "Maximum sum of absolut value of elements in column (L1norm) = " << L1norm(matrix.data()->data(), n, m) << std::endl;
	std::cout << "Maximum sum of absolut value of elements in row (L infinity norm) = " << LInfinityNorm(matrix.data()->data(), n, m) << std::endl;
	std::cout << "Maximum absolut value of element = " << maxAbsElemNorm(matrix.data()->data(), n, m) << std::endl;
	std::cout << "Sum of  maindiagonal elements (track) " << trackMatrix(matrix.data()->data(), n, m) << std::endl;
	std::cout << "Sum of all elements in the matrix = " << sumAllElements(matrix.data()->data(), n, m) << std::endl;
	std::cout << "Sum of all squares of elements = " << sumAllSquareOfElements(matrix.data()->data(), n, m) << std::endl;



}

void fillMaxElements(int* mat, int n, int m, int* arr) {
	for (int i = 0; i < n; i++) {
		int maxElem = *(mat + i * m);
		for (int j = 1; j < m; j++)
			if (*(mat + i * m + j) > maxElem)
				maxElem = *(mat + i * m + j);
		*(arr + i) = maxElem;
	}
	return;

}

int L1norm(int* matrix, int n, int m) {
	int maxSumma = 0;
	for (int i = 0; i < n; i++)
		maxSumma += abs(*(matrix + m * i));
	int curSumma = 0;
	for (int j = 0; j < m; j++) {
		curSumma = 0;
		for (int i = 0; i < n; i++)
			curSumma += abs(*(matrix + m * i + j));
		if (curSumma > maxSumma)
			maxSumma = curSumma;
	}
	return maxSumma;
}

int LInfinityNorm(int* matrix, int n, int m) {
	int maxSumma = 0;
	for (int j = 0; j < m; j++)
		maxSumma += abs(*(matrix + j));
	int curSumma = 0;
	for (int i = 0; i < n; i++) {
		curSumma = 0;
		for (int j = 0; j < m; j++)
			curSumma += abs(*(matrix + m * i + j));
		if (curSumma > maxSumma)
			maxSumma = curSumma;
	}
	return maxSumma;
}

int maxAbsElemNorm(int* matrix, int n, int m) {
	int maxElem = *matrix;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			if (abs(*(matrix + i * m + j)) > maxElem)
				maxElem = abs(*(matrix + i * m + j));
	}
	return maxElem;
}

int trackMatrix(int* matrix, int n, int m) {
	int summa = 0;
	int minSize = min(n, m);
	for (int i = 0; i < minSize; i++) {
		summa += *(matrix + i * m + i);
	}
	return summa;
}

int sumAllElements(int* matrix, int n, int m) {
	int summa = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			summa += *(matrix + m * i + j);
	}
	return summa;
}

int sumAllSquareOfElements(int* matrix, int n, int m) {
	int summa = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			summa += (*(matrix + m * i + j)) * (*(matrix + m * i + j));
	}
	return summa;
}

void task6proizvedenie() {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	int n, m, l;
	std::cin >> n;
	std::cin >> m;
	std::cin >> l;

	std::vector<std::vector<int>*> matrixA(n);
	for (int i = 0; i < n;i++) {
		matrixA[i] = new std::vector<int>;
		matrixA[i]->resize(m);
	}
	randomFillMatrix2(matrixA, n, m, 0, 10);
	std::cout << "Matrix A:" << std::endl;
	printMatrix2(matrixA, n, m);

	std::vector<std::vector<int>*> matrixB(m);
	for (int i = 0; i < m;i++) {
		matrixB[i] = new std::vector<int>;
		matrixB[i]->resize(l);
	}
	randomFillMatrix2(matrixB, m, l, 0, 10);
	std::cout << "Matrix B:" << std::endl;
	printMatrix2(matrixB, m, l);

	std::vector<std::vector<int>*> matrixC(n);
	for (int i = 0; i < n;i++) {
		matrixC[i] = new std::vector<int>;
		matrixC[i]->resize(l);
	}
	//printMatrix2(matrixC, n, l);
	proizvedenieOfMatrix(matrixA, matrixB, matrixC, n, m, l);
	std::cout << "Matrix C = A * B" << std::endl;
	printMatrix2(matrixC, n, l);




}

void randomFillMatrix2(std::vector<std::vector<int>*>& address, int n, int m, int minElem, int maxElem) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			(*address[i])[j] = (rand() % (maxElem - minElem)) + minElem;
		}
	}
	return;
}

void printMatrix2(std::vector<std::vector<int>*>& address, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << (*(address[i]))[j] << "\t";
		}
		std::cout << std::endl;
	}
	return;
}

void proizvedenieOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m, int l) {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	int summa;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++) {
			summa = 0;
			for (int k = 0; k < m; k++) {
				summa += (*matrixA[i])[k] * (*matrixB[k])[j];
			}
			(*matrixC[i])[j] = summa;
		}
	}
	return;
}

void task6summa(bool isPlus) {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	int n, m;
	std::cin >> n;
	std::cin >> m;

	std::vector<std::vector<int>*> matrixA(n);
	for (int i = 0; i < n;i++) {
		matrixA[i] = new std::vector<int>;
		matrixA[i]->resize(m);
	}
	randomFillMatrix2(matrixA, n, m, -10, 10);
	std::cout << "Matrix A:" << std::endl;
	printMatrix2(matrixA, n, m);

	std::vector<std::vector<int>*> matrixB(n);
	for (int i = 0; i < n;i++) {
		matrixB[i] = new std::vector<int>;
		matrixB[i]->resize(m);
	}
	randomFillMatrix2(matrixB, n, m, 0, 10);
	std::cout << "Matrix B:" << std::endl;
	printMatrix2(matrixB, n, m);

	std::vector<std::vector<int>*> matrixC(n);
	for (int i = 0; i < n;i++) {
		matrixC[i] = new std::vector<int>;
		matrixC[i]->resize(m);
	}
	if (isPlus) {
		sumOfMatrix(matrixA, matrixB, matrixC, n, m);
		std::cout << "Matrix C = A + B" << std::endl;
		printMatrix2(matrixC, n, m);
	}
	else {
		differenceOfMatrix(matrixA, matrixB, matrixC, n, m);
		std::cout << "Matrix C = A - B" << std::endl;
		printMatrix2(matrixC, n, m);
	}
}

void sumOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m) {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*matrixC[i])[j] = (*matrixA[i])[j] + (*matrixB[i])[j];
	return;
}

void differenceOfMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixB, std::vector<std::vector<int>*>& matrixC, int n, int m) {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*matrixC[i])[j] = (*matrixA[i])[j] - (*matrixB[i])[j];
	return;
}


void task6transpose() {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	int n, m;
	std::cin >> n;
	std::cin >> m;

	std::vector<std::vector<int>*> matrixA(n);
	for (int i = 0; i < n;i++) {
		matrixA[i] = new std::vector<int>;
		matrixA[i]->resize(m);
	}
	randomFillMatrix2(matrixA, n, m, -10, 10);
	std::cout << "Matrix A:" << std::endl;
	printMatrix2(matrixA, n, m);

	std::vector<std::vector<int>*> matrixC(m);
	for (int i = 0; i < m;i++) {
		matrixC[i] = new std::vector<int>;
		matrixC[i]->resize(n);
	}

	transposeMatrix(matrixA, matrixC, n, m);
	std::cout << "Matrix A(transposed):" << std::endl;
	printMatrix2(matrixC, m, n);
	return;
}

void transposeMatrix(std::vector<std::vector<int>*>& matrixA, std::vector<std::vector<int>*>& matrixC, int n, int m) {
	//11. Задача *. Реализовать сложение, вычитание, умножение, транспонирование матриц 
	//азрешается фиксированный размер матриц).
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(*matrixC[j])[i] = (*matrixA[i])[j];
	return;
}

void task7fillSkinFile(std::string fileName, int n, int m) {
	//12. Задача * .Сосчитать количество чёрных пятен на белой шкуре.Шкуру представить
	//в виде 0 и 1 матрицы, где 0 - белый, а 1 - чёрный цвет.

	std::ofstream oFile;
	oFile.open(fileName.c_str(), std::ios::out);
	if (oFile.is_open()) {
		oFile << n << ' ' << m << std::endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				oFile << rand() % 2;
			oFile << '\n';
		}
		oFile.close();
	}
	else std::cout << "Error with file write." << std::endl;
	return;
}

void task7readSkinFile(std::string fileName) {
	//12. Задача * .Сосчитать количество чёрных пятен на белой шкуре.Шкуру представить
	//в виде 0 и 1 матрицы, где 0 - белый, а 1 - чёрный цвет.
	std::ifstream iFile;
	iFile.open(fileName.c_str(), std::ios::in);
	if (iFile.is_open()) {
		int n, m;
		int countOfSpots = 0;
		char symbol = '0';
		iFile >> n;
		iFile >> m;
		std::vector<std::vector<int>*> matrix(n);
		for (int i = 0; i < n;i++) {
			matrix[i] = new std::vector<int>;
			matrix[i]->resize(m);
		}
		for (int i = 0; i < n; i++) {
			int j = 0;
			for (int j = 0; j < m; j++) {
				iFile >> symbol;
				(*matrix[i])[j] = (int)symbol;
				if (symbol == '1') {
					countOfSpots++;
					std::cout << '1';
				}
				else
					std::cout << ' ';
				//std::cout << symbol;
			}
			std::cout << std::endl;
		}
		iFile.close();
		std::cout << "Count of spots(1) = " << countOfSpots << std::endl;
	}
	else std::cout << "Error with file read." << std::endl;
	return;
}


