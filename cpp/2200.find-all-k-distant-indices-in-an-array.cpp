/*
 * @lc app=leetcode id=2200 lang=cpp
 *
 * [2200] Find All K-Distant Indices in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> index;
        for(int i=0; i<nums.size(); ++i) {
            if(nums[i]==key){
                for(int j=max(0, i-k); j<=min((int)nums.size()-1, i+k); ++j) index.insert(j);
            }
        }
        vector<int> res(index.begin(), index.end());

        return res;
    }
};
// @lc code=end

