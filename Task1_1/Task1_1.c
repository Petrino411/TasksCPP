#include <math.h>
#include <stdio.h>

/**
* @brief Расчитывает значение A
 * @param x const double
 * @param y const double
 * @param z const double 
 * @return Вычисляет значение A
 */
double get_a(double x, double y, double z);

/**
 * @brief Расчитывает значение B
 * @param x const double 
 * @param y const double 
 * @param z const double 
 * @return Вычисляет значение B
 */
double get_b(double x, double y, double z);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;
    printf("Task1 %f \n", get_a(x, y, z));
    printf("Task2 %f \n", get_b(x, y, z));
    return 0;
}

double get_a(double x, double y, double z)
{
    return pow(sin(pow(x, 2) + pow(z, 2)), 3) - sqrt(x / y);
}

double get_b(double x, double y, double z)
{
    return pow(x, 2) / z + pow(cos(x + y), 3);
}
