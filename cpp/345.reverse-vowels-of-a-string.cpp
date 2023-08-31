/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (44.17%)
 * Likes:    715
 * Dislikes: 1169
 * Total Accepted:    227.8K
 * Total Submissions: 515.2K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * Example 1:
 * 
 * 
 * Input: "hello"
 * Output: "holle"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "leotcede"
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int l = 0; int r = s.size() - 1;
        while(l < r)
        {
            while(l < r && vowels.count(s[l]) == 0) l++;
            while(l < r && vowels.count(s[r]) == 0) r--;
            if(l < r) swap(s[l++], s[r--]);
        }
        return s;
    }
};
// @lc code=end

