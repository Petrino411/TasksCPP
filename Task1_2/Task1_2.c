#include <locale.h>
#include <stdio.h>

/**
 * @brief Переводит байты в мегабайты
 * @param bytes - количество байт
 * @return int - количество мегабайт
 */
float convert_to_MB(float bytes);

/**
 * @brief Переводит байты в гигабайты
 * @param bytes - количество байт
 * @return int - количество гигабайт
 */
float convert_to_GB(float bytes);

/**
 * @brief Точка входа в программу
 * @return 0
 */
int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "Rus");
    
    float enter_bytes = 0;
    printf("Введите байты: ");
    scanf_s("%f", &enter_bytes);
    if (enter_bytes != 0)
    {
        printf("МБ:%f\n", convert_to_MB(enter_bytes));
        printf("ГБ:%f\n", convert_to_GB(enter_bytes));
    }
    else
    {
        printf("Непредвиденная ошибка");
    }
    return 0;
    
}

float convert_to_MB(float bytes)
{
    return bytes / 1024;
}

float convert_to_GB(float bytes)
{
    return bytes / 1024 / 1024;
}