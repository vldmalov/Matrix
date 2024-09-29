#pragma once

#include <iosfwd>
#include <utility>
#include <initializer_list>

struct MatrixSize {
    unsigned rows{ 0 };
    unsigned columns{ 0 };

    MatrixSize(unsigned rows, unsigned columns) : rows(rows), columns(columns) {}
};

bool operator==(const MatrixSize& lhs, const MatrixSize& rhs);
bool operator!=(const MatrixSize& lhs, const MatrixSize& rhs);

struct Matrix {
public:
    Matrix() = delete;
    Matrix(unsigned rows, unsigned columns, float itemValue = 0.f);
    Matrix(unsigned rows, unsigned columns, std::initializer_list<float> values);
    Matrix(const Matrix& another);
    ~Matrix();

    Matrix& operator=(const Matrix& another);

    MatrixSize GetSize() const;

    float& operator()(unsigned i, unsigned j);
    const float& operator()(unsigned i, unsigned j) const;

    Matrix Transposition() const;

    Matrix& operator+=(const Matrix& another);
    Matrix& operator-=(const Matrix& another);
    Matrix& operator*=(float scalar);

    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator-(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);
    friend Matrix operator*(const Matrix& matrix, float scalar);
    friend Matrix operator*(float scalar, const Matrix& matrix);

    friend bool operator==(const Matrix& lhs, const Matrix& rhs);
    friend bool operator!=(const Matrix& lhs, const Matrix& rhs);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    MatrixSize mSize;
    float* mData{nullptr};
};

Matrix operator+(const Matrix& lhs, const Matrix& rhs);
Matrix operator-(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& lhs, const Matrix& rhs);
Matrix operator*(const Matrix& matrix, float scalar);
Matrix operator*(float scalar, const Matrix& matrix);

bool operator==(const Matrix& lhs, const Matrix& rhs);
bool operator!=(const Matrix& lhs, const Matrix& rhs);

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
