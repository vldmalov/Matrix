#include "Matrix.h"

#include <iostream>
#include <stdexcept>

Matrix::Matrix(unsigned rows, unsigned columns, float itemValue)
: mRows(rows)
, mColumns(columns){
    if(mRows == 0 || mColumns == 0) {
        throw std::invalid_argument("Matrix sizes should be grater than 0");
    }

    mData = new float[mRows * mColumns];
    std::fill(mData, mData + mRows * mColumns, itemValue);
}

Matrix::Matrix(const Matrix& another)
: mRows(another.mRows)
, mColumns(another.mColumns){
    mData = new float[mRows * mColumns];
    std::copy(another.mData, another.mData + mRows * mColumns, mData);
}

Matrix::~Matrix() {
    if(mData) {
        delete [] mData;
        mData = nullptr;
    }
}

std::pair<unsigned, unsigned> Matrix::GetSize() const {
    return {mRows, mColumns};
}

float& Matrix::operator()(unsigned i, unsigned j) {
    return mData[i * mColumns + j];
}

const float& Matrix::operator()(unsigned i, unsigned j) const {
    return mData[i * mColumns + j];
}