/*
 * @lc app=leetcode id=1716 lang=cpp
 *
 * [1716] Calculate Money in Leetcode Bank
 */

// @lc code=start
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int res = weeks > 0 ? 28 * weeks + (weeks - 1) * weeks * 7 / 2 : 0;
        res += (1+weeks) * days + days * (days - 1) / 2;
        return res;
    }
};
// @lc code=end

