/*
Problem: LeetCode 424 - Longest Repeating Character Replacement

Description:
Given a string `s` that consists of only uppercase English letters, you can perform at most `k` operations on that string.
In one operation, you can choose any character of the string and change it to any other uppercase English letter.
Find the length of the longest substring containing repeating letters you can get after performing the above operations.

Intuition:
To find the longest substring with repeating characters, we can use a sliding window approach.
We can maintain a window that contains the most frequent character and update it as we expand the window.
The maximum length of the substring with repeating characters can be obtained by considering the count of the most frequent character within the window.

Approach:
1. Initialize variables `maxCount` and `maxLength` to track the maximum count of a character and the maximum length of the substring with repeating characters.
2. Initialize a vector `count` to keep track of the count of each character.
3. Initialize variables `left` and `right` to represent the left and right pointers of the sliding window.
   - Set both `left` and `right` to 0 initially.
4. Iterate while `right` is less than the length of the string:
   - Increment the count of the character at `right` in the `count` vector.
   - Update `maxCount` with the maximum value between `maxCount` and the current count.
   - Calculate the length of the current substring as `right - left + 1`.
   - If the length of the current substring minus `maxCount` is greater than `k`:
     - Decrement the count of the character at `left` in the `count` vector.
     - Increment `left` to shrink the window.
   - Update `maxLength` with the maximum value between `maxLength` and the current substring length.
   - Increment `right` to expand the window.
5. Return `maxLength`, which represents the length of the longest substring with repeating characters that can be obtained.

Time Complexity:
The time complexity is O(n), where n is the length of the input string. We iterate through the string once with the sliding window approach.

Space Complexity:
The space complexity is O(1) as we are using a fixed-size vector `count` to store the count of characters.
*/

class Solution {
  public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int left = 0, right = 0;
        int maxCount = 0, maxLength = 0;

        while (right < s.length()) {
            count[s[right] - 'A']++;
            maxCount = max(maxCount, count[s[right] - 'A']);

            if ((right - left + 1) - maxCount > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};