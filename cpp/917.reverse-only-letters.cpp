/*
 * @lc app=leetcode id=917 lang=cpp
 *
 * [917] Reverse Only Letters
 *
 * https://leetcode.com/problems/reverse-only-letters/description/
 *
 * algorithms
 * Easy (58.50%)
 * Likes:    723
 * Dislikes: 40
 * Total Accepted:    72.3K
 * Total Submissions: 123.4K
 * Testcase Example:  '"ab-cd"'
 *
 * Given a string S, return the "reversed" string where all characters that are
 * not a letter stay in the same place, and all letters reverse their
 * positions.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "ab-cd"
 * Output: "dc-ba"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "a-bC-dEf-ghIj"
 * Output: "j-Ih-gfE-dCba"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "Test1ng-Leet=code-Q!"
 * Output: "Qedo1ct-eeLg=ntse-T!"
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * S.length <= 100
 * 33 <= S[i].ASCIIcode <= 122 
 * S doesn't contain \ or "
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int left = 0;
        int right = S.size()-1;
        while(left < right)
        {
            while(left<right && !isalpha(S[left])) left++;
            while(left<right && !isalpha(S[right])) right--;
            swap(S[left++], S[right--]);
        }
        return S;
    }
};
// @lc code=end
// ""a-bC-dEf-ghIj""
