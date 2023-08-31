/*
 * @lc app=leetcode id=2165 lang=cpp
 *
 * [2165] Smallest Value of the Rearranged Number
 */

// @lc code=start
class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return num;
        bool neg = num < 0;
        num = abs(num);
        string str = to_string(num);
        if(neg) {
            sort(str.begin(), str.end(), greater<char>());
            return stoll(str) * -1;
        }
        
        sort(str.begin(), str.end());
        if(str[0]=='0') {
            int i = 0;
            while(str[i]=='0') i++;
            swap(str[0], str[i]);
        }
        return stoll(str);
    }
};
// @lc code=end

