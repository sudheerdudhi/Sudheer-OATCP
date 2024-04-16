#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int countCornerBlackSubgrids(vector<vector<int>>& grid) {
    int n = grid.size();
    int count = 0;

    // Loop through all possible top-left corners
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Check if the current cell is black
            if (grid[i][j] == 0) {
                // Loop through all possible bottom-right corners
                for (int k = i + 1; k < n; ++k) {
                    for (int l = j + 1; l < n; ++l) {
                        // Check if all corners are black
                        if (grid[i][l] == 0 && grid[k][j] == 0 && grid[k][l] == 0) {
                            // Increment count if all corners are black
                            ++count;
                        }
                    }
                }
            }
        }
    }

    return count;
}

int main() {
    ifstream infile("input1.txt");
    ofstream outfile("output1.txt");

    int n;
    infile >> n;

    // Input grid
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            infile >> grid[i][j];
        }
    }

    // Calculate the number of subgrids with all black corners
    int result = countCornerBlackSubgrids(grid);

    // Write the result to output file
    outfile << " Total number of subgrids whose all corners are all black : "<< result << endl;

    infile.close();
    outfile.close();

    return 0;
}
