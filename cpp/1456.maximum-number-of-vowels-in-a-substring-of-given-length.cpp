/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (52.35%)
 * Likes:    222
 * Dislikes: 12
 * Total Accepted:    18.4K
 * Total Submissions: 34.8K
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k.
 * 
 * Return the maximum number of vowel letters in any substring of s with length
 * k.
 * 
 * Vowel letters in English are (a, e, i, o, u).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "rhythms", k = 4
 * Output: 0
 * Explanation: We can see that s doesn't have any vowel letters.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "tryhard", k = 4
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 * 
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels{'a','e','i','o','u'};
        int res = 0;
        int count = 0;
        for(int i=0; i<s.size(); ++i)
        {
            if(i>=k && vowels.count(s[i-k])) count--;
            if(vowels.count(s[i])) count++;
            res=max(res, count);
        }
        return res;
    }
};
// @lc code=end

