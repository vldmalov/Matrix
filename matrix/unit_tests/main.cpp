#include <gtest/gtest.h>

#include "Matrix.h"

TEST(MatrixCreation, DefaultConstructRowMatrixDefaultValues) {
    // Arrange
    // Act
    Matrix matrix{1, 3};

    // Assert
    auto matrixSize = matrix.GetSize();
    EXPECT_EQ(matrixSize.first, 1);
    EXPECT_EQ(matrixSize.second, 3);
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 0.f);
}

TEST(MatrixCreation, DefaultConstructColumnMatrixDefaultValues) {
    // Arrange
    // Act
    Matrix matrix{4, 1};

    // Assert
    auto matrixSize = matrix.GetSize();
    EXPECT_EQ(matrixSize.first, 4);
    EXPECT_EQ(matrixSize.second, 1);
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(3, 0), 0.f);
}

TEST(MatrixCreation, DefaultConstructSquareMatrixDefaultValues) {
    // Arrange
    // Act
    Matrix matrix{2, 2};

    // Assert
    auto matrixSize = matrix.GetSize();
    EXPECT_EQ(matrixSize.first, 2);
    EXPECT_EQ(matrixSize.second, 2);
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 0.f);
}

// TODO: Extend number of tests