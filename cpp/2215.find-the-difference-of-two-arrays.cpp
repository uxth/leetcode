/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> set2(nums2.begin(),nums2.end());
        vector<int> ans1,ans2;
        for(auto it:set1){
            if(set2.count(it)==0){
                ans1.push_back(it);
            }
        }
        for(auto it:set2){
            if(set1.count(it)==0){
                ans2.push_back(it);
            }
        }
        return {ans1,ans2};
    }
};
// @lc code=end
/*
[1,2,3,3]\n[1,1,2,2]
*/

