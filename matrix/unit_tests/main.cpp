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

TEST(MatrixCreation, ConstructSquareConstMatrixWithDefaultValues) {
    // Arrange
    // Act
    const Matrix matrix{2, 2};

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

TEST(MatrixItemsAccess, SetItemValues) {
    // Arrange
    Matrix matrix{2, 3, {1.0f, 1.0f, 1.0f,
                         1.0f, 1.0f, 1.0f}};

    // Act
    matrix(0, 2) = -10.f;
    matrix(1, 2) = 10.f;

    // Assert
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 1.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), -10.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 1.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 1.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 10.0f);
}

TEST(MatrixOperations, CopyMatrix) {
    // Arrange
    Matrix sourceMatrix{2, 2, {10.f, 0.0f,
                               0.0f, 4.0f}};

    // Act
    Matrix copiedMatrix = sourceMatrix;

    // Assert
    EXPECT_FLOAT_EQ(sourceMatrix(0, 0), 10.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(1, 1), 4.0f);

    EXPECT_FLOAT_EQ(copiedMatrix(0, 0), 10.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(1, 1), 4.0f);
}

TEST(MatrixOperations, CopyAndEditMatrix) {
    // Arrange
    Matrix sourceMatrix{2, 2, {10.f, 0.0f,
                               0.0f, 4.0f}};

    // Act
    Matrix copiedMatrix = sourceMatrix;
    copiedMatrix(0,0) = -2.f;
    copiedMatrix(0,1) = 8.f;

    // Assert
    EXPECT_FLOAT_EQ(sourceMatrix(0, 0), 10.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(sourceMatrix(1, 1), 4.0f);

    EXPECT_FLOAT_EQ(copiedMatrix(0, 0), -2.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(0, 1), 8.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(copiedMatrix(1, 1), 4.0f);
}

TEST(MatrixOperations, AdditionAssignmentOperator) {
    // Arrange
    Matrix firstMatrix{2, 2, {1.f, 2.0f,
                              3.0f, 4.0f}};

    Matrix secondMatrix{2, 2, {10.f, 20.0f,
                               30.0f, 40.0f}};

    // Act
    firstMatrix += secondMatrix;

    // Assert
    EXPECT_FLOAT_EQ(firstMatrix(0, 0), 11.0f);
    EXPECT_FLOAT_EQ(firstMatrix(0, 1), 22.0f);
    EXPECT_FLOAT_EQ(firstMatrix(1, 0), 33.0f);
    EXPECT_FLOAT_EQ(firstMatrix(1, 1), 44.0f);

    EXPECT_FLOAT_EQ(secondMatrix(0, 0), 10.0f);
    EXPECT_FLOAT_EQ(secondMatrix(0, 1), 20.0f);
    EXPECT_FLOAT_EQ(secondMatrix(1, 0), 30.0f);
    EXPECT_FLOAT_EQ(secondMatrix(1, 1), 40.0f);
}

TEST(MatrixOperations, AdditionAssignmentOperatorDifferentSizes) {
    // Arrange
    Matrix firstMatrix{1, 2, {1.f, 2.0f}};

    Matrix secondMatrix{2, 1, {10.f,
                               20.0f}};

    try {
        // Act
        firstMatrix += secondMatrix;
        FAIL() << "Expected std::invalid_argument";
    } catch(std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrices should have the same size"));
    } catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(MatrixOperations, SubstractionAssignmentOperator) {
    // Arrange
    Matrix firstMatrix{2, 2, {1.f, 2.0f,
                              3.0f, 4.0f}};

    Matrix secondMatrix{2, 2, {10.f, 20.0f,
                               30.0f, 40.0f}};

    // Act
    firstMatrix -= secondMatrix;

    // Assert
    EXPECT_FLOAT_EQ(firstMatrix(0, 0), -9.0f);
    EXPECT_FLOAT_EQ(firstMatrix(0, 1), -18.0f);
    EXPECT_FLOAT_EQ(firstMatrix(1, 0), -27.0f);
    EXPECT_FLOAT_EQ(firstMatrix(1, 1), -36.0f);

    EXPECT_FLOAT_EQ(secondMatrix(0, 0), 10.0f);
    EXPECT_FLOAT_EQ(secondMatrix(0, 1), 20.0f);
    EXPECT_FLOAT_EQ(secondMatrix(1, 0), 30.0f);
    EXPECT_FLOAT_EQ(secondMatrix(1, 1), 40.0f);
}

TEST(MatrixOperations, SubstractionAssignmentOperatorDifferentSizes) {
    // Arrange
    Matrix firstMatrix{1, 2, {1.f, 2.0f}};

    Matrix secondMatrix{2, 1, {10.f,
                               20.0f}};

    try {
        // Act
        firstMatrix -= secondMatrix;
        FAIL() << "Expected std::invalid_argument";
    } catch(std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrices should have the same size"));
    } catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(MatrixOperations, MultipyMatrixOnZeroScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 0.0f,
                         -3.0f, 3.0f}};

    // Act
    matrix *= 0.f;

    // Assert
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 0.0f);
}

TEST(MatrixOperations, MultipyMatrixOnPositiveScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 0.0f,
                         -3.0f, 3.0f}};

    // Act
    matrix *= 4.5f;

    // Assert
    EXPECT_FLOAT_EQ(matrix(0, 0), 4.5f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), -13.5f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 13.5f);
}

TEST(MatrixOperations, MultipyMatrixOnNegativeScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 0.0f,
                         -3.0f, 3.0f}};

    // Act
    matrix *= -4.5f;

    // Assert
    EXPECT_FLOAT_EQ(matrix(0, 0), -4.5f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 13.5f);
    EXPECT_FLOAT_EQ(matrix(1, 1), -13.5f);
}


// TODO: Extend number of tests