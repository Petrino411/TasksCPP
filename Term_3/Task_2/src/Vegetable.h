#pragma once
#include <string>

/**
 * @brief Класс, представляющий овощ как товар магазина.
 *
 */
class Vegetable {
    std::string name;
    double price;

public:
    /**
     * @brief Конструктор с параметрами.
     * @param name Название овоща.
     * @param price Цена за килограмм.
     */
    Vegetable(const std::string& name, double price);

    /**
     * @brief Получить название овоща.
     * @return Ссылка на строку с названием.
     */
    const std::string& getName() const;

    /**
     * @brief Получить цену овоща за килограмм.
     * @return Цена в условных единицах.
     */
    double getPrice() const;

    /**
     * @brief Установить новое название овоща.
     * @param n Новое название.
     */
    void setName(const std::string& n);

    /**
     * @brief Установить новую цену овоща.
     * @param p Новая цена в условных единицах.
     */
    void setPrice(double p);
};