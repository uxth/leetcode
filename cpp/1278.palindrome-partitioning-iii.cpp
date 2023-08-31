/*
 * @lc app=leetcode id=1278 lang=cpp
 *
 * [1278] Palindrome Partitioning III
 *
 * https://leetcode.com/problems/palindrome-partitioning-iii/description/
 *
 * algorithms
 * Hard (59.90%)
 * Likes:    289
 * Dislikes: 5
 * Total Accepted:    8.7K
 * Total Submissions: 14.5K
 * Testcase Example:  '"abc"\n2'
 *
 * You are given a string s containing lowercase letters and an integer k. You
 * need to :
 * 
 * 
 * First, change some characters of s to other lowercase English letters.
 * Then divide s into k non-empty disjoint substrings such that each substring
 * is palindrome.
 * 
 * 
 * Return the minimal number of characters that you need to change to divide
 * the string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abc", k = 2
 * Output: 1
 * Explanation: You can split the string into "ab" and "c", and change 1
 * character in "ab" to make it palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aabbc", k = 3
 * Output: 0
 * Explanation: You can split the string into "aa", "bb" and "c", all of them
 * are palindrome.
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 8
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= s.length <= 100.
 * s only contains lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> data;
    // int diff(string& s, int start, int end)
    // {
    //     if(start >= end) return 0;
    //     if(data[start][end]) return data[start][end];
    //     data[start][end]= s[start] == s[end] ? diff(s, start+1, end-1) : 1 + diff(s, start+1, end-1);
    //     return data[start][end];
    // }
    // int dfs(string& s, int k, int start, vector<vector<int>>& dp)
    // {
    //     if(start>=s.size()) return INT16_MAX;
    //     if(k >= s.size() - start) return 0;
    //     if(k == 1) return diff(s, start, s.size()-1);
    //     if(dp[k][start]) return dp[k][start];
    //     int res = INT16_MAX;
    //     for(int i=start; i<s.size(); ++i)
    //     {
    //         res = min(res, diff(s, start, i) + dfs(s, k-1, i+1, dp));
    //     }
    //     dp[k][start] = res == INT16_MAX ? 0 : res;
    //     return dp[k][start];
    // }
    // int palindromePartition(string s, int k) {
    //     vector<vector<int>> dp(k+1, vector<int>(s.size()+1, 0));
    //     data.assign(s.size(), vector<int>(s.size(), 0));
    //     return dfs(s, k, 0, dp);
    // }

//========================================================
    int palindromePartition(string s, int K) {
        vector<vector<int>> dp(101,vector<int>(101,100));
        vector<vector<int>> pd(101,vector<int>(101,101));
		
        for(int i = 0; i < s.size(); i++) {
            pd[i][i] = 0;
        }
        for(int i = 0; i < s.size()-1;i++) {
            if(s[i] == s[i+1])
                pd[i][i+1] = 0;
            else
                pd[i][i+1] = 1;
        }
        
        for(int k = 2; k < s.size(); k++) {
            for(int i = 0; i < s.size(); i++) {
                if(i+k>=s.size())
                    continue;
                int j = i + k;
                pd[i][j] = pd[i+1][j-1];
                if(s[i]!=s[j])
                    pd[i][j] = pd[i+1][j-1] + 1;
            }
        }
        
        for(int j = 0; j < s.size(); j++) {
            dp[j][1] = pd[0][j];
        }
        
        for(int k = 2;  k <= K; k++ ) {
            for(int j = 1; j < s.size(); j++) {
                dp[j][k] = j+1;
                for(int l = 0; l <= j; l++) {
                    dp[j][k] = min(dp[l][k-1] + pd[l+1][j], dp[j][k]);
                }
            }
        }
        return dp[s.size()-1][K];
        
    }
};
// @lc code=end
// "aabbc"\n3
// "leetcode"\n8

// "tcymekt"\n4

// "fyhowoxzyrincxivwarjuwxrwealesxsimsepjdqsstfggjnjhilvrwwytbgsqbpnwjaojfnmiqiqnyzijfmvekgakefjaxryyml"\n32

// "qrpmkzhntwmzeafnrrsimtjbzmixererogubhspdugjmimhqfhukfhyklchnvvjjrnuoauanpwtmnswjcjgauzxrlwmoevwirhwe"\n46