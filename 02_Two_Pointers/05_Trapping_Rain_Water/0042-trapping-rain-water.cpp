/*
Problem: LeetCode 42 - Trapping Rain Water

Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Intuition:
To determine the amount of water that can be trapped, we need to consider the height of each bar and the width between the bars.
The amount of water trapped at a particular position depends on the minimum height of the tallest bars on its left and right sides minus the elevation.

Approach:
1. Initialize two pointers, `left` pointing to the start of the array (index 0), and `right` pointing to the end of the array.
2. Initialize variables `leftMax` and `rightMax` to keep track of the maximum heights encountered on the left and right sides.
3. Initialize a variable `water` to store the total trapped water.
4. Iterate while `left` is less than `right`:
   - If the height at `left` is less than or equal to the height at `right`:
     - Update `leftMax` with the maximum value between `leftMax` and the current height at `left`.
     - Calculate the amount of water that can be trapped at `left` by subtracting the height at `left` from `leftMax`.
     - Add the calculated water to the total `water` variable.
     - Increment `left`.
   - If the height at `left` is greater than the height at `right`:
     - Update `rightMax` with the maximum value between `rightMax` and the current height at `right`.
     - Calculate the amount of water that can be trapped at `right` by subtracting the height at `right` from `rightMax`.
     - Add the calculated water to the total `water` variable.
     - Decrement `right`.
5. Return the total trapped `water`.

Time Complexity:
The time complexity is O(n), where n is the number of elements in the input array. We iterate through the array once from both ends.

Space Complexity:
The space complexity is O(1) as we are using a constant amount of space to store the pointers and variables.
*/

class Solution {
  public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                leftMax = max(leftMax, height[left]);
                water += leftMax - height[left];
                left++;
            } else {
                rightMax = max(rightMax, height[right]);
                water += rightMax - height[right];
                right--;
            }
        }

        return water;
    }
};