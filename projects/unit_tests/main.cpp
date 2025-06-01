#include <gtest/gtest.h>

#include "Matrix.h"

TEST(MatrixCreation, ConstructRowMatrixWithDefaultValues) {
    // Arrange
    // Act
    Matrix matrix{1, 3};

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(1, 3));
    EXPECT_FLOAT_EQ(matrix(0, 0), 0.f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 0.f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 0.f);
}

TEST(MatrixCreation, ConstructColumnMatrixWithDefaultValues) {
    // Arrange
    // Act
    Matrix matrix{4, 1};

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(4, 1));
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
    EXPECT_EQ(matrix.GetSize(), MatrixSize(2, 2));
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
    EXPECT_EQ(matrix.GetSize(), MatrixSize(2, 3));
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
    EXPECT_EQ(matrix.GetSize(), MatrixSize(2, 3));
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

TEST(MatrixCreation, CopyMatrix) {
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

TEST(MatrixCreation, CopyAndEditMatrix) {
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

TEST(MatrixAssignmentOperator, SameSize) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 2.0f,
                         3.0f, 4.0f}};


    // Act
    matrix = Matrix{2, 2, {9.f, 8.0f,
                           7.0f, 6.0f}};

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(2, 2));
    EXPECT_FLOAT_EQ(matrix(0, 0), 9.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 8.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 7.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 6.0f);
}

TEST(MatrixAssignmentOperator, BiggerSize) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 2.0f,
                         3.0f, 4.0f}};


    // Act
    matrix = Matrix{3, 3, {9.f, 8.f, 7.f,
                           6.f, 5.f, 4.f,
                           3.f, 2.f, 1.f}};

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(3, 3));
    EXPECT_FLOAT_EQ(matrix(0, 0), 9.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 8.0f);
    EXPECT_FLOAT_EQ(matrix(0, 2), 7.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 6.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 5.0f);
    EXPECT_FLOAT_EQ(matrix(1, 2), 4.0f);
    EXPECT_FLOAT_EQ(matrix(2, 0), 3.0f);
    EXPECT_FLOAT_EQ(matrix(2, 1), 2.0f);
    EXPECT_FLOAT_EQ(matrix(2, 2), 1.0f);
}

TEST(MatrixAssignmentOperator, SmallerSize) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 2.0f,
                         3.0f, 4.0f}};


    // Act
    matrix = Matrix{1, 2, {9.f,
                           8.f}};

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(1, 2));
    EXPECT_FLOAT_EQ(matrix(0, 0), 9.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 8.0f);
}

TEST(MatrixAssignmentOperator, Themeself) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 2.0f,
                         3.0f, 4.0f}};
    Matrix& refToMatrix = matrix;

    // Act
    matrix = refToMatrix;

    // Assert
    EXPECT_EQ(matrix.GetSize(), MatrixSize(2, 2));
    EXPECT_FLOAT_EQ(matrix(0, 0), 1.0f);
    EXPECT_FLOAT_EQ(matrix(0, 1), 2.0f);
    EXPECT_FLOAT_EQ(matrix(1, 0), 3.0f);
    EXPECT_FLOAT_EQ(matrix(1, 1), 4.0f);
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
    EXPECT_EQ(matrix, Matrix(2, 2, {0.0f, 0.0f,
                                    0.0f, 0.0f}));
}

TEST(MatrixOperations, MultipyMatrixOnPositiveScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 0.0f,
                         -3.0f, 3.0f}};

    // Act
    matrix *= 4.5f;

    // Assert
    EXPECT_EQ(matrix, Matrix(2, 2, {4.5f, 0.0f,
                                    -13.5f, 13.5f}));
}

TEST(MatrixOperations, MultipyMatrixOnNegativeScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 0.0f,
                         -3.0f, 3.0f}};

    // Act
    matrix *= -4.5f;

    // Assert
    EXPECT_EQ(matrix, Matrix(2, 2, {-4.5f, 0.0f,
                                   13.5f, -13.5f}));
}

TEST(MatrixOperations, OperatorPlus) {
    // Arrange
    Matrix firstMatrix{2, 2, {1.f, 2.0f,
                              3.0f, 4.0f}};

    Matrix secondMatrix{2, 2, {10.f, 20.0f,
                               30.0f, 40.0f}};

    // Act
    Matrix resultMatrix = firstMatrix + secondMatrix;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(2, 2, {11.f, 22.f,
                                          33.f, 44.f}));

    EXPECT_EQ(firstMatrix, Matrix(2, 2, {1.f, 2.0f,
                                         3.0f, 4.0f}));

    EXPECT_EQ(secondMatrix, Matrix(2, 2, {10.f, 20.0f,
                                          30.0f, 40.0f}));
}

TEST(MatrixOperations, OperatorMinus) {
    // Arrange
    Matrix firstMatrix{2, 2, {1.f, 2.0f,
                              3.0f, 4.0f}};

    Matrix secondMatrix{2, 2, {10.f, 20.0f,
                               30.0f, 40.0f}};

    // Act
    Matrix resultMatrix = firstMatrix - secondMatrix;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(2, 2, {-9.f, -18.f,
                                           -27.f, -36.f}));

    EXPECT_EQ(firstMatrix, Matrix(2, 2, {1.f, 2.0f,
                                        3.0f, 4.0f}));

    EXPECT_EQ(secondMatrix, Matrix(2, 2, {10.f, 20.0f,
                                         30.0f, 40.0f}));
}

