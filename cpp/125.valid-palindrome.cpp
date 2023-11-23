/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (36.65%)
 * Likes:    1325
 * Dislikes: 3061
 * Total Accepted:    650.3K
 * Total Submissions: 1.8M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 * 
 * Example 1:
 * 
 * 
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "race a car"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * s consists only of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int low=0, high=s.length()-1;
        
        while(low<high)
        {
            if(!isalnum(s[low])) low++;
            else if(!isalnum(s[high])) high--;
            else
            {
                if(tolower(s[low++]) != tolower(s[high--]))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

