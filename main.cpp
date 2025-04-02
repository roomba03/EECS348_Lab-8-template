#include "matrix.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    // Ensure the user provides a filename as a command-line argument
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1; // Exit with an error code
    }

    std::string filename = argv[1]; // Get filename from command-line argument
    std::ifstream file(filename);
    
    // Check if file opens successfully
    if (!file) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return 1; // Exit with an error code
    }

    // Read matrix size
    std::size_t N;
    file >> N;

    // Read first matrix from the file
    std::vector<std::vector<int>> matrix1(N, std::vector<int>(N));
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix1[i][j];
        }
    }

    // Read second matrix from the file
    std::vector<std::vector<int>> matrix2(N, std::vector<int>(N));
    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < N; ++j) {
            file >> matrix2[i][j];
        }
    }

    file.close(); // Close the file after reading

    // Create Matrix objects
    Matrix mat1(matrix1);
    Matrix mat2(matrix2);

    // Display the matrices
    std::cout << "\nMatrix 1:\n";
    mat1.print_matrix();

    std::cout << "\nMatrix 2:\n";
    mat2.print_matrix();

    // Perform matrix addition
    try {
        Matrix sumMatrix = mat1 + mat2;
        std::cout << "\nMatrix Addition Result:\n";
        sumMatrix.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << "Error in addition: " << e.what() << std::endl;
    }

    // Perform matrix multiplication
    try {
        Matrix productMatrix = mat1 * mat2;
        std::cout << "\nMatrix Multiplication Result:\n";
        productMatrix.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << "Error in multiplication: " << e.what() << std::endl;
    }

    // Calculate diagonal sums
    std::cout << "\nSum of Major Diagonal of Matrix 1: " << mat1.sum_diagonal_major() << std::endl;
    std::cout << "Sum of Minor Diagonal of Matrix 1: " << mat1.sum_diagonal_minor() << std::endl;

    // Perform row swap (example: swapping row 0 and row 1)
    try {
        mat1.swap_rows(0, 1);
        std::cout << "\nMatrix 1 after swapping row 0 and row 1:\n";
        mat1.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << "Error in row swapping: " << e.what() << std::endl;
    }

    // Perform column swap (example: swapping column 0 and column 1)
    try {
        mat1.swap_cols(0, 1);
        std::cout << "\nMatrix 1 after swapping column 0 and column 1:\n";
        mat1.print_matrix();
    } catch (const std::exception &e) {
        std::cerr << "Error in column swapping: " << e.what() << std::endl;
    }

    return 0;
}