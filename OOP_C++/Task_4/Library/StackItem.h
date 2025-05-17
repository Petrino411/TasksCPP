#ifndef TASK_4_STACKITEM_H
#define TASK_4_STACKITEM_H

/**
 * Класс StackItem
 */
class StackItem
{
private:
    int data; /**@brief Целочисленное значение, хранящееся в элементе стека*/
    StackItem* next; /**@brief Указатель на следующий элемент стека*/
public:

    /**
     * @brief Конструктор класса StackItem
     * @param value Целочисленное значение для инициализации элемента стека
     */
    explicit StackItem(const int value);

    /**
     * @brief Получить данные элемента стека
     * @return Целочисленное значение, хранящееся в элементе стека
     */
    int getData() const;

    /**
     * @brief Получить следующий элемент стека
     * @return Указатель на следующий элемент стека
     */
    StackItem* getNext();

    /**
     * @brief Установить следующий элемент стека
     * @param next Указатель на следующий элемент стека
     */
    void setNext(StackItem* next);

};



#endif