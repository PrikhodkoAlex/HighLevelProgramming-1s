
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>




float task12_2(float r, float z) {
    //Провести рефакторинг кода:
    //1. В предыдущих домашних заданиях найти блоки кода, которые возможно выделить
    //   в функции и определить их в функции.Например, запись в файл, вычисление
    //   формул
    float t = sqrt(log(fabs(M_PI * r)) / (1000 + (r * z)));
    float m = 180 * atan((exp(5 * t) - exp(0 - (5 * t))) / (exp(z * t) - exp(0 - (z * t))));
    std::cout << "          ln(|pi*r|)\n";
    std::cout << "t = sqrt(------------) = " << t << std::endl;
    std::cout << "          1000 + rz\n";
    std::cout << "                 e^(5t) - e^(-5t)\n";
    std::cout << "m = 180 * arctg(------------------) = " << m << std::endl;
    std::cout << "                 e^(zt) - e^(-zt)\n";

    return m;
}

int Quarter(float x, float y);
double Leng(double xA, double yA, double xB, double yB);
void ShiftLeft(float& a, float& b, float& sc);
float f(float x);


int main() {
    unsigned short int choice = 1;
    while (choice != 0) {
        std::cout << std::endl << "Enter number of task << ";
        std::cin >> choice;
        switch (choice) {
        case 1:
            //Провести рефакторинг кода:
            //1. В предыдущих домашних заданиях найти блоки кода, которые возможно выделить
            //   в функции и определить их в функции.Например, запись в файл, вычисление
            //   формул
            float r, z, m;
            std::cout << "Enter r << ";
            std::cin >> r;
            std::cout << "Enter z << ";
            std::cin >> z;
            m = task12_2(r, z);
            std::cout << " m = " << m << std::endl;

            break;
        case 2:
            //10. Описать функцию Quarter(x, y) целого типа, определяющую номер координатной
            //четверти, в которой находится точка с ненулевыми вещественными координатами
           //(x, y).С помощью этой функции найти номера координатных четвертей для трех
            //точек с данными ненулевыми координатами.
            std::cout << "Task 10." << std::endl;
            float x, y;
            for (int i = 0; i < 3; i++) {
                std::cout << i + 1 << ") Enter x << ";
                std::cin >> x;
                std::cout << "  Enter y << ";
                std::cin >> y;
                std::cout << "The coordinate quarter of point is " << Quarter(x, y) << std::endl;
            }
            break;
        case 3:
            //15. Описать функцию Leng(xA, yA, xB, yB) вещественного типа, находящую длину
                //отрезка AB на плоскости по координатам его концов : AB = sqrt((xA - xB)^2 + (yA - yB)^2)
                //(xA, yA, xB, yB — вещественные параметры).С помощью этой функции найти длины отрезков 
                //AB, AC, AD, если даны координаты точек A, B, C, D.

            std::cout << "Task 15." << std::endl;
            double xA, yA, xB, yB, xC, yC, xD, yD;
            std::cout << "Enter coordinates of point A (x y) << ";
            std::cin >> xA >> yA;
            std::cout << "Enter coordinates of point B (x y) << ";
            std::cin >> xB >> yB;
            std::cout << "Enter coordinates of point C (x y) << ";
            std::cin >> xC >> yC;
            std::cout << "Enter coordinates of point D (x y) << ";
            std::cin >> xD >> yD;
            std::cout << "AB = " << Leng(xA, yA, xB, yB) << std::endl;
            std::cout << "AC = " << Leng(xA, yA, xC, yC) << std::endl;
            std::cout << "AD = " << Leng(xA, yA, xD, yD) << std::endl;
            break;
        case 4:
            //7. Описать процедуру ShiftLeft3(A, B, C), выполняющую левый циклический сдвиг :
            //  значение A переходит в C, значение C — в B, значение B — в A(A, B, C —
            //  вещественные параметры, являющиеся одновременно входными и выходными).С
            //  помощью этой процедуры выполнить левый циклический сдвиг для двух данных
            //  наборов из трех чисел : (A1, B1, C1) и(A2, B2, C2).
            float A1, B1, C1;
            float A2, B2, C2;
            std::cout << "Enter numbers (A1 B1 C1) << ";
            std::cin >> A1 >> B1 >> C1;
            ShiftLeft(A1, B1, C1);
            std::cout << "A1 = " << A1 << "  B1 = " << B1 << "  C1 = " << C1 << std::endl;
            std::cout << "Enter numbers (A2 B2 C2) << ";
            std::cin >> A2 >> B2 >> C2;
            ShiftLeft(A2, B2, C2);
            std::cout << "A2 = " << A2 << "  B2 = " << B2 << "  C2 = " << C2 << std::endl;
            break;

        case 5:
            //16. Реализовать функцию y = f(x). Протабулировать функцию
            //c
            //y = 1, 5x + 5, если x > 0
            //y = -2, если x = 0
            //y = 2 * | x + 4 | -6, если x < 0
            for (int i = 0; i < 8 * 12; i++)
                std::cout << '-';
            std::cout << std::endl;
            for (float x = -6; x < 6; x = x + 1)
                std::cout << x << "\t";
            std::cout << '|' << std::endl;
            for (int i = 0; i < 8 * 12; i++)
                std::cout << '-';
            std::cout << std::endl;
            for (float x = -6; x < 6; x = x + 1)
                std::cout << f(x) << "\t";
            std::cout << '|' << std::endl;
            for (int i = 0; i < 8 * 12; i++)
                std::cout << '-';
            std::cout << std::endl;
            //----------------------------------------------------
            //-6    -5  -4  -3  -2  -1  0   1   2   3   4   5   |
            //----------------------------------------------------
            //-2    -4  -6  -4  -2  0   -2  6.5 8   9.5 11  12.5    |
            //----------------------------------------------------
            break;
        default:
            break;
        }

    }

    return 0;
}


int Quarter(float x, float y) {
    //10. Описать функцию Quarter(x, y) целого типа, определяющую номер координатной
    //четверти, в которой находится точка с ненулевыми вещественными координатами
    //(x, y).С помощью этой функции найти номера координатных четвертей для трех
    //точек с данными ненулевыми координатами.

    if (x > 0) {
        if (y > 0)
            return 1;
        else if (y < 0)
            return 4;
        else
            return 0;
    }
    else if (x < 0) {
        if (y > 0)
            return 2;
        else if (y < 0)
            return 3;
        else
            return 0;
    }
    else
        return 0;
}


double Leng(double xA, double yA, double xB, double yB) {
    return sqrt((xA - xB) * (xA - xB) + (yA - yB) * (yA - yB));
}

void ShiftLeft(float& a, float& b, float& c) {
    float temp = a;
    a = b;
    b = c;
    c = temp;
}
float f(float x) {
    //y = 1.5x + 5, если x > 0
    //y = -2, если x = 0
    //y = 2 * | x + 4 | -6, если x < 0

    if (x > 0)
        return 1.5 * x + 5;
    else if (x < 0)
        return 2 * fabs(x + 4) - 6;
    else
        return -2;
}

