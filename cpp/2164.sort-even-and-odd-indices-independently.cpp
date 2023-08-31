/*
 * @lc app=leetcode id=2164 lang=cpp
 *
 * [2164] Sort Even and Odd Indices Independently
 */

// @lc code=start
class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> even, odd;
        for(int i=0; i<nums.size(); ++i) {
            if(i%2) odd.push_back(nums[i]);
            else even.push_back(nums[i]);
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), less<int>());
        vector<int> res(nums.size());
        for(int i=0; i<nums.size(); ++i) {
            if(i%2) res[i] = odd[i/2];
            else res[i] = even[i/2];
        }
        return res;
    }
};
// @lc code=end

