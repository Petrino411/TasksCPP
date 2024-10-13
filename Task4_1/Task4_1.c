#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100  // Максимальный размер массива

// Определение перечисления для выбора способа заполнения массива
typedef enum {
    RANDOM_FILL = 1,   // Заполнение случайными числами
    MANUAL_FILL = 2    // Заполнение с клавиатуры
} FillMethod;

// Функция для заполнения массива случайными числами в диапазоне [-40; 40]
void fill_array_random(int *arr, int n) {
    srand(time(0));  // Инициализация генератора случайных чисел
    for (int i = 0; i < n; i++) {
        *(arr + i) = (rand() % 81) - 40;  // Случайное число в диапазоне [-40, 40]
    }
}

// Функция для заполнения массива с клавиатуры
void fill_array_manual(int *arr, int n) {
    printf("Введите %d целых чисел:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Элемент %d: ", i + 1);
        scanf("%d", arr + i);
    }
}

// Функция для нахождения суммы элементов по модулю меньше 10
int sum_of_elements_less_than_10(const int *arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (abs(*(arr + i)) < 10) {
            sum += *(arr + i);
        }
    }
    return sum;
}

// Функция для вывода индексов элементов, которые больше последующего элемента
void print_indices_greater_than_next(const int *arr, int n) {
    printf("Индексы элементов, которые больше следующего:\n");
    for (int i = 0; i < n - 1; i++) {
        if (*(arr + i) > *(arr + i + 1)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Функция для умножения элементов массива, кратных 3, на третий элемент массива
void multiply_by_third_element(int *arr, int n) {
    if (n < 3) {
        printf("Недостаточно элементов для умножения на третий элемент (массив должен содержать минимум 3 элемента).\n");
        return;
    }
    
    int third_element = *(arr + 2);  // Третий элемент массива
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 3 == 0) {
            *(arr + i) *= third_element;
        }
    }
}

int main() {
    int n;
    int arr[MAX_SIZE];
    int choice;

    // Ввод размера массива
    printf("Введите количество элементов массива (не более %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Ввод выбора метода заполнения массива через enum
    printf("Выберите способ заполнения массива:\n");
    printf("1. Заполнить случайными числами\n");
    printf("2. Заполнить с клавиатуры\n");
    scanf("%d", &choice);

    FillMethod fill_method = (FillMethod)choice;  // Преобразование выбора в enum

    // В зависимости от выбора вызываем соответствующую функцию
    if (fill_method == RANDOM_FILL) {
        fill_array_random(arr, n);
    } else if (fill_method == MANUAL_FILL) {
        fill_array_manual(arr, n);
    } else {
        printf("Неверный выбор!\n");
        return 1;
    }

    // Вывод исходного массива
    printf("Исходный массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    // Задание 1: Найти сумму элементов, значения которых по модулю меньше 10
    int sum = sum_of_elements_less_than_10(arr, n);
    printf("Сумма элементов, значения которых по модулю меньше 10: %d\n", sum);

    // Задание 2: Вывести индексы элементов, которые больше последующего
    print_indices_greater_than_next(arr, n);

    // Задание 3: Умножить все элементы массива, кратные 3, на третий элемент массива
    multiply_by_third_element(arr, n);

    // Вывод измененного массива
    printf("Массив после умножения элементов, кратных 3, на третий элемент:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    return 0;
}
