/*
 * @lc app=leetcode id=1678 lang=cpp
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
public:
    string interpret(string command) {
        unordered_map<string, string> mp{
            {"G", "G"},
            {"()", "o"},
            {"(al)", "al"}
        };
        string res;
        for(int left = 0, i=1; left<command.size() && i<=command.size(); ++i){
            string sub = command.substr(left, i-left);
            if(!mp.count(sub)) continue;
            res += mp[sub];
            left = i;
        }
        return res;
    }
};
// @lc code=end

