/*
 * @lc app=leetcode id=327 lang=cpp
 *
 * [327] Count of Range Sum
 *
 * https://leetcode.com/problems/count-of-range-sum/description/
 *
 * algorithms
 * Hard (35.80%)
 * Likes:    980
 * Dislikes: 111
 * Total Accepted:    48.4K
 * Total Submissions: 134.4K
 * Testcase Example:  '[-2,5,-1]\n-2\n2'
 *
 * Given an integer array nums, return the number of range sums that lie in
 * [lower, upper] inclusive.
 * Range sum S(i, j) is defined as the sum of the elements in nums between
 * indices i and j (i ≤ j), inclusive.
 * 
 * Note:
 * A naive algorithm of O(n^2) is trivial. You MUST do better than that.
 * 
 * Example:
 * 
 * 
 * Input: nums = [-2,5,-1], lower = -2, upper = 2,
 * Output: 3 
 * Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
 * sums are: -2, -1, 2.
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= nums.length <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long> s{0};
        long result = 0, sum = 0;
        for (int n : nums)
        {
            sum += n;
            auto itUpperB = s.upper_bound(sum - lower);
            auto itLowerB = s.lower_bound(sum - upper);
            result += distance(itLowerB, itUpperB);
            s.insert(sum);
        }
        return result;
    }
};
// @lc code=end
// [1,2,3,-1,-1,-1,-1]\n1\n3
