#include <math.h>
#include <stdio.h>


double task1(double, double,double);
double task2(double, double,double);

int main()
{
    const double x = 0.2;
    const double y = 0.004;
    const double z = 1.1;   
    printf("Task1 %f \n", task1(x,y,z));
    printf("Task2 %f \n", task2(x,y,z));
}
/**
* 
 * @param x 
 * @param y 
 * @param z 
 * @return double
 */
double task1(double x,double y, double z)
{
    return pow( sin(pow(x,2) + pow(y,2)),3) - sqrt(x/y);
}
/**
 * 
 * @param x 
 * @param y 
 * @param z 
 * @return double
 */
double task2(double x,double y, double z)
{
    return pow(x,2)/z + pow(cos(x+y),3);
}