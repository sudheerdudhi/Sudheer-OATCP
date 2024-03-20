#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    int max_prod = nums[0];
    int min_prod = nums[0];
    int result = nums[0];

    for (int i = 1; i < n; ++i) {
        if (nums[i] < 0)
            swap(max_prod, min_prod);

        max_prod = max(nums[i], max_prod * nums[i]);
        min_prod = min(nums[i], min_prod * nums[i]);

        result = max(result, max_prod);
    }

    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid size of the array. Please enter a positive integer." << endl;
        return 1;
    }

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = maxProduct(nums);
    cout << "Maximum product of a subarray: " << result << endl;

    return 0;
}
