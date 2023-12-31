/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (59.06%)
 * Likes:    1292
 * Dislikes: 25
 * Total Accepted:    63.6K
 * Total Submissions: 107.2K
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given an array A of 0s and 1s, we may change up to K values from 0 to 1.
 * 
 * Return the length of the longest (contiguous) subarray that contains only
 * 1s. 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 * Output: 6
 * Explanation: 
 * [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
 * Output: 10
 * Explanation: 
 * [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1.  The longest subarray is
 * underlined.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 20000
 * 0 <= K <= A.length
 * A[i] is 0 or 1 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    // int longestOnes(vector<int>& A, int K) {
    //     int i = 0, j;
    //     for (j = 0; j < A.size(); ++j) {
    //         if (A[j] == 0) K--;
    //         if (K < 0 && A[i++] == 0) K++;
    //     }
    //     return j - i;
    // }
    int longestOnes(vector<int>& A, int K) {

        int res  = 0;
        for(int i=0, j=0; i<A.size(); ++i){
            if(A[i] == 0) K--;
            while(K<0){
                if(A[j++]==0)K++;
            }
            res = max(res, i-j+1);
        }
        return res;
    }
};
// @lc code=end
// [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]\n3
