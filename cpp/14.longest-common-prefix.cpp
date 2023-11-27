/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.41%)
 * Likes:    2754
 * Dislikes: 1911
 * Total Accepted:    786.7K
 * Total Submissions: 2.2M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */

// @lc code=start
class Solution {
public:
    string lcp(vector<string>& strs) {
        if(strs.empty()) return "";
        string res = strs[0];
        for(int i=1; i<strs.size(); ++i)
        {
            int j = 0;
            while(j<min(res.size(), strs[i].size()) && res[j] == strs[i][j]) j++;
            res = res.substr(0, j);
        }
        return res;
    }
    string longestCommonPrefix(vector<string>& strs) {
        return lcp(strs);
    }
};
// @lc code=end

