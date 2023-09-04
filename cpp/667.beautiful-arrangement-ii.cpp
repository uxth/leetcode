/*
 * @lc app=leetcode id=667 lang=cpp
 *
 * [667] Beautiful Arrangement II
 */

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> res(n);
        for (int i = 0, a = 1, z = k + 1; i <= k; i++)
            res[i] = i % 2 ? z-- : a++;
        for (int i = k+1; i < n; i++)
            res[i] = i + 1;
        return res;
    }
};
// @lc code=end

