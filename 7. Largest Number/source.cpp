#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool compareNums(const std::string &a, const std::string &b)
{
    return a + b > b + a;
}

std::string largestNumber(const std::vector<int> &nums)
{
    // Convert all integers to strings for easy concatenation
    std::vector<std::string> asStrings;
    for (int num : nums)
    {
        asStrings.push_back(std::to_string(num));
    }

    // Sort the strings using the custom comparator
    std::sort(asStrings.begin(), asStrings.end(), compareNums);

    // Handle the case where the largest number is 0 (to avoid "00...0")
    if (!asStrings.empty() && asStrings[0] == "0")
    {
        return "0";
    }

    // Concatenate all strings to form the largest number
    std::string largestNum;
    for (const std::string &numStr : asStrings)
    {
        largestNum += numStr;
    }

    return largestNum;
}

int main()
{
    
    freopen("input_2.txt", "r", stdin);
    freopen("output_2.txt", "w", stdout);
    int n;
    std::cin >> n; 

    std::vector<int> nums(n);
  
    for (int i = 0; i < n; ++i)
    {
        std::cin >> nums[i];
    }

    std::string result = largestNumber(nums);
    std::cout << "Largest number: " << result << std::endl;

    return 0;
}