#include <gtest/gtest.h>

#include "Matrix.h"

TEST(MatrixCreation, ConstructRowMatrixWithDefaultValues) {
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

TEST(MatrixCreation, ConstructColumnMatrixWithDefaultValues) {
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

TEST(MatrixCreation, ConstructSquareMatrixWithDefaultValues) {
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

TEST(MatrixCreation, ConstructMatrixWithPredefinedValues) {
    // Arrange
    // Act
    Matrix matrix{2, 3, 4.5f};

    // Assert
    auto matrixSize = matrix.GetSize();
    EXPECT_EQ(matrixSize.first, 2);
    EXPECT_EQ(matrixSize.second, 3);
    EXPECT_FLOAT_EQ(matrix(0, 0), 4.5f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 4.5f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 4.5f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 4.5f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 4.5f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 4.5f);
}

TEST(MatrixCreation, ConstructMatrixWithInitializerList) {
    // Arrange
    // Act
    Matrix matrix{2, 3, {1.1f, 2.2f, 3.3f,
                         4.4f, 5.5f, 6.6f}};

    // Assert
    auto matrixSize = matrix.GetSize();
    EXPECT_EQ(matrixSize.first, 2);
    EXPECT_EQ(matrixSize.second, 3);
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.1f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 2.2f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 3.3f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 4.4f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 5.5f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 6.6f);
}

TEST(MatrixCreation, ConstructInvalidMatrix) {
    // Arrange
    // Act
    try {
        Matrix matrix{0, 3};
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrix sizes should be grater than 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(MatrixCreation, ConstructInvalidMatrix2) {
    // Arrange
    // Act
    try {
        Matrix matrix{3, 0};
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrix sizes should be grater than 0"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(MatrixCreation, ConstructInvalidMatrixWithInitializerList) {
    // Arrange
    // Act
    try {
        Matrix matrix{3, 3, {1.0f, 0.0f, 2.0f,
                             0.0f, -4.0f, 1.0f,
                             3.0f}};
        FAIL() << "Expected std::invalid_argument";
    }
    catch(std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrix size doesn't correspond to size of initializer list"));
    }
    catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

// TODO: Extend number of tests