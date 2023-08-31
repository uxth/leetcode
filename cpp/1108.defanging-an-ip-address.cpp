/*
 * @lc app=leetcode id=1108 lang=cpp
 *
 * [1108] Defanging an IP Address
 *
 * https://leetcode.com/problems/defanging-an-ip-address/description/
 *
 * algorithms
 * Easy (87.52%)
 * Likes:    493
 * Dislikes: 954
 * Total Accepted:    234.1K
 * Total Submissions: 265.8K
 * Testcase Example:  '"1.1.1.1"'
 *
 * Given a valid (IPv4) IP address, return a defanged version of that IP
 * address.
 * 
 * A defanged IP address replaces every period "." with "[.]".
 * 
 * 
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 * 
 * 
 * Constraints:
 * 
 * 
 * The given address is a valid IPv4 address.
 * 
 */

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        string res;
        int left = 0;
        for(int i=0; i<=address.size(); ++i)
        {
            if(i==address.size() || address[i] == '.')
            {
                res += address.substr(left, i-left);
                if(i!=address.size()) res+="[.]";
                left = i+1;
            }
        }
        return res;
    }
};
// @lc code=end

