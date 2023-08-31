/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (34.06%)
 * Likes:    2771
 * Dislikes: 430
 * Total Accepted:    293.9K
 * Total Submissions: 859K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */

// @lc code=start
class Solution {
public:

    vector<string> dfs(string s, vector<string>& wordDict, unordered_map<string, vector<string>>& m) {
        if (m.count(s)) return m[s];
        if (s.empty()) return {""};
        for (string word : wordDict) {
            if (s.substr(0, word.size()) != word) continue;
            vector<string> rem = dfs(s.substr(word.size()), wordDict, m);
            for (string str : rem) {
                m[s].push_back(word + (str.empty() ? "" : " ") + str);
            }
        }
        return m[s];
    }
    vector<string> topdowndp(string s, vector<string>& wordDict)
    {
        unordered_map<string, vector<string>> m;
        return dfs(s, wordDict, m);
    }

    vector<string> bfs(string s, vector<string>& wordDict)
    {
        queue<pair<string,string>> q;
        for(string& w : wordDict) if(s.substr(0, w.size()) == w) q.push({w,w});
        vector<string> res;
        while(!q.empty())
        {
            string f = q.front().first;
            string data = q.front().second;
            q.pop();
            if(f==s) res.push_back(data);
            for(string& w : wordDict)
            {
                string next = f + w;
                if(s.substr(0, next.size()) == next) q.push({next, data + " " + w});
            }
        }
        return res;
    }
    vector<string> dynamicprogramming(string s, vector<string>& wordDict)
    {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(s.size());
        for(int i=0; i<s.size(); ++i)
        {
            for(int j=i; j>=0; --j)
            {
                string sub = s.substr(j, i-j+1);
                if(dict.count(sub) && (j>0&&!dp[j-1].empty() || j==0))
                {
                    if(j==0)
                    {
                        dp[i].push_back({sub});
                    }
                    else
                    {
                        vector<string> tmp(dp[j-1]);
                        for(auto& t : tmp) t+=" "+sub;
                        dp[i].insert(dp[i].end(), tmp.begin(), tmp.end());
                    }
                }
            }
        }
        return dp.back();
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // return topdowndp(s, wordDict);
        // return bfs(s, wordDict);
        return dynamicprogramming(s, wordDict);
    }
};
// @lc code=end
// "pineapplepenapple"\n["apple", "pen", "applepen", "pine", "pineapple"]
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

// "catsandog"\n["cats","dog","sand","and","cat"]