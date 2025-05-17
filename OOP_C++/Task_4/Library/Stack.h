#ifndef TASK_4_STACK_H
#define TASK_4_STACK_H

#include "StackItem.h"
#include <initializer_list>

/**
 * @brief Класс Stack
 */
class Stack {
    int capacity; /**@brief Максимальная ёмкость стека*/
    int count; /** @brief Текущий размер стека*/
    StackItem* top; /**@brief Указатель на верхний элемент стека*/

public:
    /**
     * @brief Конструктор класса Stack
     * @param size Размер стека
     */
    explicit Stack(int size);
    /**
     * @brief Конструктор класса Stack с инициализацией из списка
     * @param l Инициализирующий список элементов стека
     */
    Stack(std::initializer_list<StackItem> l);

    /**
     * @brief Конструктор копирования класса Stack
     * @param other
     */
    Stack(const Stack& other);

    /**
     * @brief Конструктор перемещения класса Stack
     * @param other
     */
    Stack(Stack&& other) noexcept;

    /**
     * @brief Оператор присваивания класса Stack
     * @param other
     * @return Ссылка на текущий объект
     */
    Stack& operator=(const Stack& other);

    /**
     * @brief Оператор перемещения присваивания класса Stack
     * @param other
     * @return Ссылка на текущий объект
     */
    Stack& operator=(Stack&& other) noexcept;

    /**
     * @brief Деструктор класса Stack
     */
    ~Stack();

    /**
     * @brief Добавить элемент в стек
     * @param x Целочисленное значение для добавления в стек
     * @return true, если элемент успешно добавлен; false в противном случае
     */
    bool push(int x);

    /**
     * @brief Добавить элемент в стек
     * @param item Элемент стека для добавления
     * @return true, если элемент успешно добавлен; false в противном случае
     */
    bool push(const StackItem& item);

    /**
     * @brief Удалить верхний элемент из стека
     * @return true, если элемент успешно удален; false в противном случае
     */
    bool pop();

    /**
     * @brief Вывод содержимого стека на экран
     */
    void display() const;

    /**
     * @brief Получить размер стека
     * @return Размер стека
     */
    int size() const;

    /**
     * @brief Проверить пуст ли стек
     * @return true, если стек пуст; false в противном случае
     */
    bool isEmpty() const;

    /**
     * @ Реализация swap между объектами Stack
     * @param first первый стек
     * @param second второй стек
     */
    void swap(Stack& first, Stack& second) noexcept;

    /**
     * @brief Очистить стек
     */
    void clearStack();
};

#endif //TASK_4_STACK_H
