/*
 * @lc app=leetcode id=1092 lang=cpp
 *
 * [1092] Shortest Common Supersequence 
 *
 * https://leetcode.com/problems/shortest-common-supersequence/description/
 *
 * algorithms
 * Hard (51.55%)
 * Likes:    620
 * Dislikes: 18
 * Total Accepted:    15K
 * Total Submissions: 28.9K
 * Testcase Example:  '"abac"\n"cab"'
 *
 * Given two strings str1 and str2, return the shortest string that has both
 * str1 and str2 as subsequences.  If multiple answers exist, you may return
 * any of them.
 * 
 * (A string S is a subsequence of string T if deleting some number of
 * characters from T (possibly 0, and the characters are chosen anywhere from
 * T) results in the string S.)
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "abac", str2 = "cab"
 * Output: "cabac"
 * Explanation: 
 * str1 = "abac" is a subsequence of "cabac" because we can delete the first
 * "c".
 * str2 = "cab" is a subsequence of "cabac" because we can delete the last
 * "ac".
 * The answer provided is the shortest such string that satisfies these
 * properties.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string lcs(string& str1, string& str2)
    {
        vector<vector<string>> dp(str1.size()+1, vector<string>(str2.size()+1));
        for(int i=1; i<=str1.size(); ++i) for(int j=1;j<=str2.size(); ++j)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1]+str1[i-1];
            else
                dp[i][j] = dp[i-1][j].size() > dp[i][j-1].size() ? dp[i-1][j] : dp[i][j-1];
        }
        return dp.back().back();
    }
    string shortestCommonSupersequence(string str1, string str2) {
        string res;
        int i=0; int j=0;
        for(char c : lcs(str1, str2))
        {
            while(str1[i] != c) res+=str1[i++];
            while(str2[j] != c) res+=str2[j++];
            res+=c; i++;j++;
        }
        return res + str1.substr(i) + str2.substr(j);
    }
};
// @lc code=end

