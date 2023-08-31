/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (46.31%)
 * Likes:    449
 * Dislikes: 25
 * Total Accepted:    27.4K
 * Total Submissions: 59.1K
 * Testcase Example:  '[1,2,2]'
 *
 * Given an array of integers A, a move consists of choosing any A[i], and
 * incrementing it by 1.
 * 
 * Return the least number of moves to make every value in A unique.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,2]
 * Output: 1
 * Explanation:  After 1 move, the array could be [1, 2, 3].
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,1,2,1,7]
 * Output: 6
 * Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 0 <= A.length <= 40000
 * 0 <= A[i] < 40000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.empty()) return 0;
        // int start = *min_element(A.begin(), A.end());
        sort(A.begin(), A.end());
        int start = A.front();
        int res = 0;
        for(int i : A)
        {
            if(start > i) res+=start++ - i;
            else start = i+1;
        }
        return res;
    }
};
// @lc code=end

// [0,2,2]