#include <iostream>
#include <vector>

int main() {
    // Declare a vector of vectors of integers
    std::vector<std::vector<int>> matrix;

    // Define the dimensions of the matrix (rows and columns)
    int rows = 3;
    int columns = 4;

    // Resize the outer vector to the number of rows
    matrix.resize(rows);

    // Resize each inner vector to the number of columns
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(columns);
    }

    // Fill the matrix with values (for demonstration purposes)
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Access and print the elements of the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
