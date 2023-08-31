/*
 * @lc app=leetcode id=795 lang=cpp
 *
 * [795] Number of Subarrays with Bounded Maximum
 *
 * https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/description/
 *
 * algorithms
 * Medium (46.33%)
 * Likes:    632
 * Dislikes: 44
 * Total Accepted:    20.3K
 * Total Submissions: 43.4K
 * Testcase Example:  '[2,1,4,3]\n2\n3'
 *
 * We are given an array A of positive integers, and two positive integers L
 * and R (L <= R).
 * 
 * Return the number of (contiguous, non-empty) subarrays such that the value
 * of the maximum array element in that subarray is at least L and at most R.
 * 
 * 
 * Example :
 * Input: 
 * A = [2, 1, 4, 3]
 * L = 2
 * R = 3
 * Output: 3
 * Explanation: There are three subarrays that meet the requirements: [2], [2,
 * 1], [3].
 * 
 * 
 * Note:
 * 
 * 
 * L, R  and A[i] will be an integer in the range [0, 10^9].
 * The length of A will be in the range of [1, 50000].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int result=0, left=-1, right=-1;
        for (int i=0; i<A.size(); i++) {
            if (A[i]>R) left=i;
            if (A[i]>=L) right=i;
            result+=right-left;
        }
        return result;
    }
};
// @lc code=end

