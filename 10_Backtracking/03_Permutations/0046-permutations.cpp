/*
Problem: LeetCode 46 - Permutations

Description:
Given an array nums of distinct integers, return all possible permutations of the elements in nums.
You can return the answer in any order.

Intuition:
To find all possible permutations of a given array, we can use a backtracking approach. The idea is to generate all possible arrangements by trying out different elements at each step.
We explore each element, including it in the current permutation if it hasn't been used before. By backtracking, we generate all valid permutations.

Approach:
1. Initialize an empty vector `permutation` to store the current permutation.
2. Initialize an empty vector `result` to store all valid permutations.
3. Define a helper function `backtrack`:
   - If the size of the current permutation is equal to the size of the input array `nums`, add the current permutation to the `result` vector.
   - Otherwise:
     - Iterate through the elements in the input array `nums`:
       - If the current element is already in the permutation, skip it to avoid duplicates.
       - Include the current element in the permutation.
       - Recursively call `backtrack` with the updated permutation.
       - Exclude the current element from the permutation (backtrack).
4. Call the `backtrack` function with an empty permutation.
5. Return the `result` vector containing all valid permutations.

Time Complexity:
The time complexity is O(N!), where N is the size of the input array `nums`. This is because there are N! possible permutations, and we generate all of them.

Space Complexity:
The space complexity is O(N), where N is the size of the input array `nums`. This is because we store the permutations in the `result` vector.
*/

class Solution {
  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);  // Track used elements to avoid duplicates
        backtrack(nums, used, permutation, result);
        return result;
    }

  private:
    void backtrack(const vector<int> &nums, vector<bool> &used, vector<int> &permutation, vector<vector<int>> &result) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;  // Skip already used elements
            }

            used[i] = true;  // Mark the current element as used
            permutation.push_back(nums[i]);  // Include the current element in the permutation
            backtrack(nums, used, permutation, result);  // Recursively call with updated permutation
            permutation.pop_back();  // Exclude the current element (backtrack)
            used[i] = false;  // Mark the current element as unused for other permutations
        }
    }
};