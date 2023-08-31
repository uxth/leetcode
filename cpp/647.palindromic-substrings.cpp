/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (61.60%)
 * Likes:    3511
 * Dislikes: 133
 * Total Accepted:    236.3K
 * Total Submissions: 383.1K
 * Testcase Example:  '"abc"'
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 * 
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 * 
 * Example 1:
 * 
 * 
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input string length won't exceed 1000.
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // bool isPalindromic(string& s, int l, int r)
    // {
    //     while(l<r) if(s[l++] != s[r--])return false;
    //     return true;
    // }
    // int countSubstrings(string s) {
    //     int res = 0;
    //     for(int i=0; i<s.size(); ++i)
    //     {
    //         for(int j=i; j<s.size(); ++j)
    //         {
    //             res += isPalindromic(s, i, j);
    //         }
    //     }
    //     return res;
    // }
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.length(); ++i) {
            res += palin(s, i, i) + palin(s, i, i + 1);
        }
        return res;
    }
    
    int palin(string s, int left, int right) {
        int cnt = 0;
        while (left >= 0 && right < s.length()) {
            if (s[left--] == s[right++]) ++cnt;
            else break;
        }
        return cnt;
    }
};
// @lc code=end
// ""aaa""
