#include <stdio.h>
#include <math.h>


long double sum_series(double x, long double eps) {
    long double term = 1.0;  
    long double sum = term;  
    int n = 1;
    
    while (fabsl(term) >= eps) {
        term *= (2 * x) / n;  
        sum += term;  
        n++;
    }
    
    return sum;
}

int main() {
    const double a = 0.1;  
    const double b = 1.0;  
    const double h = 0.1;  
    const long double eps = 0.00000625; 
    
    printf(" x\t e^(2x)\t\t S(x)\n");
    printf("-------------------------------\n");
    

    for (double x = a; x <= b; x += h) {
        long double func_val = expl(2 * x);  
        long double series_sum = sum_series(x, eps);  
        
        // Выводим результат
        printf("%0.1f\t%0.10Lf\t%0.10Lf\n", x, func_val, series_sum);
    }
    
    return 0;
}
