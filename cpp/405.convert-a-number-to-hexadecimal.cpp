/*
 * @lc app=leetcode id=405 lang=cpp
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (44.30%)
 * Likes:    566
 * Dislikes: 128
 * Total Accepted:    76.8K
 * Total Submissions: 172.8K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string toHex(int num) {
        char l[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
        string s;
        
        if (num == 0)
            return "0";
        
        bool bSkip = true;
        for (int i=0;i<8;i++) {
            unsigned char ch = (num & 0xf0000000) >> 28;
            num = (num & 0x0fffffff) << 4;
            
            if (bSkip) {
                if (!ch)   
                    continue;
                bSkip = false;
            }
            
            s+=l[ch];
        }
        return s;
    }
};
// @lc code=end

