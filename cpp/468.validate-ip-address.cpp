/*
 * @lc app=leetcode id=468 lang=cpp
 *
 * [468] Validate IP Address
 *
 * https://leetcode.com/problems/validate-ip-address/description/
 *
 * algorithms
 * Medium (26.17%)
 * Likes:    943
 * Dislikes: 2665
 * Total Accepted:    150.2K
 * Total Submissions: 561.2K
 * Testcase Example:  '"172.16.254.1"'
 *
 * Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6"
 * if IP is a valid IPv6 address or "Neither" if IP is not a correct IP of any
 * type.
 * 
 * A valid IPv4 address is an IP in the form "x1.x2.x3.x4" where 0 <= xi <= 255
 * and xi cannot contain leading zeros. For example, "192.168.1.1" and
 * "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00",
 * and "192.168@1.1" are invalid IPv4 addresses.
 * 
 * A valid IPv6 address is an IP in the form "x1:x2:x3:x4:x5:x6:x7:x8"
 * where:
 * 
 * 
 * 1 <= xi.length <= 4
 * xi is a hexadecimal string which may contain digits, lowercase English
 * letter ('a' to 'f') and upper-case English letters ('A' to 'F').
 * Leading zeros are allowed in xi.
 * 
 * 
 * For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and
 * "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, while
 * "2001:0db8:85a3::8A2E:037j:7334" and
 * "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: queryIP = "172.16.254.1"
 * Output: "IPv4"
 * Explanation: This is a valid IPv4 address, return "IPv4".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
 * Output: "IPv6"
 * Explanation: This is a valid IPv6 address, return "IPv6".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: queryIP = "256.256.256.256"
 * Output: "Neither"
 * Explanation: This is neither a IPv4 address nor a IPv6 address.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * queryIP consists only of English letters, digits and the characters '.' and
 * ':'.
 * 
 * 
 */

// @lc code=start
class Solution {
private:
bool valid_ipv4(string str)
{
    int count = 0;//to count no of dots
    int temp_size=0;
    char prev='\0';
    int i =0;
    while(i< str.size())
    {
        char ch = str[i];
        string temp="";
        temp_size=0;
        while(i<str.size()&&str[i]!='.')
        {
            temp_size++;
            ch = str[i];
            if(!(ch>='0'&&ch<='9'))
            return false;
            temp+=ch;
            i++;
        }
        if(str[i]=='.'&&i==str.size()-1)
        return false;
        i++;
        if((temp_size==0)||temp_size>3||temp[0]=='0'&&temp_size>1)
        {
            return false;
        }
        count++;
        int value = stoi(temp);
        if(value<0||value>255)//check the value of part 
        return false;
    }
   
    if(count-1==3)
    return true;

    return false;

}
bool valid_ipv6(string str)
{
    int count = 0;
    int temp_size=0;
    int i =0;
    while(i< str.size())
    {
        char ch = str[i];
        string temp="";
        temp_size=0;
        while(i<str.size()&&str[i]!=':')
        {
            temp_size++;
            ch = str[i];
            if(!(ch>='0'&&ch<='9'||ch>='a'&&ch<='f'||ch>='A'&&ch<='F'))
            return false;
            temp+=ch;
            i++;
        }
        if(str[i]==':'&&i==str.size()-1)
        return false;
        i++;
        if(temp_size<1||temp_size>4)
        {
            return false;
        }
        count++;
    }

    if(count-1==7)
    return true;

    return false;
}
public:
    string validIPAddress(string str) {
        bool ipv4=false;
        bool ipv6=false;
        int ret=str.find('.');
        if(ret>=0&&ret<=str.size())
        {
            ipv4=valid_ipv4(str);
        }
        else{
            ipv6=valid_ipv6(str);
        }   
        if(ipv4)
        {
            cout<<"ipv4";
            return "IPv4";
        }
        else if(ipv6)
        {
            cout<<"ipv6";
            return "IPv6";
        }
        else 
        {
            cout<<"neither";
            return "Neither";
        }
    }
};
// @lc code=end

