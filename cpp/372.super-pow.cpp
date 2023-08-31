/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 *
 * https://leetcode.com/problems/super-pow/description/
 *
 * algorithms
 * Medium (36.62%)
 * Likes:    282
 * Dislikes: 845
 * Total Accepted:    38.8K
 * Total Submissions: 105.9K
 * Testcase Example:  '2\n[3]'
 *
 * Your task is to calculate a^b mod 1337 where a is a positive integer and b
 * is an extremely large positive integer given in the form of an array.
 * 
 * 
 * Example 1:
 * Input: a = 2, b = [3]
 * Output: 8
 * Example 2:
 * Input: a = 2, b = [1,0]
 * Output: 1024
 * Example 3:
 * Input: a = 1, b = [4,3,3,8,5,2]
 * Output: 1
 * Example 4:
 * Input: a = 2147483647, b = [2,0,0]
 * Output: 1198
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a <= 2^31 - 1
 * 1 <= b.length <= 2000
 * 0 <= b[i] <= 9
 * b doesn't contain leading zeros.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    const int MOD = 1337;
    
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        int pre_a = a%MOD;
        
        for(int j = b.size()-1; j>=0; j--){
            int tmp_res = 1;
            for(int i = 0; i < 10; i++){
                if(i == b[j]){
                    res = (tmp_res*res)%MOD;
                }
                tmp_res = (tmp_res * pre_a)%MOD;
            }
            pre_a = tmp_res;
        }
        
        return res;
    }
};
// @lc code=end

