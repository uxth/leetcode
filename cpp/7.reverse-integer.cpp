/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        if(x == __INT32_MAX__) return 0;
        long xx = abs(long(x));
        long res = 0;
        while(xx > 0)
        {
            res = res * 10 + xx % 10;
            xx /= 10;
        }
        res = res > __INT32_MAX__ ? 0 : res;
        return x > 0 ? res : (-res);
    }
};
// @lc code=end

