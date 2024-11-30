#include <benchmark/benchmark.h>
#include <random>

#include "Matrix.h"

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

Matrix CreateMatrix() {
    Matrix matrix{3, 3, {1.f, -5.f, 3.f,
                         0.f, -2.f, 6.f,
                         7.f, 2.f, -4.f}};
    return matrix;
}

Matrix MultiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    return matrix1 * matrix2;
}

static void bmMatrixCreationBenchmark(benchmark::State& state) {
    for (auto _ : state) {
        CreateMatrix();
    }
}

static void bmMatricesMultiplication3x3Benchmark(benchmark::State& state) {
    const Matrix matrixA_3_3 = GenerateMatrix(3, 3);
    const Matrix matrixB_3_3 = GenerateMatrix(3, 3);
    for (auto _ : state) {
        MultiplyMatrices(matrixA_3_3, matrixB_3_3);
    }
}

static void bmMatricesMultiplication9x9Benchmark(benchmark::State& state) {
    const Matrix matrixA_9_9 = GenerateMatrix(9, 9);
    const Matrix matrixB_9_9 = GenerateMatrix(9, 9);
    for (auto _ : state) {
        MultiplyMatrices(matrixA_9_9, matrixB_9_9);
    }
}

static void bmMatricesMultiplication100x100Benchmark(benchmark::State& state) {
    const Matrix matrixA_100_100 = GenerateMatrix(100, 100);
    const Matrix matrixB_100_100 = GenerateMatrix(100, 100);
    for (auto _ : state) {
        MultiplyMatrices(matrixA_100_100, matrixB_100_100);
    }
}

BENCHMARK(bmMatrixCreationBenchmark);
BENCHMARK(bmMatricesMultiplication3x3Benchmark);
BENCHMARK(bmMatricesMultiplication9x9Benchmark);
BENCHMARK(bmMatricesMultiplication100x100Benchmark);
BENCHMARK_MAIN();
