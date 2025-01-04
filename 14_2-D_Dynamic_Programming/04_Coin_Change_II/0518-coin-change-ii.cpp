/*
Problem: LeetCode 518 - Coin Change 2

Description:
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Intuition:
To find the number of combinations that make up the amount, we can use dynamic programming.
At each step, we can decide whether to include a coin or not.
The key idea is to track the number of combinations for each amount up to the target amount.

Approach:
1. Initialize a 1D array dp of size (amount + 1) and set dp[0] = 1, representing the base case where there is one way to make up an amount of 0.
2. Iterate through the coins array:
   - For each coin, iterate through the amounts from coin to the target amount:
     - Update the dp[j] by adding the number of combinations for the amount j - coin.
3. Return dp[amount], which represents the number of combinations that make up the target amount.

Time Complexity:
The time complexity is O(coins * amount), where coins is the number of coins and amount is the target amount.

Space Complexity:
The space complexity is O(amount) as we only need a 1D array to store the number of combinations.

Dynamic Programming:
- Subproblem: The subproblem is finding the number of combinations for each amount up to the target amount.
- Recurrence Relation: dp[j] = dp[j] + dp[j - coin], where dp[j] represents the number of combinations for the amount j.
- Base Case: Initialize dp[0] = 1, representing one way to make up an amount of 0.
*/

class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        // Create a DP array to store the number of combinations
        // dp[i] represents the number of combinations to make amount i
        vector<int> dp(amount + 1, 0);
        // Base case: There is one combination to make amount 0, using no coins
        dp[0] = 1;

        // Iterate over the coins
        for (int coin : coins) {
            // For each coin, iterate over the amounts starting from the coin value
            for (int i = coin; i <= amount; ++i) {
                // For each amount, add the number of combinations from the current amount minus the coin value
                // This accounts for using the current coin to make the remaining amount
                // We sum up these combinations for all the coins to get the total number of combinations for the current amount
                dp[i] += dp[i - coin];
            }
        }

        // Return the number of combinations to make the given amount using the coins
        return dp[amount];
    }
};