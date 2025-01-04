/*
Problem: LeetCode 217 - Contains Duplicate

Intuition:
To solve this problem, we can utilize the property of a hash set. By storing each element encountered in the set and checking for collisions, we can efficiently determine if any duplicates exist in the array. If a collision occurs, it indicates the presence of a duplicate element.

Approach:
1. Initialize an empty hash set.
2. Iterate through each element num in the input array nums:
    - If num is already present in the hash set, return true as we have found a duplicate.
    - Otherwise, add num to the hash set.
3. If no duplicates are found after iterating through all elements, return false.

Time Complexity:
The time complexity of this approach is O(n), where n is the size of the input array nums. This is because we iterate through the array once and perform constant-time operations for each element.

Space Complexity:
The space complexity is O(n), as the hash set can potentially store all elements of the input array.
*/

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true; // Duplicate found
            }

            seen.insert(num);
        }

        return false; // No duplicates found
    }
};