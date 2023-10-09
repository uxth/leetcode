/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> res;
        for(int i : arr){
            res.emplace_back(i);
            if(i==0) res.emplace_back(i);
        }
        res.resize(arr.size());
        arr = res;
    }
};
// @lc code=end

