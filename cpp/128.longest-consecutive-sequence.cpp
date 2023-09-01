/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size()==0)return 0;
    //     sort(begin(nums),end(nums));
    //     int res=1;
    //     int count=1;
    //     for(int i=0;i<nums.size()-1;i++){
    //         if(nums[i] == nums[i+1]) continue;
    //         if(nums[i+1]-nums[i]==1)
    //             count++;
    //         else {
    //             res=max(res,count);
    //             count=1;
    //         }
    //     }
    //     return max(res,count);
    // }

    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> data(begin(nums), end(nums));
        int res = 0;
        for(int n : nums){
            if(!data.count(n-1)){
                int count = 0;
                while(data.count(n++)) count++;
                res = max(res, count);
            }
        }
        return res;
    }
};
// @lc code=end

