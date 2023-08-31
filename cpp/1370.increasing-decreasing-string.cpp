/*
 * @lc app=leetcode id=1370 lang=cpp
 *
 * [1370] Increasing Decreasing String
 *
 * https://leetcode.com/problems/increasing-decreasing-string/description/
 *
 * algorithms
 * Easy (75.62%)
 * Likes:    188
 * Dislikes: 172
 * Total Accepted:    20.6K
 * Total Submissions: 27.2K
 * Testcase Example:  '"aaaabbbbcccc"'
 *
 * Given a string s. You should re-order the string using the following
 * algorithm:
 * 
 * 
 * Pick the smallest character from s and append it to the result.
 * Pick the smallest character from s which is greater than the last appended
 * character to the result and append it.
 * Repeat step 2 until you cannot pick more characters.
 * Pick the largest character from s and append it to the result.
 * Pick the largest character from s which is smaller than the last appended
 * character to the result and append it.
 * Repeat step 5 until you cannot pick more characters.
 * Repeat the steps from 1 to 6 until you pick all characters from s.
 * 
 * 
 * In each step, If the smallest or the largest character appears more than
 * once you can choose any occurrence and append it to the result.
 * 
 * Return the result string after sorting s with this algorithm.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "aaaabbbbcccc"
 * Output: "abccbaabccba"
 * Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
 * After steps 4, 5 and 6 of the first iteration, result = "abccba"
 * First iteration is done. Now s = "aabbcc" and we go back to step 1
 * After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
 * After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat"
 * Output: "art"
 * Explanation: The word "rat" becomes "art" after re-ordering it with the
 * mentioned algorithm.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: "cdelotee"
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "ggggggg"
 * Output: "ggggggg"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "spo"
 * Output: "ops"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * s contains only lower-case English letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string sortString(string s) {
        unordered_map<char,int> m;
        for(char c : s) ++m[c];

        string res;
        while(res.size() != s.size())
        {
            for(char c='a'; c<='z'; ++c)
                if(--m[c]>=0) res+=c;
            for(char c='z'; c>='a'; --c)
                if(--m[c]>=0) res+=c;
        } 
        return res;
    }
};
// @lc code=end

