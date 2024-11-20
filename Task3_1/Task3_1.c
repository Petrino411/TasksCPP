#include <corecrt_wctype.h>
#include <float.h>
#include <locale.h>
#include <math.h>
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
 * @return значение функции в точке x
 */
double get_y(const double x);

/**
 * @brief Функция ввода вещественного числа
 * @return вещественное число
 */
double double_input(void);

/**
 *  @brief  Ввод и проверка вещественного числа на положительность
 * @return  Вещественное число
 */
double get_positive_double(void);

/**
 * @brief Точка входа в программу
 * @returns 0 в случае успеха
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    puts("Нижняя граница");
    double bottom_limit = double_input();
    puts("Верхняя граница");
    double top_limit = double_input();
    puts("Шаг");
    const double delta = get_positive_double();
    print_table(bottom_limit, top_limit, delta);
    return 0;
}

void print_table(const double bottom_limit, const double top_limit, const double delta)
{
    for (double i = bottom_limit; i  <= top_limit + DBL_EPSILON; i += delta)
    {
        if (i <= DBL_EPSILON)
        {
            printf("Нет значения в точке %.2f\n", i);
        }
        else
        {
            const double y = get_y(i);
            printf("%.2f: %.2f\n", i, y);
        }
    }
}


double get_y(const double x)
{
    return 0.1 * pow(x, 2) - x * log10(x);
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

double get_positive_double(void)
{
    const double value = double_input();
    if (value < DBL_EPSILON)
    {
        abort();
    }
    return value;
}
