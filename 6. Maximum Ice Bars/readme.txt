Algorithm  
1. Sort the Costs: Sort the costs of ice cream bars in ascending order. This helps in ensuring
   that we always choose the cheapest available option first.

2. Initialize Count: Set a variable, let's call it 'count', to keep track of the number of ice
   cream bars the boy can buy. Start with count = 0.  
3. Iterate Over Costs:

    For each cost in the sorted list:
      Check if the boy has enough coins to buy the ice cream bar at this cost.
    If he does:
      Subtract the cost of the ice cream bar from his total coins.
      Increment the count of ice cream bars he can buy.
    If he doesn't have enough coins:
      Break out of the loop since he can't buy any more ice cream bars.

4. Output: Once the loop ends, return the count. This represents the maximum number of ice cream
   bars the boy can buy given his budget.
   