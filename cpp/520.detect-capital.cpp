/*
 * @lc app=leetcode id=520 lang=cpp
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (54.36%)
 * Likes:    642
 * Dislikes: 278
 * Total Accepted:    170K
 * Total Submissions: 315.4K
 * Testcase Example:  '"USA"'
 *
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * 
 * Note: The input will be a non-empty word consisting of uppercase and
 * lowercase latin letters.
 * 
 */

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()<2)return true;
        int cap = 0;
        for(int i = 0; i < word.size(); ++i)
            if(word[i] >='A' && word[i]<='Z') cap++;
        return cap == word.size() || (cap == 1 && word[0]>='A'&&word[0]<='Z') || cap == 0;
    }
};
// @lc code=end

