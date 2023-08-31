/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (34.63%)
 * Likes:    2231
 * Dislikes: 940
 * Total Accepted:    344.6K
 * Total Submissions: 989.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Note: You must not use any built-in BigInteger library or convert the inputs
 * to integer directly.
 * 
 * 
 * Example 1:
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * Example 2:
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 200
 * num1 and num2 consist of digits only.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
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
    string multipleWithOneDigit(string num1, char num2)
    {
        int carry = 0;
        string res;
        for(int i=num1.size()-1; i>=0; --i)
        {
            int num = num1[i]-'0';
            num *= (num2-'0');
            num += carry;
            carry = num / 10;
            res += '0'+num%10;
        }
        if(carry) res+=carry+'0';
        reverse(res.begin(), res.end());
        return res;
    }
    string multiplyTwoString(string num1, string num2)
    {
        if(num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return "0";
        string res;
        for(int j=num2.size()-1; j>=0; --j)
        {
            string tmp = multipleWithOneDigit(num1, num2[j]) + string(num2.size()-1-j, '0');
            res = add(res, tmp);
        }
        return res;
    }
    string multiplyStringWithNeg(string num1, string num2)
    {
        if(num1.empty() || num2.empty() || num1 == "0" || num2 == "0") return "0";
        if(num1[0] == '-' || num2[0] == '-') return num1[0] == num2[0] ? multiply(num1.substr(1), num2.substr(1)) : '-'+(num1[0] == '-' ? multiply(num1.substr(1), num2) : multiply(num1, num2.substr(1)));

        return multiplyTwoString(num1, num2);
    }

    string mul(string num1, string num2)
    {
        if ( num1 == "0" || num2 == "0") { return "0";}
        
        vector<int> num (num1.size() + num2.size());
        
        for (int i= num1.size() - 1; i>=0; i-- ){ 
            for (int j = num2.size() - 1; j >=0; j--) {
                num[i+j+1] += (num1[i] - '0') * (num2[j] - '0');
                num[i+j] += num[i+j+1] /10;
                num[i+j+1] %= 10;
            }
        }
        
         int i = 0;
        while (i < num.size() && num[i] == 0) ++i;
        
        // transofrm the vector to a string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0');
        
        return res;
    }
    string mul2(string num1, string num2)
    {
        int m = num1.size(), n= num2.size();
        string res(m+n,'0');
        for(int i=m-1;i>=0;i--){
            int c = 0;
            for(int j=n-1;j>=0;j--){
                int v = (num1[i]-'0')*(num2[j]-'0') + c + (res[i+j+1]-'0');
                res[i+j+1] = '0'+(v%10);
                c = v/10;
            }
            if(c > 0)res[i] += c;
        }
        
        int i = 0;
        while(i<res.size() && res[i]=='0')++i;
        return i==res.size() ? "0" : res.substr(i);
    }
    string multiply(string num1, string num2) {
        // return multiplyTwoString(num1, num2);
        // return mul(num1, num2);
        return mul2(num1, num2);
    }
};
// @lc code=end

