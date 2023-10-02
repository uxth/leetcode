/*
 * @lc app=leetcode id=1981 lang=cpp
 *
 * [1981] Minimize the Difference Between Target and Chosen Elements
 */

// @lc code=start
class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bitset<2311> match(1);
        for(auto x: mat){
            bitset<2311> combine;
            for(auto y: x){
                combine |= (match << y);
            }
            match = combine;
        }
        int ans = INT_MAX;
        for(int i=0; i<2311; i++){
            if(match[i]) ans = min(ans, abs(i-target));
        }
        return ans;     
    }
};
// @lc code=end

