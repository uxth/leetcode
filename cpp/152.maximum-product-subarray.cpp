/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] resmum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int prod=1;

        for(int i=0;i<nums.size();i++)
        {
          prod*=nums[i];
          res=max(prod,res);
          if(prod==0)
            prod=1;
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
          prod*=nums[i];

          res=max(prod,res);
          if(prod==0)
           prod=1;
        }
        return res;
    }
};
// @lc code=end

