#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int totalDistance = 0;
        int n = nums.size();
        
        for (int i = 0; i < 32; ++i) {
            int countOnes = 0;
            for (int j = 0; j < n; ++j) {
                countOnes += (nums[j] >> i) & 1;
            }
            totalDistance += countOnes * (n - countOnes);
        }
        
        return totalDistance;
    }
};

int main() {
    ifstream infile("input1.txt");
    ofstream outfile("output1.txt");

    Solution sol;
    int n;
    infile >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        infile >> nums[i];
    }
    outfile << "Total Hamming Distance of all the nums in the array : "  <<  sol.totalHammingDistance(nums) << endl;

    infile.close();
    outfile.close();
    
    return 0;
}
