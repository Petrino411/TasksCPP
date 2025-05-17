#ifndef TASK_3_СONSTRAINT_H
#define TASK_3_СONSTRAINT_H


#include <string>

/**
 * @brief Абстрактный класс Ограничение
 */
class Сonstraint {
public:
    /**
     * @brief Сереализация в строку
     * @return string
     */
    virtual std::string ToString() const = 0;

    /**
     * @brief Деструктор
     */
    virtual ~Сonstraint() = default;

    /**
     * @brief Чтение из потока ввода
     * @param in поток ввода
     */
    virtual void ReadFrom(std::istream &in) = 0;

    /**
     * @brief Оператор ввода
     * @param in поток воода
     * @param obj ссылка на объект
     * @return  поток воода
     */
    friend std::istream &operator>>(std::istream &in, Сonstraint &obj);
};


#endif //TASK_3_СONSTRAINT_H
