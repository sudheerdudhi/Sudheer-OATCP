#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

// Function to count the number of ways to construct sum n by throwing a dice
int countWays(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 6 && j <= i; ++j) {
            dp[i] = (dp[i] + dp[i - j]) % MOD;
        }
    }
    
    return dp[n];
}

int main() {
    int numSums;
    cout << "Enter the number of sums: ";
    cin >> numSums;

    for (int i = 0; i < numSums; ++i) {
        int n;
        cout << "Enter sum value " << i + 1 << ": ";
        cin >> n;
        int ways = countWays(n);
        cout << ways << endl;
    }

    return 0;
}
