/*
 * @lc app=leetcode id=455 lang=cpp
 *
 * [455] Assign Cookies
 */

// @lc code=start
class Solution {
public:
    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(begin(g), end(g), greater<int>());
    //     sort(begin(s), end(s), greater<int>());
    //     int res = 0;
    //     for(int i=0, j=0; i<g.size(); ++i){
    //         if(j<s.size() && s[j] >= g[i]){
    //             res++; j++;
    //         }
    //     }
    //     return res;
    // }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g), end(g));
        sort(begin(s), end(s));
        int res = 0;
        for(int i=0, j=0; j<s.size(); ++j){
            if(i<g.size() && g[i] <= s[j]){
                res++; i++;
            }
        }
        return res;
    }
};
// @lc code=end
// [2,2]\n[1,1,1]
// [1,2,3]\n[1,1]
// [10,9,8,7]\n[5,6,7,8]
// [1,2]\n[1,2,3]