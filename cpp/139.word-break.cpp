/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (41.28%)
 * Likes:    5820
 * Dislikes: 277
 * Total Accepted:    685.5K
 * Total Submissions: 1.7M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
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
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool dfs(string& s, int start, unordered_set<string>& dict, unordered_map<string, bool>& dp)
    {
        string sub = s.substr(start);
        if(dp.count(sub)) return dp[sub];
        if(dict.count(sub))
        {
            dp[sub] = true;
            return true;
        }
        for(int i=start; i<s.size(); ++i)
        {
            if(dict.count(s.substr(start, i-start+1)) && dfs(s, i+1, dict, dp))
                return true;
        }
        dp[sub] = false;
        return false;
    }
    bool topdowndp(string s, vector<string>& wordDict)
    {
        unordered_map<string, bool> dp; 
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return dfs(s, 0, dict, dp);
    }
    bool bottomupdp(string s, vector<string>& wordDict)
    {
        vector<bool> dp(s.size()+1, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for(int i=1; i<=s.size(); ++i)
        {
            for(int j=i-1; j>=0; --j)
            {
                if(dp[j] && dict.count(s.substr(j, i-j)))
                {
                    dp[i] = true; break;
                }
            }
        }
        return dp.back();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // return topdowndp(s, wordDict);
        return bottomupdp(s, wordDict);
    }
};
// @lc code=end
// "applepenapple"\n["apple", "pen"]
// "catsandog"\n["cats", "dog", "sand", "and", "cat"]
// "applepenapple"\n["apple","pen"]
// "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"\n["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]