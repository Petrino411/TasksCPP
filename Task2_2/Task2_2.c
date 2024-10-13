#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * @brief Вычисляет значение функции при x > 1
 * @param a константа а
 * @param x переменная x
 * @return Возвращает значение y
 */
double get_y1(double a, double x);

/**
 * @brief Вычисляет значение функции при x > 1
 * @param a константа а
 * @param x переменная x
 * @return Возвращает значение y
 */
double get_y2(double a, double x);

/**
 * @ Функция ввода вещестенного числа
 * @return double
 */
double double_input();

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    const double a = 0.9;
    setlocale(LC_ALL, "Rus");

    puts("Введите значение x:");

    double x = double_input();
    if (x > 1)
    {
        printf("Значение y: %lf\n", get_y1(a, x));
    }
    else
    {
        printf("Значение y: %lf\n", get_y2(a, x));
    }

    return 0;
}

double get_y1(double a, double x)
{
    return a * log10(x) + sqrt(fabs(x));
}

double get_y2(double a, double x)
{
    return 2 * a * cos(x) + 3 * pow(x, 3);
}


double double_input()
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        abort();
    }
    return value;
}