#pragma once
#include "Vegetable.h"
#include "TypeRecord.h"
#include <ctime>

/**
 * @class Record
 * @brief Класс, описывающий запись о движении товара (поставка или продажа).
 */
class Record {
    Vegetable vegetable;
    TypeRecord typeRecord;
    double kilos;
    std::time_t date;
    double spoiledPercent;

public:
    /**
     * @brief Конструктор записи о товаре.
     *
     * @param veg Объект овоща, участвующего в операции.
     * @param type Тип записи (поставка или продажа).
     * @param kilos Масса товара (в кг).
     * @param date Дата операции.
     * @param spoiledPercent Процент испорченного товара от общей массы (по умолчанию 0.0).
     */
    Record(const Vegetable& veg, TypeRecord type, double kilos,
           std::time_t date, double spoiledPercent = 0.0);

    /**
     * @brief Возвращает объект товара, связанный с записью.
     * @return Константная ссылка на объект Vegetable.
     */
    const Vegetable& getVegetable() const;

    /**
     * @brief Возвращает тип записи (поставка или продажа).
     * @return Значение перечисления TypeRecord.
     */
    TypeRecord getTypeRecord() const;

    /**
     * @brief Возвращает массу товара (в кг), участвующую в операции.
     * @return Количество товара в килограммах.
     */
    double getKilos() const;

    /**
     * @brief Возвращает дату операции.
     * @return Время операции в формате std::time_t.
     */
    std::time_t getDate() const;

    /**
     * @brief Возвращает процент испорченного товара в поставке.
     *
     * Для продаж всегда возвращает 0.0.
     *
     * @return Процент испорченного товара от общей массы.
     */
    double getSpoiledPercent() const;

    /**
     * @brief Возвращает количество хорошего (неиспорченного) товара.
     *
     * Рассчитывается как:
     * `goodKilos = kilos * (1 - spoiledPercent / 100)`.
     *
     * @return Масса хорошего товара (в кг).
     */
    double getGoodKilos() const;
};
