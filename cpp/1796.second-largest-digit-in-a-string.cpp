/*
 * @lc app=leetcode id=1796 lang=cpp
 *
 * [1796] Second Largest Digit in a String
 */

// @lc code=start
class Solution {
public:
    int secondHighest(string s) {
        set<int> data;
        for(char c : s){
            if(isdigit(c)){
                data.insert(c-'0');
            }
        }
        if(data.size() <= 1) return -1;
        return *prev(prev(data.end()));
    }
};
// @lc code=end

