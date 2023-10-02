/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start
class Solution {
public:
    int findGCD(vector<int>& nums) {
        auto [i, j] = minmax_element(begin(nums), end(nums));
        return gcd(*i, *j);
    }
};
// @lc code=end