TEST(MatrixOperations, OperatorMultiplyOnScalar) {
    // Arrange
    Matrix matrix{2, 2, {1.f, 2.0f,
                         3.0f, 4.0f}};

    // Act
    Matrix resultMatrix1 = matrix * 11.f;
    Matrix resultMatrix2 = 11.f * matrix;

    // Assert
    EXPECT_EQ(resultMatrix1, Matrix(2, 2, {11.f, 22.f,
                                           33.f, 44.f}));
    EXPECT_EQ(resultMatrix2, Matrix(2, 2, {11.f, 22.f,
                                           33.f, 44.f}));
}

TEST(MatrixMultiply, SingleItemMatrices) {
    // Arrange
    Matrix matrix1{1, 1, {3.f}};
    Matrix matrix2{1, 1, {5.f}};

    // Act
    const Matrix resultMatrix = matrix1 * matrix2;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(1, 1, {15.f}));
}

TEST(MatrixMultiply, SquareMatrices) {
    // Arrange
    Matrix matrix1{3, 3, {1.f, -5.f, 3.f,
                          0.f, -2.f, 6.f,
                          7.f, 2.f, -4.f}};
    Matrix matrix2{3, 3, {-8.f, 6.f, 1.f,
                          7.f, 0.f, -3.f,
                          2.f, 4.f, 5.f}};

    // Act
    const Matrix resultMatrix = matrix1 * matrix2;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(3, 3, {-37.f, 18.f, 31.f,
                                          -2.f, 24.f, 36.f,
                                          -50.f, 26.f, -19.f}));
}

TEST(MatrixMultiply, IdentityMatrix) {
    // Arrange
    Matrix matrix1{3, 3, {1.f, -5.f, 3.f,
                          0.f, -2.f, 6.f,
                          7.f, 2.f, -4.f}};
    Matrix matrix2{3, 3, {1.f, 0.f, 0.f,
                          0.f, 1.f, 0.f,
                          0.f, 0.f, 1.f}};

    // Act
    const Matrix resultMatrix = matrix1 * matrix2;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(3, 3, {1.f, -5.f, 3.f,
                                          0.f, -2.f, 6.f,
                                          7.f, 2.f, -4.f}));
}

TEST(MatrixMultiply, DifferentSizes1) {
    // Arrange
    Matrix matrix1{1, 3, {1.f, -5.f, 3.f}};
    Matrix matrix2{3, 1, {-8.f,
                          7.f,
                          2.f}};

    // Act
    const Matrix resultMatrix = matrix1 * matrix2;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(1, 1, {-37.f}));
}

TEST(MatrixMultiply, DifferentSizes2) {
    // Arrange
    Matrix matrix1{3, 1, {-8.f,
                          7.f,
                          2.f}};
    Matrix matrix2{1, 3, {1.f, -5.f, 3.f}};

    // Act
    const Matrix resultMatrix = matrix1 * matrix2;

    // Assert
    EXPECT_EQ(resultMatrix, Matrix(3, 3, {-8.f, 40.f, -24.f,
                                          7.f, -35.f, 21.f,
                                          2.f, -10.f, 6.f}));
}

TEST(MatrixMultiply, InvalidSizedMatrices) {
    // Arrange
    Matrix matrix1{2, 2, {-8.f, 4.f,
                          7.f, 3.f}};
    Matrix matrix2{1, 3, {1.f, -5.f, 3.f}};

    try {
        // Act
        const Matrix resultMatrix = matrix1 * matrix2;
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument const & err) {
        // Assert
        EXPECT_EQ(err.what(), std::string("Matrices sizes should correspond to each other"));
    } catch(...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(MatrixTransposition, OneItemMatrix) {
    // Arrange
    Matrix matrix{1, 1, {5.5f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(1, 1, {5.5f}));
}

TEST(MatrixTransposition, RowMatrix) {
    // Arrange
    Matrix matrix{1, 3, {3.f, 6.f, 9.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(3, 1, {3.f,
                                              6.f,
                                              9.f}));
}

TEST(MatrixTransposition, ColumnMatrix) {
    // Arrange
    Matrix matrix{3, 1, {3.f,
                         6.f,
                         9.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(1, 3, {3.f, 6.f, 9.f}));
}

TEST(MatrixTransposition, IdentityMatrix) {
    // Arrange
    Matrix matrix{3, 3, {1.f, 0.f, 0.f,
                         0.f, 1.f, 0.f,
                         0.f, 0.f, 1.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(3, 3, {1.f, 0.f, 0.f,
                                              0.f, 1.f, 0.f,
                                              0.f, 0.f, 1.f}));
}

TEST(MatrixTransposition, DiagonalMatrix) {
    // Arrange
    Matrix matrix{3, 3, {7.f, 0.f, 0.f,
                         0.f, 6.f, 0.f,
                         0.f, 0.f, 5.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(3, 3, {7.f, 0.f, 0.f,
                                              0.f, 6.f, 0.f,
                                              0.f, 0.f, 5.f}));
}

TEST(MatrixTransposition, SquareMatrix) {
    // Arrange
    Matrix matrix{3, 3, {1.f, 2.f, 3.f,
                         4.f, 5.f, 6.f,
                         7.f, 8.f, 9.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(3, 3, {1.f, 4.f, 7.f,
                                              2.f, 5.f, 8.f,
                                              3.f, 6.f, 9.f}));
}

TEST(MatrixTransposition, ArbitraryMatrix) {
    // Arrange
    Matrix matrix{2, 4, {1.f, 2.f, 3.f, 4.f,
                         5.f, 6.f, 7.f, 8.f}};

    // Act
    Matrix transposedMatrix = matrix.Transposition();

    // Assert
    EXPECT_EQ(transposedMatrix, Matrix(4, 2, {1.f, 5.f,
                                              2.f, 6.f,
                                              3.f, 7.f,
                                              4.f, 8.f}));
}
