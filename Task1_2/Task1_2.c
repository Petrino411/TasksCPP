#include <locale.h>
#include <math.h>
#include <stdio.h>

/**
 * @brief Переводит байты в мегабайты
 * @param bytes - количество байт
 * @return double - количество мегабайт
 */
double convert_to_mb(int bytes);

/**
 * @brief Переводит байты в гигабайты
 * @param bytes - количество байт
 * @return double - количество гигабайт
 */
double convert_to_gb(int bytes);

/**
 * @brief Функция переводящая байты в мб и гб.
 * @return Код завершения программы
 */
int solution(void);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    solution();
}


int solution(void)
{
    int enter_bytes = 0;
    puts("Введите байты: ");
    if (scanf_s("%d", &enter_bytes) != 1)
    {
        puts("Ошибка ввода. Не удалось прочитать число.\n");
        return 1; 
    }

    printf("МБ: %lf\n", convert_to_mb(enter_bytes));
    printf("ГБ: %lf\n", convert_to_gb(enter_bytes));
    
    return 0;
    
}

double convert_to_mb(int bytes)
{
    return bytes / pow(2,10);
}

double convert_to_gb(int bytes)
{
    return bytes / (pow(2,10) * pow(2,10));
}