/*
 * @lc app=leetcode id=1248 lang=cpp
 *
 * [1248] Count Number of Nice Subarrays
 *
 * https://leetcode.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (56.38%)
 * Likes:    504
 * Dislikes: 15
 * Total Accepted:    19.1K
 * Total Submissions: 33.6K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * Given an array of integers nums and an integer k. A subarray is called nice
 * if there are k odd numbers on it.
 * 
 * Return the number of nice sub-arrays.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,2,1,1], k = 3
 * Output: 2
 * Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and
 * [1,2,1,1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,4,6], k = 1
 * Output: 0
 * Explanation: There is no odd numbers in the array.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * Output: 16
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        vector<int> odds{-1};
        for(int i=0; i<nums.size(); ++i) if(nums[i] % 2) odds.push_back(i);
        odds.push_back(nums.size());
        if(odds.size() < k+2) return 0;
        int res = 0;
        for(int i=k+1; i<odds.size(); ++i)
            res += (odds[i]-odds[i-1]) * (odds[i-k]-odds[i-k-1]);
        return res;
    }
};
// @lc code=end

