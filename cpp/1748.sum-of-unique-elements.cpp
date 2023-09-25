/*
 * @lc app=leetcode id=1748 lang=cpp
 *
 * [1748] Sum of Unique Elements
 */

// @lc code=start
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
      unordered_map<int,int> m1;
      int sum=0;
      for(int i=0;i<nums.size();i++)m1[nums[i]]++;
      for(auto& it:m1) if(it.second<2)sum=sum+it.first;
      return sum;
    }
};
// @lc code=end
/*
[1,1,1,1,1]
[1,2,3,4,5]
*/
