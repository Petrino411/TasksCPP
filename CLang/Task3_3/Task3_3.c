#include <float.h>
#include <locale.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief Рассчитывает сумму на области определения 
 * @param x Значение x
 * @param eps погрешность
 * @return Сумма на области определения x 
 */
long double sum_series(const double x, const long double eps);

/**
 * @brief Функция ввода вещественного числа
 * @return Вещественное число
 */
double double_input(void);

/**
 *  @brief  Ввод и проверка вещественного числа на положительность
 * @return  Вещественное число
 */
double get_positive_double(void);

/**
 * @brief Точка входа в программу
 * @return 0 в случае успеха
 */
int main(void)
{
    setlocale(LC_ALL, "Rus");
    puts("Введите a, b, h, eps\n");
    const double a = get_positive_double();
    const double b = get_positive_double();
    const double h = get_positive_double();
    const double eps = get_positive_double();

    printf(" x\t e^(2x)\t\t S(x)\n");
    printf("-------------------------------\n");

    for (double x = a; x < b + h; x += h)
    {
        const long double func_val = expl(2 * x);
        const long double series_sum = sum_series(x, eps);

        printf("%0.1f\t%0.10Lf\t%0.10Lf\n", x, func_val, series_sum);
    }
    return 0;
}

long double sum_series(const double x, const long double eps)
{
    long double curr = 1.0;
    long double sum = 0;
    int n = 1;

    while (fabsl(curr) >= eps - DBL_EPSILON)
    {
        sum += curr;
        curr *= 2 * x / n;
        n++;
    }

    return sum;
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
    double value = double_input();
    if (value < 0)
    {
        abort();
    }
    return value;
}
