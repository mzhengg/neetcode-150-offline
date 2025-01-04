/*
Problem: LeetCode 76 - Minimum Window Substring

Description:
Given two strings `s` and `t`, return the minimum window in `s` that contains all the characters of `t`.
If there is no such window in `s` that covers all characters in `t`, return an empty string.

Intuition:
To find the minimum window substring, we can use the sliding window technique.
The idea is to maintain two pointers, `left` and `right`, to create a window in `s`.
By expanding and contracting the window, we can find the minimum window substring that contains all the characters of `t`.

Approach:
1. We start by initializing two pointers, `left` and `right`, to the first index of `s`.
2. We initialize two frequency maps, `targetFreq` and `windowFreq`, to store the frequencies of characters in `t` and the current window of `s`, respectively.
3. We initialize variables, `count` and `minLen`, to keep track of the count of characters in `t` that are present in the current window and the minimum window length found so far.
4. We iterate through `s` using the `right` pointer:
   - Increment the frequency of the character at `s[right]` in `windowFreq`.
   - If the frequency of the character at `s[right]` in `windowFreq` is less than or equal to the frequency of the same character in `targetFreq`, increment the `count`.
   - If `count` is equal to the length of `t`, it means we have found a valid window that contains all the characters of `t`.
     - Update `minLen` if the current window length is smaller.
     - Move the `left` pointer to contract the window:
       - Decrement the frequency of the character at `s[left]` in `windowFreq`.
       - If the frequency of the character at `s[left]` in `windowFreq` becomes less than the frequency in `targetFreq`, decrement the `count`.
     - Move the `left` pointer to the right to search for the next valid window.
5. Repeat steps 4 and 5 until the `right` pointer reaches the end of `s`.
6. Return the minimum window substring found based on `minLen`. If no valid window is found, return an empty string.

Time Complexity:
The time complexity is O(n), where n is the length of `s`. We iterate through `s` once using the sliding window approach.

Space Complexity:
The space complexity is O(1) as both `targetFreq` and `windowFreq` have a fixed size of 128 to represent ASCII characters.
*/

class Solution {
  public:
    string minWindow(string s, string t) {
        vector<int> targetFreq(128, 0);
        vector<int> windowFreq(128, 0);

        for (char ch : t) {
            targetFreq[ch]++;
        }

        int left = 0;
        int right = 0;
        int count = 0;
        int minLen = INT_MAX;
        int minStart = 0;

        while (right < s.length()) {
            windowFreq[s[right]]++;

            if (windowFreq[s[right]] <= targetFreq[s[right]]) {
                count++;
            }

            while (count == t.length()) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minStart = left;
                }

                windowFreq[s[left]]--;

                if (windowFreq[s[left]] < targetFreq[s[left]]) {
                    count--;
                }

                left++;
            }

            right++;
        }

        return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
    }
};