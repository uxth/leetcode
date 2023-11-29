/*
 * @lc app=leetcode id=1054 lang=cpp
 *
 * [1054] Distant Barcodes
 *
 * https://leetcode.com/problems/distant-barcodes/description/
 *
 * algorithms
 * Medium (43.16%)
 * Likes:    392
 * Dislikes: 19
 * Total Accepted:    16.9K
 * Total Submissions: 39.1K
 * Testcase Example:  '[1,1,1,2,2,2]'
 *
 * In a warehouse, there is a row of barcodes, where the i-th barcode is
 * barcodes[i].
 * 
 * Rearrange the barcodes so that no two adjacent barcodes are equal.  You may
 * return any answer, and it is guaranteed an answer exists.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1,1,1,2,2,2]
 * Output: [2,1,2,1,2,1]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,1,1,1,2,2,3,3]
 * Output: [1,3,1,3,2,1,2,1]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= barcodes.length <= 10000
 * 1 <= barcodes[i] <= 10000
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> m;
        for(int i : barcodes) ++m[i];
        vector<pair<int,int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), [](auto& a, auto& b){return a.second>b.second;});
        vector<int> res(barcodes.size(), -1);

        int j = 0;
        for(int start=0; start<=1; ++start)
        {
            for(int i=start; i<res.size(); i+=2)
            {
                res[i] = v[j].first;
                if(--v[j].second == 0) j++;
            }
        }
        return res;
    }
};
// @lc code=end

