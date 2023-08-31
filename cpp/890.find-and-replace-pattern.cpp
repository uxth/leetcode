/*
 * @lc app=leetcode id=890 lang=cpp
 *
 * [890] Find and Replace Pattern
 *
 * https://leetcode.com/problems/find-and-replace-pattern/description/
 *
 * algorithms
 * Medium (73.40%)
 * Likes:    730
 * Dislikes: 70
 * Total Accepted:    53K
 * Total Submissions: 72.1K
 * Testcase Example:  '["abc","deq","mee","aqq","dkd","ccc"]\n"abb"'
 *
 * You have a list of words and a pattern, and you want to know which words in
 * words matches the pattern.
 * 
 * A word matches the pattern if there exists a permutation of letters p so
 * that after replacing every letter x in the pattern with p(x), we get the
 * desired word.
 * 
 * (Recall that a permutation of letters is a bijection from letters to
 * letters: every letter maps to another letter, and no two letters map to the
 * same letter.)
 * 
 * Return a list of the words in words that match the given pattern. 
 * 
 * You may return the answer in any order.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
 * Output: ["mee","aqq"]
 * Explanation: "mee" matches the pattern because there is a permutation {a ->
 * m, b -> e, ...}. 
 * "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a
 * permutation,
 * since a and b map to the same letter.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= words.length <= 50
 * 1 <= pattern.length = words[i].length <= 20
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(string& w : words)
        {
            if(w.size() != pattern.size()) continue;
            unordered_map<char, char> m, k;
            int i=0;
            for(; i<w.size(); ++i)
            {
                if(m.count(pattern[i]) && m[pattern[i]] != w[i] || k.count(w[i]) && k[w[i]] != pattern[i]) break;
                else {m[pattern[i]] = w[i]; k[w[i]] = pattern[i];}
            }
            if(i==w.size()) res.push_back(w);
        }
        return res;
    }
};
// @lc code=end

