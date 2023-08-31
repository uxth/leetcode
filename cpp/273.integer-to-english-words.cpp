/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 *
 * https://leetcode.com/problems/integer-to-english-words/description/
 *
 * algorithms
 * Hard (27.02%)
 * Likes:    1242
 * Dislikes: 3188
 * Total Accepted:    202.3K
 * Total Submissions: 731.8K
 * Testcase Example:  '123'
 *
 * Convert a non-negative integer num to its English words representation.
 * 
 * 
 * Example 1:
 * Input: num = 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 * Input: num = 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 * Input: num = 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty
 * Seven"
 * Example 4:
 * Input: num = 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty
 * Seven Thousand Eight Hundred Ninety One"
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= num <= 2^31 - 1
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        vector<string> units {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine "};
        vector<string> teens {"Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
        vector<string> tenths {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
        vector<string> position {"", "", "Hundred ", "Thousand ", "", "Hundred ", "Million ", "", "Hundred ", "Billion "};
        
        string answer;
        if (num<0) {
            answer += "Negative ";
            num = abs(num);
        };
        vector<int> digits;
        while (num) {
            digits.push_back(num%10);
            num /= 10;
        }
        
        for (int i = digits.size(); i>0; ) {
            int d = digits[--i];
            if (i%3==1) {
                if (d==1) {
                    d = digits[--i];
                    answer += teens[d];
                }
                else answer += tenths[d];
            }
            else answer += units[d];
            if (d>0 || (i%3==0 && (digits[i+1]>0 || digits[i+2]>0)) ) {
                answer += position[i];
            }
        }
        // answer.erase(answer.size()-1);
        answer.pop_back();
        return answer;  
    }
};
// @lc code=end

