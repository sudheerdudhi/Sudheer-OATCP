#include <iostream>
#include <vector>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    long long sum = 0;
    long long rotationSum = 0; 
    for (int i = 0; i < n; ++i) {
        sum += nums[i];
        rotationSum += i * nums[i];
    }

    long long maxRotate = rotationSum;

    for (int i = 1; i < n; ++i) {
        rotationSum += sum - n * nums[n - i]; 
        maxRotate = max(maxRotate, rotationSum); 
    }

    return maxRotate;
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

    int result = maxRotateFunction(nums);
    cout << "Maximum rotate value: " << result << endl;

    return 0;
}
