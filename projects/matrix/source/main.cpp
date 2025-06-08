#include <iostream>

#include "Matrix.h"

// Show float array in Watch window:
// 1. LLDB (float(*)[9])matrix_a.mData
// 2. GDB (float[9])matrix_a.mData

int main() {
    std::cout << "Test application for the matrix class" << std::endl;

    Matrix diagonalMatrix3_3{3, 3, {10.f, 0.0f, 0.0f,
                                    0.0f, 4.0f, 0.0f,
                                    0.0f, 0.0f, 1.0f}};

    std::cout << diagonalMatrix3_3 << std::endl;
}