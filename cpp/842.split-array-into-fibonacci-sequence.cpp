/*
 * @lc app=leetcode id=842 lang=cpp
 *
 * [842] Split Array into Fibonacci Sequence
 *
 * https://leetcode.com/problems/split-array-into-fibonacci-sequence/description/
 *
 * algorithms
 * Medium (36.33%)
 * Likes:    475
 * Dislikes: 166
 * Total Accepted:    20.2K
 * Total Submissions: 55.6K
 * Testcase Example:  '"123456579"'
 *
 * Given a string S of digits, such as S = "123456579", we can split it into a
 * Fibonacci-like sequence [123, 456, 579].
 * 
 * Formally, a Fibonacci-like sequence is a list F of non-negative integers
 * such that:
 * 
 * 
 * 0 <= F[i] <= 2^31 - 1, (that is, each integer fits a 32-bit signed integer
 * type);
 * F.length >= 3;
 * and F[i] + F[i+1] = F[i+2] for all 0 <= i < F.length - 2.
 * 
 * 
 * Also, note that when splitting the string into pieces, each piece must not
 * have extra leading zeroes, except if the piece is the number 0 itself.
 * 
 * Return any Fibonacci-like sequence split from S, or return [] if it cannot
 * be done.
 * 
 * Example 1:
 * 
 * 
 * Input: "123456579"
 * Output: [123,456,579]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "11235813"
 * Output: [1,1,2,3,5,8,13]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "112358130"
 * Output: []
 * Explanation: The task is impossible.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "0123"
 * Output: []
 * Explanation: Leading zeroes are not allowed, so "01", "2", "3" is not
 * valid.
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "1101111"
 * Output: [110, 1, 111]
 * Explanation: The output [11, 0, 11, 11] would also be accepted.
 * 
 * 
 * Note: 
 * 
 * 
 * 1 <= S.length <= 200
 * S contains only digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int i=0; i<S.size(); ++i)
        {
            for(int j=i+1; j<S.size(); ++j)
            {
                string max = to_string(INT_MAX);
                if(i+1 > max.size() || j-i > max.size()) break;
                long long a = stoll(S.substr(0, i+1));
                long long b = stoll(S.substr(i+1, j-i));
                vector<int> res{(int)a,(int)b};
                string str = to_string(a) + to_string(b);
                while(str.size() < S.size())
                {
                    a += b;
                    if(a>INT_MAX) break;
                    swap(a, b);
                    str+=to_string(b);
                    res.push_back(b);
                }
                if(res.size()>2 && str == S) return res;
            }
        }
        return {};
    }
};
// @lc code=end
// "214748364721474836422147483641"

// "17522"