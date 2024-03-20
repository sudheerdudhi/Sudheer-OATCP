#include <iostream>
#include <vector>
#include <fstream> // For file handling

#define ll long long int
#define mod 1000000007

using namespace std;

ll solve(vector<string> &grid, ll N)
{
    // dp[][] array such that dp[i][j] stores the number of
    // ways to reach cell(i, j) from cell(0, 0)
    vector<vector<ll>> dp(N, vector<ll>(N, 0));

    // Finding the number of ways for the first column
    for (int i = 0; i < N; i++)
    {
        if (grid[i][0] == '*')
            break;
        dp[i][0] = 1;
    }

    // Finding the number of ways for the first row
    for (int j = 0; j < N; j++)
    {
        if (grid[0][j] == '*')
            break;
        dp[0][j] = 1;
    }

    // Finding the number of ways for the remaining grid
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            // If the cell is blocked, then move to the next
            // cell
            if (grid[i][j] == '*')
                continue;

            // The number of ways to reach cell(i, j) =
            // number of ways to reach cell (i-1,j) + number
            // of ways to reach cell(i,j-1)
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }

    // Return the number of ways to reach the last cell of the grid
    return dp[N - 1][N - 1];
}

int main()
{
    // Opening input and output files
    ifstream infile("input2.txt");
    ofstream outfile("output2.txt");

    // Redirecting input and output streams to files
    streambuf *cinbuf = cin.rdbuf();
    streambuf *coutbuf = cout.rdbuf();
    cin.rdbuf(infile.rdbuf());
    cout.rdbuf(outfile.rdbuf());

    // Sample Input
    ll N;
    cin >> N;
    vector<string> grid(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> grid[i];
    }

    // Calculate result
    ll result = solve(grid, N);

    // Output result
    cout << result << "\n";

    // Closing input and output files
    infile.close();
    outfile.close();

    // Restoring standard input and output streams
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);

    return 0;
}