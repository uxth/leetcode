/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (48.50%)
 * Likes:    3537
 * Dislikes: 7324
 * Total Accepted:    827.9K
 * Total Submissions: 1.6M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 * 
 * 
 * countAndSay(1) = "1"
 * countAndSay(n) is the way you would "say" the digit string from
 * countAndSay(n-1), which is then converted into a different digit string.
 * 
 * 
 * To determine how you "say" a digit string, split it into the minimal number
 * of substrings such that each substring contains exactly one unique digit.
 * Then for each substring, say the number of digits, then say the digit.
 * Finally, concatenate every said digit.
 * 
 * For example, the saying and conversion for digit string "3322251":
 * 
 * Given a positive integer n, return the n^th term of the count-and-say
 * sequence.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 1
 * Output: "1"
 * Explanation: This is the base case.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4
 * Output: "1211"
 * Explanation:
 * countAndSay(1) = "1"
 * countAndSay(2) = say "1" = one 1 = "11"
 * countAndSay(3) = say "11" = two 1's = "21"
 * countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 30
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        string tmp = "1";             //base string
        n--;                          //n is decremented because we already have ans for n=1
        while(n--)
        {
            string tr = "";           //take new string
            int cnt=0;
            char st = tmp[0];

            for(auto&a:tmp)
            {
                if(a==st)
                {
                    cnt++;            //increase frequency of same adjacent elements
                }
                else
                {
                    tr += to_string(cnt);       //if new element comes add to string freq(prev elem) + prev elem and update
                    tr += st;
                    cnt = 1;
                    st  = a;
                }
            }
            if(cnt>0)                  //for last common continuous elements
            {
                tr+= to_string(cnt);
                tr+= st;
            }
            tmp = tr;               //update base string
        }
        return tmp;
    }
};
// @lc code=end

