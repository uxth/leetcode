/*
 * @lc app=leetcode id=1576 lang=cpp
 *
 * [1576] Replace All ?'s to Avoid Consecutive Repeating Characters
 */

// @lc code=start
class Solution {
public:
    string modifyString(string s) {
        for(int i=0; i<s.size(); ++i){
            if(s[i] == '?'){
                char next = 'a';
                if(i>0 && next == s[i-1]){
                    next++;
                }
                if(i<s.size()-1 && next == s[i+1]){
                    next++;
                }
                if(i>0 && next == s[i-1]){
                    next++;
                }
                s[i] = next;
            }
        }
        return s;
    }
};
// @lc code=end
/*
""ubv?w""
""b?a""
*/
