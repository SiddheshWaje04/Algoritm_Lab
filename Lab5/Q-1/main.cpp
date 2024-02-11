#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS to find the size of the region
int dfs(vector<vector<int>>& matrix, int row, int col, int rows, int cols) {
    if (row < 0 || col < 0 || row >= rows || col >= cols || matrix[row][col] == 0)
        return 0;

    // Marking current cell as visited by setting it to '0'
    matrix[row][col] = 0;

    // Variables to store the size of the region
    int size = 1;

    // Iterating over all adjacent cells (including diagonals)
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            size += dfs(matrix, row + i, col + j, rows, cols);
        }
    }
    return size;
}

// Function to find the size of the largest region
int largestRegionSize(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Variable to store the maximum region size
    int maxRegionSize = 0;

    // Iterating through each cell in the matrix
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            // If the cell contains '1', performing DFS to find region size
            if (matrix[i][j] == 1) {
                int regionSize = dfs(matrix, i, j, rows, cols);
                maxRegionSize = max(maxRegionSize, regionSize);
            }
        }
    }
    return maxRegionSize;
}

int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 0, 0, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {1, 0, 0, 0, 1}
    };

    // Finding the size of the largest region
    int largestSize = largestRegionSize(matrix);
    cout << "Size of the largest region: " << largestSize << endl;

    return 0;
}
