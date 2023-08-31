/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (38.21%)
 * Likes:    1723
 * Dislikes: 209
 * Total Accepted:    245.7K
 * Total Submissions: 640.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string s, find if s follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in s.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat dog"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: pattern = "abba", s = "dog cat cat fish"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", s = "dog cat cat dog"
 * Output: false
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", s = "dog dog dog dog"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= pattern.length <= 300
 * pattern contains only lower-case English letters.
 * 1 <= s.length <= 3000
 * s contains only lower-case English letters and spaces ' '.
 * s does not contain any leading or trailing spaces.
 * All the words in s are separated by a single space.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void split(const std::string& s, vector<string>& sv, const char* delim = " ") {
        sv.clear(); 
        int start = 0;
        for(int i=0; i<=s.size(); ++i)
        {
            if(s[i] == ' ' || i == s.size())
            {
                sv.push_back(s.substr(start, i-start));
                start = i+1;
            }
        }
        return;
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> forward;
        unordered_map<string, char> backward;
        vector<string> s;
        split(str, s);
        if(s.size() != pattern.size()) return false;
        for(int i=0; i<s.size(); ++i)
        {
            if((forward.count(pattern[i]) || backward.count(s[i])) && !(forward[pattern[i]] == s[i] && backward[s[i]] == pattern[i]))
            {
                return false;
            }
            forward[pattern[i]] = s[i];
            backward[s[i]] = pattern[i];
        }
        return true;
    }
};
// @lc code=end

