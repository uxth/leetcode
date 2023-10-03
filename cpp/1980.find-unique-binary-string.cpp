/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 */

// @lc code=start
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        int limit = 1 << n;
        
        unordered_set<string> st(begin(nums), end(nums));
        for(int i=0; i<limit; ++i){
            string data = "";
            for(int j=(1<<(n-1)); j>0; j=(j>>1)){
                data += (j & i) > 0 ? "1" : "0";
            }
            if(st.count(data) == 0) return data;
        }
        return "";
    }
};
// @lc code=end

