#include <benchmark/benchmark.h>

#include "Matrix.h"

Matrix CreateMatrix() {
    Matrix matrix{3, 3, {1.f, -5.f, 3.f,
                         0.f, -2.f, 6.f,
                         7.f, 2.f, -4.f}};
    return matrix;
}

Matrix MultiplyMatrices() {
    Matrix matrix1{3, 3, {1.f, -5.f, 3.f,
                         0.f, -2.f, 6.f,
                         7.f, 2.f, -4.f}};

    Matrix matrix2{3, 3, {1.f, -5.f, 3.f,
                         0.f, -2.f, 6.f,
                         7.f, 2.f, -4.f}};
    return matrix1 * matrix2;
}

static void bmMatrixCreationBenchmark(benchmark::State& state) {
    for (auto _ : state) {
        CreateMatrix();
    }
}

static void bmMatricesMultiplicationBenchmark(benchmark::State& state) {
    for (auto _ : state) {
        MultiplyMatrices();
    }
}

BENCHMARK(bmMatrixCreationBenchmark);
BENCHMARK(bmMatricesMultiplicationBenchmark);
BENCHMARK_MAIN();