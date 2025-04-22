#include <iostream>
#include <vector>

int main() {
    // Define rows and columns
    int rows = 3, columns = 4;

    // Directly initialize a 3x4 matrix with default value 0
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(columns, 0));

    // Fill the matrix with values
    int value = 1;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = value++;
        }
    }

    // Print the matrix
    for (const auto &row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
