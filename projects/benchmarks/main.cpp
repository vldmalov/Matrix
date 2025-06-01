#include <benchmark/benchmark.h>

#include "Matrix.h"
#include "MatrixUtils.h"

Matrix MultiplyMatrices(const Matrix& matrix1, const Matrix& matrix2) {
    return matrix1 * matrix2;
}

static void bmMatrixCreationSimple3x3Benchmark(benchmark::State& state) {
    for (auto _ : state) {
        Matrix matrix{3, 3, 1.f};
    }
}

static void bmMatrixCreationInitializerList3x3Benchmark(benchmark::State& state) {
    for (auto _ : state) {
        Matrix matrix{
            3, 3,
            {1.f, 2.f, 3.f,
                  4.f, 5.f, 6.f,
                  7.f, 8.f, 9.f}};
    }
}

static void bmMatrixCreationSimple10x10Benchmark(benchmark::State& state) {
    for (auto _ : state) {
        Matrix matrix{10, 10, 1.f};
    }
}

static void bmMatrixCreationInitializerList10x10Benchmark(benchmark::State& state) {
    for (auto _ : state) {
        Matrix matrix{
            10, 10,
            {1.f, 2.f, 3.f, 4.f, 5.f, 6.f, 7.f, 8.f, 9.f, 10.f,
                11.f, 12.f, 13.f, 14.f, 15.f, 16.f, 17.f, 18.f, 19.f, 20.f,
                21.f, 22.f, 23.f, 24.f, 25.f, 26.f, 27.f, 28.f, 29.f, 30.f,
                31.f, 32.f, 33.f, 34.f, 35.f, 36.f, 37.f, 38.f, 39.f, 40.f,
                41.f, 42.f, 43.f, 44.f, 45.f, 46.f, 47.f, 48.f, 49.f, 50.f,
                51.f, 52.f, 53.f, 54.f, 55.f, 56.f, 57.f, 58.f, 59.f, 60.f,
                61.f, 62.f, 63.f, 64.f, 65.f, 66.f, 67.f, 68.f, 69.f, 70.f,
                71.f, 72.f, 73.f, 74.f, 75.f, 76.f, 77.f, 78.f, 79.f, 80.f,
                81.f, 82.f, 83.f, 84.f, 85.f, 86.f, 87.f, 88.f, 89.f, 90.f,
                91.f, 92.f, 93.f, 94.f, 95.f, 96.f, 97.f, 98.f, 99.f, 100.f}};
    }
}

static void bmMatricesMultiplication3x3Benchmark(benchmark::State& state) {
    const Matrix matrixA = GenerateMatrix(3, 3);
    const Matrix matrixB = GenerateMatrix(3, 3);
    for (auto _ : state) {
        MultiplyMatrices(matrixA, matrixB);
    }
}

static void bmMatricesMultiplication9x9Benchmark(benchmark::State& state) {
    const Matrix matrixA = GenerateMatrix(9, 9);
    const Matrix matrixB = GenerateMatrix(9, 9);
    for (auto _ : state) {
        MultiplyMatrices(matrixA, matrixB);
    }
}

static void bmMatricesMultiplication81x81Benchmark(benchmark::State& state) {
    const Matrix matrixA = GenerateMatrix(81, 81);
    const Matrix matrixB = GenerateMatrix(81, 81);
    for (auto _ : state) {
        MultiplyMatrices(matrixA, matrixB);
    }
}

static void bmMatricesCopyMoveBenchmark(benchmark::State& state) {
    const size_t matricesCount = 10000;
    std::vector<Matrix> srcMatrices;
    srcMatrices.reserve(matricesCount);
    for (size_t i = 0; i < matricesCount; ++i) {
        srcMatrices.push_back(GenerateMatrix(25, 25));
    }

    for (auto _ : state) {
        std::vector<Matrix> dstMatrices;
        std::ranges::copy(srcMatrices, std::back_inserter(dstMatrices));
    }
}

BENCHMARK(bmMatrixCreationSimple3x3Benchmark);
BENCHMARK(bmMatrixCreationInitializerList3x3Benchmark);
BENCHMARK(bmMatrixCreationSimple10x10Benchmark);
BENCHMARK(bmMatrixCreationInitializerList10x10Benchmark);

// Horisontal/Vertical
BENCHMARK(bmMatricesMultiplication3x3Benchmark);
BENCHMARK(bmMatricesMultiplication9x9Benchmark);
BENCHMARK(bmMatricesMultiplication81x81Benchmark);

// Add/Remove Matrix(Matrix&& another) noexcept;
BENCHMARK(bmMatricesCopyMoveBenchmark);

BENCHMARK_MAIN();
