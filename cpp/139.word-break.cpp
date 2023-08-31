/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<string> q;
        q.push(s);
        while(!s.empty()){
            string f = q.front(); q.pop();
            if(dict.count(f)) return true;
            for(int i=1; i<f.size(); ++i){
                string sub = f.substr(0, i);
                if(dict.count(sub)) {
                    q.push(f.substr(i));
                }
            }
        }
        return false;
    }
};
// @lc code=end

