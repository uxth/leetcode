/*
 * @lc app=leetcode id=1790 lang=cpp
 *
 * [1790] Check if One String Swap Can Make Strings Equal
 */

// @lc code=start
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        int pos = -1;
        for(int i=0; i<s1.size(); ++i){
            if(s1[i] != s2[i]){
                if(pos == -1) pos = i;
                else {
                    swap(s1[pos], s1[i]);
                    return s1 == s2;
                }
            }
        }
        return false;
    }
};
// @lc code=end
/*
""attack"\n"defend""
""abcd"\n"bcda""
*/
