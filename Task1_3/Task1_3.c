#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вычисляет общее сопротивление последовательно соединенных резисторов
 * @param resistors массив float 
 * @param size Количество сопротивлений
 * @return 
 */
float count_r(const float* resistors, int size);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    int n = 0;
    float* resistors;
    puts("Enter the number of resistors: ");
    if (!scanf_s("%d", &n))
    {
        puts("Invalid input\n");
        return 1;
    }

    resistors = (float*)malloc(n * sizeof(float));
    if (resistors == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter resistor #%d: ", i + 1);
        if (scanf_s("%f", &resistors[i]) != 1)
        {
            printf("Invalid input for resistor #%d\n", i + 1);
            free(resistors);
            return 1;
        }
    }
    
    float resistance = count_r(resistors, n);
    printf("Total resistance: %f\n", resistance);
    
    free(resistors);
    
    return 0;
}

float count_r(const float* resistors, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += resistors[i];
    }
    return sum;
}
