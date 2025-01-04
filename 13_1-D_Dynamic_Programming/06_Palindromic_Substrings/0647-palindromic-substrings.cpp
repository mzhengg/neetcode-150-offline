/*
Problem: LeetCode 647 - Palindromic Substrings

Description:
Given a string s, return the number of palindromic substrings in s.
A substring is a contiguous sequence of characters within the string.

Intuition:
To count the number of palindromic substrings, we can use a two-pointer approach.
We iterate through each character in the string and treat it as a potential center of a palindrome.
By expanding from the center, we check if the substring formed is a palindrome and count it as a valid palindrome.

Approach:
1. Initialize a variable count to keep track of the number of palindromic substrings.
2. Iterate through each character in the string:
   - Consider each character as the center of a potential palindrome.
   - Expand around the center using two pointers, one on each side.
   - Count all valid palindromes found during expansion.
3. Return the count of palindromic substrings.

Time Complexity:
The time complexity is O(n^2), where n is the length of the input string s. We iterate through the string and perform expansion for each character.

Space Complexity:
The space complexity is O(1) since we only use a few variables to store indices and counts.
*/

// Better solution but not dynamic programming
class Solution {
  public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            count += countPalindromes(s, i, i);      // Odd-length palindromes
            count += countPalindromes(s, i, i + 1);  // Even-length palindromes
        }

        return count;
    }

    int countPalindromes(string s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};