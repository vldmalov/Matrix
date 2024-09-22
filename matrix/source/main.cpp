#include <iostream>
#include <algorithm>
#include <numeric>

#include "Matrix.h"

void PrintMatrix(const std::string& title, const Matrix& matrix) {
    std::cout << title << std::endl;
    const std::pair<unsigned, unsigned> matrixSize = matrix.GetSize();

    std::cout << "Matrix size: (" << matrixSize.first << "; " << matrixSize.second << ")" << std::endl;

    for(unsigned i = 0; i < matrixSize.first; ++i) {
        std::cout << "[ ";
        for(unsigned j = 0; j < matrixSize.second; ++j) {
            std::cout << matrix(i, j) << " ";
        }
        std::cout << "]" << std::endl;
    }
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

    return 0;
}


