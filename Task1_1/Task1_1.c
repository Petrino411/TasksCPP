#include <math.h>
#include <stdio.h>

/**
* 
 * @param x const double
 * @param y const double
 * @param z const double 
 * @return Вычисляет занчение A
 */
double getA(double, double,double);
/**
 * 
 * @param x const double 
 * @param y const double 
 * @param z const double 
 * @return Вычисляет занчение B
 */
double getB(double, double,double);


/**
 * Точка входа в программу
 * @return 0
 */
int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;   
    printf("Task1 %f \n", getA(x,y,z));
    printf("Task2 %f \n", getB(x,y,z));
    return 0;
}

double getA(double x,double y, double z)
{
    return pow( sin(pow(x,2) + pow(y,2)),3) - sqrt(x/y);
}

double getB(double x,double y, double z)
{
    return pow(x,2)/z + pow(cos(x+y),3);
}