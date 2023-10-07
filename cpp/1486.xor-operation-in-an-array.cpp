/*
 * @lc app=leetcode id=1486 lang=cpp
 *
 * [1486] XOR Operation in an Array
 */

// @lc code=start
class Solution {
public:
    int xorOperation(int n, int start) {
        int res = 0;
        for(int i=0; i<n; ++i)
            res = res ^ (start + 2 * i);
        return res;
    }
};
// @lc code=end

