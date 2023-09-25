/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> c(nums.size()+1);
        c[0] = 1;
        // unordered_map<int, int> c({{0, 1}});
        int psum = 0, res = 0;
        for (int i : nums) {
            psum += i;
            res += psum >= goal ? c[psum - goal] : 0;
            c[psum]++;
        }
        return res;
    }
};
// @lc code=end
/*
[0,0,0,0,0]\n0
*/
