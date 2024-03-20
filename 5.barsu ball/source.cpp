#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1e9 + 7;

int findPairs(vector<int>& boys, vector<int>& girls) {
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());

    int boysIndex = 0;
    int girlsIndex = 0;
    int pairs = 0;

    while (boysIndex < boys.size() && girlsIndex < girls.size()) {
        if (abs(boys[boysIndex] - girls[girlsIndex]) <= 1) {
            ++pairs;
            ++boysIndex;
            ++girlsIndex;
        } else if (boys[boysIndex] < girls[girlsIndex]) {
            ++boysIndex;
        } else {
            ++girlsIndex;
        }
    }

    return pairs;
}

int main() {
    int n, m;
    cout << "Enter the number of skills of boys: ";
    cin >> n;

    vector<int> boys(n);
    cout << "Enter the skills of boys: ";
    for (int i = 0; i < n; ++i) {
        cin >> boys[i];
    }

    cout << "Enter the number of skills of girls: ";
    cin >> m;

    vector<int> girls(m);
    cout << "Enter the skills of girls: ";
    for (int i = 0; i < m; ++i) {
        cin >> girls[i];
    }

    int result = findPairs(boys, girls);
    cout << "Number of pairs: " << result << endl;

    return 0;
}
