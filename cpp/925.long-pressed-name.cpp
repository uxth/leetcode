/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 *
 * https://leetcode.com/problems/long-pressed-name/description/
 *
 * algorithms
 * Easy (40.58%)
 * Likes:    768
 * Dislikes: 130
 * Total Accepted:    52.4K
 * Total Submissions: 133.1K
 * Testcase Example:  '"alex"\n"aaleex"'
 *
 * Your friend is typing his name into a keyboard.  Sometimes, when typing a
 * character c, the key might get long pressed, and the character will be typed
 * 1 or more times.
 * 
 * You examine the typed characters of the keyboard.  Return True if it is
 * possible that it was your friends name, with some characters (possibly none)
 * being long pressed.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: name = "alex", typed = "aaleex"
 * Output: true
 * Explanation: 'a' and 'e' in 'alex' were long pressed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: name = "saeed", typed = "ssaaedd"
 * Output: false
 * Explanation: 'e' must have been pressed twice, but it wasn't in the typed
 * output.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: name = "leelee", typed = "lleeelee"
 * Output: true
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: name = "laiden", typed = "laiden"
 * Output: true
 * Explanation: It's not necessary to long press any character.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= name.length <= 1000
 * 1 <= typed.length <= 1000
 * The characters of name and typed are lowercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // bool isLongPressedName(string name, string typed) {
    //     int i = 0, m = name.length(), n = typed.length();
    //     for (int j = 0; j < n; ++j)
    //         if (i < m && name[i] == typed[j])
    //             ++i;
    //         else if (!j || typed[j] != typed[j - 1])
    //             return false;
    //     return i == m;
    // }

    bool isLongPressedName(string name, string typed) {
        vector<pair<char,int>> n;
        for(char c : name)
        {
            if(n.empty() || n.back().first != c)
                n.push_back({c,1});
            else
                n.back().second++;
        }
        vector<pair<char,int>> t;
        for(char c : typed)
        {
            if(t.empty() || t.back().first != c)
                t.push_back({c,1});
            else
                t.back().second++;
        }
        
        if(n.size()!=t.size()) return false;
        for(int i=0; i<n.size(); ++i)
            if(t[i].first!=n[i].first || t[i].second < n[i].second) return false;
        return true;
    }
};
// @lc code=end
// ""saeed"\n"ssaaedd""
// ""leelee"\n"lleeelee""
// ""saeed"\n"ssaaedd""