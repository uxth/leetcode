/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 *
 * https://leetcode.com/problems/target-sum/description/
 *
 * algorithms
 * Medium (46.34%)
 * Likes:    2855
 * Dislikes: 117
 * Total Accepted:    177.6K
 * Total Submissions: 384.3K
 * Testcase Example:  '[1,1,1,1,1]\n3'
 *
 * You are given a list of non-negative integers, a1, a2, ..., an, and a
 * target, S. Now you have 2 symbols + and -. For each integer, you should
 * choose one from + and - as its new symbol.
 * 
 * Find out how many ways to assign symbols to make sum of integers equal to
 * target S.
 * 
 * Example 1:
 * 
 * 
 * Input: nums is [1, 1, 1, 1, 1], S is 3. 
 * Output: 5
 * Explanation: 
 * 
 * -1+1+1+1+1 = 3
 * +1-1+1+1+1 = 3
 * +1+1-1+1+1 = 3
 * +1+1+1-1+1 = 3
 * +1+1+1+1-1 = 3
 * 
 * There are 5 ways to assign symbols to make the sum of nums be target 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The length of the given array is positive and will not exceed 20.
 * The sum of elements in the given array will not exceed 1000.
 * Your output answer is guaranteed to be fitted in a 32-bit integer.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int dynamicprogramming(vector<int>& nums, int s)
    {
        unordered_map<int, int> dp;
        dp[0] = 1;
        for (int num : nums) {
            unordered_map<int, int> t;
            for (auto& [sum,cnt] : dp) {
                t[sum + num] += cnt;
                t[sum - num] += cnt;
            }
            dp = move(t);
        }
        return dp[s];
    }
    int dfshelper(vector<int>& nums, int i, int sum, int s, vector<unordered_map<long,int>>& dp)
    {
        if(i==nums.size())
        {
            if(sum == s) return dp[i][sum]=1;
            return 0;
        }
        if(dp[nums.size()-1-i][s-sum]) return dp[nums.size()-1-i][s-sum];
        int pos = dfshelper(nums, i+1, sum+nums[i], s, dp);
        int neg = dfshelper(nums, i+1, sum-nums[i], s, dp);
        return dp[nums.size()-1-i][s-sum] = neg + pos;
    }
    int dfs(vector<int>& nums, int s )
    {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<unordered_map<long,int>> dp(nums.size()+1);
        return dfshelper(nums, 0, 0, s, dp);
    }
    int findTargetSumWays(vector<int>& nums, int s) {
        return dynamicprogramming(nums, s);
        // return dfs(nums,s);
    }

};
// @lc code=end
// [2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53]\n1000
// [1,1,1,1,1]\n3

// [46,49,5,7,5,21,27,4,4,27,45,24,7,22,25,5,38,14,50,28]\n45
// [2,107,109,113,127,131,137,3,2,3,5,7,11,13,17,19,23,29,47,53]\n2147483647
// [16,40,9,17,49,32,30,10,38,36,31,22,3,36,32,2,26,17,30,47]]\n49