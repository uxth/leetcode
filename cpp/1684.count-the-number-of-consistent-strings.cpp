/*
 * @lc app=leetcode id=1684 lang=cpp
 *
 * [1684] Count the Number of Consistent Strings
 */

// @lc code=start
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> mp(256, false);
        for(char c : allowed) mp[c] = true;
        int res = 0;
        for(string& s : words) {
            res += all_of(begin(s), end(s), [&](auto& c){return mp[c];}) ? 1 : 0;
        }
        return res;
    }
};
// @lc code=end

