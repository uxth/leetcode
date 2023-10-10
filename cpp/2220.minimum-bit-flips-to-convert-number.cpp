/*
 * @lc app=leetcode id=2220 lang=cpp
 *
 * [2220] Minimum Bit Flips to Convert Number
 */

// @lc code=start
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start ^ goal, res = 0;
        while(num){
            num -= num & -num;
            res++;
        }
        return res;
    }
};
// @lc code=end
/*
3\n4
*/
