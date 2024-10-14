#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Выводит все значения функции
 * @param bottom_limit нижняя граница
 * @param top_limit верхняя граница 
 * @param delta шаг
 */
void printTable(const double bottom_limit, const double top_limit, const double delta);

/**
 * @brief Расчитывает значение функции в точке x
 * @param x 
 * @return double
 */
double getY(const double x);

double double_input(void);


int main(int argc, char* argv[])
{
    double bottom_limit = double_input();
    double top_limit = double_input();
    double delta = double_input();
    printTable(bottom_limit, top_limit, delta);
    return 0;
}

void printTable(const double bottom_limit, const double top_limit, const double delta)
{
    for (double i = 0.1; i < 2.1; i += 0.1)
    {
        printf("%.2f: %.2f\n",i, getY(i));
    }
}


double getY(double x)
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


