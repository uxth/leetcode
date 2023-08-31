/*
 * @lc app=leetcode id=923 lang=cpp
 *
 * [923] 3Sum With Multiplicity
 *
 * https://leetcode.com/problems/3sum-with-multiplicity/description/
 *
 * algorithms
 * Medium (35.74%)
 * Likes:    382
 * Dislikes: 84
 * Total Accepted:    20.6K
 * Total Submissions: 57.3K
 * Testcase Example:  '[1,1,2,2,3,3,4,4,5,5]\n8'
 *
 * Given an integer array A, and an integer target, return the number of tuples
 * i, j, k  such that i < j < k and A[i] + A[j] + A[k] == target.
 * 
 * As the answer can be very large, return it modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
 * Output: 20
 * Explanation: 
 * Enumerating by the values (A[i], A[j], A[k]):
 * (1, 2, 5) occurs 8 times;
 * (1, 3, 4) occurs 8 times;
 * (2, 2, 4) occurs 2 times;
 * (2, 3, 3) occurs 2 times.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: A = [1,1,2,2,2,2], target = 5
 * Output: 12
 * Explanation: 
 * A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
 * We choose one 1 from [1,1] in 2 ways,
 * and two 2s from [2,2,2,2] in 6 ways.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= A.length <= 3000
 * 0 <= A[i] <= 100
 * 0 <= target <= 300
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    const int mod = (int) 1e9 + 7;
public:
    int threeSumMulti(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for(int i = 0;i < n;i++){
            int count = 0, l = i + 1, r = n - 1, sum;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                if(sum == target){
                    bool equal = (nums[l] == nums[r]);
                    int countL = 1, countR = 1;
                    while(l + 1 < r and nums[l + 1] == nums[l]) countL++, l++;
                    while(r - 1 > l and nums[r - 1] == nums[r]) countR++, r--;
                    l++;
                    r--;
                    if(equal) ans = (ans + countL * (countL + 1) / 2) % mod;
                    else ans = (ans + countL * countR) % mod;
                }
                else if(sum < target) l++;
                else r--;
            }
        }
        return ans;
    }
};
// @lc code=end

