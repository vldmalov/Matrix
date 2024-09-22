#pragma once

#include <utility>  // std::pair

struct Matrix {
public:
    Matrix() = delete;
    Matrix(unsigned rows, unsigned columns, float itemValue = 0.f);
    ~Matrix();

    std::pair<unsigned, unsigned> GetSize() const;

    float& operator()(unsigned i, unsigned j);
    const float& operator()(unsigned i, unsigned j) const;

private:
    unsigned mRows{0};
    unsigned mColumns{0};
    float* mData{nullptr};
};

