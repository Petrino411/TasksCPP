#pragma once
#include <ostream>

/**
 * @brief Класс, представляющий точку в трёхмерном пространстве.
 */
class Point
{
private:
    double x;
    double y;
    double z;

public:
    /**
     * @brief Конструктор по умолчанию. Инициализирует точку в начале координат (0, 0, 0).
     */
    Point();

    /**
     * @brief Конструктор с параметрами.
     * @param x Координата X.
     * @param y Координата Y.
     * @param z Координата Z.
     */
    Point(double x, double y, double z);

    /**
     * @brief Получить координату X точки.
     * @return Значение координаты X.
     */
    double getX() const;

    /**
     * @brief Получить координату Y точки.
     * @return Значение координаты Y.
     */
    double getY() const;

    /**
     * @brief Получить координату Z точки.
     * @return Значение координаты Z.
     */
    double getZ() const;

    /// @brief Выводит координаты точки в поток.
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

/**
 * @brief Проверка равенства двух точек.
 * @param point1 Первая точка.
 * @param point2 Вторая точка.
 * @return true, если точки равны, иначе false.
 */
bool operator==(const Point& point1, const Point& point2);

/**
 * @brief Проверка неравенства двух точек.
 * @param point1 Первая точка.
 * @param point2 Вторая точка.
 * @return true, если точки не равны, иначе false.
 */
bool operator!=(const Point& point1, const Point& point2);
