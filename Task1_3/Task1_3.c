#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Вычисляет общее сопротивление последовательно соединенных резисторов
 * @param resistors массив float 
 * @param size количество сопротивлений
 * @return 
 */
float count_R(const float* resistors, int size);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    int n = 0;
    float* resitors;
    printf("Enter the number of resistors: ");
    if (scanf_s("%d", &n))
    {
        resitors = (float*)malloc(n * sizeof(float));
        for (int i = 0; i < n; i++)
        {
            printf("Enter resitor #%d: ", i + 1);
            if (!scanf_s("%f", &resitors[i]))
            {
                printf("Invalid input\n");
            }
        }
        float resistance = count_R(resitors, n);
        printf("Resistance: %f\n", resistance);
        free(resitors);
    }
    else
    {
        printf("Invalid input\n");
    }
    return 0;
}

float count_R(const float* resistors, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += resistors[i];
    }
    return sum;
}
