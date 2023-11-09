/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 *
 * https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
 *
 * algorithms
 * Easy (77.74%)
 * Likes:    632
 * Dislikes: 18
 * Total Accepted:    77.3K
 * Total Submissions: 99.8K
 * Testcase Example:  '["pay","attention","practice","attend"]\n"at"'
 *
 * You are given an array of strings words and a string pref.
 * 
 * Return the number of strings in words that contain pref as a prefix.
 * 
 * A prefix of a string s is any leading contiguous substring of s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["pay","attention","practice","attend"], pref = "at"
 * Output: 2
 * Explanation: The 2 strings that contain "at" as a prefix are: "attention"
 * and "attend".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["leetcode","win","loops","success"], pref = "code"
 * Output: 0
 * Explanation: There are no strings that contain "code" as a prefix.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length, pref.length <= 100
 * words[i] and pref consist of lowercase English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res = 0;
        for(string& w : words){
            if(w.rfind(pref, 0) == 0) res++;
        }
        return res;
    }
};
// @lc code=end

