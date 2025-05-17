#pragma once
#include "Point.h"

/**
 * @brief Класс, представляющий цилиндр в трёхмерном пространстве.
 */
class Cylinder
{
private:
    Point center;
    double radius;
    double height;

public:
    /**
    * @brief Конструктор по умолчанию.
    */
    Cylinder() = default;

    /**
     * @brief Конструктор с параметрами.
     * @param p Центр основания цилиндра.
     * @param r Радиус цилиндра.
     * @param h Высота цилиндра.
     */
    Cylinder(const Point& p, const double& r, const double& h);

    /**
     * Геттер центр
     * @return Center
     */
    Point getCenter() const;

    /**
     * Геттер радиус
     * @return double
     */
    double getRadius() const;

    /**
     * Геттер высота
     * @return double
     */
    double getHeight() const;

    /**
     * @brief Вычисление объёма цилиндра.
     * @return Объём цилиндра.
     */
    double volume() const;

    /**
     * @brief Проверка, находится ли точка внутри цилиндра.
     * @param p Точка для проверки.
     * @return true, если точка внутри цилиндра, иначе false.
     */
    bool isInside(const Point& p) const;

    /// @brief Выводит инфоромацию о цилиндре в поток
    friend std::ostream& operator<<(std::ostream& os, const Cylinder& cylinder);

};