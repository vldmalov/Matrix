#include "MatrixUtils.h"
#include "Matrix.h"

#include <random>

Matrix GenerateMatrix(unsigned rows, unsigned columns) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> dist(-100.0, 100.0);

    const unsigned matrixNumValues = rows * columns;

    std::vector<float> matrixValues;
    matrixValues.reserve(matrixNumValues);

    for(size_t idx = 0; idx < matrixNumValues; ++idx) {
        matrixValues.emplace_back(dist(rng));
    }

    return Matrix(rows, columns, matrixValues);
}