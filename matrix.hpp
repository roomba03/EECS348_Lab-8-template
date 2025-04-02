#ifndef __MATRIX_HPP__
#define __MATRIX_HPP__

#include <cstdint>
#include <vector>

class Matrix {
public:
    // data members
    std::vector<std::vector<int> > matrix;
    // constructor to create a NxN matrix

    Matrix(std::size_t N);
    // constructor to create a matrix with vectors
    Matrix(std::vector<std::vector<int> > nums);

    // operator overloading to add matrices
    Matrix operator+(const Matrix &rhs) const;
    // operator overloading to multiply two matrices
    Matrix operator*(const Matrix &rhs) const;
    // method to set a value at position (i, j) in the matrix
    void set_value(std::size_t i, std::size_t j, int n);
    // method to get the value at position (i, j) in the matrix
    int get_value(std::size_t i, std::size_t j) const;
    // method that returns the size of the matrix
    int get_size() const;
    // method to calculate the sum of the major diagonal (top-left to bottom-right)
    int sum_diagonal_major() const;
    // method to calculate and return the sum of the minor diagonal (top-right to bottom-left)
    int sum_diagonal_minor() const;
    // method to swap 2 rows
    void swap_rows(std::size_t r1, std::size_t r2);
    // method to swap 2 columns
    void swap_cols(std::size_t c1, std::size_t c2);
    // prints matrix in a readable format
    void print_matrix() const;
};

#endif // __MATRIX_HPP__