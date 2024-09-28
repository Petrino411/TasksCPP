#include <math.h>
#include <stdio.h>

void printTable();
double getY(double x);
int factorial(int n);

int main(int argc, char* argv[])
{
    // printTable();
    printf("%d\n", factorial(10));
    return 0;
}

void printTable()
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

int factorial(int n)
{
    if (n == 0) return 1;
    return n * factorial(n - 1);
}
