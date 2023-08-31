/*
 * @lc app=leetcode id=1291 lang=cpp
 *
 * [1291] Sequential Digits
 *
 * https://leetcode.com/problems/sequential-digits/description/
 *
 * algorithms
 * Medium (53.38%)
 * Likes:    424
 * Dislikes: 46
 * Total Accepted:    32.2K
 * Total Submissions: 56K
 * Testcase Example:  '100\n300'
 *
 * An integer has sequential digits if and only if each digit in the number is
 * one more than the previous digit.
 * 
 * Return a sorted list of all the integers in the range [low, high] inclusive
 * that have sequential digits.
 * 
 * 
 * Example 1:
 * Input: low = 100, high = 300
 * Output: [123,234]
 * Example 2:
 * Input: low = 1000, high = 13000
 * Output: [1234,2345,3456,4567,5678,6789,12345]
 * 
 * 
 * Constraints:
 * 
 * 
 * 10 <= low <= high <= 10^9
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int digitLow = 0; int l = low;
        while(l){digitLow++;l/=10;}
        int digitHigh = 0; int h = high;
        while(h){digitHigh++;h/=10;}
        vector<int> res;


        for(int k=digitLow; k<=digitHigh; ++k)
        {
            for(int i=1; i+k-1<=9; i++)
            {
                int n = 0;
                for(int j=i; j<i+k; ++j) n=n*10+j;
                // cout << n << endl;
                if(n>high) break;
                if(n>=low)res.push_back(n);
            }
        }

        return res;
    }
};
// @lc code=end
// 1000\n13000
