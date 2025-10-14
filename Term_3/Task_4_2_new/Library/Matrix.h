#pragma once
#include <cstddef>
#include <string>
#include <stdexcept>
#include <memory>

namespace miit::algebra
{
    /**
     * @class Matrix
     * @brief Шаблонный класс, представляющий простую матрицу (вектор) фиксированного размера.
     * 
     * Класс обеспечивает базовые операции с данными, такие как копирование, перемещение,
     * доступ к элементам, заполнение генератором и преобразование в строку.
     * 
     * @tparam T Тип элементов матрицы (например, int, double и т.д.)
     */
    template<typename T>
    class Matrix
    {
        std::unique_ptr<T[]> data;  ///< Указатель на область памяти, хранящую элементы матрицы.
        size_t size;                ///< Размер матрицы (количество элементов).


    public:
        /**
         * @brief Конструктор по умолчанию.
         * 
         * Создаёт пустую матрицу с размером 0.
         */
        Matrix();

        /**
         * @brief Конструктор с заданным размером.
         * 
         * @param size Размер матрицы (количество элементов).
         * @throws std::invalid_argument Если размер равен 0.
         */
        explicit Matrix(size_t size);

        /**
         * @brief Конструктор копирования.
         * 
         * @param other Матрица, из которой выполняется копирование.
         */
        Matrix(const Matrix& other);

        /**
         * @brief Конструктор перемещения.
         * 
         * @param other Матрица, из которой выполняется перемещение данных.
         */
        Matrix(Matrix&& other) noexcept;

        /**
         * @brief Оператор копирующего присваивания.
         * 
         * @param other Матрица, из которой выполняется копирование.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(const Matrix& other);

        /**
         * @brief Оператор перемещающего присваивания.
         * 
         * @param other Матрица, из которой выполняется перемещение данных.
         * @return Ссылка на текущий объект.
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Доступ к элементу матрицы по индексу.
         * 
         * @param index Индекс элемента.
         * @return Ссылка на элемент по указанному индексу.
         * @throws std::out_of_range Если индекс выходит за границы матрицы.
         */
        T& operator[](size_t index);

        /**
         * @brief Константный доступ к элементу матрицы по индексу.
         * 
         * @param index Индекс элемента.
         * @return Константная ссылка на элемент по указанному индексу.
         * @throws std::out_of_range Если индекс выходит за границы матрицы.
         */
        const T& operator[](size_t index) const;

        /**
         * @brief Добавление значения в матрицу (пример перегрузки оператора).
         * 
         * @param value Значение, добавляемое в матрицу.
         * @return Ссылка на текущий объект (для цепочки вызовов).
         */
        Matrix& operator<<(const T& value);

        /**
         * @brief Извлечение значения из матрицы (пример перегрузки оператора).
         * 
         * @param value Значение, в которое производится извлечение.
         * @return Ссылка на текущий объект (для цепочки вызовов).
         */
        Matrix& operator>>(const T& value);

        /**
         * @brief Заполнение матрицы с использованием генератора.
         * 
         * @param gen Объект генератора, реализующий интерфейс класса Generator.
         */
        void fill(class Generator& gen);

        /**
         * @brief Преобразует матрицу в строковое представление.
         * 
         * @return Строка, содержащая элементы матрицы.
         */
        std::string toString() const;

        /**
         * @brief Получить размер матрицы.
         * 
         * @return Количество элементов матрицы.
         */
        size_t getSize() const { return size; }

        /**
         * @brief Получить указатель на внутренние данные.
         * 
         * @return Указатель на массив элементов матрицы.
         */
        T* getData() const { return data.get(); }
    };
}

#include "Matrix.cpp"
