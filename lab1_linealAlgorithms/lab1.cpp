//СевГУ
//УТС/б-24-1-о
//Приходько Александр

#define _USE_MATH_DEFINES 
#include <iostream>
#include <cmath>
#include <string>

float task14a(float priceForCookies, float priceForCandies) {
    return (0.3 * priceForCookies) + (0.4 * priceForCandies);
}
float task14b(float priceForCookies, float priceForCandies) {
    return 3 * ((2 * priceForCookies) + (1.8 * priceForCandies));
}
int main1() {
    setlocale(LC_ALL, "RU");
    std::cout << "Вариант 11\n\n";
    //1. Вывести на экран Первую букву имени из символов "*" (звездочка)
    std::cout << "Задача 1.\n1. Вывести на экран Первую букву имени из символов '*' (звездочка)\n";
    std::cout << "\t ***** \n";
    std::cout << "\t*     *\n";
    std::cout << "\t*      \n";
    std::cout << "\t*     *\n";
    std::cout << "\t ***** \n";
    std::cout << "\n\n";

    //2. Пользователь вводит параметры фигуры. Найти периметр и площадь фигур:
    //f. Салинон
    std::cout << "Задача 2.\nПользователь вводит параметры фигуры. Найти периметр и площадь фигур:\nf. Салинон\n";
    float r1, r2;
    std::cout << "R1 << "; std::cin >> r1;
    std::cout << "R2 << "; std::cin >> r2;
    float s = M_PI * (r1 + r2) * (r1 + r2) / 4;
    std::cout << "S = " << s << std::endl;
    float p = (3 * M_PI * r2) - (M_PI * r1);
    std::cout << "P = " << p << std::endl << std::endl;
    std::cout << "\n\n";


    //4. Пользователь вводит два числа. Необходимо поменять значения переменных так,
    //чтобы значение первой оказалось во второй, а второй - в первой.
    std::cout << "Задача 3.\nПоменять числа местами\n";
    float a, b;
    std::cout << "a << "; std::cin >> a;
    std::cout << "b << "; std::cin >> b;
    float t = a; a = b; b = t;
    std::cout << "a = " << a << "\tb = " << b << std::endl;
    std::cout << "\n\n";


    //8. Вычислите значение выражения:
    //   e. e ^ (x - 2) + |sin(x)| - x^4 * cos(1/x)
    //   при x=3.6 Ответ: -156.1276 (проверено!)
    std::cout << "Задача 4.\nВычислите значение выражения:\ne ^ (x - 2) + |sin(x)| - x^4 * cos(1/x)\nпри x=3.6 Ответ: -156.1276 (проверено!)\n"; 
    double x = 3.6;
    double ansver = exp(x - 2) + fabs(sin(x)) - (x * x * x * x * cos(1 / x));
    if (ansver == -156.1276) {
        std::cout <<"e ^ (x - 2) + |sin(x)| - x^4 * cos(1/x) = " << ansver << " = -156.1276" << std::endl;
    }
    else {
        std::cout << "e ^ (x - 2) + |sin(x)| - x^4 * cos(1/x) = " << ansver << " != -156.1276" << std::endl;
    }
    std::cout << "\n\n";


    //9. Сделать конвертер величин. Формат ввода: Направление_Перевода Величина.
    // k. Информация (байты, килобайты, биты, мегабайты, дискеты)
    std::cout << "Задача 5.\nКонвертер информации\n";
    float cnt;
    float cnt1;
    std::string type;
    std::cout << "count (bit / byte / Kbyte / Mbyte / disk) << "; std::cin >> cnt; std::cin >> type;
    
    if (type ==  "bit") cnt1 = cnt;
    else if (type == "byte")  cnt1 = cnt * 8; 
    else if (type == "Kbyte")  cnt1 = cnt * 8192;
    else if (type == "Mbyte") cnt1 = cnt * 8388608;
    else if (type == "disk") cnt1 = cnt * 5830656;
    else cnt1 = 0;
    std::cout << cnt1 << " bits" << std::endl;
    std::cout << cnt1 / 8 << " bytes" << std::endl;
    std::cout << cnt1 / 8192 << " Kbytes" << std::endl;
    std::cout << cnt1 / 8388608 << " Mbytes" << std::endl;
    std::cout << cnt1 / 5830656 << " floppy disks" << std::endl;
    std::cout << "\n\n";


    // 14. Пользователь вводит цены 1 кг конфет и 1 кг печенья. Найдите стоимость: а) одной
    //     покупки из 300 г конфет и 400 г печенья; б) трех покупок, каждая из 2 кг печенья и
    //     1 кг 800 г конфет.
    //     Организовать предыдущее задание с помощью функций.
    std::cout << "Задача 6.\nСтоимость покупки.\n";
    float priceForCookies, priceForCandies;
    std::cout << "Price of cookies << "; std::cin >> priceForCookies;
    std::cout << "Price of candies << "; std::cin >> priceForCandies;
    std::cout << "300g of cookies and 400g of candies cost " << task14a(priceForCookies, priceForCandies) << std::endl;
    std::cout << "6kg of cookies and 5kg 400g of candies cost " << task14b(priceForCookies, priceForCandies) << std::endl;
    return 0;
}
