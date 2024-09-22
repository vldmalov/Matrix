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

    std::pair<unsigned, unsigned> GetSize() const;

    float& operator()(unsigned i, unsigned j);
    const float& operator()(unsigned i, unsigned j) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

private:
    unsigned mRows{0};
    unsigned mColumns{0};
    float* mData{nullptr};
};

std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
