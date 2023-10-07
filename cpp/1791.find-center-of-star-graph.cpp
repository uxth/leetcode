/*
 * @lc app=leetcode id=1791 lang=cpp
 *
 * [1791] Find Center of Star Graph
 */

// @lc code=start
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int res = -1;
        vector<int> count(edges.size() + 2);
        for(vector<int>& e : edges){
            ++count[e[0]];
            ++count[e[1]];
            if(count[e[0]] > count[e[1]]) res = e[0];
            else res = e[1];
        }
        return res;
    }
};
// @lc code=end
/*
[[1,2],[5,1],[1,3],[1,4]]
*/
