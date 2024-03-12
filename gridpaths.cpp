#include <iostream>
#include <vector>

using namespace std;

int countPaths(vector<vector<bool>>& grid, int n) {
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    
    // Base case: Initialize the first row and first column
    dp[0][0] = (grid[0][0]) ? 0 : 1;
    for (int i = 1; i < n; ++i) {
        if (grid[i][0]) {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int j = 1; j < n; ++j) {
        if (grid[0][j]) {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }
    
    // Calculate number of paths for each cell
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j]) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
            }
        }
    }
    
    return dp[n - 1][n - 1];
}

int main() {
    int n;
    cout << "Enter the size of the grid: ";
    cin >> n;

    vector<vector<bool>> grid(n, vector<bool>(n));
    cout << "Enter the grid (use '*' for trap and '.' for empty cell):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char cell;
            cin >> cell;
            grid[i][j] = (cell == '*');
        }
    }

    int result = countPaths(grid, n);
    cout << "Number of paths from the upper-left square to the lower-right square: " << result << endl;

    return 0;
}
