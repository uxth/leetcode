/*
 * @lc app=leetcode id=1752 lang=cpp
 *
 * [1752] Check if Array Is Sorted and Rotated
 */

// @lc code=start
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i=1; i<=n; ++i){
            if(nums[i%n]<nums[i-1]) count++;
        }
        return count <= 1;
    }
};
// @lc code=end
/*
[2,1,3,4]
[1,2,3]
*/
