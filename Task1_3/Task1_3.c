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
 * @ Функция ввода целого числа
 * @return int
 */
int int_input();

/**
 * @brief Функция ввода вещественного числа
 * @return float
 */
float float_input();

/**
 * @brief Функция проверки целого числа
 * @return int
 */
int get_int();

/**
 * @brief Пытается выделить память
 * @param size размер массива
 * @return 
 */
float* try_allocate_memory(int size);


/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{

    puts("Enter the number of resistors: ");
    int size = get_int();

    float* resistors = try_allocate_memory(size);
        
    for (int i = 0; i < size; i++)
    {
        printf("Enter resistor #%d: ", i + 1);
        resistors[i] = float_input();
    }
    
    float resistance = count_r(resistors, size);
    printf("Total resistance: %f\n", resistance);
    
    free(resistors);
    
    return 0;
}


int get_int()
{
    int value = int_input();
    if (value < 1)
    {
        abort();
    }
    return value;
}

int int_input()
{
    int value = 0;
    if (scanf_s("%d", &value) != 1)
    {
        abort();
    }
    return value;
}

float float_input()
{
    float value = 0;
    if (scanf_s("%f", &value) != 1)
    {
        abort();
    }
    return value;
}

float* try_allocate_memory(int size)
{
    float* array = malloc(size * sizeof(float));
    if (array == NULL)
    {
        abort();
    }
    return array;
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
