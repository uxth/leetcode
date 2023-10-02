/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(begin(boxTypes),end(boxTypes), [](vector<int>& a, vector<int>& b){return a[1] > b[1];});
        int res = 0;
        for(int i=0, count = 0; i<boxTypes.size(); ++i){

        }
    }
};
// @lc code=end

