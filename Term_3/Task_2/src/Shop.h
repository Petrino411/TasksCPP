#pragma once
#include <vector>
#include <string>
#include <ctime>
#include "Record.h"

/**
 * @class Shop
 * @brief Класс, описывающий деятельность овощного магазина.
 */
class Shop {
    std::vector<Record> records;
public:
    /**
     * @brief Добавляет новую запись о движении товара.
     *
     * Метод добавляет в журнал магазина информацию о поставке или продаже.
     *
     * @param record Объект Record, описывающий операцию.
     */
    void addRecord(const Record& record);

    /**
     * @brief Возвращает общий объём поступившего товара за указанный период.
     *
     * Учитывает только записи с типом TypeRecord::Supply.
     * При расчёте объёма используется только хорошая часть товара,
     * с учётом процента порчи.
     *
     * @param veg Товар (овощ), по которому ведётся расчёт.
     * @param from Начало периода (время в формате std::time_t).
     * @param to Конец периода (время в формате std::time_t).
     * @return Масса поставленного товара (в кг) за период.
     */
    double getIncoming(const Vegetable& veg, std::time_t from, std::time_t to) const;

    /**
     * @brief Возвращает общий объём проданного товара за указанный период.
     *
     * Учитывает только записи с типом TypeRecord::Sale.
     *
     * @param veg Товар (овощ), по которому ведётся расчёт.
     * @param from Начало периода (время в формате std::time_t).
     * @param to Конец периода (время в формате std::time_t).
     * @return Масса проданного товара (в кг) за период.
     */
    double getOutgoing(const Vegetable& veg, std::time_t from, std::time_t to) const;

    /**
     * @brief Возвращает прибыль по указанному товару за период.
     * Прибыль рассчитывается как разница между суммой продаж и себестоимостью поставок
     * @param veg Товар (овощ), по которому вычисляется прибыль.
     * @param from Начало периода (время в формате std::time_t).
     * @param to Конец периода (время в формате std::time_t).
     * @return Чистая прибыль без учёта налогов и издержек.
     */
    double getProfit(const Vegetable& veg, std::time_t from, std::time_t to) const;

    /**
     * @brief Возвращает средний процент испорченного товара для выбранного овоща за период.
     *
     * Учитывает только поставки (TypeRecord::Supply).
     *
     * @param name Название овоща.
     * @param from Начало периода.
     * @param to Конец периода.
     * @return Средний процент испорченного товара (0, если поставок не было).
     */
    double getSpoiledPercent(const std::string& name, std::time_t from, std::time_t to) const;

    /**
     * @brief Возвращает ассортимент доступных товаров на указанную дату.
     *
     * Ассортимент включает все товары, у которых есть хотя бы одна поставка,
     * совершённая до указанной даты.
     *
     * @param date Дата, на которую необходимо определить ассортимент.
     * @return Вектор объектов Vegetable, представляющих доступные товары.
     */
    std::vector<Vegetable> getAvailableAssortment(std::time_t date) const;
};
