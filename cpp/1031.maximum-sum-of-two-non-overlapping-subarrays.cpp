/*
 * @lc app=leetcode id=1031 lang=cpp
 *
 * [1031] Maximum Sum of Two Non-Overlapping Subarrays
 */

// @lc code=start
class Solution {
// public:
    // int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    //     int n = nums.size();
    //     vector<vector<int>> data(n, vector<int>(n, 0));
    //     for(int i=0; i<n; ++i) data[i][i] = nums[i];
    //     for(int i=0; i<n; ++i) for(int j=i+1; j<n; ++j) data[i][j] = data[i][j-1]+nums[j];
    //     int res = INT_MIN;
    //     for(int i=0; i<n-firstLen; ++i){
    //         for(int j=i+firstLen; j<=n-secondLen; ++j){
    //             res = max(res, data[i][i+firstLen-1] + data[j][j+secondLen-1]);
    //         }
    //     }
    //     for(int i=0; i<n-secondLen; ++i){
    //         for(int j=i+secondLen; j<=n-firstLen; ++j){
    //             res = max(res, data[i][i+secondLen-1] + data[j][j+firstLen-1]);
    //         }
    //     }
    //     return res;
    // }

    int n;
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        n = nums.size();
        if(!n)
            return 0;
        return max(getSum(nums, firstLen, secondLen), getSum(nums, secondLen, firstLen));
    }
    
    int getSum(const vector<int>&nums, int l_len, int r_len){
        vector<int>left(n, 0), right(n, INT_MIN);
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
            if(i>=l_len-1){
                left[i] = max(i?left[i-1]:INT_MIN, sum);
                sum -= nums[i-l_len+1];
            }
        }
        sum = 0;
        for(int i = n-1;i>=0;i--){
            sum += nums[i];
            if(i<=n-r_len){
                right[i] = max(i<n-1?right[i+1]:INT_MIN, sum);
                sum -= nums[i+r_len-1];
            }
        }
        long ret = INT_MIN;
        for(int i = 1;i<n;i++){
            ret = max((long)ret, (long)left[i-1]+(long)right[i]);
        }
        return ret;
    }
};
// @lc code=end
// [3,8,1,3,2,1,8,9,0]\n3\n2
// [2,1,5,6,0,9,5,0,3,8]\n4\n3