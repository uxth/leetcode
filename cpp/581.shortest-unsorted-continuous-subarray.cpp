/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 *
 * https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
 *
 * algorithms
 * Medium (34.13%)
 * Likes:    7614
 * Dislikes: 258
 * Total Accepted:    316.2K
 * Total Submissions: 862.8K
 * Testcase Example:  '[2,6,4,8,10,9,15]'
 *
 * Given an integer array nums, you need to find one continuous subarray such
 * that if you only sort this subarray in non-decreasing order, then the whole
 * array will be sorted in non-decreasing order.
 * 
 * Return the shortest such subarray and output its length.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,6,4,8,10,9,15]
 * Output: 5
 * Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make
 * the whole array sorted in ascending order.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3,4]
 * Output: 0
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -10^5 <= nums[i] <= 10^5
 * 
 * 
 * 
 * Follow up: Can you solve it in O(n) time complexity?
 */

// @lc code=start
class Solution {
public:
    int useStack(vector<int>& nums){
        int n = nums.size();
        int start = n;
        int end = -1;
        stack<int> inc, dec;

        for(int i=0; i<n; ++i){
            while(!inc.empty() && nums[i] < nums[inc.top()]) {
                start = min(start, inc.top());
                inc.pop();
            }
            inc.push(i);

            while(!dec.empty() && nums[n-i-1] > nums[dec.top()]){
                end = max(end, dec.top());
                dec.pop();
            }
            dec.push(n-i-1);
        }
        if(end == -1) return 0;
        return end - start + 1;

    }
    int useConst(vector<int>& nums){
        int n = nums.size();
        int end = -1;
        int mx = nums[0];
        int start = n;
        int mn = nums[n-1];
        for(int i=0; i<n; ++i){
            mx = max(mx, nums[i]);
            if(mx > nums[i]) end = i;

            int j = n-1-i;
            mn = min(mn, nums[j]);
            if(mn < nums[j]) start = j;
        }

        if(end == -1) return 0;
        return end - start + 1;
    }
    int findUnsortedSubarray(vector<int>& nums) {
        // return useStack(nums);
        return useConst(nums);
    }
};
// @lc code=end

