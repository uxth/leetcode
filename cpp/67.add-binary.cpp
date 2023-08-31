/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (46.47%)
 * Likes:    2522
 * Dislikes: 328
 * Total Accepted:    566.6K
 * Total Submissions: 1.2M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * 
 * Example 1:
 * Input: a = "11", b = "1"
 * Output: "100"
 * Example 2:
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a.length, b.length <= 10^4
 * a and b consist only of '0' or '1' characters.
 * Each string does not contain leading zeros except for the zero itself.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty()||b.empty()) return a.empty()?b:a;
        // if(a.size()<b.size()) return addBinary(b, a);
        int i=a.size()-1, j=b.size()-1;
        string res;
        int carry = 0;
        while(i>=0||j>=0)
        {
            int n = carry;
            if(i>=0) n+=a[i--]-'0';
            if(j>=0) n+=b[j--]-'0';
            res+='0'+(n%2);
            carry=n/2;
        }
        if(carry) res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

