/*
 * @lc app=leetcode id=600 lang=cpp
 *
 * [600] Non-negative Integers without Consecutive Ones
 *
 * https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
 *
 * algorithms
 * Hard (34.05%)
 * Likes:    428
 * Dislikes: 73
 * Total Accepted:    12.9K
 * Total Submissions: 37.6K
 * Testcase Example:  '1'
 *
 * Given a positive integer n, find the number of non-negative integers less
 * than or equal to n, whose binary representations do NOT contain consecutive
 * ones.
 * 
 * Example 1:
 * 
 * Input: 5
 * Output: 5
 * Explanation: 
 * Here are the non-negative integers 
 * 
 * 
 * Note:
 * 1 
 * 
 */

// @lc code=start
class Solution {
public:
    int findIntegers(int num) {
        //one:all bit before cur is less than num and no continues 1 and cur bit is at one;
        //zero:all bit before cur is less than num and no continues 1 and cur bit is at zero;
        int one=0,zero=0,temp;
        bool isNum=true;
        for(int i=31;i>=0;i--){
            temp=zero;
            zero+=one;
            one=temp;
            if(isNum&&((num>>i)&1)==1){
                zero+=1;
            }
            if(((num>>i)&1)==1&&((num>>i+1)&1)==1){
                isNum=false;
            }
            
        }
        return one+zero+(isNum?1:0);
    }
};
// @lc code=end

