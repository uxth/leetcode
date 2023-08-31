/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 *
 * https://leetcode.com/problems/greatest-sum-divisible-by-three/description/
 *
 * algorithms
 * Medium (47.61%)
 * Likes:    477
 * Dislikes: 14
 * Total Accepted:    17K
 * Total Submissions: 35.8K
 * Testcase Example:  '[3,6,5,1,8]'
 *
 * Given an array nums of integers, we need to find the maximum possible sum of
 * elements of the array such that it is divisible by three.
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,6,5,1,8]
 * Output: 18
 * Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum
 * divisible by 3).
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4]
 * Output: 0
 * Explanation: Since 4 is not divisible by 3, do not pick any number.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,4,4]
 * Output: 12
 * Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum
 * divisible by 3).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 4 * 10^4
 * 1 <= nums[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    
    int maxSumDivThree(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        if(sum % 3 == 0) return sum;
        sort(nums.begin(), nums.end());
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<nums.size(); ++i) pq.push(make_pair(nums[i], i));
        while(!pq.empty())
        {
            int val = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            if(sum%3 == val%3) return sum-val;
            for(int i=idx+1; i<nums.size(); ++i)
            {
                pq.push(make_pair(val+nums[i], i));
            }
        }
        return 0;
    }
};
// @lc code=end

