#include <iostream>
#include <vector>
#include <algorithm> // For std::sort

// Function to calculate the maximum number of ice cream bars the boy can buy
// This function implements a greedy algorithm.
int maxIceCreamBars(std::vector<int> &costs, int coins)
{
    // Sort the costs in ascending order to always pick the cheapest option next
    std::sort(costs.begin(), costs.end());

    int count = 0; // Initialize count of ice cream bars the boy can buy
    for (int price : costs)
    {
        if (coins >= price)
        {                   // Check if the boy can afford this bar
            coins -= price; // Subtract the cost from his total coins
            count++;        // Increment the count, making the greedy choice to buy
        }
        else
        {
            // Cannot afford the next bar, so we've found the maximum number he can buy
            break;
        }
    }
    return count; // Return the total number of ice cream bars the boy can buy
}

int main()
{
    // below in freopen both line of code is changable acordangly input 
    freopen("input_3.txt", "r", stdin); 
    freopen("output_3.txt", "w", stdout);
    int n, coins;
    std::cin >> n; // User inputs the number of ice cream bars

    std::vector<int> costs(n); // Vector to store the costs of ice cream bars
    for (int i = 0; i < n; ++i)
    {
        std::cin >> costs[i]; // User inputs the cost of each ice cream bar
    }

    std::cin >> coins; // User inputs the total amount of coins the boy has

    // Calculate and display the result
    std::cout << "The maximum number of ice cream bars the boy can buy is: "
              << maxIceCreamBars(costs, coins) << std::endl;

    return 0;
}