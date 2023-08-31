/*
 * @lc app=leetcode id=500 lang=cpp
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (64.71%)
 * Likes:    561
 * Dislikes: 680
 * Total Accepted:    113.7K
 * Total Submissions: 175.4K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */

// @lc code=start
class Solution {
    unordered_map<char,int> m{
        {'q', 1}, {'w', 1}, {'e', 1}, {'r', 1}, {'t', 1},{'y', 1}, {'u', 1}, {'i', 1}, {'o', 1}, {'p', 1},
        {'a', 2},{'s', 2}, {'d', 2}, {'f', 2}, {'g', 2}, {'h', 2},{'j', 2}, {'k', 2}, {'l', 2},
        {'z', 3},{'x', 3},{'c', 3},{'v', 3}, {'b', 3}, {'n', 3}, {'m', 3}
        
    };
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        for(string& s : words)
        {
            int status = m[tolower(s[0])];
            if(all_of(s.begin(), s.end(), [&](char c){return m[tolower(c)] == status;}))
                res.push_back(s);
        }
        return res;
    }
};
// @lc code=end

