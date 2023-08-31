/*
 * @lc app=leetcode id=1191 lang=cpp
 *
 * [1191] K-Concatenation Maximum Sum
 *
 * https://leetcode.com/problems/k-concatenation-maximum-sum/description/
 *
 * algorithms
 * Medium (25.45%)
 * Likes:    462
 * Dislikes: 43
 * Total Accepted:    15.7K
 * Total Submissions: 61.9K
 * Testcase Example:  '[1,2]\n3'
 *
 * Given an integer array arr and an integer k, modify the array by repeating
 * it k times.
 * 
 * For example, if arr = [1, 2] and k = 3 then the modified array will be [1,
 * 2, 1, 2, 1, 2].
 * 
 * Return the maximum sub-array sum in the modified array. Note that the length
 * of the sub-array can be 0 and its sum in that case is 0.
 * 
 * As the answer can be very large, return the answer modulo 10^9 + 7.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,2], k = 3
 * Output: 9
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,1], k = 5
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-2], k = 7
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * 1 <= k <= 10^5
 * -10^4 <= arr[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int mod=1e9+7;
        int n=arr.size();
        int round=min(k,2);
        long long int sum=0;
        long long int max_sum=0;
        long long int total=accumulate(arr.begin(),arr.end(),0);
        for(int i=0;i<round;i++)
        {
            for(int j=0;j<n;j++)
            {
                sum=sum+arr[j];
                if(sum>max_sum)
                {
                    max_sum=sum;
                }
                else if(sum<0)
                {
                    sum=0;
                }
            }
        }
        if(k==1)
        {
            return max_sum;
        }
        
        return total>=0?(max_sum+(k-2)*total)%mod:max_sum%mod;
    }

};
// @lc code=end

