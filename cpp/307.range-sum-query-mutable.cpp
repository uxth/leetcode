/*
 * @lc app=leetcode id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 *
 * https://leetcode.com/problems/range-sum-query-mutable/description/
 *
 * algorithms
 * Medium (34.58%)
 * Likes:    1351
 * Dislikes: 84
 * Total Accepted:    110.1K
 * Total Submissions: 318.1K
 * Testcase Example:  '["NumArray","sumRange","update","sumRange"]\n[[[1,3,5]],[0,2],[1,2],[0,2]]'
 *
 * Given an integer array nums, find the sum of the elements between indices i
 * and j (i ≤ j), inclusive.
 * 
 * The update(i, val) function modifies nums by updating the element at index i
 * to val.
 * 
 * Example:
 * 
 * 
 * Given nums = [1, 3, 5]
 * 
 * sumRange(0, 2) -> 9
 * update(1, 2)
 * sumRange(0, 2) -> 8
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The array is only modifiable by the update function.
 * You may assume the number of calls to update and sumRange function is
 * distributed evenly.
 * 0 <= i <= j <= nums.length - 1
 * 
 * 
 */

// @lc code=start
class NumArray {
    vector<int> data;
    vector<int> nums;
    int sum(int i)
    {
        if(i<0)return 0;
        int res = 0;
        while(i>0)
        {
            // cout <<res<<" "<<i<<endl;
            res+=data[i];
            i-=(i&-i);
        }
        return res;
    }
public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        data.assign(nums.size()+1, 0);
        for(int i=0; i<nums.size(); ++i)
        {
            int j=i+1;
            while(j<data.size())
            {
                data[j] += nums[i];
                j+=(j&-j);
            }
        }
    }
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i++] = val;
        while(i<data.size())
        {
            data[i]+=diff;
            i+=(i&-i);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)return sum(j+1);
        if(i==j)return nums[i];
        
        return sum(j+1)-sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
// @lc code=end
// ["NumArray","update","sumRange","sumRange","update","sumRange"]\n[[[9,-8]],[0,3],[1,1],[0,1],[1,-3],[0,1]]
