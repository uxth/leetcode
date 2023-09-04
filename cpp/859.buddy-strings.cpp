/*
 * @lc app=leetcode id=859 lang=cpp
 *
 * [859] Buddy Strings
 */

// @lc code=start
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size() || s.size() <= 1) return false;
        if(s == goal){
            unordered_set<char> st(begin(s), end(s));
            return st.size() < s.size();
        }
        vector<int> position;
        for(int i=0; i<s.size(); ++i){
            if(s[i] != goal[i]) position.push_back(i);
        }
        if(position.size() != 2) return false;
        swap(s[position[0]], s[position[1]]);
        return s == goal;
    }
};
// @lc code=end

