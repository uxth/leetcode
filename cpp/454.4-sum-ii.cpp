// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem454.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> s;
        int res = 0;
        for(int i : nums1) for(int j : nums2) s[i+j]++;
        for(int i : nums3) for(int j : nums4) res += s.count(0 - i - j) ? s[0-i-j] : 0;
        return res;
    }
};
// @lc code=end

