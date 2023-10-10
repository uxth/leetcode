/*
 * @lc app=leetcode id=1710 lang=cpp
 *
 * [1710] Maximum Units on a Truck
 */

// @lc code=start
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto& a, auto& b){return a[1] > b[1];});
        int res = 0;
        for(int i=0; i<boxTypes.size() && truckSize > 0; ++i) {
            res += boxTypes[i][1] * min(truckSize, boxTypes[i][0]);
            truckSize -= min(truckSize, boxTypes[i][0]);
      
        }
        return res;
    }
};
// @lc code=end

