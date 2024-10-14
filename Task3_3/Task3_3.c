#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * 
 * @param x Значение x
 * @param eps погрешность
 * @return Сумма на области определения x 
 */
long double sum_series(double x, long double eps);

/**
 * @ Функция ввода вещественного числа
 * @return double
 */
double double_input(void);

/**
 * Точка входа в программу
 * @return 0
 */
int main()
{
    puts("Введите a, b, h, eps\n");
    const double a = double_input();
    const double b = double_input();
    const double h = double_input();
    const double eps = double_input();

    printf(" x\t e^(2x)\t\t S(x)\n");
    printf("-------------------------------\n");


    for (double x = a; x < b+h; x += h)
    {
        long double func_val = expl(2 * x);
        long double series_sum = sum_series(x, eps);

        printf("%0.1f\t%0.10Lf\t%0.10Lf\n", x, func_val, series_sum);
    }

    return 0;
}

long double sum_series(double x, long double eps)
{
    long double curr = 1.0;
    long double sum = 0;
    int n = 1;

    while (fabsl(curr) >= eps)
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
