#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long long int req = 1;
        int i = 0;
        int ret = 0;
        while (req <= n)
        {
            if (i < nums.size() && nums[i] <= req)
            {
                req += nums[i];
                i++;
            }
            else
            {
                req += req;
                ret++;
            }
        }
        return ret;
    }
};

int main()
{
    // below in freopen both line of code is changable acordangly input
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
    Solution ob;
    vector<int> v;
    int size, num, n;
    
    // cout << "Enter the size of the vector: ";
    cin >> size;
    // cout << "Enter " << size << " elements of the vector:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> num;
        v.push_back(num);
    }

    // cout << "Enter the value of n: ";
    cin >> n;

    cout << "Minimum patches required: " << ob.minPatches(v, n) << endl;

    return 0;
}