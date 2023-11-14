/*

Question
Formatted question description: https://leetcode.ca/all/259.html

Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

 

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
[-2,0,1]
[-2,0,3]
Example 2:

Input: nums = [], target = 0
Output: 0
Example 3:

Input: nums = [0], target = 0
Output: 0
 

Constraints:

n == nums.length
0 <= n <= 3500
-100 <= nums[i] <= 100
-100 <= target <= 100
Algorithm
The follow up in the title allows us to achieve it within O(n^2) time complexity. Then learn from the methods in the previous two questions 3Sum Closest and 3Sum, and use double pointers to do it.

There is a trick here that is to judge When the sum of three numbers is less than the target value, right-left should be added to the result at this time, because after the array is sorted, if the addition of num[right] is less than the target value, then adding a smaller number must also be less than Target value, then move the left pointer to the right by one place, otherwise move the right pointer to the left by one place,
*/
// OJ: https://leetcode.com/problems/3sum-smaller/
// Time: O(N^2)
// Space: O(1)
class Solution {
private:
    int twoSumSmaller(vector<int>& nums, int start, int target) {
        int i = start, j = nums.size() - 1, ans = 0;
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                ans += j - i;
                ++i;
            } else --j;
        }
        return ans;
    }
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int N = nums.size(), ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < N; ++i)
            ans += twoSumSmaller(nums, i + 1, target - nums[i]);
        return ans;
    }
};