/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (45.59%)
 * Likes:    563
 * Dislikes: 34
 * Total Accepted:    21.8K
 * Total Submissions: 47.6K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B
 * is the number of indices i for which A[i] > B[i].
 * 
 * Return any permutation of A that maximizes its advantage with respect to
 * B.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> nums(A.begin(), A.end());
        vector<int> result(A.size());
        for(int i = 0; i < B.size(); ++i) {

            auto iter  = nums.lower_bound(B[i]+1);
            if(iter != nums.end()) {
                result[i] = *iter;
                nums.erase(iter);
            }
            else
            {
                result[i] = INT_MIN;
            }
        }
        for(int i = 0; i < A.size(); ++i) {
            if(result[i] == INT_MIN) {
                auto iter = nums.begin();
                result[i] = *iter;
                nums.erase(iter);
            }
        }
        
        return result;  
    }
};
// @lc code=end
// [12,24,8,32]\n[13,25,32,11]
// [2,0,4,1,2]\n[1,3,0,0,2]
