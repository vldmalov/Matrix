#include "Matrix.h"

#include <iostream>
#include <stdexcept>

// MatrixSize
bool operator==(const MatrixSize& lhs, const MatrixSize& rhs) {
    return lhs.rows == rhs.rows && lhs.columns == rhs.columns;
}

bool operator!=(const MatrixSize& lhs, const MatrixSize& rhs) {
    return !(lhs == rhs);
}

// Matrix
Matrix::Matrix(unsigned rows, unsigned columns, float itemValue)
: mSize(rows, columns) {
    if(mSize.rows == 0 || mSize.columns == 0) {
        throw std::invalid_argument("Matrix sizes should be grater than 0");
    }

    mData = new float[mSize.rows * mSize.columns];
    std::fill(mData, mData + mSize.rows * mSize.columns, itemValue);
}

Matrix::Matrix(const Matrix& another)
: mSize(another.mSize) {
    mData = new float[mSize.rows * mSize.columns];
    std::copy(another.mData, another.mData + mSize.rows * mSize.columns, mData);
}

Matrix::Matrix(unsigned rows, unsigned columns, std::initializer_list<float> values)
: mSize(rows, columns) {
    if (mSize.rows == 0 || mSize.columns == 0) {
        throw std::invalid_argument("Matrix sizes should be grater than 0");
    }

    if (mSize.rows * mSize.columns != values.size()) {
        throw std::invalid_argument("Matrix size doesn't correspond to size of initializer list");
    }

    mData = new float[mSize.rows * mSize.columns];
    std::copy(values.begin(), values.end(), mData);
}

Matrix::Matrix(unsigned rows, unsigned columns, std::span<float> values)
: mSize(rows, columns) {
    if (mSize.rows == 0 || mSize.columns == 0) {
        throw std::invalid_argument("Matrix sizes should be grater than 0");
    }

    if (mSize.rows * mSize.columns != values.size()) {
        throw std::invalid_argument("Matrix size doesn't correspond to size of initializer list");
    }

    mData = new float[mSize.rows * mSize.columns];
    std::copy(values.begin(), values.end(), mData);
}

Matrix::~Matrix() {
    if(mData) {
        delete [] mData;
        mData = nullptr;
    }
}

Matrix& Matrix::operator=(const Matrix& another) {
    if(this == &another) {
        return *this;
    }

    mSize = another.mSize;
    float* newData = new float[mSize.rows * mSize.columns];
    std::swap(mData, newData);
    delete [] newData;

    std::copy(another.mData, another.mData + mSize.rows * mSize.columns, mData);
    return *this;
}

MatrixSize Matrix::GetSize() const {
    return mSize;
}

float& Matrix::operator()(unsigned i, unsigned j) {
    return mData[i * mSize.columns + j];
}

const float& Matrix::operator()(unsigned i, unsigned j) const {
    return mData[i * mSize.columns + j];
}

Matrix Matrix::Transposition() const {
    Matrix result(mSize.columns, mSize.rows);
    for(unsigned i = 0; i < mSize.rows; ++i) {
        for(unsigned j = 0; j < mSize.columns; ++j) {
            result(j, i) = this->operator()(i, j);
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& another) {
    if(mSize != another.mSize) {
        throw std::invalid_argument("Matrices should have the same size");
    }

    for(unsigned idx = 0; idx < mSize.rows*mSize.columns; ++idx) {
        *(mData + idx) += *(another.mData + idx);
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& another) {
    if(mSize != another.mSize) {
        throw std::invalid_argument("Matrices should have the same size");
    }

    for(unsigned idx = 0; idx < mSize.rows*mSize.columns; ++idx) {
        *(mData + idx) -= *(another.mData + idx);
    }
    return *this;
}

Matrix& Matrix::operator*=(float scalar) {
    for(unsigned idx = 0; idx < mSize.rows*mSize.columns; ++idx) {
        *(mData + idx) *= scalar;
    }
    return *this;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    result += rhs;
    return result;
}

Matrix operator-(const Matrix& lhs, const Matrix& rhs) {
    Matrix result(lhs);
    result -= rhs;
    return result;
}

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
    if(lhs.mSize.columns != rhs.mSize.rows) {
        throw std::invalid_argument("Matrices sizes should correspond to each other");
    }
    unsigned rowsNumber = lhs.mSize.rows;
    unsigned columnsNumber = rhs.mSize.columns;
    unsigned internalSize = lhs.mSize.columns;

    Matrix result(rowsNumber, columnsNumber);
    for(unsigned i = 0; i < rowsNumber; ++i) {
        for(unsigned j = 0; j < columnsNumber; ++j) {
            for(unsigned k = 0; k < internalSize; ++k) {
                result(i, j) += lhs(i, k) * rhs(k, j);
            }
        }
    }
    return result;
}

Matrix operator*(const Matrix& matrix, float scalar) {
    Matrix result(matrix);
    result *= scalar;
    return result;
}

Matrix operator*(float scalar, const Matrix& matrix) {
    return operator*(matrix, scalar);
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if(lhs.mSize != rhs.mSize) {
        return false;
    }

    for(unsigned idx = 0; idx < lhs.mSize.rows * lhs.mSize.columns; ++idx) {
        if(*(lhs.mData + idx) != *(rhs.mData + idx)) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Matrix& lhs, const Matrix& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    os << "Matrix size: (" << matrix.mSize.rows << "; " << matrix.mSize.columns << ")" << std::endl;
    for(unsigned i = 0; i < matrix.mSize.rows; ++i) {
        os << "[ ";
        for(unsigned j = 0; j < matrix.mSize.columns; ++j) {
            os << matrix(i, j) << " ";
        }
        os << "]" << std::endl;
    }

    return os;
}
