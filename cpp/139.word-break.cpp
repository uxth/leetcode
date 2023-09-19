/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool bfs(string& s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        queue<string> q;
        q.push(s);
        while(!q.empty()){
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
    bool dp(string& s, vector<string>& wordDict){
        unordered_set<string> dict(begin(wordDict),end(wordDict));
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i=1; i<=s.size(); ++i){
            for(int j=i-1; j>=0; --j){
                string sub = s.substr(j, i-j);
                if(dict.count(sub) && dp[j]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
    bool wordBreak(string s, vector<string>& wordDict){
        return dp(s, wordDict);
    }
};
// @lc code=end
/*
"catsandog"\n["cats","dog","sand","and","cat"]
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
*/
