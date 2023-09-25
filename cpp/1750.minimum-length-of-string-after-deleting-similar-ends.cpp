/*
 * @lc app=leetcode id=1750 lang=cpp
 *
 * [1750] Minimum Length of String After Deleting Similar Ends
 */

// @lc code=start
class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while(left<right && s[left] == s[right]){
            char temp = s[left];
            while(left < n && s[left] == temp) left++;
            while(right >= 0 &&s[right] == temp) right--;
            if(left > right) return 0;
        }
        return right-left+1;
    }
};
// @lc code=end
/*
""bbbbbbbbbbbbbbbbbbb""
*/
