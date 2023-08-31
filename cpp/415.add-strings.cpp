/*
 * @lc app=leetcode id=415 lang=cpp
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (48.07%)
 * Likes:    1507
 * Dislikes: 358
 * Total Accepted:    258K
 * Total Submissions: 535.6K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool larger(string num1, string num2)
    {
        if(num1.size() != num2.size()) return num1.size() > num2.size();
        for(int i=0; i<num1.size(); ++i)
            if(num1[i] > num2[i]) return true;
        return false;
    }
    string substract(string num1, string num2)
    {
        if(num1 == num2) return "0";
        if(!larger(num1, num2)) return '-'+substract(num2, num1);
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res;
        while(i>=0 ||j>=0)
        {
            int num = carry;
            carry = 0;
            if(i>=0) num+=num1[i--]-'0';
            if(j>=0)
            {
                int n2 = num2[j--] - '0';
                if(num >= n2)
                {
                    num -= n2;
                }
                else
                {
                    carry = -1;
                    num = num + 10 - n2;
                }
            }
            
            res += '0'+num;
        }
        while(res.back() == '0') res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
    string add(string num1, string num2)
    {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string res;
        while(i>=0 || j>=0)
        {
            int num = carry;
            if(i>=0) num+=num1[i--]-'0';
            if(j>=0) num+=num2[j--]-'0';
            carry = num / 10;
            res += '0'+num%10;
        }
        if(carry) res+='1';
        reverse(res.begin(), res.end());
        return res;
    }
    string addStringWithNeg(string num1, string num2)
    {
        // if the input has '-' in the beginning
        if(num1.empty() || num2.empty()) return num1.empty() ? num2 : num1;
        if(num1[0] == '-' || num2[0] == '-') return num1[0] == num2[0] ? "-" + add(num1.substr(1), num2.substr(1)) : (num1[0] == '-' ? substract(num2, num1.substr(1)) : substract(num1, num2.substr(1)));

        return add(num1, num2);
    }
    
    string addStrings(string num1, string num2)
    {
        // cout << addStringWithNeg(num1, num2) << endl;
        return add(num1, num2);
    }
};
// @lc code=end
// ""999"\n"-123""
// ""123"\n"-9999""
// ""1000"\n"-999""
// ""1000"\n"-1000""
// ""100000000000000000000000000000000000000000000"\n"-300000000000000000000000000000000000000000000""

// ""100"\n"-1000""