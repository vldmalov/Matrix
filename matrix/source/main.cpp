#include <iostream>
#include <algorithm>
#include <numeric>

#include "Matrix.h"

void PrintMatrix(const std::string& title, const Matrix& matrix) {
    std::cout << title << std::endl;
    std::cout << matrix << std::endl;
}

int main() {
    std::cout << "Test application for the matrix class" << std::endl;

    // Construct matrices with default item's value
    Matrix defaultMatrix1x3{1, 3};
    Matrix defaultMatrix3x1{3, 1};
    Matrix defaultMatrix3x3{3, 3};

    // Construct matrices with particular item's value
    Matrix filledMatrix1x3{1, 3, 3.25f};
    Matrix filledMatrix3x1{3, 1, 1.33f};
    Matrix filledMatrix3x3{3, 3, 5.17f};

    PrintMatrix("Default Matrix 1x3", defaultMatrix1x3);
    PrintMatrix("Default Matrix 3x1", defaultMatrix3x1);
    PrintMatrix("Default Matrix 3x3", defaultMatrix3x3);

    PrintMatrix("Filled Matrix 1x3", filledMatrix1x3);
    PrintMatrix("Filled Matrix 3x1", filledMatrix3x1);
    PrintMatrix("Filled Matrix 3x3", filledMatrix3x3);

    // Try construct matrices with invalid sizes
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

    // Access matrix items
    Matrix identityMatrix3x3{3, 3, 0.f};
    identityMatrix3x3(0, 0) = 1.f;
    identityMatrix3x3(1, 1) = 1.f;
    identityMatrix3x3(2, 2) = 1.f;
    PrintMatrix("Identity Matrix 3x3", identityMatrix3x3);

    // Copy matrix
    // Exercise1: Try to copy without writing a copy constructor
    Matrix copiedIdentityMatrix3x3 = identityMatrix3x3;
    PrintMatrix("Copied Identity Matrix 3x3", copiedIdentityMatrix3x3);

    // Modify copied matrix
    copiedIdentityMatrix3x3(0, 1) = 2.5f;
    copiedIdentityMatrix3x3(2, 1) = -4.7f;

    // Print both matrices
    std::cout << "After modification" << std::endl;
    PrintMatrix("Identity Matrix 3x3", identityMatrix3x3);
    PrintMatrix("Copied Identity Matrix 3x3", copiedIdentityMatrix3x3);

    // Create matrix with initializer list
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

    return 0;
}


