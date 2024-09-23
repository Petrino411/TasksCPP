#include <locale.h>
#include <math.h>
#include <stdio.h>

const double a = 0.9;

/**
 * @brief Вычисляет значение системы функций
 * @param x переменная x
 * @return Возвращает значение y
 */
double get_y(double x);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    double x = 0;

    printf("Введите значение x: \n");
    if (scanf_s("%lf", &x))
    {
        printf("Значение y: %lf\n", get_y(x));
    }
    else
    {
        printf("Ошибка ввода\n");
    }
    
    return 0;
}

double get_y(double x)
{
    if (x > 1)
    {
        return a * log10(x) + sqrt(fabs(x));
    }
    if (x <= 1)
    {
        return 2 * a * cos(x) + 3 * pow(x, 3);
    }
    return 0;
}
