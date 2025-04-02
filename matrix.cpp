#include "matrix.hpp"
#include <iostream>
#include <iomanip>
#include <stdexcept> 


// implementation of functions declared in matrix.hpp goes here
// function definitions for a class have their names prefixed with
// the class name and "::"

// e.g. for the constructor:
Matrix::Matrix(std::size_t N) {
    // initialize an empty NxN matrix
    matrix.resize(N, std::vector<int>(N, 0));
}

// constructor for the vector matrix
Matrix::Matrix(std::vector<std::vector<int>> nums) {
    matrix = nums;
}

// Overloaded + operator to add two matrices
Matrix Matrix::operator+(const Matrix &rhs) const {
    if (this->get_size() != rhs.get_size()) {
        throw std::invalid_argument("Matrices must have the same size to add."); // Ensure matrices are the same size
    }

    std::size_t N = this->get_size();
    Matrix result(N); // Create a result matrix of the same size

    // Add corresponding elements from both matrices
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            result.set_value(i, j, this->get_value(i, j) + rhs.get_value(i, j));
        }
    }
    return result;
}

// Overloaded * operator to multiply two matrices
Matrix Matrix::operator*(const Matrix &rhs) const {
    if (this->get_size() != rhs.get_size()) {
        throw std::invalid_argument("Matrices must have the same size to multiply."); // Ensure matrices are the same size
    }

    std::size_t N = this->get_size();
    Matrix result(N); // Create a result matrix of the same size

    // Matrix multiplication: multiply rows of the first matrix by columns of the second
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            int sum = 0;
            for (std::size_t k = 0; k < N; ++k) {
                sum += this->get_value(i, k) * rhs.get_value(k, j); // Sum of products
            }
            result.set_value(i, j, sum); // Store result in the matrix
        }
    }

    return result; // Return the resulting matrix
}

// Method to set the value at position (i, j) in the matrix
void Matrix::set_value(std::size_t i, std::size_t j, int n) {
    if (i >= matrix.size() || j >= matrix.size()) {
        throw std::out_of_range("Index out of range"); // Check if indices are valid
    }
    matrix[i][j] = n; // Set the value at the specified position
}

// Method to get the value at position (i, j) in the matrix
int Matrix::get_value(std::size_t i, std::size_t j) const {
    if (i >= matrix.size() || j >= matrix.size()) {
        throw std::out_of_range("Index out of range"); // Check if indices are valid
    }
    return matrix[i][j]; // Return the value at the specified position
}

// Method to return the size (dimension) of the matrix
int Matrix::get_size() const {
    return matrix.size(); // Return the size of the matrix (NxN)
}

// Method to calculate and return the sum of the major diagonal
int Matrix::sum_diagonal_major() const {
    int sum = 0;
    std::size_t N = this->get_size();

    for (std::size_t i = 0; i < N; ++i) {
        sum += matrix[i][i]; // Sum of the major diagonal elements (top-left to bottom-right)
    }

    return sum; // Return the sum of the major diagonal
}

// Method to calculate and return the sum of the minor diagonal
int Matrix::sum_diagonal_minor() const {
    int sum = 0;
    std::size_t N = this->get_size();

    for (std::size_t i = 0; i < N; ++i) {
        sum += matrix[i][N - i - 1]; // Sum of the minor diagonal elements (top-right to bottom-left)
    }

    return sum; // Return the sum of the minor diagonal
}

// method to swap two rows in the matrix
void Matrix::swap_rows(std::size_t r1, std::size_t r2) {
    if (r1 >= matrix.size() || r2 >= matrix.size()) {
        throw std::out_of_range("Row index out of range"); // checks if row indices are valid
    }
    std::swap(matrix[r1], matrix[r2]); // Swap the two rows
}

// Method to swap two columns in the matrix
void Matrix::swap_cols(std::size_t c1, std::size_t c2) {
    if (c1 >= matrix.size() || c2 >= matrix.size()) {
        throw std::out_of_range("Column index out of range"); // Check if column indices are valid
    }
    
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        std::swap(matrix[i][c1], matrix[i][c2]); // Swap the two columns element-wise
    }
}

// e.g. for a member function:

void Matrix::print_matrix() const {
    // print out the matrix
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << std::setw(4) << value; // Use setw for column alignment
        }
        std::cout << std::endl; // Move to the next line after printing a row
    }

}
