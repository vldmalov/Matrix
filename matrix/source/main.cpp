#include <iostream>
#include <algorithm>
#include <numeric>

#include "Matrix.h"

void ConstructDefaultMatrices();
void ConstructFilledMatrices();
void ConstructMatricesWithInitializerList();
void TryConstructInvalidMatrices();
void AccessMatrixItems();
void AccessConstMatrixItems();
void CopyMatrices();
void MatrixAdd();
void MatrixSubtract();
void MultiplyMatrixOnScalar();

void PrintMatrix(const std::string& title, const Matrix& matrix) {
    std::cout << title << std::endl << matrix << std::endl;
}

int main() {
    std::cout << "Test application for the matrix class" << std::endl;
    ConstructDefaultMatrices();
    ConstructFilledMatrices();
    ConstructMatricesWithInitializerList();
    TryConstructInvalidMatrices();
    AccessMatrixItems();
    AccessConstMatrixItems();
    CopyMatrices();
    MatrixAdd();
    MatrixSubtract();
    MultiplyMatrixOnScalar();
}

void ConstructDefaultMatrices() {
    Matrix defaultMatrix1x3{1, 3};
    Matrix defaultMatrix3x1{3, 1};
    Matrix defaultMatrix3x3{3, 3};

    PrintMatrix("Default Matrix 1x3", defaultMatrix1x3);
    PrintMatrix("Default Matrix 3x1", defaultMatrix3x1);
    PrintMatrix("Default Matrix 3x3", defaultMatrix3x3);
}

void ConstructFilledMatrices() {
    Matrix filledMatrix1x3{1, 3, 3.25f};
    Matrix filledMatrix3x1{3, 1, 1.33f};
    Matrix filledMatrix3x3{3, 3, 5.17f};

    PrintMatrix("Filled Matrix 1x3", filledMatrix1x3);
    PrintMatrix("Filled Matrix 3x1", filledMatrix3x1);
    PrintMatrix("Filled Matrix 3x3", filledMatrix3x3);
}

void ConstructMatricesWithInitializerList() {
    Matrix matrix1_3{1, 3, {10.f, -30.f, 5.25f}};
    std::cout << "Matrix 1x3: " << matrix1_3 << std::endl;

    Matrix matrix3_1{3, 1, {10.f, -30.f, 5.25f}};
    std::cout << "Matrix 3x1: " << matrix3_1 << std::endl;

    {
        Matrix matrix3_3{3, 3, {10.f, 0.f, 5.25f,
                                0.f, -4.f, 12.1f,
                                56.7f, -2.f, 1.f}};
        std::cout << "Matrix 3x3: " << matrix3_3 << std::endl;
    }
}

void TryConstructInvalidMatrices() {
    try {
        Matrix invalidMatrix1{0, 3};
        Matrix invalidMatrix2{3, 0};
    }
    catch(std::invalid_argument& ex) {
        std::cout << "Exception has been thrown. Details: " << ex.what()  << std::endl;
    }
    catch(...) {
        std::cout << "Exception has been thrown" << std::endl;
    }

    {
        try {
            Matrix matrix3_3{3, 3, {10.f, 0.f, 5.25f,
                                    0.f, -4.f, 12.1f,
                                    56.7f}};
            std::cout << "Matrix 3x3: " << matrix3_3 << std::endl;
        }
        catch(std::exception& ex) {
            std::cout << "Attempt to construct a matrix with invalid parameters. Details: " << ex.what() << std::endl;
        }
    }
}

void AccessMatrixItems() {
    Matrix identityMatrix3x3{3, 3, 0.f};
    identityMatrix3x3(0, 0) = 1.f;
    identityMatrix3x3(1, 1) = 1.f;
    identityMatrix3x3(2, 2) = 1.f;
    PrintMatrix("Identity Matrix 3x3", identityMatrix3x3);
}

void AccessConstMatrixItems() {
    const Matrix identityMatrix3x3{3, 3, 1.f};
    // identityMatrix3x3(1, 1) = 1.f; // Compilation error!
    std::cout << "Matrix item (1, 1): " << identityMatrix3x3(1, 1) << std::endl;
}

void CopyMatrices() {
    Matrix diagonalMatrix3_3{3, 3, {10.f, 0.0f, 0.0f,
                                    0.0f, 4.0f, 0.0f,
                                    0.0f, 0.0f, 1.0f}};

    // Exercise1: Try to copy without writing a copy constructor
    Matrix copiedDiagonalMatrix3x3 = diagonalMatrix3_3;
    PrintMatrix("Copied Diagonal Matrix 3x3", copiedDiagonalMatrix3x3);

    // Modify copied matrix
    copiedDiagonalMatrix3x3(0, 1) = 2.5f;
    copiedDiagonalMatrix3x3(2, 2) *= -5.25f;

    // Print both matrices
    std::cout << "After modification" << std::endl;
    PrintMatrix("Source Matrix 3x3", diagonalMatrix3_3);
    PrintMatrix("Copied Matrix 3x3", copiedDiagonalMatrix3x3);
}

void MatrixAdd() {
    Matrix matrix_a{3, 3, {10.f, 9.f, 8.f,
                           7.f, 6.f, 5.f,
                           4.f, 3.f, 2.f}};

    Matrix matrix_b{3, 3, {0.f, 2.f, -4.f,
                           6.f, -8.f, 10.f,
                           -12.f, 14.f, 16.f}};

    std::cout << "Matrix A: " << matrix_a << std::endl;
    std::cout << "Matrix B: " << matrix_b << std::endl;

    matrix_a += matrix_b;
    std::cout << "Matrix A after addition operation: " << matrix_a << std::endl;
}

void MatrixSubtract() {
    Matrix matrix_a{3, 3, {10.f, 9.f, 8.f,
                           7.f, 6.f, 5.f,
                           4.f, 3.f, 2.f}};

    Matrix matrix_b{3, 3, {0.f, 2.f, -4.f,
                           6.f, -8.f, 10.f,
                           -12.f, 14.f, 16.f}};
    matrix_a -= matrix_b;
    std::cout << "Matrix A after addition operation: " << matrix_a << std::endl;
}

void MultiplyMatrixOnScalar() {
    Matrix matrix{3, 3, {  -8, 6, 1,
                           7, 0, -3,
                           2, 4, 5}};

    matrix *= -1.5f;
    std::cout << "Matrix multiplied on scalar: " << matrix << std::endl;
}


