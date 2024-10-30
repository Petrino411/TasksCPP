#include <corecrt_wctype.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Выводит все значения функции
 * @param bottom_limit Нижняя граница
 * @param top_limit Верхняя граница 
 * @param delta шаг
 */
void print_table(const double bottom_limit, const double top_limit, const double delta);

/**
 * @brief Расчитывает значение функции в точке x
 * @param x 
 * @return double
 */
bool get_y(double* y, double x);

/**
 * @brief Функция ввода вещественного числа
 * @return double
 */
double double_input(void);

/**
 *  @brief  Ввод и проверка вещественного числа на положительность
 * @return  Вещественное число
 */
double get_double(void);

/**
 * @brief Точка входа в программу
 * @returns 0 в случае успеха
 */
int main(int argc, char* argv[])
{

    setlocale(LC_ALL, "Rus");
    double bottom_limit = double_input();
    double top_limit = double_input();
    double delta = get_double();
    print_table(bottom_limit, top_limit, delta);
    return 0;
}

void print_table(const double bottom_limit, const double top_limit, const double delta)
{
    for (double i = bottom_limit; i < top_limit; i += delta)
    {
        double y = 0;
        if(get_y(&y, i))
        {
            printf("%.2f: %.2f\n",i, y);
        }
        else
        {
            printf("Нет значения в точке %.2f\n", i);
        }
       
    }
}


bool get_y(double* y, const double x)
{
    *y = 0.1 * pow(x, 2) - x * log10(x);
    if (isnan(*y))
    {
        return false;
    }
    return true;
}

double double_input(void)
{
    double value = 0;
    if (scanf_s("%lf", &value) != 1)
    {
        abort();
    }
    return value;
}

double get_double(void)
{
    double value = double_input();
    if(value < 0)
    {
        abort();
    }
    return value;
}

