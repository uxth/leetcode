/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 *
 * https://leetcode.com/problems/backspace-string-compare/description/
 *
 * algorithms
 * Easy (46.40%)
 * Likes:    1954
 * Dislikes: 97
 * Total Accepted:    242.7K
 * Total Submissions: 520K
 * Testcase Example:  '"ab#c"\n"ad#c"'
 *
 * Given two strings S and T, return if they are equal when both are typed into
 * empty text editors. # means a backspace character.
 * 
 * Note that after backspacing an empty text, the text will continue empty.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: S = "ab#c", T = "ad#c"
 * Output: true
 * Explanation: Both S and T become "ac".
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "ab##", T = "c#d#"
 * Output: true
 * Explanation: Both S and T become "".
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: S = "a##c", T = "#a#c"
 * Output: true
 * Explanation: Both S and T become "c".
 * 
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: S = "a#c", T = "b"
 * Output: false
 * Explanation: S becomes "c" while T becomes "b".
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= S.length <= 200
 * 1 <= T.length <= 200
 * S and T only contain lowercase letters and '#' characters.
 * 
 * 
 * Follow up:
 * 
 * 
 * Can you solve it in O(N) time and O(1) space?
 * 
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string ss, tt;
        for(int i=0; i<T.size(); ++i)
        {
            if( T[i] == '#'){
                if(!tt.empty())
                    tt.pop_back();
            }
            else
            {
                tt+=T[i];
            }
        }
        for(int i=0; i<S.size(); ++i)
        {
            if(S[i] == '#'){
                if(!ss.empty())
                    ss.pop_back();
            }
            else
            {
                ss+=S[i];
            }
        }
        return ss == tt;
    }
};
// @lc code=end
// "xywrrmp"\n"xywrrmu#p"
// "y#fo##f"\n"y#f#o##f"