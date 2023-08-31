/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (43.65%)
 * Likes:    3072
 * Dislikes: 74
 * Total Accepted:    203.4K
 * Total Submissions: 462.5K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(),sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        sort(nums.begin(),nums.end(),greater<int>());
        return dfsSum(nums,sum/2,0);
    }
    bool dfsSum(vector<int>& nums,int sum,int i){
        if(i==nums.size()) return false;
        if(sum == nums[i]) return true;
        if(sum < nums[i]) return false;
        return dfsSum(nums,sum-nums[i],i+1) || dfsSum(nums,sum,i+1);
    }
};
// @lc code=end

