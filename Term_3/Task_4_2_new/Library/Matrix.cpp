#include "Matrix.h"
#include <sstream>
#include <memory>

#include "Generator.h"

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : data(nullptr), size(0) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size)
    {
        data = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i)
            data[i] = T{};
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size)
    {
        data = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i)
            data[i] = other.data[i];
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : data(std::move(other.data)), size(other.size)
    {
        other.size = 0;
    }


    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this == &other) return *this;

        auto new_data = std::make_unique<T[]>(other.size);
        for (size_t i = 0; i < other.size; ++i)
            new_data[i] = other.data[i];

        data = std::move(new_data);
        size = other.size;
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this == &other) return *this;

        data = std::move(other.data);
        size = other.size;
        other.size = 0;
        return *this;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator<<(const T& value)
    {
        for (size_t i = 0; i + 1 < size; ++i)
            data[i] = data[i + 1];
        data[size - 1] = value;
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator>>(const T& value)
    {
        for (size_t i = size - 1; i > 0; --i)
            data[i] = data[i - 1];
        data[0] = value;
        return *this;
    }

    template<typename T>
    void Matrix<T>::fill(Generator& gen)
    {
        for (size_t i = 0; i < size; ++i)
            data[i] = gen.generate();
    }

    template<typename T>
    std::string Matrix<T>::toString() const
    {
        std::ostringstream out;
        for (size_t i = 0; i < size; ++i)
            out << data[i] << ' ';
        return out.str();
    }
}