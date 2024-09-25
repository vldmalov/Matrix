#pragma once

#include <iosfwd>
#include <utility>
#include <initializer_list>

struct Matrix {
public:
    Matrix() = delete;
    Matrix(unsigned rows, unsigned columns, float itemValue = 0.f);
    Matrix(unsigned rows, unsigned columns, std::initializer_list<float> values);
    Matrix(const Matrix& another);
    ~Matrix();

    Matrix& operator=(const Matrix& another);

    std::pair<unsigned, unsigned> GetSize() const;

    float& operator()(unsigned i, unsigned j);
    const float& operator()(unsigned i, unsigned j) const;

    Matrix& operator+=(const Matrix& another);
    Matrix& operator-=(const Matrix& another);
    Matrix& operator*=(float scalar);

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& matrix, float scalar);
    friend Matrix operator*(float scalar, const Matrix& matrix);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    unsigned mRows{0};
    unsigned mColumns{0};
    float* mData{nullptr};
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& matrix, float scalar);
Matrix operator*(float scalar, const Matrix& matrix);

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
