#pragma once
#include <cstddef>
#include <string>
#include <stdexcept>
#include <memory>

namespace miit::algebra
{
    template<typename T>
    class Matrix
    {
        std::unique_ptr<T[]> data;
        size_t size;

    public:
        Matrix();
        explicit Matrix(size_t size);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;

        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        Matrix& operator<<(const T& value);
        Matrix& operator>>(const T& value);

        void fill(class Generator& gen);
        std::string toString() const;

        size_t getSize() const { return size; }
        T* getData() const { return data.get(); }
    };
}

#include "Matrix.cpp"